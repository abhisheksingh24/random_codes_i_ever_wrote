#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct data{
    long long d, t, s;
    bool operator<(data other) const{
        return(s > other.s);
    }
};

vector<data> train;
bool filled[1000001];

void init(int n){
    for(int i = 1; i <= n; i++){
        filled[i] = false;
    }
}

int allot(int beg, int n, int lectures){
    if(beg>n) return lectures;
    if(lectures==0) return 0;
    if(filled[beg]) return allot(beg+1, n, lectures);
    filled[beg] = true;
    return allot(beg+1, n, lectures-1);
}

long long sadness(int n, int days){
    long long sad = 0;
    for(int i = 0; i < n; i++){
        int missed = allot(train[i].d, days, train[i].t);
        sad+=(missed*train[i].s);
    }
    return sad;
}

int main(){
    int t, n, days;
    data temp;
    cin >> t;
    while(t--){
        train.clear();
        cin >> n >> days;
        init(days);
        for(int i = 0; i < n; i++){
            cin >> temp.d >> temp.t >> temp.s;
            train.push_back(temp);
        }
        sort(train.begin(), train.end());
        cout << sadness(n, days) << endl;
    }
}
