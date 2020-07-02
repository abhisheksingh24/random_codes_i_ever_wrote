#include<bits/stdc++.h>

using namespace std;

int main(){
    ofstream fout("input.txt");
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 5);
    fout << 1000 << endl;
    for(int i = 0; i < 1000; i++){
        fout << 10 << endl;
        for(int j = 0; j < 10; j++){
            fout << dist(rng);
            if(j != 9) fout << " ";
        }
        fout << endl;
    }
}