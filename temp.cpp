

void sieve(int n){
    
}

bool bSearch(vector<int> valid, int x, int l, int r){
    int m = l + (r-l)/2;
    if(valid[m] == x) return true;
    if(valid[m] < x) return bSearch(valid, x, m + 1, r);
    return bSearch(valid, x, l, m - 1);
}

int blah(int l, int r){
    vector<bool> power(5e6 + 1, false);
    power[0] = power[1] = true;
    for(int i = 2; i <= 5e6; i++){
        for(long long j = i*i; j <= 5e6; j *= i) power[j] = true;
    }
    vector<int> valid;
    for(int i  =0; i <= 5e6; i++) if(power[i]) valid.push_back(i);
    int n = valid.size();
    int res = 0;
    
    for(int x = l; x < r; x++){
        for(int i = 0; i < n; i++){
            if(valid[i] > x) break;
            if(bSearch(valid, x - valid[i], 0, n - 1)){
                res++;
                break;
            }
        }
    }
    return res;
}