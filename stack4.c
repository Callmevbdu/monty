#include "monty.h"

/**
 * printChar - Prints the Ascii value.
 * @top: a pointer to the top node of the stack.
 * @lineN: line number.
 */

void printChar(stack_t **top, unsigned int lineN)
{
	int lim;

	if (top == NULL || *top == NULL)
		errorString(11, lineN);

	lim = (*top)->n;

	if (lim < 0 || lim > 127)
		errorString(10, lineN);

	printf("%c\n", lim);
}

/**
 * printStr - a function that prints a string.
 * @top: a pointer to the top node of the stack.
 * @lineN: line number.
 */

void printStr(stack_t **top, __attribute__((unused))unsigned int lineN)
{
	int lim;
	stack_t *old;

	if (top == NULL || *top == NULL)
	{
		printf("\n");
		return;
	}

	old = *top;

	while (old != NULL)
	{
		lim = old->n;

		if (lim <= 0 || lim > 127)
			break;

		printf("%c", lim);
		old = old->next;
	}

	printf("\n");
}

/**
 * rotateL - a function that rotates the first node to the bottom.
 * @top: a pointer to the top node of the stack.
 * @lineN: line number.
 */

void rotateL(stack_t **top, __attribute__((unused))unsigned int lineN)
{
	stack_t *old;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
		return;

	old = *top;

	while (old->next != NULL)
		old = old->next;

	old->next = *top;
	(*top)->prev = old;
	*top = (*top)->next;
	(*top)->prev->next = NULL;
	(*top)->prev = NULL;
}

/**
 * rotateR - a function that rotates the first node to the top.
 * @top: a pointer to the top node of the stack.
 * @lineN: line number.
 */

void rotateR(stack_t **top, __attribute__((unused))unsigned int lineN)
{
	stack_t *old;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
		return;

	old = *top;

	while (old->next != NULL)
		old = old->next;

	old->next = *top;
	old->prev->next = NULL;
	old->prev = NULL;
	(*top)->prev = old;
	(*top) = old;
}