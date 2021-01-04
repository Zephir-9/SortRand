#include <iostream>
#include <Windows.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "wchar.h"
#include <iomanip>
#include <fstream>

#define ARR_SIZE 10
#define RANGE 1
using namespace std;

void Merge(double* sarr, long, long);
void MergeSort(double* arr, double, double);

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	double tmp = 0;
	clock_t t;
	double arr[ARR_SIZE];

	for (long i = 0; i < ARR_SIZE; i++)
	{
		arr[i] = 1 / rand();
	}
	for (long i = 0; i < ARR_SIZE; i++)
	{
		//printf("%i element -> %i\n", i, arr[i]);
	}
	printf("\n\n");
	t = clock();

	MergeSort(arr, 0, ARR_SIZE - 1);


	t = clock() - t;
	for (long i = 0; i < ARR_SIZE; i++)
	{
		std::cout << i << "element -> " << arr[i] << '\n';
	}

	printf("time -> %f", (float)t / CLOCKS_PER_SEC);


	if (std::cin.fail())
	{
		std::cerr << " input is incorrect\n";
		return EXIT_FAILURE;
	}
	system("PAUSE");
	return EXIT_SUCCESS;
}

void MergeSort(double* sarr, double start, double end)
{
	if (start < end)
	{
		MergeSort(sarr, start, (start + end) / 2);
		MergeSort(sarr, (start + end) / 2 + 1, end);

		Merge(sarr, start, end);
	}
}

void Merge(double* sarr, long first, long last)
{
	long left_iterator, right_iterator, middle;
	double* mas;
	mas = (double*)malloc((last - first) * sizeof(int));

	middle = (first + last) / 2;
	left_iterator = first;
	right_iterator = middle + 1;

	for (long j = first; j <= last; j++)
	{
		if ((left_iterator <= middle) && ((right_iterator > last) || (sarr[left_iterator] < sarr[right_iterator])))
		{
			*(mas + j - first) = sarr[left_iterator];
			left_iterator++;
		}
		else {
			*(mas + j - first) = sarr[right_iterator];
			right_iterator++;
		}
	}

	for (long j = first; j <= last; j++)
	{
		sarr[j] = *(mas + j - first);
	}
}