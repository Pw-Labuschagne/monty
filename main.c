#include "monty.h"
#include <stdlib.h>

/**
 * free_stack - Used to free list known as dlistint_t
 * @ptr: A pointer to lsit to be freed
 * Return: Nothing
 */

void free_stack(stack_t *ptr)
{
	stack_t *_free;

	while (ptr != NULL)
	{
		_free = ptr->next;
		free(ptr);
		ptr = _free;
	}
}

/**
 * main - Intepreter for Monty ByteCode files
 * @argc: Ammount of arguments fed
 * @argv: String of arguments fed
 * Return: EXIT_SUCCESS if successfull else EXIT_FAILURE
 */

int main(int argc, char *argv[])
{
	FILE *monty_f = NULL;
	unsigned int line_number = 1;
	stack_t *stack = NULL;
	char buf[100];
	unsigned int num = 0;
	char *token = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_f = fopen(argv[1], "r");

	if (monty_f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fscanf(monty_f, "%s %u", buf, &num) != -1)
	{
		token = strtok(buf, " \t\n\r\v\f'$'");
		if (token != NULL && token[0] != '#')
		{
			opcode_type(&stack, line_number, token);
		}
		line_number++;
	}

	free_stack(stack);
	stack = NULL;
	fclose(monty_f);
	exit(EXIT_SUCCESS);
}

/**
 * opcode_type - Determines the type of opcode used by monty
 * @stack: The linked list used as a stack
 * @line_number: The counter of lines in monty file
 * @token: Type of opcode to be used
 * Return: Nothing
 */

void opcode_type(stack_t **stack, unsigned int line_number, char *token)
{
	int count = 0;

	instruction_t opcode_func[] = {
		{"push", m_push},
		{"pall", m_pall},
		{"pint", m_pint},
		{"pop", m_pop},
		{"swap", m_swap},
		{"add", m_add},
		{"nop", m_nop},
		{NULL, NULL}
	};

	while (opcode_func[count].opcode)
	{
		if (strcmp(opcode_func[count].opcode, token) == 0)
		{
			opcode_func[count].f(stack, line_number);
			return;
		}
		count++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
	free_stack(*stack);

	exit(EXIT_FAILURE);

}
