#pragma once
#include"Bullet.h"

// 子弹移动函数的实现，根据子弹速度更新子弹的x坐标
void Bullet::bulletMove()
{
    Bullet::x += Bullet::bulletSpeed;
}