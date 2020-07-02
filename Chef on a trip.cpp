#include<iostream>
#include<string>
#include<map>
#include<set>

using namespace std;

map<string, int> index;
pair<string, string> srctgt[10000];
set<string> sources;

int main(){
    int t, n, ind = 0;
    string src, dst;
    pair<string, string> temp;
    set<string>::iterator it;
    cin >> t;
    while(t--){
        cin >> n;
        for(int z = 0; z < n; z++){
            cin >> src >> dst;
            temp.first = src;
            temp.second = dst;
            srctgt[ind] = temp;
            index[src] = ind++;
        }
        for(int i = 0; i < ind; i++){
            sources.insert(srctgt[i].first);
            it = sources.find(srctgt[i].second);
            if(it!=sources.end()) sources.erase(it);
        }
        int x = index[*sources.begin()];
        for(int i = 0; i < n-1; i++){
            cout << srctgt[x].first << "-" << srctgt[x].second << " ";
            x = index.at(srctgt[x].second);
        }
        cout << srctgt[x].first << "-" << srctgt[x].second << " ";
        cout << endl;
    }

}

