"""Native checks of the frozen source-witness fast path and enabled guards."""
import argparse
import json
import os
from pathlib import Path
import subprocess


def function(text, signature):
    start = text.index(signature)
    brace = text.index('{', start)
    depth = 1
    end = brace + 1
    while depth:
        depth += (text[end] == '{') - (text[end] == '}')
        end += 1
    return text[start:end]


PREFIX = r'''
#include <algorithm>
#include <array>
#include <atomic>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
namespace reo_parent_natural {
std::atomic<size_t> actualOwnerBindingCount{0};
std::atomic<bool> actualFirstEntryEnrollmentFlag{false};
inline bool anyActualOwnerBound()noexcept{return actualOwnerBindingCount.load(std::memory_order_acquire)!=0;}
}
using namespace reo_parent_natural;
enum class ContextWriteIntent:uint32_t {GeneratedPcProgress=1,GenuineScalarControl=2,NumericOrOpaque=3,ReviewedRawIngress=4};
struct InstructionOrigin {uint32_t pc=0,word=0;ContextWriteIntent intent=ContextWriteIntent::NumericOrOpaque;};
enum class SourceSpace {Ram,Spr};
struct PS2Runtime {};
struct R5900Context {uint32_t pc=0;};
struct MemoryView {SourceSpace space=SourceSpace::Ram;uint32_t at=0,limit=0;bool source=false;};
struct Target {};
std::vector<std::string> events;
unsigned refusals=0;
bool failOwner=false;
std::shared_ptr<Target> scopedMemoryOwner(const void*,R5900Context&){
 events.push_back("lookup");if(failOwner)throw std::runtime_error("owner failure");
 return anyActualOwnerBound()?std::make_shared<Target>():nullptr;
}
MemoryView actualMemoryView(PS2Runtime&,uint32_t address,bool fast){
 return {SourceSpace::Ram,address&0x1ffffffu,0x2000000u,fast||address<0x10000000u};
}
void invalidateActualPreEntryControlBytes(const void*,uint32_t,uint32_t){events.push_back("invalidate");}
std::shared_ptr<int> prepareActualPreEntryControlWrite(PS2Runtime&,const void*,R5900Context&,uint32_t,const void*,size_t,const InstructionOrigin&){
 events.push_back("prepare");return actualFirstEntryEnrollmentFlag.load()?std::make_shared<int>(1):nullptr;
}
void completeActualPreEntryControlWrite(const std::shared_ptr<int>&){events.push_back("complete");}
void abandonActualPreEntryControlWrite(const std::shared_ptr<int>&){events.push_back("abandon");}
namespace reo_parent_natural {[[noreturn]] void throwOwnedSourceFailure(PS2Runtime*){++refusals;throw std::runtime_error("owned failure");}}
struct WriteTransaction {
 const void* value;
 WriteTransaction(const void*,SourceSpace,uint32_t,const void* v,size_t,R5900Context&):value(v){events.push_back("authorize");}
 const void* actualBytes(const void*){return value;}
 void completed(){events.push_back("completed");}
};
namespace reo_source_instrumentation {InstructionOrigin actualInstructionOrigin{};}
struct Inputs {unsigned calls=0;uint32_t pc=0,word=0;void at(uint32_t p,uint32_t w){++calls;pc=p;word=w;}};
'''

