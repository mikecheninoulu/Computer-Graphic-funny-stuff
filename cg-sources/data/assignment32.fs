#version 150
uniform vec4 objColor;

out vec4 gl_FragColor;

void main(void) {
    gl_FragColor = objColor; //vec4(ex_Color,1.0);
}
