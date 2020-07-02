#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> pos;

int main(){
    int n, temp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        pos.push_back(temp);
    }
    int toSort = 0, lastSorted = n+1;
    priority_queue<int> unSorted;
    cout << 1 << " ";
    for(int p: pos){
        if(p == lastSorted-1){
            lastSorted--;
            while(!unSorted.empty()){
                if(unSorted.top() == lastSorted-1){
                    lastSorted--;
                    toSort--;
                    unSorted.pop();
                }
                else break;
            }
        }
        else{
            toSort++;
            unSorted.push(p);
        }
        cout << toSort+1 << " ";
    }
}
