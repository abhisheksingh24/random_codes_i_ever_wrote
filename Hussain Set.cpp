#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

long long res[63000005], ar[1000000];

int main(){
    int m, n, pos=0;
    long long temp, a,b;
    queue<long long> q;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> ar[i];
    sort(ar, ar+n, greater<int>());
    int ind = 0;
    while(ind < n){
        //cout << "ind = "<<ind<<endl;
        //for(int i = ind; i < n; i++) cout << ar[i] << " ";
        //cout << endl;
        //cout << "size = " << q.size() << endl;
        if(q.empty()){
            temp = ar[ind++];
            res[pos++] = temp;
            if(temp/2 > 0) q.push(temp/2);
            //cout << temp/2 << "pushed\n";
        }
        else{
            a = ar[ind];
            b = q.front();
            if(a >= b){
                ind++;
                res[pos++] = a;
                if(a/2 > 0) q.push(a/2);
                //cout << a/2 << "pushed\n";
            }
            else{
                res[pos++] = b;
                q.pop();
                if(b/2 > 0) q.push(b/2);
                //cout << b/2 << "pushed\n";
            }
        }
    }
    while(!q.empty()){
        //cout << q.front() << " at the top\n";
        temp = q.front();
        res[pos++] = temp;
        q.pop();
        if(temp/2 > 0) q.push(temp/2);
    }
    while(m--){
        cin >> temp;
        cout << res[temp-1] << '\n';
    }
}
