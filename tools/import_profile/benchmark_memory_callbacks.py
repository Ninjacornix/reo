"""CPU-only timing/evaluation check of the real guard and callback bodies.

External fixture bindings return no owner. This does not exercise GPU ownership,
the game's scheduler, or gameplay and cannot establish gameplay parity.
"""
import json
import os
from pathlib import Path
import subprocess
import sys
import time


COMMON = r"""
#pragma once
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <immintrin.h>
#include <memory>
#include <stdexcept>
#include <chrono>
#include <iostream>
#include <vector>
enum class SourceSpace {Ram,Spr};
struct R5900Context {uint32_t pc=0;};
struct PS2Runtime {static bool isSpecialAddress(uint32_t a){return a>=0x10000000u;}
"""
for _bits, _kind in [(8, "uint8_t"), (16, "uint16_t"), (32, "uint32_t"),
                     (64, "uint64_t"), (128, "__m128i")]:
    COMMON += f"""
 {_kind} Load{_bits}(uint8_t* p,R5900Context*,uint32_t a){{{_kind} v;std::memcpy(&v,p+(a&0x1ffffffu),sizeof(v));return v;}}
 void Store{_bits}(uint8_t* p,R5900Context*,uint32_t a,{_kind} v){{std::memcpy(p+(a&0x1ffffffu),&v,sizeof(v));}}
"""
COMMON += r"""
};
struct Target{void read(SourceSpace,uint32_t,uint32_t,R5900Context*,uint32_t);};
struct Permit {};
namespace reo_parent_natural {[[noreturn]] void throwOwnedSourceFailure(PS2Runtime*);}
namespace reo_source_instrumentation {
extern unsigned actualInstructionOrigin;
void recordActualGuardedMemoryInput(const std::shared_ptr<Target>&,R5900Context&,uint32_t,bool,SourceSpace,uint32_t,uint32_t,const void*,size_t);
}
namespace reo_source_adapter {
struct MemoryView {SourceSpace space=SourceSpace::Ram;uint32_t at=0,limit=0;bool source=false;};
std::shared_ptr<Target> scopedMemoryOwner(const void*,R5900Context&);
inline MemoryView actualMemoryView(PS2Runtime&,uint32_t at,bool){return {SourceSpace::Ram,at&0x1ffffffu,0x2000000u,true};}
void invalidateActualPreEntryControlBytes(const void*,uint32_t,uint32_t);
std::shared_ptr<Permit> prepareActualPreEntryControlWrite(PS2Runtime&,const void*,R5900Context&,uint32_t,const void*,size_t,unsigned);
void completeActualPreEntryControlWrite(const std::shared_ptr<Permit>&);
void abandonActualPreEntryControlWrite(const std::shared_ptr<Permit>&);
struct WriteTransaction {
 WriteTransaction(const void*,SourceSpace,uint32_t,const void*,size_t,R5900Context&);
 const void* actualBytes(const void*);void completed();
};
}
void ps2TraceGuestWrite(uint8_t*,uint32_t,size_t,uint64_t,uint64_t,const char*,R5900Context*);
"""

BINDINGS = r"""
#include "common.hpp"
#include <cstdlib>
void Target::read(SourceSpace,uint32_t,uint32_t,R5900Context*,uint32_t){std::abort();}
namespace reo_parent_natural {[[noreturn]] void throwOwnedSourceFailure(PS2Runtime*){std::abort();}}
namespace reo_source_instrumentation {
unsigned actualInstructionOrigin=0;
void recordActualGuardedMemoryInput(const std::shared_ptr<Target>&,R5900Context&,uint32_t,bool,SourceSpace,uint32_t,uint32_t,const void*,size_t){std::abort();}
}
namespace reo_source_adapter {
std::shared_ptr<Target> scopedMemoryOwner(const void*,R5900Context&){return {};}
void invalidateActualPreEntryControlBytes(const void*,uint32_t,uint32_t){}
std::shared_ptr<Permit> prepareActualPreEntryControlWrite(PS2Runtime&,const void*,R5900Context&,uint32_t,const void*,size_t,unsigned){return {};}
void completeActualPreEntryControlWrite(const std::shared_ptr<Permit>&){}
void abandonActualPreEntryControlWrite(const std::shared_ptr<Permit>&){std::abort();}
WriteTransaction::WriteTransaction(const void*,SourceSpace,uint32_t,const void*,size_t,R5900Context&){std::abort();}
const void* WriteTransaction::actualBytes(const void*){std::abort();}
void WriteTransaction::completed(){std::abort();}
}
void ps2TraceGuestWrite(uint8_t*,uint32_t,size_t,uint64_t,uint64_t,const char*,R5900Context*){}
"""


