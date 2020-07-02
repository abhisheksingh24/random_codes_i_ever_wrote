#include<iostream>
#include<vector>

using namespace std;

vector<int> times, speed;
int first;

struct tym{
    int num = 0, den = 1;
};

tym fw[1000000], bw[1000000];

struct downloadInfo{
    int last, mbLeft;
    tym t;
};

long long hcf(long long a, long long b){
    if (a == 0) return b;
    return hcf(b%a, a);
}

tym addTime(tym a, tym b){
    //cout << "Adding "<<a.num <<"/"<<a.den<<" amd "<<b.num<<"/"<<b.den<<endl;
    long long NUM, DEN = a.den;
    DEN*=b.den;
    //cout << "denominator calculated as : "<< DEN << endl;
    NUM = a.num*(DEN/a.den) + b.num*(DEN/b.den);
    //cout << "numerator and denominator calculated\n";
    tym res;
    long long h = hcf(min(NUM, DEN), max(NUM,DEN));
    NUM/=h; DEN/=h;
    res.num = NUM; res.den = DEN;
    return res;
}

bool isLess(tym a, tym b){
    long long NUM1, NUM2, DEN = a.den;
    DEN*=b.den;
    NUM1 = a.num*(DEN/a.den);
    NUM2 = b.num*(DEN/b.den);
    return NUM1 < NUM2;
}

tym calcTime(int mb, int speed){
    tym res;
    if(speed == 0) {
        res.num = 0;
        res.den = 1;
        return res;
    }
    long long NUM = mb, DEN = speed;
    long long h = hcf(min(NUM, DEN), max(NUM,DEN));
    NUM/=h; DEN/=h;
    res.num = NUM; res.den = DEN;
    //cout << "Calculated tTime : " << res.num << "/" << res.den << endl;
    return res;
}

void printTime(tym t){
    cout << t.num << "/" << t.den << endl;
}

downloadInfo download(int start, int mb, int n, tym spent){
    //cout << "downloading "<<mb <<" mb " << "starting at " << start << " time spent = ";printTime(spent); cout << endl;
    //cout << "start = " << start << endl;
    downloadInfo temp;
    if(start == n-1) {
            //cout << "start reached n\n";
        temp.last = start;
        temp.mbLeft = mb;
        temp.t = spent;
        return temp;
    }
    int downloadable = speed[start]*(times[start+1]-times[start]);
    //cout << "downloadable calculated\n";
    if(downloadable >= mb){
        temp.last = start;
        temp.mbLeft = mb;
        temp.t = spent;
        return temp;
    }
    tym taken;
    taken.num = times[start+1] - times[start];
    taken.den = 1;
    return download(start+1, mb-downloadable, n, addTime(spent,taken));
}

downloadInfo downloadReverse(int end, int mb, tym spent){
    //cout << "downloading " <<mb<< " mb "<<"ending at "<<end << "time spent = "; printTime(spent);cout<< endl;
    downloadInfo temp;
    int downloadable = speed[end-1]*(times[end]-times[end-1]);
    if(downloadable >= mb){
        temp.last = end;
        temp.mbLeft = mb;
        temp.t = spent;
        return temp;
    }
    tym taken;
    taken.num = times[end] - times[end-1];
    taken.den = 1;
    return downloadReverse(end-1, mb-downloadable, addTime(spent, taken));
}

void fillBW(int mb, int n){
    tym temp;
    downloadInfo info;
    info.last = n-1; info.mbLeft = mb;
    for(int i = n-1; i >= first; i--){
        info = downloadReverse(info.last, info.mbLeft, info.t);
        bw[i] = addTime(info.t, calcTime(info.mbLeft, speed[info.last-1]));
        //cout << "bw " << i << " = "; printTime(bw[i]); cout << endl;
        if(i>first){
            int downloadable = speed[i-1]*(times[i]-times[i-1]);
            if(info.last < i){
                info.mbLeft+=downloadable;
                temp.num = times[i-1] - times[i];
                info.t = addTime(info.t, temp);
            }
        }
    }
}

void fillFW(int mb, int n){
    tym temp;
    downloadInfo info;
    info.last = 0; info.mbLeft = mb;
    for(int i = 0; i < n; i++){
        //cout << "i = " << i << endl;
        info = download(info.last, info.mbLeft, n, info.t);
        if(i==0) first = info.last + 1;
        fw[i] = addTime(info.t, calcTime(info.mbLeft, speed[info.last]));
        //cout << "fw " << i << " = "; printTime(fw[i]); cout << endl;
        if(i<n-1){
            int downloadable = speed[i]*(times[i+1]-times[i]);
            if(info.last > i){
                info.mbLeft+=downloadable;
                temp.num = times[i] - times[i+1];
                info.t = addTime(info.t, temp);
            }
            //cout << "time reduced to "; printTime(info.t); cout << endl;
        }
    }
}

tym minTime(int n){
    tym minT = fw[0];
    for(int i = 1; i < n; i++){
        if(isLess(fw[i], minT)) minT = fw[i];
    }
    for(int i = first; i < n; i++){
        if(isLess(bw[i], minT)) minT = bw[i];
    }
    return minT;
}

int main(){
    int n, s, temp1, temp2;
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> temp1 >> temp2;
        times.push_back(temp1);
        speed.push_back(temp2);
    }
    while(speed[n-1]==0) n--;
    fillFW(s, n);
    //cout << "filled FW\n";
    fillBW(s, n);

    printTime(minTime(n));
}
