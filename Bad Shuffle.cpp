#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> p1, p2;
    p1.resize(n);
    p2.resize(n);
    if(n==1){
        cout << 1 << endl << 1 << endl;
        return 0;
    }
    for(int i = 1; i < n; i++) p1[i] = i;
    p1[0] = n;
    int cur = 1;
    p2[n/2-1] = cur++;
    for(int i = 0; i < n/2-1; i++) p2[i] = cur++;
    p2[n-1] = cur++;
    for(int i = n/2; i < n-1; i++) p2[i] = cur++;

    for(int i: p2) cout << i << " ";
    cout << endl;
    for(int i: p1) cout << i << " ";
    cout << endl;
}