/*
----------------------------------------------------------------------
This file is revised from the Angle.h of Ray's code.
----------------------------------------------------------------------
*/

#ifndef _VECTOR_H_
#define _VECTOR_H_

#include"CommonHeader.h"
#include<iostream>
#include<cmath>

class Vector2
	{
	public:
		Vector2(Real value=0)
		{
			x = y = value;
		}

		Vector2(Real x, Real y) : x(x), y(y) {}

		Real& operator[](int i)
		{
			return v[i];
		}

		const Real& operator[](int i) const
		{
			return v[i];
		}

		void set(Real value)
		{
			x = y = value;
		}

		void set(Real x, Real y)
		{
			this->x = x;
			this->y = y;
		}

		Real length()
		{
			return sqrt(x*x+y*y);
		}

		Real lengthSquare()
		{
			return x*x+y*y;
		}

		void normalize()
		{
			Real m = sqrt(x*x+y*y);
			if(m>0)	// > HAWK_NEST_FLOATING_0_THRESHOLD)
			{
				x /= m;
				y /= m;
			}
			//if(fabs(x) < HAWK_NEST_FLOATING_0_THRESHOLD) x = 0.0f;
			//if(fabs(y) < HAWK_NEST_FLOATING_0_THRESHOLD) y = 0.0f;
		}

		Vector2 normalizedVector()
		{
			Vector2 temp = *this;
			temp.normalize();
			return temp;
		}

		Real dot(const Vector2& v)
		{
			return x*v.x + y*v.y;
		}

		Vector2 operator+(const Vector2& v)
		{
			return Vector2(x+v.x, y+v.y);
		}

		Vector2 operator-(const Vector2& v)
		{
			return Vector2(x-v.x, y-v.y);
		}

		Vector2 operator+=(const Vector2& v)
		{
			x += v.x;
			y += v.y;
			return *this;
		}

		Vector2 operator-=(const Vector2& v)
		{
			x -= v.x;
			y -= v.y;
			return *this;
		}

		Vector2 operator*(Real k)
		{
			return Vector2(x*k, y*k);
		}

		Vector2 operator/(Real k)
		{
			return Vector2(x/k, y/k);
		}

		Vector2 operator*=(Real k)
		{
			x *= k;
			y *= k;
			return *this;
		}

		Vector2 operator/=(Real k)
		{
			x /= k;
			y /= k;
			return *this;
		}

		/**
		 * Elementwise operatior.
		 */
		Vector2 operator/(Vector2 v)
		{
			return Vector2(x/v.x, y/v.y);
		}

		bool operator==(Vector2 v)
		{
			return x==v.x && y==v.y;
		}

	public:
		union
		{
			struct
			{
				Real x, y;
			};
			struct 
			{
				Real v0, v1;
			};
			Real v[2];
		};
	};

	class Vector3
	{
	public:
		Vector3(Real value=0)
		{
			x = y = z = value;
		}

		Vector3(Real x, Real y, Real z) : x(x), y(y), z(z) {}

		Vector3(Vector2 v2, Real z) : x(v2.x), y(v2.y), z(z) {}
		//copy constructor
		Vector3(const Vector3& other)
		{
			x = other.x;
		    y = other.y;
		    z = other.z;
		}

		Real& operator[](int i)
		{
			return v[i];
		}

		const Real& operator[](int i) const
		{
			return v[i];
		}

		void set(Real value)
		{
			x = y = z = value;
		}

		void set(Real x, Real y, Real z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		Real length()
		{
			return sqrt(x*x+y*y+z*z);
		}

		Real lengthSquare()
		{
			return x*x+y*y+z*z;
		}

		void normalize()
		{
			Real m = sqrt(x*x+y*y+z*z);
			if(m>0)	// > HAWK_NEST_FLOATING_0_THRESHOLD)
			{
				x /= m;
				y /= m;
				z /= m;
			}
			//if(fabs(x) < HAWK_NEST_FLOATING_0_THRESHOLD) x = 0.0f;
			//if(fabs(y) < HAWK_NEST_FLOATING_0_THRESHOLD) y = 0.0f;
			//if(fabs(z) < HAWK_NEST_FLOATING_0_THRESHOLD) z = 0.0f;
		}

		Vector3 normalizedVector()
		{
			Vector3 temp = *this;
			temp.normalize();
			return temp;
		}

		Real dot(const Vector3& v)
		{
			return x*v.x + y*v.y + z*v.z;
		}

		Vector3 cross(const Vector3& v)
		{
			return Vector3( y*v.z-z*v.y,
							z*v.x-x*v.z,
							x*v.y-y*v.x);
		}

		Vector3 operator+(const Vector3& v)
		{
			return Vector3(x+v.x, y+v.y, z+v.z);
		}

		Vector3 operator-(const Vector3& v)
		{
			return Vector3(x-v.x, y-v.y, z-v.z);
		}

		Vector3 operator+=(const Vector3& v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}

		Vector3 operator-=(const Vector3& v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;
			return *this;
		}


		Vector3 operator*(Real k)
		{
			return Vector3(x*k, y*k, z*k);
		}

		Vector3 operator/(Real k)
		{
			return Vector3(x/k, y/k, z/k);
		}

		Vector3 operator*=(Real k)
		{
			x *= k;
			y *= k;
			z *= k;
			return *this;
		}

		Vector3 operator/=(Real k)
		{
			x /= k;
			y /= k;
			z /= k;
			return *this;
		}

		bool operator==(const Vector3& v)
		{
			return (x==v.x && y==v.y && z==v.z);
		}

	public:
		union
		{
			struct
			{
				Real x, y, z;
			};
			struct  
			{
				Real r, g, b;
			};
			struct 
			{
				Real v0, v1, v2;
			};
			Real v[3];
		};
	};

	// These functions cannot be defined in vector class:
	inline Vector2 operator*(Real r, const Vector2& v)
	{
		return Vector2(r*v.x, r*v.y);
	}

	inline std::ostream& operator<<(std::ostream& os, const Vector2& v)
	{
		os<<v.x<<" "<<v.y<<std::endl;
		return os;
	}

	inline std::istream& operator>>(std::istream& is, Vector2& v)
	{
		is>>v.x>>v.y;
		return is;
	}

	inline std::ostream& operator<<(std::ostream& os, const Vector3& v)
	{
		os<<v.x<<" "<<v.y<<" "<<v.z<<std::endl;
		return os;
	}

	inline std::istream& operator>>(std::istream& is, Vector3& v)
	{
		is>>v.x>>v.y>>v.z;
		return is;
	}

		/**
	 * Mainly used to get/set uniform variable in glsl.
	 * @note
	 *		This class stores elements as float regardless of 
	 * configuration for Real.
	 */
	class Vector3f
	{
	public:
		Vector3f(float value=0)
		{
			x = y = z = value;
		}

		Vector3f(float x, float y, float z)
			: x(x), y(y), z(z) {}

		void set(float value)
		{
			x = y = z = value;
		}

		void set(float x, float y, float z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		float& operator[](int i)
		{
			return v[i];
		}

		const float& operator[](int i) const
		{
			return v[i];
		}
		//conversion operators for glUniform3fv()
        operator const float* () const
	    { return static_cast<const float*>( &x ); }

        operator float* ()
	    { return static_cast<float*>( &x ); }

	public:
		union
		{
			struct  
			{
				float x, y, z;
			};
			struct 
			{
				float r, g, b;
			};
			float v[3];
		};
	};

	/**
	 * Mainly used for homogeneous coordinates, color or setting 2x2 matrices 
	 * in OpenGL.
	 * @note
	 *		This class stores elements as 'Real', which maybe float or double
	 *	according to Hawk Nest configuration. Pay attention to this when 
	 *  using this class to set matrix for OpenGL.
	 */
	class Vector4
	{
	public:
		Vector4(Real value=0)
		{
			x = y = z = w = value;
		}

		Vector4(Real x, Real y, Real z, Real w)
			: x(x), y(y), z(z), w(w) {}

		void set(Real value)
		{
			x = y = z = w = value;
		}

		void set(Real x, Real y, Real z, Real w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		Real length()
		{
			return sqrt(x*x+y*y+z*z+w*w);
		}

		Real lengthSquare()
		{
			return x*x+y*y+z*z+w*w;
		}

		void normalize()
		{
			Real m = sqrt(x*x+y*y+z*z+w*w);
			if(m>0)	// > HAWK_NEST_FLOATING_0_THRESHOLD)
			{
				x /= m;
				y /= m;
				z /= m;
				w /= m;
			}
			//if(fabs(x) < HAWK_NEST_FLOATING_0_THRESHOLD) x = 0.0f;
			//if(fabs(y) < HAWK_NEST_FLOATING_0_THRESHOLD) y = 0.0f;
			//if(fabs(z) < HAWK_NEST_FLOATING_0_THRESHOLD) z = 0.0f;
			//if(fabs(w) < HAWK_NEST_FLOATING_0_THRESHOLD) w = 0.0f;
		}

		Vector4 normalizedVector()
		{
			Vector4 temp = *this;
			temp.normalize();
			return temp;
		}

		Real dot(const Vector4& v)
		{
			return x*v.x + y*v.y + z*v.z + w*v.w;
		}

		Real& operator[](int i)
		{
			return v[i];
		}

		const Real& operator[](int i) const
		{
			return v[i];
		}

	public:
		union
		{
			struct  
			{
				Real x, y, z, w;
			};
			struct 
			{
				Real r, g, b, a;
			};
			Real v[4];
		};
	};


	/**
	 * Mainly used to: (1)get/set 2x2 matrix in OpenGL 
	 * (2) get/set uniform variable in glsl 
	 * @note
	 *		This class stores elements as float regardless of 
	 * configuration for Real.
	 */
	class Vector4f
	{
	public:
		Vector4f(float value=0)
		{
			x = y = z = w = value;
		}

		Vector4f(float x, float y, float z, float w)
			: x(x), y(y), z(z), w(w) {}

		void set(float value)
		{
			x = y = z = w = value;
		}

		void set(float x, float y, float z, float w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		float& operator[](int i)
		{
			return v[i];
		}

		const float& operator[](int i) const
		{
			return v[i];
		}
        //conversion operators for glUniform4fv()
        operator const float* () const
	    { return static_cast<const float*>( &x ); }

        operator float* ()
	    { return static_cast<float*>( &x ); }

	public:
		union
		{
			struct  
			{
				float x, y, z, w;
			};
			struct 
			{
				float r, g, b, a;
			};
			float v[4];
		};
	};

	/**
	 * Mainly used to get/set 2x2 matrix in OpenGL.
	 * @note
	 *		This class stores elements as double regardless of Hawk Nest
	 * configuration for Real.
	 */
	class Vector4d
	{
	public:
		Vector4d(double value=0)
		{
			x = y = z = w = value;
		}

		Vector4d(double x, double y, double z, double w)
			: x(x), y(y), z(z), w(w) {}

		void set(double value)
		{
			x = y = z = w = value;
		}

		void set(double x, double y, double z, double w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		double& operator[](int i)
		{
			return v[i];
		}

		const double& operator[](int i) const
		{
			return v[i];
		}

	public:
		union
		{
			struct  
			{
				double x, y, z, w;
			};
			struct 
			{
				double r, g, b, a;
			};
			double v[4];
		};
	};

	/**
	* Mainly used for setting 3x3 matrices in OpenGL.
	* @note
	*		This class stores elements as 'Real', which maybe float or double
	*	according to Hawk Nest configuration. Pay attention to this when 
	*  using this class to set matrix for OpenGL.
	*/
	class Vector9
	{
	public:
		Vector9(Real value=0)
		{
			v[0] = v[1] = v[2] = 
			v[3] = v[4] = v[5] = 
			v[6] = v[7] = v[8] = value;
		}

		Vector9(Real v0, Real v1, Real v2,
				Real v3, Real v4, Real v5,
				Real v6, Real v7, Real v8)
		{
			v[0] = v0;
			v[1] = v1;
			v[2] = v2;
			v[3] = v3;
			v[4] = v4;
			v[5] = v5;
			v[6] = v6;
			v[7] = v7;
			v[8] = v8;
		}

		void set(Real value)
		{
			v[0] = v[1] = v[2] = 
			v[3] = v[4] = v[5] = 
			v[6] = v[7] = v[8] = value;
		}

		void set(Real v0, Real v1, Real v2,
				 Real v3, Real v4, Real v5,
				 Real v6, Real v7, Real v8)
		{
			v[0] = v0;
			v[1] = v1;
			v[2] = v2;
			v[3] = v3;
			v[4] = v4;
			v[5] = v5;
			v[6] = v6;
			v[7] = v7;
			v[8] = v8;
		}

		Real& operator[](int i)
		{
			return v[i];
		}
		
		const Real& operator[](int i) const
		{
			return v[i];
		}

	public:
		Real v[9];
	};

	/**
	* Mainly used for setting 3x3 matrices in OpenGL.
	* @note
	*		This class stores elements as float regardless of Hawk Nest
	* configuration for Real.
	*/
	class Vector9f
	{
	public:
		Vector9f(float value=0)
		{
			v[0] = v[1] = v[2] = 
			v[3] = v[4] = v[5] = 
			v[6] = v[7] = v[8] = value;
		}

		Vector9f(float v0, float v1, float v2,
				 float v3, float v4, float v5,
				 float v6, float v7, float v8)
		{
			v[0] = v0;
			v[1] = v1;
			v[2] = v2;
			v[3] = v3;
			v[4] = v4;
			v[5] = v5;
			v[6] = v6;
			v[7] = v7;
			v[8] = v8;
		}

		void set(float value)
		{
			v[0] = v[1] = v[2] = 
			v[3] = v[4] = v[5] = 
			v[6] = v[7] = v[8] = value;
		}

		void set(float v0, float v1, float v2,
				 float v3, float v4, float v5,
				 float v6, float v7, float v8)
		{
			v[0] = v0;
			v[1] = v1;
			v[2] = v2;
			v[3] = v3;
			v[4] = v4;
			v[5] = v5;
			v[6] = v6;
			v[7] = v7;
			v[8] = v8;
		}

		float& operator[](int i)
		{
			return v[i];
		}

		const float& operator[](int i) const
		{
			return v[i];
		}

	public:
		float v[9];
	};

	/**
	* Mainly used for setting 3x3 matrices in OpenGL.
	* @note
	*		This class stores elements as double regardless of Hawk Nest
	* configuration for Real.
	*/
	class Vector9d
	{
	public:
		Vector9d(double value=0)
		{
			v[0] = v[1] = v[2] = 
			v[3] = v[4] = v[5] = 
			v[6] = v[7] = v[8] = value;
		}

		Vector9d(double v0, double v1, double v2,
				 double v3, double v4, double v5,
				 double v6, double v7, double v8)
		{
			v[0] = v0;
			v[1] = v1;
			v[2] = v2;
			v[3] = v3;
			v[4] = v4;
			v[5] = v5;
			v[6] = v6;
			v[7] = v7;
			v[8] = v8;
		}

		void set(double value)
		{
			v[0] = v[1] = v[2] = 
			v[3] = v[4] = v[5] = 
			v[6] = v[7] = v[8] = value;
		}

		void set(double v0, double v1, double v2,
				 double v3, double v4, double v5,
				 double v6, double v7, double v8)
		{
			v[0] = v0;
			v[1] = v1;
			v[2] = v2;
			v[3] = v3;
			v[4] = v4;
			v[5] = v5;
			v[6] = v6;
			v[7] = v7;
			v[8] = v8;
		}

		double& operator[](int i)
		{
			return v[i];
		}

		const double& operator[](int i) const
		{
			return v[i];
		}

	public:
		double v[9];
	};

	/**
	* Mainly used for setting 4x4 matrices in OpenGL.
	* @note
	*		This class stores elements as 'Real', which maybe float or double
	*	according to Hawk Nest configuration. Pay attention to this when 
	*  using this class to set matrix for OpenGL.
	*/
	class Vector16
	{
	public:
		Vector16(Real value=0)
		{
			 v[0] =  v[1] =  v[2] =  v[3] = 
			 v[4] =  v[5] =  v[6] =  v[7] = 
			 v[8] =  v[9] = v[10] = v[11] = 
			v[12] = v[13] = v[14] = v[15] = value;
		}

		Vector16(Real  v0, Real  v1, Real  v2, Real  v3,
				 Real  v4, Real  v5, Real  v6, Real  v7,
				 Real  v8, Real  v9, Real v10, Real v11,
				 Real v12, Real v13, Real v14, Real v15)
		{
			 v[0] =  v0;	 v[1] =  v1;	 v[2] =  v2;	 v[3] =  v3;
			 v[4] =  v4;	 v[5] =  v5;	 v[6] =  v6;	 v[7] =  v7;
			 v[8] =  v8;	 v[9] =  v9;	v[10] = v10;	v[11] = v11;
			v[12] = v12;	v[13] = v13;	v[14] = v14;	v[15] = v15;
		}

		void set(Real value)
		{
			 v[0] =  v[1] =  v[2] =  v[3] = 
			 v[4] =  v[5] =  v[6] =  v[7] = 
			 v[8] =  v[9] = v[10] = v[11] = 
			v[12] = v[13] = v[14] = v[15] = value;
		}

		void set(Real  v0, Real  v1, Real  v2, Real  v3,
				 Real  v4, Real  v5, Real  v6, Real  v7,
				 Real  v8, Real  v9, Real v10, Real v11,
				 Real v12, Real v13, Real v14, Real v15)
		{
			 v[0] =  v0;	 v[1] =  v1;	 v[2] =  v2;	 v[3] =  v3;
			 v[4] =  v4;	 v[5] =  v5;	 v[6] =  v6;	 v[7] =  v7;
			 v[8] =  v8;	 v[9] =  v9;	v[10] = v10;	v[11] = v11;
			v[12] = v12;	v[13] = v13;	v[14] = v14;	v[15] = v15;
		}

		Real& operator[](int i)
		{
			return v[i];
		}

		const Real& operator[](int i) const
		{
			return v[i];
		}

	public:
		Real v[16];
	};

	/**
	* Mainly used for setting 4x4 matrices in OpenGL.
	* @note
	*		This class stores elements as float regardless of Hawk Nest
	* configuration for Real.
	*/
	class Vector16f
	{
	public:
		Vector16f(float value=0)
		{
			 v[0] =  v[1] =  v[2] =  v[3] = 
			 v[4] =  v[5] =  v[6] =  v[7] = 
			 v[8] =  v[9] = v[10] = v[11] = 
			v[12] = v[13] = v[14] = v[15] = value;
		}

		Vector16f(float  v0, float  v1, float  v2, float  v3,
				  float  v4, float  v5, float  v6, float  v7,
				  float  v8, float  v9, float v10, float v11,
				  float v12, float v13, float v14, float v15)
		{
			 v[0] =  v0;	 v[1] =  v1;	 v[2] =  v2;	 v[3] =  v3;
			 v[4] =  v4;	 v[5] =  v5;	 v[6] =  v6;	 v[7] =  v7;
			 v[8] =  v8;	 v[9] =  v9;	v[10] = v10;	v[11] = v11;
			v[12] = v12;	v[13] = v13;	v[14] = v14;	v[15] = v15;
		}

		void set(float value)
		{
			 v[0] =  v[1] =  v[2] =  v[3] = 
			 v[4] =  v[5] =  v[6] =  v[7] = 
			 v[8] =  v[9] = v[10] = v[11] = 
			v[12] = v[13] = v[14] = v[15] = value;
		}

		void set(float  v0, float  v1, float  v2, float  v3,
				 float  v4, float  v5, float  v6, float  v7,
				 float  v8, float  v9, float v10, float v11,
				 float v12, float v13, float v14, float v15)
		{
			 v[0] =  v0;	 v[1] =  v1;	 v[2] =  v2;	 v[3] =  v3;
			 v[4] =  v4;	 v[5] =  v5;	 v[6] =  v6;	 v[7] =  v7;
			 v[8] =  v8;	 v[9] =  v9;	v[10] = v10;	v[11] = v11;
			v[12] = v12;	v[13] = v13;	v[14] = v14;	v[15] = v15;
		}

		float& operator[](int i)
		{
			return v[i];
		}

		const float& operator[](int i) const
		{
			return v[i];
		}

	public:
		float v[16];
	};

	/**
	* Mainly used for setting 4x4 matrices in OpenGL.
	* @note
	*		This class stores elements as double regardless of Hawk Nest
	* configuration for Real.
	*/
	class Vector16d
	{
	public:
		Vector16d(double value=0)
		{
			 v[0] =  v[1] =  v[2] =  v[3] = 
			 v[4] =  v[5] =  v[6] =  v[7] = 
			 v[8] =  v[9] = v[10] = v[11] = 
			v[12] = v[13] = v[14] = v[15] = value;
		}

		Vector16d(double  v0, double  v1, double  v2, double  v3,
				  double  v4, double  v5, double  v6, double  v7,
				  double  v8, double  v9, double v10, double v11,
				  double v12, double v13, double v14, double v15)
		{
			 v[0] =  v0;	 v[1] =  v1;	 v[2] =  v2;	 v[3] =  v3;
			 v[4] =  v4;	 v[5] =  v5;	 v[6] =  v6;	 v[7] =  v7;
			 v[8] =  v8;	 v[9] =  v9;	v[10] = v10;	v[11] = v11;
			v[12] = v12;	v[13] = v13;	v[14] = v14;	v[15] = v15;
		}

		void set(double value)
		{
			 v[0] =  v[1] =  v[2] =  v[3] = 
			 v[4] =  v[5] =  v[6] =  v[7] = 
			 v[8] =  v[9] = v[10] = v[11] = 
			v[12] = v[13] = v[14] = v[15] = value;
		}

		void set(double  v0, double  v1, double  v2, double  v3,
				 double  v4, double  v5, double  v6, double  v7,
				 double  v8, double  v9, double v10, double v11,
				 double v12, double v13, double v14, double v15)
		{
			 v[0] =  v0;	 v[1] =  v1;	 v[2] =  v2;	 v[3] =  v3;
			 v[4] =  v4;	 v[5] =  v5;	 v[6] =  v6;	 v[7] =  v7;
			 v[8] =  v8;	 v[9] =  v9;	v[10] = v10;	v[11] = v11;
			v[12] = v12;	v[13] = v13;	v[14] = v14;	v[15] = v15;
		}

		double& operator[](int i)
		{
			return v[i];
		}

		const double& operator[](int i) const
		{
			return v[i];
		}

	public:
		double v[16];
	};

	// These functions cannot be defined in vector class:
	inline std::ostream& operator<<(std::ostream& os, const Vector4& v)
	{
		os<<v.x<<" "<<v.y<<" "<<v.z<<" "<<v.w<<std::endl;
		return os;
	}

	//inline std::istream& operator>>(std::istream& is, Vector4& v)
	//{
	//	is>>v.x>>v.y>>v.z>>v.w;
	//	return is;
	//}

	inline std::ostream& operator<<(std::ostream& os, const Vector4f& v)
	{
		os<<v.x<<" "<<v.y<<" "<<v.z<<" "<<v.w<<std::endl;
		return os;
	}

	//inline std::istream& operator>>(std::istream& is, Vector4f& v)
	//{
	//	is>>v.x>>v.y>>v.z>>v.w;
	//	return is;
	//}

	inline std::ostream& operator<<(std::ostream& os, const Vector4d& v)
	{
		os<<v.x<<" "<<v.y<<" "<<v.z<<" "<<v.w<<std::endl;
		return os;
	}

	//inline std::istream& operator>>(std::istream& is, Vector4d& v)
	//{
	//	is>>v.x>>v.y>>v.z>>v.w;
	//	return is;
	//}

	inline std::ostream& operator<<(std::ostream& os, const Vector9& v)
	{
		os<<v[0]<<" "<<v[1]<<" "<<v[2]<<" ";
		os<<v[3]<<" "<<v[4]<<" "<<v[5]<<" ";
		os<<v[6]<<" "<<v[7]<<" "<<v[8]<<std::endl;
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const Vector9f& v)
	{
		os<<v[0]<<" "<<v[1]<<" "<<v[2]<<" ";
		os<<v[3]<<" "<<v[4]<<" "<<v[5]<<" ";
		os<<v[6]<<" "<<v[7]<<" "<<v[8]<<std::endl;
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const Vector9d& v)
	{
		os<<v[0]<<" "<<v[1]<<" "<<v[2]<<" ";
		os<<v[3]<<" "<<v[4]<<" "<<v[5]<<" ";
		os<<v[6]<<" "<<v[7]<<" "<<v[8]<<std::endl;
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const Vector16& v)
	{
		for(int i=0; i<15; i++)	// first 15 elements
			os<<v[i]<<" ";
		os<<v[15]<<std::endl;	// the 16th element
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const Vector16f& v)
	{
		for(int i=0; i<15; i++)	// first 15 elements
			os<<v[i]<<" ";
		os<<v[15]<<std::endl;	// the 16th element
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const Vector16d& v)
	{
		for(int i=0; i<15; i++)	// first 15 elements
			os<<v[i]<<" ";
		os<<v[15]<<std::endl;	// the 16th element
		return os;
	}

	/**
	 * A vector with arbitrary number of elements
	 */
	class Vector
	{
	public:
		Vector(int size)
		{
			this->size = size;
			v = new Real[size];
		}

		Real& operator[](int index)
		{
			return v[index];
		}

		const Real& operator[](int index) const
		{
			return v[index];
		}

	public:
		int size;
		Real* v;
	};

#endif