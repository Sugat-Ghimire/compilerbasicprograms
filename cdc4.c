#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Check if a string is a C keyword
int isKeyword(char buffer[])
{
    char keywords[32][10] = {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef", "union",
        "unsigned", "void", "volatile", "while"};

    for (int i = 0; i < 32; ++i)
    {
        if (strcmp(keywords[i], buffer) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char ch, buffer[20];
    char operators[] = "+-*/%=";
    FILE *fp;
    int i, j = 0;

    fp = fopen("aa.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        // Checks if character is an operator
        for (i = 0; i < strlen(operators); i++)
        {
            if (ch == operators[i])
            {
                printf("%c is an operator\n", ch);
            }
        }

        // Build a word for keyword/identifier checking
        if (isalnum(ch))
        {
            buffer[j++] = ch;
        }
        else if ((ch == ' ' || ch == '\n' || ch == '\t') && j != 0)
        {
            buffer[j] = '\0';
            j = 0;

            if (isKeyword(buffer))
            {
                printf("%s is a keyword\n", buffer);
            }
            else
            {
                printf("%s is an identifier\n", buffer);
            }
        }
    }

    fclose(fp);
    return 0;
}
