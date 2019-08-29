// SWAP with key1 / key2 value


#include<iostream>
using namespace std;
struct node
{
int info;
node *link;
};
int main()
{
int i,k,key1,key2,item;
struct node *start,*n,*ptr,*loc1,*loc2,*loc1p,*loc2p;

cin>>k;  // no. of nodes
start = NULL;
for(i=0;i<k;i++)
{
    cin>>item;

    ptr = (struct node*)malloc(sizeof(struct node*));
    
    ptr->info = item;
    ptr->link = start;
    start = ptr;
    


    // Insert At End
    /*
    ptr->info = item;
    ptr->link = NULL;

    if(start == NULL)
    {
        start = ptr;
    }
    else
    {
        n = start;
        while(n->link != NULL)
        {
            n = n->link;
        }

        n->link = ptr;

    }
*/
    

}


cin>>key2;
cin>>key1;

n = start;
while(n)
{
    cout<<n->info<<" " ;
    n = n->link;
}

loc1 = loc2 = loc1p = loc2p = NULL;

n = start;
int flag1=1,flag2=1;
while(!(loc1 && loc2))
{
    if(flag1)
    {
    if(n->info == key1)
      {  loc1 = n;
         flag1 = 0;
      }
    else
        loc1p = n;

    }

    if(flag2)
    {
        if(n->info == key2)
        {
            loc2 = n;
            flag2 = 0;
        }
        else
            loc2p = n;
    }   

    n = n->link;
}


    ptr = loc1->link;
    loc1->link = loc2->link;
    loc2->link = ptr;

    if(loc1p)
    loc1p->link = loc2;
    else
    start = loc2;

    if(loc2p)
    loc2p->link = loc1;
    else
    start = loc2;

    cout<<endl;

    n = start;
    while(n)
    {
        cout<<n->info<<" " ;
        n = n->link;
    }

	return 0;
}
