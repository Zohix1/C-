#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> merge,merge2;
    int number,temp;
    cin>>number;
    for(int i=0;i<number;i++){
        cin>>temp;
        merge.push_back(temp);
        if(merge[i]<merge[i-1]&&i!=0){
            cout<<"erro"<<endl;
            break;
        }
    }
    for(int i=0;i<merge.size();i++){
        printf("%d ",merge[i]);
    }
    cout<<endl;
    cin>>number;
    for(int i=0;i<number;i++){
        cin>>temp;
        if(find(merge2.begin(),merge2.end(),temp)==merge2.end())
            merge2.push_back(temp);
        if(merge2[i]<merge2[i-1]&&i!=0){
            cout<<"erro"<<endl;
            break;
        }
    }
    for(int i=0;i<merge2.size();i++){
        printf("%d ",merge2[i]);
    }
    cout<<endl;
    merge.insert(merge.end(),merge2.begin(),merge2.end());
    for(int i=0;i<merge.size();i++){
        printf("%d ",merge[i]);
    }
}