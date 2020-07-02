#include<iostream>
#include<string>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    bool found = false;
    for(int i = 0; i < n-1; i++){
        if(s[i] != s[i+1]){
            cout << "YES\n";
            cout << s[i] << s[i+1] << endl;
            found = true;
            break;
        }
    }
    if(!found) cout << "NO\n";
}