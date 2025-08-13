#pragma once
#include<graphics.h>  // 图形库头文件
#include<mmsystem.h>  // 多媒体系统头文件
#pragma comment(lib,"winmm.lib")  // 链接多媒体库
#include<Windows.h>  // Windows系统头文件
#include<iostream>  // 输入输出流头文件
#include "NormalZombie.h"  // 普通僵尸类头文件
#include"Peashooter.h"  // 豌豆射手类头文件
#include"SunFlower.h"
#include"Sun.h"// 阳光类头文件
#include"Timer.h"  // 定时器类头文件
#include <chrono>  // 时间库头文件
#include<stdlib.h>  // 标准库头文件
#include<string>
#include "function.h"

#define windows_wide 1100  // 定义窗口宽度
#define windows_high 600  // 定义窗口高度

//bool gameClearRecords[20] = {false};  // 游戏通关记录数组，此处注释掉
int sunNums = 500;  // 初始阳光值
IMAGE img[100];  // 图片数组，用于存储游戏中的各种图片
ExMessage msg = { 0 };  // 鼠标消息结构体
Timer Time[50];  // 定时器数组，用于控制不同的时间间隔

// 存储存活的僵尸数组，元素类型为Zombie类
vector<Zombie*>zombieArrLivel1;
// 存储植物的数组，元素类型为Plant类
vector<Plant*>plantArr;
//存储阳光的数组，元素类型为Sun类
vector<Sun>sun;

// 初始化游戏，包括创建图形窗口和加载图片
void initGame()
{
	initgraph(windows_wide, windows_high, SHOWCONSOLE); // 创建图形窗口，并显示控制台
	char arr[30]; // 用于存储图片文件名的字符数组
	for (int i = 2; i <= 9; i++) // 循环加载部分图片
	{
		sprintf_s(arr, "./img/jmages/%d.png", i); // 生成图片文件名
		loadimage(&img[i], arr, windows_wide, windows_high); // 加载图片
	}
	loadimage(&img[0],"./img2/6/背景1(background1).jpg", 1500, 600);
	loadimage(&img[1], "./img/images/SeedBank.png", 840, 70);
	loadimage(&img[10], "./img/images/ShovelBank.png", 60, 60);
	loadimage(&img[11], "./img/images/1.png", 60, 60);
	loadimage(&img[12], "./img/images/2.png", 60, 60);
	loadimage(&img[13], "./img/images/3.png", 80, 170);
	loadimage(&img[14], "./img/images/4.png", 80, 170);
	loadimage(&img[15], "./img/images/5.png", 50, 70);
	loadimage(&img[16], "./img/images/6.png", 50, 70);
	loadimage(&img[17], "./img/images/7.png", 45, 55);
	loadimage(&img[18], "./img/images/8.png", 45, 55);
    loadimage(&img[32], "./img/images/16.png", 45, 57);
    loadimage(&img[33], "./img/images/17.png", 45, 57);
	loadimage(&img[27], "./img/images/11.png", 60, 60);
    //向日葵
    loadimage(&img[28], "./img/images/12.png", 70, 70);
    loadimage(&img[29], "./img/images/13.png", 70, 70);
    //阳光
    loadimage(&img[30], "./img/images/14.png", 50, 50);
    loadimage(&img[31], "./img/images/15.png", 50, 50);
	//子弹
	loadimage(&img[25], "./img/images/9.png", 25, 25);
	loadimage(&img[26], "./img/images/10.png", 25, 25);
	//僵尸移动图片
	loadimage(&img[19], "./img/images/迈左脚1.png", 80, 170);
	loadimage(&img[20], "./img/images/迈左脚.png", 80, 170);
	loadimage(&img[21], "./img/images/中间1.png", 80, 170);
	loadimage(&img[22], "./img/images/中间.png", 80, 170);
	loadimage(&img[23], "./img/images/迈右脚1.png", 80, 170);
	loadimage(&img[24], "./img/images/迈右脚.png", 80, 170);
}

// 播放游戏音乐
void music()
{
    mciSendString("open ./img/sounds/1.mp3", 0, 0, 0); // 打开音乐文件
    mciSendString("play ./img/sounds/1.mp3 repeat", 0, 0, 0); // 循环播放音乐
}

