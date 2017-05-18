//
// Created by jose on 11/05/17.
//

#include "tileLayer.h"



namespace spark {
    namespace graphics{
        tileLayer::tileLayer(shader *_shad)
        : layer(new batchRender() , _shad ,
        math::mat4::orthographic(IZQ_W, DER_W, ABA_W, ARR_W, NEAR_W, FAR_W))
        {

        }

        tileLayer::~tileLayer() {}
    }/* namespace graphics */
}/* namespace spark */