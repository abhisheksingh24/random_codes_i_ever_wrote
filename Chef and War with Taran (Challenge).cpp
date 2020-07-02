#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

vector<vector<int> > mat;

int main(){
    srand((int)time(0));
    int t, n, a, b;
    cin >> t;
    while(t--){
        cin >> n >> a >> b;
        mat.clear();
        mat.resize(n);
        for(int i = 0; i < n; i++){
            mat[i].resize(n);
            for(int j = 0; j < n; j++) cin >> mat[i][j];
        }
        vector<int> counts, my, his;
        counts.resize(n);
        for(int i = 0; i < n; i++){
            int x = 0, y = 0;
            while(x==y){
                x = rand() % n;
                y = rand() % n;
            }
            if(mat[x][y]){
                counts[x]++;
                my.push_back(x);
            }
            else{
                counts[y]++;
                my.push_back(y);
            }
        }
        for(int c: counts) cout << c << " ";
        cout << endl;
        for(int i = 0; i < n; i++) cin >> counts[i];
        for(int i = 0; i < n; i++){
            while(counts[i]--){
                his.push_back(i);
            }
        }
        for(int i = 0; i < n/(a+b); i++){
            for(int j = 0; j < a; j++){
                int x = 0, y = 0;
                int l = my.size();
                for(int k = 0; k < 1000; k++){
                    x = rand() % l;
                    y = rand() % l;
                    if(mat[my[x]][his[y]]) break;
                }
                cout << my[x]+1 << " " << his[y]+1 << endl;
                my.erase(my.begin() +  x);
                his.erase(his.begin() + y);
            }
            for(int j = 0; j < b; j++){
                int x, y;
                cin >> x >> y;
                int l = my.size();
                for(int i = 0; i < l; i++){
                    if(my[i] == x-1){
                        my.erase(my.begin() +  i);
                        break;
                    }
                }
                for(int i = 0; i < l; i++){
                    if(his[i] == y-1){
                        his.erase(his.begin() +  i);
                        break;
                    }
                }
            }
        }
    }
}
