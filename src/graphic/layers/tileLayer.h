//
// Created by jose on 11/05/17.
//

#pragma once

#include "layer.h"
#include "../SpriteRenderer/batchRender.h"

namespace spark {
    namespace graphics{
        class tileLayer : public layer {
        public:
            tileLayer(shader* _shad);
            ~tileLayer();
        };

    }/* namespace graphics */
}/* namespace spark */
