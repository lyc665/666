#include"Sun.h"

void Sun::move()
{
    // ���⽵�䶯��
    y += 1;
}

bool Sun::isClicked(int clickX, int clickY)
{
    // �ж��Ƿ���������
    return (clickX >= x - 20 && clickX <= x + 20 &&clickY >= y - 20 && clickY <= y + 20);
}
