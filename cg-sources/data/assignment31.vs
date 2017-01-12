#version 150
in vec3 in_Position;
in vec2 in_TexCoord0;

// model-view and projection matrices
uniform mat4 mvmatrix;
uniform mat4 pmatrix;
uniform float gtime;
// Texture coordinate for the fragment shader
out vec2 f_TexCoord0; 

void main(void)
{
	// Multiply the mvp matrix by the vertex to obtain our final vertex position
	// gl_Position is an output variable defined by standards
  vec4 newPos = vec4(0.2*in_Position.z*float(sin(in_Position.z*40.0+gtime)), in_Position.y, in_Position.z , 1.0);
  //0.1*in_Position.x*float(sin(in_Position.x*40.0-gtime))
   gl_Position = pmatrix * mvmatrix  * newPos;
 //   gl_Position = mvpmatrix * vec4(in_Position, 1.0);
	f_TexCoord0 = in_TexCoord0;
}
