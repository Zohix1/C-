#include<bits/stdc++.h>
using namespace std;
int main(){
    int line;
    cin>>line;
    int number;
    int f[40];
    int i,j;
    f[0]=0;
    f[1]=1;
    for(i=2;i<40;i++)
        f[i]=f[i-1]+f[i-2];
    while(line){
        cin>>number;
        printf("%d = ",number);
        int res[40]={0};
        i=39;
        while(number){
            if(f[i]>number)
                i--;
            else{
                res[i]=1;
                number-=f[i];
            }
        }
        for(j=39;res[j]==0;j--);
        for(;j>=2;j--)
            printf("%d",res[j]);
        printf(" (fib)");
        line--;
        if(line)
            printf("\n");
    }
    return 0;
}