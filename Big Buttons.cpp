#include<iostream>
#include<string>
#include<vector>

using namespace std;

void bSort(vector<string>& vec, int n){
    string temp;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(vec[j].length() < vec[i].length()){
                temp = vec[j];
                vec[j] = vec[i];
                vec[i] = temp;
            }
        }
    }
} 

long long power(long long b, long long e){
    if(e==0) return 1;
    if(e%2) return b*power(b*b, e/2);
    return power(b*b, e/2);
}

int main(){
    int t, n, p;
    vector<string> pre;
    string s;
    cin >> t;
    for(int z = 1; z <= t; z++){
        pre.clear();
        cin >> n >> p;
        for(int i = 0; i < p; i++){
            cin >> s;
            pre.push_back(s);
        }
        bSort(pre, p);
        //for(int i = 0; i < p; i++) cout << pre[i] << endl;
        vector<bool> removed;
        for(int i = 0; i < p; i++) removed.push_back(false);
        for(int i = 0; i < p-1; i++){
            if(removed[i]) continue;
            for(int j = i+1; j < p; j++){
                if(!removed[j] && pre[j].compare(0, pre[i].length(), pre[i]) == 0) removed[j] = true;
            }
        }
        //for(int i = 0; i < p; i++) if(!removed[i]) cout << pre[i] << endl;
        long long tot = power((long long)(2), (long long)(n));
        //cout << "tot =  " << tot << endl;
        for(int i = 0; i < p; i++){
            if(!removed[i]) tot -= (power(2, n-pre[i].length()));
            //if(!removed[i]) cout << "minus " << (power(2, n-pre[i].length())) << endl;
        }
        cout << "Case #" << z << ": " << tot << endl;
    }

}