// 开始游戏的开场动画
void start()
{
    for (int i = 2; i <= 8; i++) // 循环显示开场图片
    {
        putimage(0, 0, &img[i]); // 显示图片
        Sleep(3000); // 暂停3秒
    }
}

static long long num = 0; // 静态变量，用于计数

// 创建敌人（僵尸）
void createEnemy()
{
    if (Time[45].timer(5000)) // 每5秒执行一次
    {
        srand(time(0)); // 初始化随机数种子
        int random = rand() % 5; // 生成0到4之间的随机数
        // 创建一个新的僵尸对象
        zombieArrLivel1.push_back(new  NormalZombie(100, 1, 1100, 20 + 100 * random, random, 20, 0.3, true)); // 将新僵尸添加到存活僵尸数组中
    }
}

// 僵尸吃植物的逻辑
bool ZombieEatPlant(int i)
{
    for (int j = 0; j < plantArr.size(); j++) // 遍历所有植物
    {
        if (zombieArrLivel1[i]->road == plantArr[j]->road && zombieArrLivel1[i]->x < plantArr[j]->x + 50) // 判断僵尸和植物是否在同一路且距离足够近
        {
            if (Time[46].timer(1000)) // 每秒执行一次
            {
                plantArr[j]->hp -= zombieArrLivel1[i]->attack; // 植物生命值减去僵尸攻击力
            }
            return true; // 僵尸正在吃植物，返回true
        }
    }
    return false; // 僵尸没有吃植物，返回false
}

int zombieMoveImgFlag = 0; // 僵尸移动图片的标志

// 绘制僵尸到屏幕上
void putZombie()
{
    createEnemy(); // 创建新的敌人（僵尸）
    if (Time[47].timer(500)) // 每500毫秒执行一次
    {
        zombieMoveImgFlag = (zombieMoveImgFlag + 1) % 3; // 更新僵尸移动图片的标志
    }
    for (int i = 0; i < zombieArrLivel1.size(); i++) // 遍历所有存活的僵尸
    {
        if (zombieArrLivel1[i]->isLife == true) // 判断僵尸是否存活且未在吃植物
        {
            if (zombieArrLivel1[i]->type == 1)
            {
                NormalZombie* zombie = dynamic_cast<NormalZombie*>(zombieArrLivel1[i]);
                switch (zombieMoveImgFlag) // 根据僵尸移动图片的标志选择不同的图片
                {
                    case 0:
                    {
                        putimage(zombie->x, zombie->y, &img[19], NOTSRCERASE); // 绘制图片
                        putimage(zombieArrLivel1[i]->x, zombieArrLivel1[i]->y, &img[20], SRCINVERT); // 绘制图片
                        break;
                    }
                    case 1:
                    {
                        putimage(zombie->x, zombie->y, &img[21], NOTSRCERASE); // 绘制图片
                        putimage(zombie->x, zombie->y, &img[22], SRCINVERT); // 绘制图片
                        break;
                    }
                    case 2:
                    {
                        putimage(zombie->x, zombie->y, &img[23], NOTSRCERASE); // 绘制图片
                        putimage(zombie->x, zombie->y, &img[24], SRCINVERT); // 绘制图片
                        break;
                    }
                }
                if (!ZombieEatPlant(i)) // 如果僵尸没有在吃植物
                    zombie->ZombieMove(); // 僵尸移动
            }
        }
        else
        {
            delete zombieArrLivel1[i];
            zombieArrLivel1.erase(zombieArrLivel1.begin() + i); // 移除死亡的僵尸
        }
    }
}

bool clickCardPlant[15] = { false }; // 记录植物卡片是否被点击的数组
bool clickShovel = false; // 记录铲子是否被点击的标志
int clickFlag = 1; // 点击标志，1表示未点击植物卡片或铲子

// 处理点击植物卡片的事件
void clickPlant()
{
    if (msg.x > 145 && msg.x < 190 && msg.y > 7 && msg.y < 60) // 判断是否点击了特定的植物卡片
    {
        clickCardPlant[1] = true; // 标记该植物卡片已被点击
        clickFlag = 0; // 更新点击标志
    }
    if (msg.x > 190 && msg.x < 235 && msg.y > 7 && msg.y < 60) // 判断是否点击了特定的植物卡片
    {
        clickCardPlant[2] = true; // 标记该植物卡片已被点击
        clickFlag = 0; // 更新点击标志
    }
    if (msg.x > 845 && msg.x < 897 && msg.y > 4 && msg.y < 57) // 判断是否点击了铲子
    {
        clickShovel = true; // 标记铲子已被点击
        clickFlag = 0; // 更新点击标志
    }
}

