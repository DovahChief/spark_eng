//
// Created by jose on 6/05/17.
//

#pragma once

#include "renderer2D.h"
#include "buffers/indexBuffer.h"
#include <GL/glew.h>

namespace spark {
    namespace graphics {

        #define RENDERER_MAX_SPRITES    10000
        #define RENDERER_VERTEX_SIZE    sizeof(VertexData)
        #define RENDERER_SPRITE_SIZE    RENDERER_VERTEX_SIZE * 4
        #define RENDERER_BUFFER_SIZE    RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
        #define RENDERER_INDICE_SIZE    RENDERER_MAX_SPRITES * 6

        #define SHADER_VERTEX_INDEX 0
        #define SHADER_COLOR_INDEX 1

        class batchRender : public renderer2D{

        private:
            GLuint m_VAO; //vertex array object
            indexBuffer* m_IBO;
            GLuint m_VBO;
            GLsizei m_IndexCount;
            VertexData* m_buffer;
        public:
            batchRender();
            ~batchRender();

            void begin();
            virtual void submit(const renderable2D* renderable) override;
            void end();
            virtual void flush() override;

        private:
            void init();

        };

    } /* namespace graphics */
} /* namespace spark */


