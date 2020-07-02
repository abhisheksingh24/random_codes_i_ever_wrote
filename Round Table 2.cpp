#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> cost;

int exclude(int,int);

int include(int beg, int end){
    if(beg>=end) return 0;
    return(cost[beg] + exclude(beg+1,end));
}

int exclude(int beg, int end){
    if(beg>=end) return 0;
    return min(include(beg, end), include(beg+1, end));
}

int main(){
    int temp;
    cin >> n;
    int minSum;
    for(int i = 0; i < n; i++){
        cin >> temp;
        cost.push_back(temp);
    }
    minSum = min(include(0,n), cost[n-1]+include(1,n-1));
    cout << minSum << endl;
}
