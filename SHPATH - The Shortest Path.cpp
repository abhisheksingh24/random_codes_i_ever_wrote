#include<iostream>
#include<string>
#include<map>
#include<set>
#include<queue>

using namespace std;

int index;

struct city{
    int ind;
    int cost;
};

 bool compare(city c){
    return c.ind==index;
}

map<string, int> index;
multiset<city> dest;
vector<city> links[10001];
bool visited[10001];

#define MAX 20001

void init(int n, int s){
    city c;
    c.cost = MAX;
    for(int i = 1; i <= n; i++){
        visited[i] =false;
        c.ind = i;
        dest.insert(c);
    }
    c.ind = s;
    c.cost = 0;
    dest.insert(c);
}

int minCost(int n){
    multiset<city>::iterator it;
    for(auto c: dest){
        if(!visited[c.ind] && c.cost < MAX) return c.ind;
    }
    return -1;
}

int solve(int s, int d, int n){
    multiset<city>::iterator it;
    init(n, s);
    while(true){
        int x = minCost(s);
        if(x==-1) return cost[d];
        visited[x] = true;
        for(city c: links[x]){
            if(!visited[c.ind]){
                index = c.ind;
                it = find_if(dest.begin(), dest.end(), compare);
                city temp = *it;
                dest.erase(it);
                if(temp.cost > )
            }
        }
    }

}

int main(){
    int s, n, p, nr, r, c, sourceInd, destInd;
    neighbor n1, n2;
    string name, frm, to;
    cin >> s;
    while(s--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> name;
            index[name] = i;
            cin >> p;
            while(p--){
                cin >> nr >> c;
                n1.ind = nr; n2.ind = i;
                n1.cost = n2.cost = c;
                links[i].insert(n1);
                links[nr].insert(n2);
            }
        }
        cin >> r;
        while(r--){
            cin >> frm >> to;
            sourceInd = index[frm];
            destInd = index[to];
            init(n);
            cout << solve(sourceInd, destInd) << endl;
        }
    }
}
