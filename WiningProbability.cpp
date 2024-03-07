#include<bits/stdc++.h>
using namespace std;
int main(){
    int line;
    cin>>line;
    int n,m;
    double p;
    for(int i=0;i<line;i++){
        double pr1,pr2,temp;
        cin>>n>>p>>m;
        pr1=pow(1-p,m-1)*p;
        pr2=pow(1-p,n-1)*(1-p);
        while(true){
            temp=pr1;
            pr1=pr1+pr2*pow(1-p,m-1)*p;
            pr2*=pow(1-p,n-1)*(1-p);
            if((pr1/10000)==(temp/10000))
                break;
        }
        if(i)
            cout<<endl;
        printf("%.4lf",pr1);
        
    }
}