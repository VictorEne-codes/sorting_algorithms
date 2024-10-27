#include "sort.h"

/**
 * swap_nodes - function to swap two nodes in doubly-linked list.
 * @head: input
 * @node1: input
 * @node2: input
 *
 * Return: void
 */

void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - a function to sorts a doubly linked list of integers.
 * @list: input
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *ins, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = temp)
	{
		temp = i->next;
		ins = i->prev;
		while (ins != NULL && i->n < ins->n)
		{
			swap_nodes(list, &ins, i);
			print_list((const listint_t *)*list);
		}
	}
}
