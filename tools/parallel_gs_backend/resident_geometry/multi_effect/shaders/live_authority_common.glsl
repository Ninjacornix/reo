layout(set=0,binding=0,std430) buffer AuthorityState {uint authorityState[];};
layout(set=0,binding=1,std430) buffer AuthorityData {uint authorityData[];};
layout(set=0,binding=2,std430) readonly buffer State {uint state[];};
layout(set=0,binding=3,std430) readonly buffer Data {uint data[];};
layout(set=0,binding=4,std430) readonly buffer Tape {uint tape[];};
layout(set=0,binding=5,std430) buffer Results {uint results[];};
layout(set=0,binding=6,std430) buffer Certificate {uint cert[];};
layout(set=0,binding=7,std430) buffer Completion {uint completion[];};
shared uint admitted;
void refuse(uint error){atomicCompSwap(results[0],0u,error);atomicCompSwap(cert[0],0u,error);atomicCompSwap(completion[8],0u,error);}
