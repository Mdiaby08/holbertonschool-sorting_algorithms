#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * print_merge - Prints the left, right, and merged result
 *
 * @left: Left sub-array
 * @l_size: Size of the left sub-array
 * @right: Right sub-array
 * @r_size: Size of the right sub-array
 */
static void print_merge(int *left, size_t l_size,
			int *right, size_t r_size)
{
	size_t i;

	printf("Merging...\n[left]: ");
	for (i = 0; i < l_size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", left[i]);
	}
	printf("\n[right]: ");
	for (i = 0; i < r_size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", right[i]);
	}
	printf("\n");
}

/**
 * merge - Merges two sub-arrays into a sorted result
 *
 * @left: Left sub-array
 * @l_size: Size of the left sub-array
 * @right: Right sub-array
 * @r_size: Size of the right sub-array
 * @dest: Destination array to write the merged result
 */
static void merge(int *left, size_t l_size,
		int *right, size_t r_size, int *dest)
{
	size_t i;
	size_t j;
	size_t k;

	print_merge(left, l_size, right, r_size);

	i = 0;
	j = 0;
	k = 0;
	while (i < l_size && j < r_size)
	{
		if (left[i] <= right[j])
			dest[k++] = left[i++];
		else
			dest[k++] = right[j++];
	}
	while (i < l_size)
		dest[k++] = left[i++];
	while (j < r_size)
		dest[k++] = right[j++];

	printf("[Done]: ");
	for (k = 0; k < l_size + r_size; k++)
	{
		if (k > 0)
			printf(", ");
		printf("%d", dest[k]);
	}
	printf("\n");
}

/**
 * merge_recurse - Recursively splits and merges sub-arrays
 *
 * @array: The working sub-array (slice of the original)
 * @tmp: Temporary buffer of the same size as the original array
 * @size: Number of elements in @array
 */
static void merge_recurse(int *array, int *tmp, size_t size)
{
	size_t l_size;
	size_t r_size;

	if (size < 2)
		return;

	l_size = size / 2;
	r_size = size - l_size;

	merge_recurse(array, tmp, l_size);
	merge_recurse(array + l_size, tmp, r_size);

	merge(array, l_size, array + l_size, r_size, tmp);

	for (l_size = 0; l_size < size; l_size++)
		array[l_size] = tmp[l_size];
}

/**
 * merge_sort - Sorts an array of integers using the Merge sort algorithm
 *
 * @array: The array to sort
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;

	merge_recurse(array, tmp, size);

	free(tmp);
}
