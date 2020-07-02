#include<iostream>
#include<vector>

using namespace std;

vector<int> power;

int main(){
    long long n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        power.push_back(temp);
    }
    if(k > n) cout << n << endl;
    else{
        for(int i = 0; i < n; i++){
            int beaten = 0;
            int j = (i+1)%n;
            while(i==j || (power[i] > power[j] && beaten < k)){
                if(i==j){
                    j = (j+1)%n;
                    continue;
                }
                beaten++;
                j = (j+1)%n;
            }
            if(beaten>=k){
                cout << power[i] << endl;
                break;
            }
        }
    }
}
