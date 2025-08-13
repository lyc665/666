#include"Plant.h"
#include"Bullet.h"

using namespace std;

class Peashooter : public Plant
{
public:
	vector<Bullet>bullet; // 植物发射的子弹数组
	Peashooter(int sun,int hp, int type, float x, float y, int road, bool isLife) :Plant(sun,hp, type, x, y, road, isLife)
	{

	}
};