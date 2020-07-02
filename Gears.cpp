#include<iostream>
#include<vector>

using namespace std;

vector<int> teeth, root, parent, offset, siz;
vector<bool> blocked;
vector<vector<int> > children;

void init(int n){
    teeth.resize(n);
    root.resize(n);
    parent.resize(n);
    offset.resize(n);
    blocked.resize(n);
    siz.resize(n);
    children.resize(n);
    for(int i = 0; i < n; i++){
        root[i] = parent[i] = offset[i] = -1;
        siz[i] = 0;
        blocked[i] = false;
    }
}
/*
int root(int i){
    if(parentAr[i]==-1) return -1;
    if(parentAr[i]==i) rootAr[i] = i;
    else if(rootAr[i]==-1){
        rootAr[i] = root(parentAr[i]);
    }
    else rootAr[i] = root(rootAr[i]);
    return rootAr[i];
}

int offset(int i){
    if(parentAr[i]==-1) return -1;
    rootAr[i] = root(i);
    if(rootAr[i]==i) return 0;

}*/

void updateParent(int cur, int newParent){
    parent[cur] = newParent;

    root[cur] = root[parent[cur]];
    offset[cur] = 1 + offset[parent[cur]];
    for(auto it = children[cur].begin(); it != children[cur].end(); ){
        if(*it == newParent) it = children[cur].erase(it);
        else{
            updateParent(*it, cur);
            ++it;
        }
    }
}

void connect(int x, int y){
    int r1 = root[x];
    int r2 = root[y];
    if(r1==-1 && r2==-1){
        parent[y] = root[y] = x;
        parent[x] = root[x] = x;
        children[x].push_back(y);
        offset[x] = 0;
        offset[y] = 1;
        siz[x] = 2;
    }
    else if(r1==r2){
        int o1 = offset[x];
        int o2 = offset[y];
        if((o1+o2) % 2 == 0) blocked[r1] = true;
    }
    else if(r1==-1){
        parent[x] = y;
        children[y].push_back(x);
        root[x] = root[y];
        offset[x] = offset[y] + 1;
        siz[root[y]]++;
    }
    else if(r2==-1){
        parent[y] = x;
        children[x].push_back(y);
        root[y] = root[x];
        offset[y] = offset[x] + 1;
        siz[root[x]]++;
    }
    else{
        int cur, curParent;
        if(siz[r1] < siz[r2]){
            cur = x;
            curParent = y;
            siz[r2]+=siz[r1];
        }
        else{
            cur = y;
            curParent = x;
            siz[r1]+=siz[r2];
        }
        while(curParent != cur){
            int next = parent[cur];
            children[curParent].push_back(cur);
            updateParent(cur, curParent);
            curParent = cur;
            cur = next;
        }
    }
}

long long gcd(long long a, long long b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

void printSpeed(int x, int y, int v){
    int r1 = root[x];
    int r2 = root[y];
    //cout <<"below\n";
    if(r1==-1 || r2==-1 || r1!=r2 || blocked[r1]){
        cout << 0 << endl;
        return;
    }
    //cout << "above\n";
    long long num = v;
    int o1 = offset[x];
    int o2 = offset[y];
    int m;
    if((o1+o2) % 2 == 0) m = 1;
    else m = -1;
    num*=teeth[x];
    long long den = teeth[y];
    long long g = gcd(num, den);
    num/=g;
    den/=g;
    num*=m;
    cout << num << "/" << den << endl;
}

int main(){
    int n, m, t, x, y, c, v;
    cin >> n >> m;
    init(n);
    for(int i = 0; i < n; i++) cin >> teeth[i];
    for(int i = 0; i < m; i++){
        cin >> t;
        if(t==1){
            cin >> x >> c;
            teeth[x-1] = c;
        }
        else if(t==2){
            cin >> x >> y;
            connect(x-1, y-1);
        }
        else{
            cin >> x >> y >> v;
            printSpeed(x-1, y-1, v);
        }
    }
}
