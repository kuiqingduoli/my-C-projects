#include <stdio.h>
#include <easyx.h>

void drawShape()
{
	//绘制一条点
	putpixel(50,50,RED);
	
	//设置线条颜色
	setlinecolor(BLUE);
	//设置线条样式 
	setlinestyle(PS_SOLID,3);
	//绘制一条线
	line(0,0,getwidth(),getheight());
	
	//绘制一个正矩形
	rectangle(100,0,150,50);//无填充矩形
	setfillcolor(YELLOW);	//设置填充颜色
	fillrectangle(100,60,150,110); //填充矩形
	solidrectangle(100,120,150,170); //无边框填充矩形
	
	//绘制一个圆角矩形
	roundrect(160,0,210,50,30,30);//无填充圆角矩形 
	setfillcolor(GREEN);//设置填充颜色
	fillroundrect(220,0,270,50,30,30);//填充圆角矩形
	solidroundrect(280,0,330,50,30,30);//无边框填充圆角矩形
	
	//绘制一个圆形 
	circle(50,50,50);//无填充圆形 
	setfillcolor(RED);//设置填充颜色
	fillcircle(50,50,30); //填充圆形
	solidcircle(50,150,50);//无边框填充圆形
	
	//绘制一个椭圆
	ellipse(0,210,100,280);//无填充椭圆 
	setfillcolor(GREEN); //设置填充颜色
	fillellipse(0,290,100,360);//填充椭圆
	solidellipse(0,370,100,440);//无边框填充椭圆
	
	//绘制折线
	POINT points[] ={{150,230},{250,90},{300,450},{230,360}};
	polyline(points,4);
}
int main() 
{
	//创建一个图形窗口 宽度 * 高度 
	initgraph(640,480,EX_SHOWCONSOLE);//NO_CLOSE,NO_NOMINIMIZE
	//设置窗口的背景颜色
	setbkcolor(WHITE);//RGB(231,114,227)
	//用设置的背景颜色填充整个窗口
	cleardevice();
	//窗口的坐标体系:窗口左上角是坐标原点，x轴向右增大，y轴向下增大
	drawShape(); 
	 
	getchar();
	return 0;
}
