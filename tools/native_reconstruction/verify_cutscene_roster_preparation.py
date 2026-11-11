"""Compare native eligible-roster projection with complete owned5ED340."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True)
    a=p.parse_args();compiler=COMPILERS[a.compiler];out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
    overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=overlay.read_bytes()
    original=ROOT/'recomp/config/output_ovl/o2/o2_005ED340_0x5ed340.cpp';proof=compare_source('complete roster preparation surrounded by declared cleanup ports',original.relative_to(ROOT).as_posix(),0x5ed340,0x5ed76c,lambda at,size:raw[at-0x570000:at-0x570000+size])
    native=ROOT/'game/native/gameplay_scenario';source=native/'cutscene_roster_preparation_tests.cpp';helper=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    pending=[source,native/'cutscene_roster_preparation.hpp',native/'CMakeLists.txt'];files=set(pending)
    while pending:
        at=pending.pop()
        for name in re.findall(r'^#include "([^"]+)"',at.read_text(),re.M):
            path=(at.parent/name).resolve()
            if path.exists()and path.is_relative_to(ROOT)and path not in files:files.add(path);pending.append(path)
    files.update([original,Path(__file__),helper]);before={f.relative_to(ROOT).as_posix():sha(f)for f in sorted(files)};out.mkdir()
    for name in before:
        target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
    reference=helper.read_text().replace('Register r[32];','std::uint64_t lo{},hi{};Register r[32];');body=original.read_text();actual=original.stem;calls=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body))
    reference+='void '+actual+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'
    reference+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(calls-{actual}))
    (out/'roster_reference.hpp').write_text(reference);(out/'original.cpp').write_text(body)
    for name in ['ps2_runtime.h','ps2_runtime_macros.h','ps2_recompiled_functions.h','o2_functions.h']:(out/name).write_text('#pragma once\n#include "roster_reference.hpp"\n')
    for name in ['ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h']:(out/name).write_text('#pragma once\n')
    common=[str(compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off',str(source)]
    commands=[('build-basic',common+['-o',str(out/'native.exe')]),('basic',[str(out/'native.exe')]),('build-original',common+['-Wno-unused-label','-Wno-unused-parameter','-DREO_CUTSCENE_ROSTER_ORIGINAL=1','-I'+str(out),str(out/'original.cpp'),'-o',str(out/'compared.exe')]),('compared',[str(out/'compared.exe')])]
    env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','')
    result=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(compiler),original_owned_bodies=[proof],commands=[],game_run=False,installed_in_game=False,stage4_complete=False,declared_ports=[
        '5ED340 graphics, bank cleanup, NPC/object cleanup, temporary-pool reset and scratch consumers are explicit non-projecting observation ports. No complete scene cleanup is admitted.',
        'The actual bounded64KiB zero-fill runs in a separate fixture region.',
        'Only roster character/slot/status data, preference remapping and canonical visibility projection are compared.',
        'Missing native actor/population/scenario data and out-of-owner placement-room reads refuse before publication; those source cases do not execute.',
        'Preparation is a pure value operation, not a live World mutation or model-cache handoff.'])
    try:
        for name,command in commands:
            done=subprocess.run(command,env=env,capture_output=True,timeout=180);(out/(name+'.stdout.txt')).write_bytes(done.stdout);(out/(name+'.stderr.txt')).write_bytes(done.stderr)
            result['commands'].append(dict(command=command,exit_code=done.returncode));assert done.returncode==0,name+' '+(done.stdout+done.stderr).decode(errors='replace')[-2500:]
            if name in ['basic','compared']:result[name]=json.loads(done.stdout)
        assert all(sha(ROOT/name)==digest for name,digest in before.items());result.update(status='passed',source_unchanged=True)
    finally:
        result['output_sha256']={f.relative_to(out).as_posix():sha(f)for f in out.rglob('*')if f.is_file()};(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(dict(status=result['status'],observed=result['compared'])))
if __name__=='__main__':main()
