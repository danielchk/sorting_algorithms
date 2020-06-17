#include "sort.h"

/**
 * quick_sort - sort array with quicksorth
 * @array: to sort
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	recursion(array, size, array, size);
}

/**
 * recursion - recursion function that sort
 * @array: array
 * @size: size
 * @mainarr: The complete array
 * @mainsize: The size of the mainarr
 */
void recursion(int *array, size_t size, int *mainarr, size_t mainsize)
{
	int *arr = NULL;
	int i = -1, current = 0;
	size_t j = 0;

	if (array == NULL || size <= 1)
		return;
	arr = &array[size - 1];
	for (j = 0; j < size - 1; j++)
	{
		if (array[j] < *arr)
		{
			i++;
			if (&array[i] != &array[j])
			{
				current = array[i];
				array[i] = array[j];
				array[j] = current;
				print_array(mainarr, mainsize);
			}
		}
	}
	i++;
	if (&array[i] != arr)
	{
		current = array[i];
		array[i] = *arr;
		*arr = current;
		print_array(mainarr, mainsize);
	}
	recursion(&array[0], i, mainarr, mainsize);
	recursion(&array[i + 1], size - (i + 1), mainarr, mainsize);
}
