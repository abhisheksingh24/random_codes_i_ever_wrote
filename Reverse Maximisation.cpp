#include<bits/stdc++.h>

using namespace std;

void reverse(string& n){
    int beg = 0;
    while(beg < n.size() && n[beg] == '0') beg++;
    int l = n.size() - 1;
    bool trailing = true;
    for(int i = 1; i < n.size(); i++) if(n[i] != '0') trailing = false;
    while(l >= beg && n[l] == '9') l--;
    //cout << l << endl;
    for(int i = beg; i < l; i++){
        if(i == beg && n[i] == '1' && !trailing) continue;
        if(n[i] == '0') continue;
        n[i] = (char)((int)(n[i] - '0') - 1 + (int)'0');
        for(int j = i + 1; j <= l; j++) n[j] = '9';
        break;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string n;
        cin >> n;
        reverse(n);
        int beg = 0;
        while(beg < n.size() && n[beg] == '0') beg++;
        for(int i = beg; i < n.size(); i++) cout << n[i];
        cout << endl;
    }
}