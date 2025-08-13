#pragma once
class Sun
{
public:
    int x, y;
    int value;
    bool isSunFlower;
    bool isLife;
    Sun(int x, int y, int value, bool isSunFlower, bool isLife)
    {
        this->x = x;
        this->y = y;
        this->value = value;
        this->isSunFlower = isSunFlower;
        this->isLife = isLife;
    }

    void move();
    bool isClicked(int clickX, int clickY);
};