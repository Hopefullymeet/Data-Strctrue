#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
}*node;

node createNode(int val);
node insertNode(node root, int val);
void preorder(node root);

int main() {
    int temp;
    node root = NULL;

    while(scanf("%d", &temp) != EOF)
    {
        getchar();
        root = insertNode(root, temp);
    }

    preorder(root);

    return 0;
}

node createNode(int val)
{
    node new = (node)malloc(sizeof(struct TreeNode));

    new->val = val;
    new->left = NULL;
    new->right = NULL;

    return new;
}

node insertNode(node root, int val)
{
    if(root == NULL) return createNode(val);

    if(val > root->val)
    {
        root->right = insertNode(root->right, val);
    }
    else if(val < root->val)
    {
        root->left = insertNode(root->left, val);
    }

    return root;
}

void preorder(node root)
{
    if(root == NULL) return ;

    printf("%d,", root->val);
    preorder(root->left);
    preorder(root->right);
}