/*
 * mesh.cpp
 *
 *  Created on: 20/04/2017
 *      Author: jose
 */

#include "mesh.h"


//ctor
namespace spark { namespace graphics {


mesh::mesh(const std::string& filename){
	IndexedModel model = OBJModel(filename).ToIndexedModel();
	init_mesh(model);
}

mesh::mesh(vertex* vertices, unsigned int num_vertices,
		unsigned int* indices, unsigned int num_indices){
		IndexedModel model;
		for(unsigned int i =0 ; i <num_vertices; i++){
		        model.positions.push_back(*vertices[i].getPos());
		        model.texCoords.push_back(*vertices[i].getCoord());
		    }

		for(unsigned int i = 0; i < num_indices; i++)
			model.indices.push_back(indices[i]);

		init_mesh(model);

}

mesh::mesh(vertex* vertices, unsigned int num_vertices){
	IndexedModel model;
	for(unsigned int i =0 ; i <num_vertices; i++){
		model.positions.push_back(*vertices[i].getPos());
		model.texCoords.push_back(*vertices[i].getCoord());
		model.indices.push_back(i);
	}
	init_mesh(model);
}
//dtor
mesh::~mesh(){ glDeleteVertexArrays(1, &m_vertexArrayObj); }

//dibujar
void mesh::draw(modo_dibujo m_dib){
    glBindVertexArray(m_vertexArrayObj);
    glDrawElements(m_dib, m_draw_count, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

/*
         GL_POINTS, GL_LINE_STRIP, GL_LINE_LOOP, GL_LINES, GL_LINE_STRIP_ADJACENCY,
         GL_LINES_ADJACENCY, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_TRIANGLES,
         GL_TRIANGLE_STRIP_ADJACENCY, GL_TRIANGLES_ADJACENCY, GL_PATCHES, GL_POLYGON
*/
void mesh::init_mesh(const IndexedModel& model){

	m_draw_count = model.indices.size();

	glGenVertexArrays(1, &m_vertexArrayObj);
	glBindVertexArray(m_vertexArrayObj);

	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuff);
	glBindBuffer(GL_ARRAY_BUFFER ,m_vertexArrayBuff[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, model.positions.size()*sizeof(model.positions[0]), &model.positions[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	//glBindVertexArray(0);

	glBindBuffer(GL_ARRAY_BUFFER ,m_vertexArrayBuff[TEXT_COORD_VB]);
	glBufferData(GL_ARRAY_BUFFER, model.positions.size()*sizeof(model.texCoords[0]), &model.texCoords[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER ,m_vertexArrayBuff[INDEX_VB]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.indices.size()*sizeof(model.indices[0]), &model.indices[0], GL_STATIC_DRAW);


	glBindVertexArray(0);

}
}}


