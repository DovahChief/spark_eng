//
// Created by jose on 6/05/17.
//

#pragma once

#include "renderer2D.h"
#include "../buffers/indexBuffer.h"
#include <GL/glew.h>
#include <cstddef>

namespace spark {
    namespace graphics {

        constexpr auto RENDERER_MAX_SPRITES = 10000;
        constexpr auto RENDERER_VERTEX_SIZE = sizeof(VertexData);
        constexpr auto RENDERER_SPRITE_SIZE = RENDERER_VERTEX_SIZE * 4;
        constexpr auto RENDERER_BUFFER_SIZE = RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES;
        constexpr auto RENDERER_INDICE_SIZE = RENDERER_MAX_SPRITES * 6;

        constexpr auto SHADER_VERTEX_INDEX = 0;
        constexpr auto SHADER_COLOR_INDEX = 1;

        class batchRender : public renderer2D{

        private:
            GLuint m_VAO; //vertex array object
            indexBuffer* m_IBO;
            GLuint m_VBO;
            GLsizei m_IndexCount;
            VertexData* m_buffer;

        public:
            batchRender();
            virtual ~batchRender();

            void begin() override ;
            virtual void submit(const renderable2D* renderable) override;
            void end() override ;
            virtual void flush() override;

        private:
            void init();

        };

    } /* namespace graphics */
} /* namespace spark */


