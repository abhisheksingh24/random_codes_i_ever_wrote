#include<iostream>

using namespace std;

int main(){
    long long t, u, v;
    long long res;
    cin >> t;
    for(; t; t--){
        cin >> u >> v;
        res = ((u+v)*(u+v+1))/2 + u + 1;
        cout << res << endl;
    }
}
