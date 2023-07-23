#include "sort.h"

/**
 * help - Helping function
 *
 * @array: Array
 * @size: Size of array
 * @s: root
 * @x: Size
*/
void help(int *array, size_t size, size_t s, size_t x)
{
	size_t d = s, l = 2 * s + 1, r = 2 * s + 2;
	int w;

	if (l < size && array[l] > array[d])
		d = l;
	if (r < size && array[r] > array[d])
		d = r;
	if (d != s)
	{
		w = array[s];
		array[s] = array[d];
		array[d] = w;
		print_array(array, x);
		help(array, size, d, x);
	}
}

/**
 * heap_sort - Heap sort
 *
 * @array: Array should be sorted
 * @size: Size of array
*/
void heap_sort(int *array, size_t size)
{
	int s, d;

	if (size < 2)
		return;
	for (s = size / 2 - 1; s >= 0; s--)
		help(array, size, s, size);
	for (s = size - 1; s > 0; s--)
	{
		d = array[0];
		array[0] = array[s];
		array[s] = d;
		print_array(array, size);
		help(array, s, 0, size);
	}
}
