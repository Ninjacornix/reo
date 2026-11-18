"""Compare the separate native cinematic player pool with full owned bodies.

The scratch buffer and downstream sixteen object records are observed ports.
This does not qualify scene assignment, animation, rendering or installation.
"""
import argparse,hashlib,json,os,re,subprocess,sys
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/assets'))
from afs_inspect import read_toc
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True)
    for name in ['cmake','build','data-root','output']:p.add_argument('--'+name,type=Path,required=True)
    a=p.parse_args();out=a.output.resolve();build=a.build.resolve();compiler=COMPILERS[a.compiler]
    assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
    configured=re.search(r'^CMAKE_CXX_COMPILER:[^=]+=([^\n]+)',(build/'CMakeCache.txt').read_text(),re.M)[1]
    assert Path(configured.strip()).resolve()==compiler.resolve()
    overlay=ROOT/'build-function-index/owned-overlays/o2.bin'
    assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    raw=overlay.read_bytes();originals=[];proof=[]
    for at,end in [(0x5f1290,0x5f1328),(0x5f1330,0x5f1384)]:
        path=next((ROOT/'recomp/config/output_ovl/o2').glob(f'*_{at:08X}_*'));originals.append(path)
        proof.append(compare_source('complete cinematic primary storage source',path.relative_to(ROOT).as_posix(),at,end,lambda address,size:raw[address-0x570000:address-0x570000+size]))
    profile=ROOT/'build-native-sjuni/primary-actor-member-profile-v1/receipt.json';pr=json.loads(profile.read_bytes())
    assert pr['status']=='passed'and sha(ROOT/'game/native/gameplay_world/primary_actor_members.inc')==pr['output_sha256']
    row=next(r for r in pr['rows']if r['name'].lower()=='p00_00.nbd')
    inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json'
    assert sha(inventory)=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2'
    members={r['member']:r for r in json.loads(inventory.read_bytes())}
    archive=a.data_root/'NETBIO00.DAT';stamp=archive.stat().st_size,archive.stat().st_mtime_ns
    with archive.open('rb')as stream:
        outer=read_toc(stream,0);indices=[i for i,(name,_)in enumerate(outer[2])if name.lower()=='romdata_usa.afs'];assert len(indices)==1
        base=outer[0][indices[0]][0];directory=read_toc(stream,base);ordinal=row['member'];offset,length=directory[0][ordinal]
        assert directory[2][ordinal][0].lower()==row['name'].lower();stream.seek(base+offset);data=stream.read(length)
        expected=members[f'NETBIO00.DAT/{indices[0]}/{ordinal}'];assert len(data)==length==expected['bytes']and hashlib.sha256(data).hexdigest()==expected['sha256']
    helpers=[Path(__file__),ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp']
    files=[f for f in (ROOT/'game/native').rglob('*')if f.is_file()and(f.suffix in ['.cpp','.hpp','.h','.inc']or f.name=='CMakeLists.txt')]+helpers+originals
    before={f.relative_to(ROOT).as_posix():sha(f)for f in files};out.mkdir()
    for name in before:
        target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
    reference=helpers[1].read_text();body='\n'.join(f.read_text()for f in originals)
    actual={f.stem for f in originals};calls=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body))
    reference+=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual))
    reference+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(calls-actual))
    (out/'scene_primary_reference.hpp').write_text(reference)
    (out/'original.cpp').write_text('#pragma GCC diagnostic ignored "-Wunused-label"\n#pragma GCC diagnostic ignored "-Wunused-parameter"\n'+body)
    for name in ['ps2_runtime.h','ps2_runtime_macros.h','ps2_recompiled_functions.h','o2_functions.h']:(out/name).write_text('#pragma once\n#include "scene_primary_reference.hpp"\n')
    for name in ['ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h']:(out/name).write_text('#pragma once\n')
    result=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(compiler),original_owned_bodies=proof,owned_asset=expected,commands=[],game_run=False,installed_in_game=False,stage4_complete=False,
        declared_ports=['107C68 bounded zero-fill; scratch allocation/ownership remains a separate consumer.', '571010 sixteen category10 object initialization observed, not migrated by this player pool.', '5F0DC0/5F1400 cloning, physical model slot handoff, scene update/render/exit are not admitted by these storage checks.'])
    env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+str(a.cmake.parent)+os.pathsep+env.get('PATH','')
    commands=[('configure',[str(a.cmake),'-S',str(ROOT/'game/native'),'-B',str(build),'-DREO_SCENE_PRIMARY_REFERENCE_DIR='+str(out)]),('build',[str(a.cmake),'--build',str(build),'--parallel','2','--target','scene_primary_actors_tests']),('owned',[str(build/'gameplay_world/scene_primary_actors_tests.exe'),str(archive)]),('parent',[str(a.cmake.parent/'ctest.exe'),'--test-dir',str(build),'-R','^native_scene_primary_actors$','--output-on-failure'])]
    try:
        for name,command in commands:
            done=subprocess.run(command,env=env,capture_output=True,timeout=240);(out/(name+'.stdout.txt')).write_bytes(done.stdout);(out/(name+'.stderr.txt')).write_bytes(done.stderr)
            result['commands'].append(dict(command=command,exit_code=done.returncode));assert done.returncode==0,name+' '+(done.stdout+done.stderr).decode(errors='replace')[-3000:]
            if name=='owned':result['observed']=json.loads(done.stdout)
        assert (archive.stat().st_size,archive.stat().st_mtime_ns)==stamp and all(sha(ROOT/name)==digest for name,digest in before.items())
        result.update(status='passed',source_unchanged=True)
    finally:
        result['output_sha256']={f.relative_to(out).as_posix():sha(f)for f in out.rglob('*')if f.is_file()};(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(dict(status=result['status'],observed=result['observed'])))
if __name__=='__main__':main()
