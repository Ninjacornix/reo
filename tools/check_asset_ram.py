"""Compile the actual CPU memory helpers and check both native backing sizes."""
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / "build-ninja" / "asset-ram-check"
OUT.mkdir(exist_ok=True)
header = (ROOT / "third_party/PS2Recomp/ps2xRuntime/include/ps2_runtime_macros.h").read_text()
helpers = header[header.index("static inline bool Ps2FastRangeIsContiguous"):
                 header.index("#define FAST_READ8")]
source = '''#include "runtime/ps2_memory.h"
#include <cstring>
#include <iostream>
#include <random>
'''+helpers+'''
int main() {
    std::mt19937 random(78124);
    unsigned checks=0;
    for(uint32_t size: {PS2_RAM_SIZE, 2u*PS2_RAM_SIZE}) {
        ps2RamBackingBytes=size;
        std::vector<uint8_t> actual(size), expected(size);
        for(uint32_t i=0;i<size;++i) actual[i]=expected[i]=uint8_t(i*37+19);
'''
for bits, kind in [(8, "uint8_t"), (16, "uint16_t"), (32, "uint32_t"), (64, "uint64_t"), (128, "__m128i")]:
    source += f'''
        for(unsigned n=0;n<6000;++n) {{
            uint32_t address=n<64 ? size-32+n : random();
            if(n>=64 && n<128) address=PS2_RAM_SIZE-32+n-64;
            {kind} value, reference;
            auto* bytes=reinterpret_cast<uint8_t*>(&reference);
            for(unsigned i=0;i<sizeof(value);++i) bytes[i]=expected[(uint64_t(address)+i)%size];
            value=Ps2FastRead{bits}(actual.data(),address);
            if(std::memcmp(&value,&reference,sizeof(value))) return 1;
            for(unsigned i=0;i<sizeof(value);++i) bytes[i]=uint8_t(random());
            Ps2FastWrite{bits}(actual.data(),address,reference);
            for(unsigned i=0;i<sizeof(value);++i) expected[(uint64_t(address)+i)%size]=bytes[i];
            ++checks;
        }}
        if(actual!=expected) return 2;
'''
source += '''
        for(uint32_t bank:{0u,0x20000000u,0x80000000u,0xa0000000u}) {
            uint32_t offset=0;bool scratch=true;
            ps2ResolveGuestPointer(bank+0x02001234u,offset,scratch);
            if(scratch || offset!=(0x02001234u%size)) return 3;
            ++checks;
        }
    }
    ps2RamBackingBytes=PS2_RAM_SIZE;
    std::cout << "PASS asset RAM: " << checks << " boundary, alias and random read/write checks\\n";
}
'''
(OUT / "check.cpp").write_text(source)
(OUT / "build.cmd").write_text(f'''@echo off
call "{ROOT / 'tools/vcvars64.bat'}" >nul
if errorlevel 1 exit /b 1
cl /nologo /std:c++20 /EHsc /O2 /I "{ROOT / 'third_party/PS2Recomp/ps2xRuntime/include'}" "{OUT / 'check.cpp'}" /Fo"{OUT / 'check.obj'}" /Fe"{OUT / 'check.exe'}"
if errorlevel 1 exit /b 1
"{OUT / 'check.exe'}"
''')
subprocess.run(["cmd", "/c", str(OUT / "build.cmd")], cwd=ROOT, check=True)
