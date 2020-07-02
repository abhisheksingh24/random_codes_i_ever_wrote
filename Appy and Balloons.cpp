#include<iostream>
#include<vector>
#include<pair>
#include<algorithm>

using namespace std;

int main(int argc, char const *argv[]){
    int n, m;
    cin >> n >> m;
    m*=-1;
    vector<int> ballons, candies;
    ballons.resize(n);
    candies.resize(n);
    for(int i = 0; i < n; i++){
        cin >> balloons[i];
        m+=balloons[i];
    }
    for(int i = 0; i < n; i++) cin >> candies[i];
    if(m <= 0){
        cout << 0 << endl;
    }
    else{
        vector<pair<int, int> > balCand;
        for(int i = 0; i < n; i++){
            pair<int, int> temp;
            temp.first = candies[i];
            temp.second = ballons[i];
            balCand.push_back(temp);
        }
        sort(balCand.begin(), balCand.end());
        for(int i = 0; i < n; i++){
            if(m <= 0) break;
            int cand = balCand[i].first;
            int bal = balCand[i].second;
            if(m < bal){
                int curCand = m*cand;
                m = 0;
                if(curCand > )
            }
        }
    }

    return 0;
}