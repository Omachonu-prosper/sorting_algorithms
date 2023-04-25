#include "sort.h"

/**
 * swap_nodes - Swap two nodes of a doubly linked list
 * @list: The starting head of the list
 * @n1: Node 1 to swap
 * @n2: Node 2 to swap
 */
void swap_nodes(listint_t **list, listint_t *n1, listint_t *n2)
{
	listint_t *tmp;

	tmp = n1->next;
	n1->next = n2->next;
	n2->next = tmp;

	if (n1->next)
		n1->next->prev = n1;
	if (n2->next)
		n2->next->prev = n2;

	tmp = n1->prev;
	n1->prev = n2->prev;
	n2->prev = tmp;

	if (n1->prev)
		n1->prev->next = n1;
	else
		*list = n1;
	if (n2->prev)
		n2->prev->next = n2;
	else
		*list = n2;
}

/**
 * insertion_sort_list - sort doubly linked list using Insertion sort
 * @list: The doubly linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *counter_node;

	if (list == NULL || (*list)->next == NULL)
		return;

	counter_node = (*list)->next;

	while (counter_node)
	{
		node = counter_node;

		while (node->prev && node->n < node->prev->n)
		{
			swap_nodes(list, node, node->prev);
			print_list(*list);
		}

		counter_node = counter_node->next;
	}
}
