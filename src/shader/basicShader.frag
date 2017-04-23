#version 120
varying vec2 textCoord0;

uniform sampler2D diffuse;
uniform vec4 colour;

void main(){	
	gl_FragColor = texture2D(diffuse, textCoord0);
	//vec4(1.0, 0.0, 0.0, 1.0);
} 
