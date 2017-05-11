#version 120

attribute vec4 position;
attribute vec4 color;

uniform mat4 pr_mat = mat4(1.0);
uniform mat4 vw_mat = mat4(1.0);
uniform mat4 ml_mat = mat4(1.0);

varying vec4 pos;
varying vec4 colr;

void main(){	
	gl_Position = pr_mat *  vw_mat * ml_mat *vec4(position);
	colr = color;
	pos = ml_mat * position;
}