def main():
    repo = Path(__file__).resolve().parents[2]
    candidate = Path(sys.argv[1]).resolve()
    out = Path(sys.argv[2]).resolve()
    if not out.is_relative_to(repo / "build-ninja") or out.exists():
        raise ValueError("Use a fresh output under build-ninja")
    record = json.loads((candidate / "candidate.json").read_text())
    original = Path(record["originalHeader"]).read_text()
    updated = (candidate / "guarded_source_overlay.hpp").read_text()
    project = repo / "build-ninja/import-optimized-20261020/worker-benchmark/work/project"
    memory = (project / "third_party/PS2Recomp/ps2xRuntime/include/ps2_runtime_macros.h").read_text()
    memory = memory[memory.index("static inline bool Ps2FastRangeIsContiguous"):
                    memory.index("#define FAST_READ8")]
    out.mkdir(parents=True)
    (out / "common.hpp").write_text(COMMON)
    (out / "bindings.cpp").write_text(BINDINGS)
    paths = json.loads((repo / "build-ninja/import-profile-20261020/paths.json").read_text())
    tools = Path(paths["compiler"]) / "bin"
    compiler = str(tools / "x86_64-w64-mingw32-clang++.exe")
    env = dict(os.environ, PATH=str(tools) + os.pathsep + os.environ.get("PATH", ""))
    options = ["-O2", "-std=c++20", "-msse4.1", "-fno-fast-math", "-ffp-contract=off",
               "-fno-strict-aliasing", "-fwrapv"]
    report = {"gameExecuted": False, "gpuOwner": False, "acceptedForRelease": False,
              "bindings": "synthetic external no-owner callbacks; real guard and RAM helper bodies",
              "compiles": [], "runs": []}

    def run_compile(label, command):
        start = time.perf_counter()
        with (out / (label + ".log")).open("wb") as log:
            subprocess.run(command, env=env, stdout=log, stderr=subprocess.STDOUT, check=True)
        report["compiles"].append({"variant": label, "seconds": time.perf_counter()-start})

    run_compile("bindings", [compiler, *options, "-c", str(out / "bindings.cpp"),
                             "-o", str(out / "bindings.obj")])
    for name, text in [("old", original), ("shared", updated)]:
        guard = text[text.rfind("template <", 0, text.index("T guardedRead(")):
                     text.index("template <class T> T gprRead")]
        helpers = ""
        if name == "shared":
            helpers = text[text.index("template<bool Fast> struct OriginalMemoryRead"):
                           text.index("constexpr bool DirectFieldRewriteComplete")]
        macros = text[text.index("#define REO_GUARDED_FAST_READ"):
                      text.index("#undef GPR_U32")]
        source = ('#include "common.hpp"\n#define PS2_RAM_SIZE 0x2000000u\n'
                  '#define PS2_RAM_MASK 0x1ffffffu\n' + memory
                  + "\nnamespace reo_source_adapter {\n" + guard + helpers + "\n}\n" + macros
                  + '\n__attribute__((noinline)) void step(PS2Runtime* runtime,uint8_t* rdram,R5900Context* ctx,uint32_t index){\n')
        for i in range(64):
            source += (f'uint32_t value{i}=FAST_READ32((index+{i*4})&4095u);'
                       f'FAST_WRITE32((index+{i*4+260})&4095u,value{i}*1664525u+1013904223u);\n')
        source += r"""
}
int main(int argc,char** argv){
 std::vector<uint8_t> ram(PS2_RAM_SIZE);
 for(size_t i=0;i<ram.size();++i)ram[i]=uint8_t(i*37u+19u);
 PS2Runtime runtime;R5900Context ctx;
 auto begin=std::chrono::steady_clock::now();
 const unsigned iterations=argc>1?unsigned(std::strtoul(argv[1],nullptr,10)):1048576u;
 for(unsigned i=0;i<iterations;++i)step(&runtime,ram.data(),&ctx,i*4u);
 double seconds=std::chrono::duration<double>(std::chrono::steady_clock::now()-begin).count();
 uint64_t sum=0;for(uint8_t v:ram)sum=sum*31u+v;
 std::cout<<sum<<" "<<seconds<<"\n";
}
"""
        path = out / (name + ".cpp")
        path.write_text(source)
        run_compile(name, [compiler, *options, str(path), str(out / "bindings.obj"),
                           "-o", str(out / (name + ".exe"))])
    for name in ["old", "shared", "shared", "old"]:
        process = subprocess.run([str(out / (name + ".exe")), "1048576"], env=env, capture_output=True,
                                 text=True, check=True)
        checksum, seconds = process.stdout.split()
        report["runs"].append({"variant": name, "checksum": checksum, "seconds": float(seconds)})
        print(name, process.stdout.strip(), flush=True)
    assert len({row["checksum"] for row in report["runs"]}) == 1
    (out / "results.json").write_text(json.dumps(report, indent=2))


if __name__ == "__main__":
    main()
