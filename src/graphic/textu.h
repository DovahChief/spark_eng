#ifndef TEXTU_H
#define TEXTU_H

#include <string>
#include <GL/glew.h>

namespace spark { namespace graphics {
	class Texture
	{
	public:
		Texture(const std::string& _fileName);
		void Bind(unsigned int _unit = 0);
		virtual ~Texture();

	private:
		//Texture(const Texture& otro) {}
		//void operator=(const Texture& otro) {}
		GLuint m_texture;
};
}}
#endif
