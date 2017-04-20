/*
 * mesh.cpp
 *
 *  Created on: 20/04/2017
 *      Author: jose
 */

#include "mesh.h"


//ctor
namespace spark { namespace graphics {
mesh::mesh(vertex* vertices, unsigned int num_vertices){
    m_draw_count = num_vertices;
    glGenVertexArrays(1, &m_vertexArrayObj);
    glBindVertexArray(m_vertexArrayObj);

    std::vector<vec3> posiciones;
    std::vector<vec2> coord_text;

    posiciones.reserve(num_vertices);
    coord_text.reserve(num_vertices);

    for(unsigned int i =0 ; i <num_vertices; i++){
        posiciones.push_back(vertices[i].pos);
        coord_text.push_back(vertices[i].textCoord);
    }

    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuff);
    glBindBuffer(GL_ARRAY_BUFFER ,m_vertexArrayBuff[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, num_vertices*sizeof(posiciones[0]), &posiciones[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    //glBindVertexArray(0);

    glBindBuffer(GL_ARRAY_BUFFER ,m_vertexArrayBuff[TEXT_COORD_VB]);
    glBufferData(GL_ARRAY_BUFFER, num_vertices*sizeof(coord_text[0]), &coord_text[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glBindVertexArray(0);
}
//dtor
mesh::~mesh(){ glDeleteVertexArrays(1, &m_vertexArrayObj); }

//dibujar
void mesh::draw(modo_dibujo m_dib){
    glBindVertexArray(m_vertexArrayObj);
    glDrawArrays(m_dib, 0, m_draw_count); //md modo de dibujo
    glBindVertexArray(0);
}

/*
         GL_POINTS, GL_LINE_STRIP, GL_LINE_LOOP, GL_LINES, GL_LINE_STRIP_ADJACENCY,
         GL_LINES_ADJACENCY, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_TRIANGLES,
         GL_TRIANGLE_STRIP_ADJACENCY, GL_TRIANGLES_ADJACENCY, GL_PATCHES, GL_POLYGON
*/

}}


