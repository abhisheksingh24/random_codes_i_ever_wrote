#include<bits/stdc++.h>

using namespace std;

bool intersect(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d){
    
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int> > points(n);
    for(auto& p: points) cin >> p.first >> p.second;
    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = i + 1; k < n; k++){
                for(int l = k + 1; l < n; l++){
                    if(j == k || j == l) continue;
                    if(intersect(points[i], points[j], points[k], points[l])) res++;
                }
            }
        }
    }
    cout << res << endl;
}