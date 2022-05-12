// BaiTap1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)
bool isPrime(int n) {
	
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)return true;
	}
	return false;
};
//find the largest value in a list and return it 
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
//find the smallest value in a list and return it 
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
//create a function that take a list of numbers and return the average of the numbers
double findaverage(int* p[], int n) {
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += *p[i];
	}
	return sum / n;
};
void Bai2() {
	int a, b, a_, b_;
	printf("Nhap a:");
	scanf("%d", &a);
	printf("Nhap b:");
	scanf("%d", &b);
	a_ = a; b_ = b;
	while (a != b) {
		a = a > b ? a - b : a;
		b = b > a ? b - a : b;
	}
	printf("UCLN cua a va b la %d", a);
	while (a != b) {
		a = a > b ? a - b : a;
		b = b > a ? b - a : b;
	}
	printf("BCNN cua a va b la: %.1f", (float)(a_ / a) * b_);
}
void Bai3() {
	int time[4] = { 0,0,0,0 }; // HH,MM,SS,AM/PM (0/1)
	bool AM = false;
	printf("Nhap gio theo dinh dang HH:MM:SS AM  ");

	int x = 0;
	char stream;
	do
	{

		scanf(x < 3 ? "%d%c" : "%c%c", & time[x], & stream); // 1_2_3.. \n=break
		x++;
	} while (stream != '\n' && x < 4);

	int time24 = time[3] == 'A' ? time[0] : time[0] + 12;
	printf("%02d:%02d:%02d %cM -> %02d:%02d:%02d", time[0], time[1], time[2], time[3], time24, time[1], time[2]);
	getch();
}
void getuserinput(int* a, int* b, int* c) {
	printf("Nhap a:");
	scanf("%d", a);
	printf("Nhap b:");
	scanf("%d", b);
	printf("Nhap c:");
	scanf("%d", c);
}
int sumOfSquares(int a, int b) {
	return a * a + b * b;
}
void Bai4() {
	//read int a,b,c and save as a list
	int a, b, c;
	getuserinput(&a, &b, &c);
	int list[3] = { a,b,c };
	printf("Chon bai can tinh:\n");
	printf("1. Tim so lon nhat, nho nhat\n");
	printf("2. Tim so nguyen to trong a,b,c\n");
	printf("3. Tong binh phuong cac so lon nhat va nho nhat\n");
	int choice;
	scanf("%d", &choice);
	switch (choice)
	{

	case 1:
		printf("So lon nhat: %d\n", findmax(&list[0], 3));
		printf("So nho nhat: %d\n", findmin(&list[0], 3));
		break;
	case 2:
		printf("So nguyen to trong a,b,c:");
		for (int i = 0; i < 3; i++)
		{
			if (isPrime(list[i]))
				printf("%d ", list[i]);
		}
		break;
	case 3:
		printf("Tong binh phuong cac so lon nhat va nho nhat: %d", sumOfSquares(findmax(&list[0], 3), findmin(&list[0], 3)));
		break;
	default:
		printf("Khong co bai nay");
		break;
	}

}
int roundPoint(int point) {
	if (point < 38) return point;
	return point % 5 > 2 ? point + (5 - point % 5) : point;

}
int nhapBai5() {
	int point;
	printf("Nhap diem can tinh: ");
	scanf("%d", &point);
	return point;
}
Bai5() {
	int point = nhapBai5();
	printf("%d -> %d\n", point, roundPoint(point));
}


//Cats and mouse! 2D plane
//-C---
//----C
//--M--
//
 enum direction {
	Stop = 0,
	Up = 1,
	Right = 2,
	Left = 3,
	Down = 4
	
};

int cat1[2] = { 0,0 };
int cat2[2] = { 0,0 };
int mouse[2] = { 0,0 };
int width, height;

//initialize the cats and mouse position, check if it in range of the plane
void init() {
	intialize:
	printf("Nhap vi tri chuot: ");
	scanf("%d %d", &mouse[0], &mouse[1]);
	printf("Nhap vi tri meo 1: ");
	scanf("%d %d", &cat1[0], &cat1[1]);
	printf("Nhap vi tri meo 2: ");
	scanf("%d %d", &cat2[0], &cat2[1]);
	if (mouse[0] < 0 || mouse[0] >= width || mouse[1] < 0 || mouse[1] >= height) {
		printf("Chuot khong nam trong vung!\n");
		goto intialize;
	}
	if (cat1[0] < 0 || cat1[0] >= width || cat1[1] < 0 || cat1[1] >= height) {
		printf("Meo 1 khong nam trong vung!\n");
		goto intialize;
	}
	if (cat2[0] < 0 || cat2[0] >= width || cat2[1] < 0 || cat2[1] >= height) {
		printf("Meo 2 khong nam trong vung!\n");
		goto intialize;
	}
	
}




