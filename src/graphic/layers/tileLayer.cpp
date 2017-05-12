//
// Created by jose on 11/05/17.
//

#include "tileLayer.h"



namespace spark {
    namespace graphics{
        tileLayer::tileLayer(shader *_shad)
        : layer(new batchRender() , _shad , math::mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f))
        {

        }

        tileLayer::~tileLayer() {}
    }/* namespace graphics */
}/* namespace spark */