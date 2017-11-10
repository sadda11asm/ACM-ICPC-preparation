#include <functional>
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
 
 
int T, n, k, m, r, q;
int b[1001];
int c[1001];
int d[1001];
int main(){
	string s;
	cin>>n;
	cin>>s;
	cout<<' '<<endl;
	cin>>q;
	int i,j;
	char a;
	for (k=1;k<=q;k++) {
		cin>>m;
		cin>>a;
		c[-1]=-1;
		r=0;
		int l=m;
		for (i=0;i<n;i++) {
			if (s[i]==a) {
				c[r]=i;
				r=r+1;
			}
		}
		for (i=0;i<r-1;i++) {
			b[i]=c[i+1]-c[i]-1;
		}
		c[r]=n;
		b[r-1]=c[r]-c[r-1]-1;			
		for (j=1;j<=r;j++) {
			sort(b,b+r-1);
			if (l<b[1]) {
				cout<<m+1<<endl;
				break;
			}
			else {
				for (i=0;i<n;i++) {
					b[i]=b[i]+c[i+j];
				}
				m++;
			}
		}
	}
return 0;
}
			 




