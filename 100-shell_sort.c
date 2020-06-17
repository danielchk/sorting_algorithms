#include "sort.h"

/**
 * shell_sort - sort array whit shell alg.
 * @array: array to sort
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	int i, num, current;
	int sgnd = size;
	int indx = 0;

	if (array == NULL || size < 2)
		return;
	while (indx < (sgnd / 3))
		indx = indx * 3 + 1;
	if (size == 2)
		indx = 1;
	while (indx > 0)
	{
		for (i = indx; i < sgnd; i++)
		{
			num = i;
			while (num - indx >= 0)
			{
				if (array[num] < array[num - indx])
				{
					current = array[num];
					array[num] = array[num - indx];
					array[num - indx] = current;
				}
				else
					break;
				num -= indx;
			}
		}
		print_array(array, size);
		indx = (indx - 1) / 3;
	}
}
