#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 10
int numOfProductions;
char productionSet[MAX][MAX];

// Function declarations
void FIRST(char *result, char c);
void addToResultSet(char *result, char val);

int main()
{
    char result[20], choice, c;

    printf("Enter number of productions: ");
    scanf(" %d", &numOfProductions);

    // Reading production rules
    for (int i = 0; i < numOfProductions; i++)
    {
        printf("Enter production number %d (e.g., E=E+T): ", i + 1);
        scanf(" %s", productionSet[i]);
    }

    // Repeatedly asks user to compute FIRST
    do
    {
        printf("\nFind the FIRST of: ");
        scanf(" %c", &c);

        // Clears previous result
        result[0] = '\0';
        FIRST(result, c);

        printf("FIRST(%c) = { ", c);
        for (int i = 0; result[i] != '\0'; i++)
        {
            printf("%c ", result[i]);
        }
        printf("}\n");

        printf("Press 'y' to continue: ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

// Recursive function to compute FIRST of a non-terminal
void FIRST(char *result, char c)
{
    char subResult[20];
    int foundEpsilon;

    // Terminal case
    if (!isupper(c))
    {
        addToResultSet(result, c);
        return;
    }

    // For each production
    for (int i = 0; i < numOfProductions; i++)
    {
        // Check if production's LHS is the same as c
        if (productionSet[i][0] == c)
        {
            // Case: production is A -> ε
            if (productionSet[i][2] == '$')
            {
                addToResultSet(result, '$');
            }
            else
            {
                int j = 2;
                while (productionSet[i][j] != '\0')
                {
                    subResult[0] = '\0';
                    foundEpsilon = 0;

                    FIRST(subResult, productionSet[i][j]);

                    // Add all sub FIRST results to main result
                    for (int k = 0; subResult[k] != '\0'; k++)
                    {
                        addToResultSet(result, subResult[k]);
                    }

                    // Check for ε
                    for (int k = 0; subResult[k] != '\0'; k++)
                    {
                        if (subResult[k] == '$')
                        {
                            foundEpsilon = 1;
                            break;
                        }
                    }

                    // Stop if ε is not found
                    if (!foundEpsilon)
                        break;
                    j++;
                }
            }
        }
    }
}

// Adds character to result if not already present
void addToResultSet(char *result, char val)
{
    for (int i = 0; result[i] != '\0'; i++)
    {
        if (result[i] == val)
            return; // already present
    }
    int len = strlen(result);
    result[len] = val;
    result[len + 1] = '\0';
}
