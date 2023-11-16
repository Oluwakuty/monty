#include "monty.h"

/**
 * addnode - append node to the head stack
 * @top: top of the stack
 * @m: new_value
 * Return: no return
*/

void addnode(stack_t **top, int m)
{

	stack_t *new_node, *aux;

	aux = *top;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = m;
	new_node->next = *top;
	new_node->prev = NULL;
	*top = new_node;
}

/**
 * addqueue - append node to the tail stack
 * @top: top of the stac
 * @m: new_value
 * Return: no return
*/

void addqueue(stack_t **top, int m)
{
	stack_t *new_node, *aux;

	aux = *top;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = m;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*top = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}

/**
* free_stack - frees a doubly linked list
* @top: top of the stack
*/

void free_stack(stack_t *top)
{
	stack_t *aux;

	for (aux = top; top; top = aux)
	{
		aux = top->next;
		free(top);
	}
}
