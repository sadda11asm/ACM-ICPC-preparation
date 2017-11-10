#include <iostream>
#include <cmath>
using namespace std;
int stepen (int a, int b) {
	int c=1;
	while (b!=0) {
		c=c*a;
		b--;
	}
	return c;
}
int main() {
int i,T,x1,x2,x3,N,d,m,upper;
cin >>T;
for (i=1;i<=T;i++) {
	cin >> upper >> d>>m>>N;
	if (upper > N){
	for (x1=0;x1<=N;x1++) {
		for (x2=0;x2<=N;x2++) {
			for (x3=0;x3<=N;x3++) {	
				if ((stepen(x1,d)+stepen(x2,d)+stepen(x3,d))%N == m) 
				{cout<<x1<<x2<<x3<<endl;}
			}
		}
	} 
	}
	else{
	for (x1=0;x1<=upper;x1++) {
		for (x2=0;x2<=upper;x2++) {
			for (x3=0;x3<=upper;x3++) {	
				if ((stepen(x1,d)+stepen(x2,d)+stepen(x3,d))%N == m) 
				{cout<<x1<<x2<<x3<<endl;}
			}
		}
	}
	}
	 
}
return 0;
}