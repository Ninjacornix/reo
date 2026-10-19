layout(set=0,binding=0,std430) readonly buffer Tape {uint tape[];};
layout(set=0,binding=1,std430) readonly buffer Native {uvec4 native[];};
layout(set=0,binding=2,std430) buffer Results {uint results[];};
layout(set=0,binding=3,std430) readonly buffer Parameters {
 uvec4 limits; //rawN,triangle capacity,event capacity,native capacity
 uvec4 identity; //bindinglow,bindinghigh,generation,job ordinal
 uvec4 mainTag; //literal incomingTOP+1, before count+2
 uvec4 geometry; //TOP,ITOP,operation,pair budget
 ivec4 offsetScissorLo;ivec4 scissorHi;
 uint material[8];
} p;
layout(set=0,binding=4,std430) buffer Positions {uint positions[];};
layout(set=0,binding=5,std430) buffer Attributes {uint attributes[];};
layout(set=0,binding=6,std430) buffer Primitives {uint primitives[];};
layout(set=0,binding=7,std430) buffer Consumer {uint consumer[];};
const uint TapeMagic=0x53543532u,TapeVersion=1u,TapeWords=65536u;
const uint MaxEvents=495u,MaxVertices=247u,MaxPolygon=12u,MaxNative=3213u;
const uint HeaderWords=32u,DescriptorWords=8u,RawBase=3992u;
const uint CertMagic=0x53544331u,CertVersion=1u,PrefixBase=16u;
const uint StaticProfile=0x5273fa3eu,Variant65DProfile=0x65d42fafu,Variant570Profile=0x57026e22u;
uint fanPrePC(){return p.identity.x==StaticProfile?0x900u:p.identity.x==Variant65DProfile?0x8e0u:0x7e0u;}
uint fanVerticesPC(){return p.identity.x==StaticProfile?0xae0u:p.identity.x==Variant65DProfile?0x9c0u:0x8c0u;}
uint mainPC(){return p.identity.x==StaticProfile?0x508u:p.identity.x==Variant65DProfile?0x4f0u:0x3f0u;}
uint finalPC(){return p.identity.x==StaticProfile?0x528u:p.identity.x==Variant65DProfile?0x510u:0x410u;}
uint descriptor(uint event,uint word){return tape[HeaderWords+event*DescriptorWords+word];}
void fail(uint status){atomicCompSwap(consumer[0],0u,status);atomicCompSwap(results[0],0u,status);}
uvec4 rawRow(uint at){return uvec4(tape[at],tape[at+1u],tape[at+2u],tape[at+3u]);}
bool literalTemplate(){
 return p.limits.x>0u&&p.limits.x<=MaxVertices&&p.limits.y==11u*p.limits.x&&
 p.limits.z>0u&&p.limits.z<=MaxEvents&&p.limits.w==MaxNative&&
 p.geometry.x<1024u&&p.geometry.y<1024u&&(p.geometry.z==0u||p.geometry.z==3u||p.geometry.z==4u||p.geometry.z==5u)&&p.geometry.w==65536u&&
 (p.identity.x==StaticProfile||p.identity.x==Variant65DProfile||p.identity.x==Variant570Profile)&&p.identity.y==0u&&p.identity.z!=0u&&p.identity.w<128u&&
 p.mainTag.x==(32768u|p.limits.x)&&p.mainTag.z==0x412u&&p.mainTag.w==0u&&
 ((p.mainTag.y>>26u)&3u)==0u&&((p.mainTag.y>>28u)&15u)==3u&&((p.mainTag.y>>14u)&1u)==1u&&
 ((p.mainTag.y>>15u)&7u)==4u&&p.material[6]==0u&&p.material[7]==0u;
}
bool producerEnvelope(){
 bool literalStrip=p.identity.x==StaticProfile&&tape[6]==1u&&descriptor(0u,0u)==0x110u&&descriptor(0u,6u)==4u;
 return results[0]==0u&&tape[0]==0u&&tape[1]==TapeMagic&&tape[2]==TapeVersion&&
 tape[3]==p.identity.x&&tape[4]==p.identity.y&&tape[5]==1u&&
 tape[6]>0u&&tape[6]<=p.limits.z&&tape[6]<=2u*p.limits.x+1u&&tape[7]<=TapeWords-RawBase&&
 tape[8]<=13u*p.limits.x+2u&&tape[9]<=MaxNative&&tape[10]<=p.geometry.w&&
 tape[11]==(literalStrip?0x128u:finalPC())&&(tape[12]&255u)==1u&&
 tape[13]==p.geometry.x&&tape[14]==p.geometry.y&&tape[15]==p.limits.x&&
 tape[16]==p.geometry.z&&tape[17]==p.geometry.w&&tape[18]==p.limits.z&&
 tape[19]==p.limits.w&&tape[20]==0u&&tape[21]==p.identity.z&&tape[22]==p.identity.w;
}
void dead(uint slot){
 for(uint j=0u;j<12u;++j)positions[slot*12u+j]=0u;
 for(uint j=0u;j<18u;++j)attributes[slot*18u+j]=0u;
 primitives[slot*8u]=0u;primitives[slot*8u+1u]=0xffffffffu;
 for(uint j=0u;j<6u;++j)primitives[slot*8u+2u+j]=p.material[j];
}
