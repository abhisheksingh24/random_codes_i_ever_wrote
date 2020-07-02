#include<iostream>

using namespace std;

int main(){
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    if(c > a || c > b || a + b - c >= n) cout << -1;
    else cout << (n-a-b+c);
    cout << endl;
}
