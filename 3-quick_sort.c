#include "sort.h"

/**
 * help - Helping function
 *
 * @array: Array should be sorted
 * @s: first
 * @d: last
*/
void help(int *array, int s, int d)
{
	int q, w, f, e;

	q = array[d];
	w = s - 1;
	for (f = s; f <= d - 1; f++)
	{
		if (array[f] < q)
		{
			w++;
			e = array[w];
			array[w] = array[f];
			array[f] = e;
		}
	}
	e = array[w + 1];
	array[w + 1] = array[d];
	array[d] = e;
	return (w + 1);
}

/**
 * quick - Quick function
 *
 * @array: Array should be sorted
 * @s: first
 * @d: last
*/
void quick(int *array, int s, int d)
{
	int q;

	if (s < d)
	{
		q = help(array, s, d);
		quick(array, s, q - 1);
		quick(array, q + 1, d)
	}
}

/**
 * quick_sort - Quick sort
 *
 * @array: Array should be sorted
 * @size: Size of array
*/
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quick(array, 0, size - 1);
}
