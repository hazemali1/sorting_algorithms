#include "sort.h"

/**
 * swap - swap function
 *
 * @w: pointer to node
 * @list: Linked list
 *
 * Return: Pointer to node
*/
listint_t *swap(listint_t *w, listint_t **list)
{
	listint_t *s, *d;

	s = w;
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
	return (s);
}

/**
 * cocktail_sort_list - Cocktail sort
 *
 * @list: Linked list should be sorted
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *s;
	int n = 1;

	if (!list || !(*list) || (*list)->next == NULL)
		return;
	s = *list;
	while (n == 1)
	{
		n = 0;
		while (s->next)
		{
			if (s->n > s->next->n)
			{
				s = swap(s->next, list);
				n = 1;
				print_list(*list);
			}
			s = s->next;
		}
		if (n == 1)
		{
			n = 0;
			while (s->prev)
			{
				if (s->n < s->prev->n)
				{
					s = swap(s, list);
					n = 1;
					print_list(*list);
				}
				else
					s = s->prev;
			}
		}
	}
}
