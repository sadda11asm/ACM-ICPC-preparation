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
///////////////////////////////////////////////////////////////////// 
 
 

int a[100100],b[100100];
vector<int> x;
vector<int> y;
double w[100100];
int k[100100];
int main(){ 
	int n,m,h1,h2; 
	cin >> n>>m;
	cin>>h1;
   	x.resize(n);
	y.resize(m);
	if (h1>=1){
		for (int j=1;j<=h1;j++) {
			cin>>a[j];
		}
	}
	cin>>h2;
	if (h2>=1){
		for (int j=1;j<=h2;j++){
			cin>>b[j];	
		}
	}
	for (int i=0;i<n;i++)
		x[i]=1;
	if (h1>=1){
		for (int i=1;i<=h1;i++) {
			x[a[i]]=0;
		}
	}
	for (int i=0;i<m;i++) {
		y[i]=1;
	}
	if (h2>=1) {
		for (int i=1;i<=h2;i++){
			y[b[i]]=0;
		}
	}
	int i=0;
	while (i!=1000001) {
		int c=x[i]*y[i];
		x[i]=c;
		y[i]=c;
		x.pb(x[i]);
		y.pb(y[i]);
		i++;
	}
	int happy1=0;
	int happy2=0;
	for (i=x.size()-n;i<x.size();i++) {
		if (x[i]==0) happy1++;	
	}
	for (int j=y.size()-m;j<y.size();j++) {
		if (y[i]==0) happy2++;  
	}
	if (happy1==n && happy2 == m) cout <<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}






		
	





