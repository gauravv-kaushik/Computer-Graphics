#include <graphics.h>
#include <iostream>
#include <conio.h>
using namespace std;

int gd, gm, x1, y1, x2, y2, dep, ch;

int main() {
    cout << "\n Enter top-left and bottom-right corner:";  // 100 100 300 200
    cin >> x1 >> y1 >> x2 >> y2;
    cout << "\n Enter the depth along z axis:";    //50
    cin >> dep;
    cout << "Choose any one projection:\n\t1.Parallel Projection\n\t2.Perspective Projection\nEnter your choice:";
    cin >> ch;
    initgraph(&gd, &gm, NULL);
    switch (ch) {
        case 1:
            // Drawing parallel projection rectangles
            rectangle(x1, y1, x2, y2); // Front rectangle
            rectangle(x1 + dep, y1 - dep, x2 + dep, y2 - dep); // Back rectangle
            line(x1, y1, x1 + dep, y1 - dep); // Connecting lines
            line(x2, y1, x2 + dep, y1 - dep);
            line(x2, y2, x2 + dep, y2 - dep);
            line(x1, y2, x1 + dep, y2 - dep);
            getch();
            closegraph();
            break;
            
        case 2:
            bar3d(x1, y1, x2, y2, dep, 1);
            getch();
            closegraph();
            break;
    }
    return 0;
}
