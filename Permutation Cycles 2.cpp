#include<iostream>
#include<vector>

using namespace std;

vector<int> p;
vector<vector<int> > cycles;
bool visited[1000];

void init(int n){
    for(int i =0 ; i < n; i++){
        visited[i] = false;
    }
}

int main(){
    int n, temp, visits = 0, pos = 0;
    vector<int> cycle;
    cin >> n;
    init(n);
    for(int i = 0; i < n; i++){
        cin >> temp;
        p.push_back(temp);
    }
    while(true){
        cycle.push_back(pos+1);
        visited[pos] = true; visits++;
        pos = p[pos] - 1;
        if(visited[pos]){
            cycle.push_back(pos+1);
            cycles.push_back(cycle);
            if(visits>=n) break;
            cycle.clear();
            while(visited[pos]) pos++;
        }
    }
    cout << cycles.size() << endl;
    for(auto c : cycles){
        for(int i : c){
            cout << i << " ";
        }
        cout << endl;
    }
}
