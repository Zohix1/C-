#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
typedef long long ll;
ll a[1010][1010];
using namespace std;
int main(){
    int n;
    long long sum=0;
    cin>>n;
    for(int i=0;i<2*n-1;i++){///注意在这里的循环条件，i必须从0开始
        for(int j=i;j>=0;j--){
            if(j<n&&i-j<n){
                sum++;
            }
            if(i%2!=0){
                a[i-j][j]=sum;
            }else{
                a[j][i-j]=sum;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}