#version 120
varying vec2 textCoord0;

uniform sampler2D diffuse;

uniform vec4 colour;
uniform vec2 light_pos;

varying vec3 pos;

void main(){	
	//gl_FragColor = texture2D(diffuse, textCoord0);
	//vec4(1.0, 0.0, 0.0, 1.0);
	float intensidad = 1.0/ length(pos.xy - light_pos);
	gl_FragColor = colour * intensidad;
} 
