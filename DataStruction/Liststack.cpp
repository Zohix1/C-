#include<bits/stdc++.h>
using namespace std;
int Stack_size=10;
int now=0;
typedef struct Stack{
    int number;
    struct Stack* next;
}S,*Ptr;

S root;
Ptr a=&root;

bool Isfull(){
    if(now==Stack_size)
        return true;
    else
        return false;
}
bool Isempty(){
    if(now==0) 
        return true;
    else 
        return false;
}

void push(int b){
    if(Isfull())
        printf("FULL ");
    else{
        S* p = (S*)malloc(sizeof(S));
        p->next=a->next;
        a->next=p;
        p->number=b;
        now++;
    }
}
void pop(){
    if(Isempty())
        printf("EMPTY ");
    else{
        printf("%d ",a->next->number);
        Ptr temp = a->next;
        a->next=temp->next;
        free(temp);
        now--;
    }
}
int main(){
    int count=0;
    scanf("%d",&count);
    int signal;
    while(count>0){
        scanf("%d",&signal);
        if(signal==0)
            pop();
        else
            push(signal);
        count--;
    }
    printf("\n");
    while(now!=0) 
        pop();
    free(a);
}