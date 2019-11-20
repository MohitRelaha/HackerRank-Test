#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack{
    int data;
    struct stack* next;
}st;

void push(st** s,int data){
    st* temp = (st*)malloc(sizeof(st));
    temp->data = data;
    temp->next = *s;
    *s = temp;
}

void pop(st** s){
    if(s == NULL)
        return;
    
    st* temp = *s;
    *s = (*s)->next;
    free(temp);
}

int empty(st* s){
    if(s == NULL)
        return 1;
    
    return 0;
}

int top(st* s){
    return s->data;
}

int isPrecedence(char inside,char outside){
    int ins,out;

    if(inside == '+' || inside == '-')
        ins = 0;
    else 
        ins = 1;
    
    if(outside == '+' || outside == '-')
        out = 0;
    else 
        out = 1;

    if(out > ins)
        return 1;
    else 
        return 0;
}

char* postfix(char* str){
    char* res = (char*)malloc(sizeof(char)*(strlen(str)+1));
    int index = 0;
    st* s = NULL;

    for(int i=0;i<strlen(str);i++){
        if( (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
            res[index++] = str[i] ;
        else{
            if(empty(s) || isPrecedence(top(s),str[i]))
                push(&s,str[i]);
            else
            {
                while(!empty(s) && !isPrecedence(top(s),str[i])){
                    char c = top(s);
                    res[index++] = c;
                    pop(&s);
                }

                push(&s,str[i]);
            }
        }
    }

    while(!empty(s)){
        char c = top(s);
        res[index++] = c;
        pop(&s);
    }

    res[strlen(str)] = '\0' ;

    return res;
}


int main(){

    char str[100];
    //gets(str);
    scanf("%s",str);
    char* res = postfix(str);
    printf("%s",res);
    return 0;
}
