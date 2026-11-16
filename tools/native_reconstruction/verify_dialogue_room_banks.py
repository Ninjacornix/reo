"""Execute complete original1D41F0 bank loading and6B7720 reset against canonical owners."""
import argparse,hashlib,json,os,re,shutil,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--build',type=Path,required=True);p.add_argument('--parent',type=Path,required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--archive',type=Path,required=True);p.add_argument('--snapshot-only',action='store_true');p.add_argument('--native-snapshot',type=Path);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');parent=json.loads(a.parent.read_text());assert parent['status']=='passed'and not parent['source_drift']and parent['parent_tests']>=28;assert sha(a.compiler)==parent['compiler_sha256']
 fixture='tools/native_reconstruction/dialogue_room_banks_tests.cpp'
 frozen=a.native_snapshot.resolve()if a.native_snapshot else None
 previous=json.loads((frozen/'receipt.json').read_text())if frozen else None
 if previous:
  assert previous['snapshot_ready']and previous['compiler_sha256']==sha(a.compiler)
  for name,digest in previous['source_sha256'].items():assert sha(frozen/'source'/name)==digest,name
 else:
  for name,digest in parent['source_sha256'].items():assert sha(ROOT/name)==digest,name
 if previous:archive_names=list(previous['native_archives'])
 else:
  ninja=(a.build/'build.ninja').read_text();archive_names=[]
  for target in ['gameplay_world/dialogue_response_contract_tests','gameplay_application/native_session_tests','gameplay_world/pose_callbacks_contract_tests']:
   section=re.search(r'^build '+target+r'\.exe:.*?(?=\n\n)',ninja,re.M|re.S).group();link_line=re.search(r'^  LINK_LIBRARIES = (.*)$',section,re.M)[1];archive_names+=re.findall(r'(\S+\.a)(?:\s|$)',link_line)
  archive_names=list(dict.fromkeys(archive_names));assert len(archive_names)>20 and 'gameplay_update/libreo_native_gameplay_reception.a'in archive_names
 out.mkdir();record=dict(schema=1,status='failed',game_run=False,audio_device_opened=False,stage4_complete=False,parent=dict(path=a.parent.resolve().relative_to(ROOT).as_posix(),sha256=sha(a.parent)),compiler_sha256=sha(a.compiler),source_sha256={},native_archives={},limits=['Complete1D41F0/6B7720/6B7350/6B73F0 and admitted selected-scenario lookup/sector bodies execute against the actual canonical World, Pool, bank bindings and real owned resources. Other compiled response bodies retain their separately qualified evidence.','The fixture supplies explicit known menu/gate/resource capabilities. Later font rendering and SDK disk scheduling remain separate owners; no host/game launch or completeStage4 acceptance is claimed.','Finite owned-profile text and actor indices are admitted. Original register-history, inactive nonadvancing auxiliary and out-of-range target profiles are bounded entry interruptions rather than invented retail results.'])
 try:
  asset_path=ROOT/'build-native-sjuni/dialogue-assets-gcc-v1/receipt.json';asset_parent=json.loads(asset_path.read_bytes());assert asset_parent['status']=='passed';record['owned_asset_parent']=dict(path=asset_path.relative_to(ROOT).as_posix(),sha256=sha(asset_path));record['owned_assets']=[];archive_stamp=a.archive.stat().st_size,a.archive.stat().st_mtime_ns
  with a.archive.open('rb')as stream:
   for row in asset_parent['owned_assets']:
    if row['name'].lower()not in {'sp010000.bin','sp010001.bin','sp010008.bin','spm010000.bin','spm010001.bin','spm010008.bin'}:continue
    stream.seek(row['offset']);data=stream.read(row['bytes']);assert len(data)==row['bytes']and hashlib.sha256(data).hexdigest()==row['sha256'];record['owned_assets'].append(row)
  assert len(record['owned_assets'])==6
  if previous:record['native_snapshot']=dict(path=frozen.relative_to(ROOT).as_posix(),sha256=sha(frozen/'receipt.json'))
  for name in archive_names:
   source=(frozen/'archives'/name)if frozen else(a.build/name);target=out/'archives'/name;target.parent.mkdir(parents=True,exist_ok=True);before=sha(source);shutil.copyfile(source,target);assert before==sha(target)==sha(source);record['native_archives'][name]=before
  names=set(previous['source_sha256']if previous else parent['source_sha256']);names.update([fixture,'tools/native_reconstruction/verify_dialogue_room_banks.py','tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp','third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h'])
  overrides={fixture,'tools/native_reconstruction/verify_dialogue_room_banks.py'}
  origin=lambda name:(frozen/'source'/name)if previous and name in previous['source_sha256']and name not in overrides else(ROOT/name)
  pending=[fixture,'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'];visited=set()
  generated={'reference.hpp','functions.h','owned_constants.hpp','original_dispatch.hpp'}
  while pending:
   name=pending.pop()
   if name in visited:continue
   visited.add(name)
   if not origin(name).is_file():continue
   if(Path(name).suffix.lower()not in ['.cpp','.hpp','.h','.inc']):continue
   for rel in re.findall(r'^#include "([^"\n]+)"',origin(name).read_text(errors='replace'),re.M):
    if rel in generated:continue
    dep=((ROOT/name).parent/rel).resolve();dep=dep if dep.is_file()else(ROOT/rel).resolve();assert dep.is_file()and dep.is_relative_to(ROOT),(name,rel);key=dep.relative_to(ROOT).as_posix()
    names.add(key)
    if key not in visited:pending.append(key)
  for name in sorted(names):
   source=origin(name);assert source.is_file();record['source_sha256'][name]=sha(source);target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(source,target)
  elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';main_read=elf_reader(elf.read_bytes());banks={}
  for bank,digest in [('o2','45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'),('o0','bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2')]:
   path=ROOT/f'build-function-index/owned-overlays/{bank}.bin';assert sha(path)==digest;banks[bank]=path.read_bytes()
  read=lambda at,n:main_read(at,n)if at<0x370000 else banks['o0'][at-0x370000:at-0x370000+n]if at<0x570000 else banks['o2'][at-0x570000:at-0x570000+n]
  addresses=[0x6b7e40,0x6b7d40,0x6b8130,0x6b8440,0x6b8640,0x6b8650,0x6b88e0,0x6b8bf0,0x6b8cc0,0x6b8f60,0x6b90a0,0x6b91a0,0x6b9250,0x6b92c0,0x6b92e0,0x6b9330,0x6b94e0,0x376e70,0x192180,0x1226f0,0x120908,0x122140,0x1224a8,0x191ef0,0x1b02d0,0x1b0300,0x1b0310,0x67e230,0x667f90,0x1ba250,0x66a730]
  addresses += [0x1d41f0,0x6b73f0,0x6b7720,0x692a00,0x1cc8f0,0x1aa3e0,0x1aa480,0x1a9f20,0x1a9d70,0x1ab050,0x1a9750,0x129c08,0x130e40]
  prior=json.loads((ROOT/'build-native-sjuni/dialogue-response-choice-gcc-v4/receipt.json').read_text());addresses+=list(int(row['address'],16)for row in prior['original_owned_bodies'])if prior['original_owned_bodies']and'address'in prior['original_owned_bodies'][0]else[]
  # The preceding proof's paths enumerate the exact admitted scalar closure.
  for name in prior['source_sha256']:
   match=re.fullmatch(r'recomp/config/(?:output|output_ovl/o[02])/(?:sub|o[02])_([0-9A-Fa-f]+)_0x[0-9a-f]+\.cpp',name)
   if match:addresses.append(int(match[1],16))
  entries={};audits=[]
  for at in dict.fromkeys(addresses):
   bank='o2'if at>=0x570000 else'o0'if at>=0x370000 else'sub';folder=ROOT/('recomp/config/output_ovl/'+bank if bank!='sub'else'recomp/config/output');path=next(folder.glob(f'{bank}_{at:08X}_*'));begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',path.read_text()).groups()];name=path.relative_to(ROOT).as_posix();audits.append(compare_source('complete response frame or reached helper',name,begin,end,read));entries[at]=name;record['source_sha256'][name]=sha(path);target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(path,target)
  record['original_owned_bodies']=audits
  helper=out/'source/tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';header=helper.read_text().replace('Register r[32];','std::uint64_t lo{},hi{};Register r[32];')+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define FPU_ABS_S(v) std::fabs(v)\n#define FPU_C_EQ_S(a,b) ((a)==(b))\n#define FPU_DIV_S(a,b) ((a)/(b))\n#define SRA32(v,n) (std::int32_t(v)>>(n))\n#define PS2_PAND(a,b) _mm_and_si128((a),(b))\n#define PS2_PNOR(a,b) _mm_xor_si128(_mm_or_si128((a),(b)),_mm_set1_epi32(-1))\n#define PS2_PSUBB(a,b) _mm_sub_epi8((a),(b))\n#define PS2_PSUBW(a,b) _mm_sub_epi32((a),(b))\n#define PS2_PCPYLD(a,b) _mm_unpacklo_epi64((b),(a))\n#include "ps2_fpu_convert.h"\n#define FPU_CVT_W_S(v) Ps2FpuConvertWord(v)\n';header+='\nstd::uint8_t observed_response_byte(const std::uint8_t*,const R5900Context*,std::uint32_t);\nstd::uint32_t observed_response_word(const std::uint8_t*,const R5900Context*,std::uint32_t);\n#undef READ8\n#define READ8(at) observed_response_byte(rdram,ctx,at)\n#undef READ32\n#define READ32(at) observed_response_word(rdram,ctx,at)\n';(out/'reference.hpp').write_text(header);shutil.copyfile(ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h',out/'ps2_fpu_convert.h')
  body='\n'.join((out/'source'/name).read_text()for name in entries.values());actual={Path(name).stem for name in entries.values()};calls=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual));decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(calls-actual));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text(body);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+Path(name).stem+'(memory,context,runtime);return;\n'for at,name in entries.items()))
  for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
  for name in ['o0_functions.h','o2_functions.h','ps2_recompiled_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
  for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
  constants=[]
  for at,n in [(0x73e550,32),(0x73eea0,0x360),(0x740cd8,4),(0x723a70,32),(0x723a98,4),(0x740cc8,8),(0x740cb8,8),(0x740cc0,8),(0x2392b8,76),(0x241c00,0x400),(0x38ca98,4),(0x740710,64),(0x71adb0,32),(0x2567d0,0x150)]:constants.append('{const std::uint8_t b[]{'+','.join(map(str,read(at,n)))+'};std::memcpy(p+'+str(at)+',b,sizeof b);}')
  (out/'owned_constants.hpp').write_text('inline void owned_constants(std::uint8_t* p){\n'+'\n'.join(constants)+'\n}\n');record['snapshot_ready']=True
  if a.snapshot_only:record['status']='snapshot_ready';return
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'checks.exe';command=[str(a.compiler),'-std=c++20','-DNDEBUG','-DREO_DIALOGUE_RECORDS_ORIGINAL=1','-O2','-msse4.1','-ffunction-sections','-fdata-sections','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),str(out/'source'/fixture),str(out/'original.cpp'),'-Wl,--start-group',*[str(out/'archives'/name)for name in archive_names],'-Wl,--end-group','-Wl,--gc-sections','-o',str(binary)];record['command']=command
  for label,cmd in [('compile',command),('run',[str(binary),str(a.archive.resolve())])]:
   done=subprocess.run(cmd,env=env,capture_output=True,timeout=300);(out/(label+'.txt')).write_bytes(done.stdout+done.stderr);assert done.returncode==0,label+' failed: '+(done.stdout+done.stderr).decode(errors='replace')[-1800:]
   if label=='run':record['observed']=json.loads(done.stdout)
  assert archive_stamp==(a.archive.stat().st_size,a.archive.stat().st_mtime_ns)
  record['snapshot_unchanged']=all(sha(out/'source'/name)==digest for name,digest in record['source_sha256'].items())and all(sha(out/'archives'/name)==digest for name,digest in record['native_archives'].items());assert record['snapshot_unchanged'];record['live_source_drift']=[name for name,digest in record['source_sha256'].items()if not(ROOT/name).is_file()or sha(ROOT/name)!=digest];record['status']='passed'
 finally:
  record['output_sha256']={path.relative_to(out).as_posix():sha(path)for path in out.iterdir()if path.is_file()and path.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(dict(status=record['status'],observed=record.get('observed'),live_source_drift=record.get('live_source_drift'))))
if __name__=='__main__':main()
