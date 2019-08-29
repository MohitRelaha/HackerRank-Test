// PALINDROME LL

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct ListNode listnode;

listnode* listnode_new(int val) {
	listnode* node = (listnode *) malloc(sizeof(listnode));
	node->val = val;
	node->next = NULL;
	return node;
}

void addNode(listnode* A, int i){
	listnode* temp = listnode_new(i);
	listnode* t = A;
	while(t->next != NULL){
		t = t->next;
	}
	t->next = temp;
}

/*
 * Complete the function below.
 */

listnode* reverse(listnode* head)
{
    if(head == NULL ||  head->next == NULL )
        return head;


    listnode* smallAns = reverse(head->next);

    listnode* temp = smallAns;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = head;
    head->next = NULL;

    return smallAns;
}

int isPalin(listnode* A){

    listnode* slow = A;
    listnode* fast = A;
    listnode* prev = NULL;

    while(fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = reverse(slow);

     listnode* first = A;
     listnode* second = prev->next;
     listnode* stop = second;

     while(first != stop)
     {
         if(first->val != second->val)
            return 0;
        
        first = first->next;
        second = second->next;
     }

    return 1;

}
int main(){
	int count = 0;
	int i;
	int v;
	scanf("%d",&count);
	scanf("%d",&v);
	listnode* A = listnode_new(v);
	for(i=0;i<count-1;i++){
		scanf("%d",&v);
		addNode(A,v);
	}
	if(isPalin(A) == 1) printf("true");
	else printf("false");
}

