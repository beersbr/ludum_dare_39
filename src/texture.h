#pragma once

#ifdef _WIN32
#include <windows.h>
#define GL3_PROTOTYPES 1
#include <GL/glew.h>
#endif

#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>

#include <map>

class Texture {
public:
	static void loadTexture(std::string texture_path, std::string texture_tag);
	static Texture getTexture(std::string texture_tag);
	

	Texture();
	~Texture();

	void load(GLint level,
	          GLint internalFormat,
	          GLsizei width,
	          GLsizei height,
	          GLint border,
	          GLenum format,
	          GLenum type,
	          const GLvoid * data);

private:

	GLuint texture_id;

	static std::map<std::string, Texture *> textures;
};