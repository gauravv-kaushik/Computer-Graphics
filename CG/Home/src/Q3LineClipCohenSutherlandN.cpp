#include <iostream>
#include<graphics.h>
#include<conio.h>
using namespace std;

static int xmin,ymin,xmax,ymax;
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Compute region code for a point (x, y)
int computeCode(int x, int y) {
    int code = INSIDE; // Initialized as being inside
    if (x < xmin)      // to the left of clip window
        code |= LEFT;
    else if (x > xmax) // to the right of clip window
        code |= RIGHT;
    if (y < ymin)      // below the clip window
        code |= BOTTOM;
    else if (y > ymax) // above the clip window
        code |= TOP;

    return code;
}

// Clip the line segment (x1, y1)-(x2, y2) using Cohen-Sutherland algorithm
void cohenSutherland(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    int m=(y2-y1)/(x2-x1);
    bool accept = false;

    while (true) {
        if ((code1==0 & code2==0)) { // Both endpoints inside window
            accept = true;
            break;
        } else if (code1 == code2) { // Both endpoints outside window, trivial reject
            break;
        } else {
            int codeOut = code1 ? code1 : code2;
            int x, y;
            // Find intersection point
            if (codeOut & TOP) { // point is above the clip window
                x = (1/m) * (ymax-y1) + x1;
                y = ymax;
            } else if (codeOut & BOTTOM) { // point is below the clip window
                x = (1/m) * (ymin-y1) + x1;
                y = ymin;
            } else if (codeOut & RIGHT) { // point is to the right of clip window
                y = m * (xmax-x1) + y1;
                x = xmax;
            } else if (codeOut & LEFT) { // point is to the left of clip window
                y = m * (xmin-x1) + y1;
                x = xmin;
            }
            // Replace outside point with intersection point
            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    if (accept) {
        cout << "Line segment after clipping: (" << x1 << "," << y1 << ")-(" << x2 << "," << y2 << ")" << endl;
        cleardevice();
		rectangle(xmin,ymin,xmax,ymax);
		setcolor(RED);
		line(x1,y1,x2,y2);
        getch();
    }
    else {
        cout << "Line segment rejected." << endl;
    }
}

int main() {
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver,&gmode,(char*)"");
	setcolor(WHITE);
    cout<<"\n\t Enter xmin ymin xmax ymax :: ";
    cin >> xmin >> ymin >> xmax >> ymax;

    int x1,y1,x2,y2;
	cout<<"\n\t Enter x1 y1 x2 y2 :: ";
	cin>>x1>>y1>>x2>>y2; 
    rectangle(xmin,ymin,xmax,ymax);
    line(x1,y1,x2,y2);

    cout << "Line segment before clipping: (" << x1 << "," << y1 << ")-(" << x2 << "," << y2 << ")" << endl;

    char ch;
    cout << "press any key to clip : ";
    cin >> ch;
    if(ch){
        cohenSutherland(x1, y1, x2, y2);
    }
    return 0;
}
// 100 100 400 300
// 80 120 200 200