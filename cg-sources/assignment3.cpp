/**
 * \brief Example Scene 3 implementation
 * \file
 */
#include <cassert>
#include <iostream>
#include "assignment3.h"
#include <stack>

std::stack<glm::mat4> glm_ModelViewMatrix;
//int xpos, ypos;

float speed = 0.6f; 
float wheelvalue = 0.0f;
float horizontalAngle = 3.14f;
float verticalAngle = 0.0f;

int gwidth = 0; 
int gheight = 0;
float fovy = 45.0f;

float r1=0.0;
float g1=0.0;
float b1=0.0;

glm::vec3 position = glm::vec3( 0, 0, 5 );
glm::vec3 direction= glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 right = glm::vec3( sin(horizontalAngle - 3.14f/2.0f), 0, cos(horizontalAngle - 3.14f/2.0f));// Right vector
glm::vec3 up = glm::cross( right, direction );

unsigned int stars = 3; 
float Starposx[15] = {8.0f, -9.5f, -10.7f};
float Starposy[15] = {8.0f, 6.3f, -3.9f};
float Starposz[15] = {-18.5f, -19.5f, -19.2f};
float Starsize[15] = {0.5f, 0.4f, 0.3f};

void  Assignment3::createTail()
{
	// Define our object (Texture-mapped).
	// Note that after it has been stored in GPU memory, source buffers could be freed as long as we remember how many
	// vertices we want to to render from it.
	tail.clear();
	tailIndices.clear();

	float x0=0.0f;
	float x1=0.0f;
	float x2=0.0f;
	float x3=0.0f;
	float x4=0.0f;
	float x5=0.0f;
	float x6=0.0f;
	float x7=0.0f;

	float z0=-0.0f;
	float z1=-0.2f;
	float z2=-0.4f;
	float z3=-0.6f;
	float z4=-0.8f;
	float z5=-1.0f;
	float z6=-1.2f;	
	float z7=-1.4f;

// clomn 1:  block v1, v2
	//v1
	tail.push_back(Vertexsub(x0, 0.0f, z0 , 0.0f, 0.0f)); // 0
	tail.push_back(Vertexsub(x1, 0.0f, z1, 1.0f / 7.0f, 0.0f)); // 1
	tail.push_back(Vertexsub(x1, 0.2f, z1, 1.0f / 7.0f, 1.0f )); // 2
	//v2
	tail.push_back(Vertexsub(x0, 0.2f, z0, 0.0f, 1.0f )); // 3

// clomn 2:  block v3, v4 
	//v3
	tail.push_back(Vertexsub(x2, 0.0f, z2, 2.0f / 7.0f, 0.0f)); // 4
	//v4
	tail.push_back(Vertexsub(x2, 0.2f, z2, 2.0f / 7.0f, 1.0f )); // 5

// clomn 3:  block v5, v6
	//v5
	tail.push_back(Vertexsub(x3, 0.0f, z3, 3.0f / 7.0f, 0.0f)); // 5
	//6
	tail.push_back(Vertexsub(x3, 0.2f, z3, 3.0f / 7.0f, 1.0f )); // 6

// clomn 4:  block v7, v8
	//v7
	tail.push_back(Vertexsub(x4, 0.0f, z4,  4.0f / 7.0f, 0.0f)); // 7
	//v8
	tail.push_back(Vertexsub(x4, 0.2f, z4, 4.0f / 7.0f, 1.0f )); // 8

// clomn 5:  block v9,v10
	//v9
	tail.push_back(Vertexsub(x5, 0.0f, z5, 5.0f / 7.0f, 0.0f)); // 9
	//v10
	tail.push_back(Vertexsub(x5, 0.2f, z5, 5.0f / 7.0f, 1.0f )); // 10

// clomn 6:  block v11,v12
	//v9
	tail.push_back(Vertexsub(x6, 0.0f, z6, 6.0f / 7.0f, 0.0f)); // 10
	//v10
	tail.push_back(Vertexsub(x6, 0.2f, z6, 6.0f / 7.0f, 1.0f )); // 11

// clomn 7:  block v13,v14
	//v9
	tail.push_back(Vertexsub(x7, 0.0f, z7, 7.0f / 7.0f, 0.0f)); // 12
	//v10
	tail.push_back(Vertexsub(x7, 0.2f, z7, 7.0f / 7.0f, 1.0f )); // 13


	// Triangle 1 of block 1:012
	tailIndices.push_back(0); tailIndices.push_back(1); tailIndices.push_back(2);
	// Triangle 2 of block 1: 230
	tailIndices.push_back(2); tailIndices.push_back(3); tailIndices.push_back(0);
	// Triangle 1 of block 2: 145
	tailIndices.push_back(1); tailIndices.push_back(4); tailIndices.push_back(5);
	// Triangle 2 of block 2: 521
	tailIndices.push_back(5); tailIndices.push_back(2); tailIndices.push_back(1);
	// Triangle 1 of block 3: 467
	tailIndices.push_back(4); tailIndices.push_back(6); tailIndices.push_back(7);
	// Triangle 2 of block 3: 754
	tailIndices.push_back(7); tailIndices.push_back(5); tailIndices.push_back(4);
	// Triangle 1 of block 4: 689
	tailIndices.push_back(6); tailIndices.push_back(8); tailIndices.push_back(9);
	// Triangle 2 of block 4: 976
	tailIndices.push_back(9); tailIndices.push_back(7); tailIndices.push_back(6);
	// Triangle 1 of block 5: 81011
	tailIndices.push_back(8); tailIndices.push_back(10); tailIndices.push_back(11);
	// Triangle 2 of block 5: 1198
	tailIndices.push_back(11); tailIndices.push_back(9); tailIndices.push_back(8);

}

