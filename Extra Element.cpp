#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> b(n);
    for(int& i: b) cin >> i;
    if(n == 2){
        cout << 1 << endl;
        return 0;
    }
    map<int, int> id, cnt;
    for(int i = 0; i < n; i++) id[b[i]] = i + 1;
    sort(b.begin(), b.end());
    bool ap = true;
    int d = b[2] - b[1];
    for(int i = 3; i < n; i++){
        if(b[i] - b[i - 1] != d){
            ap = false;
            break;
        }
    }
    if(ap){
        cout << id[b[0]] << endl;
        return 0;
    }
    ap = true;
    d = b[2] - b[0];
    for(int i = 3; i < n; i++){
        if(b[i] - b[i - 1] != d){
            ap = false;
            break;
        }
    }
    if(ap){
        cout << id[b[1]] << endl;
        return 0;
    }
    ap = true;
    int del = -1;
    d = b[1] - b[0];
    for(int i = 2; i < n; i++){
        if(b[i] - b[i - 1] != d){
            if(del == -1){
                del = b[i];
                b[i] = b[i - 1];
            }
            else{
                ap = false;
                break;
            }
        }
    }
    if(ap){
        cout << id[del] << endl;
        return 0;
    }
    cout << -1 << endl;
}