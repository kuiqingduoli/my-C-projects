#include <stdio.h>
#include <easyx.h>
#include "tools.h"
#include <time.h>

int main()
{
	initgraph(500,500,EX_SHOWCONSOLE);
	setbkcolor(WHITE);
	setbkmode(TRANSPARENT);
	cleardevice();
	//动画
	IMAGE img_walk[8];
	int i;
	char walk[100];
	for(i=0;i<8;i++)
	{
		sprintf(walk,"图片/走路%d.png",i+1);
		loadimage(img_walk + i,walk);
	}
	const int frameDelay=1000/60;
	int frameStart=0;
	int frameTime=0;
	
	int index=0;
	int frames=4;
	int speed=150; //每隔150毫秒切换一帧 
	while(true)
	{
		frameStart=clock();
		BeginBatchDraw();
		cleardevice();
		drawImg(50,50,img_walk + index);
		EndBatchDraw();
		index++;
		/*while(index>=frames)
		{
			index=0;
		}
		//等于index=(index+1)%frames;
		*/
		index=(clock()/speed)%frames;
		frameTime=clock()-frameStart;
		int waittime=frameDelay-frameTime;
		if(waittime>0) 
		{
			Sleep(waittime);
		}
	}
	getchar();
	return 0;
}

