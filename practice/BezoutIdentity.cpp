 #include<bits/stdc++.h>
 using namespace std;
 int gcd(int a,int b){
     if(b==0)
        return a;
    else{
        return gcd(b,a%b);
    }
 }
 int main(){
    while(true){
        int n=0;
        int f[1000]={0};
        scanf("%d",&f[++n]);
        if(f[n]==0)
            break;
        while(f[n]!=0)
            scanf("%d",&f[++n]);
        n--;
        for(int i=1;i<n;i++)
            f[i]=f[i]-f[i+1];
        int Ans=f[1];
        for(int i=2;i<n;i++)
            Ans=gcd(f[i]==0?Ans:f[i],Ans);
        printf("%d\n",abs(Ans));
    }
    //  int number[1000]={0};
    //  int temp,i=0,j;
    //  int state=0;
    //  scanf("%d",&temp);
    //  while(temp!=0){
    //      number[i++]=temp;
    //      scanf("%d",&temp);
    //  }
    //  number[i]=0;
    //  while(number[0]){
    //      for(i--;i>0;i--){
    //         number[i]=number[i]-number[i-1];
    //      }
    //      for(j=1;number[j]!=0;j++){
    //          number[j]=gcd(number[j],number[j-1]);
    //      }
    //      cout<<number[j-1];
    //      if(state)
    //         printf("\n");
    //      else
    //         state=1;
    //      i=0;
    //      scanf("%d",&temp);
    //      while(temp!=0){
    //         number[i++]=temp;
    //         scanf("%d",&temp);
    //      }
    //  }
 }