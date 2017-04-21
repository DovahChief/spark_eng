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

    float count= 0;
    float _sinc = 0, _cosc = 0;

    vertex vertices[] = { vertex(vec3(-0.5, -0.5, 0), vec2(0,0)),
                              vertex(vec3(0, 0.5, 0), vec2(0.5,1.0)),
                              vertex(vec3(0.5, -0.5, 0),vec2(1.0,0.0))};

    unsigned int indices[] = {0,1,2};

    window w("ventana_GLFW", 800, 450);
    glClearColor(0.1f, 0.0f, 0.4f, 1.0f);
    mesh m_mesh(vertices, sizeof(vertices)/sizeof(vertices[0]), indices,sizeof(indices)/sizeof(indices[0]));
    //mesh m_mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));

    mesh m_mesh2("/home/jose/Documentos/c++/eclipseWS/spark/src/model/monkey.obj");

    Shader2 shd("/home/jose/Documentos/c++/eclipseWS/spark/src/shader/basicShader");
    Texture tx("/home/jose/Documentos/c++/eclipseWS/spark/src/texture/stones.bmp");
    camara cam( glm::vec3(0,0,-3), 80.0f, float(800)/float(450), 0.5f, 100.0f );
    transform tr;

    while(!w.cerrado()){
        w.clear();

        _cosc = cosf(count);
		_sinc = sinf(count);

		tr.set_rot(glm::vec3(count/100 , 0 , count/100 ));
		tr.set_pos(glm::vec3(0, 0, -1));

        shd.Bind();
        shd.Update(tr, cam);
        tx.Bind(0);
        m_mesh2.draw();
        w.update();
        count ++;
    }

    return (0);
}
