#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    vector<int> d(n), pre(n), post(n);
    int maxRes = 0, ii = 1, jj = 1;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(s[i] == s[j]) 
                continue;
            int res = 0;
            swap(s[i], s[j]);
            if(s[0] == '(') d[0] = 1;
            else d[0] = -1;
            for(int i = 1; i < n; i++){
                d[i] = d[i - 1];
                if(s[i] == '(') d[i]++;
                else d[i]--;
            }
            if(d[n - 1] != 0){
                swap(s[i], s[j]);
                continue;
            }
            pre[0] = d[0];
            for(int i = 1; i < n; i++) pre[i] = min(pre[i - 1], d[i]);
            
            post[n - 1] = d[n - 1];
            for(int i = n - 2; i >= 0; i--) post[i] = min(post[i + 1], d[i]);

            for(int i = 0; i < n; i++) if(pre[i] - d[i] >= 0 && post[i] - d[i] >= 0) res++;

            if(res > maxRes){
                maxRes = res;
                ii = i + 1;
                jj = j + 1;
            }
            swap(s[i], s[j]);
        }
    }
    int res = 0;
    if(s[0] == '(') d[0] = 1;
    else d[0] = -1;
    for(int i = 1; i < n; i++){
        d[i] = d[i - 1];
        if(s[i] == '(') d[i]++;
        else d[i]--;
    }
    pre[0] = d[0];
    for(int i = 1; i < n; i++) pre[i] = min(pre[i - 1], d[i]);
    
    post[n - 1] = d[n - 1];
    for(int i = n - 2; i >= 0; i--) post[i] = min(post[i + 1], d[i]);
    
    if(d[n - 1] == 0) for(int i = 0; i < n; i++) if(pre[i] - d[i] >= 0 && post[i] - d[i] >= 0) res++;

    if(res > maxRes){
        maxRes = res;
        ii = 1;
        jj = 1;
    }

    cout << maxRes << endl;
    cout << ii << " " << jj << endl;
}