#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

long long res[63000000];
priority_queue<long long> p;
queue<long long> q;

int main(){
    int m, n, pos=0;
    long long temp, a,b;
    cin >> n >> m;
    while(n--){
        cin >> temp;
        p.push(temp);
    }
    while(!p.empty() || !q.empty()){
        if(p.empty()){
            res[pos++] = q.front();
            //cout << res[pos-1] << " removed\n";
            q.pop();
            if(res[pos-1]/2) q.push(res[pos-1]/2);
        }
        else if(q.empty()){
            res[pos++] = p.top();
            //cout << res[pos-1] << " removed\n";
            p.pop();
            if(res[pos-1]/2) q.push(res[pos-1]/2);
        }
        else{
            a = p.top();
            b = q.front();
            if(a>b){
                res[pos++] = a;
                p.pop();
                if(a/2) q.push(a/2);
            }
            else{
                res[pos++] = b;
                q.pop();
                if(b/2) q.push(b/2);
            }
            //cout << res[pos-1] << " removed\n";
        }
    }
    while(m--){
        cin >> temp;
        cout << res[temp-1] << '\n';
    }
}
