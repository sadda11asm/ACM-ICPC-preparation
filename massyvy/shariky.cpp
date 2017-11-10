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
	j=-1;
	i=0;
	while (i<n) {
		cin >> k;
		v.pb(k);
		if ((i>1)and (v[i] == v[i-1]) and (v[i-1] == v[i-2])) {
			j=v[i];
			v.pop_back();
			v.pop_back();
			v.pop_back();
			i=i-3;
			n=n-3;
		}
		else { 
			if((i>=0)and(v[i]==j)) {
				j=v[i];
				v.pop_back();
				i=i-1;
				n=n-1;
			}
			else {
				if((i>=0) and (v[i]!=j) and (j!=-1)) {
					j=-1;
				}
			}
		}	
		i++;
	}
	cout << t-v.size() << endl;	
return 0;
}