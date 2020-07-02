#include<bits/stdc++.h>

using namespace std;

int compare(vector<int> a, vector<int> b){
    int missing  = -1;
    for(int i = 0, j = 0; i < 5; i++, j++){
        if(j == 4){
            missing = a[i];
            break;
        }
        if(a[i] == b[j]) continue;
        if(missing == -1){
            missing = a[i];
            j--;
            continue;
        }
        return -1;
    }
    return missing;
}

void printSeq(int cur, vector<int> query, vector<int> m, vector<int> a, int missing){
    cout << "! " << a[cur] << " ";
    for(int q: query){
        int inc = 0;
        for(int i = 0; i < 5; i++){
            if(i == cur) inc++;
            if(q == m[i]){
                cout << a[i + inc] << " ";
                break;
            }
        }
    }
    int inc = 0;
    for(int i = 0; i < 5; i++){
        if(i == cur) inc++;
        if(missing == m[i]){
            cout << a[i + inc] << endl;
            break;
        }
    }
    cout.flush();
}

int main(){
    vector<int> a = {4, 8, 15, 16, 23, 42};
    vector<vector<int> > mul(6);
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(i == j) continue;
            mul[i].push_back(a[i] * a[j]);
        }
    }
    vector<int> queryRes;
    for(int i = 0; i < 4; i++){
        cout << "? " << 1 << " " << i + 2 << endl;
        cout.flush();
        int q;
        cin >> q;
        queryRes.push_back(q);
    }
    vector<int> sorted = queryRes;
    sort(sorted.begin(), sorted.end());
    for(int i = 0; i < 6; i++){
        //cout << "comparing \n"; 
        //for(int x: mul[i]) cout << x << " "; cout << endl;
        //for(int x: sorted) cout << x << " "; cout << endl;

        int missing = compare(mul[i], sorted);
        if(missing == -1) continue;
        printSeq(i, queryRes, mul[i], a, missing);
        break;
    }
}