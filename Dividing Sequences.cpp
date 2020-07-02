#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

vector<int> seq;
int res[10000];

void init(int n){
    for(int i = 0; i < n; i++){
        res[i] = 1;
    }
}

int abs(int n){
    if(n<0) n*=-1;
    return n;
}

bool oppSigns(int a, int b){
    if(a>0) return (b<0);
    return (b>0);
}

int maxLength(int n){
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(seq[i] % seq[j] == 0){
                res[i] = max(res[i], 1 + res[j]);
            }
        }
    }
    return *max_element(res, res+n);
}

int main(){
    int n, temp;
    cin >> n;
    init(n);
    for(int i = 0; i < n; i++){
        cin >> temp;
        seq.push_back(temp);
    }
    cout << maxLength(n) << endl;
}

