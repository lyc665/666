// ֲ���ඨ��
#pragma once
class Plant
{
public:
    int sun;
    int hp; // ֲ�������ֵ
    int type; // ֲ�������
    float x; // ֲ���x����
    float y; // ֲ���y����
    int road; // ֲ�����ڵĵ�·���
    bool isLife; // ֲ��Ĵ��״̬
    // ֲ����Ĺ��캯�������ڳ�ʼ��ֲ��ĸ�������
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