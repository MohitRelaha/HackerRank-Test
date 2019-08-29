// Merge list in reverse order


#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node* next;
};


void insert(struct node** head,int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;

    temp->next = *head;
    *head = temp;

}

struct node* merge(struct node* first, struct node* second)
{
    struct node* head = NULL;
    struct node* cur = NULL;

    while(first && second)
    {
        if(first->data > second->data)
        {
            if(head == NULL)
            {
                head = first;
                cur = first;
                first = first->next;
                
            }
            else
            {
                cur->next = first;
                cur = first;
                first = first->next;
            }

        }
        else
        {
            if(head == NULL)
            {
                head = second;
                cur = second;
                second = second->next;
            }
            else
            {
                cur->next = second;
                cur = second;
                second = second->next;
            }
        }

    }

   if(first)
    cur->next = first;

    if(second)
        cur->next = second;

    return head;
}

void print(struct node* head)
{
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
}


int main() {
    int i;
    struct node* first = NULL;
    struct node* second = NULL;

    for(i=0;i<3;i++)
    {
        int val;
        scanf("%d",&val);
        insert(&first,val);
    }

    for(i=0;i<3;i++)
    {
        int val;
        scanf("%d",&val);
        insert(&second,val);
    }


    struct node* head = merge(first,second);

    print(head);

    return 0;
}


