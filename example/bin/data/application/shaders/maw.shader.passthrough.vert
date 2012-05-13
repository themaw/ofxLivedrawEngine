void main(void)
{
    // pass through vertex
	gl_Position = ftransform();
    
    // pass multi-texture coords to fragment shader
	gl_TexCoord[0] = gl_MultiTexCoord0;
	gl_TexCoord[1] = gl_MultiTexCoord1;
}
