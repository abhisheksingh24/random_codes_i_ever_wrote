#include<iostream>

using namespace std;

int main(){
    int t, n;
    cin >> t;
    for(; t; t--){
        cin >> n;
        for(int i = 500; i > (500-n); i--)
            cout<<i<<" ";
        cout<<endl;
    }
}

