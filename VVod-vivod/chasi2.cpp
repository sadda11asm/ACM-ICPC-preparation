#include <iostream>
#include <cmath>
using namespace std;
int main() {
int n;
cin >> n; 
int m=(n/3600)%24;
int k=(n%3600)/60;
int t=(n%3600)%60;
	if ((k < 10) and (t<10))  { cout <<m<<":"<<"0"<<k<<":"<<"0"<<t<< endl;
	} else 
	if ((k < 10) and (t>=10))  { cout <<m<<":"<<"0"<<k<<":"<<t<< endl;
	} else
	if ((k >= 10) and (t<10))  { cout <<m<<":"<<k<<":"<<"0"<<t<< endl;
	} else
	if ((k >= 10) and (t>=10))  { cout <<m<<":"<<k<<":"<<t<< endl;
	} 
return 0;
}
