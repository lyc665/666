#include "Timer.h"

bool Timer::timer(int ms)
{
    long long currentTime = clock();
    if ((currentTime - t1) * 1000 / CLOCKS_PER_SEC > ms)
    {
        t1 = currentTime;
        return true;
    }
    return false;
}