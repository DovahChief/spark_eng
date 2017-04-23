#version 120

attribute vec3 position;
attribute vec2 textCoord;

varying vec2 textCoord0;
uniform mat4 transform = mat4(1.0);
uniform mat4 pr_mat = mat4(1.0);
uniform mat4 vw_mat = mat4(1.0);

void main(){	
	gl_Position = pr_mat * transform * vw_mat * vec4(position, 1.0);
	textCoord0 = textCoord;
}
