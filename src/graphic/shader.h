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

	class shader_2{
	private:
		GLuint m_shader_id;
		const char* m_ruta_vertex;
		const char* m_ruta_fragment;

	public:
		shader_2(const char* _ruta_vertex, const char* _ruta_fragment);
		~shader_2();

		void enable() const;
		void disable() const;

	private:
		GLuint load();
	};

}}


#endif /* GRAPHIC_SHADER_H_ */
