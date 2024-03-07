#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    struct TreeNode* left;
    struct TreeNode* right;
    char val;
};

void InOrder(struct TreeNode* root)
{
    if(root == NULL)
    {
        return ;
    }
    InOrder(root->left);
    printf("%c ",root->val);
    InOrder(root->right);  
}

struct TreeNode* CreateTree(char* str,int* pi)
{
	if(str[*pi] =='#')
    {
        (*pi)++;
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val  =  str[(*pi)++];
    root->left = CreateTree( str, pi);
    root->right = CreateTree( str, pi);
    return root;
}

int main()
{
    char str[100];
    while(scanf("%s",str)!=EOF){
        int i = 0;
        struct TreeNode* root = CreateTree(str,&i);
        InOrder(root);
    }
    return 0;
}
