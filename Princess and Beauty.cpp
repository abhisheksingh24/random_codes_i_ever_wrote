#include<iostream>
#include<string>

using namespace std;

string result(string s){
    int l = s.length();
    for(int i = 0; i < l; i++){
        if(i < l-1 && s[i]==s[i+1]) return "YES";
        if(i < l-2 && s[i]==s[i+2]) return "YES";
    }
    return "NO";
}

int main(){
    int t;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        cout << result(s) << endl;
    }
}
