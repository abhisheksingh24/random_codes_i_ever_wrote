#include<iostream>

using namespace std;

int main(){
    int t, n, x, s, a, b;
    cin >> t;
    while(t--){
        cin >> n >> x >> s;
        while(s--){
            cin >> a >> b;
            if(x==a) x = b;
            else if(x==b) x = a;
        }
        cout << x << endl;
    }
}