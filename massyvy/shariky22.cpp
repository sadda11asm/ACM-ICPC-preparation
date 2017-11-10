#include <iostream>
#include <vector>
#include <cmath>
#define pb push_back
using namespace std;
int main () {
	int i,n,j,k,t;
	cin >> n;
	t=n;
	vector<int> v;
	for (i=0;i<n;i++) {
		cin >> k;
		v.pb(k);
		if ((v[i] == v[i-1]) and (v[i-1] == v[i-2]) and (v[i-2] == v[i-3])) {
			v.pop_back();
			v.pop_back();
			v.pop_back();
			v.pop_back();
			i=i-4;
			n=n-4;
		}
	}
	cout << t-v.size() << endl;	
return 0;
}