#include<iostream>

using namespace std;

int main(){
    long long t, n, b, y, res;
    cin >>t;
    while(t--){
        cin >> n >> b;
        y = int(n*0.5/b + 0.5);
        res = (n - b*y)*y;
        cout << res << endl;
    }
}
