"""Run original/candidate RAM helpers side by side with the pinned compiler."""
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys


def main():
    repo = Path(__file__).resolve().parents[2]
    candidate = Path(sys.argv[1]).resolve()
    record = json.loads((candidate / "candidate.json").read_text())
    before = Path(record["originalHeader"]).read_text()
    after = (candidate / "ps2_runtime_macros.h").read_text()

    def helpers(source):
        return source[source.index("static inline bool Ps2FastRangeIsContiguous"):
                      source.index("#define FAST_READ8")]

    out = candidate / "native-check"
    out.mkdir(exist_ok=False)
    source = r"""
#include <cstdint>
#include <cstring>
#include <immintrin.h>
#include <iostream>
#include <vector>
#include <random>
#define PS2_RAM_SIZE (32u*1024u*1024u)
#define PS2_RAM_MASK (PS2_RAM_SIZE-1u)
#define REO_MEMORY_NOINLINE __attribute__((noinline))
"""
    source += "\nnamespace baseline {\n" + helpers(before) + "\n}\n"
    source += "\nnamespace candidate {\n" + helpers(after) + "\n}\n"
    source += r"""
int main() {
    std::vector<uint8_t> a(PS2_RAM_SIZE), b(PS2_RAM_SIZE);
    for (size_t i=0;i<a.size();++i) a[i]=b[i]=uint8_t(i*37u+19u);
    std::mt19937 rng(0x52454f);
    unsigned checks=0;
"""
    for bits, value_type in ((8, "uint8_t"), (16, "uint16_t"), (32, "uint32_t"),
                             (64, "uint64_t"), (128, "__m128i")):
        source += f"""
    {{
        std::vector<uint32_t> addresses={{0,1,2,15,16,PS2_RAM_SIZE-{bits//8}u,
            PS2_RAM_SIZE-{bits//8}u-1,PS2_RAM_SIZE-1u,PS2_RAM_SIZE,0xffffffffu}};
        for(uint32_t delta=0;delta<32;++delta) {{
            addresses.push_back(PS2_RAM_SIZE-delta-1u);
            addresses.push_back((PS2_RAM_SIZE-delta-1u)|0x80000000u);
        }}
        for(unsigned i=0;i<2048;++i) addresses.push_back(rng());
        for(uint32_t address:addresses) {{
            auto x=baseline::Ps2FastRead{bits}(a.data(),address);
            auto y=candidate::Ps2FastRead{bits}(b.data(),address);
            if(std::memcmp(&x,&y,sizeof(x))) return 1;
            {value_type} value;
            auto* bytes=reinterpret_cast<uint8_t*>(&value);
            for(size_t i=0;i<sizeof(value);++i) bytes[i]=uint8_t(rng());
            baseline::Ps2FastWrite{bits}(a.data(),address,value);
            candidate::Ps2FastWrite{bits}(b.data(),address,value);
            x=baseline::Ps2FastRead{bits}(a.data(),address);
            y=candidate::Ps2FastRead{bits}(b.data(),address);
            if(std::memcmp(&x,&y,sizeof(x))||std::memcmp(&x,&value,sizeof(x))) return 2;
            ++checks;
        }}
        if(a!=b) return 3;
    }}
"""
    source += 'std::cout<<"PASS memory boundary/random cases="<<checks<<"\\n";}\n'
    cpp = out / "compare.cpp"
    cpp.write_text(source)
    paths = json.loads((repo / "build-ninja/import-profile-20261020/paths.json").read_text())
    root = Path(paths["compiler"])
    compiler = root / "bin/x86_64-w64-mingw32-clang++.exe"
    command = [str(compiler), "-O2", "-std=c++20", "-msse4.1", "-fno-fast-math",
               "-ffp-contract=off", "-fwrapv", "-fno-strict-aliasing",
               str(cpp), "-o", str(out / "compare.exe")]
    subprocess.run(command, check=True)
    for name in ("libc++.dll", "libunwind.dll", "libwinpthread-1.dll"):
        shutil.copyfile(root / "x86_64-w64-mingw32/bin" / name, out / name)
    result = subprocess.run([str(out / "compare.exe")], capture_output=True, text=True, check=True)
    (out / "result.json").write_text(json.dumps({
        "gameExecuted": False, "stdout": result.stdout, "exit": result.returncode,
        "command": command, "compiler": str(compiler),
    }, indent=2))
    print(result.stdout, end="")


if __name__ == "__main__":
    main()
