#include<bits/stdc++.h>

using namespace std;

const long double INF = 400, pi = 3.1415926535, eps = 0.00000001;

double dist(int x1, int y1, int x2, int y2){
    return abs(x2 * y1 - x1 * y2) / sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1));
}

long double calcY(long double x1, long double x, long double y, long double r){
    long double y1, y2, m1, m2, m3, m4;
    y1 = sqrt(r*r - x1*x1);
    m1 = (y - y1) / (x - x1);
    m2 = y / x;
    y2 = -sqrt(r*r - x1*x1);
    m3 = (y - y2) / (x - x1);
    m4 = y / x;
    if(abs(m1 * m2 + 1) <= abs(m3 * m4 + 1)) return y1;
    return y2; 
}

vector<pair<long double, long double> > tangents(long double a, long double b, long double c){
    long long x = a, y = b, r = c;
    vector<pair<long double, long double> > res;
    long double m, u, x1, y1, x2, y2;
    m = x*x + y*y;
    u = sqrt(r*r * y*y *(m - r*r));
    x1 = (r*r * x - u) / m;
    y1 = calcY(x1, a, b, c);
    //long double y1 = y*(r*r*r*r * (y*y - x*x) + r*r * x * (2 * u + x*x*x + x * y*y)) / (m * (x * u + r*r * y*y));
    x2 = (r*r * x + u) / m;
    if(x2 == x1) y2 = -y1;
    else y2 = calcY(x2, a, b, c);
    //long double y2 = y*(r*r*r*r * (y*y - x*x) + r*r * x * (-2 * u + x*x*x + x * y*y)) / (m * (-x * u + r*r * y*y));
    res.emplace_back(x1, y1);
    res.emplace_back(x2, y2);
    return res;
}

long double angle(long double x, long double y, long double r){
    long double theta = asin(abs(y) / r);
    if(x >= 0 && y >= 0) return theta;
    else if(x <= 0 && y >= 0) return pi - theta;
    else if(x <= 0 && y <= 0) return pi + theta;
    else return 2*pi - theta; 
}

long double circleDist(long double a1, long double a2, long double r){
    long double a = abs(a1 - a2);
    a = min(a, 2 * pi - a);
    return r * a;
}

long double linearDist(long double x1, long double y1, long double x2, long double y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

long double func(long double a, long double x1, long double y1, long double x2, long double y2, long double r){ 
    long double x, y;
    x = r * cos(a);
    y = r * sin(a);
    return linearDist(x, y, x1, y1) + linearDist(x, y, x2, y2);
}


long double ts(long double start, long double end, long double x1, long double y1, long double x2, long double y2, long double rr){
    long double l = start, r = end;

    for(int i=0; i<200; i++) {
      long double l1 = (l*2+r)/3;
      long double l2 = (l+2*r)/3;
      //cout<<l1<<" "<<l2<<endl;
      if(func(l1, x1, y1, x2, y2, rr) > func(l2, x1, y1, x2, y2, rr)) r = l2; else l = l1;
      }

     long double x = l;
    return func(x, x1, y1, x2, y2, rr);
}

long double closePoint(long double x1, long double y1, long double x2, long double y2, long double r){
    long double x3, y3, den, a1, a2, a;
    /*
    den = sqrt(x1*x1 - 2 * x1 * x2 + x2*x2 + (y1 - y2)*(y1 - y2));
    x3 = (r * (y2 - y1)) / den;
    y3 = (r * (x2 - x1)) / den;
    x4 = (r * (y1 - y2)) / den;
    y4 = (r * (x1 - x2)) / den;
    */
    a1 = angle(x1, y1, sqrt(x1*x1 + y1*y1));
    a2 = angle(x2, y2, sqrt(x2*x2 + y2*y2));
    
    return ts(a1, a2, x1, y1, x2, y2, r);
}

int main(){
    cout << setprecision(6) << fixed;
    long double x1, y1, x2, y2, r;
    cin >> x1 >> y1 >> x2 >> y2 >> r;
    if(x1 == x2 && y1 == y2){
        cout << (linearDist(x1, y1, 0, 0) - r) * 2 << endl;
        return 0;
    }
    long double d = dist(x1, y1, x2, y2);
    if(d < r){
        vector<pair<long double, long double> > t1 = tangents(x1, y1, r);
        vector<pair<long double, long double> > t2 = tangents(x2, y2, r);
        long double res = INF;
        for(auto& p1: t1){
            for(auto& p2: t2){
                long double a1 = angle(p1. first, p1.second, r); 
                long double a2 = angle(p2. first, p2.second, r);
                long double cd = circleDist(a1, a2, r);
                long double ld1 = linearDist(x1, y1, p1.first, p1.second);
                long double ld2 = linearDist(x2, y2, p2.first, p2.second);
                res = min(res, ld1 + cd + ld2);
            }
        }
        cout << res << endl;
    }
    else{
        cout << closePoint(x1, y1, x2, y2, r) << endl; 
    }
}