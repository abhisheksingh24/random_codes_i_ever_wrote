#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    vector<int> a, b;
    vector<bool> put;
    cin >> n;
    a.resize(n);
    b.resize(n);
    for(int i = 0; i <= n; i++) put.push_back(0);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    int ind = 0;
    for(int toPut: b){
        if(put[toPut]){
            cout << "0 ";
            continue;
        }
        int cnt = 1;
        put[toPut] = true;
        while(a[ind] != toPut){
            put[a[ind]] = true;
            cnt++;
            ind++;
        }
        cout << cnt << " ";
        ind++;
    }
}