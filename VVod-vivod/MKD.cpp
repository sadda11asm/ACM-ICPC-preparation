#include <iostream>
#include <cmath>
using namespace std;
int main() {
int v, t;
int otmetka;
cin >> v; 
cin >> t;
int s= v * t;
	if (v > 0){
otmetka= s % 109;
	} else if (v < 0) { if ( (-s) % 109 == 0) {
					otmetka=0;} else otmetka = 109-( (-s) % 109);
			} else otmetka=0;
cout << otmetka << endl;
return 0;
}