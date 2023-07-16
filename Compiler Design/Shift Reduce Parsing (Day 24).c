#include <stdio.h>
#include <string.h>

char input[] = "id+id+id"; // Input string to parse
char stack[15];            // Stack to simulate the parsing process
int i = 0, j = 0, c = 0;   // Loop control and length variables

void reduce();     // Function to perform reductions
void print_step(); // Function to print parsing step

int main()
{
    puts("GRAMMAR is S->S+S \n S->S*S \n S->id"); // Display the grammar rules
    printf("Input String is %s\n", input);        // Display the input string

    c = strlen(input);                // Calculate the length of the input string
    puts("stack \t input \t action"); // Display column headers for the parsing steps

    for (i = 0, j = 0; j < c; i++, j++)
    {
        if (input[j] == 'i' && input[j + 1] == 'd') // Check if the current characters form an identifier "id"
        {
            stack[i++] = input[j];         // Push the first character of the identifier onto the stack
            stack[i] = input[j + 1];       // Push the second character of the identifier onto the stack
            stack[i + 1] = '\0';           // Add a null terminator to the stack to mark the end of the identifier
            input[j] = input[j + 1] = ' '; // Clear the processed characters from the input string
            printf("\n$%s\t%s$\tSHIFT->id", stack, input);
            reduce(); // Check if any reductions are possible after the shift
        }
        else
        {
            stack[i] = input[j]; // Push the current character (symbol) onto the stack
            stack[i + 1] = '\0'; // Add a null terminator to the stack after the symbol
            input[j] = ' ';      // Clear the processed character from the input string
            printf("\n$%s\t%s$\tSHIFT->symbols", stack, input);
            reduce(); // Check if any reductions are possible after the shift
        }
    }
    return 0;
}

void reduce()
{
    char action[20];
    strcpy(action, "REDUCE TO S"); // Action description for reductions
    // for "id"
    for (int l = 0; l < c; l++)
    {
        if (stack[l] == 'i' && stack[l + 1] == 'd') // Check for the occurrence of an identifier "id"
        {
            stack[l] = 'S';      // Replace the identifier with nonterminal "S"
            stack[l + 1] = '\0'; // Add a null terminator to mark the end of the nonterminal
            printf("\n$%s\t%s$\t%s", stack, input, action);
            j++; // Move the input index to skip the processed identifier
        }
    }
    // for "S+S" || "S*S"
    for (int l = 0; l < c; l++)
    {
        if ((stack[l] == 'S' && stack[l + 1] == '+' && stack[l + 2] == 'S') || (stack[l] == 'S' && stack[l + 1] == '*' && stack[l + 2] == 'S')) // Check for the occurrence of "S+S"
        {
            stack[l] = 'S';                     // Replace "S+S" with nonterminal "S"
            stack[l + 1] = stack[l + 2] = '\0'; // Add null terminators to mark the end of the nonterminals
            printf("\n$%s\t%s$\t%s", stack, input, action);
            i -= 2; // Adjust the stack index after the reduction
        }
    }
}
