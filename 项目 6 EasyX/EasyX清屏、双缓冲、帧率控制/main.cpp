#include <stdio.h>
#include <easyx.h>
#include <time.h>

//清屏
//双缓冲
//帧率控制
 
int main()
{
	initgraph(640,480,EX_SHOWCONSOLE);
	setbkcolor(WHITE);
	setbkmode(TRANSPARENT);
	cleardevice();
	
	//FPS 60f 
	const clock_t FPS=1000/60;  //1000:1秒 60:60帧  1000/60=16,每帧应该花费的时间
	int startTime=0; 
	int frameTime=0; 
	char str[50];
	int score=0;
	while(true)
	{
		startTime=clock(); 
		
		sprintf(str,"score=%d",score++);
		settextcolor(BLACK);
		BeginBatchDraw();
		cleardevice();//用设置的背景颜色填充整个窗口 
		outtextxy(20,20,str);
		EndBatchDraw();
		
		frameTime=clock()-startTime;
		int waitTime=FPS-frameTime;
		if(waitTime>0)
		{
			Sleep(waitTime);
		}
	}
	return 0;
}
