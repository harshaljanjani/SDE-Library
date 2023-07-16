#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TABLE_SIZE 100
// an entry in the symbol table would have 3 things: address, keyword/symbol, and datatype (type)
typedef struct
{
    // 3 attributes
    char symbol[20];
    int address;
    char type[20];
} SymbolTableEntry;
// create an array of entries, that's basically your symbol table
SymbolTableEntry symbol_table[MAX_TABLE_SIZE];
int tableSize = 0; // for now, we iniitalize number of entries in the symbol table
// function to check if a symbol exists in the symbol table (lookup function)
bool lookup(char *symbol)
{
    int i;
    for (int i = 0; i < tableSize; i++)
    {
        if (!strcmp(symbol, symbol_table[i].symbol))
        {
            return true;
        }
    }
    return false;
}
// function to insert a new table entry in the symbol table
void insert(char *symbol, int address, char *type)
{
    if (tableSize >= MAX_TABLE_SIZE)
    {
        // overflow
        printf("Error: Symbol Table Is Full");
        return;
    }
    // else
    strcpy(symbol_table[tableSize].symbol, symbol);
    strcpy(symbol_table[tableSize].type, type);
    symbol_table[tableSize].address = address;
    tableSize++;
}
// ab hume ye logic dekhna padega ki kab insert kare, kab nahi, from the given C code
int main(void)
{
    // initalize symbol table with keywords
    insert("int", 1000, "Keyword");
    // parse input and add symbols to the symbol table
    char input[50];
    printf("Enter input: ");
    fgets(input, 50, stdin); // get input
    // string should be tokenized based on the following delimiters
    char *token = strtok(input, "+*;\n");
    while (token != NULL)
    {
        // check if the token is a keyword
        if (!strcmp(token, "int"))
        {
            // already added to the table, we can skip it
        }
        // check if the token is a number/constant
        // so basically this gives us the number of characters in the string, which match with the characters in the pattern
        // so if len(matchStr) == len(token), all characters are digits, so it is a number
        else if (strspn(token, "0123456789") == strlen(token))
        {
            // insert at address atoi(token)
            insert(token, atoi(token), "Number");
        }
        // check if the token is an identifier
        else
        {
            int index = lookup(token);
            // not already present in the table
            if (!index)
            {
            }
        }
        // when strtok() is called with the first argument as NULL, it continues tokenizing the same string from where it left off in the previous call. This allows you to extract the next token in the string.
        token = strtok(NULL, "+*;\n");
    }
    // add operators to the symbol table
    // hack
    insert("*", 2500, "Operator");
    insert("+", 2501, "Operator");
    // print symbolTable;
    printf("\nSymbol\tAddress\tType\n");
    for (int i = 0; i < tableSize; i++)
    {
        printf("%s\t%d\t%s\n", symbolTable[i].symbol, symbolTable[i].address, symbolTable[i].type);
    }
    return 0;
}