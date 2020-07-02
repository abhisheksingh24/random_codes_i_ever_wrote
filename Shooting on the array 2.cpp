#include<iostream>
#include<vector>
#include<set>

using namespace std;

#define itSet set<int, cmp>::iterator

vector<int> height, nextHigh;

struct cmp{
    bool operator()(int i, int j){
        if(height[i]==height[j]) return i<j;
        return height[i]<height[j];
    }
};

set<int, cmp> targetLess;
vector<set<int, cmp> > previous;

void init(int n){
    height.clear();
    height.resize(n+1);
    nextHigh.clear();
    nextHigh.resize(n+1);
    previous.clear();
    previous.resize(n+1);
    for(int i = 0; i <= n; i++) nextHigh[i] = -1;
}

void increment(int ind, int inc){
    itSet itr = targetLess.find(ind);
    height[ind]+=inc;
    if(itr!=targetLess.end()){
        //cout << "Found " << ind << endl;
        targetLess.erase(itr);
        targetLess.insert(ind);
    }
    for(itSet it = targetLess.begin(); it!=targetLess.end();){
        //cout << "checking " << *it << endl;
        if(height[*it] >= height[ind]) break;
        if(*it >= ind){
            ++it;
            continue;
        }
        nextHigh[*it] = ind;
        previous[ind].insert(*it);
        it = targetLess.erase(it);
    }
    for(int cur = nextHigh[ind]; cur!=-1; cur = nextHigh[cur]){
        for(itSet it = previous[cur].begin(); it!=previous[cur].end();){
            if(height[*it] >= height[ind]) break;
            if(*it >= ind){
                ++it;
                continue;
            }
            nextHigh[*it] = ind;
            previous[ind].insert(*it);
            it = previous[cur].erase(it);
        }
        if(height[cur] > height[ind]){
            nextHigh[ind] = cur;
            break;
        }
        if(nextHigh[cur]==-1) nextHigh[ind] = -1;
    }
}

int print(int ind, int l, int r){
    int cnt = 0;
    for(int cur = ind; cur!=-1; cur = nextHigh[cur]){
        if(height[cur]>=l){
            cnt++;
            //cout << "Hit #" << cnt << " @ segment#"<<cur<<endl;
        }
        if(height[cur]>=r) break;
    }
    return cnt;
}

void test(int n){
    for(int i = 1; i <= n; i++){
        int cur;
        for(cur = i; cur!=-1; ){
            cout << cur << " -> ";
            cur = nextHigh[cur];
        }
        cout << endl;
    }
}

int main(){
    int t, q, n, l, r, ind, inc;
    char type;
    cin >> t;
    while(t--){
        cin >> n >> q;
        init(n);
        for(int i = 1; i <= n; i++){
            cin >> height[i];
            //cout << "input successfull\n";
            for(itSet it = targetLess.begin(); it!=targetLess.end();){
                //cout << "inside loop\n";
                if(height[*it] >= height[i]) break;
                //cout << "line 1 done\n";
                nextHigh[*it] = i;
                //cout << "line 2 done\n";
                previous[i].insert(*it);
                //cout << "line 3 done\n";
                //cout << "trying to delete\n";
                it = targetLess.erase(it);
                //cout << "deleted\n";
            }
            targetLess.insert(i);
        }
        //cout << "Initial\n";
        //test(n);
        while(q--){
            cin >> type;
            switch(type){
            case '+':
                cin >> ind >> inc;
                //cout << "Changing\n";
                increment(ind, inc);
                //test(n);
                break;
            case '?':
                cin >> ind >> l >> r;
                //cout << "input success, printitng result\n";
                cout << print(ind, l, r) << endl;
                break;
            }
        }
    }
}
