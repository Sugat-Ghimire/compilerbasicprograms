// Program to Implement Shift Reduce Parser
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char stack[50], input[50];
int top = -1, ip = 0;

void print_action(const char *action)
{
    printf("\n%-15s %-15s %-15s", stack, &input[ip], action);
}

void push(char ch)
{
    stack[++top] = ch;
    stack[top + 1] = '\0';
}

void pop()
{
    if (top >= 0)
        stack[top--] = '\0';
}

int reduce()
{
    if (top >= 0 && (stack[top] == 'a' || stack[top] == 'b'))
    {
        stack[top] = 'E';
        print_action("Reduce E -> id");
        return 1;
    }

    if (top >= 2 && stack[top - 2] == 'E' &&
        (stack[top - 1] == '+' || stack[top - 1] == '*' || stack[top - 1] == '/') &&
        stack[top] == 'E')
    {
        stack[top - 2] = 'E';
        stack[top - 1] = '\0';
        stack[top] = '\0';
        top -= 2;
        char action[20];
        sprintf(action, "Reduce E->E%cE", stack[top + 1]);
        print_action(action);
        return 1;
    }

    return 0;
}

int main()
{
    printf("SHIFT REDUCE PARSER\n");
    printf("Grammar:\n");
    printf("E -> E+E | E*E | E/E | a | b\n\n");

    printf("Enter input string : ");
    scanf("%s", input);

    strcat(input, "$");
    printf("\n%-15s %-15s %-15s", "Stack", "Input", "Action");
    printf("\n-------------------------------------------------------");

    print_action("Initialize");

    while (input[ip] != '$' || top != 0 || stack[top] != 'E')
    {
        if (input[ip] != '$')
        {
            // Shift
            char action[20];
            sprintf(action, "Shift %c", input[ip]);
            push(input[ip++]);
            print_action(action);

            // Tries to reducing repeatedly
            while (reduce())
                ;
        }
        else
        {
            // Tryies final reductions
            if (!reduce())
                break;
        }
    }

    if (stack[0] == 'E' && stack[1] == '\0' && input[ip] == '$')
        print_action("ACCEPT");
    else
        print_action("REJECT");

    return 0;
}
