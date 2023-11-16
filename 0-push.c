#include "monty.h"

/**
 * push - append node to the stack
 * @top: stack top
 * @count: line_number
 * Return: no return
*/

void push(stack_t **top, unsigned int count)
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
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(bus.file);
			free(bus.content);
			free_stack(*top);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	m = atoi(bus.arg);

	if (bus.lifi == 0)
		addnode(top, m);
	else
		addqueue(top, m);
}


/**
 * pall - output the stack
 * @top: stack top
 * @count: nothing
 * Return: no return
*/

void pall(stack_t **top, unsigned int count)
{
	stack_t *h;
	(void)count;

	for (h = *top; h != NULL; h = h->next)
	{
		printf("%d\n", h->n);
	}
}


/**
  *nop - nothing
  *@top: stack top
  *@count: line_number
  *Return: no return
 */
void nop(stack_t **top, unsigned int count)
{
	(void) count;
	(void) top;
}
