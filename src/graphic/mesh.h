/*
 * mesh.h
 *
 *  Created on: 20/04/2017
 *      Author: jose
 */

#ifndef MESH_H_
#define MESH_H_

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <vector>
#include "../math/vec2.h"
#include "../math/vec3.h"
#include "objloader.h"

/*
         GL_POINTS, GL_LINE_STRIP, GL_LINE_LOOP, GL_LINES, GL_LINE_STRIP_ADJACENCY,
         GL_LINES_ADJACENCY, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_TRIANGLES,
         GL_TRIANGLE_STRIP_ADJACENCY, GL_TRIANGLES_ADJACENCY, GL_PATCHES
*/
namespace spark { namespace graphics {
enum modo_dibujo {punto         = GL_POINTS,
                  line_strip    = GL_LINE_STRIP,
                  line_loop     = GL_LINE_LOOP,
                  lines         = GL_LINES,
                  line_strip_a  = GL_LINE_STRIP_ADJACENCY,
                  lines_a       = GL_LINES_ADJACENCY,
                  triangle_strip= GL_TRIANGLE_STRIP,
                  triangle_fan  = GL_TRIANGLE_FAN,
                  triangles     = GL_TRIANGLES,
                  triangle_str_a= GL_TRIANGLE_STRIP_ADJACENCY,
                  triangle_a    = GL_TRIANGLES_ADJACENCY,
                  patches       = GL_PATCHES,
                  polygon       = GL_POLYGON,
                  quad          = GL_QUADS};

//data vertex class

using namespace spark;
using namespace math;


class vertex {
public:
    vertex(const vec3 _pos,const vec2 _textCoord){
        pos.x = _pos.x; pos.y = _pos.y; pos.z = _pos.z;
        textCoord.x = _textCoord.x; textCoord.y = _textCoord.y;
    	}
    glm::vec3* getPos(){return (&pos);}
    glm::vec2* getCoord(){return (&textCoord);}
private:
    glm::vec3 pos;
    glm::vec2 textCoord;
};

class mesh{

    public:
		mesh(const std::string& filename);
		mesh(vertex* vertices, unsigned int num_vertices);
		mesh(GLfloat vertices[], unsigned int num_vertices);
        mesh(vertex* vertices, unsigned int num_vertices, unsigned int* indices, unsigned int num_indices);
        virtual ~mesh();
        void draw(modo_dibujo m_dib = triangles);

    private:
        void operator=(const mesh& other);
        void init_mesh(const IndexedModel& model);

        enum {
        	POSITION_VB,
			NUM_BUFFERS,
			INDEX_VB,
			TEXT_COORD_VB };

        GLuint m_vertexArrayObj;
        GLuint m_vertexArrayBuff[NUM_BUFFERS];
        unsigned int m_draw_count;
};

}}
#endif /* MESH_H_ */
