using namespace std;
#include<iostream>
#define max 5
template <class T>
class node
{
    public:
    T data;
    node* next;
};


template <class T>
class stack
{
    node<T>* head;
    node<T>* tail;

    public:
    stack()
    {
        head = NULL;
        tail = NULL;
        
    }
     void push()
    {
        T val;
        cin>>val;

        node<T>* temp = new node<T> ;
        temp->data = val;
        temp->next = NULL;
        
        if(head == NULL)
           { head = temp;
             tail = temp;
           }
        else
        {
        tail->next = temp;
        tail = temp;
        }
        
        
    }
    
    void pop()
    {
       node<T>* temp = head;

        if(head == tail)
        {
            head = NULL;
            tail = NULL;
            return;
        }


       while(temp->next != tail)
       {
           temp = temp->next ;
       }
       temp->next = tail->next;
       tail = temp;

        
    }

    T peek()
    {
        return head->data;
    }

    int isEmpty()
    {
        if(head == NULL)
            return 1;
        else
            return 0;
    }

    void show()
    {
       node<T>* temp = head;
       while(temp)
       {
           cout<<temp->data * 2<<" ";
           temp = temp->next;
       }

        cout<<endl;
    }


};


int main()
{
     
     stack <int> s1;
     s1.push();
     s1.push();
     s1.push();
     s1.push();
     s1.push();
     s1.pop();
     s1.show();
     stack <float> s2;
     s2.push();
     s2.push();
     s2.push();
     s2.push();
     s2.push();
     s2.pop();
     s2.show();
     return 0;
     
}

