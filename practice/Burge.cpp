 #include<bits/stdc++.h>
 using namespace std;
 //注意概率的计算方式，不直接求因为不好判断何时剩下的汉堡种类相同（可能剩余超过三人时只剩一种汉堡）
 int main(){
     int line,number;
     double p[50000]={0};
     p[1]=1;
     for(int i=1;i<50000;i++){
        p[i+1]=p[i]*(2*i-1)/(2*i);
     }
     cin>>line;
     for(int i=0;i<line;i++){
         cin>>number;
        //  if(i)
        //     printf("\n");
         printf("%.4lf\n",1-p[number/2]);
     }
 }