#include<bits/stdc++.h>
using namespace std;
int node,sum[20005];//sum[]��ʾÿ�������ִ���
int tree[20005][26];
char str[1005][26];

void insert(char* str){
    int p=0;
    for(int i=0;str[i];i++){
        int path=str[i]-'a';//��ʾ�ɵ�ǰ��㣬ͨ����ĸpath��������һ����㣬��һ�����ı��Ϊnode
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