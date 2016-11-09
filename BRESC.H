# include<stdio.h>
# include<conio.h>
# include<graphics.h>
# include<math.h>


void b_c(int xc,int yc,int r,int c)
{
int x,y,p;

x=0;
y=r;
putpixel(xc+x,yc-y,1);

p=3-(2*r);

for(x=0;x<=y;x++)
{
if (p<0)
{
y=y;
p=(p+(4*x)+6);
}
else
{
y=y-1;

p=p+((4*(x-y)+10));
}

putpixel(xc+x,yc-y,c);
putpixel(xc-x,yc-y,c);
putpixel(xc+x,yc+y,c);
putpixel(xc-x,yc+y,c);
putpixel(xc+y,yc-x,c);
putpixel(xc-y,yc-x,c);
putpixel(xc+y,yc+x,c);
putpixel(xc-y,yc+x,c);

}
}





/*void main()
{
int gd=DETECT,gm;
int r,x,y,p,xc=320,yc=240;

initgraph(&gd,&gm,"C:\\TC\\BGI");
cleardevice();


printf("Enter the radius ");
scanf("%d",&r);
b_c(20,WHITE);
getch();
closegraph();

}
  */