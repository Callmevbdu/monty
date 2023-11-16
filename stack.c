#include "monty.h"

/**
 * stackAdd - a function that adds a node to the stack.
 * @new: node pointer.
 * @lineN: line number.
 */

void stackAdd(stack_t **new, __attribute__((unused))unsigned int lineN)
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
	first = *new;
	first->next = old;
	old->prev = first;
}

/**
 * stackPrint - a function that prints a node from the stack.
 * @top: a pointer to the top node of the stack.
 * @lineN: line number.
 */

void stackPrint(stack_t **top, unsigned int lineN)
{
	stack_t *old;

	(void) lineN;

	if (top == NULL)
		exit(EXIT_FAILURE);

	old = *top;

	while (old != NULL)
	{
		printf("%d\n", old->n);
		old = old->next;
	}
}

/**
 * stackPopTop - a function that removes the top node of stack.
 * @top: a pointer to the top node of the stack.
 * @lineN: line number.
 */

void stackPopTop(stack_t **top, unsigned int lineN)
{
	stack_t *old;

	if (top == NULL || *top == NULL)
		error2(7, lineN);

	old = *top;
	*top = old->next;

	if (*top != NULL)
		(*top)->prev = NULL;

	free(old);
}

/**
 * stackPrintTop - a function that prints the top node of stack.
 * @top: a pointer to the top node of the stack.
 * @lineN: line number.
 */

void stackPrintTop(stack_t **top, unsigned int lineN)
{
	if (top == NULL || *top == NULL)
		error2(6, lineN);

	printf("%d\n", (*top)->n);
}