#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    vector<int> q;
    cin >> n;
    q.resize(n);
    for(int i = 0; i < n; i++) cin >> q[i];
    int mn = *min_element(q.begin(), q.end());
    int sub = mn - (mn%n);
    for(int i = 0; i < n; i++) q[i]-=sub;
    int ind = 0;
    while(!ind){
        for(int i = 0; i < n; i++){
            q[i] -= i;
            if(q[i] <= 0){
                ind = i+1;
                break;
            }
            q[i] -= (n-i);
        }
    }
    cout << ind << endl;
}
