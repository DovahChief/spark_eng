/*
 * buffer.h
 *
 *  Created on: 23/04/2017
 *      Author: jose
 */

#ifndef GRAPHIC_BUFFERS_BUFFER_H_
#define GRAPHIC_BUFFERS_BUFFER_H_

#include <GL/glew.h>

namespace spark { namespace graphics {

class buffer {
public:
	buffer();
	virtual ~buffer();
};
} /* namespace graphics */
} /* namespace spark */

#endif /* GRAPHIC_BUFFERS_BUFFER_H_ */
