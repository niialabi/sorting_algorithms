#include "sort.h"
#include <stdio.h>
/**
 * insertion_sort_list - sort doubly linked list
 * @list: head pointer to list
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *hold_node, *new_node;

	new_node = *list;
	while (new_node)
	{
		while (new_node->next && (new_node->n > new_node->next->n))
		{
			hold_node = new_node->next;
			new_node->next = hold_node->next;
			hold_node->prev = new_node->prev;
			if (new_node->prev != NULL)
				new_node->prev->next = hold_node;
			if (hold_node->next != NULL)
				hold_node->next->prev = new_node;
			new_node->prev = hold_node;
			hold_node->next = new_node;
			if (hold_node->prev)
				new_node = hold_node->prev;
			else
				*list = hold_node;
			print_list(*list);
		}
		new_node = new_node->next;
	}
}
