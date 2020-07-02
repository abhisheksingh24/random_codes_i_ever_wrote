#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    cin >> s;
    bool vowelNeeded = false;
    for(char c: s){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            vowelNeeded = false;
        }
        else if(c=='n'){
            if(vowelNeeded) break;
        }
        else{
            if(vowelNeeded) break;
            else vowelNeeded = true;
        }
    }
    if(vowelNeeded) cout << "NO\n";
    else cout << "YES\n";
}
