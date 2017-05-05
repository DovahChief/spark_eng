/*
 * indexBuffer.h
 *
 *  Created on: 04/05/2017
 *      Author: jose
 */

#ifndef GRAPHIC_BUFFERS_INDEXBUFFER_H_
#define GRAPHIC_BUFFERS_INDEXBUFFER_H_

#include <GL/glew.h>

namespace spark { namespace graphics {

	class indexBuffer {
	private:
		GLuint m_Buffer_id;
		GLuint m_count;

	public:
		indexBuffer(GLushort* _data, GLsizei _count);

		void bind() const;
		void unbind() const;

		inline GLuint get_cont() const {return (m_count);}


	};
} /* namespace graphics */
} /* namespace spark */

#endif /* GRAPHIC_BUFFERS_INDEXBUFFER_H_ */
