
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<stdio.h>

//**************ALGORITHMS*******************
#include"sf1.h"
#include"bresc.h"
#include"bres.h"
#include"dda.h"
#include"trans1.h"
#include"flood.h"
#include"scale.h"
//#include"start.h"
#include"rotate.h"


#define bcolor 3
#define pcolor 10
#define lcolor 6


//*****************GLOBAL************************
   int xl=0,yl=0,xd=0,yd=0,ox1=600,score=0,ox2=300,ox3=150,by=0,bx=0,flag=0,gameover=0,temp1=0,bc=0;
   char ch;





void lines()
{
      int i=0;

      for(;i<60;i++)
      {

	 setcolor(lcolor);
	 DDA(0+xl,420+i,200+xl,420+i,lcolor);
	 setcolor(pcolor);
	 Bresenhams(200+xl,420+i,250+xl,420+i,pcolor);

	 setcolor(lcolor);
	 line(250+xl,420+i,450+xl,420+i);
	 setcolor(pcolor);
	 line(450+xl,420+i,500+xl,420+i);

	 setcolor(lcolor);
	 line(500+xl,420+i,700+xl,420+i);
	 setcolor(pcolor);
	 line(700+xl,420+i,750+xl,420+i);

	 setcolor(lcolor);
	 line(750+xl,420+i,950+xl,420+i);

      }
}


