#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int countDigits(int n){
    int cnt = 0;
    while(n>0){
        n/=10;
        cnt++;
    }
    return cnt;
}

int sumDigits(int n){
    int sum = 0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int findMin(int n, int dig){
    return max(0, n-9*dig);
}

int main(){
    int n;
    cin >> n;
    int numDig = countDigits(n);
    int beg = findMin(n, numDig);
    int cnt = 0;
    vector<int> solutions;
    for(int i = beg; i <= n; i++){
        if(i+sumDigits(i) == n){
            cnt++;
            solutions.push_back(i);
        }
    }
    cout << cnt << endl;
    for(int i: solutions) cout << i << " ";
    cout << endl;
}
