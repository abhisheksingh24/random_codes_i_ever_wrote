#include<iostream>
#include<string>
#include<algorithm>
#include<set>

using namespace std;

vector<pair<int, int> > bestPos;
vector<set<int> > pos;
vector<int> lastPos;

void init(){
    pos.clear();
    bestPos.clear();
    lastPos.clear();
    pos.resize(26);
    lastPos.resize(26);
}

int main(){
    string s, alpha = "abcdefghijklmnopqrstuvwxyz";
    while(!cin.eof()){
        cin >> s;
        init();
        int l = s.length();
        for(int i = 0; i < l; i++){
            pos[s[i] - 'a'].insert(i);
            lastPos[s[i] - 'a'] = i;
        }
        for(int i = 0; i < 26; i++){
            if(!pos[i].empty()) bestPos.emplace_back(*pos[i].begin(), i);
        }
        bool done = false;
        while(!done){
            done = true;
            sort(bestPos.begin(), bestPos.end());
            for(int i = 0; i+1 < bestPos.size(); i++){
                if(bestPos[i].second > bestPos[i+1].second && lastPos[bestPos[i].second] > bestPos[i+1].first){
                    bestPos[i].first = *pos[bestPos[i].second].upper_bound(bestPos[i+1].first);
                    done = false;
                    break;
                }
            }
        }
        for(auto p: bestPos) cout << alpha[p.second];
        cout << endl;    
    }
}