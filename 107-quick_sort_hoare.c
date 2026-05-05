#include "sort.h"

/**
 * swap - Swaps two integers in an array and prints the result
 *
 * @array: The array containing the elements
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
 * hoare_partition - Partitions a sub-array using Hoare scheme
 *
 * @array: The full array
 * @size: Total size of the array
 * @lo: Left boundary index
 * @hi: Right boundary index (pivot)
 *
 * Return: Final index of the pivot after partition
 */
static size_t hoare_partition(int *array, size_t size, size_t lo, size_t hi)
{
	int pivot;
	size_t i;
	size_t j;

	pivot = array[hi];
	i = lo;
	j = hi - 1;

	while (1)
	{
		while (array[i] < pivot)
			i++;
		while (j > lo && array[j] > pivot)
			j--;
		if (i >= j)
			break;
		if (array[i] != array[j])
			swap(array, size, i, j);
		i++;
		if (j > lo)
			j--;
	}
	if (array[i] != array[hi])
		swap(array, size, i, hi);
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
