#include<iostream>
#include<string>
#include<vector>

using namespace std;

int calcSameColor(string s, vector<int>& here){
    int cnt = 0;
    int n = s.length();
    for(int i = 0; i < n; i++)
        if(s[i] == s[(i+1)%n]){
            cnt++;
            here.push_back(i);
        }
    return cnt;
}

bool feasible(string s, int i, int j){
    int n = s.length();
    if(s[i] == s[j]) return false;
    if(s[(i+1)%n] == s[(j+1)%n]) return false;
    return true;
}

int main(){
    int t;
    vector<int> here;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        here.clear();
        int breaks = calcSameColor(s, here);
        if(breaks==0) cout << "yes\n";
        else if(breaks==1){
            bool possible = false;
            for(int i = 0; i < s.length(); i++){
                if(i==here[0]) continue;
                if(feasible(s, i, here[0])){
                    possible = true;
                    break;
                }
            }
            if(possible) cout << "yes\n";
            else cout << "no\n";
        }
        else if(breaks==2){
            if(feasible(s, here[0], here[1])) cout << "yes\n";
            else cout << "no\n";
        }
        else cout << "no\n";
    }
}