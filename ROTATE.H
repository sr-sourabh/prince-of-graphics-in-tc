#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<stdio.h>
#include<math.h>






void multiply1(int a[1][3],float b[3][3],int c[1][3],int r1,int c2,int c1)
{
int i,j,k;

	for(i=0; i<r1; ++i)
	for(j=0; j<c2; ++j)
	for(k=0; k<c1; ++k)
	{
		c[i][j]+=a[i][k]*b[k][j];

	}


}


void rotate(int xm,int ym,int &x1,int &y1,float t=0.0174)
{


	float b[3][3]=
	{
	{	cos(t)                 	,sin(t)                 ,	0} ,
	{      -sin(t)                	,cos(t)                 ,	0} ,
	{  -xm*cos(t)+ym*sin(t)+xm      ,-xm*sin(t)-ym*cos(t)+ym,	1}
	};

	int a[1][3]=
	{
		  {x1,y1,1}
	};




	int c[1][3]={0};

	multiply1(a,b,c,1,3,3);

	for(int i=0;i<1;i++)
		for(int j=0;j<3;j++)
			 a[i][j]=c[i][j];



	x1=c[0][0];
	y1=c[0][1];


      //	char buf[50];
      //	sprintf(buf,"%d",x1);
       //	outtextxy(20,200,buf);

      //	sprintf(buf,"%d",y1);
      //	outtextxy(20,300,buf);


}



/*

void main()
{
clrscr();

int gd = DETECT,gm;

initgraph(&gd,&gm,"C:\\TURBOC3");
cleardevice();

int c=0,xm=200,ym=200,x1=xm+25,y1=ym+25;

//line(xm,ym,x1,y1);

while(c<90)
{
	setcolor(BLACK);
	line(xm,ym,x1,y1);



       //	trans(-200,-200,xm,ym);
       //	trans(-200,-200,x1,y1);

	rotate(xm,ym,x1,y1);



	setcolor(WHITE);
	line(xm,ym,x1,y1);


	delay(100);



       c++;

}


getch();
closegraph();
}

  */