void background()
{

//int *p=0;
	int size;

	setcolor(WHITE);
	DDA(1,280,713,280,WHITE);

	rectangle(44,220,80,280);
	setfillstyle(SOLID_FILL,WHITE);
	sf(4,44,220,80,220,80,280,44,280);


	rectangle(83,280,114,177);
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(86,260,WHITE);


	rectangle(116,280,142,220);
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(122,250,WHITE);


	rectangle(145,280,182,107);
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(148,180,WHITE);


	b_c(290,75,15,WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	floodit(292,75,WHITE);

	rectangle(184,280,428,221);
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(200,240,WHITE);


	rectangle(430,280,469,107);
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(450,150,WHITE);


	rectangle(471,280,503,221);
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(474,240,WHITE);


	rectangle(505,280,543,177);
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(520,180,WHITE);


	rectangle(545,280,586,221);
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(550,240,WHITE);


}




void rescue(int x,int color1,int color2)
{
	int i=0 ;

	for(;i<60;i++)
	{
		putpixel(x,420+i,color1);

		putpixel(x+50,420+i,color2);

		putpixel(x+250,420+i,color1);

		putpixel(x+300,420+i,color2);

		putpixel(x+500,420+i,color1);

		putpixel(x+550,420+i,color2);

	}

}

//*************************INITIAL DROID********************************
void make_droid(int xd,int yd)
{

	circle(20+xd,390+yd,10);
	line(20+xd,400+yd,20+xd,419+yd);

}

//*************ERASE DROID AND MOVE**************************
void mov_droid(int &xd,int &yd)
{
	if(xd>600)
	xd=-10;

	setcolor(bcolor);
	make_droid(xd,yd);

	setcolor(lcolor);
	trans(40,-20,xd,yd);
      //	xd +=40;
      //	yd -=20;
	make_droid(xd,yd);
	delay(50);

	setcolor(bcolor);
	make_droid(xd,yd);

	setcolor(lcolor);
	trans(40,20,xd,yd);
      //	xd +=40;
      //	yd +=20;
	make_droid(xd,yd);




}

//********************MAKE OBSTACLES IN THE SKY**********************
void make_obstacle(int &ox1,int &ox2,int &ox3)
{

	 if(ox1<-10)
	 ox1=600;
	 if(ox2<-10)
	 ox2=600;
	 if(ox3<-10)
	 ox3=600;

	 setcolor(bcolor);
	  setfillstyle(SOLID_FILL,bcolor);
	  circle(ox1+1,30,5);
	   floodfill(ox1+1,30,bcolor);

	 setcolor(RED);
	 circle(ox1,30,RED);                      //obstacle 1
	 setfillstyle(SOLID_FILL,RED);
	 floodfill(ox1,30,RED);



		setcolor(bcolor);
		circle(ox2+1,30,5);
		setfillstyle(SOLID_FILL,bcolor);
		floodfill(ox2+1,30,bcolor);        //obstracle 2


	       setcolor(10);
	       circle(ox2,30,5);
	       setfillstyle(SOLID_FILL,10);
	       floodfill(ox2+1,30,10);


	       setcolor(bcolor);
	       circle(ox3+1,30,5);
	       setfillstyle(SOLID_FILL,bcolor);
	       floodfill(ox3+1,30,bcolor);        //obstracle 3


	      setcolor(5);
	      circle(ox3,30,5);
	      setfillstyle(SOLID_FILL,5);
	      floodfill(ox3+1,30,5);





	 ox1--;
	   ox2--;
	   ox3--;
}

//********************BULLET****************************
void bullet( int &by,int bx)
{

	int rescue1=getpixel(bx,279);
	if(rescue1==0)
		 {
			 setcolor(WHITE);
			 line(bx-5,280,bx+5,280);  //to check for a single line
			 bc=12;
		 }

    if(by-11+5<280&&by-11+5>177)
    {

		 temp1=getpixel(bx,by-11-6);

		 if(temp1!=15&&bc<6)
		 {
		  bc++;
		  temp1=15;
		 }



	{

		setcolor(temp1);
		//line(bx-5,by-11+6,bx+5,by-11+6);
			line(bx-5,by-11+6,bx+5,by-11+6);
		line(bx-5,by-11+7,bx+5,by-11+7);


		setcolor(MAGENTA);
		circle(bx,by-12,5);
	}

    }


    else
	 {

		setcolor(bcolor);
		line(bx-5,by-11+6,bx+5,by-11+6);
		line(bx-5,by-11+7,bx+5,by-11+7);


		setcolor(MAGENTA);
		circle(bx,by-12,5);
	}

	by-=2;

  //	char buf[50];
		for (int i=-10;i<10;i++)
		{
		int co=getpixel(bx+i,by-17);

		//sprintf(buf,"%d",co);
		//outtextxy(50,300,buf);

		if(co==RED)
		{
			setcolor(RED);
			outtextxy(50,20,"Well done");
			     //	delay(600);
		     //	 setcolor(bcolor);
		    //	outtextxy(50,20,"Well done");
//outtextxy(50,20,"Well done");
  //			delay(100);
			ox1=0;
			score+=10;
			break;
		}


			if(co==10)
			{
		       //	outtextxy(50,20,"Well done");
		       setcolor(RED);
			outtextxy(50,20,"Well done");
				//delay(600);
		   //	 setcolor(bcolor);
		    //	outtextxy(50,20,"Well done");
	//delay(100);
	score=score+10;
			ox2=0;
			break;
		}
	if(co==5)
		{
			 setcolor(RED);
			outtextxy(50,20,"Well done");
			       //	delay(600);
		     //	 setcolor(bcolor);
		      //	outtextxy(50,20,"Well done");

				   score+=10;
			ox3=0;
			break;
		}

		}//end of for2
}




//***************FALL LOGIC**************************************
void check_for_fall(int xd)
{
	int color=getpixel(20+xd,420);
	if(color==pcolor)
	{       gameover=1;
		setcolor(bcolor);
		make_droid(xd,yd)  ;

		setcolor(lcolor);
		make_droid(xd+20,yd+50)   ;
	}


}

void start_screen()
{

	setbkcolor(BLACK);

	outtextxy(100,380,"LOADING...............");
	outtextxy(200,130,"Developed by -");

	
	outtextxy(230,170,"SHOURABH PAYAL");
	

	int x1=20,x2=40;

	while(x1<650)
	{
		rectangle(x1,400,x2,420);

		trans(1,0,x1,400);





		trans(1,0,x2,420);

		delay(10);
	}

	cleardevice();


}


//***************THE DISPLAY SCREEN *****************************
void display()
{


     int cl =199,res;

    start_screen();

     setbkcolor(bcolor);

 //****************to display line *************
     lines();

     background();




     make_droid(xd,yd);

     delay(3000);  //for static start screen

     while(ch!=27)
     {


	  if(kbhit())
	  {
		ch=getch();

		if(ch==27)
		break;

		if(ch==112)
		{

			mov_droid(xd,yd);
			check_for_fall(xd);
		}

		if(ch==119)
		{

			flag=1;

			if(by>0)
				flag=1;
			else
			{
				bc=0;
				by=380;
				bx=xd+20;

			}
		}

	  }


	  //****begin****for movement of lines*************
	  if(cl==(-50))
	  {
		 lines();
		 cl=199;
	  }
	  rescue(cl,pcolor,lcolor);
	  cl--;
	  delay(15);
	  //****end****for movement of lines*************

	  check_for_fall(xd);

	  //****begin*****for movement of obstacle**********
	   //****************make obstacles in the sky***********
	  make_obstacle(ox1,ox2,ox3);
	  //****end*****for movement of obstacle**********

	  //****begin*****for movement of bullet**********
	  if(flag==1)
	  bullet(by,bx);
	  //****end*****for movement of bullet*********

	  if(gameover==1)
	  break;


     }




	 //scale();

}








//*************************MAIN***************************
void main()

{
	clrscr();
	int gd = DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3");
	cleardevice();
	       //start();
	cleardevice();
    //	while(lives>=0)
	display();

	 scale();

getch();

closegraph();

}
