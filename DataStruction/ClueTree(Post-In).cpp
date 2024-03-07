#include<iostream>
using namespace std;
typedef struct TreeNode{
    int ltag,rtag;
    struct TreeNode *lchild,*rchild;
    char data;
}TreeNode,*Tree;

TreeNode* pre = new TreeNode();

void CreateTree(Tree &T){
    char c;
    cin>>c;
    if(c=='@') T=NULL;
    else{
        T=new TreeNode();
        T->ltag=0;
        T->rtag=0;
        T->data=c;
        CreateTree(T->lchild);
        CreateTree(T->rchild);
    }
}

void InOrder(Tree &T){
    if(T){
        InOrder(T->lchild);
        if(T->lchild==NULL){
            T->ltag=1;
            T->lchild=pre;
        }
        if(pre->rchild==NULL){
            pre->rtag=1;
            pre->rchild=T;
        }
        pre=T;
        InOrder(T->rchild);
    }
    else{
        pre->rtag=1;
    }
}

void Print(Tree T){
    Tree p = T;
    while(p){
        while(p->ltag==0){
            p=p->lchild;
        }
        printf("%c  %d  %d\n",p->data,p->ltag,p->rtag);
        while(p->rtag==1){
            p=p->rchild;
            printf("%c  %d  %d\n",p->data,p->ltag,p->rtag);
        }
        p=p->rchild;
    }
}

int main(){
    Tree tree1;
    pre->rtag=1;
    pre->rchild=NULL;
    CreateTree(tree1);
    InOrder(tree1);
    Print(tree1);
}