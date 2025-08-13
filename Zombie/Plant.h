// 植物类定义
#pragma once
class Plant
{
public:
    int sun;
    int hp; // 植物的生命值
    int type; // 植物的类型
    float x; // 植物的x坐标
    float y; // 植物的y坐标
    int road; // 植物所在的道路编号
    bool isLife; // 植物的存活状态
    // 植物类的构造函数，用于初始化植物的各项属性
    Plant(int sun,int hp, int type, float x, float y, int road, bool isLife)
    {
        this->sun = sun;
        this->hp = hp;
        this->type = type;
        this->x = x;
        this->y = y;
        this->road = road;
        this->isLife = isLife;
    }
    virtual ~Plant() {}
};