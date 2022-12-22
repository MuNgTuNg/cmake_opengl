#version 330 core

//output color in rgba
out vec4 FragColor;

//comes from vertex shader
in vec3 color;
in vec2 texCoord;

uniform sampler2D makima;


void main()
{
    

    FragColor = texture(makima,texCoord);
}