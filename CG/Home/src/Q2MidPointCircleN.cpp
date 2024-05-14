#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<math.h>
#include <iostream>

using namespace std;

void mid_pt_circle(int a, int b , int r){
    int d=1.25-r;
    int x=0;
    int y=r;
    do{
        putpixel(a+x, b+y, CYAN);
		putpixel(a-x, b+y, CYAN);
		putpixel(a+x, b-y, CYAN);
		putpixel(a-x, b-y, CYAN);
		putpixel(a+y, b+x, CYAN);
		putpixel(a-y, b+x, CYAN);
		putpixel(a+y, b-x, CYAN);
		putpixel(a-y, b-x, CYAN);
        if(d<0){
            d=d+2*x+3;
        }
        else{
            d=d+2*(x-y)+5;
            y=y-1;
        }
        x=x+1;
    }while(x<y);
} 
int main(){
    cout<<"\n\n\t ---------------------- MID POINT CICLE DRAW ALGORITHM --------------------- ";
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver,&gmode,(char*)"");
    errorcode = graphresult();

   if (errorcode != grOk){
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
	int x_center,y_center,radius;
	cout<<"\n\n\n\t Enter the Coordinates of circle (x and y) :: ";   //200 200
	cin>>x_center>>y_center;
	cout<<"\n\t Enter the radius of the circle :: ";                    //50
	cin>>radius;
	if(radius < 0){
		cout<<"\n\t Radius can't be negative !!";
		exit(1);
	}
    
	mid_pt_circle(x_center,y_center,radius);
 	getch();
    closegraph();
    return 0;
}

