#include<iostream>
#include<vector>
#include<string>

using namespace std;

int gcd(int a, int b) { 
    if (b == 0) return a; 
    return gcd(b, a % b);  
}

int main(){
    int t, h1, w1, h2, w2;
    vector<vector<bool> > mat1, mat2;
    string temp;
    cin >> t;
    while(t--){
        mat1.clear();
        mat2.clear();
        cin >> h1 >> w1;
        cin >> temp;
        mat1.resize(h1);
        int ind = 0;
        for(int i = 0; i < h1; i++){
            for(int j = 0; j < w1; j++){
                //cout << i << ", " << j << ", " << ind << endl; 
                mat1[i].push_back(temp[ind++]=='1');
            }
        }
        cin >> h2 >> w2;
        cin >> temp;
        mat2.resize(h2);
        ind = 0;
        for(int i = 0; i < h2; i++){
            for(int j = 0; j < w2; j++){
                //cout << i << ", " << j << ", " << ind << endl;
                mat2[i].push_back(temp[ind++]=='1');
            }
        }
        int w = (w1*w2)/gcd(w1, w2);
        int h = (h1*h2)/gcd(h1, h2);
        int mw1 = w/w1, mw2 = w/w2, mh1 = h/h1, mh2 = h/h2;
        int res = 0;

        /*
        cout << endl << "mat 1 : " << endl;
        for(auto row: mat1){
            for( auto i: row) cout << i << " ";
            cout << endl;
        }
        cout << endl << "mat 2 : " << endl;
        for(auto row: mat2){
            for( auto i: row) cout << i << " ";
            cout << endl;
        }
        cout << endl << "mat 1 expanded : " << endl;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cout << mat1[i/mh1][j/mw1] << " ";// == mat2[j/mh2][j/mw2]) res++;
            }
            cout << endl;
        }
        cout << endl << "mat 2 expanded : " << endl;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cout << mat2[i/mh2][j/mw2] << " ";// == mat2[j/mh2][j/mw2]) res++;
            }
            cout << endl;
        }
        */

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(mat1[i/mh1][j/mw1] == mat2[i/mh2][j/mw2]) res++;
            }
        }
        cout << res << endl;
    }
}