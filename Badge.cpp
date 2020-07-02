#include<iostream>
#include<vector>

using namespace std;

void init(vector<bool>& badged, int n){
    badged.resize(n+1);
    for(int i = 0; i <= n; i++) badged[i] = false;
}

int main(){
    int n;
    vector<int> p;
    cin >> n;
    p.resize(n+1);
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int s = 1; s <= n; s++){
        vector<bool> badged;
        init(badged, n);
        int i = s;
        while(!badged[i]){
            badged[i] = true;
            i = p[i];
        }
        cout << i << " ";
    }
    cout << endl;
}
