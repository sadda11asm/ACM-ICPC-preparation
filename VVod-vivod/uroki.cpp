#include <iostream>
#include <cmath>
using namespace std;
int main () {
int n,sn,k;
cin >> k;
if (k<=1) cout << "9" <<" "<< "45"<<endl; else	
	{sn=585; 
		for (n=2; n<=k; n++) {
			int m=(n%2);
			if (m==0) sn= sn+50;
			else sn=sn+60;
		}
	int a=sn/60;
	int b=sn%60;
	cout << a <<" "<< b<< endl;
	}                
	return 0;
}