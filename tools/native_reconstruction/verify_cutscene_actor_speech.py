"""Compare concrete cinematic speech over the fixed lookup and sole facial owner."""
import argparse,hashlib,json,os,re,shutil,struct,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 parent=ROOT/'build-native-sjuni'/f'facial-motions-current-{a.compiler}-v1';prior=json.loads((parent/'receipt.json').read_bytes());assert prior['status']=='passed'
 units=['game/native/gameplay_scenario/'+name+'.cpp'for name in ['cutscene_actor_speech','facial_assets','facial_motions','cutscene_playback']]+['game/native/gameplay_world/world.cpp','game/native/animation/facial_curves.cpp','game/native/animation/facial_pose_math.cpp','game/native/gameplay_bank_loading/aliases.cpp']
 fixture='tools/native_reconstruction/cutscene_actor_speech_tests.cpp';reference='tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
 owned={*units,'game/native/gameplay_scenario/cutscene_actor_speech.hpp',fixture,Path(__file__).relative_to(ROOT).as_posix(),'game/native/gameplay_scenario/facial_motions.hpp','game/native/gameplay_scenario/facial_assets.hpp','game/native/gameplay_scenario/facial_asset_catalogue.inc','game/native/gameplay_scenario/cutscene_playback.hpp','game/native/animation/facial_curves.hpp','game/native/animation/facial_pose_math.hpp'}
 frozen={}
 for name,digest in prior['source_sha256'].items():
  path=parent/'source'/name
  if path.is_file():assert sha(path)==digest;frozen[name]=path.read_bytes()
 pending=list(owned)+[reference,'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h']
 for name in pending:
  if name not in frozen or name in owned:frozen[name]=(ROOT/name).read_bytes()
  if name.startswith('game/native/'):
   for include in re.findall(r'^\s*#include "([^"]+)"',frozen[name].decode(),re.M):
    target=((ROOT/name).parent/include).resolve();target=target if target.is_file()else(ROOT/include).resolve();assert target.is_file()and target.is_relative_to(ROOT);relative=target.relative_to(ROOT).as_posix()
    if relative not in pending:pending.append(relative)
 image=ROOT/'game_data/SLUS_207.65';assert sha(image)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read_main=elf_reader(image.read_bytes());overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';bank=overlay.read_bytes();read=lambda at,n:read_main(at,n)if at<0x570000 else bank[at-0x570000:at-0x570000+n]
 entries={};proof=[]
 for address in [0x1adb30,0x1ab2f0,0x1ab050,0x10afc0,0x10b158,0x10ae78,0x10cda8,0x5eec50,0x67c250,0x67c2e0,0x67c590,0x67c6d0,0x67c990,0x18fdf0,0x191500,0x1a5050,0x1a5180,0x1a51b0,0x1a5220]:
  owner='sub'if address<0x570000 else'o2';folder=ROOT/('recomp/config/output'if owner=='sub'else'recomp/config/output_ovl/o2');path=next(folder.glob(f'{owner}_{address:08X}_*'));name=path.relative_to(ROOT).as_posix();body=path.read_bytes();start,end=[int(value,16)for value in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',body.decode()).groups()];proof.append(compare_source('complete facial reset, preload, claim, eight-instance update or matrix math',name,start,end,read));entries[address]=name;frozen[name]=body
 out.mkdir()
 for name,body in frozen.items():target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(body)
 sdk=ROOT/'build-native-sjuni/dependency-muted-rna-reapply-v1/ps2xRuntime/include/ps2_runtime_macros.h';macros='\n'.join(next(line for line in sdk.read_text().splitlines()if line.startswith('#define '+name+'('))for name in ['PS2_PSUBW','PS2_PSUBB','PS2_PAND','PS2_PNOR','PS2_PCPYLD']);(out/'sdk_macros.txt').write_text(macros);(out/'reference.hpp').write_text(frozen[reference].decode()+macros+'\n#define GPR_S32(c,n) std::bit_cast<std::int32_t>(GPR_U32(c,n))\n#define SLLV32(a,b) (std::uint32_t(a)<<(unsigned(b)&31))\n#define SRA32(a,b) (std::int32_t(a)>>(unsigned(b)&31))\n#define DSLL32(a,b) (std::uint64_t(a)<<(unsigned(b)+32))\n#define DSRA32(a,b) (std::int64_t(a)>>(unsigned(b)+32))\n#include "third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h"\n#define FPU_CVT_W_S(a) Ps2FpuConvertWord(a)\n#define FPU_SQRT_S(value) std::sqrt(value)\n#define FPU_DIV_S(a,b) ((a)/(b))\n#define FPU_C_EQ_S(a,b) ((a)==(b))\n#define PS2_VOPMUL(a,b) _mm_mul_ps(_mm_shuffle_ps((a),(a),_MM_SHUFFLE(3,0,2,1)),_mm_shuffle_ps((b),(b),_MM_SHUFFLE(3,1,0,2)))\n')
 body='\n'.join(frozen[name].decode()for name in entries.values());actual={Path(name).stem for name in entries.values()};called=set(re.findall(r'\b((?:sub|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual));decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(called-actual));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text(body);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(address)+':'+Path(name).stem+'(memory,context,runtime);return;\n'for address,name in entries.items()))
 for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
 for name in ['ps2_recompiled_functions.h','o2_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
 for name in ['ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h']:(out/name).write_text('#pragma once\n')
 constants='inline void owned_constants(std::uint8_t* p){\n'
 constant_segments=[(0x740640,256),(0x73ed70,64),(0x2337c0,422*4),(0x2376e9,256)]
 for pointer in struct.unpack('<422I',read_main(0x2337c0,422*4)):
  encoded=read_main(pointer,256).split(b'\0')[0];constant_segments.append((pointer,len(encoded)+1))
 for at,n in constant_segments:data=read(at,n);constants+='{const std::uint8_t b[]{'+','.join(map(str,data))+'};std::memcpy(p+'+str(at)+',b,sizeof b);}\n'
 constants+='const auto identity=reo::native::transform_math::identity();std::memcpy(p+0x294e00,identity.data(),64);\n}\n';(out/'owned_constants.hpp').write_text(constants)
 libraries=[]
 for name,digest in prior['native_library_sha256'].items():
  source=parent/'libraries'/name;assert sha(source)==digest;target=out/'libraries'/name;target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(source,target);libraries.append(str(target))
 inventory=ROOT/'build-native-sjuni/facial-resource-inventory-v2/receipt.json';data=json.loads(inventory.read_bytes());matrices=ROOT/'build-native-sjuni/facial-pose-math-llvm-v5/receipt.json'
 if not matrices.is_file():matrices=ROOT/'build-native-sjuni/animation-facial-pose-math-llvm-v5/receipt.json'
 assert matrices.is_file(),str(matrices)
 matrix_data=json.loads(matrices.read_bytes());identity=json.loads((ROOT/'build-native-sjuni/primary-scene-scope-llvm-v4/receipt.json').read_bytes());archive=Path(identity['commands'][2]['command'][1]);stamp=archive.stat().st_size,archive.stat().st_mtime_ns;manifest=[];model_manifest=[]
 with archive.open('rb')as source:
  for row in data['matrix_assets']:
   actor=re.fullmatch(r'MOTION_FACE_(HP\d{2}|HN\d{2,3})_MAT',row['key'])[1];kind=0 if actor.startswith('HP')else 1;character=int(actor[2:]);name=f'data\\rom\\motion\\face\\{actor.lower()}.mat';manifest.append([kind,character,0,0,0,0,row['archive_offset'],row['logical_bytes'],row['storage_bytes'],name])
   model_row=next(item for item in matrix_data['owned_assets']if item['key']==row['key']);assert model_row['facial_nodes'];ordinal=model_row['model_ordinal']
   # Independent raw AFS extent read; the immutable oracle receipt pins this
   # exact model. The production importer still constructs its own skeleton.
   import sys
   sys.path.insert(0,str(ROOT/'tools/assets'));from afs_inspect import read_toc
   root,_,names=read_toc(source,0);base,_=next(entry for entry,(name,_)in zip(root,names)if name.lower()=='romdata_usa.afs');entries,_,_=read_toc(source,base);at,length=entries[ordinal];source.seek(base+at);model=source.read(length);assert hashlib.sha256(model).hexdigest()==model_row['model_sha256'];at,length=struct.unpack_from('<II',model,0x24);raw=model[at:at+length];assert hashlib.sha256(raw).hexdigest()==model_row['skeleton_sha256'];model_manifest.append(' '.join(map(str,[kind,character,len(raw),*raw])))
  for row in data['lip_assets']:
   scenario,cue,voice,speaker=row['identity'];manifest.append([2,0,scenario,cue,voice,speaker,row['archive_offset'],row['logical_bytes'],row['storage_bytes'],f'data\\rom\\motion\\face\\r{scenario:03d}\\lip{cue:02d}_{voice:02d}_{speaker:01d}.bin'])
 (out/'assets.txt').write_text('\n'.join(' '.join(map(str,row))for row in manifest)+'\n');(out/'models.txt').write_text('\n'.join(model_manifest)+'\n')
 descriptor_inventory=ROOT/'build-native-sjuni/cutscene-descriptor-inventory-v2/receipt.json';descriptors=json.loads(descriptor_inventory.read_bytes());loaded_scenarios={(row['scenario'],row['name']):row['layout']['identity'][0]for row in descriptors['rows']if row['version']=='0950'};assert len(loaded_scenarios)==548
 cue_rows=[(loaded_scenarios[scene['scenario'],scene['name']],int(scene['name'][2:4]),request['voice']if request['voice']<32768 else request['voice']-65536)for scene in data['scenes']for request in scene['requests']];assert len(cue_rows)==77;(out/'cues.txt').write_text('\n'.join(' '.join(map(str,row))for row in cue_rows)+'\n')
 compiler=COMPILERS[a.compiler];env=dict(os.environ,PATH=str(compiler.parent)+os.pathsep+os.environ.get('PATH',''));exe=out/'checks.exe';command=[str(compiler),'-std=c++20','-O2','-msse4.1','-ffunction-sections','-fdata-sections','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/name)for name in units],str(out/'source'/fixture),str(out/'original.cpp'),'-Wl,--gc-sections','-Wl,--start-group',*libraries,'-Wl,--end-group','-o',str(exe)]
 record=dict(schema=1,status='failed',compiler_sha256=sha(compiler),source_sha256={name:hashlib.sha256(body).hexdigest()for name,body in frozen.items()},native_parent=dict(path=parent.relative_to(ROOT).as_posix()+'/receipt.json',sha256=sha(parent/'receipt.json')),native_library_sha256=prior['native_library_sha256'],archive_identity=dict(size=stamp[0],mtime_ns=stamp[1]),inventory_sha256=sha(inventory),descriptor_inventory_sha256=sha(descriptor_inventory),model_inventory_sha256=sha(matrices),original_owned_bodies=proof,command=command,game_run=False,stage4_complete=False,limits=['Nineteen complete original bodies execute, including5EEC50 and actual1ADB30/fixed-catalogue lookup/string helpers; formatter10A830 and sector-transfer1CC8F0 are explicit fixture ports. Sector bytes come from independent actual File1 reads and the compiled51-key namespace has a separate concrete-reader qualification. SDK scheduling is not re-executed.','Actual18 base-model skeletons import through native animation::Skeleton; only33 owned clip/character pairings and admitted finite MAT ordinals execute. Source model representation is projected from the same raw topology/track identity, with all nodes/world matrices compared after each visit.','Existing current-facial CMake source/libraries remain matching immutable ABI inputs; new Playback.cpp and World.cpp override their archive units so the controller-owned worker and inline busy close guard use the new exact header. No game, media device, scene-entry provider or complete5FF1B0 orchestration is established.'])
 try:
  result=subprocess.run(command,env=env,capture_output=True,timeout=300);(out/'compile.txt').write_bytes(result.stdout+result.stderr);assert result.returncode==0,'compile failed'
  record['run_command']=[str(exe),str(archive),str(out/'assets.txt'),str(out/'models.txt'),str(out/'cues.txt')];result=subprocess.run(record['run_command'],env=env,capture_output=True,timeout=300);(out/'run.txt').write_bytes(result.stdout+result.stderr);assert result.returncode==0,'comparison failed';assert stamp==(archive.stat().st_size,archive.stat().st_mtime_ns)
  record.update(status='passed',observed=json.loads(result.stdout),owned_source_drift={name:sha(ROOT/name)for name in owned if(ROOT/name).read_bytes()!=frozen[name]});assert not record['owned_source_drift']
 finally:
  record['output_sha256']={path.relative_to(out).as_posix():sha(path)for path in out.rglob('*')if path.is_file()and path.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(record['observed']))
if __name__=='__main__':main()
