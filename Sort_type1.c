#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 30
typedef enum { ASCENDING = 1, DESCENDING = 2 } SortDirection;
typedef enum { SELECTION_SORT = 1, BUBBLE_SORT = 2 } SortType;

void(*Sort)(int* input_arry, int input_arry_size, SortDirection sort_direction);
void BubbleSort(int* input_arry, int input_arry_size, SortDirection sort_direction);
void SelectionSort(int* input_arry, int input_arry_size, SortDirection sort_direction);
void Swap(int *a, int *b);

int main()
{
	int i = 0;
	SortDirection sort_direction;
	SortType sort_type;

	int input_arry[SIZE];

	srand(time(NULL));
	for (i = 0; i < SIZE; i++)
	{
		input_arry[i] = (int)(rand() % 100);
		printf("==");
	}

	printf("\nSort 전 배열 상태\n");
	for (i = 0; i < SIZE; i++)
	{
		printf("%d ", input_arry[i]);
	}
	printf("\n");
	for (i = 0; i < SIZE; i++)
	{
		printf("==");
	}

	printf("\n 1. SelectionSort, 2. BubbleSort : ");
	scanf_s("%d", &sort_type);
	printf("\n 1. Ascending, 2. Descending : ");
	scanf_s("%d", &sort_direction);

	switch (sort_type)
	{
	case SELECTION_SORT: Sort = SelectionSort; break;
	case BUBBLE_SORT: Sort = BubbleSort; break;
	default: break;
	}
	if (sort_direction == 1)
	{
		Sort(input_arry, SIZE, ASCENDING);
	}
	else if (sort_direction == 2)
	{
		Sort(input_arry, SIZE, DESCENDING);
	}
	
	for (i = 0; i < SIZE; i++)
	{
		printf("==");
	}

	printf("\nSort 후 배열 상태\n");
	for (i = 0; i < SIZE; i++)
	{
		printf("%d ", input_arry[i]);
	}
	printf("\n");
	for (i = 0; i < SIZE; i++)
	{
		printf("==");
	}
	printf("\n");
}

void SelectionSort(int* input_arry, int input_arry_size, SortDirection sort_direction)
{
	int i = 0, j = 0;
	if (sort_direction == ASCENDING)
	{
		for (i = 0; i < input_arry_size - 1; i++)
		{
			for (j = i + 1; j < input_arry_size; j++)
			{
				if (input_arry[i] > input_arry[j]) Swap(&input_arry[i], &input_arry[j]);
			}
		}
	}
	else if (sort_direction == DESCENDING)
	{
		for (i = 0; i < input_arry_size - 1; i++)
		{
			for (j = i + 1; j < input_arry_size; j++)
			{
				if (input_arry[i] < input_arry[j]) Swap(&input_arry[i], &input_arry[j]);
			}
		}
	}
	return;
}

void BubbleSort(int* input_arry, int input_arry_size, SortDirection sort_direction)
{
	int i = 0, j = 0;
	if (sort_direction == ASCENDING)
	{
		for (i = 0; i < input_arry_size; i++)
		{
			for (j = 0; j < input_arry_size-1; j++)
			{
				if (input_arry[j] > input_arry[j + 1]) Swap(&input_arry[j], &input_arry[j + 1]);
			}
		}
	}
	else if (sort_direction == DESCENDING)
	{
		for(i = 0; i < input_arry_size; i++)
		{
			for (j = 0; j < input_arry_size - 1; j++)
			{
				if (input_arry[j] < input_arry[j + 1]) Swap(&input_arry[j], &input_arry[j + 1]);
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