#include"function.h"
using namespace std;

// ������ں���
int main()
{
    initGame(); // ��ʼ����Ϸ
    music(); // ������Ϸ����
    //start(); // ��ʼ��Ϸ�Ŀ�������
    while (1) // ��������ѭ����������Ϸ����
    {
        playGame(); // ִ����Ϸ����ѭ���߼�
    }
    return 0; // ���������˳�
}