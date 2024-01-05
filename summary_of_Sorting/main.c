#include <stdio.h>
#include <stdlib.h>

void shellSort(int array[], int size, int interval) {

    for(int gap = interval; gap > 0; gap /= 2) {

        for(int i = gap; i < size; i++) {

            int temp = array[i];
            int j;

            for(j = i; j >= gap && array[j - gap] > temp; j -= gap)
                array[j] = array[j - gap];

            array[j] = temp;

        }

    }

}

void insertionSort(int array[], int size) {

    int i, j, toCompare;


    for(i = 0; i < size; i++) {

        toCompare = array[i];
        j = i - 1;

        while(j >= 0 && array[j] > toCompare) {

            array[j + 1] = array[j];
            j--;

        }

        array[j + 1] = toCompare;

    }

}

void selectionSort(int array[], int size) {

    int i, j, minIndex;

    for(i = 0; i < size - 1; i++) {

        minIndex = i;

        for(j = i + 1; j < size; j++) {

            if(array[j] < array[minIndex])
                minIndex = j;

        }

        int temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;

    }

}

void quickSort(int array[], int l, int r) {

    if(l >= r) return;

    int midValue = array[(l + r) / 2];
    int i = l - 1, j = r + 1;

    while(i < j) {

        do {
            i++;
        } while(array[i] < midValue);

        do {
            j--;
        } while(array[j] > midValue);

        if(i < j) {

            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;

        }

    }

    quickSort(array, l, j), quickSort(array, j + 1, r);

}

void mergeSort(int array[], int l, int r) {

    if(l >= r) return;

    int mid = (l + r) / 2, count = 0;

    mergeSort(array, l, mid), mergeSort(array, mid + 1, r);

    int i = l, j = mid + 1; //注意j是mid + 1！！！！
    int temp[r + 1];

    while(i <= mid && j <= r) {

        if(array[i] < array[j])
            temp[count++] = array[i++];
        else
            temp[count++] = array[j++];

    }

    while(i <= mid) {

        temp[count++] = array[i++];

    }

    while(j <= r) {

        temp[count++] = array[j++];

    }

    for(i = l, count = 0; i <= r; i++, count++)
        array[i] = temp[count];

}

void printArray(int array[], int size) {

    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

}

int main() {

    int array[8] = {49,38,65,97,76,13,27,50};
    int size = 8;

    //shellSort(array, size, 2);
    //insertionSort(array, size);
    //selectionSort(array, size);
    //quickSort(array, 0, size - 1);
    mergeSort(array, 0, size - 1);  //归并排序
    printArray(array, size);

    return 0;
}