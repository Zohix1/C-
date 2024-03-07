#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
	int state=0;
    cin >> n;
    vector<long long> a(n), b(n), c(n);
	vector<long long> max1(n,0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
	long long count1=0,count2=0;
    long long total = 0;
    for (int i = 0; i < n; ++i) {
		max1[i]+=a[i];
        for(int j=0;j<n;++j){
			if(i!=j&&b[j]<a[j]+c[j]){
				max1[i]+=b[j];
			}
			else if(i!=j&&b[j]>=(c[j]+a[j])){
				max1[i]+=(c[j]+a[j]);
			}
		}
		if(b[i]>=(c[i]+a[i])){
			count1+=b[i]-(c[i]+a[i]);
		}
		if(a[i]==0&&c[i]!=0){
			count2+=c[i];
		}
		if(a[i]!=0){
			total+=c[i]+a[i];
			max1[i]+=c[i];
		}
    }
	total+=min(count1,count2);
	for(int i=0;i<n;i++){
		cout << max1[i] << " ";
	}
    cout << "\n";
    cout << total << endl;

    return 0;
}
