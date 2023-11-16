#include "monty.h"

/**
 * add - appends the top two elements of the stack.
 * @top: stack top
 * @count: line_number
 * Return: no return
*/

void add(stack_t **top, unsigned int count)
{
	stack_t *h;
	int len = 0, aux;

	for (h = *top; h; h = h->next)
	{
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	h = *top;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*top = h->next;
	free(h);
}
