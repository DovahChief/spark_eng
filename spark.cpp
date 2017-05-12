/*
 * Motor GRafico con OPENGL y GLFW
 * creado por Jose Antonio Limonta
 * email : pepelimonta@gmail.com
 *
 * */

#include "src/includes.h"

int main(){

	using namespace spark;
	using namespace graphics;
	using namespace math;

	window w("SPARK2", 800, 450);
    shader shad("/home/jose/Documentos/c++/eclipseWS/spark/src/shader/basicShader.vert",
				"/home/jose/Documentos/c++/eclipseWS/spark/src/shader/basicShader.frag");
	shad.enable();
	//mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	//shad.setUniformMAT4("pr_mat", ortho);
    
    tileLayer layer1(&shad);
    srand(time(NULL));
    for (float y = -9.0f; y < 9.0f; y += 0.1){
        for (float x = -16.0f; x < 16.0f; x += 0.1){
            layer1.add( new sprite {x,y, 0.09f, 0.09f, vec4(0,0,rand()%1000/1000.0f,0)});
        }
    }

	timer tm { };
    unsigned short fps {0};
    tm.reset();

	while(!w.cerrado()){
        w.clear();
		double x {}, y {};
		w.mouse_position(x, y);
		shad.setUniform2f("light_pos", vec2((float) ( (x * 32.0f/800.0f) - 16.0f ),
                                             (float) (9.0f-(y * 18.0f/450.0f)) ));

        layer1.render();
		w.update();

        fps++;
        if (tm.get_diff() >= 1){
            printf("FPS : %d \n", fps);
            tm.reset();
            fps = 0;
        }

	}
    shad.disable();
	return (0);
}
