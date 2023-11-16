#include "monty.h"

stack_t *first = NULL;

/**
 * main - entry point.
 * @ac: argument c.
 * @av: argument v.
 * Return: 0.
 */

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    openFile(av[1]);
    nodeFree();
    return 0;
}

/**
 * nodeCreate - a function that creates a node.
 * @idx: size of the node.
 * Return: the node pointer (success), else (NULL).
 */

stack_t *nodeCreate(int idx)
{
    stack_t *new;

    new = malloc(sizeof(stack_t));
    if (new == NULL)
        error(4);
    new->next = NULL;
    new->prev = NULL;
    new->n = idx;
    return new;
}

/**
 * nodeFree - a function that frees nodes in the stack.
 */

void nodeFree(void)
{
    stack_t *old;

    if (first == NULL)
        return;

    while (first != NULL)
    {
        old = first;
        first = first->next;
        free(old);
    }
}

/**
 * queueAdd - a function that adds a new node to the queue.
 * @new: node pointer.
 * @lineN: line number.
 */

void queueAdd(stack_t **new, __attribute__((unused))unsigned int lineN)
{
    stack_t *old;

    if (new == NULL || *new == NULL)
        exit(EXIT_FAILURE);
    if (first == NULL)
    {
        first = *new;
        return;
    }
    old = first;
    while (old->next != NULL)
        old = old->next;

    old->next = *new;
    (*new)->prev = old;
}