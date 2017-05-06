#version 120

//varying vec2 textCoord0;
//uniform sampler2D diffuse;
//gl_FragColor = texture2D(diffuse, textCoord0);
//vec4(1.0, 0.0, 0.0, 1.0);

uniform vec4 colour = vec4(1.0);
uniform vec2 light_pos = vec2(1.0);

varying vec4 pos;
varying vec4 colr;

void main(){	
	float intensidad = 1.0/ length(pos.xy - light_pos);
	//gl_FragColor = colr * intensidad;
	gl_FragColor = colr * intensidad;
} 
