#pragma once  // 防止头文件重复包含
#include <vector>

// 子弹类定义
class Bullet
{
public:
    float x;  // 子弹的x坐标
    float y;  // 子弹的y坐标
    int harm; // 子弹的伤害值
    int road; // 子弹所在的道路编号
    float bulletSpeed; // 子弹的移动速度
    bool isLife; // 子弹的存活状态

    // 子弹类的构造函数，用于初始化子弹的各项属性
    Bullet(float x, float y, int harm, int road, float bulletSpeed, bool isLife)
    {
        this->x = x;
        this->y = y;
        this->harm = harm;
        this->road = road;
        this->bulletSpeed = bulletSpeed;
        this->isLife = isLife;
    }
    void bulletMove(); // 子弹移动的函数声明
};