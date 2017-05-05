/*
 * indexBuffer.cpp
 *
 *  Created on: 04/05/2017
 *      Author: jose
 */

#include "indexBuffer.h"

namespace spark { namespace graphics {

	indexBuffer::indexBuffer(GLushort* _data, GLsizei _count)
		: m_count(_count)
		{
			glGenBuffers(1, &m_Buffer_id);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Buffer_id);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, _count* sizeof(GLshort), _data, GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

	void indexBuffer::bind()  const{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Buffer_id);
		}
	void indexBuffer::unbind()const{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

} /* namespace graphics */
} /* namespace spark */
