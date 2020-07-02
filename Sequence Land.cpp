#include<iostream>
#include<set>

using namespace std;

set<int> id[300], prevRel, curRel;
bool looked[300];

void init(int n){
    for(int i = 0; i < n; i++){
        looked[i] = false;
    }
}

bool related(int i, int j, int k){
    int cnt = 0;
    for(int x : id[i]){
        if(id[j].find(x) != id[j].end()) cnt++;
        if(cnt>=k) return true;
    }
    //cout << i << " and " << j <<" not related\n";
    return false;
}

int main(){
    int n, k, p, temp, totRel = 0;
    cin >> n >> k;
    init(n);
    for(int i = 0; i < n; i++){
        cin >> p;
        for(int j = 0; j < p; j++){
            cin >> temp;
            id[i].insert(temp);
        }
    }
    for(int rel = 0; rel < n-1; rel++){
        if(rel==0){
            prevRel.insert(0);
            looked[0] = true;
        }
        if(prevRel.empty()) break;
        curRel.clear();

        /*
        cout << "Depth = " << rel << " Relatives = ";
        for(int i : prevRel) cout << i << " ";
        cout << endl;
        */

        for(int i = 0; i < n; i++){
            if(!looked[i]){
                for(int j : prevRel){
                    if(related(i,j,k)){
                        //cout << i << " and " << j << " related\n";
                        curRel.insert(i);
                        looked[i] = true;
                    }
                }
            }
        }
        totRel+=curRel.size();
        prevRel = curRel;

        /*
        cout << "Added Relatives : ";
        for(int i : curRel) cout << i << " ";
        cout << endl;
        cout << "Next Relatives : ";
        for(int i : prevRel) cout << i << " ";
        cout << endl;
        */
    }
    cout << totRel+1 << endl;
}
