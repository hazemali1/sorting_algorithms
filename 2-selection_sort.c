#include "sort.h"

/**
 * selection_sort - Selction sort
 *
 * @array: Array sould be sorted
 * @size: Size of array
*/
void selection_sort(int *array, size_t size)
{
	size_t s, d, q;
	int w;

	if (size < 2)
		return;
	for (s = 0; s < size - 1; s++)
	{
		q = s;
		for (d = s + 1; d < size; d++)
		{
			if (array[d] < array[q])
				q = d;
		}
		if (q != s)
		{
			w = array[q];
			array[q] = array[s];
			array[s] = w;
			print_array(array, size);

		}
	}
}
