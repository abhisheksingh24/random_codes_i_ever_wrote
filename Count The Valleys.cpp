#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t, n ,temp;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> height;
        for(int i = 0; i < n; i++){
            cin >> temp;
            height.push_back(temp);
        }
        int cnt = 0;
        for(int i = 1; i < n-1; i++){
            if(height[i] < height[i-1] && height[i] < height[i+1]) cnt++;
        }
        cout << cnt << endl;
    }
}
