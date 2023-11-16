#include "monty.h"

/**
 * nop - a function which does nothing.
 * @top: a pointer to the top node of the stack.
 * @lineN: line number.
 */

void nop(stack_t **top, unsigned int lineN)
{
	(void)top;
	(void)lineN;
}

/**
 * nodeSwap - a function that swaps the top two elements.
 * @top: a pointer to the top node of the stack.
 * @lineN: line number.
 */

void nodeSwap(stack_t **top, unsigned int lineN)
{
	stack_t *old;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
		error2(8, lineN, "swap");

	old = (*top)->next;
	(*top)->next = old->next;

	if (old->next != NULL)
		old->next->prev = *top;

	old->next = *top;
	(*top)->prev = old;
	old->prev = NULL;
	*top = old;
}

/**
 * nodeAdd - a function which adds (calculate) the top two elements.
 * @top: a pointer to the top node of the stack.
 * @lineN: line number.
 */

void nodeAdd(stack_t **top, unsigned int lineN)
{
	int total;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
		error2(8, lineN, "add");

	(*top) = (*top)->next;
	total = (*top)->n + (*top)->prev->n;
	(*top)->n = total;
	free((*top)->prev);
	(*top)->prev = NULL;
}

/**
 * nodeSub - a function which subtract the top two elements.
 * @top: a pointer to the top node of the stack.
 * @lineN: line number.
 */

void nodeSub(stack_t **top, unsigned int lineN)
{
	int total;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
		error2(8, lineN, "sub");

	(*top) = (*top)->next;
	total = (*top)->n - (*top)->prev->n;
	(*top)->n = total;
	free((*top)->prev);
	(*top)->prev = NULL;
}

/**
 * nodeDiv - a function which divide the top two elements.
 * @top: a pointer to the top node of the stack.
 * @lineN: line number.
 */

void nodeDiv(stack_t **top, unsigned int lineN)
{
	int total;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
		error2(8, lineN, "div");

	if ((*top)->n == 0)
		error2(9, lineN);

	(*top) = (*top)->next;
	total = (*top)->n / (*top)->prev->n;
	(*top)->n = total;
	free((*top)->prev);
	(*top)->prev = NULL;
}