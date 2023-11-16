#include "monty.h"

/**
 * error - a function which return the correct error message.
 * @errCode: from 1 to 5, each code is for a specific problem.
*/

void error(int errCode, ...)
{
    int lineN;
    char *func;
    va_list arg;

    va_start(arg, errCode);

    switch (errCode)
    {
        case 1: /* If the user command is wrong */
            fprintf(stderr, "USAGE: monty file\n");
            break;
        case 2: /* If the file entered cannot be opened */
            fprintf(stderr, "Error: Can't open file %s\n",
                va_arg(arg, char *));
            break;
        case 3: /* If the file can't be read */
            lineN = va_arg(arg, int);
            func = va_arg(arg, char *);
            fprintf(stderr, "L%d: unknown instruction %s\n", lineN, func);
            break;
        case 4: /* If the app can't allocate memory */
            fprintf(stderr, "Error: malloc failed\n");
            break;
        case 5: /* If the user's input doesn't contain integers */
            fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
            break;
        default:
            break;
    }

    nodeFree();
    exit(EXIT_FAILURE);
}

/**
 * error2 - a function which return the correct error message.
 * @errCode: from 6 to 9, each code is for a specific problem.
*/

void error2(int errCode, ...)
{
    int lineN;
    char *func;
    va_list arg;

    va_start(arg, errCode);

    switch (errCode)
    {
        case 6: /* Stack is empty, can't pint */
            fprintf(stderr, "L%d: can't pint, stack empty\n",
                va_arg(arg, int));
            break;
        case 7: /* Stack is empty, can't pop */
            fprintf(stderr, "L%d: can't pop an empty stack\n",
                va_arg(arg, int));
            break;
        case 8: /* Stack is short for the operation */
            lineN = va_arg(arg, unsigned int);
            func = va_arg(arg, char *);
            fprintf(stderr, "L%d: can't %s, stack too short\n", lineN, func);
            break;
        case 9: /* If the top element of the stack is 0, can't divide */
            fprintf(stderr, "L%d: division by zero\n",
                va_arg(arg, unsigned int));
            break;
        default:
            break;
    }

    nodeFree();
    exit(EXIT_FAILURE);
}

/**
 * errorString - a function which return the correct error message.
 * @errCode: "10" if input is out of ASCII limits, "11" if the stack
 * is empty.
*/

void errorString(int errCode, ...)
{
    int lineN;
    va_list arg;

    lineN = va_arg(arg, int);
    va_start(arg, errCode);

    switch (errCode)
    {
        case 10:
            fprintf(stderr, "L%d: can't pchar, value out of range\n", lineN);
            break;
        case 11:
            fprintf(stderr, "L%d: can't pchar, stack empty\n", lineN);
            break;
        default:
            break;
    }

    nodeFree();
    exit(EXIT_FAILURE);
}