#include<bits/stdc++.h>
using namespace std;
int Fib(int a);
int main(){
    int n;
    cin>>n;
    cout<<Fib(n)<<endl;
}
int Fib(int a){
    if(a<=2&&a>0)
        return 1;
    else 
        return Fib(a-1)+Fib(a-2);
}