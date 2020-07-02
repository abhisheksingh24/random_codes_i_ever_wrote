#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

void sortSeparately(vector<int>& a, vector<int>& b, int n){
    b.clear();
    b.resize(n);
    for(int i = 0; i < n; i++) b[i] = a[i];
    sort(b.begin(), b.end());
}

void setRanks(vector<int>& r, vector<int>& s, int n){
    r.clear();
    r.resize(n);
    r[0] = 1;
    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1]) r[i] = r[i-1];
        else r[i] = r[i-1] + 1;
    }
}

void fillIndices(vector<int>& ind, vector<int>& original, vector<int>& s, int n){
    vector<bool> filled;
    filled.resize(n);
    ind.clear();
    ind.resize(n);
    for(int i = 0; i < n; i++) filled[i] = false;
    for(int i = 0; i < n; i++){
        int low = lower_bound(s.begin(), s.end(), original[i]) - s.begin();
        while(filled[low]) low++;
        ind[low] = i;
        filled[low] = true;
    }
}

int insertMultiple(vector<int>& toBe, vector<set<int> >& already, int k, int siz){
    vector<int> insertHere;
    for(int ind : toBe){
        for(int i = siz-1; ; i--){
            if(i < 0){
                insertHere.push_back(0);
                break;
            }
            auto low = lower_bound(already[i].begin(), already[i].end(), ind-k);
            if((*low) >= ind-k && (*low) <= ind+k){
                insertHere.push_back(i+1);
                break;
            }
        }
    }
    int l = insertHere.size();
    for(int i = 0; i < l; i++){
        int ind = insertHere[i];
        if(ind < siz) already[ind].insert(toBe[i]);
        else{
            set<int> temp;
            temp.insert(toBe[i]);
            already.push_back(temp);
            siz++;
        }
    }
    return siz;
}

long long calcSum(vector<int>& original, vector<int>& index, int k, int n){
    vector<set<int> > inserted;
    int siz = 0;
    for(int i = 0; i < n; ){
        vector<int> toBeInserted;
        toBeInserted.push_back(index[i]);
        int j = i+1;
        for( ; j < n && original[index[j]] == original[index[i]]; j++){
            toBeInserted.push_back(index[j]);
        }
        siz = insertMultiple(toBeInserted, inserted, k, siz);
        i = j;
    }
    long long sum = 0;
    for(int i = 0; i < siz; i++){
        sum += (inserted[i].size() * (long long)(i+1));
    }
    return sum;
}

int solve(vector<int>& original, vector<int>& sorted, vector<int>& index, long long sum, int siz, int l, int r){
    //cout << l << " to " << r << endl;
    if(l > r) return 0;
    if(l == r) return l+1;
    int k = l + (r-l+1)/2;
    long long s = calcSum(original, index, k, siz);
    if(s <= sum) return solve(original, sorted, index, sum, siz, k, r);
    else return solve(original, sorted, index, sum, siz, l, k-1);
}

int main(){
    int t, n;
    long long s;
    vector<int> A, sorted, ranks, index;
    cin >> t;
    while(t--){
        A.clear();
        cin >> n >> s;
        A.resize(n);
        for(int i = 0; i < n; i++) cin >> A[i];
        sortSeparately(A, sorted, n);
        setRanks(ranks, sorted, n);
        fillIndices(index, A, sorted, n);
        //for(int i: sorted) cout << i << " "; cout << endl;
        //for(int i: ranks) cout << i << " "; cout << endl;
        //for(int i: index) cout << i << " "; cout << endl;
        cout << solve(A, sorted, index, s, n, 0, n-1) << endl;
    }
}

