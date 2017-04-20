#include "graphic.h"
#include "maths.h"

int main(){

    using namespace spark;
    using namespace graphics;
    using namespace math;

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
