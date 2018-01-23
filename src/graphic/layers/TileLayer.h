//
// Created by jose on 11/05/17.
//

#pragma once

#include "Layer.h"
#include "../SpriteRenderer/batchRender.h"

namespace spark {
    namespace graphics{

        constexpr float IZQ_W = -16.0f;
        constexpr float DER_W =  16.0f;
        constexpr float ARR_W =  9.0f;
        constexpr float ABA_W = -9.0f;
        constexpr float NEAR_W= -1.0f;
        constexpr float FAR_W =  1.0f;

        class TileLayer : public Layer {
        public:
            TileLayer(Shader* _shad);
            ~TileLayer();
        };

    }/* namespace graphics */
}/* namespace spark */
