#include "monty.h"

/**
 * pint - output the top
 * @top: stack top
 * @count: line_number
 * Return: no return
*/

void pint(stack_t **top, unsigned int count)
{
	do {
		if (*top == NULL)
		{
			fprintf(stderr, "L%u: can't pint, stack empty\n", count);
			fclose(bus.file);
			free(bus.content);
			free_stack(*top);
			exit(EXIT_FAILURE);
		}
		else
		{
			printf("%d\n", (*top)->n);
			break;
		}
	} while (1);
}

/**
 * pop - output the top
 * @top: stack top
 * @count: line_number
 * Return: no return
*/

void pop(stack_t **top, unsigned int count)
{
	stack_t *h;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	h = *top;
	*top = h->next;
	free(h);
}

/**
 * swap - append the top with two elements of the stack.
 * @top: stack top
 * @count: line_number
 * Return: no return
*/

void swap(stack_t **top, unsigned int count)
{
	stack_t *h;
	int len = 0, aux;

	do {
		h = *top;
		while (h)
		{
			h = h->next;
			len++;
		}
		if (len < 2)
		{
			fprintf(stderr, "L%d: can't swap, stack too short\n", count);
			fclose(bus.file);
			free(bus.content);
			free_stack(*top);
			exit(EXIT_FAILURE);
		}
		h = *top;
		aux = h->n;
		h->n = h->next->n;
		h->next->n = aux;
	} while (len >= 2);
}
