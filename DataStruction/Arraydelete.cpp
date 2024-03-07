#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> merge;
    int number,temp;
    int min,max;
    cin>>number;
    for(int i=0;i<number;i++){
        cin>>temp;
        merge.push_back(temp);
    }
    scanf("%d %d",&min,&max);
    for(int i=0;i<merge.size();i++)
	{
		if(merge[i]>=min&&merge[i]<=max){
            merge.erase(merge.begin()+i);
            i--;
        }
	}
    for(int i=0;i<merge.size();i++){
        printf("%d ",merge[i]);
    }
}