#include<iostream>
#include<vector>

using namespace std;

vector<int> prices;
long long res[401][401][401];
int n;

void init(int n){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k <= n; k++){
                res[i][j][k] = -1;
            }
        }
    }
}

long long solve(int day, int boughtOn, int visitsLeft){
    if(visitsLeft==0 || day>n) return 0;
    if(res[day][boughtOn][visitsLeft] != -1) return res[day][boughtOn][visitsLeft];
    long long a, b, c;
    a = solve(day+1, boughtOn, visitsLeft);
    b = (boughtOn==0 ? solve(day+1, day, visitsLeft-1) : 0);
    if(boughtOn!=0 && prices[day-1] > prices[boughtOn-1]){
        c = solve(day+1, 0, visitsLeft-1) + (prices[day-1] - prices[boughtOn-1]);
    }
    else c = 0;
    res[day][boughtOn][visitsLeft] = max(a,max(b,c));
    return res[day][boughtOn][visitsLeft];
}

int main(){
    int k, temp;
    cin >> n>> k;
    init(n);
    for(int i = 0; i < n; i++){
        cin >> temp;
        prices.push_back(temp);
    }
    cout << solve(1,0,k) << endl;
}
