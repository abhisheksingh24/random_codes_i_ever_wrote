#include<iostream>
#include<vector>

using namespace std;

int k;
vector<int> prices;
long long a[401][401], b[401][401];

void init(){
    for(int i = 0; i < 401; i++){
        for(int j = 0; j < 401; j++){
            a[i][j] = 0;
        }
    }
}

/*
void print(long long ar[401][401], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            cout<<a[i][j]<<" ";
        }
        cout << endl;
    }
}
*/

long long solve(long long up[401][401], long long down[401][401], int n){
    //cout << "\nn = "<<n<<endl;
    //print(a,n);
    for(int buyingDay = 0; buyingDay < n; buyingDay++){
        for(int visitsLeft = 0; visitsLeft <= k; visitsLeft++){
            if(!visitsLeft) down[buyingDay][visitsLeft] = 0;
            else{
                long long a, b, c;
                a = up[buyingDay][visitsLeft];
                b = (buyingDay==0 ? up[n][visitsLeft-1] : 0);
                c = (buyingDay!=0 && prices[n-1]-prices[buyingDay-1] ? up[0][visitsLeft-1] + (prices[n-1]-prices[buyingDay-1]) : 0);
                down[buyingDay][visitsLeft] = max(a,max(b,c));
            }
        }
    }
    //cout<<endl;
    //print(b,n);
    if(n==1) return down[0][k];
    return solve(down, up, n-1);
}

int main(){
    int n, temp;
    cin >> n>> k;
    for(int i = 0; i < n; i++){
        cin >> temp;
        prices.push_back(temp);
    }
    init();
    cout << solve(a,b,n) <<endl;
}
