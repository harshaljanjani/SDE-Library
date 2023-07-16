#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 100
#define MAX_TOKEN_SIZE 10
// 3. For the given grammar E -> E +E | E*E | E/E | E-E | a | b | id Construct the operator precedence table using C program and parse the string id *id + id.
// pehle toh operator ka struct banao boss
typedef struct
{
    // 1) operator ka symbol
    // 2) uska precedence
    char operator;
    int precedence;
} Operator;
Operator operators[] = {
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2},
};
// table ka seedha output denge hum, no need for a structure
// ab, stack ke functions for a character stack
char stack[STACK_SIZE];
int top = -1;
void push(char token)
{
    if (top == STACK_SIZE - 1)
    {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = token;
}
char pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}
// part 2: ab utility functions aayenge
// pehla function: agar koi operator pass kiya hai, then return uska precedence
// utility function 1
int getPrecedence(char op)
{
    for (int i = 0; i < sizeof(operators) / sizeof(operators[0]); i++)
    {
        if (operators[i].operator== op)
        {
            return operators[i].precedence;
        }
    }
    return -1;
}
// utility function 2
int hasHigherPrecedence(char op1, char op2)
{
    int p1 = getPrecedence(op1);
    int p2 = getPrecedence(op2);
    // basically, not -1, then direct comparison
    return (p1 >= 0 && p2 >= 0 && p1 >= p2);
    // if true, then p1 >= p2 else p2 > p1
}
// utility function 3
int isOperator(char symbol)
{
    // operator table mein hai, toh operator hai, nahi toh nahi hai. simple
    for (int i = 0; i < sizeof(operators) / sizeof(operators[0]); i++)
    {
        if (operators[i].operator== symbol)
        {
            return 1;
        }
    }
    return 0;
}
// utility function 4
// get posfix expression from the operator precedence table
void parseExpression(const char *expression)
{
    // here we would use the stack logic
    int i = 0;
    int length = strlen(expression);
    for (int i = 0; i < length; i++)
    {
        char token = expression[i];
        if (isOperator(token))
        {
            // if the token is an operator, keep popping all operators of higher precedence from the stack until we encounter a non-operator token
            while (top >= 0 && isOperator(stack[top]) && hasHigherPrecedence(stack[top], token))
            {
                printf("%c", pop());
            }
            // first operator with lower precedence, or a non-operator token
            push(token);
        }
        // for non-operators encountered
        else
        {
            printf("%c", token);
        }
    }
    // pop the remaining
    while (top >= 0)
    {
        printf("%c", pop());
    }
    printf("\n");
}
// driver code
int main()
{
    // example of a parsing string/expression
    const char *expression = "id*id+id";
    printf("Operator Precedence Table:\n");
    printf("--------------------------\n");
    printf("| + | - | * | / |\n");
    printf("--------------------------\n");
    printf("| < | < | > | > |\n");
    printf("--------------------------\n\n");
    printf("Parsing Expression: %s\n", expression);
    printf("Postfix Notation: ");
    parseExpression(expression);
    return 0;
}