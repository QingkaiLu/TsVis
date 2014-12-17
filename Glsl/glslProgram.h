/*
----------------------------------------------------------------------
C++ class for glsl API revised from Prof. Mike Bailey's code.
----------------------------------------------------------------------
*/
#ifndef GLSLPROGRAM_H
#define GLSLPROGRAM_H

#include <ctype.h>
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

#ifdef WIN32
#include <windows.h>
#endif

#include "glew.h"
#include <gl.h>
#include <glu.h>
#include "glut.h"
#include <map>
#include <stdarg.h>
#include"../Vector.h"

// Define a helpful macro for handling offsets into buffer objects
#define BUFFER_OFFSET( offset )   ((GLvoid*) (offset))

inline int GetOSU( int flag )
{
	int i;
	glGetIntegerv( flag, &i );
	return i;
}


void	CheckGlErrors( const char* );



class GLSLProgram
{
  private:
	std::map<char *, int>	AttributeLocs;
	char *			Ffile;
	unsigned int		Fshader;
	char *			Gfile;
	GLuint			Gshader;
	bool			IncludeGstap;
	GLenum			InputTopology;
	GLenum			OutputTopology;
	GLuint			Program;
	char *			TCfile;
	GLuint			TCshader;
	char *			TEfile;
	GLuint			TEshader;
	std::map<char *, int>	UniformLocs;
	bool			Valid;
	char *			Vfile;
	GLuint			Vshader;
	bool			Verbose;

	static int		CurrentProgram;

	void	AttachShader( GLuint );
	bool	CanDoBinaryFiles;
	bool	CanDoFragmentShaders;
	bool	CanDoGeometryShaders;
	bool	CanDoTessControlShaders;
	bool	CanDoTessEvaluationShaders;
	bool	CanDoVertexShaders;
	int	CompileShader( GLuint );
	bool	CreateHelper( char *, ... );


  public:
		GLSLProgram( );

	bool	Create( char *, char * = NULL, char * = NULL, char * = NULL, char * = NULL );
	bool	IsExtensionSupported( const char * );
	bool	IsNotValid( );
	bool	IsValid( );
	int	GetAttributeLocation( char * );
	//int	GetUniformLocation( char * );
	void	LoadBinaryFile( char * );
	void	LoadProgramBinary( const char *, GLenum );
	void	SaveBinaryFile( char * );
	void	SaveProgramBinary( const char *, GLenum * );
	void	SetAttribute( char *, int );
	void	SetAttribute( char *, float );
	void	SetAttribute( char *, float, float, float );
	void	SetAttribute( char *, float[3] );
#ifdef VEC3_H
	void	SetAttribute( char *, Vec3& );
#endif
#ifdef VERTEX_ARRAY_H
	void	SetAttribute( char *, VertexArray&, GLenum );
#endif
#ifdef VERTEX_BUFFER_OBJECT_H
	void	SetAttribute( char *, VertexBufferObject&, GLenum );
#endif
	void	SetGstap( bool );
	void	SetInputTopology( GLenum );
	void	SetOutputTopology( GLenum );
	//void	SetUniform( char *, int );
	void	SetUniform( char *, float );
	//void	SetUniform( char *, float, float, float );
	//void	SetUniform( char *, float[3] );
	void	SetUniform( char *, Vector3f& v);
	void	SetUniform( char *, Vector4f& v);
#ifdef MATRIX4_H
	void	SetUniform( char *, Matrix4& );
#endif
	void	SetVerbose( bool );
	void	Use( );
	void	Use( GLuint );
	void	UseFixedFunction( );
};

#endif		// #ifndef GLSLPROGRAM_H
