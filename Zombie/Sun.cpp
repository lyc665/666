#include"Sun.h"

void Sun::move()
{
    // 阳光降落动画
    y += 1;
}

bool Sun::isClicked(int clickX, int clickY)
{
    // 判断是否点击了阳光
    return (clickX >= x - 20 && clickX <= x + 20 &&clickY >= y - 20 && clickY <= y + 20);
}
