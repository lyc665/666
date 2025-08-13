// 初始化游戏，包括初始化图形窗口和加载图片
void initGame();
// 播放游戏音乐
void music();
// 开始游戏的开场动画
void start();
// 游戏的主循环逻辑
void playGame();
// 普通模式的游戏逻辑
void normalMode();
// 迷你模式的游戏逻辑
void miniMode();
// 绘制僵尸到屏幕上
void putZombie();
// 处理点击植物卡片的事件
void clickPlant();
// 绘制植物卡片和铲子
void putCardPlantAndShovel();
// 判断放置植物的位置是否合法
void judgePutPlantPos();
// 判断是否移除植物
void judgeRemovePlant();
// 绘制草地上的植物
void drawGrassPlant();
// 删除死亡的子弹、僵尸和植物
void delBulletZombiePlant();
// 僵尸吃植物的逻辑
bool ZombieEatPlant(int i);
//显示剩余阳光 
void showSunNums();
//创造阳光
void createNatureSun();
//绘制阳光
void drawSun();
//点击阳光
void clickSun();