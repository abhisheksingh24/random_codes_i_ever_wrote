#include<bits/stdc++.h> 
using namespace std; 
  
const int MAX = 1000001; 
  
// structure to store queries 
struct Query 
{ 
    int l, r, idx; 
}; 
  
// cmp function to sort queries according to r 
bool cmp(Query x, Query y) 
{ 
    return x.r < y.r; 
} 
  
// updating the bit array 
void update(int idx, int val, int bit[], int n) 
{ 
    for (; idx <= n; idx += idx&-idx) 
        bit[idx] += val; 
} 
  
// querying the bit array 
int query(int idx, int bit[], int n) 
{ 
    int sum = 0; 
    for (; idx>0; idx-=idx&-idx) 
        sum += bit[idx]; 
    return sum; 
} 
  
void answeringQueries(int arr[], int n, Query queries[], int q) 
{ 
    cout << "ajay" << "\n";
    // initialising bit array 
    int bit[n+1]; 
    memset(bit, 0, sizeof(bit)); 
  
    // holds the rightmost index of any number 
    // as numbers of a[i] are less than or equal to 10^6 
    int last_visit[MAX]; 
    memset(last_visit, -1, sizeof(last_visit)); 
  
    // answer for each query 
    int ans[q]; 
    int query_counter = 0; 
    for (int i=0; i<n; i++) 
    { 
        // If last visit is not -1 update -1 at the 
        // idx equal to last_visit[arr[i]] 
        if (last_visit[arr[i]] !=-1) 
            update (last_visit[arr[i]] + 1, -1, bit, n); 
  
        // Setting last_visit[arr[i]] as i and updating 
        // the bit array accordingly 
        last_visit[arr[i]] = i; 
        update(i + 1, 1, bit, n); 
  
        // If i is equal to r of any query  store answer 
        // for that query in ans[] 
        while (query_counter < q && queries[query_counter].r == i) 
        { 
            ans[queries[query_counter].idx] = 
                     query(queries[query_counter].r + 1, bit, n)- 
                     query(queries[query_counter].l, bit, n); 
            query_counter++; 
        } 
    } 
  
    // print answer for each query 
    for (int i=0; i<q; i++) 
        cout << ans[i] << endl; 
}

int main(){
    int n;
    cin >> n;
    vector<string> v(n);
    for(auto& s: v) cin >> s;
    for(auto& s: v) sort(s.begin(), s.end());
    map<string, int> id;
    for(int i = 0; i < n; i++){
        if(!id.count(v[i])) id[v[i]] = i; 
    }
    int q;
    cin >> q;
    Query queries[q];
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        l--; r--;
        queries[i].l = l;
        queries[i].r = r;
        queries[i].idx = i;
    }
    sort(queries, queries+q, cmp);
    int a[n];
    for(int i = 0; i < n; i++) a[i] = id[v[i]];
    answeringQueries(a, n, queries, q);

}