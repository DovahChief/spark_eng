/*
 * Motor GRafico con OPENGL y GLFW
 * creado por Jose Antonio Limonta
 * email : pepelimonta@gmail.com
 *
 * */

#include "includes.h"
#include <vector>
#include <time.h>

#define BATCH_R 0


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

#if BATCH_R
    batchRender renderer {};
#else
    simple2DRenderer renderer {};
#endif



    std::vector<renderable2D*> sprites;
    srand(time(NULL));

    for (float y = 0; y < 9.0f; y++) {
        for (float x = 0; x < 16.0f; x++) {
        #if BATCH_R
            sprites.push_back(new sprite(x,y, 0.9f,0.9f, vec4(0,0 , rand()% 1000/1000.0f ,0) ));
        #else
            sprites.push_back(new static_sprite(x,y, 0.9f,0.9f, vec4(0,0 , rand()% 1000/1000.0f ,0), shad));
        #endif
        }
    }



	while(!w.cerrado()){
		w.clear();

		double x {}, y {};
		w.mouse_position(x, y);
		shad.setUniform2f("light_pos", vec2((float) ( x* 10.0f/800.0f) + 2, (float) (9.0f - (y * 9.0f/450.0f)) ));

#if BATCH_R
		renderer.begin();
#endif
		for(auto x : sprites)
            renderer.submit(x);
#if BATCH_R
		renderer.end();
#endif
		renderer.flush();

		w.update();
	}

	return (0);
}
