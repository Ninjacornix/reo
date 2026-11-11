"""Verify actual NPC/HP bundle reads and full original nonzeroBB4 filename routes."""
import argparse,hashlib,json,os,re,subprocess,sys,struct
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
from verify_gameplay_collision import COMPILERS
from verify_actor_assets import skeleton_nodes,model_parts,owned_manifest
ROOT=Path(__file__).resolve().parents[2];sys.path.insert(0,str(ROOT/'tools/assets'))
from afs_inspect import read_toc
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True)
    for name in ['build','cmake','data-root','output']:p.add_argument('--'+name,type=Path,required=True)
    a=p.parse_args();out=a.output.resolve();build=a.build.resolve();compiler=COMPILERS[a.compiler]
    assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
    configured=re.search(r'^CMAKE_CXX_COMPILER:[^=]+=([^\n]+)',(build/'CMakeCache.txt').read_text(),re.M)[1];assert Path(configured.strip()).resolve()==compiler.resolve()
    elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes());original=ROOT/'recomp/config/output/sub_001AA740_0x1aa740.cpp'
    proof=compare_source('complete primary substituted model loader, filename and failed-read profile',original.relative_to(ROOT).as_posix(),0x1aa740,0x1aaad0,read)
    selector=ROOT/'recomp/config/output/sub_001CD710_0x1cd710.cpp';formatter=ROOT/'recomp/config/output/sub_001CD340_0x1cd340.cpp'
    selector_proofs=[compare_source('complete resident NPC filename selector',selector.relative_to(ROOT).as_posix(),0x1cd710,0x1cdda0,read),compare_source('complete resident NPC filename formatter',formatter.relative_to(ROOT).as_posix(),0x1cd340,0x1cd3f0,read)]
    auxiliary_path=ROOT/'build-native-sjuni/auxiliary-actor-member-profile-v1/receipt.json';auxiliary=json.loads(auxiliary_path.read_bytes());assert auxiliary['status']=='passed'and sha(ROOT/'game/native/gameplay_world/auxiliary_actor_members.inc')==auxiliary['output_sha256']
    auxiliary_lines=[];auxiliary_assets=[]
    inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json';assert sha(inventory)=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2';members={r['member']:r for r in json.loads(inventory.read_bytes())}
    archive=a.data_root/'NETBIO00.DAT';stamp=archive.stat().st_size,archive.stat().st_mtime_ns;lines=[];assets=[]
    profile_path=ROOT/'build-native-sjuni/npc-actor-member-profile-v1/receipt.json';profile=json.loads(profile_path.read_bytes());assert profile['status']=='passed' and sha(ROOT/'game/native/gameplay_world/npc_actor_members.inc')==profile['output_sha256']
    skeletons=[];stale=[]
    with archive.open('rb')as f:
        outer=read_toc(f,0);common=[i for i,(name,_)in enumerate(outer[2])if name.lower()=='romdata_usa.afs'];assert len(common)==1;base=outer[0][common[0]][0];directory=read_toc(f,base);assert len(directory[0])==1342
        for row in profile['rows']:
            name=row['name'];index=row['member'];assert directory[2][index][0].lower()==name.lower();match=re.fullmatch(r'(n|hp)(\d+)\.nbd',name.lower());assert match
            hp=match[1]=='hp';number=int(match[2]);offset,length=directory[0][index];f.seek(base+offset);raw=f.read(length);expected=members[f'NETBIO00.DAT/{common[0]}/{index}'];assert len(raw)==expected['bytes'] and hashlib.sha256(raw).hexdigest()==expected['sha256']
            lines.append(f"{1 if hp else number+1} {1 if hp else 0} {number if hp else 0} {name} {base+offset} {length} {skeleton_nodes(raw,True)} {model_parts(raw)}");assets.append(dict(name=name,member=expected['member'],sha256=expected['sha256']))
            pos,size=struct.unpack_from('<II',raw,0x24)
            if pos:
                block=raw[pos:pos+size];assert len(block)==size;skeletons.append(block)
                if struct.unpack_from('<I',block,8)[0]!=len(block):stale.append(dict(name=name,member=expected['member'],actual=len(block),declared=struct.unpack_from('<I',block,8)[0]))
        for row in auxiliary['rows']:
            index=row['member'];name=row['name'];assert directory[2][index][0].lower()==name.lower();offset,length=directory[0][index];f.seek(base+offset);raw=f.read(length);expected=members[f'NETBIO00.DAT/{common[0]}/{index}'];assert len(raw)==expected['bytes']and hashlib.sha256(raw).hexdigest()==expected['sha256']
            auxiliary_lines.append(f"{row['id']} {row['model_class']} {name} {base+offset} {length} {skeleton_nodes(raw,True)} {model_parts(raw)}");auxiliary_assets.append(dict(name=name,member=expected['member'],sha256=expected['sha256']))
    assert len(assets)==133 and sum(x['name'].lower().startswith('hp')for x in assets)==8 and len(stale)==7
    files=[p for p in (ROOT/'game/native').rglob('*')if p.is_file()and(p.suffix in ['.cpp','.hpp','.h','.inc']or p.name=='CMakeLists.txt')]+[Path(__file__),original,selector,formatter,ROOT/'tools/native_reconstruction/generate_auxiliary_actor_members.py',ROOT/'runtime/assets/virtual_afs.h',ROOT/'tools/native_reconstruction/verify_actor_assets.py',ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp',ROOT/'tools/native_reconstruction/npc_actor_asset_reference_tests.inc',ROOT/'tools/native_reconstruction/generate_npc_actor_members.py']
    before={p.relative_to(ROOT).as_posix():sha(p)for p in files};out.mkdir()
    for name in before:target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
    (out/'owned_npc_skeletons.bin').write_bytes(struct.pack('<I',len(skeletons))+b''.join(struct.pack('<I',len(raw))+raw for raw in skeletons))
    (out/'auxiliary_members.txt').write_text('\n'.join(auxiliary_lines)+'\n')
    (out/'members.txt').write_text('\n'.join(lines)+'\n');_,models,model_rows=owned_manifest(a.data_root,out)
    bodies=[original.read_text(),selector.read_text(),formatter.read_text()];body='\n'.join(bodies)
    reference=(ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp').read_text().replace('Register r[32];','std::uint64_t lo{},hi{};Register r[32];')+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n'
    actual={'sub_001AA740_0x1aa740','sub_001CD710_0x1cd710','sub_001CD340_0x1cd340'}
    for name in sorted(actual):reference+='void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'
    for name in sorted(set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body))-actual):reference+='inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r); }\n'
    reference+='inline void owned_npc_name_formats(std::uint8_t* memory){\n'
    for address in [0x24d030,0x24d040,0x24d050,0x24d060]:
        raw=read(address,80).split(b'\0')[0]+b'\0';reference+='{const std::uint8_t b[]{'+','.join(map(str,raw))+'};std::memcpy(memory+'+str(address)+',b,sizeof b);}\n'
    reference+='}\ninline void owned_auxiliary_name_formats(std::uint8_t* memory){\n'
    ranges=[(0x255f80,0x140),(0x2366d0,8)]
    for index in range(2):
        address=struct.unpack('<I',read(0x2366d0+4*index,4))[0];ranges.append((address,len(read(address,80).split(b'\0')[0])+1))
    for address,size in ranges:
        raw=read(address,size);reference+='{const std::uint8_t b[]{'+','.join(map(str,raw))+'};std::memcpy(memory+'+str(address)+',b,sizeof b);}\n'
    (out/'reference.hpp').write_text(reference+'}\n');(out/'original.cpp').write_text('#include "reference.hpp"\n'+''.join(part[part.index('// Function:'):]for part in bodies));(out/'npc_actor_asset_reference_tests.inc').write_bytes((ROOT/'tools/native_reconstruction/npc_actor_asset_reference_tests.inc').read_bytes())
    result=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(compiler),original_owned_body=proof,selector_owned_bodies=selector_proofs,auxiliary_member_profile=dict(path=str(auxiliary_path),sha256=sha(auxiliary_path)),owned_auxiliary_assets=auxiliary_assets,original_observation_ports=['10A830 actual owned sprintf literals','1AA480 controlled failed read after observing requested path; actual native asset reads tested separately'],owned_assets=assets,baseline_models=model_rows,member_profile=dict(path=str(profile_path),sha256=sha(profile_path)),stale_skeleton_lengths=stale,commands=[],game_run=False,installed_in_game=False,stage4_complete=False)
    targets=['npc_actor_assets_tests','cutscene_scripted_construction_tests','cutscene_descriptor_assets_tests','gameplay_actor_assets_tests','scripted_motion_assets_tests','gameplay_target_metrics_tests','gameplay_cooperative_events_tests','gameplay_collision_workers_tests','gameplay_ai_owner_tests'];regex='^(native_npc_actor_assets|native_cutscene_scripted_construction|native_cutscene_descriptor_assets|native_gameplay_actor_assets|native_scripted_motion_assets|native_gameplay_target_metrics|native_gameplay_cooperative_events|native_gameplay_collision_workers|native_gameplay_ai_owner)$'
    env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+str(a.cmake.parent)+os.pathsep+env.get('PATH','')
    commands=[('configure',[str(a.cmake),'-S',str(ROOT/'game/native'),'-B',str(build),'-DREO_NPC_ASSETS_REFERENCE_DIR='+str(out)]),('build',[str(a.cmake),'--build',str(build),'--parallel','2','--target',*targets]),('owned',[str(build/'gameplay_world/npc_actor_assets_tests.exe'),str(archive),str(out/'members.txt'),str(out/'auxiliary_members.txt')]),('baseline',[str(build/'gameplay_world/gameplay_actor_assets_tests.exe'),str(archive),str(models)]),('parents',[str(a.cmake.parent/'ctest.exe'),'--test-dir',str(build),'-R',regex,'--output-on-failure'])]
    try:
        for name,command in commands:
            done=subprocess.run(command,env=env,capture_output=True,timeout=240);(out/(name+'.stdout.txt')).write_bytes(done.stdout);(out/(name+'.stderr.txt')).write_bytes(done.stderr);result['commands'].append(dict(command=command,exit_code=done.returncode));assert done.returncode==0,name+' '+(done.stdout+done.stderr).decode(errors='replace')[-2400:]
            if name in ['owned','baseline']:result[name]=json.loads(done.stdout)
            if name=='parents':assert b'100% tests passed, 0 tests failed out of 9'in done.stdout
        assert (archive.stat().st_size,archive.stat().st_mtime_ns)==stamp and all(sha(ROOT/name)==digest for name,digest in before.items());result.update(status='passed',source_unchanged=True)
    finally:
        result['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()};(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(dict(status=result['status'],owned=result['owned'],baseline=result['baseline'])))
if __name__=='__main__':main()
