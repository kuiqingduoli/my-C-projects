#ifndef TOOLS_H
#define TOOLS_H

#include <easyx.h>
#include <windows.h>

// 函数：绘制带透明度的图片
// 注意：inline函数必须把完整定义放在头文件里
inline void drawImg(int x, int y, IMAGE* img, BYTE alpha = 255)
{
    if (!img) return;

    // 获取当前绘图设备的句柄 (目标)
    HDC hDestDC = GetImageHDC(NULL);

    // 获取图片的句柄 (源)
    HDC hSrcDC = GetImageHDC(img);

    int width = img->getwidth();
    int height = img->getheight();

    // 设置混合函数参数
    BLENDFUNCTION bf = { AC_SRC_OVER, 0, alpha, AC_SRC_ALPHA };

    // 执行 Alpha 混合绘制
    AlphaBlend(hDestDC, x, y, width, height, hSrcDC, 0, 0, width, height, bf);
}

#endif // TOOLS_H
