#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// MAX_NON_TERMINALS, MAX_TERMINALS, MAX_NON_TERMINALS
#define MAX_NON_TERMINALS 10
#define MAX_TERMINALS 10
#define MAX_PROD_RULES 10
// structure to represent a production rule
typedef struct
{
    char leftOfProd;                      // left hand side of production rule
    char rightOfProd[MAX_PROD_RULES][20]; // right hand side of the production rule
    int count;                            // number of right hand side options
} ProductionRule;
// structure to represent the LL(1) parsing table
typedef struct
{
    char nonTerminal;
    char terminals[MAX_TERMINALS];
    char production[MAX_NON_TERMINALS][MAX_TERMINALS][20];
    int count;
} LL1Table;
// function to add a production rule to the LL(1) table
// table, nonTerminal, terminal, productionRule
void addProdRule(LL1Table *table, char nonTerminal, char terminal, char *productionRule)
{
    int nonTerminalIndex = nonTerminal - 'A'; // nonTerminalIndex -> subtract ASCII value of nonTerminal with reference 'A'
    int terminalIndex = terminal - 'a';       // terminalIndex -> subtract ASCII value of terminal with reference 'a'
    // move the production rule into the table, at table[nonTerminalIndex][terminalIndex]
    strcpy(table->production[nonTerminalIndex][terminalIndex], productionRule);
    table->count++;
}
// suppose 'A'
// function to find the FIRST set of a given non-terminal
// grammar -> array of ProductionRule
// table -> array of rows in the LL1Table
// non-terminal -> the non-terminal we're trying to find the FIRST of
// visited -> if the non-terminal has been visited yet or not, full array
// firstSetCount -> count of how many firsts the non-terminal has
// firstSet -> array of firsts of the non-terminal
void findFirstSet(ProductionRule *grammar, LL1Table *table, char nonTerminal, int *visited, int *firstSetCount, char *firstSet)
{
    int nonTerminalIndex = nonTerminal - 'A';
    visited[nonTerminalIndex] = 1; // mark non-terminal as visited
    // grammar[i] would be a ProductionRule
    // in the table
    for (int i = 0; i < table->count; i++)
    {
        // in the grammar's [i]th rule
        // only if it is a non-terminal, we enter the next stage of the loop
        if (grammar[i].leftOfProd == nonTerminal)
        {
            // for every left side of the production
            for (int j = 0; j < grammar[i].leftOfProd; j++)
            {
                // A(i)->B(j)|C(j)
                // index at 0 because that's the first terminal/non-terminal in the right side of the production rule
                char firstSymbol = grammar[i].rightOfProd[j][0];
                // so basically, if the first symbol is not a terminal
                if (firstSymbol >= 'A' && firstSymbol <= 'Z' && !visited[firstSymbol - 'A'])
                {
                    // non-terminal we pass into the recursive call is firstSymbol
                    findFirstSet(grammar, table, firstSymbol, visited, firstSetCount, firstSet);
                }
                // basically if the first symbol is a terminal, and not #
                else if (firstSymbol != '#')
                {
                    firstSet[*firstSetCount] = firstSymbol;
                    (*firstSetCount)++;
                    // basically, the next time it's inserted it is inserted at the next position
                    // also, that's why it's necessary to pass it as a reference
                }
            }
        }
    }
}
// function to find FOLLOW of a non-terminal
void findFollowSet(ProductionRule *grammar, LL1Table *table, char nonTerminal, int *followSetCount, char *followSet)
{
    // loop structure
    // if the nonTerminal is a starting symbol
    if (nonTerminal == 'E')
    {
        followSet[*followSetCount] = '$';
        (*followSetCount)++;
    }
    // loop structure
    for (int i = 0; i < table->count; i++)
    {
        for (int j = 0; j < grammar[i].count; j++)
        {
            // how to reach the right of the production rule?
            char *productionRule = grammar[i].rightOfProd[j];
            int len = strlen(productionRule);
            // now, in that one right of the prod, there could be something like Ab, then b, then A
            // we need to cater to all these cases
            for (int k = 0; k < len; k++)
            {
                if (productionRule[k] == nonTerminal)
                {
                    // the last element
                    // toh FOLLOW(leftOfProd) hoga
                    if (k == len - 1)
                    {
                        // basically aise nikalta hai na? last element ke next toh kuch hota nahi hai, so we have to find FOLLOW(leftOfProd)
                        if (nonTerminal != grammar[i].leftOfProd)
                        {
                            findFollowSet(grammar, table, grammar[i].leftOfProd, followSetCount, followSet);
                        }
                    }
                    // if it's not the last element, toh just uske next dekhna padega (if its a terminal, add to followSet, if it's a nonTerminal, I think recursive call hoga)
                    else
                    {
                        char nextSymbol = productionRule[k + 1];
                        // how to check if its a non-terminal or not
                        if (nextSymbol >= 'A' && nextSymbol <= 'Z')
                        {
                            // initialize a visited array, of size MAX_NON_TERMINALS, all to 0
                            int visited[MAX_NON_TERMINALS] = {0};
                            // we'll see why we need firstSet here, but apparently we do
                            int firstSetCount = 0;
                            char firstSet[MAX_TERMINALS];
                            // find firstSet of the nextSymbol, that's direct only
                            findFirstSet(grammar, table, nextSymbol, visited, &firstSetCount, firstSet);
                            // saare firstSet ke copy kardo into the followSet, ez
                            for (int l = 0; l < firstSetCount; l++)
                            {
                                if (firstSet[l] != '#')
                                {
                                    followSet[*followSetCount] = firstSet[l];
                                    (*followSetCount)++;
                                }
                            }
                            // agar aapke firstSet me kuch nahi aaya toh?
                            // secondly, agar aapke firstSet mein # aaya toh? we can't have that in the followSet
                            if (firstSetCount == 0 || (firstSetCount > 0 && strchr(firstSet, '#')))
                            {
                                // fir aap leftOfProd ka nikaal lo FOLLOW
                                findFollowSet(grammar, table, grammar[i].leftOfProd, followSetCount, followSet);
                            }
                        }
                        // seedha terminal aa-gaya apun ke paas
                        else
                        {
                            followSet[*followSetCount] = nextSymbol;
                            (*followSetCount)++;
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    // wahi grammar jo question mein diya hua hai
    /*
    E -> E + T | T
    T -> T * F | F
    */
    // different grammar hai toh yahan pe daal do
    ProductionRule grammar[MAX_NON_TERMINALS] = {
        {'E', {"E+T", "T"}, 2},
        {'T', {"T*F", "F"}, 2}};
    LL1Table table;
    memset(&table, 0, sizeof(table));
    // yahan bhi change kar do question ke hisaab se
    table.nonTerminal = 'E';
    table.terminals[0] = '+';
    table.terminals[1] = '*';
    table.terminals[2] = 'a';
    table.count = 3;
    addProdRule(&table, 'E', '+', "E+T");
    addProdRule(&table, 'E', 'a', "T");
    addProdRule(&table, 'T', '*', "T*F");
    addProdRule(&table, 'T', 'a', "F");
    printf("LL(1) Parsing Table Is As Follows:\n");
    printf("--------------------\n");
    printf("| NT | + | * | a |\n");
    printf("--------------------\n");
    printf("| E | E+T | | T |\n");
    printf("--------------------\n");
    printf("| T | | T*F | F |\n");
    printf("--------------------\n");
    char nonTerminal;
    printf("\nWhich non-terminal to find the FIRST and FOLLOW sets for: ");
    scanf("%c", &nonTerminal);
    int visited[MAX_NON_TERMINALS] = {0};
    int firstSetCount = 0;
    char firstSet[MAX_TERMINALS];
    // main idhar hai apun ka function
    findFirstSet(grammar, &table, nonTerminal, visited, &firstSetCount, firstSet);
    int i;
    printf("\nFIRST(%c): ", nonTerminal);
    for (i = 0; i < firstSetCount; i++)
    {
        printf("%c ", firstSet[i]);
    }
    int followSetCnt = 0;
    char followSet[MAX_TERMINALS];
    // main idhar hai apun ka function
    findFollowSet(grammar, &table, nonTerminal, &followSetCnt, followSet);
    printf("\nFOLLOW(%c): ", nonTerminal);
    for (i = 0; i < followSetCnt; i++)
    {
        printf("%c ", followSet[i]);
    }
    printf("\n");
    return 0;
}