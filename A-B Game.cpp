#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    int t;
    string s;
    cin >> t;
    while(t--){
        vector<int> sizes;
        int aa = 0, bb = 0, ab1 = 0, ab2 = 0;
        cin >> s;
        int n = s.length();
        char c = '.';
        int l = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == '.') continue;
            if(l == -1){
                c = s[i];
                l = i;
            }
            else{
                if(c=='A' && s[i]=='A') aa += (i-l-1);
                else if(c=='B' && s[i]=='B') bb += (i-l-1);
                else{
                    if(i-l-1 == 1) ab1++;
                    else if(i-l-1 > 1){
                        ab2++;
                        sizes.push_back(i-l-1);
                    }
                }
                c = '.';
                l = -1;
            }
        }
        sort(sizes.begin(), sizes.end());
        int pairs = 0;
        for(int i = 0; i < sizes.size() - 1; i++){
            if(sizes[i] == sizes[i+1]) pairs++;
        }
        if(l != -1){
            if(c=='A') aa += (n-1-l);
            else bb += (n-1-l);
        }
        int scoreForA = aa - bb;
        if(ab2 > 0){
            if(ab2==2 && pairs>0) scoreForA++;
            
            if(ab2 % 2 ) scoreForA++;
        }
        else{
            if(ab1 % 2) scoreForA++;
        }
        if(scoreForA > 0) cout << "A\n";
        else cout << "B\n"; 
    }
}