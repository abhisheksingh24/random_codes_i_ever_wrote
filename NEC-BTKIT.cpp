#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isStark(long long n){
  	int d = 0;
  	for(int temp = n; temp>0; temp/=10) d++;
	long long sq = n*n;
  	long long l, r;
  	r = sq%int((pow(10.0, d)));
  	l = sq/int((pow(10.0, d)));
  	return l+r == n;
}

int main() {
	int p, q;
  	cin >> p >> q;
  	bool found = false;
  	for(int i = p; i <= q; i++){
    	if(isStark(i)){
        	cout << i << " ";
          	found = true;
        }
    }
  	if(!found) cout << "INVALID RANGE";
  	cout << endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
