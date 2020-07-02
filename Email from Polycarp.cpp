#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        string s, t;
        cin >> s;
        cin >> t;
        int i = 0, j = 0, cnt1, cnt2;
        bool possible = true;
        while(i < s.size()){
            char c = s[i];
            //cout << "searching for  " << c << endl;
            cnt1 = 0;
            while(i < s.size() && s[i] == c) i++, cnt1++;
            cnt2 = 0;
            while(j < t.size() && t[j] == c) j++, cnt2++;
            //cout << cnt1 << " " << cnt2 << endl;
            if(cnt1 > cnt2){
                possible = false;
                break;
            }
        }
        if(possible && j == t.size()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}