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
	string s;
	cin>>a>>b>>l>>r;
	s.resize(0);
	for (i=1;i<=a;i++) {
		s=s+char(i+96);
	}
	for (i=1;i<=11;i++) {
		for (j=1;j<=b;j++) {
			s=s+char(s[s.size()]+96);
		}
		for (j=1;j<=a;j++) {
			s=
		}
	}
	cout<<s<<endl;		
	return 0;
}
	