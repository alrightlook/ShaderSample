attribute vec3 VertexPosition;
attribute vec3 VertexColor;

varying vec3 Color;

void main(void)
{
	Color = VertexColor;
	gl_Position = vec4(VertexPosition,1.0);
}
