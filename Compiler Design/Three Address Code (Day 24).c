#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100
// 2. Write a C Program to create a 3 address code for given expression.
int temp_num = 1;
// create a structure for an expression/instruction: has two arguments joined by an operator, to give a result
typedef struct
{
    char op;
    char arg1[MAX_LENGTH];
    char arg2[MAX_LENGTH];
    char result[MAX_LENGTH];
} Instruction;
// generate_code takes an input expression, expr, and generates a sequence of instructions, code, based on the expression. The instructions are stored in an array of Instruction structures, and the number of instructions generated is stored in the variable num_instructions.
void generate_code(char *expr, Instruction *code, int *num_instructions)
{
    char token[MAX_LENGTH];
    char temp[MAX_LENGTH];
    int i = 0;
    while (expr[i] != '\0')
    {
        // Skip whitespace
        while (expr[i] == ' ' || expr[i] == '\t')
        {
            i++;
        }
        // Read next token
        int j = 0;
        while (expr[i] != '\0' && expr[i] != ' ' && expr[i] != '\t')
        {
            token[j++] = expr[i++];
        }
        token[j] = '\0';
        if (strcmp(token, "*") == 0)
        {
            // Multiply operation
            sprintf(temp, "t%d", temp_num++);
            sprintf(code[*num_instructions].arg1, "%c", expr[i + 1]);
            sprintf(code[*num_instructions].arg2, "%c", expr[i + 3]);
            sprintf(code[*num_instructions].result, "%s", temp);
            code[(*num_instructions)++].op = '*';
            i += 3;
        }
        else if (strcmp(token, "-") == 0)
        {
            // Negation operation
            sprintf(temp, "t%d", temp_num++);
            sprintf(code[*num_instructions].arg1, "%c", expr[i + 1]);
            sprintf(code[*num_instructions].result, "%s", temp);
            code[(*num_instructions)++].op = 'u';
            i += 2;
        }
        else if (strcmp(token, "+") == 0)
        {
            // Addition operation
            sprintf(temp, "t%d", temp_num++);
            sprintf(code[*num_instructions].arg1, "%s", temp);
            sprintf(code[*num_instructions].arg2, "%c", expr[i + 1]);
            sprintf(code[*num_instructions].result, "%s", temp);
            code[(*num_instructions)++].op = '+';
            i += 2;
        }
        else
        {
            // Variable assignment
            sprintf(code[*num_instructions].arg1, "%s", token);
            sprintf(code[*num_instructions].result, "%c", token[0]);
            code[(*num_instructions)++].op = '=';
        }
    }
}
int main()
{
    char expr[MAX_LENGTH];
    Instruction code[MAX_LENGTH];
    int num_instructions = 0;
    printf("Enter the expression: ");
    fgets(expr, MAX_LENGTH, stdin);
    expr[strcspn(expr, "\n")] = '\0';
    generate_code(expr, code, &num_instructions);
    printf("3-address code:\n");
    for (int i = 0; i < num_instructions; i++)
    {
        switch (code[i].op)
        {
        case '=':
            printf("%s = %s\n", code[i].result, code[i].arg1);
            break;
        case '+':
            printf("%s = %s + %s\n", code[i].result, code[i].arg1, code[i].arg2);
            break;
        case '*':
            printf("%s = %s * %s\n", code[i].result, code[i].arg1, code[i].arg2);
            break;
        case 'u':
            printf("%s = -%s\n", code[i].result, code[i].arg1);
            break;
        default:
            printf("Invalid operator found!\n");
            exit(1);
        }
    }
    return 0;
}

// method #2: three address code
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    char expr[100];
    int i, j, k, l;
    char op[10], opnd[10][10], arg1[10], arg2[10], res[10];
    printf("Enter the expression: ");
    scanf("%s", expr);
    i = 0;
    j = 0;
    k = 0;
    l = 0;
    while (expr[i] != '\0')
    {
        if (isalnum(expr[i]))
        {
            opnd[j][k++] = expr[i];
        }
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
        {
            opnd[j][k] = '\0';
            j++;
            k = 0;
            op[l++] = expr[i];
        }
        i++;
    }
    opnd[j][k] = '\0';
    strcpy(arg1, opnd[0]);
    strcpy(arg2, opnd[1]);
    sprintf(res, "t%d", 1); // Changed the starting temporary variable to t1
    printf("%s = %s %c %s\n", res, arg1, op[0], arg2);
    for (i = 1; i < j; i++)
    {
        strcpy(arg1, res);
        strcpy(arg2, opnd[i + 1]);
        sprintf(res, "t%d", i + 1); // Updated the temporary variable in the loop
        printf("%s = %s %c %s\n", res, arg1, op[i], arg2);
    }
    return 0;
}