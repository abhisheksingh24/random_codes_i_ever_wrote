#include<iostream>
#include<vector>

using namespace std;

vector <long long> seq;

long long setHeight(long long n, long long d){
    long long cnt = 0;
    long long sum = 0;
    for(long long i = 0; i < n; i++){
        cnt++;
        sum+=seq[i];
    }
    if(sum%cnt) return -1;
    else return sum/cnt;
}

long long absolute(long long a){
    if(a<0) a*=(-1);
    return a;
}

long long move(long long start, long long n, long long d, long long h){
    long long cnt = 0, change;
    long long steps = 0;
    long long sum = 0;
    for(long long i = start; i < n; i+=d){
        cnt++;
        sum+=seq[i];
    }
    if(cnt==1 && seq[start] != h) return -1;
    if(sum!=cnt*h) return -1;
    for(long long i = start, j = start+d; j < n; i+=d, j+=d){
        change = h - seq[i];
        steps += absolute(change);
        seq[i]+=change;
        seq[j]-=change;
    }
    return steps;
}

long long minMoves(long long n, long long d){
    long long h = setHeight(n ,d), totSteps = 0, steps;
    //cout << "Height set to " << h << endl;
    if(h==-1) return -1;
    for(long long start = 0; start < d; start++){
        steps = move(start, n, d, h);
        if(steps == -1) return -1;
        totSteps+=steps;
    }
    return totSteps;
}

int main(){
    long long t, n, d;
    cin >> t;
    while(t--){
        cin >> n >> d;
        seq.clear();
        seq.resize(n);
        for(long long i = 0; i < n; i++) cin >> seq[i];
        cout << minMoves(n, d) << endl;
    }
}
