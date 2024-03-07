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
    for(int i=0,j=0;i<number;i++){
        cin>>temp;
        if(find(merge.begin(),merge.end(),temp)!=merge.end()){
            merge.erase(find(merge.begin(),merge.end(),temp));
        }
    }
    cout<<merge.size()<<endl;
    for(int i=0;i<merge.size();i++){
        if(i)
            cout<<" ";
        printf("%d",merge[i]);
    }
}