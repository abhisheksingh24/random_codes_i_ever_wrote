#include<iostream>

using namespace std;

int star[101][101];

void init(){
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){
            star[i][j] = -1;
        }
    }
}

int bAt(int t, int c){

}

int main(){
    int n, q, c, x, y, x2, y2, t;
    cin >> n >> q >> c;
    init();
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        cin >> star[x][y];
    }
    for(int i = 0; i < q; i++){
        int brightness = 0;
        cin >> t >> x >> y >> x2 >> y2;
        for(int m = x; m <= x2; m++){
            for(int n = y; n <= y2; n++){
                if(star[m][n]!=-1){
                    brightness+=((star[m][n]+(t%(c+1)))%(c+1));
                }
            }
        }
        cout << brightness << endl;
    }
}
