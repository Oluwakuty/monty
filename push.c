#include "monty.h"

/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/

void f_push(stack_t **head, unsigned int counter)
{
	int m, l = 0, vlag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			l++;
		while (bus.arg[l] != '\0')
		{
			if (bus.arg[l] > 57 || bus.arg[l] < 48)
				vlag = 1;
			l++;
		}
		if (vlag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	m = atoi(bus.arg);

	if (bus.lifi == 0)
		addnode(head, m);
	else
		addqueue(head, m);
}


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


/**
  *f_nop- nothing
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void f_nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}
