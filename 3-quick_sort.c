#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_num - a function to swap two integers
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
 * lomuto_partition - a function to order a subset of an array of integers
 * @array: input
 * @s: input
 * @l: input
 * @r: input
 *
 * Return: int
 */

int lomuto_partition(int *array, size_t s, int l, int r)
{
	int *p, a, b;

	p = array + r;
	for (a = b = l; b < r; b++)
	{
		if (array[b] < *p)
		{
			if (a < b)
			{
				swap_num(array + b, array + a);
				print_array(array, s);
			}
			a++;
		}
	}

	if (array[a] > *p)
	{
		swap_num(array + a, p);
		print_array(array, s);
	}

	return (a);
}

/**
 * lomuto_sort - a function to implement the quicksort algorithm
 * @array: input
 * @s: input
 * @l: input
 * @r: input
 *
 * Return: void
 */

void lomuto_sort(int *array, size_t s, int l, int r)
{
	int part;

	if (r - l > 0)
	{
		part = lomuto_partition(array, s, l, r);
		lomuto_sort(array, s, l, part - 1);
		lomuto_sort(array, s, part + 1, r);
	}
}

/**
 * quick_sort - a function to sort an array of integers in ascending
 * @array: input
 * @size: input
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