// 绘制植物卡片和铲子
void putCardPlantAndShovel()
{
    if (clickShovel == true) // 如果铲子已被点击
    {
        putimage(840, 0, &img[11], NOTSRCERASE); // 绘制相关图片
        putimage(840, 0, &img[27], SRCINVERT); // 绘制相关图片
    }
    else
    {
        putimage(840, 0, &img[11], NOTSRCERASE); // 绘制相关图片
        putimage(840, 0, &img[12], SRCINVERT); // 绘制相关图片
    }

    if (clickCardPlant[1] == false) // 如果特定植物卡片未被点击
        putimage(145, 7, &img[17]); // 绘制相关图片
    else
        putimage(145, 7, &img[18]); // 绘制相关图片

    if (clickCardPlant[2] == false) // 如果特定植物卡片未被点击
        putimage(190, 7, &img[32]); // 绘制相关图片
    else
        putimage(190, 7, &img[33]); // 绘制相关图片

}

// 判断放置植物的位置是否合法
void judgePutPlantPos()
{
    for (int i = 0; i < 15; i++) // 遍历所有植物卡片
    {
        if (clickCardPlant[i] == true) // 如果该植物卡片已被点击
        {
            if (msg.x > 276 && msg.x < 1047 && msg.y > 84 && msg.y < 564) // 判断点击位置是否在合法范围内
            {
                // 创建一个新的植物对象
                if (i == 1)
                {
                    plantArr.push_back(new Peashooter(100,100, i, ((msg.x - 276) / 90) * 90 + 276, ((msg.y - 114) / 90) * 90 + 114, (msg.y - 80) / 90, true)); // 将新植物添加到植物数组中
                    sunNums -= 100;
                }
                if (i == 2)
                {
                    plantArr.push_back(new SunFlower(50,100, i, ((msg.x - 276) / 90) * 90 + 276, ((msg.y - 114) / 90) * 90 + 114, (msg.y - 80) / 90, true)); // 将新植物添加到植物数组中
                    // 初始化对应的定时器
                    int index = plantArr.size() - 1;
                    Time[index].t1 = clock();
                    sunNums -= 50;
                }
            }
            clickCardPlant[i] = false; // 标记该植物卡片未被点击
            clickFlag = 1; // 更新点击标志
            break; // 跳出循环
        }
    }
}

// 绘制草地上的植物和删除false的对象
void drawGrassPlant()
{
    for (int i = plantArr.size() - 1; i >= 0; i--) // 从后往前遍历所有植物
    {
        if (plantArr[i]->isLife == true) // 判断植物是否存活
        {
            if (plantArr[i]->type == 1) // 豌豆射手
            {
                Peashooter* peashooter = dynamic_cast<Peashooter*>(plantArr[i]);
                putimage(peashooter->x, peashooter->y, &img[15], NOTSRCERASE); // 绘制图片
                putimage(peashooter->x, peashooter->y, &img[16], SRCINVERT); // 绘制图片
                for (int j = peashooter->bullet.size() - 1; j >= 0; j--) // 遍历豌豆射手发射的所有子弹
                {
                    if (peashooter->bullet[j].isLife == true) // 判断子弹是否存活
                    {
                        putimage(peashooter->bullet[j].x, peashooter->bullet[j].y, &img[25], NOTSRCERASE); // 绘制子弹图片
                        putimage(peashooter->bullet[j].x, peashooter->bullet[j].y, &img[26], SRCINVERT); // 绘制子弹图片
                        peashooter->bullet[j].bulletMove(); // 子弹移动
                    }
                    else
                    {
                        peashooter->bullet.erase(peashooter->bullet.begin() + j); // 移除死亡的子弹
                    }
                }
                // 豌豆射手发射子弹的逻辑
                if (Time[i].timer(3000)) // 每3秒执行一次
                {
                    // 创建一个新的子弹对象
                    Bullet bullet(peashooter->x + 25, peashooter->y + 7, 10, peashooter->road, 2, true);
                    peashooter->bullet.push_back(bullet); // 将子弹添加到豌豆射手的子弹数组中
                }
            }
            if (plantArr[i]->type == 2) // 向日葵
            {
                SunFlower* sunFlower = dynamic_cast<SunFlower*>(plantArr[i]);
                putimage(sunFlower->x, sunFlower->y, &img[28], NOTSRCERASE); // 绘制子弹图片
                putimage(sunFlower->x, sunFlower->y, &img[29], SRCINVERT); // 绘制子弹图片
                if (Time[i].timer(15000)) // 每15秒执行一次
                {
                    // 创建一个新的阳光对象
                    Sun s(sunFlower->x, sunFlower->y, 25, true, true);
                    sun.push_back(s);
                }
            }
        }
        else
        {
            delete plantArr[i]; // 释放植物对象的内存
            plantArr.erase(plantArr.begin() + i); // 移除死亡的植物
        }
    }
}

