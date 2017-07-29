
#include "shader_manager.hpp"

shader_manager_t *shader_manager_t::singleton_instance = NULL;

shader_manager_t *shader_manager_t::instance() {
	if ( ! shader_manager_t::singleton_instance ) {
		shader_manager_t::singleton_instance = new shader_manager_t();
	}
	return shader_manager_t::singleton_instance;
}


shader_manager_t::shader_manager_t() { 

}


GLuint shader_manager_t::create_program(const std::string& tag,
                                        const std::string& vertex_filename,
                                        const std::string& fragment_filename) {

	std::string vertex_shader_contents = read_shader(vertex_filename.c_str());
	std::string fragment_shader_contents = read_shader(fragment_filename.c_str());

	GLuint vertex_shader = create_shader(GL_VERTEX_SHADER,
	                                     vertex_shader_contents,
	                                     "vertex_shader");

	GLuint fragment_shader = create_shader(GL_FRAGMENT_SHADER,
	                                       fragment_shader_contents,
	                                       "fragment_shader");

	GLuint program = glCreateProgram();
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);

	glLinkProgram(program);

	int result = 0;
	glGetProgramiv(program, GL_LINK_STATUS, &result);

	if ( result == GL_FALSE )
	{

		#ifdef SLOW
		int log_length = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &log_length);
		std::vector<char> log(log_length);
		glGetProgramInfoLog(program, log_length, NULL, &log[0]);
		std::cout << "[ERROR] shader link error in shader named: " <<  &log[0] << std::endl;
		#endif 

		return 0;
	}

	shader_t shader = { program };

	shaders[tag] = shader;

	#ifdef SLOW
	std::cout << "successfully compiled shader program with id:  " << shaders[tag].id << std::endl;
	#endif

	return program;
}


std::string shader_manager_t::read_shader(const char *filename) {

	std::string file_contents;
	std::ifstream file(filename, std::ios::in);

	if ( !file.good() )
	{
		return "ERROR";
	}

	file.seekg(0, std::ios::end);
	file_contents.resize(file.tellg());
	file.seekg(0, std::ios::beg);
	file.read(&file_contents[0], file_contents.size());
	file.close();

	return file_contents;
}


GLuint shader_manager_t::create_shader(GLenum shader_type, std::string source, const std::string& shader_name) {
	GLuint shader = glCreateShader(shader_type);
	const char *program_code = source.c_str();
	const int program_size = source.size();

	glShaderSource(shader, 1, &program_code, &program_size);
	glCompileShader(shader);

	int result = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);

	if ( result == GL_FALSE )
	{

		#ifdef SLOW
		int log_length = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &log_length);
		std::vector<char> log(log_length);
		glGetShaderInfoLog(shader, log_length, NULL, &log[0]);
		std::cout << "[ERROR] shader compilation error in shader named: " <<  shader_name  << "\n" << &log[0] << std::endl;
		#endif

		return 0;
	}

	#ifdef SLOW
	std::cout << "successfully compiled shader named:  " << source << std::endl;
	#endif

	return shader;
}


const GLuint shader_manager_t::get_shader(const std::string& tag) {
	// TODO(Brett):This is an erro waiting to happen... at least I will get a program failure.
	return shaders[tag].id;
}
