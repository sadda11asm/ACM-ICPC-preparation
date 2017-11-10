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
#define s second
 
const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);
 
const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
// /////////////////////////////////////////////////////////////////////
 
 
int T, n, f;
int r[100100];
double w[100100];
int k[100100];
int main(){
    cin >> T;
    for(int s = 1; s <= T; ++s){
        sc("%d%d", &n, &f);
	f++;
	for(int i = 0; i < n; ++i)
            sc("%d", &r[i]);
        double ans = 0;
        sort(r, r + n);
        if(n >= f){
            ans = pi * 1.0 * r[n - f] * r[n - f];
            cout << ans << endl;
        }
        else{
            for(int i = 0; i < n; ++i)
                k[i] = f/ n;
            for(int i = 0; i < f % n; ++i)
                k[i]++;
            int pos1 = 0, pos2 = n - 1;
            for(int i = 0; i < n; ++i){
                w[i] = (1.0 * r[i] * 1.0 * r[i]/ k[i]);
            }
            int  average = n / 2 + 1;
            while (pos1<=pos2) {
        	k[pos1]--;
                k[pos2]++;
		w[pos1]=(1.0 * r[pos1] * 1.0 * r[pos1]/ k[pos1]);
		w[pos2]=(1.0 * r[pos2] * 1.0 * r[pos2]/ k[pos2]);
            	if (w[pos1] >= w[average]) {
                	pos1++;
                }
                if (w[pos2]<w[average] && w[pos2]<(1.0 * r[pos1] * 1.0 * r[pos1]/ (k[pos1]+1))) {
			k[pos1]++;
                	k[pos2]--;
			w[pos1]=(1.0 * r[pos1] * 1.0 * r[pos1]/ k[pos1]);
			w[pos2]=(1.0 * r[pos2] * 1.0 * r[pos2]/ k[pos2]);
			pos2--;
                }
	 	if  (w[pos2]<=w[average]) pos2--;
	     }
            sort(w,w+n);
            cout<<pi*w[0]<<endl;
        }
    }
    return 0;
}