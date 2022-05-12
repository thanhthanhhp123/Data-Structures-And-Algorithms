#pragma once
#include <math.h>
#include <stdbool.h>

/// <summary>
/// Check if n is prime number
/// </summary>
/// <param name="n"> </param>
bool isPrime(int n) {
	
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)return true;
	}
	return false;
};

/// <summary>
/// Find the largest value in a list and return it
/// </summary>
/// <param name="*p">The pointer of the first value in list </param>
/// <param name="n"> Size of the list</param> 
int findmax(int *p,int n) {

	int max = *p;
	int* p_ = p;
	for (int i = 0; i < n; i++)
	{
		max = *p_ > max ? *p_ : max;
		p_++;
	}
	return max;
};
/// <summary>
/// Find the smallest value in a list and return it 
/// </summary>
/// <param name="*p">The pointer of the first value in list </param>
/// <param name="n"> Size of the list</param> 
int findmin(int* p,int n) {
	int min = *p;
	int* p_ = p;
	for (int i = 0; i < n; i++)
	{
		min = *p_ < min ? *p_ : min;
		p_++;
	}
	return min;
};

/// <summary>
/// Return the average value of all value in a list
/// </summary>
/// <param name="*p">The pointer of the first value in list </param>
/// <param name="n"> Size of the list</param> 
double findaverage(int* p[], int n) {
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += *p[i];
	}
	return sum / n;
};
void InputArray(int arr[], int n)
{
	int* index = arr--;
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap gia tri mang[%d]=", i);
		scanf("%d", index);
		index++;
	}
}
void InputArray(int arr[], int n, int minVal, int maxVal)
{
	int* index = arr--;
	for (int i = 0; i < n; i++)
	{
		do
		{
			printf("\nNhap gia tri mang[%d]=", i);
			scanf("%d", index);
			if (minVal > *index || maxVal < *index)printf("Gia tri da nhap khong hop le! (%d < mang[%d] < %d)", minVal, i, maxVal);
		} while (minVal > *index || maxVal < *index);
		index++;
	}
}


