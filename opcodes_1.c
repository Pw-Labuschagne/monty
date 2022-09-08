#include "monty.h"

/**
 * m_push - The opcode push pushes an element to the stack
 * Usage: push <int>
 * @stack: Head reference to the stack
 * @line_number: An integer that needs to be added to the stack
 * Return: Nothing
 */

void m_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(new_node);
		exit(EXIT_FAILURE);
	}

	new_node->n = line_number;
	new_node->prev = NULL;

	if (*stack == NULL)
	{
		new_node->next = NULL;
		*stack = new_node;
		return;
	}

	(*stack)->prev = new_node;
	new_node->next = *stack;

	*stack = new_node;
}

/**
 * m_pall - Prints all the values on the stack, starting from top of stack
 * @stack: Head reference to the stack
 * @line_number: Still figuring this one out
 * Return: Nothing
 */

void m_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *pall_stack;

	pall_stack = *stack;

	(void)line_number;

	if (pall_stack == NULL)
		return;

	while (pall_stack != NULL)
	{
		printf("%d\n", pall_stack->n);
		pall_stack = pall_stack->next;
	}
}

/**
 * m_pint - Prints the value at the top of the stack
 * @stack: Head reference of the stack
 * @line_number: Still no idea
 * Return: Nothing
 */

void m_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *pint_stack;

	pint_stack = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	} else
	{
		printf("%d\n", pint_stack->n);
	}

}

/**
 * m_pop - Removes the top element of the stack
 * @stack: Head reference of the stack
 * @line_number: Now I am assuming it's the integer>?
 * Return: nothing
 */

void m_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *pop_stack = NULL;

	pop_stack = (*stack)->next;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	*stack = pop_stack;

	if (*stack == NULL)
		return;

	(*stack)->prev = NULL;

}


/**
 * m_swap - Swaps the two top elements of the stack
 * @stack: Head reference of the stack
 * @line_number: Okay still don't know
 * Return: Nothing
 */

void m_swap(stack_t **stack, unsigned int line_number)
{

	stack_t *swap_stack = NULL;

	int temp = 0;

	swap_stack = *stack;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		free_stack(swap_stack);
		exit(EXIT_FAILURE);
	}

	swap_stack = *stack;

	temp = swap_stack->next->n;

	swap_stack->next->n = swap_stack->n;
	swap_stack->n = temp;

}
