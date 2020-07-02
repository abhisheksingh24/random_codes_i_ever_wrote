#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    if(n % 2 || s[0] == ')' || s[n-1] == '('){
        cout << ":(\n";
        return 0;
    }
    int open = 0, closed = 0, toClose = 0, desired = (n-2) / 2;
    for(int i = 1; i < n-1; ++i){
        if(s[i] == '(') open++;
        else if(s[i] == ')') closed++;
    }
    if(open > desired || closed > desired){
        cout << ":(\n";
        return 0;
    }
    for(int i = 1; i < n-1; ++i){
        if(s[i] == '('){
            toClose++;
        }
        else if(s[i] == ')'){
            --toClose;
            if(toClose < 0){
                cout << ":(\n";
                return 0;
            }
        }
        else if(s[i] == '?'){
            if(open == desired && toClose == 0){
                cout << ":(\n";
                return 0;
            }
            else if(open == desired){
                --toClose;
                s[i] = ')';
            }
            else{
                ++open;
                ++toClose;
                s[i] = '(';
            }
        }
    }
    s[0] = '(';
    s[n-1] = ')';
    cout << s << endl;
}