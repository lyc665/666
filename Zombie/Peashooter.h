#include"Plant.h"
#include"Bullet.h"

using namespace std;

class Peashooter : public Plant
{
public:
	vector<Bullet>bullet; // ֲ�﷢����ӵ�����
	Peashooter(int sun,int hp, int type, float x, float y, int road, bool isLife) :Plant(sun,hp, type, x, y, road, isLife)
	{

	}
};