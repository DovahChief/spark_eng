//
// Created by jose on 6/05/17.
//

#include "batchRender.h"


namespace spark {
    namespace graphics {

        batchRender::batchRender() {
            init();
        }

        batchRender::~batchRender() {
            delete m_IBO;
            glDeleteBuffers(1, &m_VBO);
        }

        void batchRender::begin() {
            glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
            m_buffer = (VertexData*) glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
        }

        void batchRender::submit(const renderable2D *renderable) {

            const math::vec3& position = renderable->get_position();
            const math::vec4& color = renderable->get_color();
            const math::vec2& size = renderable->get_size();

            int r  = color.x * 255.0f;
            int g  = color.y * 255.0f;
            int b  = color.z * 255.0f;
            int a  = color.w * 255.0f;

            unsigned int c = a << 24 | b <<16 | g << 8 | r;

            m_buffer->vertex = m_transform_stack.back() *  position;
            m_buffer->color = c;
            m_buffer++;

            m_buffer->vertex = m_transform_stack.back() * math::vec3(position.x, position.y +size.y, position.z );
            m_buffer->color = c;
            m_buffer++;

            m_buffer->vertex = m_transform_stack.back() * math::vec3(position.x + size.x, position.y +size.y, position.z );
            m_buffer->color = c;
            m_buffer++;

            m_buffer->vertex = m_transform_stack.back() * math::vec3(position.x + size.x, position.y, position.z );
            m_buffer->color = c;
            m_buffer++;

            m_IndexCount += 6;
            if (m_IndexCount >= 60000){ //eqivalente a 10000 sprites
                this->end();
                this->flush();
                this->begin();
            }
        }

        void batchRender::end() {
            glUnmapBuffer(GL_ARRAY_BUFFER);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }

        void batchRender::flush() {
            glBindVertexArray(m_VAO);
            m_IBO->bind();

            glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_SHORT, NULL);

            m_IBO->unbind();
            glBindVertexArray(0);

            m_IndexCount = 0;
        }

        void batchRender::init() {

            glGenVertexArrays(1, &m_VAO);
            glGenBuffers(1, &m_VBO);

            glBindVertexArray(m_VAO);

            glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
            glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);

            glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
            glEnableVertexAttribArray(SHADER_COLOR_INDEX);

            glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE,
                                  RENDERER_VERTEX_SIZE, (const GLvoid*) 0);

            glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_UNSIGNED_BYTE, GL_TRUE,
                                  RENDERER_VERTEX_SIZE, (const GLvoid*) offsetof(VertexData, color)  );

            glBindBuffer(GL_ARRAY_BUFFER, 0);

            GLushort* indices = new GLushort[RENDERER_INDICE_SIZE] { };
            int offset { 0 };

            for (GLushort i = 0; i < RENDERER_INDICE_SIZE ; i+=6) {
                indices[i]      = offset + 0;
                indices[i + 1]  = offset + 1;
                indices[i + 2]  = offset + 2;
                indices[i + 3]  = offset + 2;
                indices[i + 4]  = offset + 3;
                indices[i + 5]  = offset + 0;

                offset += 4;
            }

            m_IBO = new indexBuffer { indices, RENDERER_INDICE_SIZE };
            glBindVertexArray(0);
        }



    } /* namespace graphics */
} /* namespace spark */
