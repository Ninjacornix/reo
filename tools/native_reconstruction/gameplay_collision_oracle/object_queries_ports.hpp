#pragma once
inline void query_input_gate(std::uint8_t* m,R5900Context* c,PS2Runtime*){c->g[2].lo=m[80];c->pc=GPR_U32(c,31);}
inline void sub_001B0310_0x1b0310(std::uint8_t* m,R5900Context* c,PS2Runtime* r){query_input_gate(m,c,r);}
