#pragma once
#include<graphics.h>  // ͼ�ο�ͷ�ļ�
#include<mmsystem.h>  // ��ý��ϵͳͷ�ļ�
#pragma comment(lib,"winmm.lib")  // ���Ӷ�ý���
#include<Windows.h>  // Windowsϵͳͷ�ļ�
#include<iostream>  // ���������ͷ�ļ�
#include "NormalZombie.h"  // ��ͨ��ʬ��ͷ�ļ�
#include"Peashooter.h"  // �㶹������ͷ�ļ�
#include"SunFlower.h"
#include"Sun.h"// ������ͷ�ļ�
#include"Timer.h"  // ��ʱ����ͷ�ļ�
#include <chrono>  // ʱ���ͷ�ļ�
#include<stdlib.h>  // ��׼��ͷ�ļ�
#include<string>
#include "function.h"

#define windows_wide 1100  // ���崰�ڿ��
#define windows_high 600  // ���崰�ڸ߶�

//bool gameClearRecords[20] = {false};  // ��Ϸͨ�ؼ�¼���飬�˴�ע�͵�
int sunNums = 500;  // ��ʼ����ֵ
IMAGE img[100];  // ͼƬ���飬���ڴ洢��Ϸ�еĸ���ͼƬ
ExMessage msg = { 0 };  // �����Ϣ�ṹ��
Timer Time[50];  // ��ʱ�����飬���ڿ��Ʋ�ͬ��ʱ����

// �洢���Ľ�ʬ���飬Ԫ������ΪZombie��
vector<Zombie*>zombieArrLivel1;
// �洢ֲ������飬Ԫ������ΪPlant��
vector<Plant*>plantArr;
//�洢��������飬Ԫ������ΪSun��
vector<Sun>sun;

// ��ʼ����Ϸ����������ͼ�δ��ںͼ���ͼƬ
void initGame()
{
	initgraph(windows_wide, windows_high, SHOWCONSOLE); // ����ͼ�δ��ڣ�����ʾ����̨
	char arr[30]; // ���ڴ洢ͼƬ�ļ������ַ�����
	for (int i = 2; i <= 9; i++) // ѭ�����ز���ͼƬ
	{
		sprintf_s(arr, "./img/jmages/%d.png", i); // ����ͼƬ�ļ���
		loadimage(&img[i], arr, windows_wide, windows_high); // ����ͼƬ
	}
	loadimage(&img[0],"./img2/6/����1(background1).jpg", 1500, 600);
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
    //���տ�
    loadimage(&img[28], "./img/images/12.png", 70, 70);
    loadimage(&img[29], "./img/images/13.png", 70, 70);
    //����
    loadimage(&img[30], "./img/images/14.png", 50, 50);
    loadimage(&img[31], "./img/images/15.png", 50, 50);
	//�ӵ�
	loadimage(&img[25], "./img/images/9.png", 25, 25);
	loadimage(&img[26], "./img/images/10.png", 25, 25);
	//��ʬ�ƶ�ͼƬ
	loadimage(&img[19], "./img/images/�����1.png", 80, 170);
	loadimage(&img[20], "./img/images/�����.png", 80, 170);
	loadimage(&img[21], "./img/images/�м�1.png", 80, 170);
	loadimage(&img[22], "./img/images/�м�.png", 80, 170);
	loadimage(&img[23], "./img/images/���ҽ�1.png", 80, 170);
	loadimage(&img[24], "./img/images/���ҽ�.png", 80, 170);
}

// ������Ϸ����
void music()
{
    mciSendString("open ./img/sounds/1.mp3", 0, 0, 0); // �������ļ�
    mciSendString("play ./img/sounds/1.mp3 repeat", 0, 0, 0); // ѭ����������
}

// ��ʼ��Ϸ�Ŀ�������
void start()
{
    for (int i = 2; i <= 8; i++) // ѭ����ʾ����ͼƬ
    {
        putimage(0, 0, &img[i]); // ��ʾͼƬ
        Sleep(3000); // ��ͣ3��
    }
}

static long long num = 0; // ��̬���������ڼ���

// �������ˣ���ʬ��
void createEnemy()
{
    if (Time[45].timer(5000)) // ÿ5��ִ��һ��
    {
        srand(time(0)); // ��ʼ�����������
        int random = rand() % 5; // ����0��4֮��������
        // ����һ���µĽ�ʬ����
        zombieArrLivel1.push_back(new  NormalZombie(100, 1, 1100, 20 + 100 * random, random, 20, 0.3, true)); // ���½�ʬ��ӵ���ʬ������
    }
}

