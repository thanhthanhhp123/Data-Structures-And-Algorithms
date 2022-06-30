#include<stdio.h>

void shellSort(int a[], int n) {
    int i, j, interval, temp;
    for(interval = n / 2; interval > 0; interval /= 2) {
        for(i = interval; i < n; i++) {
            temp = a[i];
            for(j = i; j >= interval && a[j-interval] > temp; j-= interval) {
                a[j] = a[i - interval];
            }
            a[j] = temp;
        }
    }
}

int main() {
    int n, a[1000];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    shellSort(a, n);
    for(int  i =0;i < n; i++) {
        printf("%d ", a[i]);
    }
}