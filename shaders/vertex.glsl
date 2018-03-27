#version 330 core

in vec2 position;
in vec3 _incol;

out vec3 _outcol;

void main() {
    _outcol = _incol;
    gl_position = vec4(position, 1.0);
}