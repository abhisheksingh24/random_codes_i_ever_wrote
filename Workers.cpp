#include<iostream>
#include<vector>
#include<limits>

using namespace std;

#define MAX 100000

int main(){
    int n, minAuth, minTrans, minBoth;
    minAuth = minTrans = minBoth = MAX;
    vector<int> coins, type;
    cin >> n;
    coins.resize(n);
    type.resize(n);
    for(int i = 0; i < n; i++) cin >> coins[i];
    for(int i = 0; i < n; i++) cin >> type[i];
    for(int i = 0; i < n; i++){
        switch(type[i]){
        case 1:
            if(coins[i] < minAuth) minAuth = coins[i];
            break;
        case 2:
            if(coins[i] < minTrans) minTrans = coins[i];
            break;
        case 3:
            if(coins[i] < minBoth) minBoth = coins[i];
            break;
        }
    }
    cout << min(minAuth + minTrans, minBoth) << endl;
}
