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
 * count_sort_digit - Sorts array by a specific digit using counting sort
 *
 * @array: The array to sort
 * @size: Number of elements in @array
 * @exp: The current digit position (1, 10, 100, ...)
 * @output: Temporary buffer of the same size as @array
 *
 * Return: 1 on success, 0 on failure
 */
static void count_sort_digit(int *array, size_t size, int exp, int *output)
{
	int count[10];
	int i;

	for (i = 0; i < 10; i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = (int)size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
}

/**
 * radix_sort - Sorts an array of integers using the LSD Radix sort algorithm
 *
 * @array: The array to sort
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
	int max;
	int exp;
	int *output;

	if (!array || size < 2)
		return;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count_sort_digit(array, size, exp, output);
		print_array(array, size);
	}

	free(output);
}
