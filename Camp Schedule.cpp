#include<bits/stdc++.h>

using namespace std;

int longestPrefixSuffix(string s) 
{ 
    int n = s.length(); 
  
    int lps[n]; 
    lps[0] = lps[1] = 0; // lps[0] is always 0 
  
    // length of the previous 
    // longest prefix suffix 
    int len = 0; 
  
    // the loop calculates lps[i] 
    // for i = 1 to n-1 
    int i = 2; 
    while (i < n) 
    { 
        if (s[i] == s[len]) 
        { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider 
            // the example. AAACAAAA 
            // and i = 7. The idea is 
            // similar to search step. 
            if (len != 0) 
            { 
                len = lps[len-1]; 
  
                // Also, note that we do 
                // not increment i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
  
    int res = lps[n-1]; 
  
    // Since we are looking for 
    // non overlapping parts. 
    return res; 
} 
  
int main(){
    string s, t;
    cin >> s >> t;
    int l = longestPrefixSuffix(t);
    int cnt0 = 0, cnt1 = 0;
    for(char c: s) c == '0' ? cnt0++ : cnt1++;
    for(int i = 0; i < t.size(); i++){
        if(t[i] == '1'){
            if(cnt1 <= 0) break;
            cout << t[i];
            cnt1--;
        }
        else{
            if(cnt0 <= 0) break;
            cout << t[i];
            cnt0--;
        }
    }
    bool allGood = true;
    while(allGood){
        for(int i = l; i < t.size(); i++){
            if(t[i] == '1'){
                if(cnt1 <= 0){
                    allGood = false;
                    break;
                }
                cout << t[i];
                cnt1--;
            }
            else{
                if(cnt0 <= 0){
                    allGood = false;
                     break;
                }
                cout << t[i];
                cnt0--;
            }   
        }
    }
    allGood = true;
    while(allGood){

    }
    while(cnt1--) cout << 1;
    while(cnt0--) cout << 0;
    cout << endl; 
}