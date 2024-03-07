#include<stdio.h>
typedef struct Book1{
    double price;
    char name[31];
}Book[10];
int main(){
    int line;
    scanf("%d",&line);
    int i;
    Book a;
    int min,max,mini,maxi;
    for(i=0;i<line;i++){
        getchar();
        scanf("Programming in %s",&a[i].name);
        getchar();
        scanf("%lf",&a[i].price);
        if(i==0){
            min=max=a[i].price;
            mini=maxi=0;
        }
        else{
            if(a[i].price>max){
                max=a[i].price;
                maxi=i;
            }
            if(a[i].price<min){
                min=a[i].price;
                mini=i;
            }
        }
    }
    printf("%.2lf, Programming in %s\n",a[maxi].price,a[maxi].name);
    printf("%.2lf, Programming in %s",a[mini].price,a[mini].name);
}