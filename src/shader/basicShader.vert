#version 120

attribute vec3 position;
attribute vec2 textCoord;

varying vec2 textCoord0;
uniform mat4 transform;
uniform mat4 prmat;

void main(){	
	gl_Position = transform * vec4(position, 1.0);
	textCoord0 = textCoord;
}