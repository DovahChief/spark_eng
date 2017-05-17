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

    timer tm {};
    unsigned short fps {0};
    float x {0.0f}, y {0.0f};

	window w{"SPARK2", 800, 450};

	shader* shad = new shader { "/home/jose/Documentos/c++/eclipseWS/spark/src/shader/basicShader.vert",
			                    "/home/jose/Documentos/c++/eclipseWS/spark/src/shader/basicShader.frag" };

	shader* shad2 = new shader { "/home/jose/Documentos/c++/eclipseWS/spark/src/shader/basicShader.vert",
			                     "/home/jose/Documentos/c++/eclipseWS/spark/src/shader/basicShader.frag" };
    
    tileLayer layer1 {shad};
    tileLayer layer2 {shad2};

    srand(time(NULL));
    for (float _y = -9.0f; _y < 9.0f; _y += 0.1){
        for (float _x = -16.0f; _x < 16.0f; _x += 0.1){
            layer1.add( new sprite {_x,_y, 0.09f, 0.09f, vec4(0,0,rand()%1000/1000.0f,0)});
        }
    }

    layer2.add(new sprite {0,0, 4.0f, 4.0f, vec4(0.7,0,0,0)});
    tm.reset();

	while(!w.cerrado()){
        w.clear();
		w.mouse_position(x, y);
        x =  (x * 32.0f/800.0f) - 16.0f;
        y =  9.0f - (y * 18.0f/450.0f);
        shad->enable();
        shad->setUniform2f("light_pos", vec2 {x, y} );
        shad2->enable();
        shad2->setUniform2f("light_pos", vec2 {x, y} );

        layer1.render();
        layer2.render();
		w.update();

        if (tm.get_diff() >= 1){
            std::cout << "FPS : " << fps <<std::endl;
            tm.reset();
            fps = 0;
        }
        fps++;
	}

	return (0);
}
