#include<iostream>
#include<string>

using namespace std;

string solve(string s){
    int l = s.length();
    int i = 0;
    while(i < l && s[i]!='1') i++;
    int cnt = 0;
    for(; i < l; i++){
        if(s[i]=='0'){
            cnt++;
        }
    }
    if(cnt>=6) return "yes";
    return "no";
}

int main(){
    string s;
    cin >> s;
    cout << solve(s) << endl;
}
