
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>
   
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
// /////////////////////////////////////////////////////////////////////
 
 
int n, k, m, b, r, q, v0, v1, l, i, j;
int a[200001];
int d[200001];
int t[200001];
int main() {
	cin>>n;
	for (i=1;i<=n;i++) {
		cin>>a[i];
	}
	int s;
	if (a[1]<a[2]) {
	         s=0;
	}
	if (a[1]==a[2]) {
		s=1;
	}
	if (a[1]>a[2]) {
		s=2;
	}
	m=0;
	if (n==1 || n==2) cout<<"YES"<<endl;
	else {	for (i=2;i<=n-1;i++) {
		if (a[i+1]<a[i] && s==0) {
			s=2;
		}	      
		if (a[i+1]==a[i] && s==0) {
			s=1;
		} 
		
		if (a[i+1]>a[i] && s==1) {
			break;
			m=1;
			cout<<"NO"<<endl;
		}
		if (a[i+1]<a[i] && s==1) {
			s=2;
		}
		if (a[i+1]>=a[i] && s==2) {
			break;
			m=1;
			cout<<"NO"<< endl;
		}
	}
	if (m==0 && s >= 0) cout<<"YES"<<endl;
	}
return 0;
}
				
				






							

						  


