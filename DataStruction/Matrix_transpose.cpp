#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n,t;
    int a,b,c;
    scanf("%d %d %d",&m,&n,&t);
    int mat[m][n]={0};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=0;
        }
    }
    int temp1[t][4]={0};
    for(int i=0;i<t;i++){
        scanf("%d %d %d",&a,&b,&c);
        mat[a][b]=c;
        temp1[i][1]=b;
        temp1[i][2]=a;
        temp1[i][3]=c;
    }
    int temp2[t][3]={0};
    int p=0;
    for(int j=0;j<n;j++){
        for(int i=0;i<m;i++){
            if(mat[i][j]!=0){
                temp2[p][0]=j;
                temp2[p][1]=i;
                temp2[p][2]=mat[i][j];
                p++;
            }
        }
    }
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
            if(temp2[j][0]==temp1[i][1]&&temp2[j][1]==temp1[i][2]){
                temp1[i][0]=j;
                break;
            }
        }
    }
    for(int i=0;i<t;i++){
        printf("%d %d %d %d\n",temp1[i][0],temp1[i][1],temp1[i][2],temp1[i][3]);
    }
}
