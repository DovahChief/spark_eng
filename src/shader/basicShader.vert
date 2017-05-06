#version 120

//attribute vec2 textCoord;
//layout (location = 0) in vec4 psn;
//varying vec2 textCoord0;
attribute vec4 position;
attribute vec4 color;


//uniform mat4 transform = mat4(1.0);
uniform mat4 pr_mat = mat4(1.0);
uniform mat4 vw_mat = mat4(1.0);
uniform mat4 ml_mat = mat4(1.0);

varying vec4 pos;
varying vec4 colr;

void main(){	
	gl_Position = pr_mat *  vw_mat * ml_mat *vec4(position);
	//textCoord0 = textCoord;
	colr = color;
	pos = ml_mat * position;
}
