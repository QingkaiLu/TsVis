#include "StdAfx.h"
#include"FieldRenderer.h"
//#include "glut.h"
using namespace std;

FieldRenderer* FieldRenderer::mSingle = NULL;

void FieldRenderer::setupTransform(bool picking)
{
	glMatrixMode(GL_PROJECTION);
	if(!picking) glLoadIdentity();
	double side = mPoly->radius; 
	double cx = mPoly->center.x;
	double cy = mPoly->center.y;
	//gluPerspective(60, VisOpManager::mWinWidth/VisOpManager::mWinHeight, 0, 100);//mPoly->radius*1.2);
	glOrtho(cx-side,cx+side,cy-side,cy+side,0,100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0,0,5, 0,0,0, 0,1,0);

	glTranslated(mTranslate.x, mTranslate.y, mTranslate.z);
	Vector3& r = mRotation.getAxis();

	glTranslatef(mPoly->center.x, mPoly->center.y, mPoly->center.z);
	glRotated(mRotation.getAngle().getDegreeValue(), r.x, r.y, r.z);
	glScaled(mScale.x, mScale.y, mScale.z);
	glTranslatef(-mPoly->center.x, -mPoly->center.y, -mPoly->center.z);

	//glScalef(2,2,2);
}

void FieldRenderer::initGlsl(bool& isPlyChanged)
{
	
	//gurantee only initialize glsl once, unless open another file in interface
	if(!isPlyChanged) 
	return;        

	int nPoint = 3*(mPoly->ntris);
	Vector4* points = new Vector4[nPoint];
	Vector3* normals = new Vector3[nPoint];
	Vector4* tensors = new Vector4[nPoint];

	for(int i=0;i<mPoly->ntris;++i)
	{
		Triangle *tempT = mPoly->tlist[i];
		for(int j=0;j<3;++j)
		{
			Vertex* tempV = tempT->verts[j];
			points[i*3+j].set(tempV->x,tempV->y,tempV->z,1.0);
			normals[i*3+j].set(tempV->normal[0],tempV->normal[1],tempV->normal[2]);
			tensors[i*3+j].set(tempV->mTensor.a,tempV->mTensor.b,tempV->mTensor.c,tempV->mTensor.d);
		}
	}

	//GLSLProgram initShader;
	if(!initShader)
	initShader = new GLSLProgram;
	if(initShader->Create("Glsl\\tenVis.vert", "Glsl\\tenVis.frag",NULL))
		initShader->Use();
	else
	fprintf(stderr, "Error: %s\n", "Can't create shader!");

	//create a vertex array object
	GLuint vao;
    glGenVertexArrays( 1, &vao );
    glBindVertexArray( vao );

	//create and initialize a buffer object
    GLuint buffer;
    glGenBuffers( 1, &buffer );
    glBindBuffer( GL_ARRAY_BUFFER, buffer );
    glBufferData( GL_ARRAY_BUFFER, sizeof(points[0])*nPoint + sizeof(normals[0])*nPoint 
		+ sizeof(tensors[0])*nPoint, NULL, GL_STATIC_DRAW );
    glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(points[0])*nPoint, points );
    glBufferSubData( GL_ARRAY_BUFFER, sizeof(points[0])*nPoint,
		    sizeof(normals[0])*nPoint, normals );
	glBufferSubData( GL_ARRAY_BUFFER, sizeof(points[0])*nPoint + sizeof(normals[0])*nPoint,
		sizeof(tensors[0])*nPoint, tensors );

	int vPosition = initShader->GetAttributeLocation("vPosition");
	//initShader.Use();
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer( vPosition, 4, GL_DOUBLE, GL_FALSE, 0, BUFFER_OFFSET(0) );

    int vNormal = initShader->GetAttributeLocation("vNormal");
	//initShader.Use();
	glEnableVertexAttribArray(vNormal);
	glVertexAttribPointer( vNormal, 3, GL_DOUBLE, GL_FALSE, 0, BUFFER_OFFSET(sizeof(points[0])*nPoint) );

	int vTensor = initShader->GetAttributeLocation("vTensor");
	//initShader.Use();
	glEnableVertexAttribArray(vTensor);
	glVertexAttribPointer( vTensor, 4, GL_DOUBLE, GL_FALSE, 0,
		BUFFER_OFFSET(sizeof(points[0])*nPoint + sizeof(normals[0])*nPoint) );


	Vector3f eyeLightPos(.0, .0, 20.0);
	initShader->SetUniform("eyeLightPosition",eyeLightPos);

	float uKa=0.1, uKd=0.6, uKs=0.3;
	initShader->SetUniform("uKa", uKa);
	initShader->SetUniform("uKd", uKd);
	initShader->SetUniform("uKs", uKs);

	float uShine = 10.0;
	initShader->SetUniform("uShininess",uShine);

	//Vector4f uColor(0., 0.8, 0.5, 1.);
	//initShader->SetUniform("uColor",uColor);

	Vector4f uSpecColor(1., 1., 1., 1.);
	initShader->SetUniform("uSpecularColor",uSpecColor);

	isPlyChanged = false;

}
void FieldRenderer::renderEigVecMfd()
{
	
	//glBindVertexArray(vao);
	//glShadeModel(GL_FLAT);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays( GL_TRIANGLES, 0, 3*(mPoly->ntris));

}
