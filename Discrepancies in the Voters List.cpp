#include<iostream>
#include<map>

using namespace std;

int main(){
    int n1, n2, n3, mx = -1, temp, num = 0;
    map<int,int> m;
    cin >> n1 >> n2 >> n3;
    for(int i = 0; i < n1; i++){
        cin >> temp;
        m[temp]++;
        if(m[temp]==2) num++;
    }
    cout << num << endl;
    for (const auto &p : m) {
        if(p.second >= 2) cout << p.second << endl;
    }

}