// ��ʬ��ֲ����߼�
bool ZombieEatPlant(int i)
{
    for (int j = 0; j < plantArr.size(); j++) // ��������ֲ��
    {
        if (zombieArrLivel1[i]->road == plantArr[j]->road && zombieArrLivel1[i]->x < plantArr[j]->x + 50) // �жϽ�ʬ��ֲ���Ƿ���ͬһ·�Ҿ����㹻��
        {
            if (Time[46].timer(1000)) // ÿ��ִ��һ��
            {
                plantArr[j]->hp -= zombieArrLivel1[i]->attack; // ֲ������ֵ��ȥ��ʬ������
            }
            return true; // ��ʬ���ڳ�ֲ�����true
        }
    }
    return false; // ��ʬû�г�ֲ�����false
}

int zombieMoveImgFlag = 0; // ��ʬ�ƶ�ͼƬ�ı�־

// ���ƽ�ʬ����Ļ��
void putZombie()
{
    createEnemy(); // �����µĵ��ˣ���ʬ��
    if (Time[47].timer(500)) // ÿ500����ִ��һ��
    {
        zombieMoveImgFlag = (zombieMoveImgFlag + 1) % 3; // ���½�ʬ�ƶ�ͼƬ�ı�־
    }
    for (int i = 0; i < zombieArrLivel1.size(); i++) // �������д��Ľ�ʬ
    {
        if (zombieArrLivel1[i]->isLife == true) // �жϽ�ʬ�Ƿ�����δ�ڳ�ֲ��
        {
            if (zombieArrLivel1[i]->type == 1)
            {
                NormalZombie* zombie = dynamic_cast<NormalZombie*>(zombieArrLivel1[i]);
                switch (zombieMoveImgFlag) // ���ݽ�ʬ�ƶ�ͼƬ�ı�־ѡ��ͬ��ͼƬ
                {
                    case 0:
                    {
                        putimage(zombie->x, zombie->y, &img[19], NOTSRCERASE); // ����ͼƬ
                        putimage(zombieArrLivel1[i]->x, zombieArrLivel1[i]->y, &img[20], SRCINVERT); // ����ͼƬ
                        break;
                    }
                    case 1:
                    {
                        putimage(zombie->x, zombie->y, &img[21], NOTSRCERASE); // ����ͼƬ
                        putimage(zombie->x, zombie->y, &img[22], SRCINVERT); // ����ͼƬ
                        break;
                    }
                    case 2:
                    {
                        putimage(zombie->x, zombie->y, &img[23], NOTSRCERASE); // ����ͼƬ
                        putimage(zombie->x, zombie->y, &img[24], SRCINVERT); // ����ͼƬ
                        break;
                    }
                }
                if (!ZombieEatPlant(i)) // �����ʬû���ڳ�ֲ��
                    zombie->ZombieMove(); // ��ʬ�ƶ�
            }
        }
        else
        {
            delete zombieArrLivel1[i];
            zombieArrLivel1.erase(zombieArrLivel1.begin() + i); // �Ƴ������Ľ�ʬ
        }
    }
}

bool clickCardPlant[15] = { false }; // ��¼ֲ�￨Ƭ�Ƿ񱻵��������
bool clickShovel = false; // ��¼�����Ƿ񱻵���ı�־
int clickFlag = 1; // �����־��1��ʾδ���ֲ�￨Ƭ�����

// ������ֲ�￨Ƭ���¼�
void clickPlant()
{
    if (msg.x > 145 && msg.x < 190 && msg.y > 7 && msg.y < 60) // �ж��Ƿ������ض���ֲ�￨Ƭ
    {
        clickCardPlant[1] = true; // ��Ǹ�ֲ�￨Ƭ�ѱ����
        clickFlag = 0; // ���µ����־
    }
    if (msg.x > 190 && msg.x < 235 && msg.y > 7 && msg.y < 60) // �ж��Ƿ������ض���ֲ�￨Ƭ
    {
        clickCardPlant[2] = true; // ��Ǹ�ֲ�￨Ƭ�ѱ����
        clickFlag = 0; // ���µ����־
    }
    if (msg.x > 845 && msg.x < 897 && msg.y > 4 && msg.y < 57) // �ж��Ƿ����˲���
    {
        clickShovel = true; // ��ǲ����ѱ����
        clickFlag = 0; // ���µ����־
    }
}

