#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 30
typedef enum { DEFAULT = 0, ASCENDING = 1, DESCENDING = 2 } Direction;

void(*Sort)(int* input_arry, int input_arry_first_element, int input_arry_last_element, Direction direction);
void BubbleSort(int* input_arry, int input_arry_first_element, int input_arry_last_element, Direction direction);
void SelectionSort(int* input_arry, int input_arry_first_element, int input_arry_last_element, Direction direction);
void Swap(int *a, int *b);

int main()
{
	int i = 0, choice = -1;
	int direction=-1;

	int data[SIZE];

	for (i = 0; i < SIZE; i++)
	{
		data[i] = (int)(rand() % 100);
	}


	printf("Sort 전 배열 상태\n");
	for (i = 0; i < SIZE; i++)
	{
		printf("%d ", data[i]);
	}

	printf("\n 1. QuickSort, 2. SelectionSort : ");
	scanf_s("%d", &choice);
	printf("\n 1. Ascending, 2. Descending : ");
	scanf_s("%d", &direction);

	switch (choice)
	{
	case 1: Sort = quickSort; break;
	case 2: Sort = selectionSort; break;
	default: break;
	}
	if (direction == 1)
	{
		Sort(data, 0, SIZE-1, ASCENDING);
	}
	else if (direction == 2)
	{
		Sort(data, 0, SIZE-1, DESCENDING);
	}
	
	printf("Sort 후 배열 상태\n");
	for (i = 0; i < SIZE; i++)
	{
		printf("%d ", data[i]);
	}
}

void SelectionSort(int* input_arry, int input_arry_first_element, int input_arry_last_element, int sort_direction) //direction 1 : Ascending, direction 0: Descending
{
	int i = 0, j = 0;
	int input_arry_size = input_arry_last_element - input_arry_first_element;
	int arry_temp_index = 0;


	if (sort_direction == ASCENDING)
	{
		for (i = 0; i < input_arry_size - 1; i++)
		{
			arry_temp_index = i;
			for (j = i + 1; j < input_arry_size; j++)
			{
				if (input_arry[i] > input_arry[j])
				{
					arry_temp_index = j;
				}
			}
			if (arry_temp_index == i) continue;
			else if (arry_temp_index != i)
			{
				Swap(&input_arry[i], &input_arry[arry_temp_index]);
			}
		}
	}

	else if (sort_direction == DESCENDING)
	{
		for (i = input_arry_size; i >= 1; i--)
		{
			arry_temp_index = i;
			for (j = i-1; j >= 0; j--)
			{
				if (input_arry[i] < input_arry[j])
				{
					arry_temp_index = j;
				}
			}
			if (arry_temp_index == i) continue;
			else if (arry_temp_index != i)
			{
				Swap(&input_arry[i], &input_arry[arry_temp_index]);
			}
		}
	}
	else
	{
		return;
	}

	return;
}

void BubbleSort(int* input_arry, int input_arry_first_element, int input_arry_last_element, int sort_direction) //sort_direction 1 : Ascending, sort_direction 0: Descending
{
	int i = 0, j = 0;
	int input_arry_size = input_arry_last_element - input_arry_first_element;
	int arry_temp_index = 0;

	if (sort_direction == ASCENDING)
	{
		for (i = 0; i < input_arry_size - 1; i++)
		{
			arry_temp_index = i;
			for (j = 0; j < input_arry_size; j++)
			{
				if (input_arry[i] > input_arry[j])
				{
					arry_temp_index = j;
				}
			}
			if (arry_temp_index == i) continue;
			else if (arry_temp_index != i)
			{
				Swap(&input_arry[i], &input_arry[arry_temp_index]);
			}
		}
	}
	else if (sort_direction == DESCENDING)
	{
		for (i = input_arry_size; i >= 1; i--)
		{
			arry_temp_index = i;
			for (j = i - 1; j >= 0; j--)
			{
				if (input_arry[i] < input_arry[j])
				{
					arry_temp_index = j;
				}
			}
			if (arry_temp_index == i) continue;
			else if (arry_temp_index != i)
			{
				Swap(&input_arry[i], &input_arry[arry_temp_index]);
			}
		}
	}

	return;
}

void Swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}