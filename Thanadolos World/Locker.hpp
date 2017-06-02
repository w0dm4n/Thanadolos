#pragma once
#include <mutex>

class Locker
{
public:
	Locker();
	~Locker();
	void Locker::lock();
	void Locker::unlock();
private:
	std::mutex locker;
};

