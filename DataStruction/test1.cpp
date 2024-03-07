#include <stdio.h>
#include <string.h>
void getStr(char str[]);
void insertStr(char str1[],char str2[]);

void getStr(char str[]){
    int q=1;
    while(q){
        scanf("%s",str);
        int len=strlen(str);
        if(len<2)
            printf("Length must exceed 2\n");
        else
            q=0;
    }
}

void insertStr(char str1[],char str2[]){
    int l1=strlen(str1),l2=strlen(str2);
    int i,j;
    if(l1-2>l2){
        for(i=1,j=0;j<l2;i++,j++){
            str1[i]=str2[j];
        }
        str1[j+1]=str1[l1-1];
        for(i=j+2;i<l1;i++)
            str1[i]='\0';
    }
    else if(l1-2<=l2){
        str1[l2+1]=str1[l1-1];
        for(i=1,j=0;j<l2;i++,j++){
            str1[i]=str2[j];
        }
        str1[l2+2]='\0';
    }
}

int main(void)
{
    char str1[128], str2[128];
    getStr(str1);
    getStr(str2);
    insertStr(str1,str2);
    printf("Result is: %s", str1);
    
    return 0;
}
/* 请在这里填写答案 */