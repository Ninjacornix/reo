"""Native differential checks of original/candidate cache and failure behavior."""
import json
import os
from pathlib import Path
import subprocess
import sys
import time

PREFIX = r'''
#include <cstdint>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>
#include <functional>
struct OwnedSourceFailure : std::runtime_error { using std::runtime_error::runtime_error; };
struct World;
thread_local World* world=nullptr;
struct ControlTarget {
    int id; uint64_t stamp=1; bool owned=false, ready=false, failEpoch=false, failOwned=false;
    explicit ControlTarget(int value):id(value){}
    virtual ~ControlTarget()=default;
    uint64_t epoch() const;
    bool ownsAnySource() const;
    bool readyForSelection() const;
};
struct TypedSourceWriteTarget {virtual ~TypedSourceWriteTarget()=default;};
struct ExplicitSourceWriteTarget {virtual ~ExplicitSourceWriteTarget()=default;};
struct NativeControlWriteTarget {virtual ~NativeControlWriteTarget()=default;};
struct CpuInputWriteTarget {virtual ~CpuInputWriteTarget()=default;};
struct AllTarget : ControlTarget, TypedSourceWriteTarget, ExplicitSourceWriteTarget,
                   NativeControlWriteTarget, CpuInputWriteTarget {using ControlTarget::ControlTarget;};
struct World {
    uint64_t generation=1; bool race=false, failFind=false;
    std::shared_ptr<ControlTarget> next;
    std::vector<std::string> events;
};
uint64_t actualOwnerBindingGeneration(){world->events.push_back("generation:"+std::to_string(world->generation));return world->generation;}
std::shared_ptr<ControlTarget> findActualOwnerTarget(const void*){
    world->events.push_back("find");
    if(world->failFind)throw std::runtime_error("find failure");
    if(world->race){world->race=false;++world->generation;}
    return world->next;
}
uint64_t ControlTarget::epoch()const{
    world->events.push_back("epoch:"+std::to_string(id));
    if(failEpoch)throw std::runtime_error("epoch failure");
    return stamp;
}
bool ControlTarget::ownsAnySource()const{
    world->events.push_back("owned:"+std::to_string(id));
    if(failOwned)throw std::runtime_error("ownership failure");
    return owned;
}
bool ControlTarget::readyForSelection()const{world->events.push_back("ready:"+std::to_string(id));return ready;}
struct Memory {void* getRDRAM(){return reinterpret_cast<void*>(0x1000);}};
struct PS2Runtime {Memory mem; bool stopped=false; Memory& memory(){return mem;}
    void requestStop(){world->events.push_back("stop");stopped=true;}};
'''

