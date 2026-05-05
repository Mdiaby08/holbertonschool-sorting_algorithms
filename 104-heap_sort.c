#include "sort.h"

/**
 * swap - Swaps two integers in an array
 *
 * @array: The array containing the elements
 * @size: Size of the array (for printing)
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
 * sift_down - Sifts down a node to maintain the max-heap property
 *
 * @array: The array representing the heap
 * @size: Total size of the array (for printing)
 * @root: Index of the node to sift down
 * @end: Index of the last element in the current heap
 */
static void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t largest;
	size_t left;
	size_t right;

	while (1)
	{
		largest = root;
		left = 2 * root + 1;
		right = 2 * root + 2;

		if (left <= end && array[left] > array[largest])
			largest = left;

		if (right <= end && array[right] > array[largest])
			largest = right;

		if (largest == root)
			break;

		swap(array, size, root, largest);
		root = largest;
	}
}

/**
 * build_heap - Builds a max-heap from an unsorted array
 *
 * @array: The array to heapify
 * @size: Number of elements in @array
 */
static void build_heap(int *array, size_t size)
{
	size_t i;

	i = size / 2;
	while (i > 0)
	{
		i--;
		sift_down(array, size, i, size - 1);
	}
}

/**
 * heap_sort - Sorts an array of integers using the Heap sort algorithm
 *
 * @array: The array to sort
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (!array || size < 2)
		return;

	build_heap(array, size);

	end = size - 1;
	while (end > 0)
	{
		swap(array, size, 0, end);
		end--;
		sift_down(array, size, 0, end);
	}
}
