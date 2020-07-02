#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int> > xco, yco;
vector<int> sortedInt;

int CeilIndex(std::vector<int>& v, int l, int r, double key) { 
    while (r - l > 1) { 
        int m = l + (r - l) / 2; 
        if (v[m] >= key) 
            r = m; 
        else
            l = m; 
    } 
    return r; 
} 
  
int LISLength(std::vector<int>& v) { 
    if (v.size() == 0) 
        return 0; 
  
    std::vector<int> tail(v.size(), 0); 
    int length = 1; 
  
    tail[0] = v[0]; 
    for (size_t i = 1; i < v.size(); i++) { 
  
        if (v[i] < tail[0]) 
            tail[0] = v[i]; 
  
        else if (v[i] > tail[length - 1]) 
            tail[length++] = v[i]; 
  
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i]; 
    } 
  
    return length; 
} 

int main(){
    int n, a, b, c, d, y0, y1;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c >> d;
        if(i == 0) y0 = b;
        if(i == 1) y1 = b;
        xco.emplace_back(a, c);
        yco.emplace_back(b, d);
    }
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    if(y0 == y1){
        sort(yco.begin(), yco.end());
        for(auto p: yco) sortedInt.push_back(p.second);
    }
    else{
        sort(xco.begin(), xco.end());
        for(auto p: xco) sortedInt.push_back(p.second);
    }
    cout << LISLength(sortedInt) << endl;
}