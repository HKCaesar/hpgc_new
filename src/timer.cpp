#include "timer.h"

#include <thread>
#include <ctime>

namespace hpgc {

using namespace std;
using namespace std::chrono;

void Sleep(int t)
{
    std::this_thread::sleep_for(seconds(t));
}

string TimePoint2String(system_clock::time_point tp)
{
    auto ttime_t = system_clock::to_time_t(tp);
    string result(ctime(&ttime_t));
    return result;
}

string Timer::To_String()
{
    return TimePoint2String(start_time_);
}

long DurationTime(TimePoint from, TimePoint to)
{
    return duration_cast<seconds>(to - from).count();
}

}