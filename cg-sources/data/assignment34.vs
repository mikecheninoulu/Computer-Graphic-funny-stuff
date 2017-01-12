#version 150
in vec3 in_Position;
in vec2 in_TexCoord0;

// model-view and projection matrices
uniform mat4 mvmatrix;
uniform mat4 pmatrix;
// Texture coordinate for the fragment shader
out vec2 f_TexCoord0; 

void main(void)
{
	// Multiply the mvp matrix by the vertex to obtain our final vertex position
	// gl_Position is an output variable defined by standards
   gl_Position = pmatrix * mvmatrix  *  vec4(in_Position, 1.0);
	f_TexCoord0 = in_TexCoord0;
}
