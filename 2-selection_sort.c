#include "sort.h"

/**
 * selection_sort - sort array of integers
 * @array: array to sort
 * @size: size of Array
 */
void selection_sort(int *array, size_t size)
{
	size_t tmp = 0, current = 0;
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		current = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[i] > array[j] && array[current] > array[j])
				current = j;
		}
		if (current != i)
		{
			tmp = array[i];
			array[i] = array[current];
			array[current] = tmp;
			print_array(array, size);
		}
	}
}
