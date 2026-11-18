"""Qualify complete dialogue pool construction, selection, clear and record update bodies."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--archive',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 elf=ROOT/'game_data/SLUS_207.65';overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'and sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';read_main=elf_reader(elf.read_bytes());raw=overlay.read_bytes();read=lambda at,n:read_main(at,n)if at<0x570000 else raw[at-0x570000:at-0x570000+n]
 entries={};proof=[]
 for at in [0x6b7610,0x6b7810,0x6b7890,0x6b7930,0x6b9590,0x6b9e90,0x6b97d0,0x6b9750,0x6b9790,0x6b9e40,0x6b7350,0x6b7520,0x6ba230,0x6b7480,0x6b74d0,0x665dc0,0x191cc0,0x1920a0,0x1aec80,0x107c68,0x107ab0]:
  bank='o2'if at>=0x570000 else'sub';folder=ROOT/('recomp/config/output_ovl/o2'if bank=='o2'else'recomp/config/output');path=next(folder.glob(f'{bank}_{at:08X}_*'));begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',path.read_text()).groups()];proof.append(compare_source('complete dialogue update or reached scalar helper executed',path.relative_to(ROOT).as_posix(),begin,end,read));entries[at]=path.relative_to(ROOT).as_posix()
 units=['game/native/'+group+'/'+name+'.cpp'for group,names in [
 ('gameplay_world',['motion','world','linked_models','auxiliary_actors','scene_primary_actors','model_poses','model_constraints','bodies','target_metrics','cinematic_objects','secondary_pose_dynamics','secondary_pose_contacts','actor_voice_requests','dialogue_records','dialogue_pool']),
 ('gameplay_actors',['entity','input','health']),('gameplay_collision',['collision','response','actors','actor_views','trace']),
 ('animation',['model','model_math','curves','constraints','constraint_math','playback','model_blend','motion_bank','scalar_playback','secondary_pose_math']),('transform_math',['transform_math','heading']),('gameplay_scenario',['content','scene_controls','flags','scene_matrix_programs','scene_matrix_tables','scene_models','scene_model_bindings','stream_channels','dialogue_assets','scenario_archive']),('gameplay_session',['session']),('gameplay_navigation',['bank']),('gameplay_audio',['spatial','routing'])]for name in names]
 files=set(units);pending=list(units)
 while pending:
  name=pending.pop()
  for rel in re.findall(r'^#include "([^"\n]+)"',(ROOT/name).read_text(),re.M):
   dep=((ROOT/name).parent/rel).resolve();dep=dep if dep.is_file()else(ROOT/rel).resolve();assert dep.is_file()and dep.is_relative_to(ROOT),(name,rel);key=dep.relative_to(ROOT).as_posix()
   if key not in files:files.add(key);pending.append(key)
 helpers=['tools/native_reconstruction/dialogue_pool_tests.cpp','tools/native_reconstruction/verify_dialogue_pool.py','tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp','third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h'];files=sorted(files)+helpers+list(entries.values());before={name:sha(ROOT/name)for name in files};out.mkdir();result=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(a.compiler),original_owned_bodies=proof,game_run=False,audio_device_opened=False,stage4_complete=False,limits=['Complete6B7930/6B9590/6B7810/6B7890/6B9E90/6B97D0 and reached helpers execute. Complete6B7610 executes as a projection onto represented actor/record/flag fields; its other timer/monitor roles are not installed by this owner.','Presentation cache erase/draw/query and bounded no-format string copies are declared controlled primitives. Outer6B7E40 actor response orchestration, complete1D41F0 room-bank publication and actual UI cache/renderer ownership remain separate integration.','The separately qualified1BA250 marker0 leaf is the declared original voice boundary; native advances the real ActorVoiceRequests helper against an explicit known-zero archive marker. No playback source or audio device starts.','Finite bounded text/buffer and corruption-index profiles; source overruns or unavailable capabilities are refused preserving the completed prefix. One controlled retained copy changes an owned text prefix to8169 to exercise the constructor literal branch, which no owned USA text reaches.'])
 try:
  asset_path=ROOT/'build-native-sjuni/dialogue-assets-gcc-v1/receipt.json';asset_parent=json.loads(asset_path.read_bytes());assert asset_parent['status']=='passed';result['owned_asset_parent']=dict(path=asset_path.relative_to(ROOT).as_posix(),sha256=sha(asset_path));result['owned_assets']=[];stamp=a.archive.stat().st_size,a.archive.stat().st_mtime_ns
  with a.archive.open('rb')as stream:
   for row in asset_parent['owned_assets']:
    if row['name'].lower()not in {'sp010000.bin','sp010001.bin','sp010008.bin','spm010000.bin','spm010001.bin','spm010008.bin'}:continue
    stream.seek(row['offset']);data=stream.read(row['bytes']);assert len(data)==row['bytes']and hashlib.sha256(data).hexdigest()==row['sha256'];result['owned_assets'].append(row)
  assert len(result['owned_assets'])==6
  for name in files:
   target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
  header=(ROOT/helpers[2]).read_text().replace('Register r[32];','std::uint64_t lo{},hi{};Register r[32];')+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define FPU_ABS_S(v) std::fabs(v)\n#define SRA32(v,n) (std::int32_t(v)>>(n))\n#define PS2_PCPYLD(a,b) _mm_unpacklo_epi64((b),(a))\n#include "ps2_fpu_convert.h"\n#define FPU_CVT_W_S(v) Ps2FpuConvertWord(v)\n';(out/'reference.hpp').write_text(header);(out/'ps2_fpu_convert.h').write_bytes((ROOT/helpers[3]).read_bytes())
  body='\n'.join((ROOT/name).read_text()for name in entries.values());actual={Path(name).stem for name in entries.values()};calls=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual));decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(calls-actual));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text(body);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+Path(name).stem+'(memory,context,runtime);return;\n'for at,name in entries.items()))
  for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
  for name in ['o2_functions.h','ps2_recompiled_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
  for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
  constants=[]
  for at,n in [(0x740cd8,4),(0x723a98,4),(0x740cc8,8),(0x740cb8,8),(0x740cc0,8)]:constants.append('{const std::uint8_t b[]{'+','.join(map(str,read(at,n)))+'};std::memcpy(p+'+str(at)+',b,sizeof b);}')
  (out/'owned_constants.hpp').write_text('inline void owned_constants(std::uint8_t* p){\n'+'\n'.join(constants)+'\n}\n');env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'checks.exe';command=[str(a.compiler),'-std=c++20','-DREO_DIALOGUE_RECORDS_ORIGINAL=1','-O2','-msse4.1','-ffunction-sections','-fdata-sections','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/name)for name in units],str(out/'source'/helpers[0]),str(out/'original.cpp'),'-Wl,--gc-sections','-o',str(binary)];result['command']=command
  for label,cmd in [('compile',command),('run',[str(binary),str(a.archive.resolve())])]:
   done=subprocess.run(cmd,env=env,capture_output=True,timeout=300);(out/(label+'.txt')).write_bytes(done.stdout+done.stderr);assert done.returncode==0,label+' failed: '+(done.stdout+done.stderr).decode(errors='replace')[-1500:]
   if label=='run':result['observed']=json.loads(done.stdout)
  assert stamp==(a.archive.stat().st_size,a.archive.stat().st_mtime_ns)
  result['snapshot_unchanged']=all(sha(out/'source'/name)==digest for name,digest in before.items());assert result['snapshot_unchanged'];result['live_source_drift']=[name for name,digest in before.items()if not(ROOT/name).is_file()or sha(ROOT/name)!=digest];result['status']='passed'
 finally:
  result['output_sha256']={path.relative_to(out).as_posix():sha(path)for path in out.iterdir()if path.is_file()and path.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n')
 print(json.dumps(dict(status=result['status'],observed=result['observed'],live_source_drift=result['live_source_drift'])))
if __name__=='__main__':main()
