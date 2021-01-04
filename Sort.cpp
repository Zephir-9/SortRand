//#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include "wchar.h"
#include <iomanip>


//int increment(double* interval, long size);
//void Sort(double* arr, long size);
void preSort(unsigned int, double* x, double* y, int);
void quick_sort(double* sarr, int j);
void getApprox(double *arrx, double *arry, int count);

void main()
{setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	int count;
	unsigned int arr_size = 10000;
	int l = 0;


	//std::cout << "Размер массива?: ";
	//std::cin >> arr_size;
	std::cout << "Кол-во массивов: ";
	std::cin >> count;
	system("CLS");
	double* arrx = new double[count];
	double* arry = new double[count];
	int itr = 0;

	clock_t p_t = clock();

	while(l < count)
	{
		preSort(arr_size, arrx, arry, itr);
		arr_size += 10000;
		l++;
		itr++;
	}

	p_t = clock() - p_t;
	//printf("final time -> %f", (float)p_t / CLOCKS_PER_SEC);

	for (int i = 0; i < count; i++)
	{
		std::cout << "\nN = " << arrx[i] << " t = " << arry[i] << " sec";
	}

	getApprox(arrx, arry, count);

	delete[] arrx;
	delete[] arry;

	std::cout << "\n";
	system("PAUSE");
	exit(0);
}


void preSort(unsigned int arr_size, double* arrx, double* arry, int itr)
{
	long tmp = 0;
	clock_t t;
	double *arr = new double[arr_size];


	for (int i = 0; i < arr_size; i++)
	{
		arr[i] = rand() / 100000.000;
	}
	

	//printf("\n\n");
	t = clock();

	quick_sort(arr, arr_size - 1);


	t = clock() - t;

	/*for (long i = 0; i < arr_size; i++)
	{
		//printf("%i element -> %i\n", i, arr[i]);
		std::cout << i << " element -> " << arr[i] << '\n';
	}*/

	//std::cout << arr_size << ": ";
	//printf("time -> %f", (float)t / CLOCKS_PER_SEC);
	
	arrx[itr] = arr_size;
	arry[itr] = (float)t / CLOCKS_PER_SEC;


	delete[] arr;
	
	//getchar();

	if (std::cin.fail())
	{
		std::cerr << " input is incorrect\n";
		exit(0);
	}
}


void quick_sort(double* sarr, int j)
{
	int size = j;
	int k = 0;
	double c = sarr[(int)(j / 2)];
	double tmp = 0;
	do {
		while (sarr[k] < c)k++;
		while (sarr[j] > c)j--;

		if (k <= j)
		{
			tmp = sarr[k];
			sarr[k] = sarr[j];
			sarr[j] = tmp;
			k++;
			j--;
		}
	} while (k <= j);
	if (j > 0) quick_sort(sarr, j);
	if (size > k) quick_sort(sarr + k, size - k);
}


void getApprox(double* arrx, double* arry, int count)
{
	double sumx = 0;
	double sumy = 0;
	double sumx2 = 0;
	double sumxy = 0;

	for (int i = 0; i < count; i++)
	{
		sumx += arrx[i];
		sumy += arry[i];
		sumx2 += arrx[i] * arrx[i];
		sumxy += arrx[i] * arry[i];
	}

	double a = 0;
	double b = 0;

	a = (count * sumxy - (sumx * sumy)) / (count * sumx2 - sumx * sumx);
	b = (sumy - a * sumx) / count;

	std::cout << "\na = " << a <<"\nb = " << b;
}
