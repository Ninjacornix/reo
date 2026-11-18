"""Recover complete character event schedules as typed native selector tables."""
import argparse,hashlib,json,os,re,subprocess,sys
from collections import defaultdict
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source
from extract_player_schedules import NAMES,render
NAMES[0x595eb0]='character_callback'
import extract_player_schedules as common
common.CONDITIONS[0x103]='ctx.actor.secondary == 15'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def tree(traces):
    if all(not t for t in traces):return ()
    assert all(traces)
    heads=[t[0] for t in traces];first=heads[0]
    if first[0]==0x103:
        assert all(x[0]==0x103 and x[1]==0 and x[2] in (0,1) and x[3:]==(0,0) for x in heads)
        branches=[tree([t[1:] for t in traces if t[0][2]==b]) for b in (0,1)]
        return (('if',0x103,branches[1],branches[0]),)
    assert all(x==first for x in heads),heads
    return (first,)+tree([t[1:] for t in traces])
def main():
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);args=p.parse_args();out=args.output.resolve();out.mkdir(parents=True,exist_ok=False)
    compiler=Path(os.environ['LOCALAPPDATA'])/'OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe'
    assert sha(compiler)=='f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3'
    image=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(image)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=image.read_bytes()
    entries=[0x5ec3e0,0x5baff0,0x5bb480,0x5bb780,0x5bbad0,0x5ec7a0,0x5bbfa0,0x5bc380]
    sources=[ROOT/f'recomp/config/output_ovl/o2/o2_{entry:08X}_0x{entry:x}.cpp' for entry in entries];audits=[]
    for entry,source in zip(entries,sources):
        end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',source.read_text())[1],16)
        audits.append(compare_source('Complete character event schedule',source.relative_to(ROOT).as_posix(),entry,end,lambda at,n:raw[at-0x570000:at-0x570000+n]))
    reference=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    fixture=Path(__file__).with_name('character_schedule_extract.cpp')
    inputs=[*sources,reference,fixture,Path(__file__).resolve(),Path(common.__file__).resolve(),ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h']
    before={p.relative_to(ROOT).as_posix():sha(p) for p in inputs}
    (out/'reference.hpp').write_bytes(reference.read_bytes());(out/'extract.cpp').write_bytes(fixture.read_bytes())
    body='\n'.join(p.read_text() for p in sources);(out/'original.cpp').write_text(body)
    actual={p.stem for p in sources};calls=set(re.findall(r'\b(o2_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body))
    declarations=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for name in sorted(actual))
    declarations+=''.join('inline void '+name+'(std::uint8_t*m,R5900Context*c,PS2Runtime*r){original_transform_port(m,c,r);}\n' for name in sorted(calls-actual));(out/'functions.h').write_text(declarations)
    for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
    for name in ['o2_functions.h','ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h']:(out/name).write_text('#pragma once\n')
    env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','');exe=out/'extract.exe'
    command=[str(compiler),'-std=c++20','-O2','-msse4.1','-fno-fast-math','-ffp-contract=off','-I'+str(out),str(out/'extract.cpp'),'-o',str(exe)]
    result=dict(status='failed',compiler_sha256=sha(compiler),input_sha256=before,original_word_audits=audits,game_run=False)
    run=subprocess.run(command,env=env,capture_output=True,text=True,timeout=120);(out/'compile.txt').write_text(run.stdout+run.stderr);result['compile_command']=command
    try:
        assert run.returncode==0,'compile failed'
        with (out/'traces.txt').open('w') as stream:run=subprocess.run([str(exe),str(image)],env=env,stdout=stream,stderr=subprocess.PIPE,text=True,timeout=120)
        (out/'extract.stderr.txt').write_text(run.stderr);assert run.returncode==0,run.stderr
        result['observed']=json.loads(run.stderr);assert result['observed']['original_calls']==8*2*65536*2
        families=defaultdict(lambda:defaultdict(lambda:[(),()]))
        for line in (out/'traces.txt').read_text().splitlines():
            parts=line.split();family,selector,variant=map(int,parts[:3]);families[family][selector][variant]=tuple(tuple(map(int,x.split(','))) for x in parts[3:])
        functions=[];groups={}
        for family in range(16):
            name=f'character_{family//2}_{"upper" if family%2==0 else "lower"}';buckets=defaultdict(list)
            for selector,traces in families[family].items():buckets[tree(traces)].append(selector)
            lines=[f'void {name}(Context& ctx, std::uint16_t selector) {{','    (void)ctx;','    switch (selector) {']
            for body,selectors in buckets.items():
                for selector in selectors:lines.append(f'    case {selector}:')
                lines+=render(body,'        ');lines.append('        return;')
            lines+=['    default:return;','    }','}'];functions.append('\n'.join(lines));groups[name]=len(buckets)
        (out/'character_event_schedule.inc').write_text('// Recovered from eight complete owned character event bodies.\n// First read: upper selector; fresh second read: lower selector.\n'+'\n\n'.join(functions)+'\n')
        result['source_drift']=[name for name,value in before.items() if sha(ROOT/name)!=value];assert not result['source_drift']
        result.update(status='passed',groups=groups,schedule_sha256=sha(out/'character_event_schedule.inc'))
    finally:(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps({key:result[key] for key in ('status','observed','groups')}))
if __name__=='__main__':main()
