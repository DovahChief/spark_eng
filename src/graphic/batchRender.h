//
// Created by jose on 6/05/17.
//

#ifndef SPARK_BATCHRENDER_H
#define SPARK_BATCHRENDER_H

#include "renderer2D.h"
#include "buffers/vertexArray.h"
#include "buffers/indexBuffer.h"


namespace spark {
    namespace graphics {

        #define RENDERER_MAX_SPRITES    10000
        #define RENDERER_VERTEX_SIZE    sizeof(VertexData)
        #define RENDERER_SPRITE_SIZE    RENDERER_VERTEX_SIZE * 4
        #define RENDERER_BUFFER_SIZE    RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
        #define RENDERER_INDICE_SIZE    RENDERER_MAX_SPRITES * 6

        class batchRender : public renderer2D{

        private:
            vertexArray m_VAO; //vertex array object
            indexBuffer* m_IBO;
            GLuint m_VBO;
            GLsizei m_IndexCount;
        public:
            batchRender();
            ~batchRender();

            virtual void submit(const renderable2D* renderable) override;
            virtual void flush() override;

        private:
            void init();

        };

    } /* namespace graphics */
} /* namespace spark */

#endif //SPARK_BATCHRENDER_H
