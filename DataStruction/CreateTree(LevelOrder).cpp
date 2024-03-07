#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode{
    int data;
    TreeNode *left,*right;
}TreeNode;

void Create(TreeNode* tree[],int number){
    int p=1;
    tree[0]->left=tree[1];
    int count=number;
    while(count){
        int temp;
        cin>>temp;
        if(temp==0)
            tree[p]=NULL;
        else{
            tree[p]->data=temp;
            if(p*2<=number)
                tree[p]->left=tree[p*2];
            if(p*2+1<=number)
                tree[p]->right=tree[p*2+1];
        }
        count--;
        p++;
    }
}

void Print(TreeNode* p){
    if(p&&p->data!=0){
        Print(p->left);
        printf("%d ",p->data);
        Print(p->right);
    }
}


int Deep(TreeNode* p){
    if(p==NULL||p->data==0)
        return 0;
    else{
        int left=Deep(p->left);
        int right=Deep(p->right);
        return (left>right)?left+1:right+1;
    }
}

int main(){
    int count;
    cin>>count;
    while(count){
        int number;
        cin>>number;
        TreeNode* tree[number+1]={NULL};
        for (int i = 0; i <= number; ++i) {
                tree[i] = new TreeNode();
        }
        Create(tree,number);
        Print(tree[1]);
        printf("\n%d\n",Deep(tree[1]));
        for (int i = 0; i <= number; ++i)
            delete tree[i];
        count--;
    }
    
}