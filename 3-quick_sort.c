#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: array to sort
 * @low: start index
 * @high: end index
 * @size: array size
 * Return: pivot index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low, j, tmp;

for (j = low; j < high; j++)
{
if (array[j] < pivot)
{
if (i != j)
{
tmp = array[i];
array[i] = array[j];
 array[j] = tmp;

/* Print ONLY if swap changes the array */
if (array[i] != array[j])
print_array(array, size);
}
i++;
}
}

if (i != high)
{
tmp = array[i];
array[i] = array[high];
array[high] = tmp;

/* Print ONLY if swap changes the array */
if (array[i] != array[high])
print_array(array, size);
}

return (i);
}

/**
 * quick_sort_rec - recursive quicksort
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
int pivot;

if (low < high)
{
pivot = lomuto_partition(array, low, high, size);
quick_sort_rec(array, low, pivot - 1, size);
quick_sort_rec(array, pivot + 1, high, size);
}
}

/**
 * quick_sort - sorts an array using Quick sort (Lomuto)
 * @array: array of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
if (!array || size < 2)
return;

quick_sort_rec(array, 0, size - 1, size);
}