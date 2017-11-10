#include <bits/stdc++.h>
   
using namespace std;

#define sz(a) (int)a.size()
#define vi vector <int>
#define pb push_back
#define mp make_pair
#define ll long long        
#define sc scanf
#define pf printf    
#define f first
 
const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);
 
const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
// //////////////////////////////////////////////////////////////////// 
long long a[100001];
long long b[100001]; 

vector <string> mas;

int main() {
	int n;
	cin>>n;
	if (n%2==0) {
		cout<<3*n/2<<endl;
		for (int i=1;i<=n;i++) {
			if (i%2==1) {
				cout<<i<<" ";
			}
		}
		for (int i=1;i<=n;i++) {
			if (i%2==0) {
				cout<<i<<" ";
			}
		}
		for (int i=1;i<=n;i++) {
			if (i%2==1) {
				cout<<i<<" ";
			}
		}  		
	}
	if (n%2==1) {
		cout<<n/2+n/2+n/2+1<<endl;
		for (int i=1;i<=n;i++) {
			if (i%2==0) {
				cout<<i<<" ";
			}
		}
		for (int i=1;i<=n;i++) {
			if (i%2==1) {
				cout<<i<<" ";
			}
		}
		for (int i=1;i<=n;i++) {
			if (i%2==0) {
				cout<<i<<" ";
			}
		}  		
	}
	return 0;
}