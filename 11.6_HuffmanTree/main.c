#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treeNode {
    int frequency;
    struct treeNode *left, *right;
}*node;

node createNode(int frequency);
node insertIntoHeap(node root, int frequency);
node createHeap(int arr[], int length);
void quickSort(int arr[], int l, int r);

int main() {
    int arr[8] = {7, 19, 2, 6, 32, 3, 21, 10};
    quickSort(arr, 0, 7);

    createHeap(arr, 8);

    return 0;
}

node createNode(int frequency) {
    node new = (node)malloc(sizeof(struct treeNode));

    new->frequency = frequency;
    new->left = NULL;
    new->right = NULL;

    return new;
}

node insertIntoHeap(node root, int frequency) {
    if(root == NULL) return createNode(frequency);

}

node createHeap(int arr[], int length) {
    while(length > 1) {
        node new = (node)malloc(sizeof(struct treeNode));
        new->frequency = arr[length - 1] + arr[length - 2];
        new->left->frequency = arr[length - 1];
        new->right->frequency = arr[length - 2];
        length -= 1;
    }
}

//倒序排列
void quickSort(int arr[], int l, int r) {
    if(l >= r) return ;

    int mid = arr[(l + r) / 2];
    int i = l - 1, j = r + 1;

    while(i < j){
        do
            i++;
        while(arr[i] > mid);

        do
            j--;
        while(arr[j] < mid);

        if(i < j) {
            int t;
            t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }

    quickSort(arr, l, j), quickSort(arr, j + 1, r);
}