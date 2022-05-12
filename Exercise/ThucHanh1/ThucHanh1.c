#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6011)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define MAX_ROWS 100
#define MAX_COLUMNS 100
#define RANDOM_RANGE 100
void matrixMinMax(int matrix[][MAX_COLUMNS], int m, int n, int* d_min, int* d_max) {
	int min = matrix[0][0], max = matrix[0][0];
	for (int x = 0; x < m; x++)
	{
		for (int y = 0; y < n; y++)
		{
			min = min < matrix[x][y] ? min : matrix[x][y];
			max = max > matrix[x][y] ? max : matrix[x][y];
		}
	}
	*d_min = min;
	*d_max = max;
}
void GetMatrix(int matrix[][MAX_COLUMNS], int m, int n,bool random) {
	for (int x = 0; x < n; x++)
	{
		printf("[%d]: ", x + 1);
		char stream='a';
		int y = 0;
		do
		{
			int ip = random ? rand()% RANDOM_RANGE : scanf("%d%c", &matrix[x][y], &stream); // 1_2_3.. \n=break
			if (random)matrix[x][y] = ip;
			y++;
		} while ((stream != '\n'&&!random) || y < n);
		

	}
}
void ShowMatrix(int matrix[][MAX_COLUMNS],int m, int n) {
	for (int x = 0; x < m; x++)
	{
		for (int y = 0; y < n; y++)
		{
		
			printf("%d\t", matrix[x][y]);
		}
		printf("\n");
	}
}
void ShowMatrixAsTable(int matrix[][MAX_COLUMNS], int m, int n) {
	int min, max;
	matrixMinMax(matrix, m, n, &min, &max);
	printf("\n");
	for (int x = 0; x < m; x++)
	{
		
		for (int y = 0; y < n*2+1; y++)
		{
			if (y % 2 == 0)printf("+");
			if(y % 2 != 0)for (int i = 0; i < (log10(max) ); i++)printf("-");
		}
		printf("\n");
		for (int y = 0; y < n; y++)
		{
			printf("|");
			printf("%2d", matrix[x][y]);
		}
		printf("|\n");
	}
	for (int y = 0; y < n*2+1; y++)
	{
		if (y % 2 == 0)printf("+");
		if (y % 2 != 0)for (int i = 0; i < (log10(max)); i++)printf("-");
	}
	printf("\n");
}
int sumEvenMatrix(int matrix[][MAX_COLUMNS], int m, int n)
{
	int total = 0;
	for (int x = 0; x < m; x+=2)
	{
		int sum = 0;
		for (int y = 0; y < n; y++)
		{
			sum += matrix[x][y];
			total += matrix[x][y];
		}
		printf("Tong dong [%d]: %d\n", x, sum);
	}
	return total;
}

 int matrix[MAX_ROWS][MAX_COLUMNS];
 int matrix_2[MAX_ROWS][MAX_COLUMNS];
 int matrix_3[MAX_ROWS][MAX_COLUMNS];
 int matrix_4[MAX_ROWS][MAX_COLUMNS];
 void SumMatrix(int matrix1[][MAX_COLUMNS], int matrix2[][MAX_COLUMNS],int matrixResult[][MAX_COLUMNS], int m, int n) {
	 
		 for (int x = 0; x < m; x++)
		 {
			 for (int y = 0; y < n; y++)
			 {
				 matrixResult[x][y] = matrix1[x][y] + matrix2[x][y];
			 }
		 }

 }
 int matrix3(int matrix[][MAX_COLUMNS], int m, int n) {
	 int min3 = matrix[0][0], max = matrix[0][0];
	 for (int x = 0; x < m; x++)
	 {
		 for (int y = 0; y < n; y++)
		 {
			 min3= min3 < matrix[x][y] && matrix[x][y] % 3 == 0 ? min3 : matrix[x][y];
			
		 }
	 }
	 return min3;
 }

 void BubbleSort(int a[], int array_size)
 {
	 int i, j, temp;
	 for (i = 0; i < (array_size - 1); ++i)
	 {
		 for (j = 0; j < array_size - 1 - i; ++j)
		 {
			 if (a[j] > a[j + 1])
			 {
				 temp = a[j + 1];
				 a[j + 1] = a[j];
				 a[j] = temp;
			 }
		 }
	 }
 }
 int SortMatrix(int matrix[][3], int matrixResult[][MAX_COLUMNS], int m, int n,int offsetX,int offsetY) {
	 int tempArray[MAX_ROWS * MAX_COLUMNS];
	 int temp;
	 for (int x = offsetX; x < m; x++) //Flatten matrix
	 {
		 for (int y = offsetY; y < n; y++)
		 {
			 tempArray[(x - offsetX) + n * (y - offsetY)] = matrix[x][y];
		 }
	 }
	 BubbleSort(tempArray, (m-offsetX) * (n-offsetY));
	 for (int y = offsetY; y < n; y++)
	 {
		 for (int x = offsetX; x < m; x++)
		 {
			 matrixResult[x][y] = tempArray[(y - offsetY) + m * (x - offsetX)];
		 }
	 }

 }

 void SortRow(int matrix[][MAX_COLUMNS], int matrixResult[][MAX_COLUMNS], int m, int n, int row) {
	 int tempArr[MAX_ROWS];
	 for (int i = 0; i < m; i++)
	 {
		 tempArr[i] = matrix[row][i];
	 }
	 BubbleSort(tempArr,m);
	 matrixResult = tempArr;
 }
int main()
{
	int	m, n, max, min, max_2, min_2;
	printf("Nhap MxN: ");
	scanf("%dx%d", &m, &n);
	GetMatrix(matrix, m, n,true);
	ShowMatrixAsTable(matrix, m, n);
	matrixMinMax(matrix, 1, n, &min_2, &max_2);
	printf("Tong chan ma tran: %d\n Gia tri lon nhat cot 1: %d\n", sumEvenMatrix(matrix, m, n),max_2);
	matrixMinMax(matrix, m, n, &min, &max);
	printf("Gia tri lon nhat: %d\nGia tri nho nhat: %d\n", max, min);
	ShowMatrix(matrix,m,n);
	GetMatrix(matrix_2, m, n, true);
	SumMatrix(matrix, matrix_2, matrix_3, m, n);
	SortMatrix(matrix, matrix_4, m, n, 0, 0);
	ShowMatrixAsTable(matrix_4, m, n);
	
}

