#ifndef timer_h__
#define timer_h__

#include <chrono>
#include <string>

namespace hpgc {
	typedef std::chrono::high_resolution_clock Clock;
	typedef std::chrono::system_clock::time_point TimePoint;
	using namespace std::chrono;

	void Sleep(int t);

	std::string TimePoint2String(TimePoint tp);

	long DurationTime(TimePoint from, TimePoint to);

	inline TimePoint Now()
	{
		auto now = Clock::now();
		return now;
	}

	class Timer {
	public:
		Timer() {
			Reset();
		}

		void Reset() {
			start_time_ = Now();
		}

		long elapsed() const {
			return DurationTime(start_time_, Now());
		}

		std::string To_String();

	private:
		TimePoint start_time_;
	};
}




#endif /* TIMER_H_ */
