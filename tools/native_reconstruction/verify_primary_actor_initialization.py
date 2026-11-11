"""Compare native default primary initialization/restore with complete owned bodies."""
import argparse,hashlib,json,os,re,subprocess,sys,struct
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2];sys.path.insert(0,str(ROOT/'tools/assets'))
from afs_inspect import read_toc
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True)
    for name in ['cmake','build','data-root','output']:p.add_argument('--'+name,type=Path,required=True)
    p.add_argument('--custom',action='store_true')
    a=p.parse_args();out=a.output.resolve();build=a.build.resolve();compiler=COMPILERS[a.compiler];assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
    configured=re.search(r'^CMAKE_CXX_COMPILER:[^=]+=([^\n]+)',(build/'CMakeCache.txt').read_text(),re.M)[1];assert Path(configured.strip()).resolve()==compiler.resolve()
    overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=overlay.read_bytes();read=lambda at,n:raw[at-0x570000:at-0x570000+n]
    elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';main_read=elf_reader(elf.read_bytes())
    addresses=[0x66a750,0x663170,0x65fab0,0x6efaf0]+([0x669860,0x603110,0x6dd7f0]if a.custom else[])
    originals=[ROOT/f'recomp/config/output_ovl/o2/o2_{at:08X}_0x{at:x}.cpp'for at in addresses];proof=[]
    for source in originals:
        start,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',source.read_text()).groups()];proof.append(compare_source('complete primary default initialization/restore and health/priority/setter body',source.relative_to(ROOT).as_posix(),start,end,read))
    clear=ROOT/'recomp/config/output/sub_001B2130_0x1b2130.cpp';proof.append(compare_source('complete cleared bank header policy',clear.relative_to(ROOT).as_posix(),0x1b2130,0x1b213c,main_read))
    profiles={}
    for name,include in [('primary-actor-definition','primary_actor_definitions.inc'),('primary-actor-member','primary_actor_members.inc'),('humanoid-motion-member','humanoid_motion_members.inc')]:
        path=ROOT/f'build-native-sjuni/{name}-profile-v1/receipt.json';r=json.loads(path.read_bytes());assert r['status']=='passed'and sha(ROOT/'game/native/gameplay_world'/include)==r['output_sha256'];profiles[name]=dict(path=str(path),sha256=sha(path),rows=r['rows'])
    inputs=profiles['primary-actor-member']['rows']+[row for row in profiles['humanoid-motion-member']['rows']if row['character']!=255 or row['index']in [0,1,2]]
    if a.custom:
        path=ROOT/'build-native-sjuni/primary-custom-statistic-profile-v1/receipt.json';custom=json.loads(path.read_bytes());assert custom['status']=='passed'and sha(ROOT/'game/native/gameplay_world/primary_custom_statistics.inc')==custom['output_sha256'];profiles['custom-statistics']=dict(path=str(path),sha256=sha(path),table=custom['table'])
        path=ROOT/'build-native-sjuni/npc-actor-member-profile-v1/receipt.json';substitutions=json.loads(path.read_bytes());assert substitutions['status']=='passed'and sha(ROOT/'game/native/gameplay_world/npc_actor_members.inc')==substitutions['output_sha256'];inputs+=substitutions['rows']
        inputs=list({row['member']:row for row in inputs}.values())
    inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json';assert sha(inventory)=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2';members={row['member']:row for row in json.loads(inventory.read_bytes())}
    archive=a.data_root/'NETBIO00.DAT';stamp=archive.stat().st_size,archive.stat().st_mtime_ns;assets=[]
    with archive.open('rb')as stream:
        outer=read_toc(stream,0);indices=[i for i,(name,_)in enumerate(outer[2])if name.lower()=='romdata_usa.afs'];assert len(indices)==1;base=outer[0][indices[0]][0];directory=read_toc(stream,base);assert len(directory[0])==1342
        for row in inputs:
            ordinal=row['member'];offset,length=directory[0][ordinal];assert directory[2][ordinal][0].lower()==row['name'].lower();stream.seek(base+offset);data=stream.read(length);expected=members[f'NETBIO00.DAT/{indices[0]}/{ordinal}'];assert len(data)==length==expected['bytes']and hashlib.sha256(data).hexdigest()==expected['sha256'];assets.append(dict(name=row['name'],member=ordinal,bytes=length,sha256=expected['sha256']))
    helpers=[Path(__file__),ROOT/'tools/native_reconstruction/primary_actor_initialization_reference.inc',ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp',ROOT/'tools/native_reconstruction/generate_primary_actor_definitions.py',ROOT/'runtime/assets/virtual_afs.h']
    if a.custom:helpers +=[ROOT/'tools/native_reconstruction/primary_custom_statistics_reference.inc',ROOT/'tools/native_reconstruction/generate_primary_custom_statistics.py',ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h']
    files=[p for p in (ROOT/'game/native').rglob('*')if p.is_file()and(p.suffix in ['.cpp','.hpp','.h','.inc']or p.name=='CMakeLists.txt')]+helpers+originals+[clear];before={p.relative_to(ROOT).as_posix():sha(p)for p in files};out.mkdir()
    for name in before:target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
    reference=(ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp').read_text().replace('Register r[32];','std::uint64_t lo{},hi{};Register r[32];')+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define FPU_DIV_S(a,b) ((a)/(b))\n#define FPU_C_EQ_S(a,b) ((a)==(b))\n'
    if a.custom:
        reference+='\n#include "ps2_fpu_convert.h"\n#define FPU_CVT_W_S(v) Ps2FpuConvertWord(v)\n';(out/'ps2_fpu_convert.h').write_bytes(helpers[-1].read_bytes())
    actual={p.stem for p in originals};body='\n'.join(p.read_text()for p in originals);calls=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body))
    reference+=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual))+''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(calls-actual))
    ranges=[(0x71adf0,0x90),(0x71b020,24),(0x71bd80,96),(0x71b988,4),(0x7346d8,8)]
    if a.custom:ranges +=[(0x71ad30,64),(0x71acf0,32),(0x716450,20*208)]
    for character in range(8):
        body_at=struct.unpack('<I',read(0x71bd80+4*character,4))[0];shape_table=struct.unpack('<I',read(0x71bda0+4*character,4))[0];shape=struct.unpack('<I',read(shape_table,4))[0];hit_table=struct.unpack('<I',read(0x71bdc0+4*character,4))[0];hit=struct.unpack('<I',read(hit_table,4))[0];ranges.extend([(body_at,56),(shape_table,4),(shape,20),(hit_table,4),(hit,100)])
    reference+='inline void owned_primary_constants(std::uint8_t* memory){\n'
    for address,length in dict.fromkeys(ranges):
        data=read(address,length);assert len(data)==length;reference+='{const std::uint8_t bytes[]{'+','.join(map(str,data))+'};std::memcpy(memory+'+str(address)+',bytes,sizeof bytes);}\n'
    if a.custom:
        zero=ROOT/'build-function-index/owned-overlays/o0.bin';assert sha(zero)=='bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2';table=zero.read_bytes()[0x3898e0-0x370000:0x3898e0-0x370000+custom['table']['bytes']];assert hashlib.sha256(table).hexdigest()==custom['table']['sha256'];reference+='{const std::uint8_t bytes[]{'+','.join(map(str,table))+'};std::memcpy(memory+0x3898e0,bytes,sizeof bytes);}\n';(out/'primary_custom_statistics_reference.inc').write_bytes((ROOT/'tools/native_reconstruction/primary_custom_statistics_reference.inc').read_bytes())
    (out/'primary_reference.hpp').write_text(reference+'}\n');(out/'primary_original.cpp').write_text(body);(out/'primary_actor_initialization_reference.inc').write_bytes(helpers[1].read_bytes())
    for name in ['ps2_runtime.h','ps2_runtime_macros.h','o2_functions.h']:(out/name).write_text('#pragma once\n#include "primary_reference.hpp"\n')
    for name in ['ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h']:(out/name).write_text('#pragma once\n')
    result=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(compiler),profiles=profiles,owned_assets=assets,original_owned_bodies=proof,declared_ports=['5D6850 constraint call observation; actual native constraints constructed and checked separately','Custom BB4 statistics and saved-state override are explicitly outside default initialization admission'],commands=[],game_run=False,installed_in_game=False,stage4_complete=False)
    if a.custom:result['declared_ports']=['5D6850 constraint call observation; actual native constraints constructed and checked separately','1AEC80 selector0 getter observation with the same canonical RNG word; no random advancement is invented','Saved-state override remains explicitly outside this fresh initialization admission']
    env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+str(a.cmake.parent)+os.pathsep+env.get('PATH','')
    commands=[('configure',[str(a.cmake),'-S',str(ROOT/'game/native'),'-B',str(build),'-DREO_PRIMARY_INITIALIZATION_REFERENCE_DIR='+str(out)]),('build',[str(a.cmake),'--build',str(build),'--parallel','2','--target','primary_actor_initialization_tests']),('owned',[str(build/'gameplay_world/primary_actor_initialization_tests.exe'),str(archive)]),('parents',[str(a.cmake.parent/'ctest.exe'),'--test-dir',str(build),'-R','^native_primary_actor_initialization$','--output-on-failure'])]
    commands[0][1].append('-DREO_PRIMARY_CUSTOM_STATISTICS_REFERENCE_DIR='+(str(out)if a.custom else''))
    if a.custom:
        commands[1][1].append('primary_custom_statistics_tests');commands.insert(-1,('custom',[str(build/'gameplay_world/primary_custom_statistics_tests.exe')]));commands[-1][1][-2]='^(native_primary_actor_initialization|native_primary_custom_statistics)$'
        extra=['humanoid_motion_assets_tests','humanoid_motion_publication_tests','npc_actor_construction_tests','cutscene_npc_construction_tests','npc_actor_assets_tests','cutscene_scripted_construction_tests','cutscene_descriptor_assets_tests','gameplay_actor_assets_tests','scripted_motion_assets_tests','gameplay_target_metrics_tests','gameplay_cooperative_events_tests','gameplay_collision_workers_tests','gameplay_ai_owner_tests']
        commands[1][1].extend(extra)
        commands[-1][1][-2]='^(native_primary_actor_initialization|native_primary_custom_statistics|native_humanoid_motion_assets|native_humanoid_motion_publication|native_npc_actor_construction|native_cutscene_npc_construction|native_npc_actor_assets|native_cutscene_scripted_construction|native_cutscene_descriptor_assets|native_gameplay_actor_assets|native_scripted_motion_assets|native_gameplay_target_metrics|native_gameplay_cooperative_events|native_gameplay_collision_workers|native_gameplay_ai_owner)$'
    try:
        for name,command in commands:
            done=subprocess.run(command,env=env,capture_output=True,timeout=240);(out/(name+'.stdout.txt')).write_bytes(done.stdout);(out/(name+'.stderr.txt')).write_bytes(done.stderr);result['commands'].append(dict(command=command,exit_code=done.returncode));assert done.returncode==0,name+' '+(done.stdout+done.stderr).decode(errors='replace')[-2500:]
            if name in ['owned','custom']:result[name]=json.loads(done.stdout)
            if name=='parents':assert ('100% tests passed, 0 tests failed out of '+str(15 if a.custom else 1)).encode()in done.stdout
        assert (archive.stat().st_size,archive.stat().st_mtime_ns)==stamp and all(sha(ROOT/name)==digest for name,digest in before.items());result.update(status='passed',source_unchanged=True)
    finally:
        result['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()};(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(dict(status=result['status'],owned=result['owned'])))
if __name__=='__main__':main()
