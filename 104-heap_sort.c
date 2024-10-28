#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);

/**
 * swap_ints - entry point swaps two integers in an array.
 * @a: first input.
 * @b: second input.
 */
void swap_ints(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

/**
 * max_heapify - Entry point turns a binary tree into a complete binary heap.
 * @array: array of integers.
 * @size: size of the array/tree.
 * @base: index of the base row of the tree.
 * @root: root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t l, r, large;

	l = 2 * root + 1;
	r = 2 * root + 2;
	large = root;

	if (l < base && array[l] > array[large])
		large = l;
	if (r < base && array[r] > array[large])
		large = r;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - entry point sorts an array of integers in ascending
 *             order using the heap sort.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_ints(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
