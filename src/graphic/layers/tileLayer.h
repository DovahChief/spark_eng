//
// Created by jose on 11/05/17.
//

#pragma once

#include "layer.h"
#include "../SpriteRenderer/batchRender.h"

namespace spark {
    namespace graphics{

        constexpr float IZQ_W = -16.0f;
        constexpr float DER_W =  16.0f;
        constexpr float ARR_W =  9.0f;
        constexpr float ABA_W = -9.0f;
        constexpr float NEAR_W= -1.0f;
        constexpr float FAR_W =  1.0f;

        class tileLayer : public layer {
        public:
            tileLayer(shader* _shad);
            ~tileLayer();
        };

    }/* namespace graphics */
}/* namespace spark */
