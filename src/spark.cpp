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

	    GLuint vbo;


	    GLfloat vertices[] = {
	        -0.5f, -0.5f,  1.0f,
	        -0.5f,  0.5f,  1.0f,
	         0.5f,  0.5f,  1.0f,
	         0.5f,  0.5f,  1.0f,
	         0.5f, -0.5f,  1.0f,
	        -0.5f, -0.5f,  1.0f
	    };


	    glGenBuffers(1, &vbo);
	    glBindBuffer(GL_ARRAY_BUFFER, vbo);
	    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	    glEnableVertexAttribArray(0);
/*
	    vertex vert[] = { vertex(vec3(-0.5, -0.5, 0), vec2(0,0)),
	                              vertex(vec3(0, 0.5, 0), vec2(0.5,1.0)),
	                              vertex(vec3(0.5, -0.5, 0),vec2(1.0,0.0))};
*/
	    //unsigned int indices[] = {0,1,2};
	    //mesh m_mesh(vert, sizeof(vert)/sizeof(vert[0]));

	    mesh msh(vertices, 6);

	    shader shad("/home/jose/Documentos/c++/eclipseWS/spark/src/shader/basicShader.vert",
	    			"/home/jose/Documentos/c++/eclipseWS/spark/src/shader/basicShader.frag");
	    shad.enable();
	    Texture tx("/home/jose/Documentos/c++/eclipseWS/spark/src/texture/stones.bmp");
	    camara cam( glm::vec3(0,0,-1), 70.0f, float(800)/float(450), 0.5f, 100.0f );
	    transform tr;


	    while(!w.cerrado()){
	        w.clear();
	        shad.update(tr,cam);
	        tx.Bind(0);
	        msh.draw();
	        //glDrawArrays(GL_TRIANGLES, 0,6);
	        w.update();
	    }

	    return (0);
}
