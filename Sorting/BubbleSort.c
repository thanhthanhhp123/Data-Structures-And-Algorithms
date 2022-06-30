#include<stdio.h>

void bubbleSort(int a[], int n) {
    for(int i =0; i < n; i++) {
        for(int j = i +1; j < n; j++) {
            if(a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main() {
    int n, a[100];
    scanf("%d", &n);
    for(int i =0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    bubbleSort(a, n);
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}