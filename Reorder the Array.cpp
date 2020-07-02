#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    vector<int> ar;
    cin >> n;
    ar.resize(n);
    for(int i = 0; i < n; i++) cin >> ar[i];
    sort(ar.begin(), ar.end());
    int cnt = 0, j = 1;
    for(int i = 0; i < n; i++){
        while(j < n && ar[j] <= ar[i]) j++;
        if(j==n) break;
        cnt++;
        j++;
    }
    cout << cnt << endl;
}
