#include<bits/stdc++.h>

using namespace std;

int main(){
    long long a, b, c;
    cin >> a >> b >> c;
    if(a > b) a = b + 1;
    else if(b > a) b = a + 1;
    cout << a + b + 2*c << endl;
}