uniform float uKa, uKd, uKs;
//uniform vec4  uColor;
uniform vec4  uSpecularColor;
uniform float uShininess;

varying vec3 vNs;
varying vec3 vLs;
varying vec3 vEs;
varying vec4 tensorPxl;

void
main( )
{
	vec3 Normal;
	vec3 Light;
	vec3 Eye;

	Normal = normalize(vNs);
	Light =  normalize(vLs);
	Eye =    normalize(vEs);

	vec4  uColor;

	double a = tensorPxl[0];
	double b = tensorPxl[1];
	double c = tensorPxl[2];
	double d = tensorPxl[3];

	double gammaR = (c - b)/2.;
	double gammaS = pow( (float)((a - d)*(a - d) + (b + c)*(b +c)), 0.5)/2.; // float may not be accurate enough
	                                                                         // need to make double work
    if(gammaS==0 || gammaS==gammaR)//Boundary
	uColor = vec4(0.,0.,0.,1.);
	else
	{

	double tan = gammaR/gammaS;

	if(tan>1.)
	uColor = vec4(1.,0.,0.,1.);//deep red for CCWC
	else if(tan>0.)
	uColor = vec4(1.,0.5,0.5,1.);//slight red for CCWR
	else if(tan>-1.)
	uColor = vec4(0.3,1.,0.,1.);//slight green for CWR
	else
	uColor = vec4(0.,0.9,0.,1.);//deep green for CWC
	}

	vec4 ambient = uKa * uColor;

	float dir = max( dot(Normal,Light), 0. );
	vec4 diffuse = uKd * dir * uColor;

	float s = 0.;
	if( dot(Normal,Light) > 0. )		// only do specular if the light can see the point
	{
		vec3 ref = normalize( 2. * Normal * dot(Normal,Light) - Light );
		s = pow( max( dot(Eye,ref),0. ), uShininess );
	}
	vec4 specular = uKs * s * uSpecularColor;

	gl_FragColor = vec4( ambient.rgb + diffuse.rgb + specular.rgb, 1. );
	//gl_FragColor = uColor;
}