// ����ֲ�￨Ƭ�Ͳ���
void putCardPlantAndShovel()
{
    if (clickShovel == true) // ��������ѱ����
    {
        putimage(840, 0, &img[11], NOTSRCERASE); // �������ͼƬ
        putimage(840, 0, &img[27], SRCINVERT); // �������ͼƬ
    }
    else
    {
        putimage(840, 0, &img[11], NOTSRCERASE); // �������ͼƬ
        putimage(840, 0, &img[12], SRCINVERT); // �������ͼƬ
    }

    if (clickCardPlant[1] == false) // ����ض�ֲ�￨Ƭδ�����
        putimage(145, 7, &img[17]); // �������ͼƬ
    else
        putimage(145, 7, &img[18]); // �������ͼƬ

    if (clickCardPlant[2] == false) // ����ض�ֲ�￨Ƭδ�����
        putimage(190, 7, &img[32]); // �������ͼƬ
    else
        putimage(190, 7, &img[33]); // �������ͼƬ

}

// �жϷ���ֲ���λ���Ƿ�Ϸ�
void judgePutPlantPos()
{
    for (int i = 0; i < 15; i++) // ��������ֲ�￨Ƭ
    {
        if (clickCardPlant[i] == true) // �����ֲ�￨Ƭ�ѱ����
        {
            if (msg.x > 276 && msg.x < 1047 && msg.y > 84 && msg.y < 564) // �жϵ��λ���Ƿ��ںϷ���Χ��
            {
                // ����һ���µ�ֲ�����
                if (i == 1)
                {
                    plantArr.push_back(new Peashooter(100,100, i, ((msg.x - 276) / 90) * 90 + 276, ((msg.y - 114) / 90) * 90 + 114, (msg.y - 80) / 90, true)); // ����ֲ����ӵ�ֲ��������
                    sunNums -= 100;
                }
                if (i == 2)
                {
                    plantArr.push_back(new SunFlower(50,100, i, ((msg.x - 276) / 90) * 90 + 276, ((msg.y - 114) / 90) * 90 + 114, (msg.y - 80) / 90, true)); // ����ֲ����ӵ�ֲ��������
                    // ��ʼ����Ӧ�Ķ�ʱ��
                    int index = plantArr.size() - 1;
                    Time[index].t1 = clock();
                    sunNums -= 50;
                }
            }
            clickCardPlant[i] = false; // ��Ǹ�ֲ�￨Ƭδ�����
            clickFlag = 1; // ���µ����־
            break; // ����ѭ��
        }
    }
}

// ���Ʋݵ��ϵ�ֲ���ɾ��false�Ķ���
void drawGrassPlant()
{
    for (int i = plantArr.size() - 1; i >= 0; i--) // �Ӻ���ǰ��������ֲ��
    {
        if (plantArr[i]->isLife == true) // �ж�ֲ���Ƿ���
        {
            if (plantArr[i]->type == 1) // �㶹����
            {
                Peashooter* peashooter = dynamic_cast<Peashooter*>(plantArr[i]);
                putimage(peashooter->x, peashooter->y, &img[15], NOTSRCERASE); // ����ͼƬ
                putimage(peashooter->x, peashooter->y, &img[16], SRCINVERT); // ����ͼƬ
                for (int j = peashooter->bullet.size() - 1; j >= 0; j--) // �����㶹���ַ���������ӵ�
                {
                    if (peashooter->bullet[j].isLife == true) // �ж��ӵ��Ƿ���
                    {
                        putimage(peashooter->bullet[j].x, peashooter->bullet[j].y, &img[25], NOTSRCERASE); // �����ӵ�ͼƬ
                        putimage(peashooter->bullet[j].x, peashooter->bullet[j].y, &img[26], SRCINVERT); // �����ӵ�ͼƬ
                        peashooter->bullet[j].bulletMove(); // �ӵ��ƶ�
                    }
                    else
                    {
                        peashooter->bullet.erase(peashooter->bullet.begin() + j); // �Ƴ��������ӵ�
                    }
                }
                // �㶹���ַ����ӵ����߼�
                if (Time[i].timer(3000)) // ÿ3��ִ��һ��
                {
                    // ����һ���µ��ӵ�����
                    Bullet bullet(peashooter->x + 25, peashooter->y + 7, 10, peashooter->road, 2, true);
                    peashooter->bullet.push_back(bullet); // ���ӵ���ӵ��㶹���ֵ��ӵ�������
                }
            }
            if (plantArr[i]->type == 2) // ���տ�
            {
                SunFlower* sunFlower = dynamic_cast<SunFlower*>(plantArr[i]);
                putimage(sunFlower->x, sunFlower->y, &img[28], NOTSRCERASE); // �����ӵ�ͼƬ
                putimage(sunFlower->x, sunFlower->y, &img[29], SRCINVERT); // �����ӵ�ͼƬ
                if (Time[i].timer(15000)) // ÿ15��ִ��һ��
                {
                    // ����һ���µ��������
                    Sun s(sunFlower->x, sunFlower->y, 25, true, true);
                    sun.push_back(s);
                }
            }
        }
        else
        {
            delete plantArr[i]; // �ͷ�ֲ�������ڴ�
            plantArr.erase(plantArr.begin() + i); // �Ƴ�������ֲ��
        }
    }
}

