#pragma once  // ��ֹͷ�ļ��ظ�����
#include <vector>

// �ӵ��ඨ��
class Bullet
{
public:
    float x;  // �ӵ���x����
    float y;  // �ӵ���y����
    int harm; // �ӵ����˺�ֵ
    int road; // �ӵ����ڵĵ�·���
    float bulletSpeed; // �ӵ����ƶ��ٶ�
    bool isLife; // �ӵ��Ĵ��״̬

    // �ӵ���Ĺ��캯�������ڳ�ʼ���ӵ��ĸ�������
    Bullet(float x, float y, int harm, int road, float bulletSpeed, bool isLife)
    {
        this->x = x;
        this->y = y;
        this->harm = harm;
        this->road = road;
        this->bulletSpeed = bulletSpeed;
        this->isLife = isLife;
    }
    void bulletMove(); // �ӵ��ƶ��ĺ�������
};