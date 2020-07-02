#include<iostream>
#include<string>

using namespace std;

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        string a = "1";
        string z;
        if(n%2) z = string((n-1)/2, '0');
        else z = string(n/2, '0');
        string b = '1' + z;
        cout << a << " " << b << endl;
    }
}
