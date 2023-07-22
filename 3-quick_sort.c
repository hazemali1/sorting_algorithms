#include "sort.h"

/**
 * help - Helping function
 *
 * @array: Array should be sorted
 * @s: first
 * @d: last
 * @size: Size of array
 *
 * Return: Int
*/
int help(int *array, int s, int d, size_t size)
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
			print_array(array, size);
		}
	}
	e = array[w + 1];
	array[w + 1] = array[d];
	array[d] = e;
	print_array(array, size);
	return (w + 1);
}

/**
 * quick - Quick function
 *
 * @array: Array should be sorted
 * @s: first
 * @d: last
 * @size: Size of array
*/
void quick(int *array, int s, int d, size_t size)
{
	int q;

	if (s < d)
	{
		q = help(array, s, d, size);
		quick(array, s, q - 1, size);
		quick(array, q + 1, d, size);
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
	quick(array, 0, size - 1, size);
}