void Assignment3::createHead()
{
	// Define our object (Texture-mapped 2x2x2 cube centered at origin).
	// Note that after it has been stored in GPU memory, source buffers could be freed as long as we remember how many
	// vertices we want to to render from it.
	// 
	// Because we need different texture coordinates (and normal coordinates for lighting calculations), we need to define different vertices
	// for all the different parameter combinations even when position coordinates for the same vertex are the same. If _all_ the used vertex
	// properties (position, normal, texture coordinates, vertex color, ...) are the same, we can reuse the same index value! This happens
	// in this example when we define triangles that form each side of the cube.
	//
	// After we have defined each side, we also define vertex index values that are used for actual triangles that are drawn. All the triangles
	// are defined in counter-clockwise orientation.
	//
	// Texture coordinates with labeled sides      Vertex names for our cube
	//                                             v8      v7
	//  3/3+---+---+---+                           *------*     y
	//     | 1 | 2 | 3 |                          /|     /|     ^
	//  2/3+---+---+---+                       v4/ |  v3/ |     |
	//     | 4 | 5 | 6 |                        *--*---*--*v6   +--->x
	//  1/3+---+---+---+                        | /v5  | /     /
	//     |   |   |   |                        |/     |/     z
	//    0+---+---+---+                        *------*
	//     0  1/3 2/3 3/3                      v1      v2
	//
	// Bottom area of the texture will be unused in this example so that when a square texture is used, the source texture is not stretched
	head.clear();
	headIndices.clear();


	// Side 1: v1, v2, v3, v4 (front)
	head.push_back(Vertexsub(-1.0f, -1.0f, 1.0f, 0.0f, 2.0f / 3.0f)); // 0: Vertexsub 1 of side 1
	head.push_back(Vertexsub(1.0f, -1.0f, 1.0f, 1.0f / 3.0f, 2.0f / 3.0f)); // 1: Vertexsub 2 of side 1
	head.push_back(Vertexsub(1.0f, 1.0f, 1.0f, 1.0f / 3.0f, 3.0f / 3.0f)); // 2: Vertexsub 3 of side 1
	head.push_back(Vertexsub(-1.0f, 1.0f, 1.0f, 0.0f, 3.0f / 3.0f)); // 3: Vertexsub 4 of side 1
	// Triangle 1 of side 1: v1, v2, v3
	headIndices.push_back(0); headIndices.push_back(1); headIndices.push_back(2);

	// Triangle 2 of side 1: v3, v4, v1
	headIndices.push_back(2); headIndices.push_back(3); headIndices.push_back(0);

	// Side 2: v2, v6, v7, v3 (right side)
	head.push_back(Vertexsub(1.0f, -1.0f, 1.0f, 1.0f / 3.0f, 2.0f / 3.0f)); // 4: Vertexsub 2 of side 2
	head.push_back(Vertexsub(1.0f, -1.0f, -1.0f, 2.0f / 3.0f, 2.0f / 3.0f)); // 5: Vertexsub 6 of side 2
	head.push_back(Vertexsub(1.0f, 1.0f, -1.0f, 2.0f / 3.0f, 3.0f / 3.0f)); // 6: Vertexsub 7 of side 2
	head.push_back(Vertexsub(1.0f, 1.0f, 1.0f, 1.0f / 3.0f, 3.0f / 3.0f)); // 7: Vertexsub 3 of side 2

	// Triangle 1 of side 2: v2, v6, v7
	headIndices.push_back(4); headIndices.push_back(5); headIndices.push_back(6);
	// Triangle 2 of side 2: v7, v3, v2
	headIndices.push_back(6); headIndices.push_back(7); headIndices.push_back(4);

	// Side 3: v2, v1, v5, v6 (bottom)
	head.push_back(Vertexsub(1.0f, -1.0f, 1.0f, 2.0f / 3.0f, 2.0f / 3.0f)); // 8: Vertexsub 2 of side 3
	head.push_back(Vertexsub(-1.0f, -1.0f, 1.0f, 3.0f / 3.0f, 2.0f / 3.0f)); // 9: Vertexsub 1 of side 3
	head.push_back(Vertexsub(-1.0f, -1.0f, -1.0f, 3.0f / 3.0f, 3.0f / 3.0f)); // 10: Vertexsub 5 of side 3
	head.push_back(Vertexsub(1.0f, -1.0f, -1.0f, 2.0f / 3.0f, 3.0f / 3.0f)); // 11: Vertexsub 6 of side 3

	// Triangle 1 of side 3: v1, v2, v6
	headIndices.push_back(8); headIndices.push_back(9); headIndices.push_back(10);
	// Triangle 2 of side 3: v6, v5, v1
	headIndices.push_back(10); headIndices.push_back(11); headIndices.push_back(8);

	// Side 4: v4, v3, v7, v8 (top)
	head.push_back(Vertexsub(-1.0f, 1.0f, 1.0f, 0.0f, 1.0f / 3.0f)); // 12: Vertexsub 4 of side 4
	head.push_back(Vertexsub(1.0f, 1.0f, 1.0f, 1.0f / 3.0f, 1.0f / 3.0f)); // 13: Vertexsub 3 of side 4
	head.push_back(Vertexsub(1.0f, 1.0f, -1.0f, 1.0f / 3.0f, 2.0f / 3.0f)); // 14: Vertexsub 7 of side 4
	head.push_back(Vertexsub(-1.0f, 1.0f, -1.0f, 0.0f, 2.0f / 3.0f)); // 15: Vertexsub 8 of side 4

	// Triangle 1 of side 4: v4, v3, v7
	headIndices.push_back(12); headIndices.push_back(13); headIndices.push_back(14);
	// Triangle 2 of side 4: v7, v8, v4
	headIndices.push_back(14); headIndices.push_back(15); headIndices.push_back(12);

	// Side 5: v5, v1, v4, v8 (left)
	head.push_back(Vertexsub(-1.0f, -1.0f, -1.0f, 1.0f / 3.0f, 1.0f / 3.0f)); // 16: Vertexsub 5 of side 5
	head.push_back(Vertexsub(-1.0f, -1.0f, 1.0f, 2.0f / 3.0f, 1.0f / 3.0f)); // 17: Vertexsub 1 of side 5
	head.push_back(Vertexsub(-1.0f, 1.0f, 1.0f, 2.0f / 3.0f, 2.0f / 3.0f)); // 18: Vertexsub 4 of side 5
	head.push_back(Vertexsub(-1.0f, 1.0f, -1.0f, 1.0f / 3.0f, 2.0f / 3.0f)); // 19: Vertexsub 8 of side 5

	// Triangle 1 of side 5: v5, v1, v4
	headIndices.push_back(16); headIndices.push_back(17); headIndices.push_back(18);
	// Triangle 2 of side 5: v4, v8, v5
	headIndices.push_back(18); headIndices.push_back(19); headIndices.push_back(16);

	// Side 6: v6, v5, v8, v7 (back)
	head.push_back(Vertexsub(1.0f, -1.0f, -1.0f, 2.0f / 3.0f, 1.0f / 3.0f)); // 20: Vertexsub 6 of side 6
	head.push_back(Vertexsub(-1.0f, -1.0f, -1.0f, 3.0f / 3.0f, 1.0f / 3.0f)); // 21: Vertexsub 5 of side 6
	head.push_back(Vertexsub(-1.0f, 1.0f, -1.0f, 3.0f / 3.0f, 2.0f / 3.0f)); // 22: Vertexsub 8 of side 6
	head.push_back(Vertexsub(1.0f, 1.0f, -1.0f, 2.0f / 3.0f, 2.0f / 3.0f)); // 23: Vertexsub 7 of side 6

	// Triangle 1 of side 6: v6, v5, v8
	headIndices.push_back(20); headIndices.push_back(21); headIndices.push_back(22);
	// Triangle 2 of side 6: v8, v7, v6
	headIndices.push_back(22); headIndices.push_back(23); headIndices.push_back(20);
}



void Assignment3::createIcosahedron(std::vector<Vertex> &icosahedron, std::vector<GLushort> &icosahedronIndices) const
{
	// Define our object. Note that after it has been stored in GPU memory, source buffers could be freed as long as we remember how many
	// vertices we want to to render from it
	icosahedron.clear();

	icosahedron.push_back(Vertex(glm::normalize(glm::vec3(-0.26286500f, 0.0000000f, 0.42532500f)), glm::vec3(0.0f, 0.0f, 0.0f), glm::normalize(glm::vec3(-0.26286500f, 0.0000000f, 0.42532500f))));
	icosahedron.push_back(Vertex(glm::normalize(glm::vec3(0.26286500f, 0.0000000f, 0.42532500f)), glm::vec3(1.0f, 0.0f, 0.0f), glm::normalize(glm::vec3(0.26286500f, 0.0000000f, 0.42532500f))));
	icosahedron.push_back(Vertex(glm::normalize(glm::vec3(-0.26286500f, 0.0000000f, -0.42532500f)), glm::vec3(0.0f, 1.0f, 0.0f), glm::normalize(glm::vec3(-0.26286500f, 0.0000000f, -0.42532500f))));
	icosahedron.push_back(Vertex(glm::normalize(glm::vec3(0.26286500f, 0.0000000f, -0.42532500f)), glm::vec3(0.0f, 0.0f, 1.0f), glm::normalize(glm::vec3(0.26286500f, 0.0000000f, -0.42532500f))));
	icosahedron.push_back(Vertex(glm::normalize(glm::vec3(0.0000000f, 0.42532500f, 0.26286500f)), glm::vec3(1.0f, 1.0f, 0.0f), glm::normalize(glm::vec3(0.0000000f, 0.42532500f, 0.26286500f))));
	icosahedron.push_back(Vertex(glm::normalize(glm::vec3(0.0000000f, 0.42532500f, -0.26286500f)), glm::vec3(1.0f, 0.0f, 1.0f), glm::normalize(glm::vec3(0.0000000f, 0.42532500f, -0.26286500f))));
	icosahedron.push_back(Vertex(glm::normalize(glm::vec3(0.0000000f, -0.42532500f, 0.26286500f)), glm::vec3(0.0f, 1.0f, 1.0f), glm::normalize(glm::vec3(0.0000000f, -0.42532500f, 0.26286500f))));
	icosahedron.push_back(Vertex(glm::normalize(glm::vec3(0.0000000f, -0.42532500f, -0.26286500f)), glm::vec3(1.0f, 1.0f, 1.0f), glm::normalize(glm::vec3(0.0000000f, -0.42532500f, -0.26286500f))));
	icosahedron.push_back(Vertex(glm::normalize(glm::vec3(0.42532500f, 0.26286500f, 0.0000000f)), glm::vec3(1.0f, 0.5f, 0.0f), glm::normalize(glm::vec3(0.42532500f, 0.26286500f, 0.0000000f))));
	icosahedron.push_back(Vertex(glm::normalize(glm::vec3(-0.42532500f, 0.26286500f, 0.0000000f)), glm::vec3(1.0f, 0.0f, 0.5f), glm::normalize(glm::vec3(-0.42532500f, 0.26286500f, 0.0000000f))));
	icosahedron.push_back(Vertex(glm::normalize(glm::vec3(0.42532500f, -0.26286500f, 0.0000000f)), glm::vec3(0.5f, 1.0f, 0.0f), glm::normalize(glm::vec3(0.42532500f, -0.26286500f, 0.0000000f))));
	icosahedron.push_back(Vertex(glm::normalize(glm::vec3(-0.42532500f, -0.26286500f, 0.0000000f)), glm::vec3(0.5f, 0.0f, 1.0f), glm::normalize(glm::vec3(-0.42532500f, -0.26286500f, 0.0000000f))));

	// Create indices
	icosahedronIndices.push_back(0); icosahedronIndices.push_back(6);  icosahedronIndices.push_back(1);
	icosahedronIndices.push_back(0); icosahedronIndices.push_back(11); icosahedronIndices.push_back(6);
	icosahedronIndices.push_back(1); icosahedronIndices.push_back(4);  icosahedronIndices.push_back(0);
	icosahedronIndices.push_back(1); icosahedronIndices.push_back(8);  icosahedronIndices.push_back(4);
	icosahedronIndices.push_back(1); icosahedronIndices.push_back(10); icosahedronIndices.push_back(8);
	icosahedronIndices.push_back(2); icosahedronIndices.push_back(5);  icosahedronIndices.push_back(3);
	icosahedronIndices.push_back(2); icosahedronIndices.push_back(9);  icosahedronIndices.push_back(5);
	icosahedronIndices.push_back(2); icosahedronIndices.push_back(11); icosahedronIndices.push_back(9);
	icosahedronIndices.push_back(3); icosahedronIndices.push_back(7);  icosahedronIndices.push_back(2);
	icosahedronIndices.push_back(3); icosahedronIndices.push_back(10); icosahedronIndices.push_back(7);
	icosahedronIndices.push_back(4); icosahedronIndices.push_back(8);  icosahedronIndices.push_back(5);
	icosahedronIndices.push_back(4); icosahedronIndices.push_back(9);  icosahedronIndices.push_back(0);
	icosahedronIndices.push_back(5); icosahedronIndices.push_back(8);  icosahedronIndices.push_back(3);
	icosahedronIndices.push_back(5); icosahedronIndices.push_back(9);  icosahedronIndices.push_back(4);
	icosahedronIndices.push_back(6); icosahedronIndices.push_back(10); icosahedronIndices.push_back(1);
	icosahedronIndices.push_back(6); icosahedronIndices.push_back(11); icosahedronIndices.push_back(7);
	icosahedronIndices.push_back(7); icosahedronIndices.push_back(10); icosahedronIndices.push_back(6);
	icosahedronIndices.push_back(7); icosahedronIndices.push_back(11); icosahedronIndices.push_back(2);
	icosahedronIndices.push_back(8); icosahedronIndices.push_back(10); icosahedronIndices.push_back(3);
	icosahedronIndices.push_back(9); icosahedronIndices.push_back(11); icosahedronIndices.push_back(0);
}

