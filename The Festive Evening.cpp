#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> seq;
int last[26];
bool assigned[26];

void init(){
    for(int i = 0; i < 26; i++) assigned[i] = false;
}

int firstAssigned(){
    for(int i = 0; i < 26; i++){
        if(assigned[i]) return i;
    }
}

string unguarded(int n, int k){
    int assigns = 0;
    for(int i = 0; i < n; i++){
        if(!assigned[seq[i]]){
            if(assigns==k){
                return "YES";
            }
            else{
                assigned[seq[i]] = true;
                assigns++;
            }
        }
        if(last[seq[i]]==i){
            assigned[seq[i]] = false;
            assigns--;
        }
    }
    return "NO";
}

int main(){
    int n, k;
    char temp;
    init();
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> temp;
        seq.push_back(temp-'A');
        last[seq[i]] = i;
    }
    cout << unguarded(n, k) << endl;
}
