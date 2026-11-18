"""Compare actual native World target metrics to admitted complete owned bodies."""
import argparse
import hashlib
import json
import os
import re
import subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def main():
    parser=argparse.ArgumentParser();parser.add_argument('--compiler',choices=COMPILERS,required=True);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
    out=args.output.resolve();assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
    entries={};audits=[];images={}
    for bank,pin,addresses in [('o2','45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226',[0x6d6240,0x6d6d60]),('main','06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46',[0x1b02d0,0x1b0300,0x191d10])]:
        image=ROOT/('game_data/SLUS_207.65' if bank=='main' else f'build-function-index/owned-overlays/{bank}.bin');raw=image.read_bytes();assert sha(image)==pin;images[image.relative_to(ROOT).as_posix()]=pin
        read=elf_reader(raw) if bank=='main' else lambda at,n:raw[at-0x570000:at-0x570000+n]
        for address in addresses:
            folder=ROOT/('recomp/config/output' if bank=='main' else f'recomp/config/output_ovl/{bank}');path=next(folder.glob(f'*_{address:08X}_0x{address:x}.cpp'))
            end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',path.read_text())[1],16)
            name=path.relative_to(ROOT).as_posix();entries[address]=name;audits.append(compare_source('Complete target-metric native comparison body',name,address,end,read))
    helper='tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';fixture='game/native/gameplay_world/target_metrics_tests.cpp'
    units=['game/native/'+group+'/'+name+'.cpp' for group,names in [
        ('gameplay_world',['target_metrics','world','linked_models','auxiliary_actors','scene_primary_actors','model_poses','model_constraints']),
        ('gameplay_actors',['entity','input','health']),('gameplay_navigation',['navigation','bank']),
        ('gameplay_collision',['collision','response','trace']),
        ('animation',['model','model_math','curves','constraints','constraint_math']),('transform_math',['transform_math','heading'])] for name in names]
    files=[helper,fixture,Path(__file__).relative_to(ROOT).as_posix(),*entries.values(),*units,'game/native/gameplay_world/CMakeLists.txt']
    closure=set(files);pending=[ROOT/name for name in files if name not in entries.values()]
    while pending:
        path=pending.pop()
        for name in re.findall(r'#include "([^"\n]+)"',path.read_text()):
            candidate=next((p.resolve() for p in [path.parent/name,ROOT/name] if p.is_file()),None)
            if candidate and candidate.is_relative_to(ROOT):
                relative=candidate.relative_to(ROOT).as_posix()
                if relative not in closure:closure.add(relative);pending.append(candidate)
    frozen={name:(ROOT/name).read_bytes() for name in sorted(closure)};out.mkdir(parents=True)
    for name,data in frozen.items():
        path=out/'source'/name;path.parent.mkdir(parents=True,exist_ok=True);path.write_bytes(data)
    reference=frozen[helper].decode().replace('#include <stdexcept>','#include <stdexcept>\nvoid cache_scratch_read(std::uint32_t,std::size_t);\nvoid cache_scratch_write(std::uint32_t,std::size_t);')
    assert reference.count('std::memcpy(&value,p+at,sizeof value);')==1 and reference.count('std::memcpy(p+at,&value,sizeof value);')==1
    reference=reference.replace('std::memcpy(&value,p+at,sizeof value);','cache_scratch_read(at,sizeof(T));std::memcpy(&value,p+at,sizeof value);').replace('std::memcpy(p+at,&value,sizeof value);','cache_scratch_write(at,sizeof(T));std::memcpy(p+at,&value,sizeof value);')
    (out/'reference.hpp').write_text(reference+'\n#define GPR_S32(c,n) std::bit_cast<std::int32_t>(GPR_U32(c,n))\n')
    body='\n'.join(frozen[name].decode() for name in entries.values());(out/'original.cpp').write_text(body)
    actual={Path(name).stem for name in entries.values()};calls=set(re.findall(r'\b((?:sub|o[0-9]+)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body))
    (out/'functions.h').write_text('#pragma once\n'+''.join(f'void {name}(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for name in sorted(actual))+''.join(f'inline void {name}(std::uint8_t* m,R5900Context* c,PS2Runtime* r){{original_transform_port(m,c,r);}}\n' for name in sorted(calls-actual)))
    for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
    for name in ['o2_functions.h','ps2_recompiled_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
    for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
    (out/'dispatch.inc').write_text(''.join(f'case {address}:{Path(name).stem}(memory,context,runtime);return;\n' for address,name in entries.items()))
    compiler=COMPILERS[args.compiler];env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','');exe=out/'checks.exe'
    command=[str(compiler),'-std=c++20','-O2','-msse4.1','-fno-fast-math','-ffp-contract=off','-DREO_TARGET_METRICS_ORIGINAL=1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/name) for name in units],str(out/'source'/fixture),str(out/'original.cpp'),'-o',str(exe)]
    receipt=dict(schema=1,status='failed',game_launched=False,installed_in_game=False,stage4_complete=False,compiler_sha256=sha(compiler),owned_image_sha256=images,source_sha256={name:hashlib.sha256(data).hexdigest() for name,data in frozen.items()},original_word_audits=audits,commands=[],declared_ports=['376E70 finite direction through existing native heading helper','579980 and57D630 actual native Grid wall/floor consumers with audited arguments'],limitations=['Original cache rebuild, repeated pairwise sort, raw-mode chain and XYZ distance execute completely. Native model points are projected into the reference fixture. The heading and collision ports are explicitly shared qualified child algorithms; this is not transitive independent math or geometry coverage.','Strict profiles compare only when all reached scratch reads are written. Separate corrected comparisons initialize both work arrays to finite maximum before the unchanged source body. No game, stock room caller or performance measurement is claimed.'])
    try:
        for label,cmd in [('compile',command),('test',[str(exe)])]:
            result=subprocess.run(cmd,capture_output=True,env=env,timeout=180);(out/f'{label}.stdout.txt').write_bytes(result.stdout);(out/f'{label}.stderr.txt').write_bytes(result.stderr);receipt['commands'].append(dict(label=label,exit_code=result.returncode,command=cmd));assert result.returncode==0,label+': '+result.stderr.decode(errors='replace')[-3500:]
            if label=='test':receipt['observed']=json.loads(result.stdout)
        receipt['source_unchanged']=all((ROOT/name).read_bytes()==data for name,data in frozen.items());assert receipt['source_unchanged'];receipt['status']='passed'
    finally:
        receipt['output_sha256']={p.name:sha(p) for p in out.iterdir() if p.is_file()};(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(receipt['observed']))
if __name__=='__main__':main()
