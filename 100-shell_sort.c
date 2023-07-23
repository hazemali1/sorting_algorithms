#include "sort.h"

/**
 * shell_sort - Shell sort
 *
 * @array: Array should be sorted
 * @size: Size of array
*/
void shell_sort(int *array, size_t size)
{
	size_t g = 1, s, d;
	int w;

	if (size < 2)
		return;
	while (g < size)
		g = g * 3 + 1;
	while (g >= 1)
	{
		g = g / 3;
		for (s = g; s < size; s++)
		{
			for (d = s; d >= g && array[d - g] > array[d]; d -= g)
			{
				w = array[d];
				array[d] = array[d - g];
				array[d - g] = w;
			}
		}
		print_array(array, size);
	}
}