// 标记死亡的 子弹 僵尸 植物 阳光
void delBulletZombiePlant()
{
    for (int i = plantArr.size() - 1; i >= 0; i--) // 从后往前遍历所有植物
    {
        if (plantArr[i]->type == 1) // 豌豆射手
        {
            Peashooter* plant = dynamic_cast<Peashooter*>(plantArr[i]);
            for (int j = plant->bullet.size() - 1; j >= 0; j--) // 遍历植物发射的所有子弹
            {
                for (int k = zombieArrLivel1.size() - 1; k >= 0; k--) // 遍历所有存活的僵尸
                {
                    if (plant->bullet[j].x < zombieArrLivel1[k]->x + 80 && plant->bullet[j].x > zombieArrLivel1[k]->x && zombieArrLivel1[k]->road == plant->bullet[j].road) // 判断子弹是否击中僵尸
                    {
                        plant->bullet[j].isLife = false; // 标记子弹死亡
                        zombieArrLivel1[k]->hp -= plant->bullet[j].harm; // 僵尸生命值减去子弹伤害
                        if (zombieArrLivel1[k]->hp <= 0) // 判断僵尸是否死亡
                        {
                            zombieArrLivel1[k]->isLife = false; // 标记僵尸死亡
                        }
                    }
                    if (plant->bullet[j].x > windows_wide) // 判断子弹是否超出屏幕范围
                    {
                        plant->bullet[j].isLife = false; // 标记子弹死亡
                    }
                }
            }
        }
        if (plantArr[i]->hp <= 0) // 判断植物是否死亡
        {
            plantArr[i]->isLife = false; // 标记植物死亡
        }
    }
}

// 判断是否移除植物
void judgeRemovePlant()
{
    if (clickShovel == true) // 如果铲子已被点击
    {
        for (int i = plantArr.size() - 1; i >= 0; i--) // 从后往前遍历所有植物
        {
            if (msg.x > plantArr[i]->x && msg.x < plantArr[i]->x + 50 && (msg.y - 80) / 90 == plantArr[i]->road) // 判断点击位置是否在植物范围内
            {
                plantArr.erase(plantArr.begin() + i); // 移除该植物
            }
        }
        clickShovel = false; // 标记铲子未被点击
        clickFlag = 1; // 更新点击标志
    }
}

void showSunNums()
{
    char sunText[20];
    setbkmode(TRANSPARENT);// 设置文字背景为透明模式
    settextcolor(BLACK);// 设置文字颜色和字体
    settextstyle(20, 20, _T("宋体"));
    sprintf_s(sunText, "%d", sunNums);
    string S = to_string(sunNums);//用于居中对齐
    outtextxy(20+(105-S.size()*20)/2, 50, sunText);
}

void createNatureSun()
{
    srand(time(0));
    int x = rand() % (windows_wide-350);
    Sun s(x,0,25, false,true);
    sun.push_back(s);
}

void drawSun()
{
    for (int i = 0; i < sun.size(); i++)
    {
        putimage(sun[i].x, sun[i].y, &img[30], NOTSRCERASE); // 绘制图片
        putimage(sun[i].x, sun[i].y, &img[31], SRCINVERT); // 绘制图片
        if (sun[i].isSunFlower == false)
        {
            sun[i].move();
        }
    }
}

