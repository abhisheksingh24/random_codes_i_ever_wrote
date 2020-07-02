#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<map>

using namespace std;

vector<set<int> > toCheck; 
vector<int> len;
vector<pair<int, int> > queries;
vector<string> str;
map<pair<int, int>, bool> dp;
map<int, int> ind;

int main(){
    int n, q, x, y;
    cin >> n >> q;
    str.resize(n);
    toCheck.resize(n);
    for(auto& s: str) cin >> s;
    for(string s: str) len.push_back(s.length());
    for(int i = 0; i < q; i++){
        cin >> x >> y;
        queries.emplace_back(x-1, y-1);
        toCheck[x-1].insert(y-1);
        toCheck[y-1].insert(x-1);
    }
    for(int i = 0; i < n; i++){
        ind.clear();
        for(int j: toCheck[i]) ind[j] = 0;
        for(int id = 0; id < len[i]; id++){
            vector<int> toRemove;
            char c = str[i][id];
            for(int j: toCheck[i]){
                while(ind[j] < len[j] && str[j][ind[j]] != c) ++ind[j];
                if(ind[j] == len[j]) toRemove.push_back(j);
                else ++ind[j];
            }
            for(int rem: toRemove){
                toCheck[i].erase(rem);
                dp[make_pair(i, rem)] = false;
            }
        }
        for(int left: toCheck[i]){
            dp[make_pair(i, left)] = true;
        }
    }
    for(auto q1: queries){
        auto q2 = make_pair(q1.second, q1.first);
        if(dp[q1] || dp[q2]) cout << "Yes\n";
        else cout << "No\n";
    }
}
