#version 330 core

out vec4 color;

in vec3 inColor;

void main()
{
  color = vec4(inColor, 1.f);
}
