"""Compare the complete generated64E960/64F2D0 bodies with current native policies.

Calls that belong to already qualified adjacent owners are controlled boundary
ports; both policy bodies execute as generated, including their delay slots.
"""
import argparse, hashlib, json, os, re, shutil, subprocess, time
from pathlib import Path
from audit_retail_effect_descriptors import compare_source

ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
O2_SHA="45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226"
SNAPSHOT=ROOT/"build-native-sjuni/movement-sound-cohort-snapshot-v1"

def main():
    p=argparse.ArgumentParser();p.add_argument("--output",type=Path,required=True);a=p.parse_args()
    out=a.output.resolve();allowed=(ROOT/"build-native-sjuni").resolve()
    if out.exists() or not out.is_relative_to(allowed):raise ValueError("output must be a fresh directory under build-native-sjuni")
    receipt=json.loads((SNAPSHOT/"receipt.json").read_text());assert receipt["status"]=="passed"
    o2=ROOT/"build-function-index/owned-overlays/o2.bin";raw=o2.read_bytes();assert sha(o2)==O2_SHA
    entries=[0x64e960,0x64f2d0];bodies=[];audits=[];sources=[]
    for address in entries:
        source=ROOT/f"recomp/config/output_ovl/o2/o2_{address:08X}_0x{address:x}.cpp"
        text=source.read_text(encoding="utf-8");end=int(re.search(r"// Address: 0x[\da-f]+ - 0x([\da-f]+)",text)[1],16)
        audits.append(compare_source("interaction policy complete-body oracle",source.relative_to(ROOT).as_posix(),address,end,lambda at,n:raw[at-0x570000:at-0x570000+n]))
        body=text[text.index("// Function:"):]
        body=re.sub(r"o[02]_([0-9A-Fa-f]{8})_0x([0-9A-Fa-f]+)\(rdram, ctx, runtime\);",
                    lambda m:f"runtime->lookupFunction(0x{m.group(2)}u)(rdram,ctx,runtime);",body)
        bodies.append(body);sources.append(source)
    base=(ROOT/"tools/native_reconstruction/gameplay_collision_oracle/reference.hpp").read_text(encoding="utf-8")
    start=base.index("inline PS2Runtime::Fn PS2Runtime::lookupFunction")
    end=base.index("\n}",start)+2
    base=base[:start]+base[end:]
    base+="\n#define WRITE16(at,v) ref_write(rdram,at,std::uint16_t(v))\n#define SRA32(v,n) (std::int32_t(v)>>(n))\n"
    base+="\nvoid original_port(std::uint8_t*,R5900Context*,PS2Runtime*);\ninline PS2Runtime::Fn PS2Runtime::lookupFunction(std::uint32_t)const{return original_port;}\n"
    base+="\n".join(f"void o2_{at:08X}_0x{at:x}(std::uint8_t*,R5900Context*,PS2Runtime*);" for at in entries)
    out.mkdir(parents=True);(out/"trace_reference.hpp").write_text(base,encoding="utf-8")
    test=ROOT/"tools/native_reconstruction/interaction_policy_original_tests.cpp"
    generated=out/"original_and_native.cpp";generated.write_text('#include "trace_reference.hpp"\n'+'\n'.join(bodies)+'\n'+test.read_text(encoding="utf-8"),encoding="utf-8")
    compiler=Path(os.environ["LOCALAPPDATA"])/"OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe"
    assert sha(compiler)=="f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3"
    current=[ROOT/"game/native/gameplay_world/interaction_action.cpp",ROOT/"game/native/gameplay_world/control_request_flow.cpp"]
    tracked=sources+[test,o2]+current+[SNAPSHOT/"receipt.json"]
    before={str(x.relative_to(ROOT)):sha(x) for x in tracked}
    exe=out/"interaction-policy.exe"
    command=[str(compiler),"-std=c++20","-O2","-Wall","-Wextra","-Wpedantic","-Werror","-Wno-unused-parameter","-fno-fast-math","-ffp-contract=off",
             "-I"+str(out),"-I"+str(ROOT),"-I"+str(ROOT/"game/native"),str(generated),*map(str,current),
             "-Wl,--start-group",*[str(SNAPSHOT/"native-build"/name) for name in receipt["archives_sha256"]],"-Wl,--end-group",
             "-lwinmm","-lxinput","-luser32","-lgdi32","-o",str(exe)]
    env=dict(os.environ,PATH=str(compiler.parent)+os.pathsep+os.environ.get("PATH",""));result={"status":"failed","snapshot":str(SNAPSHOT.relative_to(ROOT)),"snapshot_receipt_sha256":sha(SNAPSHOT/"receipt.json"),"original_word_audits":audits,"compiler_sha256":sha(compiler),"commands":[],"game_run":False,"stage4_complete":False}
    for label,cmd in [("compile",command),("run",[str(exe)])]:
        began=time.monotonic();run=subprocess.run(cmd,cwd=ROOT,env=env,text=True,capture_output=True,timeout=240)
        (out/(label+".stdout.txt")).write_text(run.stdout);(out/(label+".stderr.txt")).write_text(run.stderr)
        result["commands"].append({"label":label,"command":cmd,"returncode":run.returncode,"seconds":time.monotonic()-began})
        print(label,run.returncode,run.stdout[-1500:],run.stderr[-3000:],flush=True)
        if run.returncode:break
    result["source_sha256"]=before;result["source_drift"]=[n for n,h in before.items() if sha(ROOT/n)!=h]
    if run.returncode==0 and not result["source_drift"]:result.update(status="passed",observed=json.loads(run.stdout),executable_sha256=sha(exe))
    (out/"receipt.json").write_text(json.dumps(result,indent=2)+"\n");return int(result["status"]!="passed")
if __name__=="__main__":raise SystemExit(main())
