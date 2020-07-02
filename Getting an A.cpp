#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

 int main(){
    int n, tot = 0;
    vector<int> grades;
    cin >> n;
    grades.resize(n);
    for(int i = 0; i < n; i++){
        cin >> grades[i];
        tot += grades[i];
    }
    int minReq = (int)(4.5*n + 0.5);
    int need = minReq - tot;
    if(need <= 0) cout << 0 << endl;
    else{
        sort(grades.begin(), grades.end());
        int work = 0;
        while(need > 0){
            need-=(5-grades[work++]);
        }
        cout << work << endl;
    }

 }
