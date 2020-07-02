#include<iostream>
#include<map>

using namespace std;

#define ll long long

map<ll,ll> found;

ll dollar(ll n){
    try{
        return(found.at(n));
    }
    catch(...){
        ll m = dollar(n/2) + dollar(n/3) + dollar(n/4);
        found[n] = n>m? n:m;
        return(found[n]);
    }
}

int main(){
    ll n;
    found[0] = 0;
    while(cin >> n){
        cout << dollar(n) << endl;
    }
}
