#include <graphics.h>
#include <iostream>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); // Initialize graphics system

    int xc, yc, a, b;

    cout << "Enter the coordinates of the center (xc, yc): ";   //200 150
    cin >> xc >> yc;

    cout << "Enter the length of the major axis (a): ";         //100
    cin >> a;

    cout << "Enter the length of the minor axis (b): ";         //50
    cin >> b;

    float x, y, d;

    x = 0;
    y = b;
    d = b * b + a * a * (-b + 0.25);

    while (2 * b * b * x <= 2 * a * a * y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (d < 0) {
            x++;
            d += 2 * b * b * x + b * b;
        } else {
            x++;
            y--;
            d += 2 * b * b * x - 2 * a * a * y + b * b;
        }
    }

    d = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b;

    while (y >= 0) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (d <= 0) {
            x++;
            y--;
            d += 2 * b * b * x - 2 * a * a * y + a * a;
        } else {
            y--;
            d += -2 * a * a * y + a * a;
        }
    }

    //delay(5000); // Display for 5 seconds
    closegraph(); // Close graphics

    return 0;
}
