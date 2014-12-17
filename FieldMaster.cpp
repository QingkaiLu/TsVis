#include"stdafx.h"

#include"FieldMaster.h"
#include"Polyhedron\Polyhedron.h"

FieldMaster* FieldMaster::mSingle = NULL;

void FieldMaster::initPoly()
{
  mPoly->initialize(); 
  mPoly->calc_bounding_sphere();
  mPoly->calc_face_normals_and_area();
  mPoly->average_normals();

  // set up triangle local frame

  for(int i=0; i<mPoly->ntris; ++i)
  {
	  Triangle* t = mPoly->tlist[i];

	  // set up 3D triangle local frame
	  t->mLocalAxis[2] = t->normal;
	  t->mLocalAxis[0] = (t->verts[1]->getGlobalPos() - 
		  t->verts[0]->getGlobalPos()).normalizedVector();
	  t->mLocalAxis[1] = t->mLocalAxis[2].cross(t->mLocalAxis[0]);

	  // set up 2D triangle local frame
	  t->mLocalAxis2D[0].set(t->mLocalAxis[0].x, t->mLocalAxis[0].y);
	  t->mLocalAxis2D[0].normalize();	  
	  t->mLocalAxis2D[1].set(t->mLocalAxis[1].x, t->mLocalAxis[1].y);
	  t->mLocalAxis2D[1].normalize();

	  // set up 2D coordinates of triangle's vertices 
	  t->mVertexLocalCoord[0].set(0., 0.);
	  t->mVertexLocalCoord[1].set((t->verts[1]->getGlobalPos() - 
		  t->verts[0]->getGlobalPos()).length(), 0.);
	  t->mVertexLocalCoord[2] = t->globalToLocalPoint(Vector2(
		  t->verts[2]->x, t->verts[2]->y));

	  // test the interpolation
	  //Matrix2x2 tensor;
	  //tensor = t->interpolateTensor(Vector2(Real(0.7071/3.),Real(0.7071/3.)));
	  //tensor = t->interpolateTensor(Vector2(Real(2/3.),Real(2/3.)));

	  //tensor = t->interpolateTensor(Vector2(Real(1.),Real(1./1.732050807568877)));
	  //Vector3 bary = t->getBarycentricCoord(Real(1.),Real(1./1.732050807568877));
	  //tensor = t->interpolateTensor(bary);

	  //tensor = t->interpolateTensor(Vector2(Real(0.832),Real(3.05)));
	  //bary = t->getBarycentricCoord(Real(0.832),Real(3.05));
	  //tensor = t->interpolateTensor(bary);
	  //Matrix2x2 tensor2 = tensor;
  }
}