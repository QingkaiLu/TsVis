/*
----------------------------------------------------------------------
This file is revised from the Angle.h of Ray's code.
----------------------------------------------------------------------
*/

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "CommonHeader.h"
#include "Vector.h"
#include <iostream>

class Matrix2x2
	{
	public:
		Matrix2x2(Real value=0) 
		{
			a = b = c = d = value;
		}

		Matrix2x2(Real a, Real b, Real c, Real d)
			: a(a), b(b), c(c), d(d) {}

		void set(Real value)
		{
			a = b = c = d = value;
		}

		void set(Real a, Real b, Real c, Real d)
		{
			this->a = a;
			this->b = b;
			this->c = c;
			this->d = d;
		}

		/**
		 * Set the column referenced by numCol with the value in v.
		 * @param
		 *		numCol Index of the column to set, starting from 0.
		 * @param
		 *		v A vector contains the values to set to the column.
		 */
		void setColumn(uint numCol, const Vector2& v)
		{
			//if(numCol>=2)
			//	HAWK_THROW("Try to set value of a column with numCol >= 2",
			//	"Matrix2x2::setColumn()");

			this->v[0][numCol]=v.x;
			this->v[1][numCol]=v.y;
		}

		/**
		* Set the row referenced by numRow with the value in v.
		* @param 
		*		numRow Index of the row to set, starting from 0.
		* @param
		*		v A vector contains the values to set to the row.
		*/
		void setRow(uint numRow, const Vector2& v)
		{
			//if(numRow>=2)
			//	HAWK_THROW("Try to set value of a row with numRow >= 2",
			//	"Matrix2x2::setRow()");

			this->v[numRow][0]=v.x;
			this->v[numRow][1]=v.y;
		}
		
		Real* operator[](int i)
		{
			return v[i];
		}

		const Real* operator[](int i) const
		{
			return v[i];
		}

		Matrix2x2 transpose()
		{
			return Matrix2x2(a, c,
							 b, d);
		}

		Real determinant()
		{
			return a*d-b*c;
		}

		Matrix2x2 inverse()
		{
			Real det = determinant();
			if(det==0)
			{
				char buf[200];
				//sprintf(buf, "Try to invert a 2x2 matrix with 0 determinant, the matrix is: %f,%f,%f,%f", a, b, c, d);
				//HAWK_THROW(buf, "Matrix2x2::inverse()");
			}
			Matrix2x2 m(d,-b,-c,a);
			m/=det;
			return m;
		}

		/**
		 * 2x2  Matrix * 2D Vector.
		 */
		Vector2 operator*(const Vector2& v)
		{
			return Vector2(a*v.x+b*v.y, c*v.x+d*v.y);
		}

		/**
		 * 2x2 Matrix * 2x2 Matrix.
		 */
		Matrix2x2 operator*(const Matrix2x2& m)
		{
			return Matrix2x2(a*m.a+b*m.c, a*m.b+b*m.d,
							 c*m.a+d*m.c, c*m.b+d*m.d);
		}
		
		Matrix2x2 operator+(const Matrix2x2& v)
		{
			return Matrix2x2(a+v.a, b+v.b,
							 c+v.c, d+v.d);
		}

		Matrix2x2 operator-(const Matrix2x2& v)
		{
			return Matrix2x2(a-v.a, b-v.b,
							 c-v.c, d-v.d);
		}

		Matrix2x2& operator+=(const Matrix2x2& v)
		{
			a += v.a;
			b += v.b;
			c += v.c;
			d += v.d;
			return *this;
		}

		Matrix2x2& operator-=(const Matrix2x2& v)
		{
			a -= v.a;
			b -= v.b;
			c -= v.c;
			d -= v.d;
			return *this;
		}

		Matrix2x2 operator*(Real k)
		{
			return Matrix2x2(a*k, b*k, c*k, d*k);
		}

		Matrix2x2 operator/(Real k)
		{
			return Matrix2x2(a/k, b/k, c/k, d/k);
		}

		Matrix2x2& operator*=(Real k)
		{
			a *= k;
			b *= k;
			c *= k;
			d *= k;
			return *this;
		}

		Matrix2x2& operator/=(Real k)
		{
			a /= k;
			b /= k;
			c /= k;
			d /= k;
			return *this;
		}

		bool operator==(Matrix2x2& m)
		{
			return a==m.a && b==m.b && c==m.c && d==m.d;
		}

		bool operator==(Real r)
		{
			return a==b && b==c && c==d && d==r;
		}

		Vector4f getOpenGLMatrix()
		{
			return Vector4f(a,b,c,d);
		}

	public:
		union
		{
			struct
			{
				Real a, b, c, d;
			};
			struct  
			{
				Real v11, v12, v21, v22;
			};
			Real v[2][2];
		};
	};

	// These functions cannot be defined in matrix class:
	/**
	 * 2D Vector * 2x2 Matrix.
	 */
	inline Vector2 operator*(const Vector2& v, const Matrix2x2& m)
	{
		return Vector2(m.a*v.x+m.c*v.y, m.b*v.x+m.d*v.y);
	}

	inline std::ostream& operator<<(std::ostream& os, const Matrix2x2& m)
	{
		os<<m.a<<" "<<m.b<<std::endl;
		os<<m.c<<" "<<m.d<<std::endl;
		return os;
	}




	/** A 3x3 matrix.
	* @remarks
	*	Position of elements:\n
	*	  |a, b, c|		|v11, v12, v13|		|v[0][0], v[0][1], v[0][2]|\n
	*	  |d, e, f|		|v21, v22, v23|		|v[1][0], v[1][1], v[1][2]|\n
	*	  |g, h, i|		|v31, v32, v33|		|v[2][0], v[2][1], v[2][2]|\n
	*/
	class Matrix3x3
	{
	public:
		Matrix3x3(Real value=0) 
		{
			a = b = c = d = e = f = g = h = i = value;
		}

		Matrix3x3(Real a, Real b, Real c,
				  Real d, Real e, Real f, 
				  Real g, Real h, Real i)
			: a(a), b(b), c(c), 
			  d(d), e(e), f(f),
			  g(g), h(h), i(i) {}

		void set(Real value)
		{
			a = b = c = d = e = f = g = h = i = value;
		}

		void set(Real a, Real b, Real c,
				 Real d, Real e, Real f,
				 Real g, Real h, Real i)
		{
			this->a = a;
			this->b = b;
			this->c = c;
			this->d = d;
			this->e = e;
			this->f = f;
			this->g = g;
			this->h = h;
			this->i = i;
		}

		/**
		* Set the column referenced by numCol with the value in v.
		* @param
		*		numCol Index of the column to set, starting from 0.
		* @param
		*		v A vector contains the values to set to the column.
		*/
		void setColumn(uint numCol, const Vector3& v)
		{
			//if(numCol>=3)
			//	HAWK_THROW("Try to set value of a column with numCol >= 3",
			//			   "Matrix3x3::setColumn()");
			this->v[0][numCol]=v.x;
			this->v[1][numCol]=v.y;
			this->v[2][numCol]=v.z;
		}

		/**
		* Set the row referenced by numRow with the value in v.
		* @param 
		*		numRow Index of the row to set, starting from 0.
		* @param
		*		v A vector contains the values to set to the row.
		*/
		void setRow(uint numRow, const Vector3& v)
		{
			//if(numRow>=3)
			//	HAWK_THROW("Try to set value of a row with numRow >= 3",
			//	"Matrix3x3::setRow()");

			this->v[numRow][0]=v.x;
			this->v[numRow][1]=v.y;
			this->v[numRow][2]=v.z;
		}

		Real det() ///< Determinant
		{
			Real a=0;		
			for(int i=0;i<3;i++)
			{			
				Real k=v[0][(i)%3]*v[1][(i+1)%3]*v[2][(i+2)%3];
				a+=k;
			}
			for(int i=0;i<3;i++)
			{
				Real k=v[0][(i)%3]*v[1][(i+2)%3]*v[2][(i+1)%3];
				a-=k;
			}
			return a;
		}

		Real* operator[](int i)
		{
			return v[i];
		}

		const Real* operator[](int i) const
		{
			return v[i];
		}

		Matrix3x3 transpose()
		{
			return Matrix3x3(a, d, g,
							 b, e, h,
							 c, f, i);
		}

		/**
		 * 3x3 Matrix * 3D Vector.
		 */
		Vector3 operator*(const Vector3& v)
		{
			return Vector3(a*v.x+b*v.y+c*v.z,
						   d*v.x+e*v.y+f*v.z,
						   g*v.x+h*v.y+i*v.z);
		}

		/**
		 * 3x3 Matrix * 3x3 Matrix.
		 */
		Matrix3x3 operator*(const Matrix3x3& m)
		{
			return Matrix3x3(a*m.a+b*m.d+c*m.g, a*m.b+b*m.e+c*m.h, a*m.c+b*m.f+c*m.i,
							 d*m.a+e*m.d+f*m.g, d*m.b+e*m.e+f*m.h, d*m.c+e*m.f+f*m.i,
							 g*m.a+h*m.d+i*m.g, g*m.b+h*m.e+i*m.h, g*m.c+h*m.f+i*m.i);
		}

		Matrix3x3 operator+(const Matrix3x3& v)
		{
			return Matrix3x3(a+v.a, b+v.b, c+v.c,
							 d+v.d, e+v.e, f+v.f,
							 g+v.g, h+v.h, i+v.i);
		}

		Matrix3x3 operator-(const Matrix3x3& v)
		{
			return Matrix3x3(a-v.a, b-v.b, c-v.c,
							 d-v.d, e-v.e, f-v.f,
							 g-v.g, h-v.h, i-v.i);
		}

		Matrix3x3& operator+=(const Matrix3x3& v)
		{
			a += v.a;
			b += v.b;
			c += v.c;
			d += v.d;
			e += v.e;
			f += v.f;
			g += v.g;
			h += v.h;
			i += v.i;
			return *this;
		}

		Matrix3x3& operator-=(const Matrix3x3& v)
		{
			a -= v.a;
			b -= v.b;
			c -= v.c;
			d -= v.d;
			e -= v.e;
			f -= v.f;
			g -= v.g;
			h -= v.h;
			i -= v.i;
			return *this;
		}

		Matrix3x3 operator*(Real k)
		{
			return Matrix3x3(a*k, b*k, c*k,
							 d*k, e*k, f*k,
							 g*k, h*k, i*k);
		}

		Matrix3x3 operator/(Real k)
		{
			return Matrix3x3(a/k, b/k, c/k,
							 d/k, e/k, f/k,
							 g/k, h/k, i/k);
		}

		Matrix3x3& operator*=(Real k)
		{
			a *= k;
			b *= k;
			c *= k;
			d *= k;
			e *= k;
			f *= k;
			g *= k;
			h *= k;
			i *= k;
			return *this;
		}

		Matrix3x3& operator/=(Real k)
		{
			a /= k;
			b /= k;
			c /= k;
			d /= k;
			e /= k;
			f /= k;
			g /= k;
			h /= k;
			i /= k;
			return *this;
		}

	public:
		union
		{
			struct
			{
				Real a, b, c;
				Real d, e, f;
				Real g, h, i;
			};
			struct  
			{
				Real v11, v12, v13;
				Real v21, v22, v23;
				Real v31, v32, v33;
			};
			Real v[3][3];
		};
	};

	// These functions cannot be defined in matrix class:
	/**
	* 3D Vector * 3x3 Matrix.
	*/
	inline Vector3 operator*(const Vector3& v, const Matrix3x3& m)
	{
		return Vector3(m.a*v.x+m.d*v.y+m.g*v.z,
					   m.b*v.x+m.e*v.y+m.h*v.z,
					   m.c*v.x+m.f*v.y+m.i*v.z);
	}

	inline std::ostream& operator<<(std::ostream& os, const Matrix3x3& m)
	{
		os<<m.a<<" "<<m.b<<" "<<m.c<<std::endl;
		os<<m.d<<" "<<m.e<<" "<<m.f<<std::endl;
		os<<m.g<<" "<<m.h<<" "<<m.i<<std::endl;
		return os;
	}



	/** A 4x4 matrix.
	* @remarks
	*	Position of elements:\n
	*	  |a, b, c, d|	|v11, v12, v13, v14|	|v[0][0], v[0][1], v[0][2], v[0][3]|\n
	*	  |e, f, g, h|	|v21, v22, v23, v24|	|v[1][0], v[1][1], v[1][2], v[1][3]|\n
	*	  |i, j, k, l|	|v31, v32, v33, v34|	|v[2][0], v[2][1], v[2][2], v[2][3]|\n
	*	  |m, n, o, p|	|v41, v42, v43, v44|	|v[3][0], v[3][1], v[3][2], v[3][3]|\n
	*/
	class Matrix4x4
	{
	public:
		Matrix4x4(Real value=0) 
		{
			a = b = c = d = 
			e = f = g = h = 
			i = j = k = l = 
			m = n = o = p = value;
		}

		Matrix4x4(Real a, Real b, Real c, Real d,
				  Real e, Real f, Real g, Real h,
				  Real i, Real j, Real k, Real l,
				  Real m, Real n, Real o, Real p)
			: a(a), b(b), c(c), d(d),
			  e(e), f(f), g(g), h(h),
			  i(i), j(j), k(k), l(l),
			  m(m), n(n), o(o), p(p) {}

		void set(Real value)
		{
			a = b = c = d = 
			e = f = g = h = 
			i = j = k = l = 
			m = n = o = p = value;
		}

		void set(Real a, Real b, Real c, Real d,
				 Real e, Real f, Real g, Real h,
				 Real i, Real j, Real k, Real l,
				 Real m, Real n, Real o, Real p)
		{
			this->a = a;
			this->b = b;
			this->c = c;
			this->d = d;
			this->e = e;
			this->f = f;
			this->g = g;
			this->h = h;
			this->i = i;
			this->j = j;
			this->k = k;
			this->l = l;
			this->m = m;
			this->n = n;
			this->o = o;
			this->p = p;
		}

		/**
		* Set the column referenced by numCol with the value in v.
		* @param
		*		numCol Index of the column to set, starting from 0.
		* @param
		*		v A vector contains the values to set to the column.
		*/
		void setColumn(uint numCol, const Vector4& v)
		{
			//if(numCol>=4)
			//	HAWK_THROW("Try to set value of a column with numCol >= 4",
			//	"Matrix4x4::setColumn()");

			this->v[0][numCol]=v.x;
			this->v[1][numCol]=v.y;
			this->v[2][numCol]=v.z;
			this->v[3][numCol]=v.w;
		}

		/**
		* Set the row referenced by numRow with the value in v.
		* @param 
		*		numRow Index of the row to set, starting from 0.
		* @param
		*		v A vector contains the values to set to the row.
		*/
		void setRow(uint numRow, const Vector4& v)
		{
			//if(numRow>=4)
			//	HAWK_THROW("Try to set value of a column with numRow >= 4",
			//	"Matrix4x4::setRow()");

			this->v[numRow][0]=v.x;
			this->v[numRow][1]=v.y;
			this->v[numRow][2]=v.z;
			this->v[numRow][3]=v.w;
		}

		Real* operator[](int i)
		{
			return v[i];
		}

		const Real* operator[](int i) const
		{
			return v[i];
		}

		Matrix4x4 transpose()
		{
			return Matrix4x4(a, e, i, m,
							 b, f, j, n,
							 c, g, k, o,
							 d, h, l, p);
		}

		/**
		* 4x4 Matrix * 4D Vector.
		*/
		Vector4 operator*(const Vector4& v)
		{
			return Vector4(a*v.x+b*v.y+c*v.z+d*v.w,
						   e*v.x+f*v.y+g*v.z+h*v.w,
						   i*v.x+j*v.y+k*v.z+l*v.w,
						   m*v.x+n*v.y+o*v.z+p*v.w);
		}

		/**
		* 4x4 Matrix * 4x4 Matrix.
		*/
		Matrix4x4 operator*(const Matrix4x4& mm)
		{
			return Matrix4x4(a*mm.a+b*mm.e+c*mm.i+d*mm.m, a*mm.b+b*mm.f+c*mm.j+d*mm.n, a*mm.c+b*mm.g+c*mm.k+d*mm.o, a*mm.d+b*mm.h+c*mm.l+d*mm.p,
							 e*mm.a+f*mm.e+g*mm.i+h*mm.m, e*mm.b+f*mm.f+g*mm.j+h*mm.n, e*mm.c+f*mm.g+g*mm.k+h*mm.o, e*mm.d+f*mm.h+g*mm.l+h*mm.p,
							 i*mm.a+j*mm.e+k*mm.i+l*mm.m, i*mm.b+j*mm.f+k*mm.j+l*mm.n, i*mm.c+j*mm.g+k*mm.k+l*mm.o, i*mm.d+j*mm.h+k*mm.l+l*mm.p,
							 m*mm.a+n*mm.e+o*mm.i+p*mm.m, m*mm.b+n*mm.f+o*mm.j+p*mm.n, m*mm.c+n*mm.g+o*mm.k+p*mm.o, m*mm.d+n*mm.h+o*mm.l+p*mm.p);
		}

		Matrix4x4 operator+(const Matrix4x4& v)
		{
			return Matrix4x4(a+v.a, b+v.b, c+v.c, d+v.d,
							 e+v.e, f+v.f, g+v.g, h+v.h,
							 i+v.i, j+v.j, k+v.k, l+v.l,
							 m+v.m, n+v.n, o+v.o, p+v.p);
		}

		Matrix4x4 operator-(const Matrix4x4& v)
		{
			return Matrix4x4(a-v.a, b-v.b, c-v.c, d-v.d,
							 e-v.e, f-v.f, g-v.g, h-v.h,
							 i-v.i, j-v.j, k-v.k, l-v.l,
							 m-v.m, n-v.n, o-v.o, p-v.p);
		}

		Matrix4x4& operator+=(const Matrix4x4& v)
		{
			a += v.a; b += v.b; c += v.c; d += v.d;
			e += v.e; f += v.f; g += v.g; h += v.h;
			i += v.i; j += v.j; k += v.k; l += v.l;
			m += v.m; n += v.n; o += v.o; p += v.p;
			return *this;
		}

		Matrix4x4& operator-=(const Matrix4x4& v)
		{
			a -= v.a; b -= v.b; c -= v.c; d -= v.d;
			e -= v.e; f -= v.f; g -= v.g; h -= v.h;
			i -= v.i; j -= v.j; k -= v.k; l -= v.l;
			m -= v.m; n -= v.n; o -= v.o; p -= v.p;
			return *this;
		}

		Matrix4x4 operator*(Real kk)
		{
			// use kk instead of k in argument, so that no need to 
			// use this->k to refer to the member variable k
			return Matrix4x4(a*kk, b*kk, c*kk, d*kk,
							 e*kk, f*kk, g*kk, h*kk,
							 i*kk, j*kk, k*kk, l*kk,
							 m*kk, n*kk, o*kk, p*kk);
		}

		Matrix4x4 operator/(Real kk)
		{
			return Matrix4x4(a/kk, b/kk, c/kk, d/kk,
							 e/kk, f/kk, g/kk, h/kk,
							 i/kk, j/kk, k/kk, l/kk,
							 m/kk, n/kk, o/kk, p/kk);
		}

		Matrix4x4& operator*=(Real kk)
		{
			a *= kk; b *= kk; c *= kk; d *= kk; 
			e *= kk; f *= kk; g *= kk; h *= kk;
			i *= kk; j *= kk; k *= kk; l *= kk;
			m *= kk; n *= kk; o *= kk; p *= kk;
			return *this;
		}

		Matrix4x4& operator/=(Real kk)
		{
			a /= kk; b /= kk; c /= kk; d /= kk;
			e /= kk; f /= kk; g /= kk; h /= kk;
			i /= kk; j /= kk; k /= kk; l /= kk;
			m /= kk; n /= kk; o /= kk; p /= kk;
			return *this;
		}

		Vector16f getOpenGLMatrix()
		{
			return Vector16f(a,e,i,m,
							 b,f,j,n,
							 c,g,k,o,
							 d,h,l,p);
		}


	public:
		union
		{
			struct
			{
				Real a, b, c, d;
				Real e, f, g, h;
				Real i, j, k, l;
				Real m, n, o, p;
			};
			struct  
			{
				Real v11, v12, v13, v14;
				Real v21, v22, v23, v24;
				Real v31, v32, v33, v34;
				Real v41, v42, v43, v44;
			};
			Real v[4][4];
		};
	};

	// These functions cannot be defined in matrix class:
	/**
	* 4D Vector * 4x4 Matrix.
	*/
	inline Vector4 operator*(const Vector4& v, const Matrix4x4& m)
	{
		return Vector4(m.a*v.x+m.e*v.y+m.i*v.z+m.m*v.w,
					   m.b*v.x+m.f*v.y+m.j*v.z+m.n*v.w,
					   m.c*v.x+m.g*v.y+m.k*v.z+m.o*v.w,
					   m.d*v.x+m.h*v.y+m.l*v.z+m.p*v.w);
	}

	inline std::ostream& operator<<(std::ostream& os, const Matrix4x4& m)
	{
		os<<m.a<<" "<<m.b<<" "<<m.c<<" "<<m.d<<std::endl;
		os<<m.e<<" "<<m.f<<" "<<m.g<<" "<<m.h<<std::endl;
		os<<m.i<<" "<<m.j<<" "<<m.k<<" "<<m.l<<std::endl;
		os<<m.m<<" "<<m.n<<" "<<m.o<<" "<<m.p<<std::endl;
		return os;
	}

	/**
	 * A matrix with arbitrary number of elements
	 */
	class Matrix
	{
	public:
		Matrix(int nRow , int nCol)
		{
			this->nRow = nRow;
			this->nCol = nCol;
			v = new Real[nRow*nCol];
		}

		/**
		 * @note row starts from 0!
		 */
		Real* operator[](int row)
		{
			return &v[nCol*row];
		}

		Vector operator*(const Vector& v)
		{
			//if(v.size != nCol)
			//	HAWK_THROW("Matrix times vector with incompatible sizes.", "Matrix::operator*(const Vector& v)");

			Vector out(nRow);
			for(int i=0; i<nRow; i++)
			{
				Real r = 0;
				for(int j=0; j<nCol; j++)
				{
					r += at(i,j)*v[j];
				}
				out[i] = r;
			}
			return out;
		}

		/**
		 * Return reference of element at n-th row, m-th col.
		 * @note n,m start from 0!
		 */
		Real& at(int row, int col)
		{
			return v[row*nCol+col];
		}

		const Real& at(int row, int col) const
		{
			return v[row*nCol+col];
		}

		Matrix transpose()
		{
			Matrix m(nCol, nRow);
			for(int i=0; i<nRow; i++)
			{
				for(int j=0; j<nCol; j++)
				{
					m.at(j,i) = this->at(i,j);
				}
			}
			return m;
		}

	public:
		int nRow;	///< number of rows
		int nCol;	///< number of columns
		Real* v;
	};

	inline Vector operator*(const Vector& v, const Matrix& m)
	{
		//if(v.size != m.nRow)
		//	HAWK_THROW("Vector times matrix with incompatible sizes.", "inline Vector operator*(const Vector& v, const Matrix& m)");

		Vector out(m.nCol);
		for(int j=0; j<m.nCol; j++)
		{
			Real r = 0;
			for(int i=0; i<m.nRow; i++)
			{
				r += m.at(i,j)*v[i];
			}
			out[j] = r;
		}
		return out;
	}

#endif