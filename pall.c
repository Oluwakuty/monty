#include "monty.h"

/**
 * f_pall - prints the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
*/

void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	for (h = *head; h != NULL; h = h->next)
	{
		printf("%d\n", h->n);
	}
}
