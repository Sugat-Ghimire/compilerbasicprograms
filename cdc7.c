// program for Final Code Generation
#include <stdio.h>
#include <string.h>

char op[3], arg1[10], arg2[10], result[10];

int main()
{
    FILE *fp1, *fp2;

    fp1 = fopen("input.txt", "r");
    fp2 = fopen("output.txt", "w");

    if (fp1 == NULL || fp2 == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    while (fscanf(fp1, "%s %s %s %s", op, arg1, arg2, result) != EOF)
    {
        if (strcmp(op, "+") == 0)
        {
            fprintf(fp2, "\nMOV R0, %s", arg1);
            fprintf(fp2, "\nADD R0, %s", arg2);
            fprintf(fp2, "\nMOV %s, R0", result);
        }
        else if (strcmp(op, "*") == 0)
        {
            fprintf(fp2, "\nMOV R0, %s", arg1);
            fprintf(fp2, "\nMUL R0, %s", arg2);
            fprintf(fp2, "\nMOV %s, R0", result);
        }
        else if (strcmp(op, "-") == 0)
        {
            fprintf(fp2, "\nMOV R0, %s", arg1);
            fprintf(fp2, "\nSUB R0, %s", arg2);
            fprintf(fp2, "\nMOV %s, R0", result);
        }
        else if (strcmp(op, "/") == 0)
        {
            fprintf(fp2, "\nMOV R0, %s", arg1);
            fprintf(fp2, "\nDIV R0, %s", arg2);
            fprintf(fp2, "\nMOV %s, R0", result);
        }
        else if (strcmp(op, "=") == 0)
        {
            fprintf(fp2, "\nMOV R0, %s", arg1);
            fprintf(fp2, "\nMOV %s, R0", result);
        }
    }

    fclose(fp1);
    fclose(fp2);
    printf("Final code generated in output.txt\n");

    return 0;
}
