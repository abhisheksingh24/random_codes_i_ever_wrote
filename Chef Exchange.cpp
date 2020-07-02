#include<bits/stdc++.h>

using namespace std;

struct send{
    int a, b, c, k;
    send(int a0, int b0, int c0, int d0){
        a = a0;
        b = b0;
        c = c0;
        k = d0;
    }
    void print(){
        cout << "SEND " << a <<" " << b  << " " << c  << " " << k << endl;
    }
};

int main(){
    int n, m, q;
    vector<int> bal;
    cin >> n >> m >> q;
    bal.resize(n, 0);
    while(q--){
        int temp, a, b, k, c, x;
        cin >> temp;
        if(temp == 0){
            cin >> a >> b >> k;
            --a; --b;
            bal[a] -= k;
            bal[b] += k;
        }   
        else{
            cin >> c >> x;
        }
        if(q == 0){
            vector<send> op;
            for(int i = 0; i < n; i++){
                if(bal[i] > 0){
                    op.emplace_back(i + 1, i + 2, 1, bal[i]);
                    bal[i + 1] += bal[i];
                    bal[i] = 0;
                }
                else if(bal[i] < 0){
                    op.emplace_back(i + 2, i + 1, 1, -bal[i]);
                    bal[i + 1] += bal[i];
                    bal[i] = 0;
                }
            } 
            cout << op.size() << endl;
            for(auto opi: op){
                opi.print();
            }
        }
        else cout << 0 << endl;
        cout.flush();
        cin >> temp;
        assert(temp == 1);
    }
}