void Assignment3::createStar()
{
	// Define our object. Note that after it has been stored in GPU memory, source buffers could be freed as long as we remember how many
	// vertices we want to to render from it
	star.clear();


	star.push_back(Vertexstar(-1.0f, 0.3f, 0.0f, 1.0f, 0.0f, 0.0f));
	star.push_back(Vertexstar( 0.0f, -1.7f, 0.0f, 1.0f, 0.0f, 0.0f));
	star.push_back(Vertexstar(1.0f, 0.3f, 0.0f, 1.0f, 0.0f, 0.0f));


	star.push_back(Vertexstar(-1.0f, -0.3f, 0.0f, 1.0f, 0.0f, 0.0f));
	star.push_back(Vertexstar(1.0f, -0.3f, 0.0f, 1.0f, 0.0f, 0.0f));
	star.push_back(Vertexstar( 0.0f, 1.7f, 0.0f, 1.0f, 0.0f, 0.0f));

}

void Assignment3::createHand()
{
	// Define our object. Note that after it has been stored in GPU memory, source buffers could be freed as long as we remember how many
	// vertices we want to to render from it
	hand.clear();

	//v9
	hand.push_back(Vertexsub(-0.1f, 0.0f, 0.0f, 0.0f, 0.0f));
	//v10
	hand.push_back(Vertexsub(0.1f, 0.0f, 0.0f, 0.0f, 1.0f ));

	//v9
	hand.push_back(Vertexsub(0.1f, 1.0f, 0.0f, 1.0f, 0.0f));
	//v10
	hand.push_back(Vertexsub(-0.1f, 1.0f, 0.0f, 1.0f, 1.0f ));

	handIndices.push_back(0); handIndices.push_back(1); handIndices.push_back(2);

	handIndices.push_back(0); handIndices.push_back(2); handIndices.push_back(3);



}

void Assignment3::createSphere(std::vector<Vertex> &sphere, std::vector<GLushort> &sphereIndices, int numTesselations) const
{
	// Start with a tetrahedron
//	createTetrahedron(sphere, sphereIndices);
	createIcosahedron(sphere, sphereIndices);

	// Tesselate object numTesselations times until we have a round enough sphere
	for (int tesselation = 0; tesselation < numTesselations; ++tesselation)
	{
		// Get number of triangles at previous tesselation level
		size_t origTriangles = sphereIndices.size() / 3;

		//std::cout << "Tesselation " << tesselation + 1 << " with " << origTriangles << " triangles" << std::endl;

		// Split each existing triangle v0, v1, v2 into four parts using a new vertices v3, v4 and v5
		//         *v2       //
		//        / \        //
		//       /   \       //
		//    v5*.....*v4    //
		//     / .   . \     //
		//    /   . .   \    //
		// v0*-----*-----*v1 //
		//         v3        //
		for (size_t t = 0; t < origTriangles; ++t)
		{
			// Get a new center point of the vertices
			size_t tpos = t * 3;

			GLushort v0Index = sphereIndices[tpos];
			GLushort v1Index = sphereIndices[tpos + 1];
			GLushort v2Index = sphereIndices[tpos + 2];
			const Vertex &v0 = sphere[v0Index];
			const Vertex &v1 = sphere[v1Index];
			const Vertex &v2 = sphere[v2Index];

//			std::cout << "Splitting triangle (v0, v1, v2): " << v0Index << ", " << v1Index << ", " << v2Index << std::endl;
//			std::cout << "v0 coordinates: " << v0.position.x << ", " << v0.position.y << ", " << v0.position.z << std::endl;
//			std::cout << "v1 coordinates: " << v1.position.x << ", " << v1.position.y << ", " << v1.position.z << std::endl;
//			std::cout << "v2 coordinates: " << v2.position.x << ", " << v2.position.y << ", " << v2.position.z << std::endl;

			// Create new vertices
			Vertex v3(glm::normalize(v0.position + v1.position), 0.5f * (v0.color + v1.color), glm::normalize(v0.position + v1.position));
			Vertex v4(glm::normalize(v1.position + v2.position), 0.5f * (v1.color + v2.color), glm::normalize(v1.position + v2.position));
			Vertex v5(glm::normalize(v2.position + v0.position), 0.5f * (v2.color + v0.color), glm::normalize(v2.position + v0.position));

//			std::cout << "v3 coordinates: " << v3.position.x << ", " << v3.position.y << ", " << v3.position.z << std::endl;
//			std::cout << "v4 coordinates: " << v4.position.x << ", " << v4.position.y << ", " << v4.position.z << std::endl;
//			std::cout << "v5 coordinates: " << v5.position.x << ", " << v5.position.y << ", " << v5.position.z << std::endl;

			// Add a new vertex index for the center point
			GLuint v3Index = static_cast<GLuint>(sphere.size());
			sphere.push_back(v3);
			GLuint v4Index = static_cast<GLuint>(sphere.size());
			sphere.push_back(v4);
			GLuint v5Index = static_cast<GLuint>(sphere.size());
			sphere.push_back(v5);

//			std::cout << "v3 index: " << v3Index << std::endl;
//			std::cout << "v4 index: " << v4Index << std::endl;
//			std::cout << "v5 index: " << v5Index << std::endl;

			// Replace original triangle v0, v1, v2 with v0, v3, v5
			sphereIndices[tpos + 1] = v3Index;
			sphereIndices[tpos + 2] = v5Index;

			// Add triangle v3, v1, v4 to the model
			sphereIndices.push_back(v3Index); sphereIndices.push_back(v1Index); sphereIndices.push_back(v4Index);

			// Add triangle v3, v4, v5 to the model
			sphereIndices.push_back(v3Index); sphereIndices.push_back(v4Index); sphereIndices.push_back(v5Index);

			// Add triangle v5, v4, v2 to the model
			sphereIndices.push_back(v5Index); sphereIndices.push_back(v4Index); sphereIndices.push_back(v2Index);
		}
	}

	// Note that some (half) of new vertices are duplicates after tesselation as edges are shared with another triangle!
	//std::cout << "Created sphere with " << sphere.size() << " vertices and " << sphereIndices.size() / 3 << " faces" << std::endl;

	// Verify that we don't have too many vertices (over 65535)
	assert(sphere.size() <= (GLushort)-1);
}

/**
 * \brief Update mesh shading using Blinn-Phong model.
 * We can create Gouraud-shading (vertex-based shading) this way with a point light source
 * This ignores set vertex colors and overwrites them with given material colors
 */
