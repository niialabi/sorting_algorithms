#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the array
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, idx;
	int tmp;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[idx])
				idx = j;
		}
		if (idx != i)
		{
			tmp = array[i];
			array[i] = array[idx];
			array[idx] = tmp;
			print_array(array, size);
		}
	}
}
