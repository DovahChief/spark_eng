/*
 * Motor GRafico con OPENGL y GLFW
 * creado por Jose Antonio Limonta
 * email : pepelimonta@gmail.com
 *
 * */

#include "includes.h"


int main(){

		using namespace spark;
	    using namespace graphics;
	    using namespace math;

	    window w("SPARK-R", 800, 450);

	    shader shad("/home/jose/Documentos/c++/eclipseWS/spark/src/shader/basicShader.vert",
	    			"/home/jose/Documentos/c++/eclipseWS/spark/src/shader/basicShader.frag");
	    shad.enable();
	    mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	    shad.setUniformMAT4("pr_mat", ortho);

	    renderable2D sprite(math::vec3(2,2,0), math::vec2(4,4), math::vec4(1.0, 0.0, 1, 0), shad);
	    renderable2D sprite2(math::vec3(7,1,0), math::vec2(2,4), math::vec4(0.4, 0.0, 1, 0), shad);

	    simple2DRenderer renderer {};//clion

    //todo batch renderer
	    while(!w.cerrado()){
	        w.clear();

	        double x {}, y {};
	        w.mouse_position(x, y);
	        shad.setUniform2f("light_pos", vec2((float) ( x* 10.0f/800.0f) + 2, (float) (9.0f - (y * 9.0f/450.0f)) ));
	        renderer.submit(&sprite);
	        renderer.submit(&sprite2);
	        renderer.flush();

	        w.update();
	    }

	    return (0);
}