void Assignment3::updateShading(std::vector<Vertex> &mesh, const glm::mat4 &modelMat, const glm::vec4 lightPos) const
{
	// Viewer parameters
	glm::vec4 viewPos(0.0f, 1.0f, 5.0f, 1.0f);

	// Different light properties
	glm::vec4 lightAmbient(0.2, 0.2, 0.2, 1.0);
	glm::vec4 lightDiffuse(1.0, 1.0, 1.0, 1.0);
	glm::vec4 lightSpecular(1.0, 1.0, 1.0, 1.0);
	glm::float32 attenuationConstant(1.0f);
	glm::float32 attenuationLinear(0.0f);
	glm::float32 attenuationQuadratic(0.0f);

	// Different material properties
	glm::vec4 materialAmbient(1.0, 0.0, 1.0, 1.0);
	glm::vec4 materialDiffuse(1.0, 0.8, 0.0, 1.0);
	glm::vec4 materialSpecular(1.0, 0.8, 0.0, 1.0);
	glm::float32 materialShininess = 100.0f;
	glm::vec4 materialEmission(0.0, 0.3, 0.3, 1.0);

	// Effect of both light and material properties is multiplication
	glm::vec4 ambientProduct = glm::matrixCompMult(lightAmbient, materialAmbient);
	glm::vec4 diffuseProduct = glm::matrixCompMult(lightDiffuse, materialDiffuse);
	glm::vec4 specularProduct = glm::matrixCompMult(lightSpecular, materialSpecular);

	// For each vertex..
	for (unsigned int v = 0; v < mesh.size(); ++v)
	{
		// Diffuse component. Depends on an angle between light source and surface normal.
		// If normal points to opposite direction, it receives no light.
		glm::vec4 lightVector = lightPos - glm::vec4(mesh[v].position, 1.0f);
		glm::float32 lightDistance = glm::length(lightVector);
		lightVector /= lightDistance;
		glm::float32 diffuseCoef = glm::max(glm::dot(glm::vec4(mesh[v].normal, 0.0f), lightVector), 0.0f);

		glm::vec4 diffuse = diffuseCoef * diffuseProduct;

		// Specular component.
		glm::vec4 specular(0.0f, 0.0f, 0.0f, 1.0f);

		if (diffuseCoef > 0.0f)
		{
			glm::vec4 viewDirection = glm::normalize(viewPos - glm::vec4(mesh[v].position, 1.0f));
			glm::vec4 half = glm::normalize(lightVector + viewDirection);

			glm::float32 specularCoef = glm::dot(glm::vec3(half), mesh[v].normal);
			if (specularCoef > 0.0f)
				specular = glm::pow(specularCoef, materialShininess) * specularProduct;
		}

		// Calculate light attenuation based on distance
		glm::float32 lightAttenuation = 1.0f / ((attenuationQuadratic * lightDistance + attenuationLinear) * lightDistance + attenuationConstant);

		// Combine all the components to final colors
		mesh[v].color = (glm::vec3(diffuse) + glm::vec3(specular) + glm::vec3(ambientProduct)) * lightAttenuation + glm::vec3(materialEmission);
	}
}

Assignment3::Assignment3():
    TailTexture(0)
    {

	// These OpenGL functions must be defined by the OpenGL (or through GLEW) for this example to work..
	assert(glBindBuffer != 0);
	assert(glBindVertexArray != 0);
	assert(glBufferData != 0);
	assert(glClear != 0);
	assert(glClearColor != 0);
	assert(glCullFace != 0);
	assert(glDepthFunc != 0);
	assert(glDeleteBuffers != 0);
	assert(glDeleteVertexArrays != 0);
	assert(glDisableVertexAttribArray != 0);
	assert(glDrawArrays != 0);
	assert(glEnable != 0);
	assert(glGenVertexArrays != 0);
	assert(glGenBuffers != 0);
	assert(glUseProgram != 0);
	assert(glUniformMatrix4fv != 0);
	assert(glVertexAttribPointer != 0);
	assert(glViewport != 0);
}

Assignment3::~Assignment3()
{
	// Clean up everything
	glUseProgram(0); // Shader state
	glDisableVertexAttribArray(shaderProgram.getPositionAttribLocation()); // VBO state
	glDisableVertexAttribArray(shaderProgram.getColorAttribLocation());
	glDisableVertexAttribArray(shaderProgram.getTexture0AttribLocation());
	glDeleteBuffers(1, &ibo); // Allocated index data
	glDeleteBuffers(1, &vbo); // Allocated vertex data
	glDeleteVertexArrays(1, &vao); // Allocated object data

	glDeleteBuffers(1, &tailibo); // Allocated index data
	glDeleteBuffers(1, &tailvbo); // Allocated vertex data
	glDeleteVertexArrays(1, &tailvao); // Allocated object data
	glDeleteBuffers(1, &tailvbo); // Allocated vertex data
	glDeleteVertexArrays(1, &tailvao); // Allocated object data

	glDeleteBuffers(1, &staribo); // Allocated index data
	glDeleteBuffers(1, &starvbo); // Allocated vertex data
	glDeleteVertexArrays(1, &starvao); // Allocated object data
	glDeleteBuffers(1, &starvbo); // Allocated vertex data
	glDeleteVertexArrays(1, &starvao); // Allocated object data

	if (TailTexture)
		delete TailTexture;
	if (HeadTexture)
		delete HeadTexture;
	if (HandTexture)
		delete HandTexture;
}

bool Assignment3::init()
{
	// Reset object rotation
	rotation = 0;

	
	// Create tail geometry
	createTail();

	// Create star geometry
	createStar();

	// Create head geometry
	createHead();

	// Create hand geometry
	createHand();

	// Create body main geometry
	int numTesselations = 3;
	createSphere(sphere, sphereIndices, numTesselations);

	// Load texture
	TailTexture = new Texture("data/tail-texture.png");
	HeadTexture = new Texture("data/cube-texture.png");
	HandTexture = new Texture("data/hand-texture.png");
	
	if (TailTexture->getTextureId() == 0)
		return false;
	if (HeadTexture->getTextureId() == 0)
		return false;
	if (HandTexture->getTextureId() == 0)
		return false;

	// Update our model's shading with some orientation in the world
	glm::vec4 lightPos( 0.47f, 0.67f, 0.88f, 1.0f);
	updateShading(sphere, modelMat, lightPos);

	//Initialize clear color for glClear() 
	glClearColor(0.2f, 0.3f, 0.1f, 1.f);

	glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);//both sides
	glCullFace(GL_BACK);
	glDepthFunc(GL_LESS);

	// Enable blending (slower but necessary for partially transparent objects)
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

//build buffer for body ear and foot
	// Allocate and assign a Vertex Array Object to our handle
	glGenVertexArrays(1, &vao);

	// Bind our Vertex Array Object as the current used object
	glBindVertexArray(vao);

	// Create Index Buffer Object
	glGenBuffers(1, &ibo);

	// Bind our Index Buffer Object
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	// Allocate and assign One Vertex Buffer Object to our handle
	glGenBuffers(1, &vbo);

	// Bind our VBO as being the active buffer and storing vertex attributes (coordinates + colors)
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	// Store our index values in Index Buffer Object
	// GL_STATIC_DRAW means that we don't expect this buffer to change (It's a hint that it can be stored on GPU)
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sphereIndices.size() * sizeof(GLushort), &sphereIndices[0], GL_STATIC_DRAW);

	// Copy the vertex data from tetrahedron to our buffer
	// GL_STATIC_DRAW means that we don't expect this buffer to change (It's a hint that it can be stored on GPU)
	glBufferData(GL_ARRAY_BUFFER, sphere.size() * sizeof (struct Vertex), &sphere[0], GL_STATIC_DRAW);

	// Note: The following attribute indexes must match what is defined in shader (in shaderprogram.cpp) for glBindAttribLocation() calls!

	// Specify that our coordinate data is going into attribute index 0 (shaderProgram.getPositionAttribLocation()), and contains three floats per vertex
	glVertexAttribPointer(shaderProgram.getPositionAttribLocation(), 3, GL_FLOAT, GL_FALSE, sizeof (struct Vertex), (const GLvoid*)offsetof(struct Vertex, position));

	// Enable attribute index 0 as being used
	glEnableVertexAttribArray(shaderProgram.getPositionAttribLocation());

	// Specify that our color data is going into attribute index 1 (shaderProgram.getColorAttribLocation()), and contains three floats per vertex
	glVertexAttribPointer(shaderProgram.getColorAttribLocation(), 3, GL_FLOAT, GL_FALSE, sizeof (struct Vertex), (const GLvoid*)offsetof(struct Vertex, color));

	// Enable attribute index 1 as being used
	glEnableVertexAttribArray(shaderProgram.getColorAttribLocation()); // Bind our second VBO as being the active buffer and storing vertex attributes (colors)

	// Specify that our vertex normals are going into attribute index 2 (shaderProgram.getNormalAttribLocation()), and contains three floats per vertex
	glVertexAttribPointer(shaderProgram.getNormalAttribLocation(), 3, GL_FLOAT, GL_FALSE, sizeof(struct Vertex), (const GLvoid*)offsetof(struct Vertex, normal));

	// Enable attribute index 2 as being used
	glEnableVertexAttribArray(shaderProgram.getNormalAttribLocation()); // Bind our second VBO as being the active buffer and storing vertex attributes (colors)


