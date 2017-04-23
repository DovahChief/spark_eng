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

	    window w("SPARK", 800, 450);
	    glClearColor(0.1f, 0.0f, 0.4f, 1.0f);

	    GLfloat vertices[] = {
	        -0.5f, -0.5f,  1.0f,
	        -0.5f,  0.5f,  1.0f,
	         0.5f,  0.5f,  1.0f,
	         0.5f,  0.5f,  1.0f,
	         0.5f, -0.5f,  1.0f,
	        -0.5f, -0.5f,  1.0f
	    };


	    vertex vert[] = { vertex(vec3(-0.5, -0.5, 1), vec2(0,0)),
	                              vertex(vec3(0, 0.5, 1), vec2(0.5,1.0)),
	                              vertex(vec3(0.5, -0.5, 1),vec2(1.0,0.0))};

	    //unsigned int indices[] = {0,1,2};
	    mesh m_mesh(vert, sizeof(vert)/sizeof(vert[0]));
	    auto num_vert = sizeof(vertices)/(sizeof(vertices[0]) * 3);
	    mesh msh(vertices, num_vert);

	    shader shad("/home/jose/Documentos/c++/eclipseWS/spark/src/shader/basicShader.vert",
	    			"/home/jose/Documentos/c++/eclipseWS/spark/src/shader/basicShader.frag");
	    shad.enable();
	    Texture tx("/home/jose/Documentos/c++/eclipseWS/spark/src/texture/stones.bmp");

	    while(!w.cerrado()){
	        w.clear();
	        shad.update();
	        tx.Bind(0);
	        m_mesh.draw();

	        w.update();
	    }

	    return (0);
}
