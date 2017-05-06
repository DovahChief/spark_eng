cmake_minimum_required(VERSION 3.7)
project(spark)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/graphic/buffers/buffer.cpp
        src/graphic/buffers/buffer.h
        src/graphic/buffers/indexBuffer.cpp
        src/graphic/buffers/indexBuffer.h
        src/graphic/buffers/vertexArray.cpp
        src/graphic/buffers/vertexArray.h
        src/graphic/graphic.h
        src/graphic/renderable2D.h
        src/graphic/renderer2D.h
        src/graphic/shader.cpp
        src/graphic/shader.h
        src/graphic/simple2Drenderer.cpp
        src/graphic/simple2Drenderer.h
        src/graphic/window.cpp
        src/graphic/window.h
        src/math/mat4.cpp
        src/math/mat4.h
        src/math/maths.h
        src/math/vec2.cpp
        src/math/vec2.h
        src/math/vec3.cpp
        src/math/vec3.h
        src/math/vec4.cpp
        src/math/vec4.h
        src/shader/basicShader.frag
        src/shader/basicShader.vert
        src/utils/file_utils.h
        src/includes.h
        src/spark.cpp)



add_executable(spark ${SOURCE_FILES})
target_link_libraries( spark GL GLEW glfw pthread)