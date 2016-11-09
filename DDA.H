	#include<stdio.h>
	#include<conio.h>
	#include<graphics.h>
	#include<dos.h>
	void DDA(int x1,int y1,int x2,int y2,int col);
       /*	void main()
	{
	int gd=DE
	TECT,gm,x1,x2,y1,y2;
	initgraph(&gd,&gm,"");
	printf("Enter (x1,y1) and (x2,y2) : ");
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	DDA(x1,y1,x2,y2,14,20);
	getch();
	closegraph();
	}*/
	void DDA(int x1,int y1,int x2,int y2,int col)
	{
	int dx,dy,s,i,xi,yi,x,y;
	x=x1,y=y1;
	dx=x2-x1;
	dy=y2-y1;
	if(dx>dy)
	s=dx;
	else
	s=dy;
	xi=dx/s;
	yi=dy/s;
	putpixel(x,y,col);
	for(i=0;i<s;i++)
	{
	x+=xi;
	y+=yi;
	putpixel(x,y,col);
    //	delay(del);
	}
	}
