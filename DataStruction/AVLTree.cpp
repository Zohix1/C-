#include<stdio.h>
#include<stdlib.h>

typedef struct Tree{
    int element;
    struct Tree *left,*right;
}node;

int High(node* T){
    if(!T)
        return 0;
    int left=High(T->left);
    int right=High(T->right);
    return left>right?left+1:right+1;
}

node* LL(node* T){
    node* temp;
    temp=T->right;
    T->right=temp->left;
    temp->left=T;
    return temp;
}

node* RR(node* T){
    node* temp;
    temp=T->left;
    T->left=temp->right;
    temp->right=T;
    return temp;
}

node* LR(node* T){
    node *temp1,*temp2;
    temp1=T->left->right;
    temp2=T->left;
    temp2->right=temp1->left;
    temp1->left=temp2;
    T->left=temp1;
    T->left=temp1->right;
    temp1->right=T;
    return temp1;
}

node* RL(node* T){
    node *temp1,*temp2;
    temp1=T->right->left;
    temp2=T->right;
    temp2->left=temp1->right;
    temp1->right=temp2;
    T->right=temp1;
    T->right=temp1->left;
    temp1->left=T;
    return temp1;
}

node* Insert(node* T,int number){
    if(!T){
        node* temp=(node*)malloc(sizeof(node));
        temp->element=number;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    else if(T->element>number){
        T->left=Insert(T->left,number);
        if((High(T->left)-High(T->right))==2){
            if(T->left->element>number)
                T=RR(T);
            else
                T=LR(T);
        }
    }
    else if(T->element<number){
        T->right=Insert(T->right,number);
        if((High(T->right)-High(T->left))==2){
            if(T->right->element<number)
                T=LL(T);
            else
                T=RL(T);
        }
    }
    return T;
}

int main(){
    int count;
    scanf("%d",&count);
    node* T=NULL;
    for(int i=0;i<count;i++){
        int number;
        scanf("%d",&number);
        T=Insert(T,number);
    }
    printf("%d",T->element);
}