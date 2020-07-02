#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

vector<int> seq;
map<tuple<int, int, int>, bool> dp;

bool query(int a, int b, int c){
    tuple<int, int, int> temp = make_tuple(a, b, c);
    if(dp.find(temp) == dp.end()){
        cout << "? " << a << " " << b << " " << c << endl;
        string reply;
        cin >> reply;
        dp[temp] = (reply=="Yes");
    }
    return dp[temp];
}

bool isLeaf(int a){
    int b = seq[0];
    for(int i = 1; b == a; ++i) b = seq[i];
    for(int i: seq){
        if(i == a || i==b) continue;
        if(query(b, a, i)) return false;
    }
    return true;
}

bool secondLeaf(int a, int b, int h, vector<int>& path){
    for(int i: seq){
        if(i==a || i==b) continue;
        if(query(a, i, b)) path.push_back(i);
    }
    return(path.size() == 2*h - 1);
}

int findRoot(int l1, vector<int>& path){
    int temp;
    for(int i = 0; i < path.size(); i++){
        for(int j = i+1; j < path.size(); j++){
            if(query(l1, path[j], path[i])){
                temp = path[i];
                path[i] = path[j];
                path[j] = temp;   
            }
        }
    }
    return path[path.size()/2];
}

int main(){
    int n, k;
    cin >> n >> k;
    int h = 0;
    for(int i = 1; i < n; i+=(i*k), ++h);
    for(int i = 1; i <= n; i++) seq.push_back(i);
    random_shuffle(seq.begin(), seq. end());
    vector<int> path;
    int l1, l2;
    for(int i: seq){
        if(isLeaf(i)){
            l1 = i;
            break;
        }
    }
    for(int i: seq){
        if(i == l1) continue;
        path.clear();
        if(secondLeaf(l1, i, h, path)){
            cout << "! " << findRoot(i, path) << endl;
            break;
        }
    }
}