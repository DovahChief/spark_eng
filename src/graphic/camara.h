/*
 * camara.h
 *
 *  Created on: 21/04/2017
 *      Author: jose
 */

#ifndef GRAPHIC_CAMARA_H_
#define GRAPHIC_CAMARA_H_

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>


namespace spark { namespace graphics {
class camara{
public:
    camara(const glm::vec3& pos, float fov, float aspect, float z_cerca, float z_lejos){
        this->m_posicion = pos;
        this->m_adelante = glm::vec3(0.0f,0.0f,1.0f);
        this->m_arriba = glm::vec3(0.0f,1.0f,0.0f);
        this->m_perspect = glm::perspective(fov, aspect, z_cerca, z_lejos);
    }

    inline mat get_view_projection() const {
        return (m_perspect * glm::lookAt(m_posicion, m_posicion + m_adelante, m_arriba));
    }

protected:
private:
    glm::mat4 m_perspect;
    glm::vec3 m_posicion;
    glm::vec3 m_adelante;
    glm::vec3 m_arriba;
};

} }





#endif /* GRAPHIC_CAMARA_H_ */
