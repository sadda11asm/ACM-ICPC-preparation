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
 
 
int t, n, k, m,b, r, q, a, c, v0, v1, l, i, j;
int d[1001];
int main() {
	long long max =0;
	cin>>c>>v0>>v1>>a>>l;
	m=v0;
	k=0;
	i=1;
	while (c>0) {
		if (i>=2) c=c-(m-l);
		else c=c-m;
		i++;
		k=k+1;
		if ((m+a)>v1) m=v1;
		else m=m+a;
	}
	cout<<k<<endl;
	return 0;
}
	