// ��������� �ӵ� ��ʬ ֲ�� ����
void delBulletZombiePlant()
{
    for (int i = plantArr.size() - 1; i >= 0; i--) // �Ӻ���ǰ��������ֲ��
    {
        if (plantArr[i]->type == 1) // �㶹����
        {
            Peashooter* plant = dynamic_cast<Peashooter*>(plantArr[i]);
            for (int j = plant->bullet.size() - 1; j >= 0; j--) // ����ֲ�﷢��������ӵ�
            {
                for (int k = zombieArrLivel1.size() - 1; k >= 0; k--) // �������д��Ľ�ʬ
                {
                    if (plant->bullet[j].x < zombieArrLivel1[k]->x + 80 && plant->bullet[j].x > zombieArrLivel1[k]->x && zombieArrLivel1[k]->road == plant->bullet[j].road) // �ж��ӵ��Ƿ���н�ʬ
                    {
                        plant->bullet[j].isLife = false; // ����ӵ�����
                        zombieArrLivel1[k]->hp -= plant->bullet[j].harm; // ��ʬ����ֵ��ȥ�ӵ��˺�
                        if (zombieArrLivel1[k]->hp <= 0) // �жϽ�ʬ�Ƿ�����
                        {
                            zombieArrLivel1[k]->isLife = false; // ��ǽ�ʬ����
                        }
                    }
                    if (plant->bullet[j].x > windows_wide) // �ж��ӵ��Ƿ񳬳���Ļ��Χ
                    {
                        plant->bullet[j].isLife = false; // ����ӵ�����
                    }
                }
            }
        }
        if (plantArr[i]->hp <= 0) // �ж�ֲ���Ƿ�����
        {
            plantArr[i]->isLife = false; // ���ֲ������
        }
    }
}

// �ж��Ƿ��Ƴ�ֲ��
void judgeRemovePlant()
{
    if (clickShovel == true) // ��������ѱ����
    {
        for (int i = plantArr.size() - 1; i >= 0; i--) // �Ӻ���ǰ��������ֲ��
        {
            if (msg.x > plantArr[i]->x && msg.x < plantArr[i]->x + 50 && (msg.y - 80) / 90 == plantArr[i]->road) // �жϵ��λ���Ƿ���ֲ�ﷶΧ��
            {
                plantArr.erase(plantArr.begin() + i); // �Ƴ���ֲ��
            }
        }
        clickShovel = false; // ��ǲ���δ�����
        clickFlag = 1; // ���µ����־
    }
}

void showSunNums()
{
    char sunText[20];
    setbkmode(TRANSPARENT);// �������ֱ���Ϊ͸��ģʽ
    settextcolor(BLACK);// ����������ɫ������
    settextstyle(20, 20, _T("����"));
    sprintf_s(sunText, "%d", sunNums);
    string S = to_string(sunNums);//���ھ��ж���
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
        putimage(sun[i].x, sun[i].y, &img[30], NOTSRCERASE); // ����ͼƬ
        putimage(sun[i].x, sun[i].y, &img[31], SRCINVERT); // ����ͼƬ
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
        if (msg.x > sun[i].x && msg.x < sun[i].x+50 && msg.y > sun[i].y && msg.y < sun[i].y+50) // �ж��Ƿ���������
        {
            sunNums += sun[i].value;
            sun.erase(sun.begin()+i);
        }
    }
}

