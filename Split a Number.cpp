#include<bits/stdc++.h>

using namespace std;

void reverse(string& s){
    for(int l = 0, r = s.size() - 1; l < r; l++, r--){
        swap(s[l], s[r]);
    }
}

string sum(string a, string b){
    string res;
    reverse(a);
    reverse(b);
    int carry = 0;
    int i;
    for(i = 0; i < a.size() && i < b.size(); i++){
        int d = (a[i] - '0') + (b[i] - '0') + carry;
        carry = d / 10;
        d %= 10;
        res.push_back('0' + d);
    }
    for(; i < a.size(); i++){
        int d = (a[i] - '0') + carry;
        carry = d / 10;
        d %= 10;
        res.push_back('0' + d);
    }
    for(; i < a.size(); i++){
        int d = (b[i] - '0') + carry;
        carry = d / 10;
        d %= 10;
        res.push_back('0' + d);
    }
    reverse(res);
    return res;
}

int main(){
    //cout << sum("1234", "567") << endl;
    int ll;
    string n;
    cin >> ll;
    cin >> n;
    int l = ll / 2, r = (ll + 1) / 2;
    while(n[l] == '0' && n[r] == '0') l--, r++;
    //cout << "l = " << l << " r = " << r << endl;;
    string res1, res2, INF;
    for(char c: n) INF.push_back('9');
    if(n[l] != '0'){
        string a, b;
        for(int i = 0; i < l; i++) a.push_back(n[i]); 
        for(int i = l; i < ll; i++) b.push_back(n[i]);
        res1 = sum(a, b); 
    }
    else res1 = INF;
    if(n[r] != '0'){
        string a, b;
        for(int i = 0; i < r; i++) a.push_back(n[i]); 
        for(int i = r; i < ll; i++) b.push_back(n[i]);
        res2 = sum(a, b); 
    }
    else res2 = INF;
    cout << min(res1, res2) << endl;
}