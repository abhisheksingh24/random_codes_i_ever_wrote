#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;
    cout << n - ((int) sqrt(9 + 8 * (k + n)) - 3) / 2 << endl;
}