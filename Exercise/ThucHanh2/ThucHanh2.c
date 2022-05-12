#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <math.h>
#include<stdio.h>
#include <string.h>
#include <conio.h>


#define MAX_COLS  100
#pragma region CountTime
#include <time.h>
#include <stdbool.h>
int timer,timerNano;
static long get_nanos(void) {
	struct timespec ts;
	timespec_get(&ts, TIME_UTC);
	return (long)ts.tv_sec * 1000000000L + ts.tv_nsec;
}
void StartTimer() {
	timer = clock();
	timerNano = get_nanos();
}
int PrintTime(bool reset) {
	int timeElapsed = (clock() - timer) * 1000 / CLOCKS_PER_SEC;
	
	if (timeElapsed < 100)
	{
		printf("\n%d nanoseconds elapsed.\n",get_nanos()-timerNano);
	}
	else {
		int min = timeElapsed / 60000, sec = (timeElapsed - (min * 60000)) / 1000, millis = (timeElapsed - min * 60000 - sec * 1000) / 10;
		printf("\n%d minutes, %02d seconds and  %02d milliseconds elapsed.\n", min, sec, millis);
	}
	if (reset) { timer = clock(); timerNano = get_nanos();
	}
	return timer;
}

#pragma endregion
void InputArray(int arr[], int n)
{
	int* index = arr--;
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap gia tri [%d]=", i);
		scanf("%d", index);
		index++;
	}
}
void shiftArray(int arr[],int n, int d) {
	int arr_new[MAX_COLS];
	int tempD = d;
	for (int i = 0; i < n; i++)
	{
		if (tempD > 0) {
			arr_new[n + d-tempD] = arr[i]; tempD--;
		}
		else {
			arr_new[i] = arr[i];
		}
	}
	for (int i = d; i < n+d; i++)
	{
		printf("%d", arr_new[i]);
	}
}
void rotateArray(int arr[MAX_COLS], int n, int d) {
	
	int temp;
		for (int i = 0; i < d; i++)
		{
			temp = arr[0];
			for (int j = 0; j < n-1; j++) {
				arr[j] = arr[j + 1];
			}
			arr[n-1] = temp;

		}

		for (int i = 0; i < n; i++)
		
		{
			int lastDisplayTime = clock();
			printf("\r     %d", arr[i]);
			while (lastDisplayTime + CLOCKS_PER_SEC > clock());
		}
		PrintTime(true);
	
	
}

void Bai2() {
	int arr[MAX_COLS];
	int n,d;
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("Nhap mang: ");
	InputArray(arr, n);
	printf("Nhap d: ");
	scanf("%d", &d);
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; ++j)
		{
			if ((arr[i]+arr[j])%d == 0)
			{
				count++;
				printf("tong cua [%d]=%d va [%d]=%d chia het cho %d\n", i, arr[i], j, arr[j], d);
			}
		}
	}
	PrintTime(false);

}

void Occurrences(int arr[],int n, int resultArr[][100]) {
	for (int i = 0; i < n; i++)
	{
		int j = -1;
	forwrd:
		j++;
		if (resultArr[0][j] < -10000) {
			resultArr[0][j] = arr[i];
			resultArr[1][j] = arr[i];
		}
		else if (resultArr[0][j] == arr[i])
		{
			resultArr[1][j]--;
		}
		else goto forwrd;
		
	}
}
void Bai3() {
	int n;
	int arr[MAX_COLS], arrCount[2][MAX_COLS];
	printf("Nhap n: ");
	scanf("%d", &n);
	InputArray(arr, n);
	PrintTime(true);
	Occurrences(arr, n, arrCount);
	int temp1 = arr[0], temp2 = arr[0],i=0;
	do
	{
		if (temp2 >= arrCount[1][i])
		{
			temp1 = arrCount[0][i];
			temp2 = arrCount[1][i];
		}
		i++;
	} while (arrCount[0][i] > -100000);
		
	PrintTime(true);
	printf("So nho nhat co lan xuat hien lon nhat la %d xuat hien %d lan\n", temp1, temp1 - temp2+1);
}
void Bai4() {
		int n;
		int arr[MAX_COLS], arrCount[2][MAX_COLS];
		printf("Nhap n: ");
		scanf("%d", &n);
		InputArray(arr, n);
		PrintTime(true);
		Occurrences(arr, n, arrCount);
		int i = 0;
		do
		{
			int socks = arrCount[0][i] - arrCount[1][i] + 1;
			printf("Co %d doi tat mau %d, du ra %d chiec tat\n", socks / 2, arrCount[0][i], socks % 2);
			i++;
		} while (arrCount[0][i] > -100000);

		PrintTime(true);
}
//void SubArrayLength(int arr[], int n,int arrSubIndex[2][MAX_COLS],int delta) // arrSubIndex: index - length
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i; j < n && abs(arr[i] - arr[j]) <= delta ; j++)
//		{
//			int k = -1;
//		forward:
//			k++;
//			if (arrSubIndex[0][k] < -10000) {
//				arrSubIndex[0][k] = i;
//				arrSubIndex[1][k] = 1;
//			}
//			else if (arrSubIndex[0][k] == i)
//			{
//				arrSubIndex[1][k]++;
//			}
//			else goto forward;
//		}
//	}
//}
void SubArrayLength(int arr[], int n, int arrSubIndex[2][MAX_COLS], int delta) // arrSubIndex: index - length
{
	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n ; j++)
			{
				if (abs(arr[i] - arr[j]) <= delta)
				{
					int k = -1;
				forward:
					k++;
					if (arrSubIndex[0][k] < -10000) {
						arrSubIndex[0][k] = i;
						arrSubIndex[1][k] = 1;
					}
					else if (arrSubIndex[0][k] == i)
					{
						arrSubIndex[1][k]++;
					}
					else goto forward;
				}
			}
		}
		}
//Lap het ca Array 
void Bai5() {
	int n;
	int arr[MAX_COLS], arrSubIndex[2][MAX_COLS];
	printf("Nhap n: ");
	scanf("%d", &n);
	int delta = 1;
	InputArray(arr, n);
	PrintTime(true);
	SubArrayLength(arr, n, arrSubIndex,delta);
	int temp1 = arrSubIndex[0][0], temp2 = arrSubIndex[1][0], i = 0; // Khoi tao: temp2 = do dai arrSubIndex[1][i] lap qua cac do dai
	do
	{
		if (temp2 < arrSubIndex[1][i])
		{
			temp1 = arrSubIndex[0][i];
			temp2 = arrSubIndex[1][i];
		}
		i++;
	} while (arrSubIndex[0][i] > -100000);

	printf("Mang con dai nhat la: [");
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (abs(arr[i]-temp1) <= delta)
		{
			printf("%d,", arr[temp1 + i]);
			count++;
		}
	}
	printf("],co do dai la %d\n",count);
	PrintTime(true);
}
int arr2[MAX_COLS];
int main() {
	StartTimer();
	int arr[20];
	/*InputArray(arr, 5);
	rotateArray(arr, 5, 2);
	Bai2();*/
	Bai3();/*
	Bai4();*/
	Bai5();
}