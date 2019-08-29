// SORTED INSERT IN CIRCULAR ll


#include<stdio.h>
#include<stdlib.h>

/* structure for a node */
struct node
{
  int data;
  struct node *next;
};

void sortedInsert(struct node** head_ref, struct node* new_node)
{
    if(*head_ref == NULL)
    {
        *head_ref = new_node ;
        new_node->next = *head_ref ;
    }
    else
    {
        struct node* prev = NULL;
        struct node* cur = *head_ref;

        do
        {
            if(new_node->data > cur->data)
            {
                prev = cur;
                cur = cur->next;
            }
            else
                break;

        }while(cur != *head_ref);


        if(prev == NULL)
        {
            struct node* prev_head = *head_ref;
            new_node->next = *head_ref ;
            *head_ref = new_node ;

            struct node* temp = prev_head;
            
            while(temp->next != prev_head )
            {
                temp = temp->next;
            }


            temp->next = *head_ref;


        }
        else if(cur == *head_ref)
            {
                new_node->next = *head_ref ;
                prev->next = new_node ;
            }
            else
            {
                new_node->next = prev->next;
                prev->next = new_node;
            }
        
    }
    
    
}

void printList(struct node *start)
{
  struct node *temp;

  if(start != NULL)
  {
    temp = start;
    
    do {
      printf("%d\n", temp->data);
      temp = temp->next;
    } while(temp != start);
  }
}

/* Driver program to test above functions */
int main()
{
  int arr; //= {12, 56, 2, 11, 1, 90};
  int list_size, i;

  /* start with empty linked list */
  struct node *start = NULL;
  struct node *temp;
    
  int n;
  scanf("%d",&n);

  /* Create linked list from the array arr[].
    Created linked list will be 1->2->11->56->12 */
  for(i = 0; i< n; i++)
  {
    temp = (struct node *)malloc(sizeof(struct node));
    scanf("%d",&arr);
    temp->data = arr;
    sortedInsert(&start, temp);
  }

  printList(start);
  //getchar();
  return 0;
}
