/*
 * transform.h
 *
 *  Created on: 20/04/2017
 *      Author: jose
 */

#ifndef GRAPHIC_TRANSFORM_H_
#define GRAPHIC_TRANSFORM_H_


#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

using vec = const glm::vec3&;
using _vec = glm::vec3;
using mat = glm::mat4;

namespace spark { namespace graphics {
class transform
{
    public:
        transform(vec pos = glm::vec3(), vec rot = glm::vec3(), vec scale = glm::vec3(1.0f, 1.0f, 1.0f)) :
            m_pos(pos),
            m_rot(rot),
            m_scale(scale){}

    //getters
    inline vec get_pos(){return (m_pos);}
    inline vec get_rot(){return (m_rot);}
    inline vec get_scale(){return (m_scale);}

    //setters
    inline void set_pos(vec pos){ m_pos = pos;}
    inline void set_rot(vec rot){ m_rot = rot;}
    inline void set_scale(vec s){ m_scale = s;}

    //transformacion matricial
    inline mat get_model() const {
        mat mat_pos = glm::translate(m_pos);
        mat mat_sca = glm::scale(m_scale);

        mat mat_rot_x = glm::rotate(m_rot.x, glm::vec3(1,0,0));
        mat mat_rot_y = glm::rotate(m_rot.y, glm::vec3(0,1,0));
        mat mat_rot_z = glm::rotate(m_rot.z, glm::vec3(0,0,1));

        mat rot_mat = mat_rot_z * mat_rot_y * mat_rot_x;

        return (mat_pos * rot_mat * mat_sca);
    }

    private:
        _vec m_pos, m_rot, m_scale;

};

}}
#endif /* GRAPHIC_TRANSFORM_H_ */
