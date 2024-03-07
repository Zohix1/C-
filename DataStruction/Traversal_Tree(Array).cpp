#include<bits/stdc++.h>
using namespace std;
char tree[10000]={'\0'};
void print(char* tree,int i){
    if(tree[i]=='\0')
        return;
    print(tree,i*2);
    printf("%c ",tree[i]);
    tree[i]='\0';
    print(tree,i*2+1);
}

char insert(char* tree,char* str,int* p,int i){
    if(str[*p]=='#'){
        (*p)++;
        return '\0';
    }
    tree[i]=str[(*p)++];
    tree[i*2]=insert(tree,str,p,i*2);
    tree[i*2+1]=insert(tree,str,p,i*2+1);
    return tree[i];
}
int main(){
    char input[105]={'#'};
    while(scanf("%s",&input)!=EOF){
        int p=0,m=1;
        char a = insert(tree,input,&p,m);
        print(tree,1);
        printf("\n");
        for(int i=0;i<10000;i++){
            tree[i]='\0';
            if(i<105)
                input[i]='#';
        }
    }
}
