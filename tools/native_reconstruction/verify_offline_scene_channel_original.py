"""Original admission/receipt gates for the native offline channel5 owner."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists();out.mkdir(parents=True)
    cc=Path(os.environ['LOCALAPPDATA'])/'OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe'
    elf=ROOT/'game_data/SLUS_207.65';o2=ROOT/'build-function-index/owned-overlays/o2.bin';o9=ROOT/'build-function-index/owned-overlays/o9.bin'
    assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    assert sha(o2)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    assert sha(o9)=='604126d6edca1b1333948d79d1d2c8d2f2e22f4a233efbdfb769c106dafe7343'
    raw2=o2.read_bytes();raw9=o9.read_bytes();read_main=elf_reader(elf.read_bytes());audits=[];sources=[];bodies=[];dispatch=[]
    executed={0x811190,0x810ae0,0x67dd40,0x570370,0x5703a0,0x1b0310}
    for at in sorted(executed|{0x810080,0x810200,0x810550,0x810960,0x810880}):
        family='o9' if at>=0x810000 else 'o2' if at>=0x570000 else 'sub';directory=f'recomp/config/output_ovl/{family}' if family!='sub' else 'recomp/config/output'
        source=ROOT/directory/f'{family}_{at:08X}_0x{at:x}.cpp';body=source.read_text();end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',body)[1],16)
        read=(lambda address,size:raw9[address-0x810000:address-0x810000+size]) if family=='o9' else (lambda address,size:raw2[address-0x570000:address-0x570000+size]) if family=='o2' else read_main
        audits.append(compare_source('offline channel5 '+('executed body' if at in executed else 'lifecycle/framing source audit'),source.relative_to(ROOT).as_posix(),at,end,read))
        if at in executed:sources.append(source);bodies.append(body);dispatch.append(f'case 0x{at:x}:return {source.stem}(memory,context,runtime);')
    ref=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';(out/'reference.hpp').write_text(ref.read_text().replace('Register r[32];','std::uint64_t lo{},hi{};Register r[32];')+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define SRA32(v,n) (std::bit_cast<std::int32_t>(std::uint32_t(v)) >> (n))\n')
    names={x.stem for x in sources};called=set(re.findall(r'\b((?:sub|o2|o9)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram','\n'.join(bodies)))
    declarations=''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for n in sorted(names))
    declarations+=''.join('inline void '+n+'(std::uint8_t*m,R5900Context*c,PS2Runtime*r){original_transform_port(m,c,r);}\n' for n in sorted(called-names))
    (out/'functions.h').write_text('#pragma once\n'+declarations);(out/'original.cpp').write_text('\n'.join(bodies));(out/'original_dispatch.inc').write_text('\n'.join(dispatch))
    for n in ('ps2_runtime.h','ps2_runtime_macros.h'):(out/n).write_text('#pragma once\n#include "reference.hpp"\n')
    for n in ('ps2_recompiled_functions.h','o2_functions.h','o9_functions.h'):(out/n).write_text('#pragma once\n#include "functions.h"\n')
    for n in ('ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h'):(out/n).write_text('#pragma once\n')
    fixture=ROOT/'tools/native_reconstruction/offline_scene_channel_original.cpp';inputs=[elf,o2,o9,ref,fixture,Path(__file__),*sources];before={str(x):sha(x) for x in inputs}
    env=dict(os.environ,PATH=str(cc.parent)+os.pathsep+os.environ.get('PATH',''));command=[str(cc),'-std=c++20','-O1','-msse4.1','-I'+str(out),str(fixture),str(out/'original.cpp'),'-o',str(out/'checks.exe')]
    record=dict(status='failed',source_audits=audits,inputs_sha256=before,scope='Complete original admission and channel5 owner receipt. Debug flags return0;810960 framing/queue is observed, and lifecycle/framing bodies are source-audited separately. Native queue/frame integration has separate application tests.',game_run=False)
    try:
        done=subprocess.run(command,env=env,capture_output=True,text=True,timeout=180);(out/'compile.stderr').write_text(done.stderr);assert done.returncode==0,done.stderr[-2000:]
        run=subprocess.run([str(out/'checks.exe'),str(o2),str(o9)],env=env,capture_output=True,text=True,timeout=120);(out/'stdout.txt').write_text(run.stdout);(out/'stderr.txt').write_text(run.stderr);assert run.returncode==0,run.stderr
        assert all(sha(Path(x))==h for x,h in before.items());record.update(status='passed',observed=json.loads(run.stdout),executable_sha256=sha(out/'checks.exe'))
    finally:(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps(dict(status=record['status'],observed=record.get('observed'))))
if __name__=='__main__':main()
