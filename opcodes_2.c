#include "monty.h"

/**
 * m_add - Adds the top two elements of a stack
 * @stack: head reference of the stack
 * @line_number: Here we go again
 * Return: nothing
 */

void m_add(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;

	int sum = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}


	new = *stack;

	sum = new->n + new->next->n;

	m_pop(stack, line_number);
	(*stack)->n = sum;

}

/**
 * m_nop - Does nothing?
 * @stack: Head reference of the stack
 * @line_number: Round and around we go
 * Return: Nothing
 */

void m_nop(stack_t **stack, unsigned int line_number)
{
	(void)*stack;
	(void)line_number;
}
