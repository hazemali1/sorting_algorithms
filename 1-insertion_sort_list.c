#include "sort.h"

/**
 * insertion_sort_list - Insertion sort
 *
 * @list: Linked list should sorted
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *s, *d;

	if (list == NULL || (*list)->next == NULL)
		return;
	s = *list;
	s = s->next;
	while (s)
	{
		while (s->prev && s->prev->n > s->n)
		{
			d = s->prev;
			d->next = s->next;
			if (s->next)
				s->next->prev = d;
			s->next = d;
			s->prev = d->prev;
			d->prev = s;
			if (s->prev)
				s->prev->next = s;
			else
				*list = s;
			print_list(*list);
		}
		s = s->next;
	}
}
