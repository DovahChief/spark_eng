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
        }

        void batchRender::submit(const renderable2D *renderable) {

        }

        void batchRender::flush() {

        }



    } /* namespace graphics */
} /* namespace spark */
