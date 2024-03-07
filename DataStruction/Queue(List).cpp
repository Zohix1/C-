#include<bits/stdc++.h>
using namespace std;

typedef struct Queue{
    int data;
    Queue* next;
}Queue;

typedef struct QueueList{
    Queue* head;
    Queue* rear;
}QueueList;

void Init(QueueList* q){
    q->head=NULL;
    q->rear=NULL;
}

void Push(QueueList* q,int a){
    Queue* t=new Queue();
    t->data=a;
    t->next=q->rear;
    q->rear=t;
}

void Pop(QueueList* q){
    if(q->head==q->rear)
        printf("╤сапря©у\n");
    else{
        Queue* temp=q->rear;
        q->rear=q->rear->next;
        cout<<temp->data<<endl;
        delete[] temp;
    }
}

int main(){
    QueueList* q=new QueueList();
    Init(q);
    Push(q,2);
    Pop(q);
    Pop(q);
    delete[] q;
}