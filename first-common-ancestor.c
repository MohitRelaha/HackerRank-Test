#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct bst{
    int key;
    struct bst* left;
    struct bst* right;
}BST;


BST* newNode(int key){
    BST* newnode = (BST*)malloc(sizeof(BST*));
    newnode->left = newnode->right = NULL;
    newnode->key = key;

    return newnode;
}

BST* insert(BST* node,int key){
    if(node == NULL)
        return newNode(key);
    else if(node->key > key)
        node->right = insert(node->right,key);
    else if(node->key < key)
        node->left = insert(node->left,key);
    
    return node;
}


BST* lcaHelp(BST* node,int key1,int key2,int* ans){
    if(node == NULL)
        return NULL;
    if(node->key == key1 || node->key == key2)
        return node;

    BST* x = lcaHelp(node->left,key1,key2,ans);
    BST* y = lcaHelp(node->right,key1,key2,ans);

    if(x && y){
        *ans = 1;
        return node;
    }
    else if(x)
        return x;
    else
        return y;

}

BST* myAns(BST* node,BST* req){
    if(node == NULL)
        return NULL;

    if(node->left == req || node->right == req)
        return node;

    return myAns(node->left,req) || myAns(node->right,req) ;
}



int lca(BST* root,int key1,int key2){

    if(root->key == key1 || root->key == key2)
            return -1;

    int ans = 0;
    BST* answer = lcaHelp(root,key1,key2,&ans);
    
    if(ans){
        return answer->key;
    } 
    else{
        return myAns(root,answer)->key;
    }
        
}


int main() {

    BST* root = NULL;

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        int k ;
        scanf("%d",&k);

        root = insert(root,k);
    }

    int t;
    scanf("%d",&t);

    for(int i=0;i<t;i++){
        int first,second;
        scanf("%d%d",&first,&second);
        printf("%d\n",lca(root,first,second));
    }
    return 0;
}
