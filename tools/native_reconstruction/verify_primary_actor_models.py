"""Qualify native archive primary-model cache and actual CPU owner composition."""
import argparse,hashlib,json,os,re,subprocess,sys
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/assets'))
from afs_inspect import read_toc
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    parser=argparse.ArgumentParser();parser.add_argument('--compiler',choices=COMPILERS,required=True)
    for name in ['cmake','build','data-root','output']:parser.add_argument('--'+name,type=Path,required=True)
    args=parser.parse_args();out=args.output.resolve();build=args.build.resolve();compiler=COMPILERS[args.compiler]
    assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
    configured=re.search(r'^CMAKE_CXX_COMPILER:[^=]+=([^\n]+)',(build/'CMakeCache.txt').read_text(),re.M)[1]
    assert Path(configured.strip()).resolve()==compiler.resolve()
    elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';main_read=elf_reader(elf.read_bytes())
    overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=overlay.read_bytes()
    originals=[];proof=[]
    for at,end in [(0x5ec100,0x5ec270),(0x5ec010,0x5ec0d8),(0x5ebfe0,0x5ec010),(0x1d1c40,0x1d1c48)]:
        bank=at>=0x570000;path=next((ROOT/('recomp/config/output_ovl/o2'if bank else'recomp/config/output')).glob(f'*_{at:08X}_*'))
        proof.append(compare_source('complete primary cache/release/no-op source',path.relative_to(ROOT).as_posix(),at,end,(lambda address,size:raw[address-0x570000:address-0x570000+size])if bank else main_read));originals.append(path)
    inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json';assert sha(inventory)=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2';members={r['member']:r for r in json.loads(inventory.read_bytes())}
    profiles={};inputs=[]
    for name,include in [('primary-actor-member','primary_actor_members.inc'),('humanoid-motion-member','humanoid_motion_members.inc')]:
        path=ROOT/f'build-native-sjuni/{name}-profile-v1/receipt.json';profile=json.loads(path.read_bytes());assert profile['status']=='passed'and sha(ROOT/'game/native/gameplay_world'/include)==profile['output_sha256']
        profiles[name]=dict(receipt=str(path),sha256=sha(path));inputs.extend(profile['rows']if name.startswith('primary')else [r for r in profile['rows']if r['character']!=255 or r['index']in [0,1]])
    archive=args.data_root/'NETBIO00.DAT';stamp=archive.stat().st_size,archive.stat().st_mtime_ns;assets=[]
    with archive.open('rb')as stream:
        outer=read_toc(stream,0);indices=[i for i,(name,_)in enumerate(outer[2])if name.lower()=='romdata_usa.afs'];assert len(indices)==1;base=outer[0][indices[0]][0];directory=read_toc(stream,base)
        for row in {r['member']:r for r in inputs}.values():
            ordinal=row['member'];offset,length=directory[0][ordinal];assert directory[2][ordinal][0].lower()==row['name'].lower();stream.seek(base+offset);data=stream.read(length);expected=members[f'NETBIO00.DAT/{indices[0]}/{ordinal}'];assert len(data)==length==expected['bytes']and hashlib.sha256(data).hexdigest()==expected['sha256'];assets.append(dict(name=row['name'],member=ordinal,sha256=expected['sha256']))
    helpers=[Path(__file__),ROOT/'tools/native_reconstruction/primary_models_reference.inc',ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp',ROOT/'runtime/assets/virtual_afs.h']
    files=[p for p in (ROOT/'game/native').rglob('*')if p.is_file()and(p.suffix in ['.cpp','.hpp','.h','.inc']or p.name=='CMakeLists.txt')]+helpers+originals
    before={p.relative_to(ROOT).as_posix():sha(p)for p in files};out.mkdir()
    for name in before:
        target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
    reference=(ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp').read_text().replace('Register r[32];','std::uint64_t lo{},hi{};Register r[32];')
    reference+='\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n'
    body='\n'.join(p.read_text()for p in originals);actual={p.stem for p in originals};calls=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body))
    reference+=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual))
    reference+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(calls-actual))
    (out/'primary_models_reference.hpp').write_text(reference)
    (out/'primary_models_original.cpp').write_text('#pragma GCC diagnostic ignored "-Wunused-label"\n#pragma GCC diagnostic ignored "-Wunused-parameter"\n'+body)
    (out/'primary_models_reference.inc').write_bytes(helpers[1].read_bytes())
    for name in ['ps2_runtime.h','ps2_runtime_macros.h','ps2_recompiled_functions.h','o2_functions.h']:(out/name).write_text('#pragma once\n#include "primary_models_reference.hpp"\n')
    for name in ['ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h']:(out/name).write_text('#pragma once\n')
    result=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(compiler),profiles=profiles,owned_assets=assets,original_owned_bodies=proof,commands=[],game_run=False,installed_in_game=False,stage4_complete=False,
        declared_ports=['Archive1AA740 call observed; native actual assets, CPU instances, shared banks, initialization and constraints run independently. Texture/material submission remains Stage5.',
        '66A750 direct reuse call observed here; complete initializer comparisons are a separately required parent cohort.',
        '5EC0E0 release identity observed; actual immutable clear/publication is exercised natively and separately compared against its full original bodies.',
        'Registry8-key retirement, optional HP auxiliary retirement and compaction are declared resource ports; not an installed complete loader.',
        'Resident-file3243D7==0 and generation migration of a live cache row remain explicitly unavailable.'])
    env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+str(args.cmake.parent)+os.pathsep+env.get('PATH','')
    commands=[('configure',[str(args.cmake),'-S',str(ROOT/'game/native'),'-B',str(build),'-DREO_PRIMARY_MODELS_REFERENCE_DIR='+str(out)]),('build',[str(args.cmake),'--build',str(build),'--parallel','2','--target','primary_actor_models_tests']),('owned',[str(build/'gameplay_world/primary_actor_models_tests.exe'),str(archive)]),('parents',[str(args.cmake.parent/'ctest.exe'),'--test-dir',str(build),'-R','^native_primary_actor_models$','--output-on-failure'])]
    try:
        for name,command in commands:
            done=subprocess.run(command,env=env,capture_output=True,timeout=240);(out/(name+'.stdout.txt')).write_bytes(done.stdout);(out/(name+'.stderr.txt')).write_bytes(done.stderr);result['commands'].append(dict(command=command,exit_code=done.returncode));assert done.returncode==0,name+' '+(done.stdout+done.stderr).decode(errors='replace')[-3000:]
            if name=='owned':result['owned']=json.loads(done.stdout)
        assert (archive.stat().st_size,archive.stat().st_mtime_ns)==stamp and all(sha(ROOT/name)==digest for name,digest in before.items());result.update(status='passed',source_unchanged=True)
    finally:
        result['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()};(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(dict(status=result['status'],owned=result['owned'])))
if __name__=='__main__':main()
