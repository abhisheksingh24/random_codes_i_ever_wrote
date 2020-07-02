#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, m;
    char ch;
    vector<int> switchCount;
    vector<vector<int>> lamps;
    cin >> n >> m;
    switchCount.resize(m);
    lamps.resize(n);
    for(int i = 0; i < m; i++) switchCount[i] = 0;
    for(int i = 0; i , i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> ch;
            if(ch == '1'){
                switchCount[j]++;
                lamps[i].push_back(j);
            }
        }
    }
    //for(int s : switchCount) cout << s << " ";
    //cout << endl;

    bool possible;
    for(int i = 0; i < n; i++){
        possible = true;
        for(int l : lamps[i]){
            if(switchCount[l]==1){
                possible = false;
                break;
            }
        }
        if(possible) break;
    }
    if(possible) cout << "YES\n";
    else cout << "NO\n";
}
