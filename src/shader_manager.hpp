#pragma once

#ifdef _WIN32
#include <windows.h>
#define GL3_PROTOTYPES 1
#include <GL/glew.h>
#endif

#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#include <SDL2/sdl.h>

#define shader_manager shader_manager_t::instance()

struct shader_t {
	GLuint id;
};

class shader_manager_t {
public:

	GLuint create_program(const std::string& tag,
	                      const std::string& vertex_filename,
	                      const std::string& fragment_filename);

	static shader_manager_t *instance();

	const GLuint get_shader(const std::string& tag);

private:
	static shader_manager_t *singleton_instance;

	std::map<std::string, shader_t> shaders;
	

	shader_manager_t();
	std::string read_shader(const char *filename);
	GLuint create_shader(GLenum type, std::string source, const std::string& shader_name);
};
