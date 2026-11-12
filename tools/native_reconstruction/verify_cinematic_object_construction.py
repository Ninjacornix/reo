"""Qualify actual cinematic object preparation and bounded scene construction."""
import argparse,hashlib,json,os,re,struct,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
from verify_gameplay_collision import COMPILERS
from verify_cinematic_object_assets import PORTS,ALIASES
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
SCENE_PORTS={0x107c68,0x10a830,0x5ed900,0x5ebe30,0x1d2560,0x5c0920,0x6b38d0,0x5c0d50,0x1bbb10,0x67c250,0x1d4870,0x5d7d60,0x576f10,0x1d1cc0,0x1d1e00,0x1d2520,0x1d1220,0x1d4130,0x5f0dc0,0x5f0c00,0x5eda40,0x5ebdb0,0x67c2e0,0x663170,0x5ec100,0x5d6850,0x5f0b50,0x6837c0,0x377560,0x3777b0,0x6ba5c0}
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True)
 for name in ['build','cmake','archive','output']:p.add_argument('--'+name,type=Path,required=True)
 a=p.parse_args();compiler=COMPILERS[a.compiler];build=a.build.resolve();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 assert Path(re.search(r'^CMAKE_CXX_COMPILER:[^=]+=([^\n]+)',(build/'CMakeCache.txt').read_text(),re.M)[1].strip()).resolve()==compiler.resolve()
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read_main=elf_reader(elf.read_bytes());overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';two=overlay.read_bytes();read=lambda at,n:read_main(at,n)if at<0x570000 else two[at-0x570000:at-0x570000+n]
 pending=[0x5ecf90,0x5f0610,0x5f1390,0x571010,0x1d13f0,0x1d25b0,0x1d2c00];entries={}
 while pending:
  at=pending.pop()
  if at in entries or at in PORTS|SCENE_PORTS:continue
  original=ALIASES.get(at,at);bank='o2'if original>=0x570000 else 'sub';directory=ROOT/('recomp/config/output_ovl/o2'if bank=='o2'else 'recomp/config/output');path=next(directory.glob(f'{bank}_{original:08X}_*'));name=path.relative_to(ROOT).as_posix();entries[at]=name
  pending.extend(int(v,16)for v in re.findall(r'// 0x[0-9a-f]+: 0x[0-9a-f]+\s+(?:jal|j)\s+func_([0-9A-Fa-f]+)',path.read_text()))
 originals=sorted(set(entries.values()));proof=[]
 for name in originals:
  begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',(ROOT/name).read_text()).groups()];proof.append(compare_source('complete cinematic object scene reservation/construction body',name,begin,end,read))
 descriptors=ROOT/'build-native-sjuni/cutscene-descriptor-inventory-v2';dr=json.loads((descriptors/'receipt.json').read_bytes());assert dr['status']=='static_layout_inventory'and sha(descriptors/'owned_descriptors.bin')==dr['package_sha256']=='047d14cca0b28ad1f4335660db09389a525679c313f1841bfda1779c2c49629c'
 inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json';assert sha(inventory)=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2';names={(x['names'][0].lower(),name.lower())for x in json.loads(inventory.read_bytes())for name in x['names'][1:]}
 blocks=[];data=(descriptors/'owned_descriptors.bin').read_bytes();at=4
 for _ in range(struct.unpack_from('<I',data)[0]):size=struct.unpack_from('<I',data,at)[0];at+=4;blocks.append(data[at:at+size]);at+=size
 assert at==len(data);rows=sorted((x for x in dr['rows']if x['status']=='bounded_layout'),key=lambda x:x['package_index']);assert len(rows)==548;lines=[];expected_missing=0
 for row in rows:
  match=re.fullmatch(r'dm(\d{2})(\d{2})([a-z])\.bin',row['name'],re.I);assert match;request=[int(match[1]),int(match[2]),ord(match[3].lower())-97];blob=blocks[row['package_index']];available=True
  for group in row['layout']['objects']:
   header=group[2];assert header['count']and struct.unpack_from('<H',blob,header['offset']+2)[0]!=65535;model=struct.unpack_from('<i',blob,header['offset']+8)[0];name='obj%02d_%02d_%s_%02d.nbd'%(request[0],request[1],match[3].lower(),model);available&=('r%03d.afs'%row['layout']['identity'][0],name)in names
  lines.append(' '.join(map(str,[*request,int(available),row['name']])));expected_missing+=not available
 helpers=['tools/native_reconstruction/cinematic_object_construction_tests.cpp','tools/native_reconstruction/verify_cinematic_object_construction.py','tools/native_reconstruction/verify_cinematic_object_assets.py','tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp','third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h','runtime/assets/virtual_afs.h'];native=[x.relative_to(ROOT).as_posix()for x in(ROOT/'game/native').rglob('*')if x.is_file()and(x.suffix in ['.cpp','.hpp','.h','.inc']or x.name=='CMakeLists.txt')];files=native+helpers+originals;before={name:sha(ROOT/name)for name in files};stamp=a.archive.stat().st_size,a.archive.stat().st_mtime_ns;out.mkdir();record=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(compiler),game_run=False,installed_in_game=False,stage4_complete=False,expected_missing_scenes=expected_missing,original_owned_bodies=proof,descriptor_inputs=dict(receipt_sha256=sha(descriptors/'receipt.json'),package_sha256=dr['package_sha256']),limits=['Complete5ECF90/5F0610 execute with actual owned object headers and requests derived from descriptor filenames. Other actor/scenario/media phases are declared ports with no projected actor groups. This is not full scene execution.','Complete1D13F0/material/root packing/local/inverse construction executes through bounded allocator and renderer ports. Actual archive loading is native; combined legacy loaders remain boundaries.','Unavailable candidate requests are explicit and do not mutate a live World. The55 unresolved model occurrences and aliases are not guessed.','Preparation, reservation, model ownership, stream installation and generation retirement are qualified components; no renderer/game installation or whole Step4 acceptance.'],commands=[])
 try:
  for name in files:
   target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
  (out/'owned_descriptors.bin').write_bytes(data);(out/'requests.txt').write_text('\n'.join(lines)+'\n')
  reference=(ROOT/helpers[3]).read_text().replace('pc{},branch_pc{},fcr31{}','pc{},branch_pc{},fcr31{},vu0_vpu_stat{}').replace('Register r[32];','std::uint64_t lo{},hi{},lo1{},hi1{};Register r[32];')
  reference+='\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define FPU_DIV_S(a,b) ((a)/(b))\n#define FPU_C_EQ_S(a,b) ((a)==(b))\n#define FPU_SQRT_S(a) std::sqrt(a)\n#define PS2_VOPMUL(a,b) _mm_mul_ps(_mm_shuffle_ps((a),(a),_MM_SHUFFLE(3,0,2,1)),_mm_shuffle_ps((b),(b),_MM_SHUFFLE(3,1,0,2)))\n#define SRA32(v,n) (std::int32_t(v) >> (n))\n#include "ps2_fpu_convert.h"\n#define FPU_CVT_W_S(v) Ps2FpuConvertWord(v)\n';(out/'reference.hpp').write_text(reference);(out/'ps2_fpu_convert.h').write_bytes((ROOT/helpers[4]).read_bytes())
  body='\n'.join((ROOT/name).read_text()for name in originals);actual={Path(name).stem for name in originals};names=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual));decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(names-actual));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text(body);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+Path(name).stem+'(memory,context,runtime);return;\n'for at,name in sorted(entries.items())if at!=0x1d13f0))
  for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
  for name in ['o2_functions.h','ps2_recompiled_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
  for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
  constants='inline void owned_constants(std::uint8_t* p){\n';record['owned_constants']={}
  for at,size in [(0x22fe20,32),(0x241c78,40),(0x241e90,4)]+[(at,len(read(at,128).split(b'\0',1)[0])+1)for at in [0x73edb0,0x73edf0]]:
   raw=read(at,size);record['owned_constants'][hex(at)]=raw.hex();constants+='{const std::uint8_t b[]{'+','.join(map(str,raw))+'};std::memcpy(p+'+str(at)+',b,sizeof b);}\n'
  (out/'owned_constants.hpp').write_text(constants+'}\n')
  env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','');binary=build/'gameplay_world/cinematic_object_construction_tests.exe';commands=[('configure',[str(a.cmake),'-S',str(ROOT/'game/native'),'-B',str(build),'-DREO_CINEMATIC_OBJECT_CONSTRUCTION_REFERENCE_DIR:PATH='+out.as_posix()]),('build',[str(a.cmake),'--build',str(build),'--parallel','4','--target','cinematic_object_construction_tests']),('test',[str(binary),str(a.archive.resolve()),str(out/'owned_descriptors.bin'),str(out/'requests.txt')])]
  for label,cmd in commands:
   done=subprocess.run(cmd,env=env,capture_output=True,timeout=240);(out/(label+'.stdout.txt')).write_bytes(done.stdout);(out/(label+'.stderr.txt')).write_bytes(done.stderr);record['commands'].append(dict(command=cmd,exit_code=done.returncode));assert done.returncode==0,label+' '+(done.stdout+done.stderr).decode(errors='replace')[-2400:]
   if label=='test':record['observed']=json.loads(done.stdout);assert record['observed']['missing_scenes']==expected_missing
  assert all(sha(ROOT/name)==h for name,h in before.items())and(a.archive.stat().st_size,a.archive.stat().st_mtime_ns)==stamp;record.update(status='passed',source_unchanged=True,binary_sha256=sha(binary))
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(dict(status=record['status'],observed=record['observed'])))
if __name__=='__main__':main()
