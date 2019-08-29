#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct stack
{
int data;
struct stack* next;

}st;

void push(st** top, int data)
{
    st* new = (st*)malloc(sizeof(st));
    
    new->data = data;
    new->next = *top;
    *top = new;
    
}

int peek(st* top)
{
    return top->data;
}

int empty(st* top)
{
    if(top==NULL)
    {
        return 1;
    }
    return 0;
}
void pop(st** top)
{
    st* temp=*top;
    *top=(*top)->next;
    free(temp);
    temp=NULL;    
}



int main() {

    int n,i;
    scanf("%d",&n);

    while(1)
    {
        
        int arr[n];

        for(i=0;i<n;i++)
        {   
            scanf("%d",&arr[i]);
        } 


    int need = 1;
    int res[n];
    st* s = NULL;
    int flag=0;

    for(i=0;i<n;i++)
    {
        if(arr[i] == need)
        {
            res[need-1] = arr[i];
            need++;
            continue;
        }
        else if(!empty(s))
        {
            if(peek(s) == need)
                {
                    res[need-1] = peek(s);
                    pop(&s);
                    need++;
                    i--;
                    continue;
                }
            
        }

        if(!empty(s))
        {
            if(arr[i] > peek(s))
            {
                flag=1;
                break;
            }
        }
       
        push(&s,arr[i]);
        

    }


    if(flag==1)
        printf("no\n");
    else
    {
        // flag is zero here

        while(!empty(s))
        {
            res[need-1] = peek(s);
            pop(&s);
            need++;
        }


        for(i=0;i<n;i++)
        {
            if(!(res[i] == i+1))
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
            printf("no\n");
        else 
            printf("yes\n");
    }

        
        scanf("%d",&n);
        
        if(n==0)
            break;


    }


    return 0;
}


