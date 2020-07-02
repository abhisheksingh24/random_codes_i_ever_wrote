#include<iostream>
#include<vector>

using namespace std;

vector<int> tags;
int res[101][101][101];

void reset(int n){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k <= n; k++){
                res[i][j][k] = -1;
            }
        }
    }
}

int max3(int a, int b, int c){
    return max(a,max(b,c));
}

int f(int pos, int i, int j, int n){
    if(pos>n) return 0;
    if(res[pos][i][j]==-1){
        int a, b, c;
        a = f(pos+1,i,j,n);
        b = (i==0 || tags[pos-1]>tags[i-1] ? 1+f(pos+1,pos,j,n) : 0);
        c = (j==0 || tags[pos-1]<tags[j-1] ? 1+f(pos+1,i,pos,n) : 0);
        res[pos][i][j] = max3(a, b, c);
    }
    return res[pos][i][j];
}

int main(){
    int t, n, maxRooms, temp;
    cin >> t;
    while(t--){
        tags.clear();
        cin >> n;
        reset(n);
        maxRooms = 0;
        for(int i = 0; i < n; i++){
            cin >> temp;
            tags.push_back(temp);
        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                for(int k = 0; k < i; k++){
                        maxRooms = max(f(i, j, k, n), maxRooms);
                }
            }
        }
        cout << maxRooms << endl;
    }
}
