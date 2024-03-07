#include<bits/stdc++.h>
using namespace std;

typedef struct Queue{
    int data[6];
    int head;
    int rear;
}Queue;

void Init(Queue* a){
    a->head=0;
    a->rear=0;
}

void Inqueue(Queue* q,int a){
    if(q->head==(q->rear+1)%6)
        printf("队列已满\n");
    else{
        q->data[q->rear]=a;
        q->rear=(q->rear+1)%6;
    }
}

int Pop(Queue* q){
    if(q->head==q->rear)
        printf("队列为空\n");
    else{
        int temp=q->data[q->head];
        q->head=(q->head+1)%6;
        return temp;
    }
}


int main(){
    Queue* q=new Queue();
    Init(q);
    Inqueue(q,7);
    cout<<Pop(q)<<endl;
    Pop(q);
    delete[] q;
}