SUFFIX = r'''
struct Result {std::vector<std::string> events; std::vector<uint64_t> state; bool operator==(const Result&)const=default;};
template<class Cache, class Select, class Propagate>
Result scenario(unsigned which,Cache& cache,Select select,Propagate propagate){
    cache={}; World w; world=&w; PS2Runtime runtime;
    auto first=std::make_shared<AllTarget>(1); w.next=first;
    const void* ram=reinterpret_cast<void*>(0x1000);
    auto invoke=[&](const void* address){try{select(address);}catch(const std::exception& e){w.events.push_back(std::string("caught:")+e.what());}};
    if(which==0)w.next.reset();
    invoke(ram);
    switch(which){
    case 0:case 1:invoke(ram);break;
    case 2:invoke(reinterpret_cast<void*>(0x2000));break;
    case 3:++w.generation;w.next=std::make_shared<ControlTarget>(2);invoke(ram);break;
    case 4:++first->stamp;invoke(ram);break;
    case 5:++w.generation;w.race=true;invoke(ram);break;
    case 6:++w.generation;w.failFind=true;invoke(ram);w.failFind=false;invoke(ram);break;
    case 7:first->failEpoch=true;invoke(ram);first->failEpoch=false;invoke(ram);break;
    case 8:++w.generation;w.next=std::make_shared<ControlTarget>(2);w.next->failEpoch=true;invoke(ram);break;
    default:
        first->owned=which>=11; first->ready=which==10; first->failOwned=which==14;
        try{
            try{
                if(which==12)throw OwnedSourceFailure("original owned failure");
                if(which==13)throw 42;
                throw std::runtime_error("original ordinary failure");
            }catch(...){propagate(which==15?nullptr:&runtime);}
        }catch(const OwnedSourceFailure& e){w.events.push_back(std::string("owned error:")+e.what());}
         catch(const std::exception& e){w.events.push_back(std::string("ordinary error:")+e.what());}
         catch(...){w.events.push_back("unknown error");}
    }
    Result result{w.events,{cache.target?uint64_t(cache.target->id):0,
        uint64_t(bool(cache.typed)),uint64_t(bool(cache.exact)),uint64_t(bool(cache.native)),
        uint64_t(bool(cache.cpuInputs)),uint64_t(reinterpret_cast<uintptr_t>(cache.ram)),
        cache.binding,cache.epoch,uint64_t(runtime.stopped),uint64_t(cache.target.use_count())}};
    cache={}; world=nullptr; return result;
}
int main(){
    for(unsigned n=0;n<16;++n){
        auto old=scenario(n,old_impl::accessCache,old_impl::selectedTarget,old_impl::propagateOwnedFailure);
        auto candidate=scenario(n,new_impl::accessCache,new_impl::selectedTarget,new_impl::propagateOwnedFailure);
        if(!(old==candidate)){std::cerr<<"Differential failure: "<<n<<"\n";return 1;}
        if(n==3 && candidate.state[1]!=0)return 2;
        if(n==8 && candidate.state[0]!=1)return 3;
        if(n>=10 && n<=14 && candidate.state[8]!=1)return 4;
        if(n==15 && candidate.state[8]!=0)return 5;
    }
    std::cout<<"PASS 16 scenarios: callback order, cache state, identities, lifetimes, stop and exception behavior\n";
}
'''


def access_fragment(path):
    text = path.read_text(encoding='utf-8')
    return text[text.index('struct SourceAccessCache '):text.index('inline void rethrowOwnedFailure(')]


def main():
    repo = Path(__file__).resolve().parents[2]
    candidate = Path(sys.argv[1]).resolve()
    evidence = json.loads((candidate / 'candidate.json').read_text())
    out = candidate.parent / 'native-check'
    out.mkdir(exist_ok=False)
    source = (PREFIX + '\nnamespace old_impl {\n' + access_fragment(Path(evidence['source'])) + '\n}\n'
              + 'namespace new_impl {\n' + access_fragment(candidate / 'source_instruction_access.hpp')
              + '\n}\n#undef REO_SOURCE_COLD_NOINLINE\n' + SUFFIX)
    path = out / 'check.cpp'
    path.write_text(source, encoding='utf-8')
    paths = json.loads((repo / 'build-ninja/import-profile-20261020/paths.json').read_text())
    compiler_bin = Path(paths['compiler']) / 'bin'
    command = [str(compiler_bin / 'x86_64-w64-mingw32-clang++.exe'), '-O2', '-std=c++20', str(path), '-o', str(out / 'check.exe')]
    env = os.environ.copy()
    env['PATH'] = str(compiler_bin) + os.pathsep + env.get('PATH', '')
    started = time.perf_counter()
    with (out / 'compile.log').open('wb') as log:
        subprocess.run(command, env=env, stdout=log, stderr=subprocess.STDOUT, check=True)
    result = subprocess.run([str(out / 'check.exe')], env=env, capture_output=True, text=True, check=True)
    (out / 'result.json').write_text(json.dumps({'passed': True, 'scenarios': 16, 'seconds': time.perf_counter()-started,
                                               'stdout': result.stdout, 'gameExecuted': False}, indent=2))
    print(result.stdout, end='')


if __name__ == '__main__':
    main()
