#version 430 core

in vec2 ex_Tex;
in vec3 ex_Color;
out vec4 fragColor;

void main(void) {
  fragColor = vec4(ex_Color,1);
}
