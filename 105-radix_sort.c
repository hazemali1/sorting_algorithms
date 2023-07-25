#include "sort.h"

/**
 * count - Counting sort
 *
 * @arr: My array
 * @array: Array should sort
 * @size: Size of array
 * @s: Position
*/
void count(int *arr, int *array, size_t size, int s)
{
	int h[10] = {0}, d;
	size_t j;

	for (j = 0; j < size; j++)
		h[(array[j] / s) % 10]++;
	for (d = 1; d < 10; d++)
		h[d] += h[d - 1];
	for (d = size - 1; d >= 0; d--)
	{
		arr[h[(array[d] / s) % 10] - 1] = array[d];
		h[(array[d] / s) % 10]--;
	}
	for (j = 0; j < size; j++)
		array[j] = arr[j];
}

/**
 * radix_sort - Radix sort
 *
 * @array: Array should be sorted
 * @size: Size of array
*/
void radix_sort(int *array, size_t size)
{
	int m = 0, *arr, s;
	size_t i;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > m)
			m = array[i];
	}
	arr = malloc(size * sizeof(int));
	if (arr == NULL)
		return;
	for (s = 1; m / s > 0; s *= 10)
	{
		count(arr, array, size, s);
		print_array(array, size);
	}
	free(arr);
}
