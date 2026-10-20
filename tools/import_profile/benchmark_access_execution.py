"""Check CPU-only access-wrapper execution before admitting inlining changes.

Uses the real frozen headers. Separate fixture bindings return no GPU owner;
this is a microbenchmark, not a replacement for gameplay/GPU validation.
"""
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys

from benchmark_compilation import load


def main():
    repo = Path(__file__).resolve().parents[2]
    out = Path(sys.argv[1]).resolve()
    if not out.is_relative_to(repo / "build-ninja") or out.exists():
        raise ValueError("Use a fresh directory under build-ninja")
    events = [json.loads(line) for line in
              (repo / "build-ninja/compile-full-20261020/old/commands.jsonl").read_text().splitlines()]
    reference = next(row["command"] for row in events if row["stage"] == "compile"
                     and row["event"] == "begin" and Path(row["command"][-1]).stem == "main31")
    options = reference[1:reference.index("-o")]
    options.remove("-c")
    compiler = reference[0]
    paths = json.loads((repo / "build-ninja/import-profile-20261020/paths.json").read_text())
    os.environ["REO_LLVM_MINGW"] = paths["compiler"]
    kit = repo / "build-ninja/import-optimized-20261020/kit"
    worker = load("access_execution_worker", kit / "tools/local_build/compile_game.py")
    env, _ = worker.portable_environment(kit, json.loads((kit / "compile-plan.json").read_text()))
    out.mkdir(parents=True)
    (out / "bindings.cpp").write_text(r"""
#include "source_instruction_access.hpp"
#include <cstdlib>
namespace reo_parent_natural {
std::shared_ptr<ControlTarget> findActualOwnerTarget(const void*) {return {};}
uint64_t actualOwnerBindingGeneration() noexcept {return 1;}
PS2Runtime* currentRuntime() noexcept {return nullptr;}
R5900Context* currentContext() noexcept {return nullptr;}
AccessScope::AccessScope(PS2Runtime*,R5900Context*):priorRuntime_(nullptr),priorContext_(nullptr){}
AccessScope::~AccessScope(){}
}
void PS2Runtime::requestStop() {std::abort();}
bool PS2Runtime::isStopRequested() const {std::abort();}
PS2Runtime::RecompiledFunction PS2Runtime::lookupFunction(uint32_t) {std::abort();}
namespace ps2_sched {int currentThread() {std::abort();}}
uint32_t ps2ActualGuestExecutionDepth(PS2Runtime*) noexcept {return 0;}
""")
    fixture = r"""
#include "source_instruction_access.hpp"
#include <chrono>
#include <iostream>
__attribute__((noinline)) void step(R5900Context& ctx) {
    using namespace reo_source_instrumentation;
    EntryScope inputs(nullptr,&ctx);
"""
    for i in range(128):
        fixture += (f"inputs.at({0x100000+i*4}u,0u);\n"
                    f"writeField(nullptr,ctx,&ctx.pc,uint32_t(readField(ctx,&ctx.pc)*1664525u"
                    f"+readField(ctx,&ctx.branch_pc)+{i+1013904223}u));\n"
                    f"writeField(nullptr,ctx,&ctx.branch_pc,uint32_t(readField(ctx,&ctx.pc)^{i}u));\n")
    fixture += r"""
}
int main(){
 R5900Context ctx{};ctx.pc=123;ctx.branch_pc=456;
 auto begin=std::chrono::steady_clock::now();
 for(unsigned i=0;i<65536;++i) step(ctx);
 double seconds=std::chrono::duration<double>(std::chrono::steady_clock::now()-begin).count();
 std::cout<<ctx.pc<<" "<<ctx.branch_pc<<" "<<seconds<<"\n";
}
"""
    (out / "fixture.cpp").write_text(fixture)
    commands = []

    def compile_one(name, command):
        commands.append(command)
        with (out / (name + ".log")).open("wb") as log:
            result = subprocess.run(command, env=env, stdout=log, stderr=subprocess.STDOUT)
        if result.returncode:
            raise RuntimeError(f"Compile/link failed; see {out / (name + '.log')}")

    compile_one("bindings", [compiler, *options, "-c", str(out / "bindings.cpp"),
                              "-o", str(out / "bindings.obj")])
    variants = {"default": [], "75": ["-mllvm", "-inline-threshold=75", "-mllvm", "-inlinehint-threshold=75"],
                "0": ["-mllvm", "-inline-threshold=0", "-mllvm", "-inlinehint-threshold=0"],
                "no-auto": ["-fno-inline-functions"]}
    for name, flags in variants.items():
        compile_one(name, [compiler, *options, *flags, str(out / "fixture.cpp"),
                            str(out / "bindings.obj"), "-o", str(out / (name + ".exe"))])
    root = Path(paths["compiler"])
    for name in ("libc++.dll", "libunwind.dll", "libwinpthread-1.dll"):
        shutil.copyfile(root / "x86_64-w64-mingw32/bin" / name, out / name)
    report = {"gameExecuted": False, "gpuOwner": False, "backgroundFullBuild": True,
              "acceptedForRelease": False, "commands": commands, "runs": []}
    for name in ["default", "75", "0", "no-auto", "no-auto", "0", "75", "default"]:
        process = subprocess.run([str(out / (name + ".exe"))], env=env,
                                 capture_output=True, text=True, check=True)
        pc, branch, seconds = process.stdout.split()
        report["runs"].append({"variant": name, "pc": int(pc), "branch": int(branch),
                               "seconds": float(seconds)})
        print(name, process.stdout.strip(), flush=True)
        (out / "results.json").write_text(json.dumps(report, indent=2))
    assert len({(row["pc"], row["branch"]) for row in report["runs"]}) == 1


if __name__ == "__main__":
    main()
