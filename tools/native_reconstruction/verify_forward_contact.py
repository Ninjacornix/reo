"""Compare native 65F4A0 against its owned generated body and geometry helpers."""
import argparse, hashlib, json, os, re, struct, subprocess
from pathlib import Path

from audit_retail_effect_descriptors import compare_source, elf_reader
from verify_gameplay_collision import COMPILERS

ROOT = Path(__file__).resolve().parents[2]
ELF_SHA = "06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46"
O0_SHA = "bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2"
O2_SHA = "45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226"
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()

def source_for(address):
    if address < 0x370000:
        folder, prefix = ROOT / "recomp/config/output", "sub"
    elif address < 0x570000:
        folder, prefix = ROOT / "recomp/config/output_ovl/o0", "o0"
    else:
        folder, prefix = ROOT / "recomp/config/output_ovl/o2", "o2"
    matches = list(folder.glob(f"{prefix}_{address:08X}_*.cpp"))
    if len(matches) != 1:
        raise ValueError(f"Expected one generated source for {address:#x}, got {len(matches)}")
    path = matches[0]
    text = path.read_text(encoding="utf-8")
    end = int(re.search(r"// Address: 0x[\da-fA-F]+ - 0x([\da-fA-F]+)", text)[1], 16)
    return path, text, end

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--compiler", choices=COMPILERS, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    out = args.output.resolve()
    allowed = (ROOT / "build-native-sjuni").resolve()
    if out.exists() or not out.is_relative_to(allowed):
        raise ValueError("Output must be a fresh private directory under build-native-sjuni")

    elf = ROOT / "game_data/SLUS_207.65"
    o0 = ROOT / "build-function-index/owned-overlays/o0.bin"
    o2 = ROOT / "build-function-index/owned-overlays/o2.bin"
    if (sha(elf), sha(o0), sha(o2)) != (ELF_SHA, O0_SHA, O2_SHA):
        raise ValueError("Pinned executable/overlay inputs changed")
    elf_data, o0_data, o2_data = elf.read_bytes(), o0.read_bytes(), o2.read_bytes()
    elf_read = elf_reader(elf_data)
    banks = {"sub": (elf_read, 0), "o0": (lambda at, n: o0_data[at-0x370000:at-0x370000+n], 0x370000),
             "o2": (lambda at, n: o2_data[at-0x570000:at-0x570000+n], 0x570000)}
    addresses = [0x65F4A0, 0x3700C0, 0x370100, 0x5795E0, 0x579730, 0x579140,
                 0x579300, 0x617430, 0x6175C0, 0x616CC0, 0x6161E0, 0x619A50,
                 0x370FE0, 0x370AC0, 0x370B00, 0x370C70, 0x191EF0]
    entries, bodies, audits = {}, [], []
    for address in addresses:
        path, text, end = source_for(address)
        image = "sub" if address < 0x370000 else "o0" if address < 0x570000 else "o2"
        audits.append(compare_source("65F4A0 source closure", path.relative_to(ROOT).as_posix(),
                                     address, end, banks[image][0]))
        entries[address] = path.stem
        bodies.append(text[text.index("// Function:"):])

    out.mkdir(parents=True)
    base = ROOT / "tools/native_reconstruction/gameplay_collision_oracle/response_reference.hpp"
    header = base.read_text(encoding="utf-8")
    decls = "\n".join(f"void {entries[a]}(std::uint8_t*,R5900Context*,PS2Runtime*);" for a in addresses)
    header = header.replace("#pragma once", "#pragma once\n#include <vector>\n#include <span>\n#include <string>\n#include \"game/native/transform_math/transform_math.hpp\"", 1)
    header = header.replace("bool hasFunction(std::uint32_t)const{return false;}",
                            "bool hasFunction(std::uint32_t at)const{return at==0x192100u||at==0x192190u||at==0x1921a0u;}")
    header = header.replace("inline PS2Runtime::Fn PS2Runtime::lookupFunction(std::uint32_t at)const{",
                            "inline void forward_port_acos(std::uint8_t*,R5900Context* c,PS2Runtime*){c->f[0]=std::acos(c->f[12]);c->pc=GPR_U32(c,31);}\ninline void forward_port_sin(std::uint8_t*,R5900Context* c,PS2Runtime*){c->f[0]=reo::native::transform_math::sin_cos(c->f[12]).sine;c->pc=GPR_U32(c,31);}\ninline void forward_port_cos(std::uint8_t*,R5900Context* c,PS2Runtime*){c->f[0]=reo::native::transform_math::sin_cos(c->f[12]).cosine;c->pc=GPR_U32(c,31);}\ninline PS2Runtime::Fn PS2Runtime::lookupFunction(std::uint32_t at)const{")
    header = header.replace("inline PS2Runtime::Fn PS2Runtime::lookupFunction(std::uint32_t at)const{",
                            decls + "\ninline R5900Context context(std::uint32_t pc){R5900Context c{};c.pc=pc;SET_GPR_U32(&c,29,0x7f0000);SET_GPR_U32(&c,31,0xabcdef);return c;}\ninline PS2Runtime::Fn PS2Runtime::lookupFunction(std::uint32_t at)const{")
    existing_cases = {int(value,16) for value in re.findall(r"case 0x([0-9a-fA-F]+):", base.read_text(encoding="utf-8"))}
    cases = "".join(f"case 0x{a:x}:return {entries[a]};" for a in addresses if a not in existing_cases)
    header = header.replace("case 0x619a50:return o2_00619A50_0x619a50;",
                            "case 0x619a50:return o2_00619A50_0x619a50;case 0x192100:return forward_port_acos;case 0x192190:return forward_port_sin;case 0x1921a0:return forward_port_cos;")
    header = header.replace("default:throw std::runtime_error(\"Undeclared response oracle call\");", cases + "default:throw std::runtime_error(\"Undeclared forward-contact oracle call \"+std::to_string(at));")
    (out / "trace_reference.hpp").write_text(header, encoding="utf-8")
    (out / "original.cpp").write_text('#include "trace_reference.hpp"\n#pragma GCC diagnostic ignored "-Wunused-variable"\n' + "\n".join(bodies), encoding="utf-8")

    memory = bytearray(0x800000)
    phoff = struct.unpack_from("<I", elf_data, 28)[0]
    entsize, count = struct.unpack_from("<HH", elf_data, 42)
    for i in range(count):
        kind, offset, va, _, size = struct.unpack_from("<5I", elf_data, phoff + i * entsize)
        if kind == 1 and va + size <= len(memory):
            memory[va:va+size] = elf_data[offset:offset+size]
    memory[0x370000:0x370000+len(o0_data)] = o0_data
    memory[0x570000:0x570000+len(o2_data)] = o2_data
    image = out / "original-rdram.bin"
    image.write_bytes(memory)

    compiler = COMPILERS[args.compiler]
    native = [ROOT / p for p in ["game/native/gameplay_collision/collision.cpp",
        "game/native/gameplay_collision/response.cpp", "game/native/gameplay_collision/trace.cpp",
        "game/native/gameplay_world/forward_contact.cpp", "game/native/transform_math/transform_math.cpp"]]
    test = ROOT / "tools/native_reconstruction/forward_contact_original_tests.cpp"
    exe = out / "forward-contact.exe"
    command = [str(compiler), "-std=c++20", "-O2", "-Wall", "-Wextra", "-Wpedantic", "-Werror",
        "-Wno-unused-parameter", "-fno-fast-math", "-ffp-contract=off", "-I"+str(ROOT), "-I"+str(ROOT/"tools/native_reconstruction/gameplay_collision_oracle"), "-I"+str(out),
        *map(str, native), str(test), str(out/"original.cpp"), "-o", str(exe)]
    env = dict(os.environ, PATH=str(compiler.parent)+os.pathsep+os.environ.get("PATH", ""))
    record = {"schema":1,"status":"failed","game_launched":False,"source_word_audits":audits,
              "pinned_inputs":{"elf_sha256":ELF_SHA,"o0_sha256":O0_SHA,"o2_sha256":O2_SHA},
              "math_ports":["192100 acos via std::acos","192190 sine via the independently qualified native transform_math::sin_cos","1921A0 cosine via the independently qualified native transform_math::sin_cos"],
              "command":command,"checks":[]}
    try:
        for label, cmd in [("compile",command),("run",[str(exe),str(image)])]:
            result = subprocess.run(cmd,capture_output=True,env=env,timeout=300)
            (out/(label+".stdout.txt")).write_bytes(result.stdout)
            (out/(label+".stderr.txt")).write_bytes(result.stderr)
            record["checks"].append({"label":label,"exit_code":result.returncode,"command":cmd})
            if result.returncode:
                raise RuntimeError(label+" failed: "+result.stderr.decode(errors="replace")[-4000:])
            if label == "run": record["results"] = json.loads(result.stdout)
        record["status"] = "passed"
    finally:
        record["source_sha256"] = {str(p.relative_to(ROOT)):sha(p) for p in [test,*native,base,Path(__file__)]}
        (out/"receipt.json").write_text(json.dumps(record,indent=2)+"\n",encoding="utf-8")
    print(json.dumps(record["results"]))

if __name__ == "__main__":
    main()
