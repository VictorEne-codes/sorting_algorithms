#include "sort.h"

/**
 * swap_num - a function to swap two integers
 * @a: input
 * @b: input
 */

void swap_num(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - a function to sort an array of integers
 * @array: input
 * @size: input
 *
 * Return: voide
 */

void selection_sort(int *array, size_t size)
{
	int *small;
	size_t i, k;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		small = array + i;
		for (k = i + 1; k < size; k++)
			small = (array[k] < *small) ? (array + k) : small;

		if ((array + i) != small)
		{
			swap_num(array + i, small);
			print_array(array, size);
		}
	}
}
