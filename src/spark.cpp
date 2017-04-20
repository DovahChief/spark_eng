/*
 * Motor GRafico con OPENGL y GLFW
 * creado por Jose Antonio Limonta
 * email : pepelimonta@gmail.com
 * */

#include "graphic.h"
#include "maths.h"



int main(){

    using namespace spark;
    using namespace graphics;
    using namespace math;

    vertex vertices[] = { vertex(vec3(-0.5, -0.5, 0), vec2(0,0)),
                              vertex(vec3(0, 0.5, 0), vec2(0.5,1.0)),
                              vertex(vec3(0.5, -0.5, 0),vec2(1.0,0.0)),
							  vertex(vec3(0.5, -0.5, 0),vec2(1.0,0.0))};

    window w("ventana_GLFW", 800, 450);
    glClearColor(0.1f, 0.0f, 0.4f, 1.0f);
    mesh m_mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));

    Shader2 shd("/home/jose/Documentos/c++/eclipseWS/spark/src/shader/basicShader");
    Texture tx("/home/jose/Documentos/c++/eclipseWS/spark/src/texture/stones.bmp");
    transform tr;

    while(!w.cerrado()){
        w.clear();

        shd.Bind();
        shd.Update(tr);
        tx.Bind(0);
        m_mesh.draw(quad);
        w.update();
    }

    return (0);
}