SUFFIX = r'''
unsigned checks=0;
void check(bool value){++checks;if(!value)throw std::runtime_error("Source witness check failed: "+std::to_string(checks));}
template<class T>void writes(T value){
 for(unsigned owner: {0u,1u,2u})for(bool audit:{false,true})
 for(bool fast:{false,true})for(uint32_t address:{0u,0x1fffffdu,0x20000000u,0x10000000u})
 for(bool fault:{false,true}){
  actualOwnerBindingCount.store(owner);actualFirstEntryEnrollmentFlag.store(audit);
  struct Result{std::array<uint8_t,64> ram{};unsigned calls=0,refused=0;std::string error;std::vector<std::string> trace;};
  auto run=[&](bool candidate){
   Result result;events.clear();refusals=0;PS2Runtime rt;R5900Context ctx{};
   auto original=[&](T v){++result.calls;if(fault)throw std::runtime_error("original store fault");
    std::array<uint8_t,sizeof(T)> bytes{};std::memcpy(bytes.data(),&v,sizeof(T));
    for(size_t i=0;i<sizeof(T);++i)result.ram[(address+i)%result.ram.size()]=bytes[i];};
   try{if(candidate)new_impl::guardedWrite(rt,result.ram.data(),ctx,address,value,fast,original);
       else old_impl::guardedWrite(rt,result.ram.data(),ctx,address,value,fast,original);}
   catch(const std::exception& e){result.error=e.what();}
   result.refused=refusals;result.trace=events;return result;
  };
  const auto before=run(false),after=run(true);
  check(before.ram==after.ram&&before.calls==after.calls&&before.error==after.error&&before.refused==after.refused);
  if(owner||audit)check(before.trace==after.trace);else check(after.trace.empty());
 }
}
int main(){
 for(unsigned owner:{0u,1u,2u})for(bool audit:{false,true}){
  actualOwnerBindingCount.store(owner);actualFirstEntryEnrollmentFlag.store(audit);
  check(anySourceWitnessRequired()==bool(owner||audit));
  old_impl::Entry before;new_impl::Entry after;
  for(uint32_t opcode:{0u,0x44820800u,0xc4420000u}){
   before.at(0x196010u,opcode);after.at(0x196010u,opcode);
   if(owner||audit)check(before.actualInstructionOrigin.pc==after.actualInstructionOrigin.pc&&
    before.actualInstructionOrigin.word==after.actualInstructionOrigin.word&&
    before.actualInstructionOrigin.intent==after.actualInstructionOrigin.intent&&before.inputs_.calls==after.inputs_.calls);
   else check(after.inputs_.calls==0&&after.actualInstructionOrigin.pc==0);
  }
 }
 writes(uint8_t(0xa5));writes(uint16_t(0xb123));writes(uint32_t(0xabcdef12));
 writes(uint64_t(0xabcdef1234567890ull));writes(std::array<uint64_t,2>{0xabcdef1234567890ull,0x1122334455667788ull});
 actualOwnerBindingCount.store(1);actualFirstEntryEnrollmentFlag.store(false);failOwner=true;
 PS2Runtime rt;R5900Context ctx{};unsigned calls=0;
 try{new_impl::guardedWrite(rt,nullptr,ctx,0,1u,true,[&](unsigned){++calls;});check(false);}
 catch(const std::runtime_error& e){check(std::string(e.what())=="owner failure"&&calls==0);}
 std::cout<<"PASS "<<checks<<" checks: disabled witnesses, enabled audit/owner/tombstones, RAM/MMIO/wrapping stores, faults and 128-bit values\n";
}
'''


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('before', type=Path)
    parser.add_argument('after', type=Path)
    parser.add_argument('--compiler', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    runtime = 'source/third_party/PS2Recomp/ps2xRuntime/src/lib'
    parent = (args.after / runtime / 'parent_natural_runtime.h').read_text()
    origin = (args.before / runtime / 'source_instruction_origin.hpp').read_text()
    source = PREFIX + '\nnamespace reo_parent_natural {\n' + function(parent, 'inline bool anySourceWitnessRequired()') + '\n}\n'
    source += function(origin, 'inline InstructionOrigin classifyInstruction(')
    for name, kit in [('old_impl', args.before), ('new_impl', args.after)]:
        entry = (kit / runtime / 'source_instruction_access.hpp').read_text()
        overlay = (kit / 'source/tools/parallel_gs_backend/resident_geometry/guarded_source_overlay.hpp').read_text()
        source += '\nnamespace ' + name + ' {\nstruct Entry {InstructionOrigin actualInstructionOrigin{};Inputs inputs_;\n'
        source += function(entry, 'void at(uint32_t pc,uint32_t opcode)') + '\n};\n'
        source += function(overlay, 'template <class T, class OriginalWrite>') + '\n}\n'
    source += SUFFIX
    fixture = args.output / 'check.cpp'
    fixture.write_text(source)
    compiler = args.compiler.resolve()
    env = os.environ.copy()
    env['PATH'] = str(compiler.parent) + os.pathsep + str(compiler.parents[1] / 'x86_64-w64-mingw32/bin') + os.pathsep + env.get('PATH', '')
    exe = args.output / 'check.exe'
    with (args.output / 'compile.log').open('wb') as log:
        subprocess.run([str(compiler), '-O2', '-std=c++20', str(fixture), '-o', str(exe)], env=env, stdout=log, stderr=subprocess.STDOUT, check=True)
    result = subprocess.check_output([str(exe.resolve())], env=env, text=True)
    (args.output / 'result.json').write_text(json.dumps({'passed': True, 'stdout': result, 'gameplayTest': False}, indent=2))
    print(result, end='')


if __name__ == '__main__':
    main()
