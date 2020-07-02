#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

using namespace std;

int main()
{
    // gm is Graphics mode which is a computer display
    // mode that generates image using pixels.
    // DETECT is a macro defined in "graphics.h" header file
    int gd = DETECT, gm;

    // initgraph initializes the graphics system
    // by loading a graphics driver from disk
    cout << 1 << endl;
    initgraph(&gd, &gm, "");
    cout << 2 << endl;
    // line for x1, y1, x2, y2
    line(150, 150, 450, 150);

    // line for x1, y1, x2, y2
    line(150, 200, 450, 200);

    // line for x1, y1, x2, y2
    line(150, 250, 450, 250);

    getch();

    // closegraph function closes the graphics
    // mode and deallocates all memory allocated
    // by graphics system .
    closegraph();
    return 0;
}
