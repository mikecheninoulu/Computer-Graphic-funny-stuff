#version 150
in vec3 in_Position;
uniform mat4 mvmatrix;
uniform mat4 pmatrix;

void main(void)
{
	// Multiply the mvp matrix by the vertex to obtain our final vertex position
	// gl_Position is an output variable defined by standards
	gl_Position = pmatrix * mvmatrix * vec4(in_Position, 1.0);
}
