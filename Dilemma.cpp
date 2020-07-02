#include<bits/stdc++.h>

using namespace std;

void flip(string& state, int i){
    if(state[i] == '1') state[i] = '0';
    else state[i] = '1';
}

bool possible(string& state, int l){
    if(l == state.size() - 1) return state[l] == '1';
    if(state[l] == '1'){
        flip(state, l + 1);
        return possible(state, l + 1);
    }
    return possible(state, l + 1);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string state;
        cin >> state;
        if(possible(state, 0)) cout << "WIN" << endl;
        else cout << "LOSE" << endl;
    }
}