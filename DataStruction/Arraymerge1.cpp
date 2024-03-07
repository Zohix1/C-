#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> merge;
    int number,temp;
    cin>>number;
    for(int i=0;i<number;i++){
        cin>>temp;
        merge.push_back(temp);
    }
    cin>>number;
    for(int i=0;i<number;i++){
        cin>>temp;
        if(find(merge.begin(),merge.end(),temp)==merge.end())
            merge.push_back(temp);
    }
    for(int i=0;i<merge.size();i++){
        printf("%d ",merge[i]);
    }
}