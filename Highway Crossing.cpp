#include<iostream>
#include<vector>

using namespace std;

vector<double> vel, dir, pos, len;

double cross(int lane, double startTime){

}

int main(){
    int t;
    double n , s, y;
    cin >> t;

    while(t--){
        cin >> n >> s >> y;
        vel.resize(n);
        for(int i = 0; i < n; i++) cin >> vel[i];
        for(int i = 0; i < n; i++) cin >> dir[i];
        for(int i = 0; i < n; i++) cin >> pos[i];
        for(int i = 0; i < n; i++) cin >> len[i];

        double tym = 0;
        for(int i = 0; i < n; i++){
            tym = cross(i, tym);
        }
        cout << tym << endl;
    }
}