void clickSun()
{
    for (int i = sun.size()-1; i >= 0; i--)
    {
        if (msg.x > sun[i].x && msg.x < sun[i].x+50 && msg.y > sun[i].y && msg.y < sun[i].y+50) // 判断是否点击了阳光
        {
            sunNums += sun[i].value;
            sun.erase(sun.begin()+i);
        }
    }
}

// 普通模式的游戏逻辑
void normalMode()
{
    auto lastFrameTime = std::chrono::steady_clock::now(); // 记录上一帧的时间
    const int frameDelay = 16; // 帧延迟，目标帧率约为60FPS
    while (1) // 进入无限循环
    {
        auto currentTime = std::chrono::steady_clock::now(); // 获取当前时间
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastFrameTime).count(); // 计算时间差
        // 确保帧率稳定，不足的时间进行睡眠
        if (elapsedTime < frameDelay) {
            Sleep(frameDelay - elapsedTime);
        }
        lastFrameTime = std::chrono::steady_clock::now(); // 更新上一帧的时间
        BeginBatchDraw(); // 开始批量绘图
        putimage(0, 0, &img[0]); // 绘制背景图片
        putimage(0, 0, &img[1]); // 绘制种子银行图片
        putimage(840, 0, &img[10]); // 绘制铲子银行图片
        putCardPlantAndShovel(); // 绘制植物卡片和铲子
        drawGrassPlant(); // 绘制草地上的植物
        putZombie(); // 绘制僵尸
        delBulletZombiePlant(); // 删除死亡的子弹、僵尸和植物
        if (Time[49].timer(5000))
        {
            createNatureSun();
        }
        showSunNums();//显示阳光数量
        drawSun();
        EndBatchDraw(); // 结束批量绘图
        while (peekmessage(&msg, EM_MOUSE)) // 处理鼠标消息
        {
            switch (msg.message)
            {
                case WM_LBUTTONDOWN: // 鼠标左键按下事件
                {
                    cout << "x:" << msg.x << " " << "y:" << msg.y << "\n"; // 输出鼠标点击的坐标
                    clickSun();
                    if (clickFlag == 1) // 如果未点击植物卡片或铲子
                    {
                        clickPlant(); // 处理点击植物卡片的事件
                    }
                    else
                    {
                        judgePutPlantPos(); // 判断放置植物的位置是否合法
                        judgeRemovePlant(); // 判断是否移除植物
                    }
                }
            }
        }
    }
}

// 迷你模式的游戏逻辑，此处为空
void miniMode()
{

}

// 游戏的主循环逻辑
void playGame()
{
    while (1) // 进入无限循环
    {
        BeginBatchDraw(); // 开始批量绘图
        putimage(0, 0, &img[9]); // 绘制图片
        Sleep(16); // 暂停16毫秒
        EndBatchDraw(); // 结束批量绘图

        while (peekmessage(&msg, EM_MOUSE)) // 处理鼠标消息
        {
            switch (msg.message)
            {
            case WM_LBUTTONDOWN: // 鼠标左键按下事件
            {
                if (msg.y > msg.x * 0.1921 + 29.28 && msg.y < 0.1935 * msg.x + 102.71 && msg.y > -12.25 * msg.x + 6418.25 && msg.y < -5.5 * msg.x + 4310) // 判断点击位置是否进入普通模式
                {
                    // 进入普通模式
                    mciSendString("close ./img/sounds/1.mp3", 0, 0, 0); // 关闭当前音乐
                    normalMode(); // 执行普通模式的游戏逻辑
                    music(); // 播放游戏音乐
                    break;
                }
                if (msg.y > 0.2182 * msg.x + 289.95 && msg.y < 0.2022 * msg.x + 394.61 && msg.y > -0.5044 * msg.x + 579.25 && msg.y < -0.6068 * msg.x + 845.62) // 判断点击位置是否进入迷你模式
                {
                    // 进入迷你模式
                    mciSendString("close ./img/sounds/1.mp3", 0, 0, 0); // 关闭当前音乐
                    miniMode(); // 执行迷你模式的游戏逻辑
                    music(); // 播放游戏音乐
                    break;
                }
            }
            }
        }
    }
}