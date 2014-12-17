/*
----------------------------------------------------------------------
This file is revised from the Angle.h of Ray's code.
----------------------------------------------------------------------
*/

#ifndef _ANGLE_H_
#define _ANGLE_H_

#include<iostream>
#include"CommonHeader.h"
#include <cmath>

inline Real radianToDegree(Real r)
{
	return r/PI*Real(180.0);
}

inline Real degreeToRadian(Real d)
{
	return d/Real(180.0)*PI;
}

class Radian
	{
	public:
		Radian(Real value=0) : mValue(value) {}
		Radian(const Degree& d);	
		Degree toDegree() const;
		
		Real getValue()
		{
			return mValue;
		}

		Radian operator+(const Radian& r)
		{
			return Radian(mValue+r.mValue);
		}

		Radian operator-(const Radian& r)
		{
			return Radian(mValue-r.mValue);
		}

		Radian operator*(const Radian& r)
		{
			return Radian(mValue*r.mValue);
		}

		Radian operator/(const Radian& r)
		{
			return Radian(mValue/r.mValue);
		}

		Radian& operator+=(const Radian& r)
		{
			mValue += r.mValue;
			return *this;
		}

		Radian& operator-=(const Radian& r)
		{
			mValue -= r.mValue;
			return *this;
		}

		Radian& operator*=(const Radian& r)
		{
			mValue *= r.mValue;
			return *this;
		}

		Radian& operator/=(const Radian& r)
		{
			mValue /= r.mValue;
			return *this;
		}

		bool operator<(const Radian& r)
		{
			return mValue < r.mValue;
		}

		bool operator>(const Radian& r)
		{
			return mValue > r.mValue;
		}

		bool operator<=(const Radian& r)
		{
			return mValue <= r.mValue;
		}

		bool operator>=(const Radian& r)
		{
			return mValue >= r.mValue;
		}

		bool operator==(const Radian& r)
		{
			return mValue == r.mValue;
		}

	protected:
		Real mValue;

		friend std::ostream& operator<<(std::ostream& os, const Radian& r);
	};

	class Degree
	{
	public:
		Degree(Real value=0) : mValue(value) {}

		Degree(const Radian& r)
		{
			mValue = r.toDegree().getValue();
		}

		Real getValue()
		{
			return mValue;
		}

		Radian toRadian() const
		{
			return Radian(degreeToRadian(mValue));
		}

		Degree operator+(const Degree& d)
		{
			return Degree(mValue+d.mValue);
		}

		Degree operator-(const Degree& d)
		{
			return Degree(mValue-d.mValue);
		}

		Degree operator*(const Degree& d)
		{
			return Degree(mValue*d.mValue);
		}

		Degree operator/(const Degree& d)
		{
			return Degree(mValue/d.mValue);
		}

		Degree& operator+=(const Degree& d)
		{
			mValue += d.mValue;
			return *this;
		}

		Degree& operator-=(const Degree& d)
		{
			mValue -= d.mValue;
			return *this;
		}

		Degree& operator*=(const Degree& d)
		{
			mValue *= d.mValue;
			return *this;
		}

		Degree& operator/=(const Degree& d)
		{
			mValue /= d.mValue;
			return *this;
		}

		bool operator<(const Degree& d)
		{
			return mValue < d.mValue;
		}

		bool operator>(const Degree& d)
		{
			return mValue > d.mValue;
		}

		bool operator<=(const Degree& d)
		{
			return mValue <= d.mValue;
		}

		bool operator>=(const Degree& d)
		{
			return mValue >= d.mValue;
		}

		bool operator==(const Degree& d)
		{
			return mValue == d.mValue;
		}

	protected:
		Real mValue;

		friend std::ostream& operator<<(std::ostream& os, const Degree& d);
	};

	/** Wrapper of angle, the value will be converted between Radian and Degree appropriately.
	@remarks
		Internally store the angle value as radian.
	*/
	class Angle
	{
	public:
		Angle() : mRadianValue(0) {}
		Angle(const Radian& r) : mRadianValue(r) {}
		Angle(const Degree& d) : mRadianValue(d) {}

		Real getRadianValue()
		{
			return mRadianValue.getValue();
		}

		Real getDegreeValue()
		{
			return mRadianValue.toDegree().getValue();
		}

		Radian getRadian()
		{
			return mRadianValue;
		}

		void setRadian(const Radian& r)
		{
			mRadianValue = r;
		}

		Degree getDegree()
		{
			return mRadianValue.toDegree();
		}

		void setDegree(const Degree& d)
		{
			mRadianValue = d.toRadian();
		}

		operator Radian() const
		{
			return mRadianValue;
		}

		operator Degree() const
		{
			return mRadianValue.toDegree();
		}

		Angle operator+(const Angle& a)
		{
			return Angle(mRadianValue + a.mRadianValue);
		}

		Angle operator-(const Angle& a)
		{
			return Angle(mRadianValue - a.mRadianValue);
		}

		Angle operator*(const Angle& a)
		{
			return Angle(mRadianValue * a.mRadianValue);
		}

		Angle operator/(const Angle& a)
		{
			return Angle(mRadianValue / a.mRadianValue);
		}

		Angle& operator+=(const Angle& a)
		{
			mRadianValue += a.mRadianValue;
			return *this;
		}

		Angle& operator-=(const Angle& a)
		{
			mRadianValue -= a.mRadianValue;
			return *this;
		}

		Angle& operator*=(const Angle& a)
		{
			mRadianValue *= a.mRadianValue;
			return *this;
		}

		Angle& operator/=(const Angle& a)
		{
			mRadianValue /= a.mRadianValue;
			return *this;
		}

		bool operator>(const Angle& a)
		{
			return mRadianValue > a.mRadianValue;
		}

		bool operator<(const Angle& a)
		{
			return mRadianValue < a.mRadianValue;
		}

		bool operator>=(const Angle& a)
		{
			return mRadianValue >= a.mRadianValue;
		}

		bool operator<=(const Angle& a)
		{
			return mRadianValue <= a.mRadianValue;
		}

		bool operator==(const Angle& a)
		{
			return mRadianValue == a.mRadianValue;
		}

	protected:
		Radian mRadianValue;	//< always stored as radian internally

		friend std::ostream& operator<<(std::ostream& os, const Angle& d);
	};


	// for test:
	inline std::ostream& operator<<(std::ostream& os, const Radian& r)
	{
		os << r.mValue;
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const Degree& d)
	{
		os << d.mValue;
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const Angle& d)
	{
		os << d.mRadianValue;
		return os;
	}

	// These functions cannot be defined in class because they need definition of Degree:
	inline Radian::Radian(const Degree& d)
	{
		mValue = d.toRadian().getValue();
	}

	inline Degree Radian::toDegree() const
	{
		return Degree(radianToDegree(mValue));
	}

#endif 