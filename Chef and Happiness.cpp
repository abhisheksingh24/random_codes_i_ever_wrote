#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<int> cnt;
vector<vector<int> > pos;
set<int> s;

void init(int n){
    cnt.clear();
    pos.clear();
    s.clear();
    cnt.resize(n+1);
    pos.resize(n+1);
    for(int &i: cnt) i = 0;
}

int main(){
    int t, n, temp;
    cin >> t;
    while(t--){
        cin >> n;
        init(n);
        for(int i = 1; i <= n; i++){
            cin >> temp;
            cnt[temp]++;
            pos[temp].push_back(i);
            s.insert(temp);
        }
        bool found = false;
        for(int i: s){
            if(cnt[i] > 1){
                int need = 2;
                for(int p: pos[i]){
                    if(cnt[p] > 0) need--;
                    if(need <= 0){
                        found = true;
                        break;
                    }
                }
                if(found) break;
            }
        }
        if(found) cout << "Truly Happy" << endl;
        else cout << "Poor Chef" << endl;
    }
}