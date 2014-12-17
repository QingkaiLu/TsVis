attribute vec4 vPosition;
attribute vec3 vNormal;
attribute vec4 vTensor;

uniform vec3 eyeLightPosition;

varying vec3 vNs;
varying vec3 vLs;
varying vec3 vEs;
varying vec4 tensorPxl;//per-pixle tensor value after passing to frag file

void
main( ) 
{ 

	vec4 ECposition = gl_ModelViewMatrix * vPosition;

	vNs = vNormal;	// surface normal vector

	vLs = eyeLightPosition - ECposition.xyz;		// vector from the point to the light position
	vEs = vec3( 0., 0., 0. ) - ECposition.xyz;		// vector from the point to the eye(not very sure)

	tensorPxl = vTensor;

	gl_Position = gl_ModelViewProjectionMatrix * vPosition;
}