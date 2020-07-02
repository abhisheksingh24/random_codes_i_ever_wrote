#include<iostream>
#include<vector>

using namespace std;

int digitSumPartial(long long n){
    int s = 0;
    while(n>0){
        s += n%10;
        n/=10;
    }
    return s;
}

int digitSum(long long n){
    //cout << "Finding DigitSum for " << n << endl;
    if(n < 10) return (int)(n);
    return digitSum(digitSumPartial(s));
}

int findMin(long long n, long long d){
    vector<bool> found;
    for(int i = 0; i < 10; i++) found.push_back(0);
    for(int m = 0; ; m++){
        //cout << "> " << n+d*m << " : ";
        int dig = digitSum(n+d*m);
        //cout << dig << endl;
        if(found[dig]) break;
        found[dig] = true;
    }
    for(int i = 0; i < 10; i++){
        if(found[i]) return i;
    }
    return -1;
}

bool canSolveIn(long long n, long long d, int m, long long steps){
    if(steps == 0) return n==m;
    if(canSolveIn(digitSumPartial(n), d, m, steps-1)) return true;
    for(int i = 1; i <= steps; i++){
        if(canSolveIn(n+d*i, d, m, steps-i)) return true;
    }
    return false;
}

int main(){
    long long t, n, d;
    cin >> t;
    while(t--){
        cin >> n >> d;
        int m = findMin(n, d);
        long long steps;
        for(long long i = 0; ; i++){
            //cout << "Trying to solve in " << i << endl;
            if(canSolveIn(n, d, m, i)){
                steps = i;
                break;
            }
        }
        cout << m << " " << steps << endl;
    }
}