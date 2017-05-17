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

	window w("SPARK2", 800, 450);
	shader* shad = new shader { "/home/jose/Documentos/c++/eclipseWS/spark/src/shader/basicShader.vert",
			"/home/jose/Documentos/c++/eclipseWS/spark/src/shader/basicShader.frag" };
	shader* shad2 = new shader { "/home/jose/Documentos/c++/eclipseWS/spark/src/shader/basicShader.vert",
			"/home/jose/Documentos/c++/eclipseWS/spark/src/shader/basicShader.frag" };


	//mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	//shad.setUniformMAT4("pr_mat", ortho);
    
    tileLayer layer1(shad);
    tileLayer layer2(shad2);

    srand(time(NULL));
    for (float y = -9.0f; y < 9.0f; y += 0.1){
        for (float x = -16.0f; x < 16.0f; x += 0.1){
            layer1.add( new sprite {x,y, 0.09f, 0.09f, vec4(0,0,rand()%1000/1000.0f,0)});
        }
    }

    layer2.add(new sprite {0,0, 4.0f, 4.0f, vec4(0.7,0,0,0)});

	timer tm { };
    unsigned short fps {0};
    tm.reset();

	while(!w.cerrado()){
        w.clear();
		double x {}, y {};
		w.mouse_position(x, y);
        shad->enable();
		shad->setUniform2f("light_pos", vec2((float) ( (x * 32.0f/800.0f) - 16.0f ),
                                             (float) (9.0f-(y * 18.0f/450.0f)) ));

        //shad->setUniform2f("light_pos", vec2(0,4));
        shad2->enable();
        shad2->setUniform2f("light_pos", vec2((float) ( (x * 32.0f/800.0f) - 16.0f ),
                                            (float) (9.0f-(y * 18.0f/450.0f)) ));
       shad->setUniformMAT4("ml_mat",mat4::rotation(30.0f, vec3(0,1,0)));
        layer2.render();
        layer1.render();

		w.update();

        fps++;
        if (tm.get_diff() >= 1){
            printf("FPS : %d \n", fps);
            tm.reset();
            fps = 0;
        }

	}

	return (0);
}
