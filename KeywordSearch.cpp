#include<bits/stdc++.h>
using namespace std;
int main(){
    int line;
    cin>>line;
    int count=0;
    for(int i=0;i<line;i++){
        int number;
        cin>>number;
        string key[number];
        for(int j=0;j<number;j++){
            cin>>key[j];
        }
        string re;
        cin>>re;
        for(int k=0;k<number;k++){
            bool found=re.find(key[k])!=string::npos;
            if(found)
                count++;
        }
        printf("%d",count);
        if(i!=line-1)
            printf("\n");
        count=0;
    }
}