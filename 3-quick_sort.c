#include "sort.h"

/**
 * quick_sort - call recursion function
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;
	recursion(array, size, array, size);
}

/**
 * recursion - sort array with recursion
 * @array: to sort
 * @size: size of the array
 * @beg: The complete array
 * @end: The size of the beg
 */
void recursion(int *array, size_t size, int *beg, size_t end)
{
	int *pivot = NULL;
	long int i = -1, value = 0;
	size_t j = 0;

	if (array == NULL || size <= 1)
		return;
	pivot = &array[size - 1];
	for (j = 0; j < size - 1; j++)
	{
		if (array[j] <= *pivot)
		{
			i++;
			if (&array[i] != &array[j])
			{
				value = array[i];
				array[i] = array[j];
				array[j] = value;
				print_array(beg, end);
			}
		}
	}
	i++;
	if (&array[i] != pivot)
	{
		value = array[i];
		array[i] = *pivot;
		*pivot = value;
		print_array(beg, end);
	}
	recursion(&array[0], i, beg, end);
	recursion(&array[i + 1], size - (i + 1), beg, end);
}
