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
	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	shad.setUniformMAT4("pr_mat", ortho);
    
    batchRender renderer {};

    std::vector<renderable2D*> sprites { };
    srand(time(nullptr));

    for (float y = 0; y < 9.0f; y+= 0.05f) {
        for (float x = 0; x < 16.0f; x+= 0.05f) {
            auto rand_col = rand()% 1000/1000.0f;
			sprites.push_back(new sprite { x, y, 0.04f, 0.04f, vec4(0, 0, rand_col, 0) });
        }
    }

	timer tm { };
    unsigned short fps {0};
    tm.reset();

	while(!w.cerrado()){
		mat4 mtrans = mat4::rotation(fps / 10, vec3(0,0,1));
		shad.setUniformMAT4("ml_mat", mtrans);
        w.clear();
		double x {}, y {};
		w.mouse_position(x, y);
		shad.setUniform2f("light_pos", vec2((float) (x * 16.0f/800.0f),
                                             (float) (9.0f-(y * 9.0f/450.0f)) ));
		renderer.begin();
		for(auto& spr : sprites)
			renderer.submit(spr);
		renderer.end();
		renderer.flush();

		w.update();

        fps++;
        if (tm.get_diff() >= 1){
            printf("FPS : %d SPRITES : %d\n", fps, (uint)sprites.size());
            tm.reset();
            fps = 0;
        }

	}
	return (0);
}
