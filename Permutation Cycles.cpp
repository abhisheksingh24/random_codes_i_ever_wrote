#include<iostream>
#include<vector>

using namespace std;

vector<int> perm;
vector<vector<int> > cycles;
bool visited[1001];

void init(int n){
    for(int i = 0; i <= n; i++){
        visited[i] = false;
    }
}

vector<int> walk(int startVal){
    vector<int> res;
    int curVal = startVal, curPos;
    res.push_back(startVal);
    while(true){
        curPos = curVal-1;
        visited[curPos] = true;
        //cout << "Visited " << curVal << endl;
        curVal = perm[curPos];
        //cout << "current value = " << curVal << "start value = " << startVal << endl;
        res.push_back(curVal);
        if(curVal == startVal) break;
    }
    return res;
}

vector<vector<int> > findCycles(int n){
    vector<vector<int> > res;
    vector<int> cycle;
    int startPos = 0, startVal;
    while(true){
        cycle.clear();
        while(visited[startPos]) startPos++;
        //cout << "startPos = " << startPos << endl;
        if(startPos==n) break;
        visited[startPos] = true;
        //cout << "Visited " << startPos << endl;
        startVal = perm[startPos];
        cycle = walk(startVal);
        res.push_back(cycle);
    }
    return res;
}

void print(vector<vector<int> > walks){
    int l = walks.size();
    cout << l << endl;
    for(int i = 0; i < l; i++){
        int subLen = walks[i].size();
        for(int j = 0; j < subLen; j++){
            cout << walks[i][j];
            if(j<subLen-1) cout << " ";
        }
        cout << endl;
    }
}

int main(){
    int n, temp;
    cin >> n;
    init(n);
    for(int i = 0; i < n; i++){
        cin >> temp;
        perm.push_back(temp);
    }
    cycles = findCycles(n);
    print(cycles);
}
