#include "header.h"

void printCommands()
{
    printf("The commands for this program are:\n\n");
    printf("q - to quit the program\n");
    printf("? - to list the accepted commands\n");
    printf("or any postfix mathematical expression using operators of *, /, +, -\n");
}


int main(int argc, char const* argv[])
{
    char input[300];
    /* set up an infinite loop */
    while (1)
    {
        fgets(input, 300, stdin);
        /* remove the newline character from the input */
        int i = 0;
        while (input[i] != '\n' && input[i] != '\0')
        {
            i++;
        }
        input[i] = '\0';

        /* check if user enter q or Q to quit program */
        if ((strcmp(input, "q") == 0) || (strcmp(input, "Q") == 0))
            break;
        /* check if user enter ? to see command list */
        else if (strcmp(input, "?") == 0)
            printCommands();

        /* user enters an expression */
        else {
            printf("%s\n", input);
            /* 1- Store the expression in a tree
               2- Display infix notation
               3- Display prefix notation
               4- Display postfix notation
               5- Display the result
            */
            node* tree = parseExpression(input);
            if (tree == NULL)
                continue;
            else {
                printf("Infix notation: ");
                printInfixExpression(tree);
                printf("\nPrefix notation: ");
                printPrefixExpression(tree);
                printf("\nPostfix notation: ");
                printPostfixExpression(tree);
                printf("\n");
                int answer = evalExpression(tree);
                printf("Expression result: %d\n", answer);
            }
            treeClear(tree);
        }
    }
    printf("\nGoodbye\n");
    return 0;
}



