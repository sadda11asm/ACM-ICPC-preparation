#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define pb push_back
using namespace std;
int a[32];
int main () {
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) {	
		cin>>a[i];
	}	
	int s=0;
	for (int i=1;i<=n;i++) {
		if (a[i]%2!=0) {
			cout<<a[i]<<" ";
	                s=s+1;  			
		}
	}
	int m=0;
	cout<<" "<<endl;
	for (int i=1;i<=n;i++) {
		if (a[i]%2==0) {
			m=m+1;
			cout<<a[i]<<" ";
		}
	}
	cout<<" "<<endl;
	if (m>=s) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
return 0;
}	

