#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    int val;
    struct treeNode* left;
    struct treeNode* right;
    int height; // 新增：记录节点的高度
} *node;

node createNode(int val);
node insertNode(node root, int val);
node leftRotate(node root);
node rightRotate(node root);
int calculateHeight(node root);
int getBalanceFactor(node root);
node balanceTree(node root);
void preorderTraversal(node root);

int main()
{
    int temp;
    node root = NULL;

    while(scanf("%d", &temp) != EOF) {
        if(temp == '\n') break;
        root = insertNode(root, temp);
        getchar();
    }

    preorderTraversal(root);

    return 0;
}

node createNode(int val)
{
    node new = (node)malloc(sizeof(struct treeNode));

    new->val = val;
    new->left = NULL;
    new->right = NULL;
    new->height = 1; // 初始化节点的高度为1

    return new;
}

//计算节点的高度
int calculateHeight(node root)
{
    if (root == NULL)
        return 0;

    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);

    if (leftHeight >= rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

int getBalanceFactor(node root)
{
    if (root == NULL) return 0;

    int leftHeight, rightHeight;

    if(root->left != NULL) {
        leftHeight = root->left->height;
    } else {
        leftHeight = 0;
    }

    if(root->right != NULL) {
        rightHeight = root->right->height;
    } else {
        rightHeight = 0;
    }


    return leftHeight - rightHeight;
}

node balanceTree(node root)
{
    int balanceFactor = getBalanceFactor(root);

    // 左子树高度较大，需要进行右旋操作
    if (balanceFactor > 1)
    {
        // 判断左子树的平衡因子，若大于等于0，则进行单右旋；否则，先对左子树进行单左旋，再进行单右旋
        if (getBalanceFactor(root->left) >= 0)
            root = rightRotate(root);
        else    // 左子树的平衡因子小于0，需要先对左子树进行单左旋，再进行单右旋
        {
            root->left = leftRotate(root->left);
            root = rightRotate(root);
        }
    }
        // 右子树高度较大，需要进行左旋操作
    else if (balanceFactor < -1)
    {
        // 判断右子树的平衡因子，若小于等于0，则进行单左旋；否则，先对右子树进行单右旋，再进行单左旋
        if (getBalanceFactor(root->right) <= 0)
            root = leftRotate(root);
        else
        {
            root->right = rightRotate(root->right);
            root = leftRotate(root);
        }
    }

    return root;
}

node insertNode(node root, int val)
{
    if (root == NULL)
        return createNode(val);

    if (val > root->val)
        root->right = insertNode(root->right, val);
    else
        root->left = insertNode(root->left, val);

    root->height = 1 + (calculateHeight(root->left) > calculateHeight(root->right) ?
                        calculateHeight(root->left) : calculateHeight(root->right));

    root = balanceTree(root); // 平衡树

    return root;
}

node leftRotate(node root)
{
    node newRoot = root->right;
    node temp = newRoot->left;

    newRoot->left = root;
    root->right = temp;

    root->height = calculateHeight(root);
    newRoot->height = calculateHeight(newRoot);

    return newRoot;
}

node rightRotate(node root)
{
    node newRoot = root->left;
    node temp = newRoot->right;

    newRoot->right = root;
    root->left = temp;

    root->height = calculateHeight(root);
    newRoot->height = calculateHeight(newRoot);

    return newRoot;
}

void preorderTraversal(node root)
{
    if (root != NULL)
    {
        printf("%d,", root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}