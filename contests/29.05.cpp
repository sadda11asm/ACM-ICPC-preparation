#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long long a[100001];
int main () {
	long long t,i,j,l,s,k,x,m,n,r;
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	cin>>n>>k;
	if (n>=k){
		s=n*2/k;
		if ((n*2)%k==0) cout<<s<<endl;
		else cout<<s+1<<endl;
	}
	else cout<<2<<endl;
return 0;
}
