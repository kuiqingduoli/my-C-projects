#include <stdio.h>
#include <easyx.h>
#include "tools.h"  

int main()
{
	initgraph(1000, 1000, EX_SHOWCONSOLE);
	setbkcolor(WHITE);
	setbkmode(TRANSPARENT);
	cleardevice();
	
	// 定义图片变量
	IMAGE img_wsq;
	// 加载图片
	loadimage(&img_wsq, "图片/乌萨奇.jpg");
	// 输出图片
	putimage(50, 50, &img_wsq);
	
	// 掩码图透明贴图
	IMAGE img_wsq2[2];
	loadimage(img_wsq2 + 0, "图片/乌萨奇2掩码.jpg", 500, 500);
	loadimage(img_wsq2 + 1, "图片/乌萨奇2.jpg", 500, 500);
	putimage(400, 100, img_wsq2 + 0, NOTSRCERASE);  // 先绘制掩码图
	putimage(400, 100, img_wsq2 + 1, SRCINVERT);    // 再绘制原图
	
	// PNG图片透明贴图
	IMAGE img_png;
	loadimage(&img_png, "图片/青柠.png");
	putimage(200, 600, &img_png);
	
	// 调用自定义的透明贴图函数
	drawImg(500, 600, &img_png, 255);
	
	getchar();
	return 0;
}
