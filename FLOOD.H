 #include <stdio.h>
#include <conio.h>
#include<dos.h>
#include <graphics.h>

void floodit(int x,int y,int fillcolor)
{
int curcolor;
 curcolor=getpixel(x,y);

 if(curcolor==BLACK)
{                     // delay(2);
 putpixel(x,y,fillcolor);
 floodit(x-1,y,fillcolor) ;
 floodit(x+1,y,fillcolor) ;
floodit(x,y-1,fillcolor) ;
floodit(x,y+1,fillcolor) ;

 }
else return;



}



/* void flood(int x,int y,int color)
{                //   int gd=DETECT,gm;
//detectgraph(&gd,&gm);
//initgraph(&gd,&gm,"c:\\tc\\bgi");
	       setcolor(color);
//rectangle(20,20,500,50);
//circle(25,25,20);
//getch();
floodit(25,,color) ;
getch();
closegraph();

} */