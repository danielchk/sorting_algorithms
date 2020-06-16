#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * @list: doubly linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		while (current->prev && current->n < current->prev->n)
		{
			current->prev->next = current->next;
			if (current->next)
			{
				current->next->prev = current->prev;
			}

			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;

			if (!current->prev)
			{
				*list = current;
			}
			else
			{
				current->prev->next = current;
			}

			print_list(*list);
		}
		current = current->next;
	}
}
