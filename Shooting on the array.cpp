#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<int> height, nextSeg;
vector<set<int> > nextTo;
set<int> targetLess;

void init(int n){
    height.clear();
    nextSeg.clear();
    nextSeg.resize(n+1);
    for(int i = 0; i <= n; i++){
        nextSeg[i] = -1;
    }
    nextTo.clear();
    nextTo.resize(n+1);
    height.resize(n+1);
}

void increment(int i, int x){
    height[i]+=x;
    int cur = i;
    while(true){
        cur = nextSeg[cur];
        if(cur==-1){
            nextSeg[i] = -1;
            break;
        }
        vector<int> toErase;
        for(int ind: nextTo[cur]){
            if(height[ind] < height[i]){
                nextSeg[ind] = i;
                toErase.push_back(ind);
                nextTo[i].insert(ind);
            }
            for(int ind: toErase) nextTo[ind].erase(ind);
        }
        if(height[i] < height[cur]){
            nextSeg[i] = cur;
            nextTo[cur].insert(i);
        }
    }
    vector<int> toErase;
    for(int ind: targetLess){
        if(height[ind]<height[i]){
            nextSeg[ind] = i;
            nextTo[i].insert(ind);
            toErase.push_back(ind);
        }
    }
    for(int ind: toErase) targetLess.erase(ind);
}

int print(int i, int l, int r){
    int cnt = 0, cur = i;
    while(cur!=-1 && height[cur]<=r){
        if(height[cur] >= l){
            cnt++;
            //cout << "Hit #" << cnt << " at index " << cur << " with height " << height[cur] << endl;
        }
        cur = nextSeg[cur];
    }
    return cnt;
}

void test(int n){
    for(int i = 1; i <= n; i++){
        int cur;
        for(cur = i; cur!=-1; ){
            cout << cur << " -> ";
            cur = nextSeg[cur];
        }
        cout << endl;
    }
}

int main(){
    int t, n, q, ind, inc, l, r;
    char type;
    cin >> t;
    while(t--){
        cin >> n >> q;
        init(n);
        for(int i = 1; i <= n; i++){
            //cout << "Inputting element #" << i << endl;
            cin >> height[i];
            set<int> toErase;
            for(int ind: targetLess){
                //cout << "Targetting " << ind << endl;
                if(height[ind] < height[i]){
                    nextSeg[ind] = i;
                    nextTo[i].insert(ind);
                    toErase.insert(ind);
                }
            }
            for(int ind: toErase){
                targetLess.erase(ind);
            }
            targetLess.insert(i);
        }
        //test(n);
        while(q--){
            cin >> type;
            switch(type){
            case '+':
                cin >> ind >> inc;
                increment(ind, inc);
                //test(n);
                break;
            case '?':
                cin >> ind >> l >> r;
                cout << print(ind, l , r) << endl;
                break;
            }
        }
    }
}
