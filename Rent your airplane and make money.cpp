#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int res[100000];

struct order{
    int start, dur, price;
    bool operator<(order other) const{
        return start < other.start;
    }
};

vector<order> orders;

void init(int n){
    for(int i = 0; i < n; i++){
        res[i] = -1;
    }
}

int findNext(int beg, int en, int time){
    if(beg > en) return -1;
    if(beg==en && orders[beg].start >= time) return beg;
    int mid = beg + (en - beg)/2;
    if(orders[mid].start >= time) en = mid;
    else beg = mid + 1;
    return findNext(beg, en, time);
}

int maxProfit(int from, int n){
    if(from >= n || from==-1) return 0;
    if(res[from] != -1) return res[from];
    int next = findNext(from+1, n-1, orders[from].start + orders[from].dur);
    res[from] = max(orders[from].price + maxProfit(next, n), maxProfit(from+1, n));
    return res[from];
}

int main(){
    int t, n;
    order temp;
    cin >> t;
    while(t--){
        orders.clear();
        cin >> n;
        init(n);
        for(int i = 0; i < n; i++){
            cin >> temp.start >> temp.dur >> temp.price;
            orders.push_back(temp);
        }
        sort(orders.begin(), orders.end());
        cout << maxProfit(0, n) << endl;
    }
}
