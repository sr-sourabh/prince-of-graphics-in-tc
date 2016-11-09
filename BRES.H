	#include<stdio.h>
	#include<conio.h>
	#include<graphics.h>
	#include<dos.h>
	void Bresenhams(int x1,int y1,int x2,int y2,int col);
       /*	void main()
	{
	int gd=DETECT,gm,x1,x2,y1,y2;
	initgraph(&gd,&gm,"");
	printf("Enter (x1,y1) and (x2,y2) : ");
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	Bresenhams(x1,y1,x2,y2,14,20);
	getch();
	closegraph();
	} */
	void Bresenhams(int x1,int y1,int x2,int y2,int col)
	{
	int dx,dy,s,x,y;
	int p,tdy,tdydx;
	dx=x2-x1;
	dy=y2-y1;
	p=2*dy-dx;
	tdy=2*dy;
	tdydx=2*(dy-dx);
	if(x1>x2)
	{
	x=x2;
	y=y2;
	s=x1;
	}
	else
	{
	x=x1;
	y=y1;
	s=x2;
	}
	putpixel(x,y,col);
	while(x<s)
	{
	x++;
	if(p<0)
	p+=tdy;
	else
	{
	y++;
	p+=tdydx;
	}
	putpixel(x,y,col);
       //	delay(del);
	}
	}
