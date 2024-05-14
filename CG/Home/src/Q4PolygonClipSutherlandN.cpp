#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int poly[10];
    int n;
    cout << "Enter the number of vertices of the polygon: ";   //3
    cin >> n;

    for (int i = 0; i < 2 * n; i += 2) {
        cout << "Enter coordinates of vertex " << (i / 2) + 1 << " (x, y): ";
        cin >> poly[i] >> poly[i + 1];
    }
    // 80 150 200 250 300 200

    poly[2 * n] = poly[0];
    poly[2 * n + 1] = poly[1];

    int xmin, xmax, ymin, ymax;
    cout << "Enter the coordinates of the clipping window (xmin, ymin, xmax, ymax): ";
    cin >> xmin >> ymin >> xmax >> ymax;
    // 100 100 400 300
    int a=xmin;
    int b=ymin;
    int c=xmax;
    int d=ymax;

    rectangle(xmin, ymin, xmax, ymax);
    setcolor(YELLOW);
    fillpoly(n + 1, poly);
    char ch;
    cout << "\npress any key to clip :";
	cin >> ch;
	if(ch){
		cleardevice();
	}

    int clippedPoly[10];
    int clippedPolySize = 0;

    for (int i = 0; i < 2 * n; i += 2) {
        int x1 = poly[i], y1 = poly[i + 1];
        int x2 = poly[i + 2], y2 = poly[i + 3];
        
        bool accept = false, done = false;

        while (!done) {
            int outcode1 = 0, outcode2 = 0;
            if (x1 < xmin) outcode1 |= 1;  // to the left of clip window
            else if (x1 > xmax) outcode1 |= 2; // to the right of clip window
            if (y1 < ymin) outcode1 |= 4;  // above the clip window
            else if (y1 > ymax) outcode1 |= 8; // below the clip window
            if (x2 < xmin) outcode2 |= 1;
            else if (x2 > xmax) outcode2 |= 2;
            if (y2 < ymin) outcode2 |= 4;
            else if (y2 > ymax) outcode2 |= 8;

            if (outcode1 == 0 && outcode2 == 0) { // Trivially accepted
                accept = true;
                done = true;
            } else if (outcode1 & outcode2) { // Trivially rejected
                done = true;
            } else { // Clip against the boundary
                int x, y;
                int outcodeOut = outcode1 ? outcode1 : outcode2;

                if (outcodeOut & 1) { // Clip against left boundary
                    y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                    x = xmin;
                } else if (outcodeOut & 2) { // Clip against right boundary
                    y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                    x = xmax;
                } else if (outcodeOut & 4) { // Clip against top boundary
                    x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                    y = ymin;
                } else { // Clip against bottom boundary
                    x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                    y = ymax;
                }

                if (outcodeOut == outcode1) {
                    x1 = x;
                    y1 = y;
                } else {
                    x2 = x;
                    y2 = y;
                }
            }
        }

        if (accept) {
            clippedPoly[clippedPolySize++] = x1;
            clippedPoly[clippedPolySize++] = y1;
            clippedPoly[clippedPolySize++] = x2;
            clippedPoly[clippedPolySize++] = y2;
        }
    }
    setcolor(RED);
    rectangle(a,b,c,d);
    setcolor(CYAN);
    fillpoly(clippedPolySize / 2, clippedPoly);

    getch();
    closegraph();
    return 0;
}