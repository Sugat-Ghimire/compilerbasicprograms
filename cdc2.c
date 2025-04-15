// Program to recognize strings under 'a*', 'a*b+', 'abb'
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if string matches 'a*'
bool match_a_star(const char *str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] != 'a')
            return false;
    }
    return true;
}

// Function to check if string matches 'a*b+'
bool match_a_star_b_plus(const char *str)
{
    int i = 0;

    // Count a's
    while (str[i] == 'a')
    {
        i++;
    }

    // Count at least one b
    int b_count = 0;
    while (str[i] == 'b')
    {
        i++;
        b_count++;
    }

    return (b_count > 0 && str[i] == '\0');
}

// Function to check if string is exactly "abb"
bool match_abb(const char *str)
{
    return strcmp(str, "abb") == 0;
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if (match_a_star(str))
    {
        printf("Matches: a*\n");
    }
    else
    {
        printf("Does NOT match: a*\n");
    }

    if (match_a_star_b_plus(str))
    {
        printf("Matches: a*b+\n");
    }
    else
    {
        printf("Does NOT match: a*b+\n");
    }

    if (match_abb(str))
    {
        printf("Matches: abb\n");
    }
    else
    {
        printf("Does NOT match: abb\n");
    }

    return 0;
}
