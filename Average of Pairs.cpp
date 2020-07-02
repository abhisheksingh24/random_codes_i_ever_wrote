#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<long long> ar;
    int t, n;
    long long pairs;
    cin >> t;
    while(t--){
        pairs = 0;
        cin >> n;
        ar.clear();
        ar.resize(2001);
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            ar[temp+1000]++;
        }
        for(int i = 0; i <= 2000; i++){
            //if((ar[i]*(ar[i]-1))/2) cout << i-1000 << " : " << ar[i] << "; " << endl;
            pairs+=((ar[i]*(ar[i]-1))/2);
            for(int j = i+2; j <= 2000; j+=2){
                int avg = (i+j)/2;
                if(ar[avg]){
                    //if(ar[i] && ar[j]) cout << i-1000 << ", " << j-1000 << " : " << ar[i] << "*" << ar[j] << ";" << endl;
                    pairs += (ar[i]*ar[j]);
                }
            }
        }
        cout << pairs << endl;
    }
}
