
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <iostream>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <commonmath.h>

//DONE: Nhap vao mang co do dai 5 -> tong 4 so nho nhat va lon nhat
//Tim tong 4 so lon nhat
int SumMax(int a[], int n) { 
	int sum = 0;
	for (int i = 0; i < n; i++)sum += a[i] == findmin(a, n) ? 0 : a[i];
	
	return sum;
}
//Tim tong 4 so nho nhat
int SumMin(int a[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) sum += a[i] == findmax(a, n) ? 0 : a[i];
	return sum;
}
void Bai1() {
	int mang[5];
	InputArray(mang, 5);
	printf("\nTong 4 so lon nhat trong mang: %d", SumMax(mang, 5));
	printf("\nTong 4 so nho nhat trong mang: %d", SumMin(mang, 5));

}


int MaxCount(int a[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == findmax(a, n)) count++;
	}
	return count;
}
//Tim so lan xuat hien so lon nhat trong mang
void Bai2() {
	int mang[5];
	printf("Nhap mang: ");
	InputArray(mang, 5);
	printf("So lon nhat la %d", findmax(mang, 5));
	printf("\nSo lan xuat hien lon nhat trong mang: %d", MaxCount(mang, 5));

}





void ArrayRatio(int arr[], int n,float result[]) {
	int tempArr[3] = { 0 ,0 , 0 }; // dem so 0 <...
	//	  temp=	     [0] [1] [2] ....
	for (int i = 0; i < n; i++)tempArr[arr[i] > 0 ? 2 : arr[i] < 0 ? 0 : 1]++;
	for (int i = 0; i < 3; i++)*(result++) = (float)tempArr[i]/n;
}




// tinh ti le giua duong am,0
//Tao mot mang moi [-1, 0, 1]
void Bai3() {
	int mang[100],n;
	float ans[3];
	printf("Nhap kich thuoc mang n=");
	scanf("%d", &n);
	//InputArray(mang, n);
	for (int i = 0; i < n; i++)
	{
		printf("Nhap so trong mang [%d]=", i);
		scanf("%d", &mang[i]);
	}

	ArrayRatio(mang, n, ans);
	printf("Ti le giua cac gia tri trong mang:\nNho hon 0: %0.1f %%\nBang 0: %0.1f %%\nLon hon 0: %0.1f %%\n ",ans[0],ans[1],ans[2]);
}




void FindDuplicate(char str[], char value) {
	int count=0;
	int mangKiTu[100];
	for (int i = 0; i < strlen(str); i++)
	{
		if (value == str[i])
		{
			printf("Ki tu '%c' xuat hien tai vi tri %d\n", value, i+1);
			mangKiTu[count] = i;
			count++;
		}
	}
	printf("Co tat ca %d ki tu '%c' trong cau \"%s\"\n", count, value,str);
}


void Bai4() {
	fflush(stdin);
	char str[] = "lua nep la lua nep lang";
	printf("Nhap ki tu can tim: ");
	char key;
	scanf("%c", &key);
	FindDuplicate(str, key);
}







// Chia het cho mang a
int CountDiv(int a, int arr[],int n) { //a = so can phai chia, arr = mang (con tro), n do dai arr
	int count = 0;
	for (int j = 0; j < n; j++)if (a % arr[j] == 0)count++;
	return count;
}
//if count == n


//b chia het 
int Divable(int a[], int b[], int c, int d) { // a,b = mang, c,d = do dai a,b
	int count = 0;
	for (int j = 1; j <= findmax(b,d); j++) //chi can lap den so lon nhat trong b => /2
	{
		int countDiv_b = 0;
		if (CountDiv(j,a,c) == c)
		{
			for (int i = 0; i < d; i++)
			{
				if (*b % j == 0)countDiv_b++;
				b++;
			}
		}
		if (countDiv_b == d)
		{
			printf("So %d thoa man\n", j);
			count++;
		}
	}
	return count;
}
//tao mang a, mang b, do dai a < b; TM:
// - So bat ki: chia het cho tat ca cac so trong a[]
// - So trong mang b chia het cho no
void Bai5() {
	int a[100],b[100],c,d;
	inputarr:
	printf("Nhap kich thuoc a: ");
	scanf("%d", &c);
	printf("Nhap kich thuoc b: ");
	scanf("%d", &d);
		if (c >= d)goto inputarr;
	InputArray(a, c);
	InputArray(b, d);
	/*for (int i = 0; i < n; i++)
	{
		printf("Nhap so trong mang [%d]=", i);
		scanf("%d", &mang[i]);
	}*/
	printf("Co %d so thoa man dau bai\n", Divable(a, b, c, d));
}



void SumSubArray(int arr[], int n, int subLength,int max,bool consecutive = false) {
	int tempArr[12];
	for (int i = 0; i < n; i++)
	{
		int* pointer_1 = arr;
		int sum = max,sumCount = 0;
		for (int j = 0; j < (consecutive ? subLength : n) && sum > 0; j++)
		{
			if (sum - *pointer_1 >= 0)
			{
				tempArr[sumCount] = *pointer_1;
				sum -= *pointer_1;
				sumCount++;
			}
			pointer_1++;
		}
		if (sum == 0 && sumCount == subLength)
		{
			printf("Mang con [");
			for (int x = 0; x < subLength; x++) { printf("%d,", (tempArr[x])); }
			printf("] co tong bang %d\n", max);
		}
		arr++;
	}
}
void Bai6() {
	int s[100],n, d, m;
	printf("\n1<= d <= 31, 1<= m <= 12");
	printf("\nNhap: n d m\n");
	scanf("%d %d %d", &n, &d, &m);
	InputArray(s, n, 1, 5);
	SumSubArray(s, n, m, d, true);
	
}
void Bai7() {
	int n, m;
	do
	{
		printf("Nhap vao ma tran n(n<20):");
		scanf("%d", &n);
		m = n;
	} while (n < 0 && m < 0);
	int maTran[20][20];
	for (int x = 0; x < sizeof(maTran) / sizeof(maTran[0]); x++)
		for (int y = 0; y < sizeof(maTran)[0] / sizeof(maTran[0][0]); y++)
			maTran[x][y] = 0;
	printf("Nhap du lieu theo hang (VD:1 2 3 4..):\n");
	for (int x = 0; x < n; x++)
	{
		printf("Hang %d: ", x + 1);
		char stream;
		int y = 0;
		do
		{
			int ip = scanf("%d%c", &maTran[x][y], &stream); // 1_2_3.. \n=break
			y++;
		} while (stream != '\n');

	}
	
	int det = 0;
	for (int x = 0; x < n; x++)det += maTran[x][x];
	for (int x = n-1; x >= 0; x--)det -= maTran[n-1-x][x];
	printf("Do chenh lech tuyet doi: %d",abs(det));
}
int main()
{
	int choose;
	printf("Chon bai can chay: ");
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:
		Bai1();
		break;
	case 2:
		Bai2();
		break;
	case 3:
		Bai3();
		break;
	case 4:
		Bai4();
		break;
	case 5:
		Bai5();
		break;
	case 6:	
		Bai6();
		break;
	case 7:	
		Bai7();
		break;
	default:
		printf("Khong co bai nay");
		break;
	}
	return 0;
}

