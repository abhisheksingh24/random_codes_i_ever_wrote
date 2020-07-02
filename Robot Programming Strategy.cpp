#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if (b == 0) return a; 
    return gcd(b, a % b);
}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

bool isWinning(string a, string b){
    int l = lcm(a.size(), b.size());
    for(int i = 0; i < l; ++i){
        char ca = a[i % a.size()];
        char cb = b[i % b.size()];
        if(ca == cb) continue;
        if(ca == 'R'){
            if(cb == 'P') return true;
        }
        if(ca == 'P'){
            if(cb == 'S') return true;
        }
        if(ca == 'S'){
            if(cb == 'R') return true;
        }
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        int a;
        vector<string> prog;
        string winStrat;
        vector<int> len;
        vector<bool> rem;
        cin >> a;
        prog.resize(a);
        for(string& s: prog) cin >> s;
        for(string s: prog) len.push_back(s.size());
        for(int i = 0; i < a; ++i) rem.push_back(true);
        bool winning = true;
        for(int i = 0; i < 500; i++){
            set<char> cur;
            for(int j = 0; j < a; j++) if(rem[j]) cur.insert(prog[j][i % len[j]]);
            if(cur.size() >= 3){
                winning = false;
                break;
            }
            if(cur.empty()) break;
            set<char> counter;
            counter.insert('R');
            counter.insert('P');
            counter.insert('S');
            for(char c: cur){
                if(c == 'R'){
                    auto it = counter.find('S');
                    if(it != counter.end()) counter.erase(it);
                }
                else if(c == 'S'){
                    auto it = counter.find('P');
                    if(it != counter.end()) counter.erase(it);
                }
                if(c == 'P'){
                    auto it = counter.find('R');
                    if(it != counter.end()) counter.erase(it);
                }
            }
            if(counter.empty()){
                winning = false;
                break;
            }
            char c = *counter.begin();
            if(cur.size() == 1){
                char cc = *cur.begin();
                if(cc == 'R'){
                    c = 'P';
                }
                else if(cc == 'P'){
                    c = 'S';
                }
                if(cc == 'S'){
                    c = 'R';
                }
            }
            for(int j = 0; j < a; ++j){
                if(prog[j][i % len[j]] != c) rem[j] = false; 
            }
            winStrat.push_back(c);
        }
        vector<int> remain;
        for(int i = 0; i < a; ++i) if(rem[i]) remain.push_back(i);
        for(int i: remain){
            if(!isWinning(winStrat, prog[i])){
                winning = false;
                break;
            }
        }
        if(!winning){
            cout << "Case #" << tt << ": " << "IMPOSSIBLE\n";
        }
        else{ 
            cout << "Case #" << tt << ": " << winStrat << endl;
        }
    }
}