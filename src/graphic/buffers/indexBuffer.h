/*
 * indexBuffer.h
 *
 *  Created on: 04/05/2017
 *      Author: jose
 */

#pragma once

#include <GL/glew.h>

namespace spark {
	namespace graphics {

		class indexBuffer {
		private:
			GLuint m_Buffer_id;
			GLuint m_count;

		public:
			indexBuffer(GLushort* _data, GLsizei _count);
			~indexBuffer();

			void bind() const;
			void unbind() const;

			inline GLuint get_cont() const {return (m_count);}


		};
	} /* namespace graphics */
} /* namespace spark */

