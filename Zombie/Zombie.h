// ��ʬ�ඨ��
class Zombie
{
public:
    int hp; // ��ʬ������ֵ
    int type; // ��ʬ������
    float x; // ��ʬ��x����
    float y; // ��ʬ��y����
    int road; // ��ʬ���ڵĵ�·���
    int attack; // ��ʬ�Ĺ�����
    float speed; // ��ʬ���ƶ��ٶ�
    bool isLife; // ��ʬ�Ĵ��״̬

    // ��ʬ��Ĺ��캯�������ڳ�ʼ����ʬ�ĸ�������
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