#version 330 core

in vec3 _outcol;
out vec4 _frag;

void main() {
    _frag = vec4(_outcol, 1.0);
}