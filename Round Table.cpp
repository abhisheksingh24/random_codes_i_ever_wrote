#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> cost;

int res[2][1000000], call = 0;

void init(int n){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            res[i][j] = -1;
        }
    }
}

int exclude(int,int);

int include(int beg, int end){
    cout << "include "<< beg+1 << " "<< end << " called = " << res[end-n+1][beg] << endl;
    //cout << "call "<<call++ << endl;
    if(beg>=end){
        cout << "include "<< beg+1 << " "<< end << " returned 0\n\n";
        return 0;
    }
    //cout << beg << " " << end << endl;
    //cout << "[" << end-n <<"]["<<beg<<"]"<< endl;
    if(res[end-n+1][beg]==-1){
        cout << "include "<<beg+1 << ", "<<end<<" = "<<cost[beg]<<" + "<<beg+2 << ", "<<end<<endl;
        res[end-n+1][beg] = cost[beg]+exclude(beg+1, end);
    }
    cout << "include "<< beg+1 << " "<< end << " calculated ";cout << res[end-n+1][beg] << endl<<endl;
    return(res[end-n+1][beg]);
}

int exclude(int beg, int end){
    cout << "exclude "<< beg+1 << " "<< end << " called = " << res[end-n+1][beg] << endl;
    //cout << "call "<<call++ << endl;
    if(beg>=end){
        cout << "exclude "<< beg+1 << " "<< end << " returned 0\n\n";
        return 0;
    }
    if(res[end-n+1][beg]==-1){
        cout << "exclude "<<beg+1 << ", "<<end<<" = "<<beg+2 << ", "<<end<<" or "<<beg+1 << ", "<<end<<endl;
        res[end-n+1][beg] = min(include(beg+1,end), include(beg, end));
    }
    cout << "exclude "<< beg+1 << " "<< end << " calculated ";cout << res[end-n+1][beg] << endl<<endl;
    return(res[end-n+1][beg]);
}

int main(){
    int temp;
    cin >> n;
    init(n);
    //cout << "initialized\n";
    long long minSum;
    for(int i = 0; i < n; i++){
        cin >> temp;
        cost.push_back(temp);
    }
    //cout << "pushed all\n";
    minSum = min(include(0,n), cost[n-1]+include(1,n-1));
    cout << minSum << endl;
}
