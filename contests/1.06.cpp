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
int a[100100];
int c[100100];
int main(){
    cin >> T;
    int p,q;
	for(int s = 1; s <= T; ++s){
	ll x1,x2,y1,y2,u1,u2,v1,v2;
	if (x1==0 || x2==0 || y1==0 ||y2==0||u1==0||u2==0||v1==0||v2==0)  {
		x1++;
		x2++;
		y1++;
		y2++;
		u1++;
		u2++;
	}
	cin>>x1>>y1>>u1>>v1>>x2>>y2>>u2>>v2;
	double a1=sqrt((x1-u1)*(x1-u1)+(y1-v1)*(y1-v1));
	double b=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	double a2=sqrt((x2-u2)*(x2-u2)+(y2-v2)*(y2-v2));
	double c1=sqrt((x2-u1)*(x2-u1)+(y2-v1)*(y2-v1));
	double c2=sqrt((x1-u2)*(x1-u2)+(y1-v2)*(y1-v2));
	int k=0;
	int m1=101;
	int b1=0;
	int m2=101;
	int b2=0;
	a[1]=x1;
	a[2]=x2;
	a[3]=u1;
	a[4]=u2;
	c[1]=y1;
	c[2]=y2;
	c[3]=v1;
	c[4]=v2;
	for (int i=1;i<=4;i++) {
		if (a[i]<m1) 
		m1=a[i];
		if (a[i]>b1) 
		b1=a[i];
	        if (c[i]<m2) 
		m2=c[i];
		if (c[i]>b2) 
		b2=c[i];
	}
	for (int i=m1;i<=b1;i++) {
		for (int j=m2;j<=b2;j++) {
			if (x1==x2) p=1;
			if (y1==y2) p=1;
			if ((x2!=x1 && y1!=y2) && (x1-i)/(x1-x2)==(y1-j)/(y1-y2)) p=1;
			if (u1==u2) q=1;
			if (v1==v2) q=1;
			if (((u1!=u2)&&(v1!=v2)) && ((u1-i)/(u1-u2)==(v1-j)/(v1-v2))) q=1;
			if ((p==1) && (q==1))
	                k=1;
		}
	}
	if ((y1!=v1)&&(y2!=v2)){
		if ((x1-u1)/(y1-v1)==(x2-u2)/(y2-v2) && (k==1)) cout<<0<<endl; 
		else {
			if (acos((a1*a1+b*b-c1*c1)/(2*a1*b))<acos((a2*a2+b*b-c2*c2)/(2*a2*b))) cout<<"Hero"<<endl; 
			if (acos((a1*a1+b*b-c1*c1)/(2*a1*b))>acos((a2*a2+b*b-c2*c2)/(2*a2*b)))	 cout<<"Heroine"<<endl;
		}
	}
	if ((y1==v1) && (y2!=v2)) {
		if (acos((a1*a1+b*b-c1*c1)/(2*a1*b))<acos((a2*a2+b*b-c2*c2)/(2*a2*b))) cout<<"Hero"<<endl; 
		if (acos((a1*a1+b*b-c1*c1)/(2*a1*b))>acos((a2*a2+b*b-c2*c2)/(2*a2*b)))	 cout<<"Heroine"<<endl;
	}
	if ((y1!=v1) && (y2==v2)) {
		if (acos((a1*a1+b*b-c1*c1)/(2*a1*b))<acos((a2*a2+b*b-c2*c2)/(2*a2*b))) cout<<"Hero"<<endl; 
		if (acos((a1*a1+b*b-c1*c1)/(2*a1*b))>acos((a2*a2+b*b-c2*c2)/(2*a2*b)))	 cout<<"Heroine"<<endl;
	}
	if  ((y1==v1) && (y2==v2) && (((m1==x1) && (b1==x2))||((m1==x2) && (b1==x1)) )) { 
		cout<<0<<endl;
	} 
	else {
		if  ((y1==v1) && (y2==v2) && (((m1==u1) && (b1==u2))||((m1==u2) && (b1==u1)))) { 
		cout<<0<<endl;
		} 
		else {
			if  ((y1==v1) && (y2==v2) && (((m1==u1) && (b1==x2))||((m1==x2) && (b1==u1))))
			cout<<"Heroine"<<endl;
			if  ((y1==v1) && (y2==v2) && (((m1==u2) && (b1==x1))||((m1==x1) && (b1==u2))))
			cout<<"Hero"<<endl;
		}

	}
	
}
return 0;
}	
