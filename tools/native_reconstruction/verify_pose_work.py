"""Full pose pool/constructor comparisons against immutable native ABI inputs."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
from audit_retail_effect_descriptors import compare_source
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--updates',action='store_true');p.add_argument('--native-libraries',type=Path,required=True);a=p.parse_args()
    out=a.output.resolve();assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
    parent=ROOT/'build-native-sjuni'/f'session-rooms-{a.compiler}-v4/receipt.json';prior=json.loads(parent.read_bytes());assert prior['status']=='passed' and not prior['current_shared_source_drift']
    compiler=COMPILERS[a.compiler];assert sha(compiler)==prior['compiler_sha256']
    critical=['game/native/gameplay_world/world.hpp','game/native/gameplay_world/pose_work_state.hpp']
    for name in critical:assert sha(ROOT/name)==prior['source_sha256'][name],name
    units=['game/native/gameplay_world/pose_work_pool.cpp','game/native/gameplay_world/resource_pose_work.cpp','game/native/gameplay_effects/pose_lifetime.cpp','game/native/gameplay_world/animation_events.cpp']
    if a.updates:units+=['game/native/gameplay_world/resource_pose_updates.cpp']
    fixture='tools/native_reconstruction/pose_work_tests.cpp';helper='tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    files=[*units,fixture,helper,'tools/native_reconstruction/pose_work_mutation_tests.inc',Path(__file__).relative_to(ROOT).as_posix()];frozen={}
    if a.updates:files+=['tools/native_reconstruction/pose_work_updates_tests.inc']
    # Compile against the exact headers used to produce the qualified native
    # archives. Subsequent unrelated source edits cannot change their ABI.
    for name,digest in prior['source_sha256'].items():
        source=parent.parent/'source'/name;assert sha(source)==digest,name;frozen[name]=source.read_bytes()
    pending=list(files)
    for name in pending:
        if name not in frozen or name in units:frozen[name]=(ROOT/name).read_bytes()
        if name.startswith('game/native/'):
            for include in re.findall(r'^\s*#include "([^"]+)"',frozen[name].decode(),re.M):
                path=((ROOT/name).parent/include).resolve()
                if not path.is_file():path=(ROOT/include).resolve()
                assert path.is_file() and path.is_relative_to(ROOT),(name,include)
                relative=path.relative_to(ROOT).as_posix()
                if relative not in pending:pending.append(relative)
    overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';image=overlay.read_bytes()
    entries={};proof=[]
    for at in [0x581f50,0x581fe0,0x5820f0,0x582de0,0x5821f0,0x582b80,0x582df0,0x5823e0]+([0x582e30,0x582f30,0x583550,0x5840f0]if a.updates else[]):
        path=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*'));name=path.relative_to(ROOT).as_posix();contents=path.read_bytes();end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',contents.decode())[1],16)
        proof.append(compare_source('complete pose pool, service, lifetime, visibility or resource constructor',name,at,end,lambda address,size:image[address-0x570000:address-0x570000+size]));frozen[name]=contents;entries[at]=name
    out.mkdir(parents=True)
    for name,contents in frozen.items():
        path=out/'source'/name;path.parent.mkdir(parents=True,exist_ok=True);path.write_bytes(contents)
    (out/'reference.hpp').write_text(frozen[helper].decode().replace('Register r[32];','std::uint64_t lo{},hi{};Register r[32];'))
    body='\n'.join(frozen[name].decode()for name in entries.values());actual={Path(name).stem for name in entries.values()};called=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body))
    decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual));decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(called-actual))
    (out/'functions.h').write_text('#pragma once\n'+decl);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+Path(name).stem+'(memory,context,runtime);return;\n'for at,name in entries.items()))
    (out/'original.cpp').write_text('#include "reference.hpp"\n#include "functions.h"\n'+body)
    for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
    (out/'o2_functions.h').write_text('#pragma once\n#include "functions.h"\n')
    for name in ['ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h']:(out/name).write_text('#pragma once\n')
    constants=image[0x719a60-0x570000:0x719a60-0x570000+64*68]
    (out/'owned_constants.hpp').write_text('inline void owned_constants(std::uint8_t* memory){const std::uint8_t data[]{'+','.join(str(v)for v in constants)+'};std::memcpy(memory+0x719a60,data,sizeof data);}\n')
    content_parent=ROOT/'build-native-sjuni/gameplay-contact-content-llvm-v2';conversion=json.loads((content_parent/'conversion.json').read_bytes());content=content_parent/'contact-content-v1.bin';assert sha(content)==conversion['output_sha256']=='6e205620e37747181b4a14280f579e2cd85ed907f9b4634ffe28048e1e87a213';shutil.copyfile(content,out/content.name)
    build=a.native_libraries.resolve();assert build.is_relative_to(ROOT/'build-native-sjuni');libraries=[]
    for name,digest in prior['native_library_sha256'].items():
        path=build/name;assert sha(path)==digest,name;target=out/'libraries'/name;target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(path,target);assert sha(target)==digest;libraries.append(str(target))
    binary=out/'checks.exe';command=[str(compiler),'-std=c++20','-O2','-msse4.1','-ffunction-sections','-fdata-sections','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/name)for name in units],str(out/'source'/fixture),str(out/'original.cpp'),'-Wl,--gc-sections','-Wl,--start-group',*libraries,'-Wl,--end-group','-o',str(binary)]
    if a.updates:command.insert(1,'-DREO_RESOURCE_POSE_UPDATES=1')
    env=dict(os.environ,PATH=str(compiler.parent)+os.pathsep+os.environ.get('PATH',''));record=dict(schema=1,status='failed',game_run=False,installed_in_game=False,stage4_complete=False,source_sha256={name:hashlib.sha256(value).hexdigest()for name,value in frozen.items()},native_parent={'path':parent.relative_to(ROOT).as_posix(),'sha256':sha(parent)},native_library_sha256=prior['native_library_sha256'],compiler_sha256=sha(compiler),original_word_audits=proof,command=command,owned_action_table_sha256=hashlib.sha256(constants).hexdigest(),contact_content_sha256=sha(content),declared_ports=['107C68 is bounded zero-fill; complete allocation/free/service/lifetime/visibility/resource constructor execute.', '5B4D50/5B4380 lookups are controlled explicit template inputs, independently qualified native getters run in production.', '5DA2C0 is a source descriptor-request observation; actual native Packets/Catalog allocate owned definitions. Other downstream pose updates remain unadmitted.'])
    record['native_library_directory']=build.relative_to(ROOT).as_posix()
    try:
        for label,cmd in [('compile',command),('run',[str(binary),str(out/content.name)])]:
            result=subprocess.run(cmd,capture_output=True,env=env,timeout=300);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);assert result.returncode==0,label+' failed; see retained logs'
            if label=='run':record['observed']=json.loads(result.stdout)
        current_names=set(units)|set(critical)|{fixture,Path(__file__).relative_to(ROOT).as_posix()}|{name for name in pending if name not in prior['source_sha256']}
        record['current_owned_source_drift']={name:sha(ROOT/name)for name in current_names if (ROOT/name).read_bytes()!=frozen[name]};assert not record['current_owned_source_drift']
        record['subsequent_parent_source_changes']={name:{'qualified':hashlib.sha256(frozen[name]).hexdigest(),'current':sha(ROOT/name)}for name in pending if name in prior['source_sha256'] and (ROOT/name).read_bytes()!=frozen[name]}
        record.update(status='passed',binary_sha256=sha(binary))
    finally:
        record['output_sha256']={path.relative_to(out).as_posix():sha(path)for path in out.rglob('*')if path.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps(record['observed']))


if __name__=='__main__':main()
