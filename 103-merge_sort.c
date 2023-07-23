#include "sort.h"

/**
 * merge - Merge
 *
 * @array: Array i want to merge
 * @l: left
 * @m: Middle
 * @r: Right
 * @arr: pointer
*/
void merge(int *array, int l, int m, int r, int *arr)
{
	int s, d = 0, q = 0, w = l, *left, *right;

	left = &arr[0];
	right = &arr[m - l + 1];
	for (s = 0; s < m - l + 1; s++)
		left[s] = array[l + s];
	for (s = 0; s < r - m; s++)
		right[s] = array[m + 1 + s];
	while (d < (m - l + 1) && q < r - m)
	{
		if (left[d] <= right[q])
		{
			array[w] = left[d];
			d++;
		}
		else
		{
			array[w] = right[q];
			q++;
		}
		w++;
	}
	while (d < (m - l + 1))
	{
		array[w] = left[d];
		d++, w++;
	}
	while (q < r - m)
	{
		array[w] = right[q];
		q++, w++;
	}
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, d);
	printf("[right]: ");
	print_array(right, q);
	printf("[Done]: ");
	print_array(&array[l], d + q);
}

/**
 * mergesort - Merge sort function
 *
 * @array: Array should be merge
 * @l: left
 * @r: Right
 * @arr: Pointer
*/
void mergesort(int *array, int l, int r, int *arr)
{
	int m;

	m = (l + r) / 2;
	if ((l + r) % 2 == 0)
		m -= 1;
	if (m >= l)
	{
		mergesort(array, l, m, arr);
		mergesort(array, m + 1, r, arr);
		merge(array, l, m, r, arr);
	}
}

/**
 * merge_sort - Merge sort
 *
 * @array: Array should be sorted
 * @size: Size of array
*/
void merge_sort(int *array, size_t size)
{
	int *arr;
	size_t s;

	if (size < 2)
		return;
	arr = malloc(size * sizeof(int));
	if (arr == NULL)
		return;
	for (s = 0; s < size; s++)
		arr[s] = 0;
	mergesort(array, 0, size - 1, arr);
	free(arr);
}
