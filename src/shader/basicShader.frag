#version 120

uniform vec4 colour = vec4(1.0);
uniform vec2 light_pos = vec2(1.0);

varying vec4 pos;
varying vec4 colr;

void main(){	
	float intensidad = 1.0/ length(pos.xy - light_pos);
	gl_FragColor = colr * intensidad;
} 
