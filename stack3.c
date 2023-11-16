#include "monty.h"

/**
 * nodeMul - a function which multiplies of top two elements.
 * @top: a pointer to the top node of the stack.
 * @lineN: line number.
 */

void nodeMul(stack_t **top, unsigned int lineN)
{
	int total;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
		error2(8, lineN, "mul");

	(*top) = (*top)->next;
	total = (*top)->n * (*top)->prev->n;
	(*top)->n = total;
	free((*top)->prev);
	(*top)->prev = NULL;
}

/**
 * nodeMod - a function which calculates the modulus of two elements.
 * @top: a pointer to the top node of the stack.
 * @lineN: line number.
 */

void nodeMod(stack_t **top, unsigned int lineN)
{
	int total;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
		error2(8, lineN, "mod");

	if ((*top)->n == 0)
		error2(9, lineN);

	(*top) = (*top)->next;
	total = (*top)->n % (*top)->prev->n;
	(*top)->n = total;
	free((*top)->prev);
	(*top)->prev = NULL;
}
