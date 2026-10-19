#version 450
// Full-screen triangle positions are generated on GPU; no host vertex math.
void main(){gl_Position=vec4(float((gl_VertexIndex&1)*4-1),float((gl_VertexIndex>>1)*4-1),0,1);}
