#include "sort.h"

/**
 * selection_sort - sorts an array in ascending order using Selection sort
 * @array: The array to sort
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	int smallest, temp;
	size_t smallest_index, j, i;

	for (i = 0; i < size; i++)
	{
		smallest = array[i];
		smallest_index = i;

		for (j = i; j < size; j++)
		{
			if (array[j] < smallest)
			{
				smallest = array[j];
				smallest_index = j;
			}
		}

		if (smallest != array[i])
		{
			temp = array[i];
			array[i] = smallest;
			array[smallest_index] = temp;
			print_array(array, size);
		}
	}
}
