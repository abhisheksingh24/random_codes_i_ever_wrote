#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

vector<vector<int> > hoppable, dist;
vector<string> words;

bool hopByDelete(int i, int j){
    string w1 = words[i], w2 = words[j];
    int l1 = w1.length(), l2 = w2.length();
    if(l1 != l2+1) return false;
    bool canDelete = true;
    for(int i = 0, j = 0; i < l1 && j < l2; i++, j++){
        if(w1[i]==w2[j]) continue;
        if(!canDelete) return false;
        canDelete = false;
        j--;
    }
    return true;
}

bool hopByReplace(int i, int j){
    char c;
    string w1 = words[i], w2 = words[j];
    int l1 = w1.length(), l2 = w2.length();
    if(l1!=l2) return false;
    bool canReplace = true, toFind = false, found = false;
    for(int i = 0; i < l1; i++){
        if(toFind && c==w2[i]) found = true;
        if(w1[i]==w2[i]) continue;
        if(!canReplace) return false;
        canReplace = false;
        if(i==l1-1) return false;
        if(w1[i]>w2[i]) return false;
        toFind = true;
        c = w2[i];
    }
    return (!toFind || found);
}

bool canHop(int i, int j){
    if(hopByDelete(i, j) || hopByReplace(i, j)) return true;
    return false;
}

vector<int> dfs(int src, int n){
    vector<int> curDist;
    vector<bool> visited;
    for(int i = 0; i < n; i++){
        curDist.push_back(0);
        visited.push_back(false);
    }
    stack<int> toVisit;
    toVisit.push(src);
    visited[src] = true;
    while(!toVisit.empty()){
        int cur = toVisit.top();
        toVisit.pop();
        for(int j = 0; j < hoppable[cur].size(); j++){
            int nxt = hoppable[cur][j];
            if(curDist[nxt] < curDist[cur]+1){
                toVisit.push(nxt);
                curDist[nxt] = curDist[cur]+1;
            }
        }
    }
    return curDist;
}

void test(int n){
    for(int i = 0; i < n ; i++){
        cout << words[i] <<" : ";
        for(int j = 0; j < hoppable[i].size(); j++){
            int nxt = hoppable[i][j];
            cout << words[nxt] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string word;
        cin >> word;
        words.push_back(word);
    }
    hoppable.resize(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i==j) continue;
            if(canHop(i, j)) hoppable[i].push_back(j);
        }
    }
    //test(n);
    dist.resize(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) dist[i].push_back(0);
    }
    int maxLen = 0;
    for(int i = 0; i < n; i++){
        dist[i] = dfs(i, n);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dist[i][j] > maxLen) maxLen = dist[i][j];
        }
    }
    cout << maxLen+1 << endl;
}
