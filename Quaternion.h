/*
----------------------------------------------------------------------
This file is revised from the Quaternion.h of Ray's code.
----------------------------------------------------------------------
*/

#ifndef _QUATERNION_H_
#define _QUATERNION_H_

#include"Angle.h"
#include<iostream>
#include"Matrix.h"
#include"Vector.h"
#include <cmath>

using namespace std;

class Quaternion
	{
	public:
		/**
		 * Initialize to rotate 0 about Y-axis.
		 * @note
		 *		n is cos(theta/2), not angle!
		 */
		Quaternion() : n(1), v(0,0,0) {}
		Quaternion(Real n, Real x, Real y, Real z) : n(n), v(x, y, z)
		{
			// normalize the quaternion
			v.normalize();
			v *= 1 - n*n;
		}
		Quaternion(Real n, Vector3 v) : n(n), v(v)
		{
			// normalize the quaternion
			v.normalize();
			v *= 1 - n*n;
		}
		Quaternion(Angle angle, Vector3 axis)
		{
			n = cos(angle.getRadianValue()/2);
			axis.normalize();
			v = axis * sin(angle.getRadianValue()/2);
		}

		void set(Real n, Real x, Real y, Real z)
		{
			this->n=n;
			v.set(x, y, z);
			// normalize the quaternion
			v.normalize();
			v *= 1 - n*n;
		}

		void set(Angle angle, Vector3 axis)
		{
			n = cos(angle.getRadianValue()/2);
			axis.normalize();
			v = axis * sin(angle.getRadianValue()/2);
		}

		void normalize()
		{
			//!
			Real len = sqrt(n*n + v.lengthSquare());
			n /= len;
			v /= len;
		}

		Real getRadianValue()
		{
			return (Real)(2*acos(n));
		}

		Angle getAngle()
		{
			return Radian(2*acos(n));
		}

		Vector3 getAxis()
		{
			return v.normalizedVector();
		}

		Quaternion operator~()	///< conjugate
		{
			return Quaternion(n, v*-1);
		}

		Quaternion operator*(Quaternion& q)
		{
			return Quaternion(n*q.n-v.dot(q.v),
							  //q.v*n+v*q.n+q.v.cross(v));	// note the order of cross product!
							  q.v*n+v*q.n+v.cross(q.v)); //! for debug
		}

		void operator*=(Quaternion& q)
		{
			Real	scale;
			Vector3	Vector;
			scale  = n*q.n-v.dot(q.v);
			//Vector = q.v*n+v*q.n+q.v.cross(v);	// note the order of cross product!
			Vector = q.v*n+v*q.n+v.cross(q.v); //! for debug

			n = scale;
			v = Vector;

			n = n>1 ? 1 : n;	// n sometimes becomes 1.00002, etc.
			n = n<-1 ? -1 : n;
		}

		Vector3 rotate(const Vector3& v)
		{
			Quaternion q;
			q = *this * Quaternion(0, v) * ~(*this);
			return q.v;
		}
		

		Vector3 rotatedVector(const Vector3& v)
		{
			Quaternion q;
			q = *this * Quaternion(0, v) * ~(*this);
			return q.v;
		}
		
		/**
		 * Convert to 3x3 rotation matrix.
		 */
		Matrix3x3 toMatrix3x3()
		{
			Matrix3x3 m;
			m.v11 = n*n + v.x*v.x - v.y*v.y - v.z*v.z;
			m.v21 = 2*v.x*v.y + 2*v.z*n;
			m.v31 = 2*v.z*v.x - 2*v.y*n;
			m.v12 = 2*v.x*v.y - 2*v.z*n;
			m.v22 = n*n - v.x*v.x + v.y*v.y - v.z*v.z;
			m.v32 = 2*v.z*v.y + 2*v.x*n;
			m.v13 = 2*v.x*v.z + 2*v.y*n;
			m.v23 = 2*v.y*v.z - 2*v.x*n;
			m.v33 = n*n - v.x*v.x - v.y*v.y + v.z*v.z;
			return m;
		}

		Matrix4x4 toMatrix4x4()
		{
			Matrix3x3 m;
			m = this->toMatrix3x3();
			return Matrix4x4(m.a, m.b, m.c, 0,
							 m.d, m.e, m.f, 0,
							 m.g, m.h, m.i, 0,
							   0,   0,   0, 1);
		}

		Vector3 toEulerAngle()
		{
			Real heading, attitude, bank;

			attitude = 0;
			if(v.x*v.y + v.z*w == 0.5) //north pole
			{
				heading = 2*atan2(v.x,w);
				bank = 0;
			}
			else if(v.x*v.y + v.z*w == -0.5) //south pole
			{
				heading = -2*atan2(v.x,w);
				bank = 0;
			}
			else
			{
				heading  = atan2(2*v.y*w-2*v.x*v.z, 1 - 2*v.y*v.y - 2*v.z*v.z);
				attitude = asin(2*v.x*v.y + 2*v.z*w);
				bank     = atan2(2*v.x*w-2*v.y*v.z , 1 - 2*v.x*v.x - 2*v.z*v.z);
			}
			return Vector3(heading, attitude, bank);
		}

	public:
		union
		{
			Real	n;
			Real	w;
		};
		Vector3 v;

		static const Quaternion ZeroRotation;

	};

	inline std::ostream& operator<<(std::ostream& os, const Quaternion& q)
	{
		os<<q.n<<" "<<q.v<<endl;
		return os;
	}


#endif