//build buffer for tail
	glGenVertexArrays(1, &tailvao);

	glBindVertexArray(tailvao);
	
 // Create Index Buffer Object
	glGenBuffers(1, &tailibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, tailibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, tailIndices.size() * sizeof(GLushort), &tailIndices[0], GL_STATIC_DRAW);
	// Allocate and ass  ign One Vertex Buffer Object to our handle

	glGenBuffers(1, &tailvbo);
	// Bind our VBO as being the active buffer and storing vertex attributes (coordinates + colors)
	glBindBuffer(GL_ARRAY_BUFFER, tailvbo);
	glBufferData(GL_ARRAY_BUFFER, tail.size() * sizeof (struct Vertexsub), &tail[0], GL_STATIC_DRAW);
	
	// Note: The following attribute indexes must match what is defined in shader (in shaderprogram.cpp) for glBindAttribLocation() calls!

	// Enable attribute index 0 as being used
	glEnableVertexAttribArray(shaderProgram.getPositionAttribLocation());
	// Specify that our coordinate data is going into attribute index 0 (shaderProgram.getPositionAttribLocation()), and contains three doubles per vertex
	// Note stride = sizeof ( struct Vertex ) and pointer = ( const GLvoid* ) 0
	glVertexAttribPointer(shaderProgram.getPositionAttribLocation(), 3, GL_FLOAT, GL_FALSE, sizeof (struct Vertexsub), (const GLvoid*)offsetof(struct Vertexsub, position));

	// Specify that our color data is going into attribute index 1 (shaderProgram.getColorAttribLocation()), and contains three floats per vertex
	// Note stride = sizeof ( struct Vertex ) and pointer = ( const GLvoid* ) ( 3 * sizeof ( GLdouble ) ) i.e. the size (in bytes)
	// occupied by the first attribute (position)
	glVertexAttribPointer(shaderProgram.getTexture0AttribLocation(), 2, GL_FLOAT, GL_FALSE, sizeof (struct Vertexsub), (const GLvoid*)offsetof(struct Vertexsub, uv));

	// Enable attribute index 1 as being used
	glEnableVertexAttribArray(shaderProgram.getTexture0AttribLocation()); // Bind our second VBO as being the active buffer and storing vertex attributes (colors)

//build buffer for hand
	glGenVertexArrays(1, &handvao);

	glBindVertexArray(handvao);
	
 // Create Index Buffer Object
	glGenBuffers(1, &handibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, handibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, handIndices.size() * sizeof(GLushort), &handIndices[0], GL_STATIC_DRAW);
	// Allocate and ass  ign One Vertex Buffer Object to our handle

	glGenBuffers(1, &handvbo);
	// Bind our VBO as being the active buffer and storing vertex attributes (coordinates + colors)
	glBindBuffer(GL_ARRAY_BUFFER, handvbo);
	glBufferData(GL_ARRAY_BUFFER, hand.size() * sizeof (struct Vertexsub), &hand[0], GL_STATIC_DRAW);
	
	// Note: The following attribute indexes must match what is defined in shader (in shaderprogram.cpp) for glBindAttribLocation() calls!

	// Enable attribute index 0 as being used
	glEnableVertexAttribArray(shaderProgram.getPositionAttribLocation());
	// Specify that our coordinate data is going into attribute index 0 (shaderProgram.getPositionAttribLocation()), and contains three doubles per vertex
	// Note stride = sizeof ( struct Vertex ) and pointer = ( const GLvoid* ) 0
	glVertexAttribPointer(shaderProgram.getPositionAttribLocation(), 3, GL_FLOAT, GL_FALSE, sizeof (struct Vertexsub), (const GLvoid*)offsetof(struct Vertexsub, position));

	// Specify that our color data is going into attribute index 1 (shaderProgram.getColorAttribLocation()), and contains three floats per vertex
	// Note stride = sizeof ( struct Vertex ) and pointer = ( const GLvoid* ) ( 3 * sizeof ( GLdouble ) ) i.e. the size (in bytes)
	// occupied by the first attribute (position)
	glVertexAttribPointer(shaderProgram.getTexture0AttribLocation(), 2, GL_FLOAT, GL_FALSE, sizeof (struct Vertexsub), (const GLvoid*)offsetof(struct Vertexsub, uv));

	// Enable attribute index 1 as being used
	glEnableVertexAttribArray(shaderProgram.getTexture0AttribLocation()); // Bind our second VBO as being the active buffer and storing vertex attributes (colors)


//build buffer for head
	glGenVertexArrays(1, &headvao);

	glBindVertexArray(headvao);
	
 // Create Index Buffer Object
	glGenBuffers(1, &headibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, headibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, headIndices.size() * sizeof(GLushort), &headIndices[0], GL_STATIC_DRAW);
	// Allocate and ass  ign One Vertex Buffer Object to our handle

	glGenBuffers(1, &headvbo);
	// Bind our VBO as being the active buffer and storing vertex attributes (coordinates + colors)
	glBindBuffer(GL_ARRAY_BUFFER, headvbo);
	glBufferData(GL_ARRAY_BUFFER, head.size() * sizeof (struct Vertexsub), &head[0], GL_STATIC_DRAW);
	
	// Note: The following attribute indexes must match what is defined in shader (in shaderprogram.cpp) for glBindAttribLocation() calls!

	// Enable attribute index 0 as being used
	glEnableVertexAttribArray(shaderProgram.getPositionAttribLocation());
	// Specify that our coordinate data is going into attribute index 0 (shaderProgram.getPositionAttribLocation()), and contains three doubles per vertex
	// Note stride = sizeof ( struct Vertex ) and pointer = ( const GLvoid* ) 0
	glVertexAttribPointer(shaderProgram.getPositionAttribLocation(), 3, GL_FLOAT, GL_FALSE, sizeof (struct Vertexsub), (const GLvoid*)offsetof(struct Vertexsub, position));

	// Specify that our color data is going into attribute index 1 (shaderProgram.getColorAttribLocation()), and contains three floats per vertex
	// Note stride = sizeof ( struct Vertex ) and pointer = ( const GLvoid* ) ( 3 * sizeof ( GLdouble ) ) i.e. the size (in bytes)
	// occupied by the first attribute (position)
	glVertexAttribPointer(shaderProgram.getTexture0AttribLocation(), 2, GL_FLOAT, GL_FALSE, sizeof (struct Vertexsub), (const GLvoid*)offsetof(struct Vertexsub, uv));

	// Enable attribute index 1 as being used
	glEnableVertexAttribArray(shaderProgram.getTexture0AttribLocation()); // Bind our second VBO as being the active buffer and storing vertex attributes (colors)


