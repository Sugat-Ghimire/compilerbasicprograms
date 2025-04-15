// Program to test whether given entered string within valid comment section or not.
#include <stdio.h>
#include <string.h>

// Function to check if the input is a valid comment
int isValidComment(char *str)
{
    int len = strlen(str);

    // Checks for single-line comment
    if (str[0] == '/' && str[1] == '/')
    {
        return 1;
    }

    // Checks for multi-line comment
    if (str[0] == '/' && str[1] == '*')
    {
        if (len >= 4 && str[len - 2] == '*' && str[len - 1] == '/')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    return 0;
}

int main()
{
    char str[1000];

    printf("Enter a comment string: ");
    fgets(str, sizeof(str), stdin);

    // Removes newline if present
    size_t ln = strlen(str) - 1;
    if (str[ln] == '\n')
        str[ln] = '\0';

    if (isValidComment(str))
    {
        printf("Valid comment.\n");
    }
    else
    {
        printf("Not a valid comment.\n");
    }

    return 0;
}
