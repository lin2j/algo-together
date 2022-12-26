//
// Created by Kenny on 2022/8/13.
//
#include <stdio.h>

static void swap(int *i, int *j)
{
        int tmp = *i;
        *i = *j;
        *j = tmp;
}

static int partition(int *arr, int l, int r)
{
        if (l > r)
                return -1;
        int v = arr[l];
        while(l < r) {
                while(l < r && arr[r] >= v) r--;
                swap(&arr[l], &arr[r]);
                while(l < r && arr[l] <= v) l++;
                swap(&arr[l], &arr[r]);
        }
        return l;
}

static void quick_sort(int *arr, int l, int r)
{
        if (l >= r) return;
        int p = partition(arr, l, r);
        quick_sort(arr, l, p - 1);
        quick_sort(arr, p + 1, r);
}

int main(int argc, char **argv)
{
        int arr[10] = {0, 2, 5, 6, 1, 5, 9, 4, 3, 1};
        quick_sort(arr, 0, 9);
        for(int i = 0; i < 10; i++) {
                printf("%d ", arr[i]);
        }

        printf("\n");

        int arr_2[3] = {3, 2, 1};
        quick_sort(arr_2, 0, 2);
        for(int i = 0; i < 3; i++) {
                printf("%d ", arr_2[i]);
        }
        printf("\n");
        return 0;
}
