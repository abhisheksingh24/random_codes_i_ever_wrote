#include<iostream>
#include<vector>

using namespace std;

vector<int> seq;

struct data{
    int alt, len1, len3;
    void init(){
        alt = len1 = len3 = 0;
    }
    void print(){
        cout << alt << " " << len1 << " " << len3 << endl;
    }
}result;

bool isAlternate(int ind){
    if(ind==0) return true;
    if(seq[ind] == 1 && seq[ind-1] == 3) return true;
    if(seq[ind] == 3 && seq[ind-1] == 1) return true;
    return false;
}

bool isOpening(int ind){
    return (seq[ind]==1 || seq[ind]==3);
}

void compute(int n){
    data current;
    current.init();
    result.init();
    int depth1 = 0, depth3 = 0;
    for(int i = 0; i < n; i++){
        if(seq[i] == 1){
            depth1++;
        }
        if(depth1 > 0) current.len1++;
        if(seq[i] == 2){
            depth1--;
            if(depth1==0){
                result.len1 = max(result.len1, current.len1);
                current.len1 = 0;
            }
        }
        if(seq[i] == 3){
            depth3++;
        }
        if(depth3 > 0) current.len3++;
        if(seq[i] == 4){
            depth3--;
            if(depth3==0){
                result.len3 = max(result.len3, current.len3);
                current.len3 = 0;
            }
        }
        if((current.alt == 0 && isOpening(i)) || isAlternate(i)) current.alt++;
        else if(!isOpening(i)){
            result.alt = max(result.alt, current.alt);
            current.alt = 0;
        }
    }
}

int main(){
    int n, temp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        seq.push_back(temp);
    }
    compute(n);
    result.print();
}
