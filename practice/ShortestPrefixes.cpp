#include<bits/stdc++.h>
using namespace std;
int node,sum[20005];//sum[]表示每个结点出现次数
int tree[20005][26];
char str[1005][26];

void insert(char* str){
    int p=0;
    for(int i=0;str[i];i++){
        int path=str[i]-'a';//表示由当前结点，通过字母path连接至下一个结点，下一个结点的编号为node
        if(!tree[p][path])
            tree[p][path]=++node;
        p=tree[p][path];
        sum[p]++;
    }
}

void search(char* str){
    int p=0;
    for(int i=0;str[i];i++){
        int path=str[i]-'a';
        cout<<str[i];
        p=tree[p][path];
        if(sum[p]==1)
            break;
    }
}

int main(){
    int n=0;
    while(~scanf("%s",&str[n])){
        insert(str[n]);
        n++;
    }
    for(int i=0;i<=n;i++){
        printf("%s ",str[i]);
        search(str[i]);
        if(i!=n-1)
            printf("\n");
    }
}