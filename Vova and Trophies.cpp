#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    int gold = 0, maxLen = 0, frst = 100000, lst = -1, curLen, silver = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'G'){
            if(frst==100000) frst = i;
            lst = i;
        }
        else silver++;
    }
    for(int i = 0; i < n; i++){
        if(s[i] == 'G') gold++;
        else{
            int right = 0;
            for(int j = i+1; j < n && s[j]=='G'; right++, j++);
            curLen = gold + right;
            if(i+right < lst || i-gold > frst) ++curLen;
            maxLen = max(maxLen, curLen);
            gold = right;
            i+=right;
        }
    }
    if(silver == 0) maxLen = n;
    cout << maxLen << endl;
}