#include <stdio.h>
#include <easyx.h>

void drawTest()
{
	printf("Hello,EasyX!\n");
	//设置文字大小 
	settextstyle(48,0,"宋体");
	//设置文字颜色
	settextcolor(RED);
	//设置背景模式 
	setbkmode(TRANSPARENT);
	//绘制文字
	outtextxy(10,10,"Hello,EasyX!");
	//EasyX与字符串相关的函数，都有字符集问题  UNICODE 多字节字符集
	/*三种解决办法:
	*1.在字符串的前面使用L来进行转换(强制转换)
	*2.用带参宏(_T(),_TEXT())把字符串包裹起来(自适应转换)
	*3.菜单栏->项目->属性->高级->字符集->把UNICODE改为多字节字符集
	*/
	
	//现在有一个int类型的分数，需要输出到图形界面上面
	int score=100;
	char str[50];
	sprintf(str,"score:%d",score);
	settextstyle(30,0,"隶书");
	settextcolor(BLACK);
	outtextxy(100,200,str);
}
void centerText()
{
	setlinestyle(PS_SOLID, 3);
	setlinecolor(BLUE);
	setfillcolor(YELLOW);

	int left = 50;     // 矩形左上角x
	int top = 100;     // 矩形左上角y
	int right = 250;   // 矩形右下角x
	int bottom = 150;  // 矩形右下角y

	// 绘制矩形
	fillrectangle(left, top, right, bottom);

	// 设置文本样式（放在计算文本尺寸之前）
	settextstyle(15, 0, "楷体");
	settextcolor(BLUE);

	char str[50] = "play game";

	// 计算文本宽度和高度
	int textW = textwidth(str);
	int textH = textheight(str);

	// 计算居中位置
	int centerX = (left + right) / 2;
	int centerY = (top + bottom) / 2;
	int textX = centerX - textW / 2;
	int textY = centerY - textH / 2;

	// 输出文本
	outtextxy(textX, textY, str);
}
int main()
{
	initgraph(640,480,EX_SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	drawTest();
	centerText(); 
	getchar();
	return 0;
}
