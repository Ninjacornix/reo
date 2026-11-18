"""Run the generated complete 5C3FE0 flag-policy body and its native flag helpers."""
import hashlib, json, re, subprocess, os, time
from pathlib import Path
from audit_retail_effect_descriptors import compare_source

ROOT=Path(__file__).resolve().parents[2]
O2_SHA="45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226"
COMPILER_SHA="f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3"
FUNCTIONS=(0x5c3fe0,0x5c4230,0x5703e0,0x570370,0x5703a0,0x5705f0,0x570550,0x5704b0)
QUALIFIED_SOURCES=(
    "game/native/gameplay_application/session_scene_query_effects.cpp",
    "game/native/gameplay_application/session_scene_query_effects.hpp",
    "game/native/gameplay_application/native_session.hpp",
    "game/native/gameplay_application/session_rooms.cpp",
    "game/native/gameplay_application/session_rooms.hpp",
    "game/native/gameplay_scenario/flags.cpp",
    "game/native/gameplay_scenario/flags.hpp",
    "game/native/gameplay_scenario/timed_scene_text.cpp",
    "game/native/gameplay_scenario/timed_scene_text.hpp",
    "game/native/gameplay_scene/records.hpp",
    "game/native/gameplay_scenario/room_scene_input.cpp",
)

def sha(path): return hashlib.sha256(Path(path).read_bytes()).hexdigest()

