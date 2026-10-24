#include "vu_specialized_route.h"
#include "vu_native_geometry_route.h"
#include <array>
#include <cstdio>
#include <cstdlib>
#include <cstring>
static unsigned checks=0;
static void check(bool ok,const char* message){++checks;if(!ok){std::fprintf(stderr,"FAIL %s\n",message);std::exit(1);}}
static uint32_t block(vu_specialized::Invocation&){return 2;}
static vu_native_geometry::Result loop(vu_specialized::Invocation&){return {};}
int main(){
 std::array<uint8_t,32> expected{},live{},data{};
 const vu_specialized::Block translated{2,block};
 std::array<const vu_specialized::Block*,4> blocks{};blocks[1]=&translated;
 const vu_specialized::Program program{expected.data(),32,32,blocks.data()};
 const vu_specialized::ProgramTable table{&program,1};
 auto selected=[&]{return vu_specialized::selectProgram(live.data(),32,data.data(),32,false);};
 check(vu_specialized::registerProgramTable(&table),"default registration");
 check(selected()==&program,"default exact match");live[31]=71;
 check(!selected(),"default still rejects a changed bank tail");
 check(vu_specialized::registerProgramTableCodeExtent(&table,24),"covered blocks register");
 check(selected()==&program,"independent code in the tail retains geometry optimization");
 live[23]=19;check(!selected(),"last covered byte must match");live[23]=0;
 check(!vu_specialized::registerProgramTableCodeExtent(&table,16),"block extending beyond coverage rejected");
 check(selected()==&program,"failed registration preserves active metadata");
 check(!vu_specialized::registerProgramTableCodeExtent(&table,25),"unaligned extent rejected");
 check(!vu_specialized::registerProgramTableCodeExtent(&table,40),"oversized extent rejected");
 check(vu_specialized::codeComparisonBytes(&program)==24,"published extent");
 check(!vu_specialized::selectProgram(live.data(),32,data.data(),32,true),"capture still excludes compiled execution");
 check(!vu_specialized::selectProgram(live.data(),32,live.data(),32,false),"overlap still rejected");
 const vu_native_geometry::DynamicLoop safe{8,16,1,loop};
 const vu_native_geometry::DynamicLoop unsafe{8,24,1,loop};
 std::array<const vu_native_geometry::DynamicLoop*,4> loops{};loops[1]=&safe;
 const vu_native_geometry::Program native{&program,loops.data()};
 const vu_native_geometry::ProgramTable natives{&native,1};
 check(vu_native_geometry::registerProgramTable(&natives),"native body entirely covered");
 loops[1]=&unsafe;
 check(!vu_native_geometry::registerProgramTable(&natives),"native body crossing coverage rejected");
 loops[1]=&safe;
 std::array<vu_specialized::Program,2> ambiguous{{program,program}};
 std::array<uint8_t,32> differentTail{};differentTail[31]=99;ambiguous[1].exactCodeImage=differentTail.data();
 const vu_specialized::ProgramTable duplicate{ambiguous.data(),2};
 check(!vu_specialized::registerProgramTableCodeExtent(&duplicate,24),"ambiguous covered images rejected");
 check(selected()==&program,"ambiguity failure preserves active table");
 check(vu_specialized::registerProgramTable(&table),"return to exact mode");
 check(!selected(),"exact mode restored after prefix mode");
 std::printf("PASS %u code coverage checks: changed tails, exact covered bytes, block/native bounds, ambiguity and old default\n",checks);
}
