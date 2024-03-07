#include<bits/stdc++.h>
using namespace std;

typedef struct HuffmanTree{
    int value;
    char element;
    struct HuffmanTree *lchild,*rchild;
}HT,*Tree;

// 8
// abcdefgh
// 5 29 7 8 14 23 3 11


typedef struct Queue{
    char element;
    int value;
    Queue* next;
}Q;

int main(){
    int count;
    scanf("%d",&count);
    char queue1[count];
    int queue2[count];
    getchar();
    for(int i=0;i<count;i++){
        queue1[i]=getchar();
    }
    getchar();
    for(int i=0;i<count;i++){
        scanf("%d",&queue2[i]);
    }
    // for(int i=0;i<count;i++){
    //     for(int j=0;j<count-i-1;j++){
    //         if(queue2[j]>queue2[j+1]){
    //             int temp2=queue2[j+1];
    //             queue2[j+1]=queue2[j];
    //             queue2[j]=temp2;
    //             char temp1=queue1[j+1];
    //             queue1[j+1]=queue1[j];
    //             queue1[j]=temp1;
    //         }
    //     }
    // }
    Q* root=(Q*)malloc(sizeof(Q));
    root->next=NULL;
    root->value=0;
    Q* p=root;
    for(int i=0;i<count;i++){
        p=root;
        while(p->next!=NULL&&queue2[i]>p->next->value)
            p=p->next;
        Q* temp =(Q*)malloc(sizeof(Q));
        temp->value=queue2[i];
        temp->element=queue1[i];
        temp->next=p->next;
        p->next=temp;
    }
    //¹¹½¨¹þ·òÂüÊ÷
    while(root->next){
        Q* left=root->next;
        Q* right=left->next;
        HT* node=(HT*)malloc(sizeof(HT));
        node->value=left->value;
        node->element='#';
        node->lchild=
    }

    p=root;
    while(p){
        Q* temp=p;
        p=p->next;
        free(temp);
    }
}