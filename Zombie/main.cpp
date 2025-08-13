#include"function.h"
using namespace std;

// 程序入口函数
int main()
{
    initGame(); // 初始化游戏
    music(); // 播放游戏音乐
    //start(); // 开始游戏的开场动画
    while (1) // 进入无限循环，保持游戏运行
    {
        playGame(); // 执行游戏的主循环逻辑
    }
    return 0; // 程序正常退出
}