#include "sort.h"

/**
 * counting_sort - counting sort
 *
 * @array: Array should be sorted
 * @size: Size of array
*/
void counting_sort(int *array, size_t size)
{
	int m = 0, *count, j, *arr;
	size_t i;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > m)
			m = array[i];
	}
	count = malloc((m + 1) * (sizeof(int)));
	if (count == NULL)
		return;
	for (j = 0; j <= m; j++)
		count[j] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (j = 1; j <= m; j++)
		count[j] += count[j - 1];
	print_array(count, m + 1);
	arr = malloc(size * sizeof(int));
	if (arr == NULL)
	{
		free(count);
		return;
	}
	for (i = 0; i < size; i++)
	{
		arr[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = arr[i];
	free(count);
	free(arr);
}
