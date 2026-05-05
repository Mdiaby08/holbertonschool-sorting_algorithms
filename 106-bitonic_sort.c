#include <stdio.h>
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
 * bitonic_merge - Merges a bitonic sequence in the given direction
 *
 * @array: The full array
 * @size: Total size of the array
 * @start: Start index of the sub-array
 * @count: Number of elements in the sub-array
 * @up: 1 for ascending order, 0 for descending
 */
static void bitonic_merge(int *array, size_t size,
			size_t start, size_t count, int up)
{
	size_t half;
	size_t i;

	if (count <= 1)
		return;

	half = count / 2;

	printf("Merging [%lu/%lu] (%s):\n", count, size, up ? "UP" : "DOWN");
	print_array(array + start, count);

	for (i = start; i < start + half; i++)
	{
		if ((up && array[i] > array[i + half]) ||
			(!up && array[i] < array[i + half]))
			swap(array, size, i, i + half);
	}

	printf("Result [%lu/%lu] (%s):\n", count, size, up ? "UP" : "DOWN");
	print_array(array + start, count);

	bitonic_merge(array, size, start, half, up);
	bitonic_merge(array, size, start + half, half, up);
}

/**
 * bitonic_recurse - Recursively builds a bitonic sequence then merges
 *
 * @array: The full array
 * @size: Total size of the array
 * @start: Start index of the sub-array
 * @count: Number of elements in the sub-array
 * @up: 1 for ascending, 0 for descending
 */
static void bitonic_recurse(int *array, size_t size,
			size_t start, size_t count, int up)
{
	size_t half;

	if (count <= 1)
		return;

	half = count / 2;

	bitonic_recurse(array, size, start, half, 1);
	bitonic_recurse(array, size, start + half, half, 0);
	bitonic_merge(array, size, start, count, up);
}

/**
 * bitonic_sort - Sorts an array using the Bitonic sort algorithm
 *
 * @array: The array to sort
 * @size: Number of elements in @array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_recurse(array, size, 0, size, 1);
}
