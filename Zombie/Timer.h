#include <ctime>

class Timer
{
public:
    long long t1;

    Timer()
    {
        t1 = 0;
    }
    bool timer(int ms);
};