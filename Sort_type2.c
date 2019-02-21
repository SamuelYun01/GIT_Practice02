#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 30
typedef enum { ASCENDING = 1, DESCENDING = 2 } SortDirection;
typedef enum { SELECTION_SORT = 1, BUBBLE_SORT = 2 } SortType;
typedef bool(*Func)(int, int, SortDirection);
Func comp_ptr;

void(*Sort)(int* intput_arry, int intput_arry_length, bool(*testptr)(int, int, SortDirection), SortDirection sort_direction);
void SelectionSort(int* intput_arry, int intput_arry_length, bool(*testptr)(int, int, SortDirection), SortDirection sort_direction);
void BubbleSort(int* intput_arry, int intput_arry_length, bool(*testptr)(int, int, SortDirection), SortDirection sort_direction);
bool Compare(int data1, int data2, SortDirection sort_direction);
void Swap(int *a, int *b);



int main()
{
	int i = 0;
	SortType sort_choice;
	SortDirection sort_direction;
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
	scanf_s("%d", &sort_choice);
	printf("\n 1. Ascending, 2. Descending : ");
	scanf_s("%d", &sort_direction);

	switch (sort_choice)
	{
	case SELECTION_SORT: Sort = SelectionSort; break;
	case BUBBLE_SORT: Sort = BubbleSort; break;
	default: break;
	}
	switch (sort_direction)
	{
	case ASCENDING: comp_ptr = Compare; break;
	case DESCENDING: comp_ptr = Compare; break;
	default: break;
	}

	Sort(input_arry, SIZE, comp_ptr,sort_direction);

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

void SelectionSort(int* input_arry, int input_arry_length, bool(*testptr)(int, int, SortDirection), SortDirection sort_direction)
{
	int i = 0, j = 0;
	for (i = 0; i < input_arry_length-1; i++)
	{
		for (j = i+1; j < input_arry_length; j++)
		{
			if (comp_ptr(input_arry[i], input_arry[j], sort_direction) == true)
			{
				Swap(&input_arry[i], &input_arry[j]);
			}
		}
	}
	return;
}

void BubbleSort(int* input_arry, int input_arry_length, bool(*testptr)(int, int, SortDirection), SortDirection sort_direction)
{
	int i = 0, j = 0;
	for (i = 0; i < input_arry_length; i++)
	{
		for (j = 0; j < input_arry_length-1; j++)
		{
			if (comp_ptr(input_arry[j], input_arry[j + 1], sort_direction) == true)
			{
				Swap(&input_arry[j], &input_arry[j+1]);
			}
		}
	}
	return;
}

bool Compare(int data1, int data2, SortDirection sort_direction)
{
	if (sort_direction == ASCENDING)
	{
		if (data1 > data2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (sort_direction == DESCENDING)
	{
		if (data1 < data2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void Swap(int* a, int* b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;

	return;
}