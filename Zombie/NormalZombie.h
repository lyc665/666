#pragma once  // ��ֹͷ�ļ��ظ�����
#include "Zombie.h"
using namespace std;
// ʹ��public�̳�
class NormalZombie : public Zombie
{
public:
    // �����๹�캯������ʽ���û��๹�캯��
    NormalZombie(int hp, int type, float x, float y, int road, int attack, float speed, bool isLife) : Zombie(hp, type, x, y, road, attack, speed, isLife)
    {
        
    }

    void ZombieMove(); // ��ʬ�ƶ��ĺ�������
};