
#include "Polyhedron\Polyhedron.h"
#include "Matrix.h"
#include "Vector.h"
#include "Quaternion.h"
#include"Glsl\glslProgram.h"

/**
 * Encapsulate all operations relating to rendering of mesh and field, mostly visualization.
 * \a FieldRenderer is responsible for visulizing vector and tensor field stored
 * in \a Polyhedron, i.e. preparing and blending various visualization techniques
 * to get final visualization, as well as performing picking, saving images, etc.
 */
class FieldRenderer
{
private:
	static FieldRenderer* mSingle; //for singleton
	Polyhedron* mPoly;
	Vector3		mScale;		///< scaling applied to the mesh
	Vector3		mTranslate;	///< translation applied to the mesh
	Quaternion	mRotation;	///< rotation applied to the mesh
	//Vector4* points; // points to draw
	//Vector3* normals; // normals of points
	GLSLProgram* initShader;

	FieldRenderer()
	{
		mPoly = NULL;
		initShader = NULL;

		resetTransform();
	}
	
	FieldRenderer(Polyhedron* poly)
	{
		mPoly = poly;
		initShader = NULL;
		
		resetTransform();
	}

public:

	FieldRenderer* getInstance() //for singleton
	{
		if(!mSingle)
			mSingle = new FieldRenderer();
		return mSingle;
	}

	FieldRenderer* getInstance(Polyhedron* poly) //for singleton
	{
		if(!mSingle)
			mSingle = new FieldRenderer(poly);
		return mSingle;
	}

	FieldRenderer* getRenderer()
	{
		return mSingle;
	}

	void resetTransform()
	{
		mScale.set(1,1,1);
		//mScale.set(2.,2.,2.);
		// for hexagon mesh (diesel engine slice):
		/*/
		Real s = 2.0/sqrt(3.0);
		mScale.set(s,s,0);
		//*/

		mTranslate.set(0,0,0);
		mRotation.set(Degree(0),Vector3(0,1,0));
	}

	void setupTransform(bool picking=false);


	void rotate(Quaternion& q)
	{
		mRotation = mRotation * q;
	}

	void translate(Real dx, Real dy, Real dz)
	{
		mTranslate.x += dx;
		mTranslate.y += dy;
		mTranslate.z += dz;
	}
 	void scale(Real sx, Real sy, Real sz)
	{
		mScale.x *= sx;
		mScale.y *= sy;
		mScale.z *= sz;
	}

	Polyhedron* getPoly()
	{
		return mPoly;
	}

	void setPoly(Polyhedron* poly)
	{
		mPoly = poly;
		//resetTransform();
	}

	//Initialize GLSL
	void initGlsl(bool& isPlyChanged);

	/**
	 * Display the eigenvector manifold by rendering the four different areas with different colors.
	 * Four areas of the eigenvector manifold and their correspoding color:
	 * CCWC-deep red CCWR-slight red CWR-slight green CWC-deep green
	 * (CW is simplified for clockwise, CCW for counterclockwise, R for real, C for complex)
	 */
	void renderEigVecMfd();


};