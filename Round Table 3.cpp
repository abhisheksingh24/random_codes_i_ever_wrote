
#include<iostream>
#include<vector>

using namespace std;

int n, incl[1000000][2], excl[1000000][2];
vector<int> cost;

int exclude(int,int);

void init(){
    for(int i = 0; i<n; i++){
        for(int j = 0; j < 2; j++){
            incl[i][j] = excl[i][j] = -1;
        }
    }
}

int include(int beg, int end){
    if(beg>=end) return 0;
    if(incl[beg][n-end]==-1) incl[beg][n-end] = cost[beg] + exclude(beg+1,end);
    return(incl[beg][n-end]);
}

int exclude(int beg, int end){
    if(beg>=end) return 0;
    if(excl[beg][n-end]==-1) excl[beg][n-end] = min(include(beg, end), include(beg+1, end));
    return(excl[beg][n-end]);
}

int main(){
    int temp;
    cin >> n;
    int minSum;
    init();
    for(int i = 0; i < n; i++){
        cin >> temp;
        cost.push_back(temp);
    }
    minSum = min(include(0,n), cost[n-1]+include(1,n-1));
    cout << minSum << endl;
}
