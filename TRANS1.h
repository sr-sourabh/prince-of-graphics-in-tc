#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<stdio.h>



void multiply(int a[1][3],int b[3][3],int c[3][3],int r1,int c2,int c1)
{
	int i,j,k;

	for(i=0; i<r1; ++i)
	for(j=0; j<c2; ++j)
	for(k=0; k<c1; ++k)
	{
		c[i][j]+=a[i][k]*b[k][j];

	}

}

void trans(int sx,int sy,int &x1,int &y1)
{

	int b[3][3]=
	{
		{1, 0, 0},
		{0, 1, 0} ,
		{sx,sy,1}
	};

	int a[1][3]=
	{
	  {x1,y1,1}
	};

	int c[1][3]={0};

	multiply(a,b,c,1,3,3);

	for(int i=0;i<1;i++)
	for(int j=0;j<3;j++)
	a[i][j]=c[i][j];

	x1=a[0][0];
	y1=a[0][1];


}




/*void main()
{
clrscr();
int gd = DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOC3");
cleardevice();

int x1=200,y1=200;
circle(x1,y1,50);

trans(30,30,x1,y1);

circle(x1,y1,50);

getch();
closegraph();
}                 */
