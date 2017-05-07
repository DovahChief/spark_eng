#pragma once
#include <GL/glew.h>
#include <vector>
#include "buffer.h"


namespace spark { namespace graphics{

	class vertexArray{

	private:
		GLuint m_arrayID;
		std::vector<buffer*> m_Buffers;

	public:
		vertexArray();
		~vertexArray();

		void addBuffer(buffer* _buffer, GLuint _index);
		void bind() const;
		void unbind() const;

	};


} /* namespace graphics */
} /* namespace spark */

