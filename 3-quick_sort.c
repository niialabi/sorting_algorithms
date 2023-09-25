#include "sort.h"


/**
 * swap - Swap two integers of an array.
 * @a: integer to swap.
 * @b: integer to swap.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_part - according to lomuto Order a subset of an array of integers.
 * @array: array of integers
 * @size: size of array.
 * @left: start index of the subset to order.
 * @right: end index of the subset to order.
 *
 * Return: index.
 */
int lomuto_part(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomu_sort - Through recursion implement the quicksort.
 * @array: Array of integers 
 * @size: Size of the array.
 * @left: Start index of the array to order.
 * @right: End index of the array to order.
 
 */
void lomu_sort(int *array, size_t size, int left, int right)
{
	int i;

	if (right - left > 0)
	{
		i = lomuto_part(array, size, left, right);
		lomu_sort(array, size, left, i - 1);
		lomu_sort(array, size, i + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomu_sort(array, size, 0, size - 1);
}
