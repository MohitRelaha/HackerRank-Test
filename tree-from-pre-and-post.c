#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
  };
  
typedef struct TreeNode treenode;
  
treenode* treenode_new(int val) {
    treenode* node = (treenode *) malloc(sizeof(treenode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int search(int val,int* arr,int start,int end)
{
    int i;
    for(i=start;i<=end;i++)
    {
        if(arr[i] == val)
            return i;
    }
    return -1;
}

treenode* build(int* preorder,int* inorder,int start,int end,int* in)
{
    if(start > end )
        return NULL;
    
    int index = search(preorder[*in],inorder,start,end);
    treenode* newnode = treenode_new(preorder[(*in)++]);
    
    newnode->left = build(preorder,inorder,start,index-1,in);
    newnode->right = build(preorder,inorder,index+1,end,in);
    
    return newnode;
}

treenode* buildTree(int* A, int n1, int* B, int n2)
{
    int in=0;
    return build(A,B,0,n2-1,&in);
}

void postorder(treenode* node){
    if(node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ",node->val);
}


int main() {
    int n;
    scanf("%d",&n);

    int* preo = (int*)malloc(sizeof(int)*n);
    int* ino = (int*)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++)
        scanf("%d",&preo[i]);
    
    for(int i=0;i<n;i++)
        scanf("%d",&ino[i]);

    treenode* root = buildTree(preo,n,ino,n);

    postorder(root);
    return 0;
}
