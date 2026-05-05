#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Returns the largest value in an array
 *
 * @array: The array to search
 * @size: Number of elements in the array
 *
 * Return: The maximum integer found
 */
static int get_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm
 *
 * @array: The array to sort
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	int *count;
	int *output;
	int max;
	size_t i;
	int j;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;

	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(count);
		return;
	}

	for (j = 0; j <= max; j++)
		count[j] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (j = 1; j <= max; j++)
		count[j] += count[j - 1];

	print_array(count, max + 1);

	for (i = size; i > 0; i--)
	{
		output[count[array[i - 1]] - 1] = array[i - 1];
		count[array[i - 1]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
