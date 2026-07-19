#include <stdio.h> 
#include <easyx.h>

int main()
{
	initgraph(640,480,EX_SHOWCONSOLE | EX_DBLCLKS);
	setbkcolor(WHITE);
	cleardevice();
	//定义消息结构体变量
	ExMessage msg={0};
	//获取消息
	while(true)
	{
		if(peekmessage(&msg,EX_MOUSE))
		{
			switch(msg.message)
			{
				case WM_LBUTTONDOWN:   	//左键按下 
				printf("左键按下 pos(%d,%d)\n",msg.x,msg.y);
				break;
				case WM_RBUTTONDOWN:	//右键按下
				printf("右键按下 pos(%d,%d)\n",msg.x,msg.y);
				break;
				case WM_MBUTTONDOWN:    //中键按下
				printf("中键按下\n");
				break;
				case WM_MOUSEWHEEL:    //滚轮滚动 
				printf("滚轮滚动 dir(%d)\n",msg.wheel);
				break; 
			    case WM_LBUTTONDBLCLK:  //左键双击 
				printf("左键双击\n");
			    break;
			    case WM_MOUSEMOVE:    //鼠标移动 
			    //printf("鼠标移动\n");
			    break;
			}
		}
	}
	
	getchar();
	return 0;
}
