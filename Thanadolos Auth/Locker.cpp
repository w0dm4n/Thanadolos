#include "Locker.hpp"

Locker::Locker()
{
}

void Locker::lock()
{
	this->locker.lock();
}

void Locker::unlock()
{
	this->locker.unlock();
}

Locker::~Locker()
{
	this->locker.unlock();
}
