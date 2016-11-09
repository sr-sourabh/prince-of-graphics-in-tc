#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<stdio.h>


int count=60;
void multiply1(int,int,int,int,int,int);

int b1[3][3]=
{
{2,0,0},
{0,2,0} ,
{0,0,1}
};

void multiply1(int a[2][3],int b1[3][3],int c[3][3],int r1,int c2,int c1)
{
int i,j,k;
	for(i=0; i<r1; ++i)
	for(j=0; j<c2; ++j)
	for(k=0; k<c1; ++k)
	{
		c[i][j]+=a[i][k]*b1[k][j];

	}




}



void scale()
{
/*clrscr();

int gd = DETECT,gm;

initgraph(&gd,&gm,"C:\\TURBOC3");
cleardevice();        */
start:
int x1=300,y1=300,r=5;
int a[2][3]=
{
  {r,0,1},
  {0,0,1}

};



while(count>0)
{
	if(r>300)
	goto start;
	circle(x1,y1,r);
	int c[2][3]={0};
	multiply1(a,b1,c,2,3,3);

	      for(int i=0;i<2;i++)
		for(int j=0;j<3;j++)
		 a[i][j]=c[i][j];



	r=a[0][0];
	delay(200);
	if(kbhit())
	{
	char ch =getch();
	if(ch==27)
	exit(0);
	//cleardevice();
	}
	outtextxy(20,200,"GAME OVER !!!!!");
	int sc;
char buf[50];
outtextxy(0,100,"SCORE");
sprintf(buf,"%d",sc);
outtextxy(50,100,buf);

	  cleardevice();
	      count--;

}
//getch();
//closegraph();
}

