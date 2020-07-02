#include<iostream>
#include<vector>

using namespace std;

vector<int> gp, counts;

int findInd(int n, int m, int k){
    for(int i = 0; i < n; i++){
        counts[gp[i]%m]++;
        if(counts[gp[i]%m] >= k) return gp[i]%m;
    }
    return -1;
}

int main(){
    int n, k, m, temp;
    cin >> n >> k >> m;
    counts.resize(m);
    for(int i = 0; i < n; i++) {
        cin >> temp;
        gp.push_back(temp);
    }
    int div = findInd(n, m, k);
    int cnt = 0;
    if(div==-1) cout << "No\n";
    else{
        cout << "Yes\n";
        for(int i: gp){
            if(i%m==div){
                cout << i << " ";
                cnt++;
                if(cnt>=k) break;
            }
        }
        cout << endl;
    }
}
