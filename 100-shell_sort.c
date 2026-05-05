#include "sort.h"

/**
 * shell_sort - sorts an array using Shell sort (Knuth sequence)
 * @array: array of integers
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
size_t gap = 1, i, j;
int temp;

if (!array || size < 2)
return;

/* Build initial Knuth gap */
while (gap < size / 3)
gap = gap * 3 + 1;

/* Decrease gap and perform gapped insertion sort */
while (gap > 0)
{
for (i = gap; i < size; i++)
{
temp = array[i];
j = i;

while (j >= gap && array[j - gap] > temp)
{
array[j] = array[j - gap];
j -= gap;
}

array[j] = temp;
}

print_array(array, size); /* print after each gap reduction */
gap = (gap - 1) / 3;
}
}
