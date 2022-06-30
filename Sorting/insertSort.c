#include<stdio.h>

void insertSort(int a[], int n) {
    int index, value;
    for(int i = 1;i < n; i++) {
        index = i;
        value = a[i];
        while(index > 0 && a[index-1] > value) {
            a[index] = a[index-1];
            index--;
        }
        a[index] = value;
    }
}

int main() {
    int n, a[100];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    insertSort(a, n);
    for(int  i =0;i < n; i++) {
        printf("%d ", a[i]);
    }
}