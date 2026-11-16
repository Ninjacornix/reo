"""Execute complete 663190 with its complete 3700C0/370100 helpers and capture terminal query calls."""
import argparse, hashlib, json, os, re, subprocess, time
from pathlib import Path
from audit_retail_effect_descriptors import compare_source

ROOT=Path(__file__).resolve().parents[2]
O0_SHA="bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2"
O2_SHA="45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226"
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()

def body(address,bank,base):
    source=ROOT/f"recomp/config/output_ovl/{bank}/{bank}_{address:08X}_0x{address:x}.cpp"
    text=source.read_text(encoding="utf-8")
    end=int(re.search(r"// Address: 0x[\da-fA-F]+ - 0x([\da-fA-F]+)",text)[1],16)
    raw=(ROOT/f"build-function-index/owned-overlays/{bank}.bin").read_bytes()
    audit=compare_source("663190 complete query-call oracle",source.relative_to(ROOT).as_posix(),address,end,
        lambda at,n:raw[at-base:at-base+n])
    return source,text[text.index("// Function:"):],audit

def main():
    p=argparse.ArgumentParser();p.add_argument("--output",type=Path,required=True);a=p.parse_args()
    out=a.output.resolve();allowed=(ROOT/"build-native-sjuni").resolve()
    if out.exists() or not out.is_relative_to(allowed):raise ValueError("output must be a fresh folder under build-native-sjuni")
    o0=ROOT/"build-function-index/owned-overlays/o0.bin";o2=ROOT/"build-function-index/owned-overlays/o2.bin"
    if (sha(o0),sha(o2))!=(O0_SHA,O2_SHA):raise ValueError("pinned owned overlays changed")
    entries=[(0x663190,"o2",0x570000),(0x3700c0,"o0",0x370000),(0x370100,"o0",0x370000)]
    sources=[];bodies=[];audits=[]
    for address,bank,base in entries:
        source,source_body,audit=body(address,bank,base)
        if address==0x663190:
            source_body=source_body.replace("o2_005DC570_0x5dc570(rdram, ctx, runtime);","runtime->lookupFunction(0x5dc570u)(rdram,ctx,runtime);")
            source_body=source_body.replace("o2_005DCA90_0x5dca90(rdram, ctx, runtime);","runtime->lookupFunction(0x5dca90u)(rdram,ctx,runtime);")
        sources.append(source);bodies.append(source_body);audits.append(audit)
    header=(ROOT/"tools/native_reconstruction/gameplay_collision_oracle/response_reference.hpp").read_text(encoding="utf-8")
    header=header.replace("bool hasFunction(std::uint32_t)const{return false;}","bool hasFunction(std::uint32_t at)const{return at==0x5dc570u||at==0x5dca90u;}")
    start=header.index("inline PS2Runtime::Fn PS2Runtime::lookupFunction")
    end=header.index("\n}",start)+2
    declarations="""\nvoid query_capture(std::uint8_t*,R5900Context*,PS2Runtime*);\nvoid sine_port(std::uint8_t*,R5900Context*,PS2Runtime*);\nvoid cosine_port(std::uint8_t*,R5900Context*,PS2Runtime*);\nvoid o2_00663190_0x663190(std::uint8_t*,R5900Context*,PS2Runtime*);\nvoid o0_003700C0_0x3700c0(std::uint8_t*,R5900Context*,PS2Runtime*);\nvoid o0_00370100_0x370100(std::uint8_t*,R5900Context*,PS2Runtime*);\ninline PS2Runtime::Fn PS2Runtime::lookupFunction(std::uint32_t at)const{switch(at){case 0x5dc570u:case 0x5dca90u:return query_capture;case 0x3700c0u:return o0_003700C0_0x3700c0;case 0x370100u:return o0_00370100_0x370100;case 0x192190u:return sine_port;case 0x1921a0u:return cosine_port;default:throw std::runtime_error(\"Unexpected actor query oracle call\");}}\n"""
    header=header[:start]+declarations
    out.mkdir(parents=True);(out/"trace_reference.hpp").write_text(header,encoding="utf-8")
    test=ROOT/"tools/native_reconstruction/actor_query_original_tests.cpp"
    generated=out/"original.cpp";generated.write_text('#include "trace_reference.hpp"\n'+"\n".join(bodies)+"\n"+test.read_text(encoding="utf-8"),encoding="utf-8")
    image=bytearray(0x500000);image[0x370000:0x370000+len(o0.read_bytes())]=o0.read_bytes();image_path=out/"owned-overlay-memory.bin";image_path.write_bytes(image)
    compiler=Path(os.environ["LOCALAPPDATA"])/"OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe"
    current=[test,*sources,o0,o2]
    before={str(path.relative_to(ROOT)):sha(path) for path in current}
    exe=out/"actor-query.exe"
    command=[str(compiler),"-std=c++20","-O2","-Wall","-Wextra","-Wpedantic","-Werror","-Wno-unused-parameter","-Wno-unused-variable","-fno-fast-math","-ffp-contract=off","-I"+str(out),"-I"+str(ROOT),"-I"+str(ROOT/"tools/native_reconstruction/gameplay_collision_oracle"),str(generated),"-o",str(exe)]
    env=dict(os.environ,PATH=str(compiler.parent)+os.pathsep+os.environ.get("PATH",""))
    record={"schema":1,"status":"failed","game_launched":False,"source_word_audits":audits,"pinned_overlay_sha256":{"o0":O0_SHA,"o2":O2_SHA},"math_boundary_ports":["192190 sine","1921A0 cosine"],"command":command,"runs":[]}
    for label,cmd in (("compile",command),("run",[str(exe),str(image_path)])):
        began=time.monotonic();result=subprocess.run(cmd,cwd=ROOT,env=env,text=True,capture_output=True,timeout=180)
        (out/f"{label}.stdout.txt").write_text(result.stdout);(out/f"{label}.stderr.txt").write_text(result.stderr)
        record["runs"].append({"label":label,"returncode":result.returncode,"seconds":time.monotonic()-began})
        print(label,result.returncode,result.stdout[-1200:],result.stderr[-2000:],flush=True)
        if result.returncode:break
    record["source_sha256"]=before;record["source_drift"]=[name for name,digest in before.items() if sha(ROOT/name)!=digest]
    if result.returncode==0 and not record["source_drift"]:record.update(status="passed",observed=json.loads(result.stdout),executable_sha256=sha(exe))
    (out/"receipt.json").write_text(json.dumps(record,indent=2)+"\n")
    return int(record["status"]!="passed")

if __name__=="__main__":raise SystemExit(main())
