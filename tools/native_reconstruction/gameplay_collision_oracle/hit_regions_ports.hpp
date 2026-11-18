#pragma once
// Declared scalar implementation of the original1919D0 vector/basis product.
// The original pose traversal and queue/reset bodies are compiled unchanged.
inline void sub_001919D0_0x1919d0(std::uint8_t* m,R5900Context* c,PS2Runtime*){
    const auto v=ref_read<std::array<float,3>>(m,GPR_U32(c,5));
    const auto b=ref_read<std::array<float,16>>(m,GPR_U32(c,6));
    for(unsigned i=0;i<3;++i)ref_write(m,GPR_U32(c,4)+4*i,(b[i]*v[0]+b[4+i]*v[1])+b[8+i]*v[2]);
    c->pc=GPR_U32(c,31);
}
