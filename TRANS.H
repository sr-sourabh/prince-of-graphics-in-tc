#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<stdio.h>
#include"midpoint_c.h"


int b[3][3]=
{
{1,0,0},
{0,1,0} ,
{1,0,1}
};

void multiply(int a[2][3],int b[3][3],int c[3][3],int r1,int c2,int c1)
{
int i,j,k;
	for(i=0; i<r1; ++i)
	for(j=0; j<c2; ++j)
	for(k=0; k<c1; ++k)
	{
		c[i][j]+=a[i][k]*b[k][j];

	}




}



void trans()
{
/*clrscr();
int gd = DETECT,gm;

initgraph(&gd,&gm,"C:\\TURBOC3");        */
//cleardevice();
int x1=20,y1=400,x2=40,y2=420;

int a[2][3]=
{
  {x1,y1,1},
  {x2,y2,1}

};
mid_c(50,50,20,WHITE);
rectangle(180,110,380,230);

while(x1<600)
{
		outtextxy(100,380,"LOADING...............");
		outtextxy(200,130,"Developed by -");

	outtextxy(230,150,"SHUBHAM PURANDARE");
	outtextxy(230,170,"SHOURABH PAYAL");
	outtextxy(230,190,"VISHAL PUNVANI");
	outtextxy(230,210,"ABHISHEK POTNIS");


	rectangle(x1,y1,x2,y2);
	int c[2][3]={0};
	multiply(a,b,c,2,3,3);

	      for(int i=0;i<2;i++)
		for(int j=0;j<3;j++)
		 a[i][j]=c[i][j];



      //	for( i=0;i<3;i++)
       //	{cout<<"\n";
     //	for( j=0;j<3;j++)
      //	cout<<" "<<a[i][j];
       //	}
      //	cout<<"\n"<<x1<<" "<<x2;
       //	getch();
	x1=a[0][0];
	x2=a[1][0];
	delay(5);



}
//getch();
//closegraph();
}
