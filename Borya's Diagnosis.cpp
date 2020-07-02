#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> s, d;

struct cmp{
    bool operator()(int a, int b){
        if(s[a]==s[b]) return d[a] < d[b];
        return s[a] > s[b];
    }
};

priority_queue<int, vector<int>, cmp> doc;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
            int temp;
        cin >> temp;
        s.push_back(temp);
        cin >> temp;
        d.push_back(temp);
    }
    int day = 0;
    for(int curDoc = 0; curDoc < n; curDoc++){
        if(s[curDoc] > day) day = s[curDoc];
        else{
            day = day  + (d[curDoc] - (day-s[curDoc])%d[curDoc]);
        }
    }
    cout << day << endl;
}
