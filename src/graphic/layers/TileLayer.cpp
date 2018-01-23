//
// Created by jose on 11/05/17.
//

#include "TileLayer.h"



namespace spark {
    namespace graphics{
        TileLayer::TileLayer(Shader *_shad)
        : Layer(new batchRender() , _shad ,
        math::mat4::orthographic(IZQ_W, DER_W, ABA_W, ARR_W, NEAR_W, FAR_W))
        {

        }

        TileLayer::~TileLayer() {}
    }/* namespace graphics */
}/* namespace spark */