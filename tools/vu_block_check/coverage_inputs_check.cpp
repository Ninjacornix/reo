// Local supplied-input regression. No microcode images or game bytes are built in.
#include "reo_vu_specialized.h"
#include "reo_vu_specialized_generated.h"
#include "vu_specialized_route.h"
#include "vu_native_geometry_route.h"
#include "runtime/ps2_vu1.h"
#include <array>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <vector>
static unsigned checks=0;
static void check(bool ok,const char* text){++checks;if(!ok)throw std::runtime_error(text);}
int main(int argc,char** argv)try{
 if(argc!=2)return 2;
 const auto* table=reo_vu_specialized_generated::programTable();
 unsigned banks=0;
 for(const auto& file:std::filesystem::directory_iterator(argv[1])){
  const auto filename=file.path().filename().string();
  if(file.path().extension()!=".bin"||filename.ends_with(".data.bin"))continue;
  std::ifstream stream(file.path(),std::ios::binary);
  std::vector<uint8_t> code{std::istreambuf_iterator<char>(stream),std::istreambuf_iterator<char>()};
  check(code.size()==16384,"bank input size");std::array<uint8_t,16384> data{};VU1State state{};
  _putenv_s("REO_VU_EXACT_BANK","");check(reoRegisterVuSpecializedPrograms(),"real prefix factory registration");
  const auto* selected=vu_specialized::selectProgram(code.data(),16384,data.data(),16384,false);
  check(selected,"actual later-room bank selects its geometry program");
  const auto extent=vu_specialized::codeComparisonBytes(selected);
  check(extent<code.size(),"supplied later-room bank has an independently interpreted suffix");
  check(std::memcmp(code.data(),selected->exactCodeImage,extent)==0,"all covered bytes match canonical program");
  check(std::memcmp(code.data(),selected->exactCodeImage,code.size())!=0,"input really differs outside coverage");
  const auto* native=vu_native_geometry::selectProgram(selected,code.data(),16384,data.data(),16384,&state,false);
  check(native,"real native geometry binding retained");
  bool bounded=true,hasLoop=false;
  for(uint32_t pc=0;pc<16384;pc+=8){
   if(auto* block=selected->entryBlocks[pc/8])bounded&=pc+block->instructionPairs*8<=extent;
   if(auto* loop=native->entryLoops[pc/8]){hasLoop=true;bounded&=loop->lastPC+8<=extent;}
  }
  check(bounded&&hasLoop,"every actual compiled block and native loop is covered");
  code[extent-1]^=1;check(!vu_specialized::selectProgram(code.data(),16384,data.data(),16384,false),"covered instruction mutation rejects optimization");code[extent-1]^=1;
  _putenv_s("REO_VU_EXACT_BANK","1");check(reoRegisterVuSpecializedPrograms(),"real old factory registration");
  check(!vu_specialized::selectProgram(code.data(),16384,data.data(),16384,false),"old full-bank mode reproduces refusal");
  ++banks;
 }
 check(banks>0,"at least one supplied bank tested");
 std::printf("PASS %u real-input checks across %u supplied banks\n",checks,banks);return 0;
}catch(const std::exception& error){std::fprintf(stderr,"FAIL %s\n",error.what());return 1;}
