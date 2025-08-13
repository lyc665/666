// 僵尸类定义
class Zombie
{
public:
    int hp; // 僵尸的生命值
    int type; // 僵尸的类型
    float x; // 僵尸的x坐标
    float y; // 僵尸的y坐标
    int road; // 僵尸所在的道路编号
    int attack; // 僵尸的攻击力
    float speed; // 僵尸的移动速度
    bool isLife; // 僵尸的存活状态

    // 僵尸类的构造函数，用于初始化僵尸的各项属性
    Zombie(int hp, int type, float x, float y, int road, int attack, float speed, bool isLife)
    {
        this->hp = hp;
        this->type = type;
        this->x = x;
        this->y = y;
        this->road = road;
        this->attack = attack;
        this->speed = speed;
        this->isLife = isLife;
    }

    virtual ~Zombie(){}
};