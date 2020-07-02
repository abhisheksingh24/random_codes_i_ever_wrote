#include<iostream>

using namespace std;

int main(){
    int t, n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        if(n == 1){
            if(m == 1) cout << "1\n1\n";
            else if(m == 2) cout << "1\n1 1\n";
            else{
                cout << 2 << endl;
                for(int i = 0; i < m; i++){
                    if(i/2 % 2) cout << "2 ";
                    else cout << "1 ";
                }
                cout << endl;
            }
        }
        else if(n == 2){
            if(m == 1) cout << "1\n1\n1\n";
            else if(m == 2) cout << "2\n1 1\n2 2\n";
            else{
                cout << 3 << endl;
                for(int i = 0; i < 2; i++){
                    for(int j = 0; j < m; j++){
                        cout << j%3 + 1 << " ";
                    }
                    cout << endl;
                }
            }
        }
        else{
            if(m == 1){
                cout << 2 << endl;
                for(int i = 0; i < n; i++){
                    if(i/2 % 2) cout << "2\n";
                    else cout << "1\n";
                }
            }
            else if(m == 2){
                cout << 3 << endl;
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++){
                        cout << i%3 + 1 << " ";
                    }
                    cout << endl;
                }
            }
            else{
                cout << 4 << endl;
                int a, b;
                for(int i = 0; i < n; i++){
                    if(i % 4 == 0) a = 1, b = 2;
                    else if(i % 4 == 1) a = 3, b = 4;
                    else if(i % 4 == 2) a = 2, b = 1;
                    else a = 4, b = 3;
                    for(int j = 0; j < m; j++){
                        if(j/2 % 2) cout << b << " ";
                        else cout << a << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
}