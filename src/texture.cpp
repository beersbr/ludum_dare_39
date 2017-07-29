#include "texture.h"


Texture::Texture()
{
	glGenTextures(1, &texture_id);
}


Texture::~Texture() 
{

}


void
Texture::loadTexture(std::string texture_path, std::string texture_tag)
{
	SDL_Surface *img = IMG_Load(texture_path.c_str());

	if ( img ) {
		Texture *tex = new Texture();

		tex->load(0, 4,
		          img->w,
		          img->h,
		          0,
		          GL_RGBA,
		          GL_UNSIGNED_BYTE,
		          img->pixels);

		SDL_FreeSurface(img);
	}
}


void
load(GLint level,
     GLint internalFormat,
     GLsizei width,
     GLsizei height,
     GLint border,
     GLenum format,
     GLenum type,
     const GLvoid * data)
{

	glBindTexture(GL_TEXTURE_2D, texture_id);

	glTexImage2D(GL_TEXTURE_2D,
	             level,
	             internalFormat,
	             width,
	             height,
	             border,
	             format,
	             type,
	             data);

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

	glBindTexture(GL_TEXTURE_2D, 0);

}