#include<iostream>
#include<vector>
#include<queue>
#include<limits>
#include<set>
#include<algorithm>

using namespace std;

#define INF numeric_limits<int>::max()
#define invertedQueue priority_queue<int, vector<int>, cmp >

vector<int> minPossibleSum;
vector<int> ar;

struct cmp{
    bool operator()(const int a, const int b){
        return minPossibleSum[a] > minPossibleSum[b];
    }
};

void fillMinSums(vector<int> ar){
    int mn = *ar.begin();
    for(int i = 0; i < mn; i++) {
        minPossibleSum.push_back(INF);
    }

    minPossibleSum[0] = 0;
    invertedQueue toVisit;
    toVisit.push(0);

    while(!toVisit.empty()){
        int cur = toVisit.top();
        toVisit.pop();
        for(int ele: ar){
            int curSum = minPossibleSum[cur] + ele;
            int r = curSum%mn;
            if(curSum < minPossibleSum[r]){
                minPossibleSum[r] = curSum;
                toVisit.push(r);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int element;
        cin >> element;
        ar.push_back(element);
    }
    sort(ar.begin(), ar.end());
    int r = *ar.begin();
    vector<bool> found; found.resize(r);
    for(vector<int>::iterator it = ar.begin(); it!=ar.end();){
        if(found[(*it)%r]) it = ar.erase(it);
        else{
            found[(*it)%r] = true;
            it++;
        }
    }
    fillMinSums(ar);
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        int b;
        cin >> b;
        if(b >= minPossibleSum[b%r]) cout << "TAK\n";
        else cout << "NIE\n";
    }
}