//build buffer for star
		// Allocate and assign a Vertex Array Object to our handle
	glGenVertexArrays(1, &starvao);

	// Bind our Vertex Array Object as the current used object
	glBindVertexArray(starvao);

	// Allocate and assign One Vertex Buffer Object to our handle
	glGenBuffers(1, &starvbo);

	// Bind our VBO as being the active buffer and storing vertex attributes (coordinates + colors)
	glBindBuffer(GL_ARRAY_BUFFER, starvbo);

	// Copy the vertex data from tetrahedron to our buffer
	// 12 * sizeof(GLfloat) is the size of the tetrahedrom array, since it contains 12 Vertex values
	// GL_STATIC_DRAW means that we don't expect this buffer to change (It's a hint that it can be stored on GPU)
	glBufferData(GL_ARRAY_BUFFER, star.size() * sizeof (struct Vertexstar), &star[0], GL_STATIC_DRAW);

	// Note: The following attribute indexes must match what is defined in shader (in shaderprogram.cpp) for glBindAttribLoc,ation() calls!

	// Specify that our coordinate data is going into attribute index 0 (shaderProgram.getPositionAttribLocation()), and contains three floats per vertex
	// Note stride = sizeof ( struct Vertex ) and pointer = ( const GLvoid* ) 0
	glVertexAttribPointer(shaderProgram.getPositionAttribLocation(), 3, GL_FLOAT, GL_FALSE, sizeof (struct Vertexstar), (const GLvoid*)offsetof(struct Vertexstar, position));

	// Enable attribute index 0 as being used
	glEnableVertexAttribArray(shaderProgram.getPositionAttribLocation());

	// Specify that our color data is going into attribute index 1 (shaderProgram.getColorAttribLocation()), and contains three floats per vertex
	// Note stride = sizeof ( struct Vertex ) and pointer = ( const GLvoid* ) ( 3 * sizeof ( GLdouble ) ) i.e. the size (in bytes)
	// occupied by the first attribute (position)
	glVertexAttribPointer(shaderProgram.getColorAttribLocation(), 3, GL_FLOAT, GL_FALSE, sizeof (struct Vertexstar), (const GLvoid*)offsetof(struct Vertexstar, color));

	// Enable attribute index 1 as being used
	glEnableVertexAttribArray(shaderProgram.getColorAttribLocation()); // Bind our second VBO as being the active buffer and storing vertex attributes (colors)

	// Unbind buffer (not strictly necessary but it is a state in context instead of vbo
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Reset object rotation
	rotation = 0;
	// Set up our view matrix that determines camera position in the scene
	// glm::lookAt replaces old GLU library functionality for creating a projection matrix
	viewMat = glm::lookAt(glm::vec3(0.0f, 1.0f, 5.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	return true;
}

void Assignment3::resize(GLsizei width, GLsizei height)
{
	// Update OpenGL viewport to match window system's window size
	glViewport(0, 0, width, height);
	gwidth=width;
	gheight=height;

}

void Assignment3::update(float timestep)
{
	// Rotate object
	rotation += glm::two_pi<float>() * 0.1f * timestep;
}

// Render view
void Assignment3::render()
{
	int tempcolorsel;

	// Clear background
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// get time
	gtime = SDL_GetTicks();

	// Set up projection matrix and model matrix etc.

	projectionMat = glm::perspective(fovy - 0.1f * wheelvalue, static_cast<float>(gwidth) / static_cast<float>(gheight), 0.1f, 1000.0f);

	viewMat = glm::lookAt(position, position+direction, up);
	// Update our model's shading with new orientation with the camera
	glm::vec4 lightPos(0.0f, 0.0f, 3.0f, 1.0f);

	// Precalculate transformation matrix for the shader and use it
	glm::vec4 lightInViewPos = viewMat * modelMat * lightPos; // Light tied to object transformation
	//std::cout << "Initial width and height: " << window_width << " x " << window_height << std::endl;
	//cout <<glm_ModelViewMatrix.top()[00]<<endl;

	//glm_ModelViewMatrix.top() =  glm::mat4(1.0); // glLoadIdentity

	glm_ModelViewMatrix.push(glm::mat4(1.0));
	glm_ModelViewMatrix.top() *= viewMat; //=gluLookAt() 




	//draw stars
		shaderProgram.load("data/assignment32.vs", "data/assignment32.fs");
		// Use shader program to render everything
		glUseProgram(shaderProgram.getShaderProgram());

	for (int i = 0; i < stars; ++i)
    {
		tempcolorsel=static_cast <float> (rand()) / static_cast <float> (RAND_MAX)*1000;
		if(tempcolorsel%3==0)
		{
			r1=0.0;
			g1=0.74;
			b1=1.0;
		}
		else if(tempcolorsel%3==1)
		{
			r1=1.0;
			g1=0.27;
			b1=0.0;
		}
		else
			{
			r1=1.0;
			g1=1.0;
			b1=0.0;
		}
		objectColor = glm::vec4(r1, g1 ,b1, 1.0);

		glm_ModelViewMatrix.push(glm_ModelViewMatrix.top() );

		glm_ModelViewMatrix.top() = glm::rotate(glm_ModelViewMatrix.top(), 0.0f, glm::vec3(0.0, 1.0, 0.0)); // Rotate object around y-axis

		glm_ModelViewMatrix.top() = glm::scale(glm_ModelViewMatrix.top(), glm::vec3(Starsize[i], Starsize[i], Starsize[i]));

		glm_ModelViewMatrix.top() = glm::translate(glm_ModelViewMatrix.top(), glm::vec3(Starposx[i], Starposy[i], Starposz[i]));

		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.getShaderProgram(), "mvmatrix"), 1, GL_FALSE, glm::value_ptr(glm_ModelViewMatrix.top()));
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.getShaderProgram(), "pmatrix"), 1, GL_FALSE, glm::value_ptr(projectionMat));
		glUniform4fv(glGetUniformLocation(shaderProgram.getShaderProgram(), "objColor"), 1, &objectColor[0]);

		glBindVertexArray(starvao);
		glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(star.size())); 	
		glBindVertexArray(0);
		glm_ModelViewMatrix.pop();
    }

//draw body
//first node layout
	
glm_ModelViewMatrix.push(glm_ModelViewMatrix.top() ); // = glPushMatrix();
	
	// Load shader program used in this example
	shaderProgram.load("data/assignment33.vs", "data/assignment33.fs");
	// Use shader program to render everything
	glUseProgram(shaderProgram.getShaderProgram());

	// Calculate model transformation
	glm_ModelViewMatrix.top() = glm::rotate(glm_ModelViewMatrix.top(), rotation, glm::vec3(0.0, 1.0, 0.0)); // Rotate object around y-axis

	glm_ModelViewMatrix.top() = glm::scale(glm_ModelViewMatrix.top(), glm::vec3(0.8f, 0.8f, 0.8f));

	glUniformMatrix4fv(glGetUniformLocation(shaderProgram.getShaderProgram(), "mvmatrix"), 1, GL_FALSE, glm::value_ptr(glm_ModelViewMatrix.top()));
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram.getShaderProgram(), "pmatrix"), 1, GL_FALSE, glm::value_ptr(projectionMat));
	glUniform4fv(glGetUniformLocation(shaderProgram.getShaderProgram(), "lightPosition"), 1, glm::value_ptr(lightInViewPos));

	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(sphereIndices.size()), GL_UNSIGNED_SHORT, 0);
		
	//draw head
		//second node layout
		// Calculate model transformation
		glm_ModelViewMatrix.push(glm_ModelViewMatrix.top() ); // = glPushMatrix();

			glm_ModelViewMatrix.top() = glm::scale(glm_ModelViewMatrix.top(), glm::vec3(0.7f, 0.7f, 0.7f));
			glm_ModelViewMatrix.top() = glm::translate(glm_ModelViewMatrix.top(), glm::vec3(0.0f, 2.0f, 0.0f));

			shaderProgram.load("data/assignment34.vs", "data/assignment34.fs");
			// Use shader program to render everything
			glUseProgram(shaderProgram.getShaderProgram());
			// Get uniform location for the shader's texture sampler
			GLint uniform_headShader_texture = glGetUniformLocation(shaderProgram.getShaderProgram(), "texture0");

			if (uniform_headShader_texture < 0)
			{
				std::cerr << "Unable to locate uniform variable texture0 from the shader" << std::endl;
			}
	 
			// Welect what texture unit is used for
			usedTextureUnit = 1;
			glUniform1i(uniform_headShader_texture, usedTextureUnit);
		///*
			glUniformMatrix4fv(glGetUniformLocation(shaderProgram.getShaderProgram(), "mvmatrix"), 1, GL_FALSE, glm::value_ptr(glm_ModelViewMatrix.top()));
			glUniformMatrix4fv(glGetUniformLocation(shaderProgram.getShaderProgram(), "pmatrix"), 1, GL_FALSE, glm::value_ptr(projectionMat));
			// Turn on texture mapping on texture unit 0 and select our texture
			// It is redundant to set the same values all the time but texture settings are included here for clarity
			// glUniform1i(uniform_headShader_texture, usedTextureUnit); <- In init code
			glActiveTexture(GL_TEXTURE0 + usedTextureUnit); // Other textures are GL_TEXTURE0 + i (where i is the texture unit index up to GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS - 1)
			glBindTexture(GL_TEXTURE_2D, HeadTexture->getTextureId());
			// For drawing the flag it needs to be bound using (we never bound anything else to replace that state after init())
			glBindVertexArray(headvao);

			// Count is the number of elements in the array that will form triangles. It is not the number of triangles defined by the array.
			// When VBOs are in use and GL_ELEMENT_ARRAY_BUFFER is bound, the last parameter (pointer to data) is interpreted as an offset within IBO instead of
			// actual program memory address.
			glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(headIndices.size()), GL_UNSIGNED_SHORT, 0);
