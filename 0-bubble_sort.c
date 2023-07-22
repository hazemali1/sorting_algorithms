#include "sort.h"

/**
 * bubble_sort - Bubble sort
 *
 * @array: Array sould sort
 * @size: Size of array
*/
void bubble_sort(int *array, size_t size)
{
	size_t s, d;
	int q;

	if (size < 2)
		return;
	for (s = 0; s < size - 1; s++)
	{
		for (d = 0; d < size - s - 1; d++)
		{
			if (array[d] > array[d + 1] && array[d + 1])
			{
				q = array[d];
				array[d] = array[d + 1];
				array[d + 1] = q;
				print_array(array, size);
			}
		}
	}
}
