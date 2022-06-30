#include<stdio.h>

void selectionSort(int a[] ,int n) {
    int indexMin;
    for(int i = 0; i < n - 1; i++) {
        indexMin = i;
        for(int j = i + 1; j < n; j++) {
            if(a[indexMin] > a[j]) {
                indexMin = j;
            }
        }
        if(i != indexMin) {
            int temp = a[i];
            a[i] = a[indexMin];
            a[indexMin] = temp;
        }
    }
}

int main() {
    int n, a[1000];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    selectionSort(a, n);
    for(int  i =0;i < n; i++) {
        printf("%d ", a[i]);
    }
}