#include<bits/stdc++.h>
using namespace std;

typedef struct Stack{
    int data;
    Stack* next;
}Stack;

typedef struct StackList{
    Stack* top;
    int count;
}StackList;


void Init(StackList* T){
    T->top=NULL;
    T->count=0;
}

void Push(StackList* T,int a){
    Stack* p=new Stack();
    p->data=a;
    p->next=T->top;
    T->top=p;
    T->count++;
}

void Pop(StackList* T){
    if(T->top==NULL)
        printf("Õ»Îª¿Õ\n");
    else{
        Stack* temp=T->top;
        cout<<T->top->data<<endl;
        T->top=T->top->next;
        delete[] temp;
        T->count--;
    }
}

int main(){
    StackList* top=new StackList();
    Init(top);
    Push(top,1);
    Pop(top);
    Pop(top);
}