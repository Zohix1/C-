// #include<bits/stdc++.h>
// using namespace std;

// typedef struct matrix{
//     int row;
//     int column;
//     int **mat;
// }matrix;

// int main(){
//     int m,n;
//     scanf("%d  %d",&m,&n);
//     matrix mat1;
//     mat1.row=m;
//     mat1.column=n;
//     mat1.mat = new int*[m];
//     for (int i = 0; i < m; i++) {
//         mat1.mat[i] = new int[n];
//     }
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             scanf("%d",&mat1.mat[i][j]);
//         }
//     }
//     matrix mat2;
//     scanf("%d  %d",&m,&n);
//     mat2.row=m;
//     mat2.column=n;
//     mat2.mat = new int*[m];
//     for (int i = 0; i < m; i++) {
//         mat2.mat[i] = new int[n];
//     }
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             scanf("%d",&mat2.mat[i][j]);
//         }
//     }
//     if(mat1.column!=mat2.row){
//         printf("Invalid Matrix multiplication!");
//         return 0;
//     }
//     matrix mat3;
//     mat3.row=mat1.row;
//     mat3.column=mat2.column;
//     mat3.mat = new int*[mat3.row];
//     for (int i = 0; i < mat3.row; i++) {
//         mat3.mat[i] = new int[mat3.column];
//     }
//     for(int i=0;i<mat3.row;i++){
//         for(int j=0;j<mat3.column;j++){
//             int sum=0;
//             for(int m=0;m<=mat1.row;m++){
//                 sum+=mat1.mat[i][m]*mat2.mat[m][j];
//             }
//             mat3.mat[i][j]=sum;
//         }
//     }
//     for(int i=0;i<mat3.row;i++){
//         for(int j=0;j<mat3.column;j++){
//             cout<<setw(10)<<mat3.mat[i][j];
//         }
//         printf("\n");
//     } 
//     for (int i = 0; i < mat1.row; i++) {
//         delete[] mat1.mat[i];
//     }
//     for (int i = 0; i < mat2.row; i++) {
//         delete[] mat2.mat[i];
//     }
//     for (int i = 0; i < mat3.row; i++) {
//         delete[] mat3.mat[i];
//     }
//     delete[] mat1.mat;
//     delete[] mat2.mat;
//     delete[] mat3.mat;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a1 ,a2 ,b1 ,b2 ,c1 ,c2 ;
    cin >> a1 >> a2 ;
    int A[a1][a2] ;
    for (int i=0 ;i<a1 ;i++ )
        for (int j=0 ;j<a2 ;j++ )
            cin >> A[i][j] ;
    cin >> b1 >> b2 ;
    int B[b1][b2] ;
    for (int i=0 ;i<b1 ;i++ )
        for (int j=0 ;j<b2 ;j++ )
            cin >> B[i][j] ;
    if(a1==a2&&a1==1){
        for(int i=0;i<b1;i++){
            for(int j=0;j<b2;j++){
                B[i][j]*=A[0][0];
            }
        }
        for (int i=0 ;i<c1 ;i++ ) {
            for (int j=0 ;j<c2 ;j++ )
                cout<<setw(10)<<B[i][j];
            cout << endl ;
        }
    }
    else if (a2 != b1) {
        cout << "Invalid Matrix multiplication!\n";
        return 0 ;
    }
    else{
        c1 = a1 ;c2 = b2 ;
        int C[c1][c2] ;
        for (int i=0 ;i<c1 ;i++ )
            for(int j=0 ;j<c2 ;j++ ) {
                int sum = 0 ;
                for(int x=0 ;x<a2 ;x++ )
                    sum += (A[i][x] * B[x][j]) ;
                C[i][j] = sum ;
            }
        for (int i=0 ;i<c1 ;i++ ) {
            for (int j=0 ;j<c2 ;j++ )
                cout<<setw(10)<<C[i][j];
            cout << endl ;
        }
    }
    return 0;
} 