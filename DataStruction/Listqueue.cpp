#include<bits/stdc++.h>
using namespace std;
typedef int ElemType;
typedef struct QNode{
    ElemType data;
    struct QNode* next;
}QNode;
typedef struct{
    QNode* front;
    QNode* rear;
}LinkQueue;

LinkQueue* init(){
    LinkQueue* queue = (LinkQueue*)malloc(sizeof(LinkQueue));
    QNode* root = (QNode*)malloc(sizeof(QNode));
    root->next=NULL;
    queue->front = root;
    queue->rear = root;
    return queue;
}

void inqueue(LinkQueue* a,ElemType b){
    QNode* p = (QNode*)malloc(sizeof(QNode));
    p->data=b;
    a->rear->next = p;
    a->rear = p;
    p->next = NULL;
}

void dequeue(LinkQueue* a){
    if(a->front->next==NULL)
        printf("NULL");
    else{
        QNode* temp = a->front->next;
        printf("%d ",temp->data);
        a->front->next = temp->next;
        if(temp->next==NULL)
            a->rear=a->front;
        free(temp);
    }
}

int main(){
    LinkQueue* queue = init();
    int element;
    while(1){
        scanf("%d",&element);
        if(element==-1)
            break;
        else
            inqueue(queue,element);
    }
    if(queue->front==queue->rear){
        printf("Head:NULL\nPop:NULL");
    }
    else{
        printf("Head:");
        printf("%d\nPop:",queue->front->next->data);
        while(queue->front!=queue->rear)
            dequeue(queue);
        printf("NULL");
    }
}