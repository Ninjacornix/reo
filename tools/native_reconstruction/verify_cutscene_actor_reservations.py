"""Compare bounded cinematic requested/reserved sets with full owned bodies."""
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
    originals=[];proof=[]
    for at,end in [(0x5f0c60,0x5f0ce4),(0x5f0cf0,0x5f0d84),(0x5f0d90,0x5f0dc0)]:
        path=next((ROOT/'recomp/config/output_ovl/o2').glob(f'*_{at:08X}_*'));originals.append(path)
        proof.append(compare_source('complete cinematic character reservation source',path.relative_to(ROOT).as_posix(),at,end,lambda address,size:raw[address-0x570000:address-0x570000+size]))
    source=ROOT/'game/native/gameplay_scenario/cutscene_actor_reservations_tests.cpp'
    helpers=[Path(__file__),ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp',ROOT/'game/native/gameplay_scenario/CMakeLists.txt']
    files=[source,source.with_name('cutscene_actor_reservations.hpp')]+originals+helpers
    before={f.relative_to(ROOT).as_posix():sha(f)for f in files};out.mkdir()
    for name in before:
        target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
    reference=helpers[1].read_text();body='\n'.join(f.read_text()for f in originals);actual={f.stem for f in originals};calls=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body))
    reference+=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual))
    reference+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(calls-actual))
    (out/'reservation_reference.hpp').write_text(reference);(out/'original.cpp').write_text(body)
    for name in ['ps2_runtime.h','ps2_runtime_macros.h','ps2_recompiled_functions.h','o2_functions.h']:(out/name).write_text('#pragma once\n#include "reservation_reference.hpp"\n')
    for name in ['ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h']:(out/name).write_text('#pragma once\n')
    common=[str(compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off',str(source)]
    commands=[('build-basic',common+['-o',str(out/'native.exe')]),('basic',[str(out/'native.exe')]),('build-original',common+['-Wno-unused-label','-Wno-unused-parameter','-DREO_CUTSCENE_RESERVATIONS_ORIGINAL=1','-I'+str(out),str(out/'original.cpp'),'-o',str(out/'compared.exe')]),('compared',[str(out/'compared.exe')])]
    env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','')
    result=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(compiler),original_owned_bodies=proof,commands=[],game_run=False,installed_in_game=False,stage4_complete=False,declared_ports=['107C68 bounded32-byte fill and107AB0 bounded copy are fixture ports.', 'Original negative/oversized counts and writes beyond32 reservations are not executed; native refuses without mutation.', 'This qualifies character sets only. Actor binding/selection5F0DC0 and its model lifecycle remain open.'])
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
