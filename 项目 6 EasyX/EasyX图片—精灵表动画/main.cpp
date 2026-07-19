#include <stdio.h>
#include <easyx.h>
#include <time.h>
#include "tools.h"

int main()
{
	initgraph(500,500,EX_SHOWCONSOLE);
	setbkcolor(WHITE);
	setbkmode(TRANSPARENT);
	cleardevice();
	//精灵表动画
	int frameDelay=1000/60;
	int frameStart=0;
	int frameTime=0;
	IMAGE img_explosion;
	loadimage(&img_explosion,"图片/walk.png");
	int frames=8;        //总共有多少帧率 
	int imgwidth=184;    //每帧宽度 
	int imgheight=325;  //每帧高度 
	int speed=200; 
	int waitTime=0;   //多少毫秒切换一张 
	int index=0;     //贴哪一张图 
	while(true) 
	{
		frameStart=clock();
		BeginBatchDraw();
		cleardevice();
		drawSprite(50,50,&img_explosion,imgwidth*index,0,imgwidth,imgheight);
		EndBatchDraw();
		index=(clock()/speed)%frames;
		frameTime=clock()-frameStart;
		waitTime=frameDelay-frameTime;
		if(waitTime>0) 
		{
			Sleep(waitTime);
		}
	}
	getchar();
	return 0;
}
