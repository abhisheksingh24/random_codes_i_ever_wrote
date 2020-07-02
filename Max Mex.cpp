#include<iostream>
#include<vector>

using namespace std;

vector<bool> present;

int main(){
    int t, n, k, a;
    cin >> t;
    while(t--){
        cin >> n >> k;
        present.clear();
        for(int i = 0; i <= 200000; i++) present.push_back(false);
        while(n--){
            cin >> a;
            present[a] = true;
        }
        for(int i = 0; ; i++){
            if(!present[i]){
                if(k<=0){
                    cout << i << endl;
                    break;
                }
                k--;
            }
        }
    }
}
