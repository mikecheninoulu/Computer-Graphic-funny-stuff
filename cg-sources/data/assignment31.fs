#version 150
uniform sampler2D texture0;
in vec2 f_TexCoord0;
out vec4 gl_FragColor;

void main(void)
{
    gl_FragColor = texture2D(texture0, vec2(f_TexCoord0.x, f_TexCoord0.y));
}
