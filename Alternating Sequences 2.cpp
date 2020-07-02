
#include<iostream>
#include<vector>

using namespace std;

vector<int> seq;
int take[5000], skip[5000];

void init(int n){
    for(int i = 0; i < n; i++){
        take[i] = skip[i] = 1;
    }
    skip[0] = 0;
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
            if(oppSigns(seq[i], seq[j]) && abs(seq[j]) < abs(seq[i])){
                take[i] = max(take[i], 1 + take[j]);
            }
            skip[i] = max(skip[i], take[j]);
        }
    }
    return max(take[n-1], skip[n-1]);
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
