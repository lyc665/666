#pragma once
#include"Bullet.h"

// �ӵ��ƶ�������ʵ�֣������ӵ��ٶȸ����ӵ���x����
void Bullet::bulletMove()
{
    Bullet::x += Bullet::bulletSpeed;
}