//check possible move
bool checkMove(int x, int y, int direction) {
	switch (direction)
	{
	case Up:
		if (y - 1 >= 0)
			return true;
		break;
	case Right:
		if (x + 1 < width)
			return true;
		break;
	case Left:
		if (x - 1 >= 0)
			return true;
		break;
	case Down:
		if (y + 1 < height)
			return true;
		break;
	default:
		break;
	}
	return false;
}

 
int checkCat() {
	if (cat1[0] == mouse[0] && cat1[1] == mouse[1]) {
		printf("Meo 1 bat duoc chuot\n");
		return 1;
	}
	if (cat2[0] == mouse[0] && cat2[1] == mouse[1]) {
		printf("Meo 2 bat duoc chuot\n");
		return 2;
	}
	if (cat1[0] == cat2[0] && cat1[1] == cat2[1]) {
		printf("Chuot chay duoc khoi meo\n");
		return 3;
	}
	return 0;
	
}
//get the direction the cat need to move
enum direction getDirection(int x, int y) {
	//get the mouse position
	int mouseX = mouse[0];
	int mouseY = mouse[1];
	//if the mouse is above the cat
	if (mouseY < y) {
		if (mouseX == x)
			return Up;
		else if (mouseX > x)
			return Right;
		else
			return Left;
	} else if (mouseY > y) {
		if (mouseX == x)
			return Down;
		else if (mouseX > x)
			return Right;
		else
			return Left;
	}
	else {
		if (mouseX > x)
			return Right;
		else
			return Left;
	}

	
}
//move the cat
void moveCat(int *x, int *y,enum direction direction) {
	switch (direction)
	{
	case Up:
		*y -= 1;
		break;
	case Right:
		*x += 1;
		break;
	case Left:
		*x -= 1;
		break;
	case Down:
		*y += 1;
		break;
	default:
		break;
	}
}
//move the mouse randomly
void moveMouse() {
	int x = mouse[0];
	int y = mouse[1];
	if (x == cat1[0] && y == cat1[1]) {

		return;
	}
	if (x == cat2[0] && y == cat2[1]) {
		return;
	}
	if (!checkMove(x, y, Up) && !checkMove(x, y, Right) && !checkMove(x, y, Left) && !checkMove(x, y, Down)) {
		return;
	}
	int direction = rand() % 4 + 1;
	if (mouse[1] - cat1[1] > 0 || mouse[1] - cat2[1] > 0)direction = Down;
	else direction = Up;
	if (mouse[0] - cat1[0] > 0 || mouse[0] - cat2[0] > 0)direction = Right;
	else direction = Left;
	while (!checkMove(x, y, direction)) {
		direction = rand() % 4 + 1;
	}
	switch (direction)
	{
	case Up:
		mouse[1]--;
		break;
	case Right:
		mouse[0]++;
		break;
	case Left:
		mouse[0]--;
		break;
	case Down:
		mouse[1]++;
		break;
	default:
		break;
	}
}
//Print the play ground, if cat print M, if mouse print C, else print -
void printPlayGround() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (i == cat1[1] && j == cat1[0])
				printf("M");
			else if (i == cat2[1] && j == cat2[0])
				printf("M");
			else if (i == mouse[1] && j == mouse[0])
				printf("C");
			else
				printf("-");
		}
		printf("\n");
	}
}


Bai6() {
	int turn = 1;
	int catSpeed = 1;
	printf("Nhap chieu dai: ");
	scanf("%d", &width);
	printf("Nhap chieu rong: ");
	scanf("%d", &height);
	printf("So buoc meo co the di chuyen: ");
	scanf("%d", &catSpeed);
	init();
	printPlayGround();
	while (checkCat() == 0) {
		printf("Turn: %d\n\n", turn);
		for (int i = 0; i < catSpeed; i++)
		{
			enum direction cat1_ = getDirection(cat1[0], cat1[1]);
			if (checkMove(cat1[0], cat1[1], cat1_))
				moveCat(&cat1[0], &cat1[1], cat1_);
			enum direction cat2_ = getDirection(cat2[0], cat2[1]);
			if (checkMove(cat2[0], cat2[1], cat2_))
				moveCat(&cat2[0], &cat2[1], cat2_);
		}
		moveMouse();
		printPlayGround();
		turn++;
	}
	

}
void getUserVar(int *a,int*b, int *x, int *y, int *z){

printf("Nhap so luong qua trang a=");
scanf("%d",a);

printf("Nhap so luong qua den b=");
scanf("%d",b);

printf("Nhap gia thanh trang x=");
scanf("%d",x);

printf("Nhap gia thanh den y=");
scanf("%d",y);

printf("Nhap gia thanh doi trang <=> den z=");
scanf("%d",z);
}
int calculateMinSum(int a, int b, int x, int y, int z,int*mode) {
	int sumTemp=(a * x < b* y ? (a + z) * y : (b + z) * x)+(a * x < b* y ? a * x : b * y);
	int sum = a*x + b*y;
	*mode = sum > sumTemp ? a * x < b* y ? 1 : 2 : 0;
	return (sum < sumTemp ? sum : sumTemp);
}
void Bai7() {
	int a;
	int b;
	int x;
	int y;
	int z;
	getUserVar(&a, &b, &x, &y, &z);
	int mode = 0, ans = calculateMinSum(a, b, x, y, z, &mode);
	printf("So tien toi thieu de mua %d qua trang va %d qua den la %d, can phai mua ",a,b,ans);
	if (mode == 1)
	{
		printf("%d qua trang va doi %d qua trang sang den.\n", a + b, b);
	}
	else if (mode == 2)
	{
		printf("%d qua den va doi %d qua den sang trang.\n", a + b, a);
	}
	else
	{
		printf("%d qua den va  %d qua trang.\n", a, b);
	}
	
//calculate the minimum sum of a*x + b*y
}
int main()
{
	printf("Nhap bai can chay: ");
	int bai;
	scanf("%d", &bai);
	switch (bai)
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
