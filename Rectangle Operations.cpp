#include<bits/stdc++.h>

using namespace std;


struct Point{
    int x, y;
};

struct Rect{
    Point leftTop, rightBot;
};

double getPerimeter(Rect* rect){
    //get lengths by the difference of X coordinates and Y coordinates respectively
    //following lines of code are redundant
    //so its better to put them into a separate function
    //I was not sure if I'm allowed to use user made functions so I wrote them here
    double lenX = (rect -> rightBot).x - (rect -> leftTop).x;
    double lenY = (rect -> leftTop).y - (rect -> rightBot).y;
    //use the perimeter formula to get the result
    return 2 * (lenX + lenY);
}

double getArea(Rect* rect){
    double lenX = (rect -> rightBot).x - (rect -> leftTop).x;
    double lenY = (rect -> leftTop).y - (rect -> rightBot).y;
    //return area by using formula
    return lenX * lenY;
}

void shiftRect(Rect* rect, int x, int y){
    //just add the x offset to x coordinates and Y offset to Y coordinates
    (rect -> leftTop).x += x;
    (rect -> rightBot).x += x;
    (rect -> leftTop).y += y;
    (rect -> rightBot).y += y;
}

void rotateRect(Rect* rect){
    double lenX = (rect -> rightBot).x - (rect -> leftTop).x;
    double lenY = (rect -> leftTop).y - (rect -> rightBot).y;
    //this one's little tricky
    //when we rotate the bottom left corner now rotates to become top left
    //and similarly top right corner rotates to become bottom right
    //If you find this hard to imagine write in comments I'll make a diagram 
    (rect -> rightBot).x = (rect -> leftTop).x;
    (rect -> rightBot).y = (rect -> leftTop).y - lenX;
    (rect -> leftTop).x -= lenY;
}

void expandRect(Rect* rect, double factor){
    //factor is the number of times area is increased
    //we find square root of it to find the factor in which length and width increase
    //sqrt is defined in math.h Don't forget to include that
    factor = sqrt(factor);
    double lenX = (rect -> rightBot).x - (rect -> leftTop).x;
    double lenY = (rect -> leftTop).y - (rect -> rightBot).y;
    //length is now changed to (length * factor)
    //only right bottom point changes left top remains fixed
    (rect -> rightBot).x = (rect -> leftTop).x + lenX * factor;
    (rect -> rightBot).y = (rect -> leftTop).y + lenY * factor;        
}

int main(){
    Rect a;
    a.leftTop.x = 0;
    a.leftTop.y = 5;
    a.rightBot.x = 6;
    a.rightBot.y = 0;
    rotateRect(&a);
    cout << a.leftTop.x << " " << a.leftTop.y << endl << a.rightBot.x << " " <<  a.rightBot.y << endl; 
}