#include<iostream>

using namespace std;

struct point{
    int x, y;
};

struct snake{
    point from, to;
};

void input(snake *s){
    cin >> s->from.x >> s->from.y >> s->to.x >> s->to.y;
}

int main(){
    int t;
    snake s1, s2;
    cin >>t;
    for(; t; t--){
        input(&s1);
        input(&s2);
        cout << s1.from.x;
    }
}
