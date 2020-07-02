#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> minSalary, maxOffers, offeredSalary, offers;
bool qual[1000][1000];
int selections[1000];

struct result{
    int numCand = 0, numComp = 0;
    long long sumSalary = 0;
};

void init(int n, int m){
    minSalary.clear();
    minSalary.resize(n);
    maxOffers.clear();
    maxOffers.resize(m);
    offeredSalary.clear();
    offeredSalary.resize(m);
    offers.clear();
    offers.resize(m);
    for(int i = 0; i < m; i++) selections[i] = 0;
}

int chooseCompany(int s, int m){
    int maxSalary = 0, choosen = -1;
    for(int i = 0; i < m; i++){
        if(qual[s][i] && offeredSalary[i] >= minSalary[s] && selections[i] < maxOffers[i] && offeredSalary[i] > maxSalary){
            maxSalary = offeredSalary[i];
            choosen = i;
        }
    }
    if(choosen==-1) return -1;
    return choosen;
}

result calcRes(int n, int m){
    result res;
    int c;
    for(int stu = 0; stu < n; stu++){
        c = chooseCompany(stu, m);
        if(c!=-1){
            res.numCand++;
            res.sumSalary+=offeredSalary[c];
            selections[c]++;
        }
    }
    for(int i = 0; i < m; i++){
        if(!selections[i]) res.numComp++;
    }
    return res;
}

void print(result r){
    cout << r.numCand << " " << r.sumSalary << " " << r.numComp << endl;
}

int main(){
    int t, n, m;
    string bin;
    cin >> t;
    while(t--){
        cin >> n >> m;
        init(n, m);
        for(int i = 0; i < n; i++) cin >> minSalary[i];
        for(int i = 0; i < m; i++) cin >> offeredSalary[i] >> maxOffers[i];
        for(int i = 0; i < n; i++){
            cin >> bin;
            for(int j = 0; j < m; j++){
                qual[i][j] = (bool)(bin[j]-'0');
            }
        }
        result res = calcRes(n, m);
        print(res);
    }
}
