#ifndef TOOLS_H
#define TOOLS_H

#include <easyx.h>
#include <windows.h>

// 函数：绘制精灵表切片（支持透明度和指定区域）
// 参数：
//   x, y: 屏幕上的绘制坐标
//   img: 精灵表图片对象指针
//   sx, sy: 在精灵表中的起始坐标（左上角）
//   sw, sh: 要绘制的单个帧的宽度和高度
//   alpha: 透明度 (0-255)
inline void drawSprite(int x, int y, IMAGE* img, int sx, int sy, int sw, int sh, BYTE alpha = 255)
{
    if (!img) return;

    HDC hDestDC = GetImageHDC(NULL); // 目标设备上下文
    HDC hSrcDC = GetImageHDC(img);   // 源设备上下文

    BLENDFUNCTION bf = { AC_SRC_OVER, 0, alpha, AC_SRC_ALPHA };

    // 核心修改：使用指定的宽高进行绘制
    AlphaBlend(hDestDC, x, y, sw, sh, hSrcDC, sx, sy, sw, sh, bf);
}

// 辅助函数：加载图片并确保支持透明通道 (32位色)
// 注意：如果图片本身没有 alpha 通道，加载后全屏绘制可能会有黑底，
// 建议在图片编辑软件中预先处理好透明背景。
inline void loadImageWithAlpha(const char* filename, IMAGE& img)
{
    loadimage(&img, filename, -1, -1, true); // true 表示使用 32 位真彩色
}

#endif // TOOLS_H
