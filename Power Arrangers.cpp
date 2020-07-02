#include<bits/stdc++.h>

using namespace std;

void ask(int n, int k, vector<int>& cnt, vector<char>& hero){
    cout << n * 5 + k + 1<< endl;
    cout.flush();
    char h;
    cin >> h;
    hero[n] = h;
    cnt[h - 'A']++;
}

int main(){
    string alpha = "ABCDE";
    int t, f;
    cin >> t >> f;
    for(int tt = 1; tt <= t; ++tt){
        string res;
        set<int> toCheck;
        for(int i = 0; i < 119; i++) toCheck.insert(i);
        //cout << "Checking: "; for(int i: toCheck) cout << i << " "; cout << endl;
        vector<bool> found;
        for(int i = 0; i < 5; i++) found.push_back(false);
        for(int i  = 0; i < 5; i++){
            int optcnt = 1;
            for(int z = 2; z < 5 - i; z++) optcnt *= z;
            vector<int> cnt(5, 0);
            vector<char> hero(120, 'F');
            for(int j: toCheck){
                ask(j, i, cnt, hero);
            }
            char cur;
            for(int z = 0; z < 5; z++){
                if(found[z]) continue;
                if(cnt[z] < optcnt){
                    cur = alpha[z];
                    found[z] = true;
                    break;
                }
            }
            res.push_back(cur);
            for(auto it = toCheck.begin(); it != toCheck.end(); ){
                if(hero[*it] != cur) it = toCheck.erase(it);
                else ++it;
            }
        }
        cout << res << endl;
        cout.flush();
        char c;
        cin >> c;
        if(c == 'Y') continue;
        else if(c == 'N') return 1;
    }
    return 0;
}