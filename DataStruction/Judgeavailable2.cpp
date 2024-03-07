#include<stdio.h>
#include<stdlib.h>
#define MAXN 1005

int stack[MAXN];
int top=-1;

void push(int x){
    stack[++top]=x;
}

int pop(){
    return stack[top--];
}

int isPossible(int n,int m,int sequence[]){
    int i=0,j=1;

    for(i=0;i<n;i++){
        while(j<=n+1){
            if(top>=0&&stack[top]==sequence[i]){
                pop();
                break;
            }
            push(j++);
            if(top>=m){
                return 0;
            }
        }
    }
    return top==-1;
}

int main(){
    int m,n,k;
    scanf("%d %d %d",&m,&n,&k);

    while(k--){
        top=-1;
        int sequence[n];
        for(int i=0;i<n;i++){
            scanf("%d",&sequence[i]);
        }
        if(isPossible(n,m,sequence)){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}