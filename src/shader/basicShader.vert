#version 120

attribute vec3 position;
attribute vec2 textCoord;

//layout (location = 0) in vec4 psn;

varying vec2 textCoord0;



uniform mat4 transform = mat4(1.0);
uniform mat4 pr_mat = mat4(1.0);
uniform mat4 vw_mat = mat4(1.0);
uniform mat4 m1_mat = mat4(1.0);

varying vec3 pos;

void main(){	
	gl_Position = pr_mat *  vw_mat * m1_mat * transform *vec4(position, 1.0);
	textCoord0 = textCoord;
	pos = position;
}
