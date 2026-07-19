#include <stdio.h>
#include <easyx.h>

ExMessage msg={0};
//mx,my是否在指定的矩形区域 
bool inArea(int mx,int my,int x,int y,int w,int h)
{
	if(mx>x&&mx<x+w&&my>y&&my<y+h)
	{
		return true;
	}
	return false;
}
bool botton(int x,int y,int w,int h,const char*text)
{
	//绘制按钮
	setlinecolor(BLACK);
	if(inArea(msg.x,msg.y,x,y,w,h)) 
	{
		setfillcolor(RGB(100,250,253));
	}else
	{
		setfillcolor(RGB(200,252,253));
	}
	fillroundrect(x,y,x+w,y+h,5,5);
	//绘制按钮文本
	int hSpace=(w-textwidth(text))/2;
	int vSpace=(h-textheight(text))/2;
	settextcolor(BLACK);
	settextstyle(20,0,"楷书");
	outtextxy(x+hSpace,y+vSpace,text);
	//判断按钮是否被点击 
	if(msg.message==WM_LBUTTONDOWN&&inArea(msg.x,msg.y,x,y,w,h))
	{
		return true;
	}
	return false;
}
int main()
{
	initgraph(640,480,EX_SHOWCONSOLE);
	setbkcolor(WHITE);
	setbkmode(TRANSPARENT);
	cleardevice();
	while(true)
	{
		peekmessage(&msg,EX_MOUSE);
		//双缓冲绘图：所有的绘图代码必须放在begin 和 end之间 
		BeginBatchDraw();
		cleardevice();
		if(botton(20,20,150,35,"Start Game"))
		{
			printf("Start Game!\n");
		}
		if(botton(20,100,150,35,"End Game"))
		{
			printf("End Game!\n");
		}
		EndBatchDraw();
		msg.message=0;
	}
	getchar();
	return 0;
}
 
