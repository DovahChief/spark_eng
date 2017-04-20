/*
 * shader.h
 *
 *  Created on: 20/04/2017
 *      Author: jose
 */

#ifndef GRAPHIC_SHADER_H_
#define GRAPHIC_SHADER_H_

#include <GL/glew.h>
#include "../utils/file_utils.h"

namespace spark{ namespace graphics{

	class shader{
	private:
		GLuint m_shader_id;
		const char* m_ruta_vertex;
		const char* m_ruta_fragment;

	public:
		shader(const char* ruta_vertex, const char* ruta_fragment);
		~shader();

		void enable() const;
		void disable() const;

	private:
		GLuint load();
	};

}}


#endif /* GRAPHIC_SHADER_H_ */