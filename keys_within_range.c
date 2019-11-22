#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};
struct node* root= NULL;


void Print(struct node *node, int k1, int k2)
{   
    if(node == NULL)
        return;
        
    Print(node->left,k1,k2);
    if(k1 <= node->data && k2 >= node->data)
        printf("%d ",node->data);
    Print(node->right,k1,k2);
}
struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}
 struct node* insert(struct node* node, int data)
{
    if(node == NULL)
        return newNode(data);
    else if(node->data > data)
        node->left = insert(node->left,data);
    else if(node->data < data)
        node->right = insert(node->right,data);

    return node;     
}

int main()
{


    int item,n,i,k1,k2;
    scanf("%d",&n);
   
    scanf("%d%d",&k1,&k2);

    for(i=0;i<n;i++)
    {
        scanf("%d",&item);
    root= insert(root,item);

}
Print(root, k1, k2);

  getchar();
  return 0;
}
