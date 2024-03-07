#include<bits/stdc++.h>
using namespace std;
typedef struct Stack{
    int sta[6];
    int top;
}Stack;

void Init(Stack* a){
    a->top=0;
}

void Push(Stack* a,int e){
    if(a->top<5)
        a->sta[++(a->top)]=e;
    else
        printf("Õ»ÒÑÂúÁË\n");
}

int Pop(Stack* a){
    if(a->top){
        a->top--;
        return a->sta[(a->top)+1];
    }
    else{
        printf("Õ»¿Õ\n");
    }
}


int main(){
    Stack* a;
    a=new Stack();
    Init(a);
    Push(a,6);
    cout<<Pop(a)<<endl;
    cout<<Pop(a)<<endl;
    delete[] a;
}