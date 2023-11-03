#include <stdio.h>
#include <stdlib.h>

int haveFind = 0;

typedef struct treeNode{
    int data;
    struct treeNode * left;
    struct treeNode * right;
}*node;

node createBST(int arr[], int l, int r);
node createNode(int data);
void findElementsAtLevel(node root, int targetLevel, int currentLevel);

int main()
{
    int N, toSerach;
    scanf("%d", &N);

    int arr[N];
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        getchar();
        for(int j = i - 1; j >= 0; j--)
        {
            if(arr[j] > arr[j + 1])
            {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }

    scanf("%d", &toSerach);
    node root = createBST(arr, 0, N-1);
    findElementsAtLevel(root, toSerach, 1);

    if(!haveFind) printf("-1");
    return 0;
}

node createBST(int arr[], int l, int r)
{
    if(l > r) return NULL;

    int mid;
    if(l == r) mid = (l + r) / 2;
    else mid = (l + r - 1) / 2;
    if(mid < 0) mid = 0;
    node root = createNode(arr[mid]);
    root->left = createBST(arr, l, mid - 1);
    root->right = createBST(arr, mid + 1, r);

    return root;
}

node createNode(int data)
{
    node newNode = (node)malloc(sizeof(struct treeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void findElementsAtLevel(node root, int targetLevel, int currentLevel) {
    if (root == NULL) return;

    if (currentLevel == targetLevel) {
        printf("%d,", root->data);
        haveFind = 1;
    }

    findElementsAtLevel(root->left, targetLevel, currentLevel + 1);
    findElementsAtLevel(root->right, targetLevel, currentLevel + 1);
}