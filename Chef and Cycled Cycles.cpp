#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int n;
vector<vector<int> > firstToNode;
vector<pair<int, int> > firstAndLast;
vector<int> firstToLastNode, firstToCycle, toNextCycle;

void init(int n){
    firstToNode.clear();
    firstToNode.resize(n+2);
    firstAndLast.clear();
    firstAndLast.resize(n+1);
    firstToCycle.clear();
    firstToCycle.resize(n+2);
    toNextCycle.clear();
    toNextCycle.resize(n+1);
    firstToLastNode.clear();
    firstToLastNode.resize(n+1);
}

int findShortest(int c, int i, int j){
    //cout << "Finding Shirtest path\n";
    //cout << "j. " << firstToNode[c][j] << endl;
    //cout << "i. " << firstToNode[c][i] << endl;
    //cout << "n. " << firstToNode[c][n] << endl;
    int res1, res2, res;
    res1 = firstToNode[c][j] - firstToNode[c][i];
    //cout << "res1 = " << res1 << endl;
    res2 = firstToNode[c].back() - firstToNode[c][j] + firstToNode[c][i];
    //cout << "res2 = " << res2 << endl;
    res = min(res1, res2);
    //cout << "Returning " << min(res1, res2) << endl;
    return res;
}

int solve(int v1, int c1, int v2, int c2){
    int res1, res2;
    res1 = findShortest(c1, min(v1, firstAndLast[c1].second), max(v1, firstAndLast[c1].second)) + (firstToCycle[c2] - firstToCycle[c1] - firstToLastNode[c1]) + findShortest(c2, min(firstAndLast[c2].first, v2), max(firstAndLast[c2].first, v2));
    //cout << "Path 1 :" << res1 << endl;
    res2 = findShortest(c2, min(v2, firstAndLast[c2].second), max(v2, firstAndLast[c2].second)) + (firstToCycle.back() - firstToCycle[c2] - firstToLastNode[c2] + firstToLastNode[1] + firstToCycle[c1]) + findShortest(c1, min(firstAndLast[c1].first, v1), max(firstAndLast[c1].first, v1));
    //cout << "Path 2 : " << res2 << endl;
    return min(res1, res2);
}

void print(){
    cout << "First and Last\n";
    for(int i = 1; i <= n; i++){
        cout << firstAndLast[i].first << " " << firstAndLast[i].second << endl;
    }
    cout << "To next cycle\n";
    for(int i = 1; i <= n; i++){
        cout << "From " << i << " to " << i%n+1 << " : " << toNextCycle[i] << endl;
    }
    cout << "First to Last\n";
    for(int i = 1; i <= n; i++){
        cout << "Cycle " << i << " : " << firstToLastNode[i] << endl;
    }
    cout << "First to Node\n";
    for(int i = 1; i <= n; i++){
        cout << "For cycle " << i << endl;
        for(int j = 1; j < firstToNode[i].size(); j++){
            cout << "to " << j%(firstToNode[i].size()-1) << " : " << firstToNode[i][j] << endl;
        }
    }
    cout << "Cycle to cycle\n";
    for(int i = 1; i <= n+1; i++){
        cout << "to " << i%(n+1) << " : " << firstToCycle[i] << endl;
    }
}

int main(){
    int t, q, m, weight, v1, v2, c1, c2;
    cin >> t;
    while(t--){
        cin >> n >> q;
        init(n);
        for(int i = 1; i <= n; i++){
            cin >> m;
            firstToNode[i].push_back(0);
            firstToNode[i].push_back(0);
            while(m--){
                cin >> weight;
                firstToNode[i].push_back(weight + firstToNode[i].back());
            }
        }
        //cout << "First loop over\n";
        firstToCycle[0] = 0;
        for(int i = 1; i <= n; i++){
            cin >> v1 >> v2 >> weight;
            firstAndLast[i].second = v1;
            firstAndLast[i%n+1].first = v2;
            toNextCycle[i] = weight;
        }
        //cout << "Second loop over\n";
        for(int i = 1; i <= n; i++){
            //cout << "i = " << i << endl;
            firstToLastNode[i] = findShortest(i, min(firstAndLast[i].first, firstAndLast[i].second), max(firstAndLast[i].first, firstAndLast[i].second));
            //cout << i << " done\n";
        }
        firstToCycle[1] = -firstToLastNode[1];
        firstToCycle[2] = toNextCycle[1];
        //cout << "Third loop over\n";
        for(int i = 3; i <= n+1; i++){
            //cout << "i = " << i << endl;
            firstToCycle[i] = firstToCycle[i-1] + firstToLastNode[i-1] + toNextCycle[i-1];
        }
        //cout << "Fourth loop over\n";
        //print();
        while(q--){
            cin >> v1 >> c1 >> v2 >> c2;
            if(c1 < c2) cout << solve(v1, c1, v2, c2) << endl;
            else cout << solve(v2, c2, v1, c1) << endl;
        }
    }
}
