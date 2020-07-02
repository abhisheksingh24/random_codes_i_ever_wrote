#include<iostream>

using namespace std;

long long power(long long b, int e){
	if(e==0) return 1;
	if(e%2) return b*power(b*b, e/2);
	return power(b*b, e/2);
}

const long long INF = power(10, 18) + 1;

bool solve(long long n, long long k, int t){
	if(n==0) return t%2 == 0;
	int d = 18 - (t+1)/2;
	long long p;
	if(k > power(10, d)) p = INF;
	else p = power(k, (t+1)/2);
	if(p > n) return t%2 == 0;
	return solve(n - p, k, t+1);
}

int main(){
	//cout << INF << endl;
	int t;
	long long n, k;
	cin >> t;
	while(t--){
		cin >> n >> k;
		if(k == 1) n = n%2;
		if(solve(n, k, 1)) cout << "Alice\n";
		else cout << "Bob\n";
	}
}
