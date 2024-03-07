#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

int findIndex(int arr[],int start,int end,int value){
    for (int i=start;i<=end;i++){
        if(arr[i]==value){
            return i;
        }
    }
    return -1;
}

TreeNode* buildTree(int inOrder[],int postOrder[],int inStart,int inEnd,int* postIndex){
    if (inStart>inEnd)
        return NULL;
    TreeNode* node=(TreeNode*)malloc(sizeof(TreeNode));
    node->data=postOrder[(*postIndex)--];
    node->right=NULL;
    node->left=NULL;
    if(inStart==inEnd)
        return node;
    int inIndex=findIndex(inOrder,inStart,inEnd,node->data);
    node->right=buildTree(inOrder,postOrder,inIndex+1,inEnd,postIndex);
    node->left=buildTree(inOrder,postOrder,inStart,inIndex-1,postIndex);
    return node;
}

void preOrderTraversal(TreeNode* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int postOrder[n],inOrder[n];
    for(int i=0;i<n;i++){
        scanf("%d",&postOrder[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&inOrder[i]);
    }
    int postIndex=n-1;
    TreeNode* root=buildTree(inOrder,postOrder,0,n-1,&postIndex);
    preOrderTraversal(root);
    printf("\n");
    return 0;
}