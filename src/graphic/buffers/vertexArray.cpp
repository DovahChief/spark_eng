/*
 * vertexArray.cpp
 *
 *  Created on: 05/05/2017
 *      Author: jose
 */

#include "vertexArray.h"

namespace spark {
	namespace graphics{

		vertexArray::vertexArray(){
			glGenVertexArrays(1, &m_arrayID);
		}

		vertexArray::~vertexArray(){
			for(unsigned int i = 0; i < m_Buffers.size(); i++)
				delete m_Buffers[i];

			glDeleteVertexArrays(1, &m_arrayID);
		}

		void vertexArray::addBuffer(buffer* _buffer,GLuint _index){
			bind();
			_buffer->bind();

			glEnableVertexAttribArray(_index);
			glVertexAttribPointer(_index, _buffer->get_CompCount(), GL_FLOAT, GL_FALSE, 0, 0);

			_buffer->unbind();
			unbind();

		}

		void vertexArray::bind() const{
			glBindVertexArray(m_arrayID);
		}

		void vertexArray::unbind() const{
				glBindVertexArray(0);
			}

	} /* namespace graphics */
} /* namespace spark */
