#include "sort.h"

/**
 * swap_num - function to swap two integers in an array.
 * @a: input
 * @b: input
 *
 * Return: void
 */

void swap_num(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - a function to sort an array of integers
 * @array: input.
 * @size: input
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, length = size;
	bool bubb = false;

	if (array == NULL || size < 2)
		return;

	while (bubb == false)
	{
		bubb = true;
		for (i = 0; i < length - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_num(array + i, array + i + 1);
				print_array(array, size);
				bubb = false;
			}
		}
		length--;
	}
}
