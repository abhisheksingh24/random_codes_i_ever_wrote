#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    int t;
    double u, v, x;
    cin >> t;
    while(t--){
        cin >> u >> v >> x;
        cout << setprecision(10) << x / (u+v) << endl;
    }
}
