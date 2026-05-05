#include "sort.h"

/**
 * swap - Swaps two integers and prints the full array
 *
 * @array: The full array
 * @size: Total size of the array
 * @i: Index of the first element
 * @j: Index of the second element
 */
static void swap(int *array, size_t size, size_t i, size_t j)
{
	int tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
	print_array(array, size);
}

/**
 * hoare_partition - Partitions array using Hoare scheme, pivot = last element
 *
 * @array: The full array
 * @size: Total size of the array
 * @lo: Left boundary index
 * @hi: Right boundary index (pivot position)
 *
 * Return: Final index where pivot is placed
 */
static size_t hoare_partition(int *array, size_t size, size_t lo, size_t hi)
{
	int pivot;
	size_t i;
	size_t j;

	pivot = array[hi];
	i = lo;
	j = hi;

	while (1)
	{
		while (array[i] < pivot)
			i++;
		while (j > lo && array[j] > pivot)
			j--;
		if (i >= j)
			break;
		swap(array, size, i, j);
		if (i < hi)
			i++;
		if (j > lo)
			j--;
	}
	return (i);
}

/**
 * quick_recurse - Recursively sorts sub-arrays using Hoare partition
 *
 * @array: The full array
 * @size: Total size of the array
 * @lo: Left boundary index
 * @hi: Right boundary index
 */
static void quick_recurse(int *array, size_t size, size_t lo, size_t hi)
{
	size_t p;

	if (lo >= hi)
		return;

	p = hoare_partition(array, size, lo, hi);

	if (p > lo)
		quick_recurse(array, size, lo, p - 1);
	quick_recurse(array, size, p + 1, hi);
}

/**
 * quick_sort_hoare - Sorts an array using Quick sort with Hoare partition
 *
 * @array: The array to sort
 * @size: Number of elements in @array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_recurse(array, size, 0, size - 1);
}
