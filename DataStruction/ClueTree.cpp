#include<iostream>
using namespace std;

typedef struct BiThrNode
{                
    char data;                        
    struct BiThrNode *lchild,*rchild;
    int LTag,RTag;
}BiThrNode,*BiThrTree;


BiThrNode *pre=new BiThrNode;

void CreateBiTree(BiThrTree &T)
{    
    char ch;
    cin >> ch;
    if(ch=='#')  T=NULL;            
    else
    {                            
        T=new BiThrNode;
        T->data=ch;                    
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);    
    }                                
}                                

void InThreading(BiThrTree p);
void InOrderTraverse_Thr(BiThrTree T);


void InThreading(BiThrTree p){
    if(p){
        InThreading(p->lchild);
        if(p->lchild==NULL){
            p->lchild=pre;
            p->LTag=1;
        }
        if(pre != NULL && pre->rchild==NULL){
            pre->rchild=p;
            pre->RTag=1;
        }
        pre=p;
        InThreading(p->rchild);
    }
}

void InOrderTraverse_Thr(BiThrTree T){
    BiThrTree ptr = T;
    while(ptr)
    {   
        while(ptr->LTag != 1)
            ptr = ptr->lchild;
        cout << ptr->data;
        while(ptr->RTag == 1)
        {
            ptr = ptr->rchild;
            cout << ptr->data;
        }
        ptr = ptr->rchild;
    }
}

int main()
{
    pre->RTag=1;
    pre->rchild=NULL;
    BiThrTree tree;
    CreateBiTree(tree);
    InThreading(tree);
    InOrderTraverse_Thr(tree);
    return 0;
}