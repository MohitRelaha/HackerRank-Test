#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

struct node* insert( struct node* root, int data ) {
        
    if(root == NULL) {
    
        struct node* node = (struct node*)malloc(sizeof(struct node));

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;
      
    } else {
      
        struct node* cur;
        
        if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
        } else {
            cur = insert(root->right, data);
            root->right = cur;
        }
    
        return root;
    }
}


struct queue{
    int val;
    struct node* nod;
};

struct queue* q[1000];
int front;
int end;

int arr[500];
int l;
int r;

void bottomview()
{

while(front < end-1)
{
    if(q[front] == NULL)
    {
        q[end++] = NULL;
        front++;
    }

    if(q[front] )
    {
        arr[250 + q[front]->val] = q[front]->nod->data ;
        if(q[front]->val < l)
            l=q[front]->val;
        if(q[front]->val > r)
            r=q[front]->val;
    }


    if(q[front]->nod->left)
    {
        struct queue* temp = (struct queue*)malloc(sizeof(struct queue));
        temp->val = q[front]->val - 1;
        temp->nod = q[front]->nod->left;
        q[end++] = temp;
    }

    if(q[front]->nod->right)
    {
        struct queue* temp = (struct queue*)malloc(sizeof(struct queue));
        temp->val = q[front]->val + 1;
        temp->nod = q[front]->nod->right;
        q[end++] = temp;
    }

    front++;
}

}



void bottomView( struct node *root) {
    
    if(root == NULL)
        return;
   
    struct queue* temp = (struct queue*)malloc(sizeof(struct queue));
    temp->val = 0;
    temp->nod = root;

    q[end++] = temp;
    q[end++] = NULL ;
    

    bottomview();

    int i;

    for(i=l;i<=r;i++)
        printf("%d ",arr[250+i]);

   
}


int main() {
  
    struct node* root = NULL;
    
    int t;
    int data;

    scanf("%d", &t);

    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }
  
    bottomView(root);
    return 0;
}
