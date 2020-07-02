#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t, n, k;
    cin >> t;
    while(t--){
        vector<int> ar;
        cin >> n >> k;
        for(int i = 0; i  < n; i++){
                int temp;
            cin >> temp;
            ar.push_back(temp);
        }
        sort(ar.begin(), ar.end());
        cout << ar[(n-1+k)/2] << endl;
    }
}
