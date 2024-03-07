#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode{
    int ltag,rtag;
    struct TreeNode *lchild,*rchild;
    char data;
}TreeNode,*Tree;

TreeNode* pre=new TreeNode();

void Create(Tree &T){
    char c;
    cin>>c;
    if(c=='@') T=NULL;
    else{
        T=new TreeNode();
        T->data=c;
        T->ltag=0;
        T->rtag=0;
        Create(T->lchild);
        Create(T->rchild);
    }
}

void PostOrder(Tree T){
    if(T){
        if(T->lchild==NULL){
            T->lchild=pre;
            T->ltag=1;
        }
        if(pre->rchild==NULL){
            pre->rchild=T;
            pre->rtag=1;
        }
        pre=T;
        if(T->ltag==0)
            PostOrder(T->lchild);
        if(T->rtag==0)
            PostOrder(T->rchild);
    }
    else{
        pre->rtag=1;
    }
}

void Print(Tree T){
    TreeNode* p=T;
    while(p){
        while(p->ltag==0){
            printf("%c  %d  %d\n",p->data,p->ltag,p->rtag);
            p=p->lchild;
        }
        printf("%c  %d  %d\n",p->data,p->ltag,p->rtag);
        p=p->rchild;
        while(p->rtag==1){
            printf("%c  %d  %d\n",p->data,p->ltag,p->rtag);
            p=p->rchild;
        }
        p=p->rchild;
    }
}
void Delete(Tree &T){
    if(T==NULL) return;
    else{
        Delete(T->lchild);
        Delete(T->rchild);
        delete(T);
    }
}

int main(){
    pre->rtag=1;
    pre->rchild=NULL;
    Tree tree1;
    Create(tree1);
    PostOrder(tree1);
    Print(tree1);
    Delete(tree1);
}

