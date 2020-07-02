#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> digits;
    int k, sum = 0;
    string n;
    cin >> k;
    cin >> n;
    for(char i : n){
        int d = i - '0';
        sum+=d;
        digits.push_back(d);
    }
    sort(digits.begin(), digits.end());
    int cnt = 0;
    for(int i : digits){
        if(sum >= k) break;
        sum+=(9-i);
        cnt++;
    }
    cout << cnt << endl;
}
