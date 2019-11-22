#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


typedef struct bst{
    int data;
    struct bst* left;
    struct bst* right;
}BST ;


BST* newNode(int data){
    BST* temp = (BST*)malloc(sizeof(BST));
    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}


BST* insert(BST* node, int data){
    if(node == NULL)
        return newNode(data);
    else if(node->data > data)
        node->left = insert(node->left,data);
    else if(node->data < data)
        node->right = insert(node->right,data);

    return node;
}

int max(int a, int b){
    return a>b?a:b ;
}


int depth(BST* node){
    if(node == NULL)
        return 0;
    
    return 1 + max(depth(node->left),depth(node->right));
}



void diameter(BST* node,int* dia){
    if(node == NULL)
        return;

    int d = 1 + depth(node->left) + depth(node->right);
    if(d > *dia)
        *dia = d;

    diameter(node->left,dia);
    diameter(node->right,dia);
}



int main() {
    
    int n;
    scanf("%d",&n);

    BST* root = NULL;

    for(int i=0;i<n;i++){
        int val;
        scanf("%d",&val);
        root = insert(root,val);
    }

    int dia = 0;
    diameter(root,&dia);

    printf("%d",dia);

    return 0;
}
