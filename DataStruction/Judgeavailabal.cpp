#include<bits/stdc++.h>
using namespace std;
int main(){
    int limit,num,count;
    scanf("%d %d %d",&limit,&num,&count);
    int stack[num+1];
    for(int i=0;i<num+1;i++)
        stack[i]=i;
    while(count>0){
        int queue[num+1]={0};
        for(int i=1;i<num+1;i++){
            scanf("%d",&queue[i]);
        }
        int temp[limit+1]={0};
        int ptr1=1,ptr2=0,ptr3=1;
        while(1){
            while(temp[ptr2]!=queue[ptr3]&&ptr2<=limit){
                ptr2++;
                temp[ptr2]=stack[ptr1];
                ptr1++;
            }
            if(ptr2>limit)
                    ptr2--;
            while(temp[ptr2]==queue[ptr3]&&ptr3<=num){
                ptr3++;
                temp[ptr2]=0;
                ptr2--;
            }
            if(queue[ptr3]<temp[ptr2]){
                printf("NO");
                break;
            }
            else if(ptr3==num+1){
                printf("YES");
                break;
            }
            else if(queue[ptr3]>temp[ptr2]&&ptr2==limit){
                printf("NO");
                break;
            }
        }
        if(count!=1)
            printf("\n");
        count--;
    }
}