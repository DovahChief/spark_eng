#ifndef TEXTU_H
#define TEXTU_H

#include <string>
#include <GL/glew.h>

namespace spark { namespace graphics {
class Texture
{
public:
	Texture(const std::string& fileName);
	void Bind(unsigned int unit);
	virtual ~Texture();

private:
	//Texture(const Texture& otro) {}
	//void operator=(const Texture& otro) {}
	GLuint m_texture;
};
}}
#endif
