#include "monty.h"

/**
 * _div - function to div top of stack
 * @stack: pointer to list
 * @num_line: number of line
 *
 * Return: nothing
 */
void _div(stack_t **stack, unsigned int num_line)
{
	int div = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", num_line);
		free(global.buffer);
		fclose(global.file);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", num_line);
		free(global.buffer);
		fclose(global.file);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		div = (*stack)->n;
		_pop(stack, num_line);
		(*stack)->n /= div;
	}
}