//	
			glBindVertexArray(0);

		//draw ear 1
			//third node layout in
			// Calculate model transformation
			glm_ModelViewMatrix.push(glm_ModelViewMatrix.top() ); // = glPushMatrix();

				glm_ModelViewMatrix.top() = glm::scale(glm_ModelViewMatrix.top(), glm::vec3(0.2f, 0.5f, 0.2f));
				glm_ModelViewMatrix.top() = glm::translate(glm_ModelViewMatrix.top(), glm::vec3(-2.0f, 2.0f, 0.0f));

				shaderProgram.load("data/assignment33.vs", "data/assignment33.fs");
				// Use shader program to render everything
				glUseProgram(shaderProgram.getShaderProgram());

				glUniformMatrix4fv(glGetUniformLocation(shaderProgram.getShaderProgram(), "mvmatrix"), 1, GL_FALSE, glm::value_ptr(glm_ModelViewMatrix.top()));
				glUniformMatrix4fv(glGetUniformLocation(shaderProgram.getShaderProgram(), "pmatrix"), 1, GL_FALSE, glm::value_ptr(projectionMat));
				glUniform4fv(glGetUniformLocation(shaderProgram.getShaderProgram(), "lightPosition"), 1, glm::value_ptr(lightInViewPos));

				glBindVertexArray(vao);
				glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(sphereIndices.size()), GL_UNSIGNED_SHORT, 0);
			glm_ModelViewMatrix.pop(); // = glPushMatrix();
			//third node layout out
	
		//draw ear 2
			//third node layout in
			// Calculate model transformation
			glm_ModelViewMatrix.push(glm_ModelViewMatrix.top() ); // = glPushMatrix();

				glm_ModelViewMatrix.top() = glm::scale(glm_ModelViewMatrix.top(), glm::vec3(0.2f, 0.5f, 0.2f));
				glm_ModelViewMatrix.top() = glm::translate(glm_ModelViewMatrix.top(), glm::vec3(2.0f, 2.0f, 0.0f));

				glUniformMatrix4fv(glGetUniformLocation(shaderProgram.getShaderProgram(), "mvmatrix"), 1, GL_FALSE, glm::value_ptr(glm_ModelViewMatrix.top()));
				glUniformMatrix4fv(glGetUniformLocation(shaderProgram.getShaderProgram(), "pmatrix"), 1, GL_FALSE, glm::value_ptr(projectionMat));
				glUniform4fv(glGetUniformLocation(shaderProgram.getShaderProgram(), "lightPosition"), 1, glm::value_ptr(lightInViewPos));

				glBindVertexArray(vao);
				glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(sphereIndices.size()), GL_UNSIGNED_SHORT, 0);
			//third node layout out
			glm_ModelViewMatrix.pop(); // = glPushMatrix();
	//second node layout out
	glm_ModelViewMatrix.pop(); // = glPushMatrix();


	//draw foot 1
		//second node layout in
		// Calculate model transformation
		glm_ModelViewMatrix.push(glm_ModelViewMatrix.top() ); // = glPushMatrix();

			glm_ModelViewMatrix.top() = glm::scale(glm_ModelViewMatrix.top(), glm::vec3(0.2f, 0.2f, 0.4f));
			glm_ModelViewMatrix.top() = glm::translate(glm_ModelViewMatrix.top(), glm::vec3(-2.5f,-4.5f, 0.0f));

			glUniformMatrix4fv(glGetUniformLocation(shaderProgram.getShaderProgram(), "mvmatrix"), 1, GL_FALSE, glm::value_ptr(glm_ModelViewMatrix.top()));
			glUniformMatrix4fv(glGetUniformLocation(shaderProgram.getShaderProgram(), "pmatrix"), 1, GL_FALSE, glm::value_ptr(projectionMat));
			glUniform4fv(glGetUniformLocation(shaderProgram.getShaderProgram(), "lightPosition"), 1, glm::value_ptr(lightInViewPos));

			glBindVertexArray(vao);
			glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(sphereIndices.size()), GL_UNSIGNED_SHORT, 0);
		glm_ModelViewMatrix.pop(); // = glPushMatrix();
		//second node layout out
	//draw foot 2
		//second node layout in
		// Calculate model transformation
		glm_ModelViewMatrix.push(glm_ModelViewMatrix.top() ); // = glPushMatrix();
			glm_ModelViewMatrix.top() = glm::scale(glm_ModelViewMatrix.top(), glm::vec3(0.2f, 0.2f, 0.4f));
			glm_ModelViewMatrix.top() = glm::translate(glm_ModelViewMatrix.top(), glm::vec3(2.5f,-4.5f, 0.0f));

			glUniformMatrix4fv(glGetUniformLocation(shaderProgram.getShaderProgram(), "mvmatrix"), 1, GL_FALSE, glm::value_ptr(glm_ModelViewMatrix.top()));
			glUniformMatrix4fv(glGetUniformLocation(shaderProgram.getShaderProgram(), "pmatrix"), 1, GL_FALSE, glm::value_ptr(projectionMat));
			glUniform4fv(glGetUniformLocation(shaderProgram.getShaderProgram(), "lightPosition"), 1, glm::value_ptr(lightInViewPos));

			glBindVertexArray(vao);
			glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(sphereIndices.size()), GL_UNSIGNED_SHORT, 0);
			glBindVertexArray(0);
		glm_ModelViewMatrix.pop(); // = glPushMatrix();
		//second node layout out

	//draw hand1
		//second node layout in
		// Calculate model transformation
		glm_ModelViewMatrix.push(glm_ModelViewMatrix.top() ); // = glPushMatrix();
			handrotation=2*sin(gtime/1000.0f);
			//transformation
			glm_ModelViewMatrix.top() = glm::scale(glm_ModelViewMatrix.top(), glm::vec3(1.5f, 1.5f, 0.0f));
			glm_ModelViewMatrix.top() = glm::translate(glm_ModelViewMatrix.top(), glm::vec3(-0.7f, -0.1f,0.0f));
			glm_ModelViewMatrix.top() = glm::rotate(glm_ModelViewMatrix.top(), handrotation, glm::vec3(1.0, 0.0, 0.0)); // Rotate object around y-axis
				// Load shader program used in thqis example
			shaderProgram.load("data/assignment34.vs", "data/assignment34.fs");
			// Use shader program to render everything
			glUseProgram(shaderProgram.getShaderProgram());
			// Get uniform location for the shader's texture sampler
			GLint uniform_handShader_texture = glGetUniformLocation(shaderProgram.getShaderProgram(), "texture0");

			if (uniform_handShader_texture < 0)
			{
				std::cerr << "Unable to locate uniform variable texture0 from the shader" << std::endl;
			}
	 
			// Welect what texture unit is used for
			usedTextureUnit = 2;
			glUniform1i(uniform_handShader_texture, usedTextureUnit);
		///*
			glUniformMatrix4fv(glGetUniformLocation(shaderProgram.getShaderProgram(), "mvmatrix"), 1, GL_FALSE, glm::value_ptr(glm_ModelViewMatrix.top()));
			glUniformMatrix4fv(glGetUniformLocation(shaderProgram.getShaderProgram(), "pmatrix"), 1, GL_FALSE, glm::value_ptr(projectionMat));
			// Turn on texture mapping on texture unit 0 and select our texture
			// It is redundant to set the same values all the time but texture settings are included here for clarity
			// glUniform1i(uniform_handShader_texture, usedTextureUnit); <- In init code
			glActiveTexture(GL_TEXTURE0 + usedTextureUnit); // Other textures are GL_TEXTURE0 + i (where i is the texture unit index up to GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS - 1)
			glBindTexture(GL_TEXTURE_2D, HandTexture->getTextureId());
			// For drawing the flag it needs to be bound using (we never bound anything else to replace that state after init())
			glBindVertexArray(handvao);

			// Count is the number of elements in the array that will form triangles. It is not the number of triangles defined by the array.
			// When VBOs are in use and GL_ELEMENT_ARRAY_BUFFER is bound, the last parameter (pointer to data) is interpreted as an offset within IBO instead of
			// actual program memory address.
			glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(handIndices.size()), GL_UNSIGNED_SHORT, 0);
//	
			glBindVertexArray(0);

		glm_ModelViewMatrix.pop(); // = glPushMatrix();


