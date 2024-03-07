#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    int sum;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if(a==0&&b==0&&c==0&&d==0)
        return 0;
    else{
        while(!(a==0&&b==0&&c==0&&d==0)){
            sum=40;
            if(b>a)
                sum+=(40+a-b);
            else
                sum+=(a-b);
            if(b>c)
                sum+=(40+c-b);
            else
                sum+=(c-b);
            if(c<d)
                sum+=(40+c-d);
            else
                sum+=(c-d);
            printf("½á¹ûÊÇ£º%d\n",sum*9);
            scanf("%d %d %d %d",&a,&b,&c,&d);
        }
    }
}