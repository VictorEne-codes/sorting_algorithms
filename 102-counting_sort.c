#include "sort.h"

/**
 * get_max_val - entry point gets the max value in an array of integers.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Return: The max integer in the array.
 */
int get_max_val(int *array, int size)
{
	int max_val, i;

	for (max_val = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max_val)
			max_val = array[i];
	}

	return (max_val);
}

/**
 * counting_sort - entry point sorts an array of integers in ascending order
 *                 using the counting sort.
 * @array: the array of to be sorted.
 * @size: size of the array.
 *
 * Description: Prints the counting array after setting it up.
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max_val, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max_val = get_max_val(array, size);
	count = malloc(sizeof(int) * (max_val + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max_val + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max_val + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max_val + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
