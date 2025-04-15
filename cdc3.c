// Program to test whether a given identifier is valid or not
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to check if a string is a valid identifier
int isValidIdentifier(char *str)
{
    int i = 0;

    // Empty string is not a valid identifier
    if (str[0] == '\0')
    {
        return 0;
    }

    // First character must be a letter or underscore
    if (!isalpha(str[0]) && str[0] != '_')
    {
        return 0;
    }

    // Check the rest of the string
    for (i = 1; str[i] != '\0'; i++)
    {
        if (!isalnum(str[i]) && str[i] != '_')
        {
            return 0;
        }
    }

    return 1; // valid
}

int main()
{
    char identifier[100];

    printf("Enter an identifier: ");
    scanf("%s", identifier);

    if (isValidIdentifier(identifier))
    {
        printf("Valid identifier\n");
    }
    else
    {
        printf("Not a valid identifier\n");
    }

    return 0;
}
