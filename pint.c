#include "monty.h"

/**
 * f_pint - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/

void f_pint(stack_t **head, unsigned int counter)
{
	do {
		if (*head == NULL)
		{
			fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
		else
		{
			printf("%d\n", (*head)->n);
			break;
		}
	} while (1);
}