// ��ͨģʽ����Ϸ�߼�
void normalMode()
{
    auto lastFrameTime = std::chrono::steady_clock::now(); // ��¼��һ֡��ʱ��
    const int frameDelay = 16; // ֡�ӳ٣�Ŀ��֡��ԼΪ60FPS
    while (1) // ��������ѭ��
    {
        auto currentTime = std::chrono::steady_clock::now(); // ��ȡ��ǰʱ��
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastFrameTime).count(); // ����ʱ���
        // ȷ��֡���ȶ��������ʱ�����˯��
        if (elapsedTime < frameDelay) {
            Sleep(frameDelay - elapsedTime);
        }
        lastFrameTime = std::chrono::steady_clock::now(); // ������һ֡��ʱ��
        BeginBatchDraw(); // ��ʼ������ͼ
        putimage(0, 0, &img[0]); // ���Ʊ���ͼƬ
        putimage(0, 0, &img[1]); // ������������ͼƬ
        putimage(840, 0, &img[10]); // ���Ʋ�������ͼƬ
        putCardPlantAndShovel(); // ����ֲ�￨Ƭ�Ͳ���
        drawGrassPlant(); // ���Ʋݵ��ϵ�ֲ��
        putZombie(); // ���ƽ�ʬ
        delBulletZombiePlant(); // ɾ���������ӵ�����ʬ��ֲ��
        if (Time[49].timer(5000))
        {
            createNatureSun();
        }
        showSunNums();//��ʾ��������
        drawSun();
        EndBatchDraw(); // ����������ͼ
        while (peekmessage(&msg, EM_MOUSE)) // ���������Ϣ
        {
            switch (msg.message)
            {
                case WM_LBUTTONDOWN: // �����������¼�
                {
                    cout << "x:" << msg.x << " " << "y:" << msg.y << "\n"; // ��������������
                    clickSun();
                    if (clickFlag == 1) // ���δ���ֲ�￨Ƭ�����
                    {
                        clickPlant(); // ������ֲ�￨Ƭ���¼�
                    }
                    else
                    {
                        judgePutPlantPos(); // �жϷ���ֲ���λ���Ƿ�Ϸ�
                        judgeRemovePlant(); // �ж��Ƿ��Ƴ�ֲ��
                    }
                }
            }
        }
    }
}

// ����ģʽ����Ϸ�߼����˴�Ϊ��
void miniMode()
{

}

// ��Ϸ����ѭ���߼�
void playGame()
{
    while (1) // ��������ѭ��
    {
        BeginBatchDraw(); // ��ʼ������ͼ
        putimage(0, 0, &img[9]); // ����ͼƬ
        Sleep(16); // ��ͣ16����
        EndBatchDraw(); // ����������ͼ

        while (peekmessage(&msg, EM_MOUSE)) // ���������Ϣ
        {
            switch (msg.message)
            {
            case WM_LBUTTONDOWN: // �����������¼�
            {
                if (msg.y > msg.x * 0.1921 + 29.28 && msg.y < 0.1935 * msg.x + 102.71 && msg.y > -12.25 * msg.x + 6418.25 && msg.y < -5.5 * msg.x + 4310) // �жϵ��λ���Ƿ������ͨģʽ
                {
                    // ������ͨģʽ
                    mciSendString("close ./img/sounds/1.mp3", 0, 0, 0); // �رյ�ǰ����
                    normalMode(); // ִ����ͨģʽ����Ϸ�߼�
                    music(); // ������Ϸ����
                    break;
                }
                if (msg.y > 0.2182 * msg.x + 289.95 && msg.y < 0.2022 * msg.x + 394.61 && msg.y > -0.5044 * msg.x + 579.25 && msg.y < -0.6068 * msg.x + 845.62) // �жϵ��λ���Ƿ��������ģʽ
                {
                    // ��������ģʽ
                    mciSendString("close ./img/sounds/1.mp3", 0, 0, 0); // �رյ�ǰ����
                    miniMode(); // ִ������ģʽ����Ϸ�߼�
                    music(); // ������Ϸ����
                    break;
                }
            }
            }
        }
    }
}