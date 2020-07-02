#include<iostream>
#include<vector>

using namespace std;

struct date{
    int day, month, year;
};

int cmp(date d1, date d2){
    if(d1.year < d2.year) return -1;
    if(d2.year < d1.year) return 1;
    if(d1.month < d2.month) return -1;
    if(d2.month < d1.month) return 1;
    if(d1.day < d2.day) return -1;
    if(d2.day < d1.day) return 1;
    return 0;
}

date nextDate(date d){
    if(d.day<28) d.day++;
    else if(d.day==29){
        if(d.month==2){
            d.day = 1;
            d.month++;
        }
        else d.day++;
    }
    else if(d.day==30){
        if(d.month== 4 || d.month== 6 || d.month== 9 || d.month== 11){
            d.day = 1;
            d.month++;
        }
        else d.day++;
    }
    else{
        d.day = 1;
        if(d.month == 12){
            d.month = 1;
            d.year++;
        }
        else d.month++;
    }
    return d;
}

int daysBtw(date beg, date en){
    int d = 0;
    date i = beg;
    while(cmp(i, en) <= 0){
        d++;
        i = nextDate(i);
    }
    return d;
}

int findDay(date d){
    date refr;
    refr.day = 1;
    refr.month = 1;
    refr.year = 2017;
    int numDays;
    if(cmp(refr, d) <= 0) numDays = daysBtw(refr, d);
    else numDays = daysBtw(d, refr);
    return ((numDays-1) % 7);

}

vector<int> calcWeekDays(date beg, date en){
    vector<int> res;
    int startDay = findDay(beg), numDays = daysBtw(beg, en);
    for(int i = 0; i < 7; i++) res.push_back(numDays/7);
    for(int i = startDay; i < startDay + (numDays%7); i++) res[i]++;
    return res;
}

int main(){
    date d1, d2;
    vector<int> days;
    cin >> d1.day >> d1.month >> d1.year;
    cin >> d2.day >> d2.month >> d2.year;
    days = calcWeekDays(d1, d2);
    for(auto i : days) cout << i << " ";
}
