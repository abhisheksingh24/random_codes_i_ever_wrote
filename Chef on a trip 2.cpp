#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

map<string, string> nxt,prv;

string findFirst(){
    for(auto& kv:nxt){
        if(prv.find(kv.first)==prv.end()) return kv.first;
    }
}

int main(){
    int t, n;
    string src, tgt, cur;
    cin >> t;
    while(t--){
        nxt.clear();
        prv.clear();
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> src >> tgt;
            nxt[src] = tgt;
            prv[tgt] = src;
        }
        cur = findFirst();
        while(true){
            if(nxt.find(cur)==nxt.end()) break;
            cout << cur << "-" << nxt[cur] << " ";
            cur = nxt[cur];
        }
        cout << endl;
    }
}
