//
// Created by jose on 6/05/17.
//

#ifndef SPARK_BATCHRENDER_H
#define SPARK_BATCHRENDER_H

#include "renderer2D.h"
#include "buffers/vertexArray.h"

namespace spark { namespace graphics {

    class batchRender : public renderer2D{

    private:
        vertexArray m_VAO; //vertex array object
        GLuint m_VBO;
        GLuint m_IBO;
    public:
        virtual void submit(const renderable2D* renderable) override;
        virtual void flush() override;


    };

    } /* namespace graphics */
} /* namespace spark */

#endif //SPARK_BATCHRENDER_H
