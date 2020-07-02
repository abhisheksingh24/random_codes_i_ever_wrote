#include<iostream>
#include<queue>

using namespace std;

int main(){
    int n, m, temp;
    priority_queue<int> wealth;
    cin >> n >> m;
    for(int i = 0; i < m+n; i++){
        cin >> temp;
        if(temp==-1){
            cout << wealth.top() << endl;
            wealth.pop();
        }
        else{
            wealth.push(temp);
        }
    }
}
