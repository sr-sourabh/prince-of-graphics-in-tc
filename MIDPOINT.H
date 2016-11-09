#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
void mid_c(int xc,int yc,int r,int color)
{
//int gd=DETECT,gm;
int i,x,y;
float d;
/*clrscr();
initgraph(&gd,&gm,"");
printf("Enter Radius\n");
scanf("%d",&r);
printf("Enter Center of circle\n");

scanf("%d",&xc);
scanf("%d",&yc);     */
d=1.25-r;
x=0;
y=r;
do
{
if(d<0)
{

x=x+1;
d=d+2*x+1;
}
else
{

x=x+1;
y=y-1;
d=d+2*x-2*y+10;
}
 putpixel(xc+x,yc+y,color);
putpixel(xc-y,yc-x,color);
putpixel(xc+y,yc-x,color);
putpixel(xc-y,yc+x,color);
putpixel(xc+y,yc+x,color);
putpixel(xc-x,yc-y,color);
putpixel(xc+x,yc-y,color);
putpixel(xc-x,yc+y,color);
}
while(x<y);
//getch();
}