def main():
    import argparse
    p=argparse.ArgumentParser();p.add_argument("--output",type=Path,required=True)
    p.add_argument("--snapshot",type=Path,required=True);a=p.parse_args()
    out=a.output.resolve();base=(ROOT/"build-native-sjuni").resolve()
    if out.exists() or not out.is_relative_to(base): raise ValueError("output must be a fresh directory under build-native-sjuni")
    snapshot=a.snapshot.resolve();receipt=json.loads((snapshot/"receipt.json").read_text())
    if receipt.get("status")!="passed":raise ValueError("native archive snapshot is not passed")
    for name in QUALIFIED_SOURCES:
        digest=receipt["source_sha256"][name]
        if sha(snapshot/"source"/name)!=digest:raise ValueError(f"snapshot source hash mismatch: {name}")
    for name,digest in receipt["archives_sha256"].items():
        if sha(snapshot/"native-build"/name)!=digest:raise ValueError(f"native archive hash mismatch: {name}")
    overlay=ROOT/"build-function-index/owned-overlays/o2.bin";raw=overlay.read_bytes()
    if sha(overlay)!=O2_SHA: raise ValueError("owned O2 overlay hash mismatch")
    bodies=[];audits=[];names=[];files=[]
    for address in FUNCTIONS:
        source=next((ROOT/"recomp/config/output_ovl/o2").glob(f"o2_{address:08X}_*.cpp"))
        text=source.read_text(encoding="utf-8");end=int(re.search(r"// Address: 0x[\da-f]+ - 0x([\da-f]+)",text)[1],16)
        audits.append(compare_source(f"complete policy body/helper 0x{address:x}",source.relative_to(ROOT).as_posix(),address,end,
                                     lambda at,n:raw[at-0x570000:at-0x570000+n]))
        body=text[text.index("// Function:"):]
        body=re.sub(r"o[02]_([0-9A-Fa-f]{8})_0x([0-9a-f]+)\(rdram, ctx, runtime\);",
                    lambda m:f"runtime->lookupFunction(0x{m.group(2)}u)(rdram,ctx,runtime);",body)
        bodies.append(body);names.append(source.stem);files.append(source)
    test=ROOT/"tools/native_reconstruction/scene_flag_policy_original_tests.cpp"
    reference=(ROOT/"tools/native_reconstruction/gameplay_collision_oracle/reference.hpp").read_text(encoding="utf-8")
    start=reference.index("inline PS2Runtime::Fn PS2Runtime::lookupFunction")
    end=reference.index("\n}",start)+2
    reference=reference[:start]+reference[end:]
    reference+="\n#define SRL32(a,b) (std::uint32_t(a)>>(b))\n"
    declarations="\n".join(f"void {name}(std::uint8_t*,R5900Context*,PS2Runtime*);" for name in names)
    mapping={int(re.search(r"_0x([0-9a-f]+)$",n)[1],16):n for n in names}
    lookup="\ninline PS2Runtime::Fn PS2Runtime::lookupFunction(std::uint32_t a)const{switch(a){"
    lookup+="".join(f"case 0x{address:x}:return {name};" for address,name in mapping.items())
    lookup+="case 0x1b02d0:case 0x1b0340:case 0x67dbd0:case 0x570120:return original_port;default:throw std::runtime_error(\"unqualified original call\");}}\n"
    reference+="\nvoid original_port(std::uint8_t*,R5900Context*,PS2Runtime*);\n"+declarations+lookup
    out.mkdir(parents=True);(out/"scene_flag_policy_reference.hpp").write_text(reference,encoding="utf-8")
    (out/"o2_functions.h").write_text('#pragma once\n#include "scene_flag_policy_reference.hpp"\n')
    for n in ("ps2_runtime.h","ps2_runtime_macros.h","ps2_recompiled_stubs.h","ps2_syscalls.h","ps2_stubs.h"):
        (out/n).write_text('#pragma once\n#include "scene_flag_policy_reference.hpp"\n' if n in ("ps2_runtime.h","ps2_runtime_macros.h") else "#pragma once\n")
    generated=out/"original_and_checks.cpp"
    generated.write_text('#include "scene_flag_policy_reference.hpp"\n'+'\n'.join(bodies)+'\n'+test.read_text(encoding="utf-8"),encoding="utf-8")
    local=Path(os.environ["LOCALAPPDATA"])/"OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe"
    if sha(local)!=COMPILER_SHA: raise ValueError("pinned LLVM compiler hash mismatch")
    out.mkdir(exist_ok=True);exe=out/"scene-flag-policy.exe"
    cmd=[str(local),"-std=c++20","-O2","-Wall","-Wextra","-Wpedantic","-Werror","-Wno-unused-parameter","-I"+str(out),"-I"+str(snapshot/"source"),"-I"+str(ROOT),"-I"+str(ROOT/"game/native"),str(generated),"-Wl,--start-group"]
    cmd.extend(str(snapshot/"native-build"/name) for name in receipt["archives_sha256"])
    cmd.extend(["-Wl,--end-group","-lwinmm","-lxinput","-luser32","-lgdi32","-o",str(exe)])
    env=dict(os.environ,PATH=str(local.parent)+os.pathsep+os.environ.get("PATH",""))
    began=time.monotonic();compiled=subprocess.run(cmd,cwd=ROOT,env=env,text=True,capture_output=True,timeout=240)
    (out/"compile.stdout.txt").write_text(compiled.stdout);(out/"compile.stderr.txt").write_text(compiled.stderr)
    audit_summary=[{"path":x["path"],"start":x["start"],"end_exclusive":x["end_exclusive"],"matched_comments":x["matched_comments"],"omitted_zero_words":x["omitted_zero_words"],"conflicts":x["conflicts"]} for x in audits]
    result={"status":"failed","snapshot":str(snapshot.relative_to(ROOT)),"snapshot_receipt_sha256":sha(snapshot/"receipt.json"),"original_word_audits":audit_summary,"compiler_sha256":sha(local),"compile_command":cmd,"compile_seconds":time.monotonic()-began,"game_run":False}
    if compiled.returncode==0:
        run=subprocess.run([str(exe)],cwd=ROOT,env=env,text=True,capture_output=True,timeout=120)
        (out/"run.stdout.txt").write_text(run.stdout);(out/"run.stderr.txt").write_text(run.stderr)
        result.update(run_returncode=run.returncode,run_stdout=run.stdout,run_stderr=run.stderr)
        if run.returncode==0:result["status"]="passed"
    else:result.update(compile_returncode=compiled.returncode,compile_stderr=compiled.stderr[-4000:])
    (out/"receipt.json").write_text(json.dumps(result,indent=2)+"\n")
    print(json.dumps(result,indent=2));return int(result["status"]!="passed")

if __name__=="__main__":raise SystemExit(main())
