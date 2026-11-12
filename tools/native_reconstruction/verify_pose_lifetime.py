"""Qualify full signed lifetime and authored-kind domain against complete582B80."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
from audit_retail_effect_descriptors import compare_source
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
    out=a.output.resolve();assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
    overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';data=overlay.read_bytes()
    original='recomp/config/output_ovl/o2/o2_00582B80_0x582b80.cpp';body=(ROOT/original).read_text();begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',body).groups()]
    proof=compare_source('complete pose lifetime gate and dispatch',original,begin,end,lambda at,n:data[at-0x570000:at-0x570000+n])
    unit='game/native/gameplay_effects/pose_lifetime.cpp';header='game/native/gameplay_effects/pose_lifetime.hpp';fixture='tools/native_reconstruction/pose_lifetime_tests.cpp';helper='tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    names=[original,unit,header,fixture,helper,Path(__file__).relative_to(ROOT).as_posix()];frozen={name:(ROOT/name).read_bytes()for name in names};out.mkdir(parents=True)
    for name,contents in frozen.items():
        path=out/'source'/name;path.parent.mkdir(parents=True,exist_ok=True);path.write_bytes(contents)
    (out/'reference.hpp').write_bytes(frozen[helper])
    own=Path(original).stem;called=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body))
    decl='void '+own+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n';decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(called-{own}))
    (out/'functions.h').write_text('#pragma once\n'+decl)
    for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
    (out/'o2_functions.h').write_text('#pragma once\n#include "functions.h"\n')
    for name in ['ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h']:(out/name).write_text('#pragma once\n')
    (out/'original.cpp').write_text('#include "reference.hpp"\n#include "functions.h"\n'+body)
    compiler=COMPILERS[a.compiler];binary=out/'checks.exe';command=[str(compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),str(out/'source'/unit),str(out/'source'/fixture),str(out/'original.cpp'),'-o',str(binary)]
    env=dict(os.environ,PATH=str(compiler.parent)+os.pathsep+os.environ.get('PATH',''));record=dict(schema=1,status='failed',game_run=False,installed_in_game=False,stage4_complete=False,source_sha256={name:hashlib.sha256(value).hexdigest()for name,value in frozen.items()},compiler_sha256=sha(compiler),original_word_audits=[proof],command=command,declared_ports=['All actual downstream update operations and final582DE0 retirement are controlled consumers; this proves only complete582B80 gate/order.'])
    try:
        for label,cmd in [('compile',command),('run',[str(binary)])]:
            result=subprocess.run(cmd,capture_output=True,env=env,timeout=180);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);assert result.returncode==0,label+' failed; see retained logs'
            if label=='run':record['observed']=json.loads(result.stdout)
        record['source_unchanged']=all((ROOT/name).read_bytes()==value for name,value in frozen.items());assert record['source_unchanged'];record.update(status='passed',binary_sha256=sha(binary))
    finally:
        record['output_sha256']={path.relative_to(out).as_posix():sha(path)for path in out.rglob('*')if path.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps(record['observed']))


if __name__=='__main__':main()
