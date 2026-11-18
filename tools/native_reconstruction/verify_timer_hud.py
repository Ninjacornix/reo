"""Complete original5BA530/5BA8D0 CPU countdown/pulse/sprite comparison."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def main():
    parser=argparse.ArgumentParser();parser.add_argument('--compiler',choices=COMPILERS,required=True);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
    out=args.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
    overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=overlay.read_bytes()
    sources=[next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*'))for at in [0x5ba530,0x5ba8d0]];audits=[]
    for source in sources:
        start,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',source.read_text()).groups()]
        audits.append(compare_source('complete original HUD CPU callback/sprite body',source.relative_to(ROOT).as_posix(),start,end,lambda at,n:raw[at-0x570000:at-0x570000+n]))
    native=ROOT/'game/native/gameplay_scenario/timer_hud.cpp';fixture=ROOT/'tools/native_reconstruction/timer_hud_tests.cpp';reference=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    paths=[*sources,native,native.with_suffix('.hpp'),fixture,reference,Path(__file__).resolve()];before={p.relative_to(ROOT).as_posix():sha(p)for p in paths}
    for name in before:
        target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
    (out/'reference.hpp').write_text(reference.read_text().replace('Register r[32];','std::uint64_t lo{},hi{},lo1{},hi1{};Register r[32];')+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n')
    body='\n'.join(p.read_text()for p in sources);(out/'original.cpp').write_text(body)
    actual={p.stem for p in sources};called=set(re.findall(r'\b((?:sub|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body))
    decl=''.join(f'void {name}(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual))
    decl+=''.join(f'inline void {name}(std::uint8_t* m,R5900Context* c,PS2Runtime* r){{original_transform_port(m,c,r);}}\n'for name in sorted(called-actual))
    (out/'functions.h').write_text('#pragma once\n'+decl)
    (out/'original_dispatch.hpp').write_text(''.join(f'case {hex(at)}:{source.stem}(memory,context,runtime);return;\n'for at,source in zip([0x5ba530,0x5ba8d0],sources)))
    for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
    (out/'o2_functions.h').write_text('#pragma once\n#include "functions.h"\n')
    for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
    tables=out/'tables.bin';tables.write_bytes(raw[0x70a1e0-0x570000:0x70a230-0x570000]);compiler=COMPILERS[args.compiler]
    env=dict(os.environ,PATH=str(compiler.parent)+os.pathsep+os.environ.get('PATH',''));exe=out/'checks.exe'
    command=[str(compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),str(out/'source'/native.relative_to(ROOT)),str(out/'source'/fixture.relative_to(ROOT)),'-o',str(exe)]
    receipt=dict(schema='reo.native.timer_hud.v1',status='failed',source_sha256=before,compiler_sha256=sha(compiler),original_word_audits=audits,tables_sha256=sha(tables),
        boundaries=['Renderer resource2500 lookup/opaque translation, blend/material state and final sprite submission are observation ports.','All CPU countdown decomposition, clipping, signed pulse arithmetic and20-byte semantic sprite fields execute through complete owned original bodies.','Negative unowned countdown selectors are native refusals, outside the original comparison profile.'],game_launched=False)
    try:
        for label,cmd in [('compile',command),('run',[str(exe),str(tables)])]:
            result=subprocess.run(cmd,capture_output=True,text=True,env=env,timeout=240);(out/(label+'.txt')).write_text(result.stdout+result.stderr)
            assert result.returncode==0,label+': '+(result.stdout+result.stderr)[-3000:]
            if label=='run':receipt['observed']=json.loads(result.stdout)
        receipt['source_unchanged']=all(sha(ROOT/name)==digest for name,digest in before.items());assert receipt['source_unchanged'];receipt['status']='passed'
    finally:
        receipt['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(receipt['observed']))
if __name__=='__main__':main()
