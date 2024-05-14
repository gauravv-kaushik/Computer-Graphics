#include<iostream>
#include<graphics.h>
#include<stdlib.h>
using namespace std;
void bresenham(int x,int y,int x2,int y2){
	int dx,dy;
	int p;
	dx=(x2-x);
	dy=(y2-y);
    int m=dy/dx;
	p=2*dy-dx;  		// p = decision point
    while(x<x2 & y<y2){
        putpixel(x,y,GREEN);
        if(m<1){
            if(p<0){
                x=x+1;
                p=p+2*dy;
            }
            else{
                x=x+1;
                y=y+1;
            }
        }
        else{
            if(p<0){
                y=y+1;
            }
            else{
                x=x+1;
                y=y+1;
            }
        }
    }
}
int main(){
	cout<<"\n\n\t --------------------- BRESENHAM'S LINE  DRAW ALGORITHM --------------------- ";
	int gd=DETECT,gm;
	
	initgraph(&gd,&gm,(char*)"");
	int x1,x2,y1,y2,num;

	cout<<"\n\n\n\t ENTER THE COORDINATES VALUES x1, y1 :: ";  //100 100
	cin >> x1>>y1;
	cout<<"\n\t ENTER THE COORDINATES VALUES x2, y2 :: ";      //400 300
	cin >> x2>>y2;
	bresenham( x1,y1,x2,y2);
	getch(); 
	closegraph();
	return 0;
}
