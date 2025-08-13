#pragma once  // 防止头文件重复包含
#include "Zombie.h"
using namespace std;
// 使用public继承
class NormalZombie : public Zombie
{
public:
    // 派生类构造函数，显式调用基类构造函数
    NormalZombie(int hp, int type, float x, float y, int road, int attack, float speed, bool isLife) : Zombie(hp, type, x, y, road, attack, speed, isLife)
    {
        
    }

    void ZombieMove(); // 僵尸移动的函数声明
};