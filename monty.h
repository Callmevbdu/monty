#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *first;
typedef void (*op_func)(stack_t **, unsigned int);

/* STACK OPERATIONS */
void stackAdd(stack_t **, unsigned int);
void stackPrint(stack_t **, unsigned int);
void stackPopTop(stack_t **, unsigned int);
void stackPrintTop(stack_t **, unsigned int);

/* STACK 2 */
void nop(stack_t **, unsigned int);
void nodeSwap(stack_t **, unsigned int);
void nodeAdd(stack_t **, unsigned int);
void nodeSub(stack_t **, unsigned int);
void nodeDiv(stack_t **, unsigned int);

/* STACK 3 */
void nodeMul(stack_t **, unsigned int);
void nodeMod(stack_t **, unsigned int);

/* STACK 4 */
void printChar(stack_t **, unsigned int);
void printStr(stack_t **, unsigned int);
void rotateL(stack_t **, unsigned int);
void rotateR(stack_t **, unsigned int);

/* MANAGE FILE */
void openFile(char *fName);
void readFile(FILE *);
int resolveLine(char *buff, int lineN, int type);
void functionFind(char *, char *, int, int);
void functionCall(op_func, char *, char *, int, int);

/* MAIN FILE */
stack_t *nodeCreate(int idx);
void nodeFree(void);
void queueAdd(stack_t **, unsigned int);

/* ERROR RESPONSE */
void error(int errorCode, ...);
void error2(int errorCode, ...);
void errorString(int errorCode, ...);

int len_chars(FILE *);

#endif /* MONTY_H */