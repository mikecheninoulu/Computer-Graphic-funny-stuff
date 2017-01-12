/**
 * \brief Example Scene 4 interface
 */
#ifndef EXAMPLE_SCENE_4_H_
#define EXAMPLE_SCENE_4_H_

#include <vector>                       // Standard vector template
#include <GL/glew.h>                    // OpenGL extension wrangler library
#include <SDL.h>                        // libSDL functionality
#include <glm/glm.hpp>                  // Matrix library
#include <glm/gtc/matrix_transform.hpp> // Needed for glm::perspective() and friends.
#include <glm/gtc/type_ptr.hpp>         // Needed for glm::value_ptr(x). You can use &x[0] instead of that.
#include "scene.h"                      // Abstract scene class
#include "shaderprogram.h"              // For shader management
#include "texture.h"

/**
 * \brief Draws a vertex-colored tetrahedron
 */
class Assignment3 : public Scene
{
	struct Vertex
	{
		glm::vec3 position;
		glm::vec3 color;
		glm::vec3 normal;

		Vertex(const glm::vec3 &position_ = glm::vec3(0.0f, 0.0f, 0.0f),
		       const glm::vec3 &color_ = glm::vec3(0.0f, 0.0f, 0.0f),
			   const glm::vec3 &normal_ = glm::vec3(0.0f, 0.0f, 0.0f)) :
			   position(position_),
			   color(color_),
			   normal(normal_)
		{
		}
	};

		struct Vertexsub
	{
		GLfloat position[3];
		GLfloat uv[2]; // Texture coordinates

		Vertexsub(GLfloat x = 0.0, GLfloat y = 0.0, GLfloat z = 0.0, GLfloat u = 0.0f, GLfloat v = 0.0f)
		{
			position[0] = x;
			position[1] = y;
			position[2] = z;
			uv[0] = u;
			uv[1] = v;
		}
	};

	struct Vertexstar
	{
		GLfloat position[3];
		GLfloat color[3];

		Vertexstar(GLfloat x = 0.0, GLfloat y = 0.0, GLfloat z = 0.0, GLfloat r = 0.0f, GLfloat g = 0.0f, GLfloat b = 0.0f)
		{
			position[0] = x;
			position[1] = y;
			position[2] = z;
			color[0] = r;
			color[1] = g;
			color[2] = b;
		}
	};


	ShaderProgram shaderProgram;
	glm::mat4 mvpMat;

	glm::mat4 projectionMat;
	glm::mat4 viewMat;
	glm::mat4 modelMat;

	glm::vec4 objectColor;

	// Vertex Array Object, Vertex Buffer Object and Index Buffer Object handlers
	GLuint vao, vbo, ibo;
	GLuint starvao, starvbo, staribo;
	GLuint tailvao, tailvbo, tailibo;
	GLuint headvao, headvbo, headibo;
	GLuint handvao, handvbo, handibo;

	float gtime;
	float rotation; // Current rotation position
	float handrotation; // Current rotation position

	std::vector<Vertex> sphere;
	std::vector<GLushort> sphereIndices;
	std::vector<Vertexsub> tail; // Source data for our model
	std::vector<GLushort> tailIndices; // Index values for tail
	std::vector<Vertexstar> star;
	std::vector<Vertexsub> head; // Source data for our model
	std::vector<GLushort> headIndices; // Index values for cube

	std::vector<Vertexsub> hand; // Source data for our model
	std::vector<GLushort> handIndices; // Index values for cube
	
	Texture *HeadTexture;
	Texture *TailTexture;
	Texture *HandTexture;
	GLuint usedTextureUnit;

	void createTail();
	void createStar();
	void createHead();
	void createHand();
	void createIcosahedron(std::vector<Vertex> &tetrahedron, std::vector<GLushort> &tetrahedronIndices) const;
	void createSphere(std::vector<Vertex> &sphere, std::vector<GLushort> &sphereIndices, int numTesselations) const;

	void updateShading(std::vector<Vertex> &mesh, const glm::mat4 &modelMat, const glm::vec4 lightPos) const;
public:
	Assignment3();
	virtual ~Assignment3();

	// Initialize scene
	virtual bool init();

	// Called on window resize
	virtual void resize(GLsizei width, GLsizei height);

	// Update scene
	virtual void update(float timestep);

	// Render view
	virtual void render();

	// Handle SDL event
	virtual bool handleEvent(const SDL_Event &e);
};

#endif
