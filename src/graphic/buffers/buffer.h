/*
 * buffer.h
 *
 *  Created on: 23/04/2017
 *      Author: jose
 */

#pragma once

#include <GL/glew.h>

namespace spark {
	namespace graphics {

		class buffer {
		private:
			GLuint m_buffer_ID;
			GLuint m_Component_count;
		public:
			buffer(GLfloat* _data, GLsizei _count, GLuint _comp_count);

			virtual ~buffer();

			void bind() const;
			void unbind() const;
			inline GLuint get_CompCount() const {return (m_Component_count);}


		};

	} /* namespace graphics */
} /* namespace spark */


