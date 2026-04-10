#include "sort.h"

/**
 * insertion_sort_list - Trie une liste doublement chaînée par insertion
 * @list: Double pointeur vers la tête de la liste
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *node_a, *node_b, *prev_node;

	if (!list || !*list || !(*list)->next)
	{
		return;
	}
	curr = (*list)->next;
	while (curr)
	{
		node_b = curr->next;
		prev_node = curr->prev;

		while (prev_node && curr->n < prev_node->n)
		{
			node_a = curr->prev;

			if (node_a->prev)
				node_a->prev->next = curr;
			else
				*list = curr;
			if (curr->next)
				curr->next->prev = node_a;

			node_a->next = curr->next;
			curr->prev = node_a->prev;
			curr->next = node_a;
			node_a->prev = curr;

			print_list(*list);
			prev_node = curr->prev;
		}
		curr = node_b;
	}
}
