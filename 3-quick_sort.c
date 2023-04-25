#include "sort.h"
#include <stdio.h>

/**
 * swap - Swap to elements in an array
 * @array: The array holding the elements
 * @i1: the index of the element to swap
 * @i2: the index of the element to swap
 */
void swap(int *array, size_t i1, size_t i2)
{
	int temp;

	if (i1 == i2)
		return;

	temp = array[i1];
	array[i1] = array[i2];
	array[i2] = temp;
}

/**
 * lomuto_partition - Partition the array
 * @array: The array to partition an element
 * @low: Where to start partitioning the array
 * @high: where to stop partitioning the array
 * @size: The size of the array
 *
 * Return: the new location the pivot was placed in
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t current = low - 1;
	size_t i;

	for (i = low; i < high; i++)
	{
		if (array[i] < pivot)
		{
			current++;
			swap(array, i, current);
		}
	}
	swap(array, high, current + 1);
	print_array(array, size);
	return (current + 1);
}

/**
 * qs - Implements quick sort recursively
 * @array: The array to sort
 * @low: The index of the array to start sorting from
 * @high: The index of the array to stop sorting at
 * @size: the size of the array
 */
void qs(int *array, size_t low, size_t high, size_t size)
{
	size_t par;

	if (low < high)
	{
		par = lomuto_partition(array, low, high, size);

		if (par > 0)
			qs(array, low,  par - 1, size);
		qs(array, par + 1, high, size);
	}
}

/**
 * quick_sort - Used as a refrence to call the qs function
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	qs(array, 0, size - 1, size);
}
