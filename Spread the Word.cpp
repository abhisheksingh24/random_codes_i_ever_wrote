#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t, n;
    vector<long long> vec, total;
    cin >> t;
    while(t--){
        cin >> n;
        vec.clear();
        total.clear();
        vec.resize(n);
        for(int i = 0; i < n; i++) cin >> vec[i];
        total.push_back(vec[0]);
        for(int i = 1; i < n; i++) total.push_back(vec[i]+total[i-1]);
        int day = 0; long long spread = 1;
        while(spread < n){
            spread+=total[spread-1];
            day++;
        }
        cout << day << endl;
    }
}