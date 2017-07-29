#pragma once

#include "texture.h"
#include "shader_manager.hpp"


class Renderer {

public:
	static Renderer *getInstance();

	drawRect(Color *color,
	         float dst_x,
	         float dst_y,
	         float dst_w,
	         float dst_h);

	drawImage(Texture *tex,
	                float src_x,
	                float src_y,
	                float src_w,
	                float src_h,
	                float dst_x,
	                float dst_y,
	                float dst_w,
	                float dst_h);

	~Renderer();

private:
	Renderer();


};
