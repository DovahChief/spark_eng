/*
 * Motor GRafico con OPENGL y GLFW
 * creado por Jose Antonio Limonta
 * email : pepelimonta@gmail.com
 * */

#include "graphic.h"
#include "maths.h"
#include "utils/file_utils.h"

int main(){

    using namespace spark;
    using namespace graphics;
    using namespace math;

   std::string a = lee_arch("/home/jose/Documentos/c++/eclipseWS/spark/src/spark.cpp");
   std::cout<<a<<std::endl;

    window w("ventana_GLFW", 800, 450);
    glClearColor(0.1f, 0.0f, 0.4f, 1.0f);

    while(!w.cerrado()){
        w.clear();

        glBegin(GL_TRIANGLES);
            glVertex2f(-0.5f, -0.5f);
            glVertex2f( 0.0f,  0.5f);
            glVertex2f( 0.5f, -0.5f);
        glEnd();

        w.update();
    }

    return (0);
}
