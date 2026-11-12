"""Compare complete scene voice preparation, actual name resolution and prepared/playlist helper policies."""
import argparse,hashlib,json,os,re,struct,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
from audit_retail_effect_descriptors import compare_source,elf_reader
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read_main=elf_reader(elf.read_bytes());overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=overlay.read_bytes();read=lambda at,n:read_main(at,n)if at<0x570000 else raw[at-0x570000:at-0x570000+n]
 entries={}
 for at in [0x6d73f0,0x6d7470,0x6d7520,0x1ae7d0,0x1ae6d0,0x1ae9f0,0x1aea70,0x1adf00,0x1adfd0,0x1b82a0,0x132df0,0x1ab050,0x1ab2f0]:
  bank='o2'if at>=0x570000 else'sub';directory=ROOT/('recomp/config/output_ovl/o2'if bank=='o2'else'recomp/config/output');entries[at]=next(directory.glob(f'{bank}_{at:08X}_*')).relative_to(ROOT).as_posix()
 originals=sorted(set(entries.values()));proof=[]
 for name in originals:
  begin,end=[int(x,16)for x in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',(ROOT/name).read_text()).groups()];proof.append(compare_source('complete playback, queue, acknowledgement or native stream-control body',name,begin,end,read))
 units=['game/native/'+group+'/'+name+'.cpp'for group,names in [
  ('gameplay_world',['world','linked_models','auxiliary_actors','scene_primary_actors','model_poses','model_constraints','bodies','cinematic_objects','cinematic_object_attachment','model_attachments','scripted_motion','cutscene_actor','motion_transforms','surface_orientation','surface_orientation_math','humanoid_motion_bindings']),
  ('gameplay_actors',['entity','input','health']),('gameplay_collision',['collision','response','actors','actor_views']),
  ('animation',['model','model_math','curves','constraints','constraint_math','playback','model_blend','motion_bank','scalar_playback']),('transform_math',['transform_math']),('gameplay_session',['session']),('gameplay_navigation',['bank']),
  ('gameplay_scenario',['cutscene_cues','cutscene_requests','flags','stream_channels','scene_voice_assets','scene_voice_preparation','scene_resources','resource_templates'])]for name in names]
 files=set(units);pending=list(units)
 while pending:
  name=pending.pop()
  for rel in re.findall(r'^#include "([^"\n]+)"',(ROOT/name).read_text(),re.M):
   dep=((ROOT/name).parent/rel).resolve()
   if not dep.is_file():dep=(ROOT/rel).resolve()
   assert dep.is_file()and dep.is_relative_to(ROOT),(name,rel);key=dep.relative_to(ROOT).as_posix()
   if key not in files:files.add(key);pending.append(key)
 helpers=['tools/native_reconstruction/scene_voice_policy_tests.cpp','tools/native_reconstruction/verify_scene_voice_policy.py','tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp','third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h']
 files=sorted(files)+helpers+originals;before={name:sha(ROOT/name)for name in files};out.mkdir();record=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(a.compiler),original_owned_bodies=proof,game_run=False,installed_in_game=False,stage4_complete=False,limits=['Complete6D73F0/6D7470/6D7520, actual1AE prepared/playlist policies and1AB050/1AB2F0 name normalization execute against pinned File1 code/data.','Formatting and standard string primitives are declared references; actual ADXT start/pause/list SDK calls are primitive observations.','Canonical real loader/queue/source ownership is independently qualified; this test does not install scene playback or establish movie/scene lifecycle.'])
 try:
  for name in files:
   target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
  reference='#include <string>\n'+(ROOT/helpers[2]).read_text().replace('Register r[32];','std::uint64_t lo{},hi{},lo1{},hi1{};Register r[32];').replace('throw std::runtime_error("original transform read bound")','throw std::runtime_error("original transform read bound at "+std::to_string(at))')+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define SRA32(v,n) (std::int32_t(v)>>(n))\n#include "ps2_fpu_convert.h"\n#define FPU_CVT_W_S(v) Ps2FpuConvertWord(v)\n';(out/'reference.hpp').write_text(reference);(out/'ps2_fpu_convert.h').write_bytes((ROOT/helpers[3]).read_bytes())
  body='\n'.join((ROOT/name).read_text()for name in originals);body=body.replace('void sub_001B0300_0x1b0300(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {','void sub_001B0300_0x1b0300(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {\n    if(ctx->pc==0x1b0310u)goto playback_entry_1b0310;').replace('    // 0x1b0310:', 'playback_entry_1b0310:\n    // 0x1b0310:');actual={Path(name).stem for name in originals};names=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual));decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(names-actual));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text(body);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+Path(name).stem+'(memory,context,runtime);return;\n'for at,name in sorted(entries.items())))
  for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
  for name in ['o2_functions.h','ps2_recompiled_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
  for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
  constants='inline void owned_constants(std::uint8_t* p){\n';record['owned_constants']={}
  for at,n in [(0x7426b8,64),(0x70c550,64),(0x73ed90,28),(0x234060,512)]:
   data=read(at,n);record['owned_constants'][hex(at)]=data.hex();constants+='{const std::uint8_t b[]{'+','.join(map(str,data))+'};std::memcpy(p+'+str(at)+',b,sizeof b);}\n'
  (out/'owned_constants.hpp').write_text(constants+'}\n')
  main_bytes=elf.read_bytes();phoff=struct.unpack_from('<I',main_bytes,28)[0];phsize,phcount=struct.unpack_from('<HH',main_bytes,42);segments=[]
  for i in range(phcount):
   entry=struct.unpack_from('<8I',main_bytes,phoff+phsize*i)
   if entry[0]==1 and entry[4]:segments.append((entry[2],main_bytes[entry[1]:entry[1]+entry[4]]))
  segments.append((0x570000,raw));(out/'owned-voice.bin').write_bytes(struct.pack('<I',len(segments))+b''.join(struct.pack('<II',at,len(data))+data for at,data in segments));env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'checks.exe';command=[str(a.compiler),'-std=c++20','-O2','-msse4.1','-ffunction-sections','-fdata-sections','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/name)for name in units],str(out/'source'/helpers[0]),str(out/'original.cpp'),'-Wl,--gc-sections','-o',str(binary)];record['command']=command
  result=subprocess.run(command,env=env,capture_output=True,timeout=240);(out/'compile.txt').write_bytes(result.stdout+result.stderr);assert result.returncode==0,'compile failed'
  result=subprocess.run([str(binary),str(out/'owned-voice.bin')],env=env,capture_output=True,timeout=180);(out/'run.txt').write_bytes(result.stdout+result.stderr);assert result.returncode==0,'comparison failed'
  record.update(status='passed',observed=json.loads(result.stdout),source_unchanged=all(sha(ROOT/name)==digest for name,digest in before.items()));assert record['source_unchanged']
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(dict(status=record['status'],observed=record['observed'])))
if __name__=='__main__':main()
