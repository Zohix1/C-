#include<stdio.h>
int search(int* arr,int target,int len){
    int high=len-1;
    int low=0;
    int state=0;
    int min=len+1;
    while(high>=low){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            state=1;
            if(min>mid)
                min=mid;
            high=mid-1;
        }
        else if(arr[mid]>target)
            high=mid-1;
        else
            low=mid+1;
    }
    if(state==0)
        return len;
    else
        return min;
}

int main(){
    int len,number;
    scanf("%d %d",&len,&number);
    int arr[len];
    for(int i=0;i<len;i++)
        scanf("%d",&arr[i]);
    int location=search(arr,number,len);
    printf("%d\n",location+1);
}