//draw hand2
		//second node layout in
		// Calculate model transformation
		glm_ModelViewMatrix.push(glm_ModelViewMatrix.top() ); // = glPushMatrix();
			handrotation=2*sin(gtime/1000.0f);
			//transformation
			glm_ModelViewMatrix.top() = glm::scale(glm_ModelViewMatrix.top(), glm::vec3(1.5f, 1.5f, 0.0f));
			glm_ModelViewMatrix.top() = glm::translate(glm_ModelViewMatrix.top(), glm::vec3(0.7f, -0.1f,0.0f));
			glm_ModelViewMatrix.top() = glm::rotate(glm_ModelViewMatrix.top(), -handrotation, glm::vec3(1.0, 0.0, 0.0)); // Rotate object around y-axis
			
			glUniformMatrix4fv(glGetUniformLocation(shaderProgram.getShaderProgram(), "mvmatrix"), 1, GL_FALSE, glm::value_ptr(glm_ModelViewMatrix.top()));
			glUniformMatrix4fv(glGetUniformLocation(shaderProgram.getShaderProgram(), "pmatrix"), 1, GL_FALSE, glm::value_ptr(projectionMat));
			// Turn on texture mapping on texture unit 0 and select our texture
			// It is redundant to set the same values all the time but texture settings are included here for clarity
			// glUniform1i(uniform_handShader_texture, usedTextureUnit); <- In init code
			glActiveTexture(GL_TEXTURE0 + usedTextureUnit); // Other textures are GL_TEXTURE0 + i (where i is the texture unit index up to GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS - 1)
			glBindTexture(GL_TEXTURE_2D, HandTexture->getTextureId());
			// For drawing the flag it needs to be bound using (we never bound anything else to replace that state after init())
			glBindVertexArray(handvao);

			// Count is the number of elements in the array that will form triangles. It is not the number of triangles defined by the array.
			// When VBOs are in use and GL_ELEMENT_ARRAY_BUFFER is bound, the last parameter (pointer to data) is interpreted as an offset within IBO instead of
			// actual program memory address.
			glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(handIndices.size()), GL_UNSIGNED_SHORT, 0);
//	
			glBindVertexArray(0);

		glm_ModelViewMatrix.pop(); // = glPushMatrix();

			
	//draw tail
		//second node layout in
		// Calculate model transformation
		glm_ModelViewMatrix.push(glm_ModelViewMatrix.top() ); // = glPushMatrix();
			
			//transformation
			glm_ModelViewMatrix.top() = glm::scale(glm_ModelViewMatrix.top(), glm::vec3(1.5f, 1.5f, 2.5f));
			glm_ModelViewMatrix.top() = glm::translate(glm_ModelViewMatrix.top(), glm::vec3(0.0f, -0.25f, -0.25f));
				// Load shader program used in thqis example
			shaderProgram.load("data/assignment31.vs", "data/assignment31.fs");
			// Use shader program to render everything
			glUseProgram(shaderProgram.getShaderProgram());
			// Get uniform location for the shader's texture sampler
			GLint uniform_tailShader_texture = glGetUniformLocation(shaderProgram.getShaderProgram(), "texture0");

			if (uniform_tailShader_texture < 0)
			{
				std::cerr << "Unable to locate uniform variable texture0 from the shader" << std::endl;
			}
	 
			// Welect what texture unit is used for
			usedTextureUnit = 0;
			glUniform1i(uniform_tailShader_texture, usedTextureUnit);
		///*
			glUniformMatrix4fv(glGetUniformLocation(shaderProgram.getShaderProgram(), "mvmatrix"), 1, GL_FALSE, glm::value_ptr(glm_ModelViewMatrix.top()));
			glUniformMatrix4fv(glGetUniformLocation(shaderProgram.getShaderProgram(), "pmatrix"), 1, GL_FALSE, glm::value_ptr(projectionMat));
			glUniform1f(glGetUniformLocation(shaderProgram.getShaderProgram(), "gtime"), gtime/100.0f);
			// Turn on texture mapping on texture unit 0 and select our texture
			// It is redundant to set the same values all the time but texture settings are included here for clarity
			// glUniform1i(uniform_tailShader_texture, usedTextureUnit); <- In init code
			glActiveTexture(GL_TEXTURE0 + usedTextureUnit); // Other textures are GL_TEXTURE0 + i (where i is the texture unit index up to GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS - 1)
			glBindTexture(GL_TEXTURE_2D, TailTexture->getTextureId());
			// For drawing the flag it needs to be bound using (we never bound anything else to replace that state after init())
			glBindVertexArray(tailvao);

			// Count is the number of elements in the array that will form triangles. It is not the number of triangles defined by the array.
			// When VBOs are in use and GL_ELEMENT_ARRAY_BUFFER is bound, the last parameter (pointer to data) is interpreted as an offset within IBO instead of
			// actual program memory address.
			glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(tailIndices.size()), GL_UNSIGNED_SHORT, 0);
//	
			glBindVertexArray(0);

		glm_ModelViewMatrix.pop(); // = glPushMatrix();
		
		//second node layout out
	glm_ModelViewMatrix.pop(); // = glPushMatrix();
	//third node layout out
glm_ModelViewMatrix.pop(); // = glPushMatrix();
//first node layout out
} 

bool Assignment3::handleEvent(const SDL_Event &e)
{
    char key;  
	int drag=0;
	float drag_x=0.0f;
	float drag_y=0.0f;


	// Put any event handling code here.
        // Window-resizing is handled in event loop already.
			// Sample event handling code. Some of this could be useful in your own scene's handleEvent() function
			switch (e.type)
			{
				// Keyboard key pressed down (scancode is the physical key on keyboard, keycode is the symbolic key meaning)
			case SDL_KEYDOWN:
				//std::cout << "Key " << e.key.keysym.scancode << " (" << SDL_GetKeyName(e.key.keysym.sym) << ") pressed" << std::endl;
				break;
				// Keyboard key released
			case SDL_KEYUP:
				key=e.key.keysym.sym;
				//std::cout << "Key " << e.key.keysym.scancode << " (" << SDL_GetKeyName(e.key.keysym.sym) << ") released" << std::endl;
				switch (key)
			{
			case 'q':
						std::cout << "Program is closed" << std::endl;
						exit(0);
						break;
			case 'w':
						std::cout << "Go up" << std::endl;
						position += up  * speed;
						break;
			case 's':
						std::cout << "Go down" << std::endl;
						position -= up *  speed;
						break;
			case 'a':
						std::cout << "Turn left" << std::endl;
						position -= right *  speed;
						break;
			case 'd':
						std::cout << "Turn right" << std::endl;
						position += right *  speed;
						break;
			 case 'm':
				float temp;
				if (stars < 30)
				{
					stars++;
					if (stars > 1)
					{
						std::cout << "Total stars " << stars << std::endl;
					}
					else
					{ 
						std::cout << "Total stars " << stars << std::endl;
					}

					temp = static_cast <float> (rand()) / static_cast <float> (RAND_MAX)-0.5;
					Starposx[stars - 1] = temp*20.0f;
					temp = static_cast <float> (rand()) / static_cast <float> (RAND_MAX)-0.5;
					Starposy[stars - 1] = temp*20.0f;
					temp = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
					Starposz[stars - 1] = -temp*20.0f-6.5f;
					
					temp = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
					Starsize[stars - 1] = temp*0.8;
				}
				else
				{
					std::cout << "Too much stars " << std::endl;
				}
				break;
			
			case 'n':
            if (stars > 0)
            {
	
                stars--;
                if (stars > 1)
                {
					std::cout << "Stars left" << stars << std::endl;
                }
                else
				{
					std::cout << "Stars left" << stars << std::endl;
				}
			}
            else
			{
				std::cout << "No Stars anymore " << std::endl;
			}
            break;
						
			};
				break;

				// Mouse moved
			case SDL_MOUSEMOTION:
				//std::cout << "Mouse motion: " << e.motion.x << ", " << e.motion.y << std::endl;
				
				break;

				 //Mouse button pressed
			case SDL_MOUSEBUTTONDOWN:
				// See https://wiki.libsdl.org/SDL_MouseButtonEvent
				// Note: Mouse wheel has its own event
				{std::cout << "Mouse button down at : " << e.button.x << ", " << e.button.y << " button: ";
				switch(e.button.button)
				{
				case SDL_BUTTON_LEFT:
				//	if( SDL_MOUSEMOTION)
				//	{
				//	SDL_GetMouseState(&xpos , &ypos);
				//	std::cout << "drag_xy  " << xpos<< ", " << ypos<< std::endl;
				//	}
					break;
				case SDL_BUTTON_RIGHT:
					std::cout << "Right";
					break;
				case SDL_BUTTON_MIDDLE:
					std::cout << "Middle";
					break;
				case SDL_BUTTON_X1:
					std::cout << "X1";
					break;
				case SDL_BUTTON_X2:
					std::cout << "X2";
					break;


				default:
					std::cout << "Unknown (" << e.button.button << ")";
				}
				std::cout << " down: " << static_cast<int>(e.button.clicks) << std::endl;
				}
				break;
				// Mouse button released
			case SDL_MOUSEBUTTONUP:
				break;

			case SDL_MOUSEWHEEL:
				if (e.wheel.y < 0)
				{std::cout << "MOUSE : WHEEL DOWN" << std::endl;
				wheelvalue+=1.0f;
				}
				else
				{std::cout << "MOUSE : WHEEL UP" <<std::endl;
				wheelvalue-=1.0f;
				}
			break;
		}
	// Return false if you want to stop the program
	return true;
}

