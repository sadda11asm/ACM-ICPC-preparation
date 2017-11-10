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
int a[10001];
int b[10002];
int c[10001];
vector <string> mas;
int main() { 
	double n;
	int k=0;
	int ke = 0;
	int schet =0;
	cin>>n;
	for (int i=1;i<n;i++) {
		cin>>a[i]>>b[i];
		c[a[i]]++;
		c[b[i]]++;
	}
	for (int i=1;i<n+1;i++) {
		if (c[i]==1) {
			if (schet==0) {
				k=i;
				schet = 1;
			}
			else {
				ke=i;
			}
		}	
	}
	if (k!=1 && ke!=1) {
		double f = (n-1)/2;
		cout<<f<<endl;
	} else {
		cout<<n-1<<endl;
	}
}
