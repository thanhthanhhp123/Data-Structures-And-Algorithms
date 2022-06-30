#include<stdio.h>

void quickSort(int a[] ,int l, int r) {
    int p = a[(l+r) / 2];
    int i = l, j = r;
    while(i < j) {
        while(a[i] < p) {
            i++;
        }
        while(a[j] > p) {
            j--;
        }
        if(i <= j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if(i < r) {
        quickSort(a, i, r);
    }
    if(l < j) {
        quickSort(a, l, j);
    }
}