#include<iostream>

using namespace std;

int main(){
    int t, m, x, y;
    cin >> t;
    while(t--){
        cin >> m;
        x = m/3 + min(1, m%3);
        y = 2*(m/3) + max(0, m%3 - 1);
        cout << x << " " << y << endl;
    }
}
