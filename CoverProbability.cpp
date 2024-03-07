#include<bits/stdc++.h>
using namespace std;
int main(){
    int line;
    scanf("%d",&line);
    double m,n,t,c;
    for(int i=0;i<line;i++){
        cin>>m>>n>>t>>c;
        printf("Case %d:\n",i+1);
        double s1=(t-c)*(t-c)*1.0/(t*t*1.0)+((m+n)*(t-c)*c+(c*c))*1.0/(m*n*t*t*1.0);
        double s2=((2*m*n-m-n)*(t-c)*c+(m+n-2)*c*c)*1.0/(m*n*t*t);
        printf("Probability of covering 1 tile  = %.4lf%%\n",s1*100);
        printf("Probability of covering 2 tile  = %.4lf%%\n",s2*100);
        printf("Probability of covering 3 tile  = %.4lf%%\n",(m-1)*(n-1)*(c*c-M_PI*c*c*1.0/4)*100.0/(m*n*t*t));
        printf("Probability of covering 4 tile  = %.4lf%%\n",(m-1)*(n-1)*M_PI*c*c*100.0/(4*m*n*t*t));
        if(i!=line-1)
            printf("\n");
    }
}