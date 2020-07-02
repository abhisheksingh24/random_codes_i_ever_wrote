#include<iostream>
#include<vector>

using namespace std;

struct dp{
    short int lesser, great;
}res[5000];

vector<int> seq;

void init(int n){
    for(int i = 0; i < n; i++){
        res[i].lesser = res[i].great = -1;
    }
}

int abs(int n){
    if(n<0) n*=-1;
    return n;
}

bool sameSigns(int a, int b){
    if(a>0) return (b>0);
    return (b<0);
}

int maxLength(int upto, int limit = 0){
    if(upto < 0) return 0;
    if(res[upto].great == -1) res[upto].great = maxLength(upto-1, limit);
    if(limit){
        if((abs(seq[upto]) >= abs(limit) || sameSigns(limit, seq[upto]))){
            return res[upto].great;
        }
    }
    if(res[upto].lesser == -1) res[upto].lesser = 1 + maxLength(upto-1, seq[upto]);
    return max(res[upto].lesser, res[upto].great);
}

int main(){
    int n, temp;
    cin >> n;
    init(n);
    for(int i = 0; i < n; i++){
        cin >> temp;
        seq.push_back(temp);
    }
    cout << maxLength(n-1) << endl;
}
