#include <stdio.h>
#include <easyx.h>

int main()
{
	initgraph(800,600,EX_SHOWCONSOLE);
	setbkcolor(WHITE);
	setbkmode(TRANSPARENT);
	cleardevice();
	ExMessage msg={0};
	//定义小球属性
	int x=50;
	int y=50;
	int r=20; 
	int speed=3;
	int vx=0;
	int vy=0;
	while(true)
	{
		peekmessage(&msg,EX_KEY);
		//判断按键消息 
		if(msg.message==WM_KEYDOWN)
		{
			//printf("keydown\n");
			//具体判断是哪个键按下
			switch(msg.vkcode) 
			{
				case VK_UP:
				vy=-1;
				//printf("上键按下\n");
				break;
				case VK_DOWN:
				vy=1;
				//printf("下键按下\n");
				break;
				case VK_LEFT:
				vx=-1;
				//printf("左键按下\n");
				break;
				case VK_RIGHT:
				vx=1;
				//printf("右键按下\n");
				break;
			/*	case VK_SPACE:
				printf("space\n");
				break;
				case 'A': //对于字母键，必须写大写的字符 
				printf("A键按下\n");
			*/
			}
		}else if(msg.message==WM_KEYUP)
		{
			//printf("keyup\n");
			switch(msg.vkcode) 
			{
				case VK_UP:
				vy=0;
				break;
				case VK_DOWN:
				vy=0;
				break;
				case VK_LEFT:
				vx=0;
				break;
				case VK_RIGHT:
				vx=0;
			}
			
		}
		BeginBatchDraw();
		cleardevice();
		//绘制小球 
		setlinecolor(BLACK);
		setfillcolor(RGB(90,252,253));
		fillcircle(x,y,r);
		//更新小球位置 
		x+=speed*vx;
		y+=speed*vy;
		EndBatchDraw();
		Sleep(10);
		msg.message=0;
	}
	getchar();
	return 0;
}
