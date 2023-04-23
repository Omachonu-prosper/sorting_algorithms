#include "sort.h"

/**
 * bubble_sort - sorts an array ascending order using the Bubble sort algorithm
 * @array: the array to sort
 * size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t n = size;
	int temp;
	size_t i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (j + 1 != n)
			{
				if (array[j] > array[j+1])
				{
					temp = array[j];
					array[j] = array[j+1];
					array[j+1] = temp;
					print_array(array, n);
				}
			}
		}
	}
}
