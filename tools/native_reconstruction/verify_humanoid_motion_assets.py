"""Qualify actual common/character motion loads and shared scene-bank ownership."""
import argparse,hashlib,json,os,re,subprocess,struct,sys
from pathlib import Path
from audit_retail_effect_descriptors import elf_reader,compare_source
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2];sys.path.insert(0,str(ROOT/'tools/assets'))
from afs_inspect import read_toc
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True)
    for name in ['cmake','build','data-root','output']:p.add_argument('--'+name,type=Path,required=True)
    p.add_argument('--publication',action='store_true')
    a=p.parse_args();out=a.output.resolve();build=a.build.resolve();compiler=COMPILERS[a.compiler];assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
    configured=re.search(r'^CMAKE_CXX_COMPILER:[^=]+=([^\n]+)',(build/'CMakeCache.txt').read_text(),re.M)[1];assert Path(configured.strip()).resolve()==compiler.resolve()
    elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    read=elf_reader(elf.read_bytes());entries={};proof=[]
    for at in [0x1d1500,0x1d16c0,0x1d1940,0x1d1960,0x1d1990,0x1d19d0,0x1d1a80,0x1d1b10,0x1d1cc0,0x1b1bc0,0x1b1b40,0x1b2130]:
        source=ROOT/f'recomp/config/output/sub_{at:08X}_0x{at:x}.cpp';begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',source.read_text()).groups()];entries[at]=source
        proof.append(compare_source('complete source containing common/character loader and bank construction',source.relative_to(ROOT).as_posix(),begin,end,read))
    overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';overlay_raw=overlay.read_bytes();source=ROOT/'recomp/config/output_ovl/o2/o2_005EC0E0_0x5ec0e0.cpp';entries[0x5ec0e0]=source
    proof.append(compare_source('complete primary model-cache character-bank release route',source.relative_to(ROOT).as_posix(),0x5ec0e0,0x5ec0f8,lambda at,n:overlay_raw[at-0x570000:at-0x570000+n]))
    profile_path=ROOT/'build-native-sjuni/humanoid-motion-member-profile-v1/receipt.json';profile=json.loads(profile_path.read_bytes());assert profile['status']=='passed'and sha(ROOT/'game/native/gameplay_world/humanoid_motion_members.inc')==profile['output_sha256']
    scripted_path=ROOT/'build-native-sjuni/scripted-motion-member-profile-v1/receipt.json';scripted=json.loads(scripted_path.read_bytes());assert scripted['status']=='passed'and sha(ROOT/'game/native/gameplay_world/scripted_motion_members.inc')==scripted['output_sha256']
    scene_rows=[row for row in scripted['rows']if row['scenario']==1 and row['clip']==2 and row['kind']in [0,2]];assert len(scene_rows)==2
    inputs=profile['rows']+[dict(index=2,character=253 if row['kind']==0 else 254,member=row['member'],name='D02.BIN'if row['kind']==0 else'HD02.BIN',alias=row['alias'])for row in scene_rows]
    inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json';assert sha(inventory)=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2';members={row['member']:row for row in json.loads(inventory.read_bytes())}
    archive=a.data_root/'NETBIO00.DAT';stamp=archive.stat().st_size,archive.stat().st_mtime_ns;lines=[];assets=[]
    with archive.open('rb')as stream:
        outer=read_toc(stream,0);common=[i for i,(name,_)in enumerate(outer[2])if name.lower()=='romdata_usa.afs'];assert len(common)==1;base=outer[0][common[0]][0];directory=read_toc(stream,base);assert len(directory[0])==1342
        for row in inputs:
            ordinal=row['member'];offset,length=directory[0][ordinal];assert directory[2][ordinal][0].lower()==row['name'].lower();stream.seek(base+offset);raw=stream.read(length);expected=members[f'NETBIO00.DAT/{common[0]}/{ordinal}'];assert len(raw)==length==expected['bytes']and hashlib.sha256(raw).hexdigest()==expected['sha256']
            lines.append(f"{row['index']} {row['character']} {ordinal} {row['name']} {base+offset} {length}");assets.append(dict(**row,bytes=length,sha256=expected['sha256']))
    helpers=[Path(__file__),ROOT/'tools/native_reconstruction/generate_humanoid_motion_members.py',ROOT/'tools/native_reconstruction/animation/motion_bank_tests.cpp',ROOT/'tools/native_reconstruction/humanoid_motion_loader_reference.inc',ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp',ROOT/'runtime/assets/virtual_afs.h']
    files=[p for p in (ROOT/'game/native').rglob('*')if p.is_file()and(p.suffix in ['.cpp','.hpp','.h','.inc']or p.name=='CMakeLists.txt')]+helpers+list(entries.values());before={p.relative_to(ROOT).as_posix():sha(p)for p in files};out.mkdir()
    for name in before:target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
    (out/'members.txt').write_text('\n'.join(lines)+'\n')
    reference=(ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp').read_text().replace('Register r[32];','std::uint64_t lo{},hi{};Register r[32];')+'\n#define GPR_S32(c,n) std::bit_cast<std::int32_t>(GPR_U32(c,n))\n'
    (out/'reference.hpp').write_text(reference);body='\n'.join(path.read_text()for path in entries.values());(out/'original_banks.cpp').write_text(body)
    actual={path.stem for path in entries.values()};calls=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body))
    declarations=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual))+''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(calls-actual))
    (out/'functions.h').write_text('#pragma once\n'+declarations);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+path.stem+'(memory,context,runtime);return;\n'for at,path in entries.items()))
    for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
    (out/'ps2_recompiled_functions.h').write_text('#pragma once\n#include "functions.h"\n')
    (out/'o2_functions.h').write_text('#pragma once\n#include "functions.h"\n')
    for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
    init='inline void constants(std::uint8_t* p){\n'
    for address,size in [(0x2366f0,12)]:
        raw=read(address,size);init+='{const std::uint8_t b[]{'+','.join(map(str,raw))+'};std::memcpy(p+'+str(address)+',b,sizeof b);}\n'
    init+='}\ninline void owned_humanoid_formats(std::uint8_t* p){\n'
    for address in [0x256380,0x2563b0,0x2563e0,0x256430,0x256460,0x256490]:
        raw=read(address,100).split(b'\0')[0]+b'\0';init+='{const std::uint8_t b[]{'+','.join(map(str,raw))+'};std::memcpy(p+'+str(address)+',b,sizeof b);}\n'
    (out/'constants.hpp').write_text(init+'}\n')
    fixture=(ROOT/'tools/native_reconstruction/animation/motion_bank_tests.cpp').read_text().replace('int main(','int unused_motion_bank_fixture(').replace('\n}catch(const std::exception& e)','\nreturn 0;\n}catch(const std::exception& e)')
    fixture=fixture.replace(' ++calls;',' ++calls;if(humanoid_loader_original_port(memory,context,runtime))return;').replace('std::to_string(expected.asset)','humanoid_original_identity(expected.asset)');(out/'motion_bank_fixture.hpp').write_text(fixture)
    (out/'humanoid_motion_loader_reference.inc').write_bytes((ROOT/'tools/native_reconstruction/humanoid_motion_loader_reference.inc').read_bytes())
    result=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(compiler),member_profile=dict(path=str(profile_path),sha256=sha(profile_path)),original_owned_bodies=proof,scripted_member_profile=dict(path=str(scripted_path),sha256=sha(scripted_path)),owned_assets=assets,commands=[],game_run=False,installed_in_game=False,stage4_complete=False,declared_ports=['1CC8F0 path acquisition observed with pinned raw member bytes','1B1DF0/1B2CE0 work-buffer preparation/release observations','1D3550 raw block provenance,192500 token identity,1925A0 release observations','name-only failed reads bypass constructors explicitly'])
    targets=['humanoid_motion_assets_tests','cutscene_npc_construction_tests','npc_actor_construction_tests','npc_actor_assets_tests','cutscene_scripted_construction_tests','cutscene_descriptor_assets_tests','gameplay_actor_assets_tests','scripted_motion_assets_tests','gameplay_target_metrics_tests','gameplay_cooperative_events_tests','gameplay_collision_workers_tests','gameplay_ai_owner_tests'];regex='^(native_humanoid_motion_assets|native_cutscene_npc_construction|native_npc_actor_construction|native_npc_actor_assets|native_cutscene_scripted_construction|native_cutscene_descriptor_assets|native_gameplay_actor_assets|native_scripted_motion_assets|native_gameplay_target_metrics|native_gameplay_cooperative_events|native_gameplay_collision_workers|native_gameplay_ai_owner)$'
    env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+str(a.cmake.parent)+os.pathsep+env.get('PATH','')
    if a.publication:
        targets.append('humanoid_motion_publication_tests');regex=regex[:-2]+'|native_humanoid_motion_publication)$'
    commands=[('configure',[str(a.cmake),'-S',str(ROOT/'game/native'),'-B',str(build),'-DREO_HUMANOID_MOTION_REFERENCE_DIR='+str(out)]),('build',[str(a.cmake),'--build',str(build),'--parallel','2','--target',*targets]),('owned',[str(build/'gameplay_world/humanoid_motion_assets_tests.exe'),str(archive),str(out/'members.txt')]),('parents',[str(a.cmake.parent/'ctest.exe'),'--test-dir',str(build),'-R',regex,'--output-on-failure'])]
    if a.publication:commands.insert(-1,('publication',[str(build/'gameplay_world/humanoid_motion_publication_tests.exe'),str(archive)]))
    try:
        for name,command in commands:
            done=subprocess.run(command,env=env,capture_output=True,timeout=240);(out/(name+'.stdout.txt')).write_bytes(done.stdout);(out/(name+'.stderr.txt')).write_bytes(done.stderr);result['commands'].append(dict(command=command,exit_code=done.returncode));assert done.returncode==0,name+' '+(done.stdout+done.stderr).decode(errors='replace')[-2200:]
            if name in ['owned','publication']:result[name]=json.loads(done.stdout)
            if name=='parents':assert ('100% tests passed, 0 tests failed out of '+str(13 if a.publication else 12)).encode()in done.stdout
        assert (archive.stat().st_size,archive.stat().st_mtime_ns)==stamp and all(sha(ROOT/name)==digest for name,digest in before.items());result.update(status='passed',source_unchanged=True)
    finally:
        result['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()};(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(dict(status=result['status'],owned=result['owned'])))
if __name__=='__main__':main()
