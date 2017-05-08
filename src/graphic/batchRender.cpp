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

            m_buffer->vertex = position;
            m_buffer->color = color;
            m_buffer++;

            m_buffer->vertex = math::vec3(position.x, position.y +size.y, position.z );
            m_buffer->color = color;
            m_buffer++;

            m_buffer->vertex = math::vec3(position.x + size.x, position.y +size.y, position.z );
            m_buffer->color = color;
            m_buffer++;

            m_buffer->vertex = math::vec3(position.x + size.x, position.y, position.z );
            m_buffer->color = renderable->get_color();
            m_buffer++;

            m_IndexCount += 6;
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

            glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_FLOAT, GL_FALSE,
                                  RENDERER_VERTEX_SIZE, (const GLvoid*)(3* sizeof(GLfloat)));

            glBindBuffer(GL_ARRAY_BUFFER, 0);

            GLushort indices[RENDERER_INDICE_SIZE];
            int offset = 0;

            for (int i = 0; i < RENDERER_INDICE_SIZE ; i+=6) {
                indices[i]      = offset + 0;
                indices[i + 1]  = offset + 1;
                indices[i + 2]  = offset + 2;
                indices[i + 3]  = offset + 2;
                indices[i + 4]  = offset + 3;
                indices[i + 5]  = offset + 0;

                offset += 4;
            }

            m_IBO = new indexBuffer(indices, RENDERER_INDICE_SIZE);
            glBindVertexArray(0);
        }



    } /* namespace graphics */
} /* namespace spark */
