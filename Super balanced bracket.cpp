#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        vector<int> opn(s.size()), cls(s.size());
        opn[0] = (s[0] == '(');
        for(int i = 1; i < s.size(); i++){
            opn[i] = opn[i - 1] + (s[i] == '(');
        }
        cls[s.size() - 1] = (s.back() == ')');
        for(int i = s.size() - 1; i >= 0; i--){
            cls[i] = cls[i + 1] + (s[i] == ')');
        }
        int res = 0;
        for(int i = 0; i < s.size() - 1; i++) res = max(res, 2 * min(opn[i], cls[i + 1]));
        cout << res << endl;
    }
}