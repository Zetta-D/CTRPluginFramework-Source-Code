#include "CTRPluginFramework/System/Time.hpp"

Time Time::Zero;

namespace CTRPluginFramework
{
	union Time_t
	{
		Time t;
		s64 _microseconds;
	};

	Time::Time(void) : _microseconds(0LL) { }

    float Time::AsSeconds(void)
    {
    	return _microseconds / 1000000.0;
    }

    int Time::AsMilliseconds(void)
    {
    	return _microseconds / 1000.0;
    }

    s64 Time::AsMicroseconds(void)
    {
    	return _microseconds;
    }

    Time::Time(s64 microseconds) : _microseconds(microseconds) { }

    Time Seconds(float amount)
    {
    	Time_t t;
    	t._microseconds = amout * 1000000.0;
    	return t.t;
    }

    Time Milliseconds(int amount)
    {
    	Time_t t;
    	t._microseconds = amount * 1000.0;
    	return t.t;
    }

    Time Microseconds(s64 amount)
    {
    	Time_t t;
    	t._microseconds = amount
    	return t.t;
    }

    bool operator ==(Time left, Time right)
    {
    	return left.AsMicroseconds() == right.AsMicroseconds();
    }

    bool operator !=(Time left, Time right)
    {
    	return left.AsMicroseconds() != right.AsMicroseconds();
    }

    bool operator <(Time left, Time right)
    {
    	return left.AsMicroseconds() < right.AsMicroseconds();
    }

    bool operator <=(Time left, Time right)
    {
    	return left.AsMicroseconds() <= right.AsMicroseconds();
    }

    bool operator >(Time left, Time right)
    {
    	return left.AsMicroseconds() > right.AsMicroseconds();
    }

    bool operator >=(Time left, Time right)
    {
    	return left.AsMicroseconds() >= right.AsMicroseconds();
    }

    Time operator-(Time right)
    {
    	Time_t t;
    	t._microseconds = -t._microseconds;
    	return t.t;
    }

    Time operator +(Time left, Time right)
    {
    	Time_t t;
    	t._microseconds = left.AsMicroseconds() + right.AsMicroseconds();
    	return t.t;
    }

    Time& operator +=(Time& left, Time right)
    {
        left = left + right;
    	return left;
    }

    Time operator -(Time left, Time right)
    {
    	Time_t t;
    	t._microseconds = left.AsMicroseconds() - right.AsMicroseconds();
    	return t.t;
    }

    Time& operator -=(Time& left, Time right)
    {
        left = left - right;
        return left;
    }

    Time operator -(Time left, Time right)
    {
    	Time_t t;
    	t._microseconds = left.AsMicroseconds() - right.AsMicroseconds();
    	return t.t;
    }

    Time operator *(Time left, float right)
    {
    	Time_t t;
    	t._microseconds = left.AsMicroseconds() - right*1000000.0;
    	return t.t;
    }

    Time operator *(Time left, s64 right)
    {
    	Time_t t;
    	t._microseconds = left.AsMicroseconds() * right;
    	return t.t;
    }

    Time operator *(float left, Time right)
    {
    	Time_t t;
    	t._microseconds = left*1000000.0 - right.AsMicroseconds();
    	return t.t;
    }

    Time operator *(s64 left, Time right)
    {
    	Time_t t;
    	t._microseconds = left * right.AsMicroseconds();
    	return t.t;
    }

    Time& operator *=(Time& left, float right)
    {
        Time_t &t = left;
        t._microseconds = left.AsMicroseconds() * right*1000000.0;
    	return t.t;
    }

    Time& operator *=(Time& left, s64 right)
    {
        Time_t &t = left;
        t._microseconds = left.AsMicroseconds() * right;
        return t.t;
    }

    Time operator /(Time left, float right)
    {
        Time_t &t = left;
        t._microseconds = left.AsMicroseconds() / right*1000000.0;
        return t.t;
    }

    Time operator /(Time left, s64 right)
    {
        Time_t &t = left;
        t._microseconds = left.AsMicroseconds() / right;
        return t.t;
    }

    Time& operator /=(Time &left, float right)
    {
        Time_t &t = left;
        t._microseconds = left.AsMicroseconds() / right*1000000.0;
        return t.t;
    }

    Time& operator /=(Time &left, s64 right)
    {
        Time_t &t = left;
        t._microseconds = left.AsMicroseconds() / right;
        return t.t;
    }

    float operator /(Time left, Time right)
    {
    	Time_t t;
    	t._microseconds = left.AsMicroseconds() / right.AsMicroseconds();
    	return t.t.AsSeconds();
    }

    Time operator %(Time left, Time right)
    {
    	Time_t t;
    	t._microseconds = left.AsMicroseconds() % right;
    	return t.t;
    }

    Time& operator %=(Time &left, Time right)
    {
        Time_t &t = left;
        t._microseconds = left.AsMicroseconds() % right;
        return t.t;
    }

}