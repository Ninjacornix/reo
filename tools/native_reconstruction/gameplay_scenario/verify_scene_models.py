"""Native room model state versus complete original remap/flag/style/B4 chains."""
import argparse,hashlib,json,os,re,struct,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source,elf_reader
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main(a):
 cc=Path(a.compiler).resolve();out=a.output.resolve();assert cc.exists() and not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir(parents=True)
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes())
 overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=overlay.read_bytes()
 main_ids=[0x18f570,0x18fdf0,0x190a10,0x1913e0,0x191530,0x1919d0];o2_ids=[0x581830,0x690600,0x690640,0x690700,0x5d8350,0x5d8390]
 originals=[next((ROOT/'recomp/config/output').glob(f'sub_{i:08X}_*')).relative_to(ROOT).as_posix()for i in main_ids]+[next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{i:08X}_*')).relative_to(ROOT).as_posix()for i in o2_ids]
 authority=originals+['recomp/config/output/sub_00195E50_0x195e50.cpp','recomp/config/output_ovl/o2/o2_0068C570_0x68c570.cpp']
 proof=[]
 for name in authority:
  begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',(ROOT/name).read_text()).groups()]
  proof.append(compare_source('complete scene-model body or required initialization/import authority',name,begin,end,read if begin<0x570000 else lambda at,size:raw[at-0x570000:at-0x570000+size]))
 mathq=ROOT/'tools/native_reconstruction/native_transform_math_qualification_v1.json';assert mathq.exists();qualified_math=json.loads(mathq.read_text())
 for name in ['game/native/transform_math/transform_math.hpp','game/native/transform_math/transform_math.cpp','tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp']:assert sha(ROOT/name)==qualified_math['source_sha256'][name]
 native=['game/native/gameplay_scenario/model_reference.hpp','game/native/gameplay_scenario/scene_models.hpp','game/native/gameplay_scenario/scene_models.cpp','game/native/gameplay_scenario/model_transform_presets.inc','game/native/gameplay_scenario/content.hpp','game/native/gameplay_scenario/content.cpp','game/native/transform_math/transform_math.hpp','game/native/transform_math/transform_math.cpp']
 helpers=['tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp','tools/native_reconstruction/gameplay_scenario/scene_model_tests.cpp','tools/native_reconstruction/gameplay_scenario/verify_scene_models.py']
 before={n:sha(ROOT/n)for n in authority+native+helpers}
 for name in before:
  dest=out/'source'/name;dest.parent.mkdir(parents=True,exist_ok=True);dest.write_bytes((ROOT/name).read_bytes())
 (out/'reference.hpp').write_bytes((ROOT/helpers[0]).read_bytes());(out/'tests.cpp').write_bytes((ROOT/helpers[1]).read_bytes());body='\n'.join((ROOT/n).read_text()for n in originals);(out/'original_models.cpp').write_text(body)
 actual={Path(n).stem for n in originals};names=set(re.findall(r'\b((?:sub|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for n in sorted(actual))
 decl+=''.join('inline void '+n+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for n in sorted(names-actual));(out/'functions.h').write_text('#pragma once\n'+decl)
 for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
 for name in ['ps2_recompiled_functions.h','o2_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
 for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
 init='inline void owned_constants(std::uint8_t* p){\n';constants={}
 for at,size in [(0x22fe20,32),(0x241c78,32)]:
  chunk=read(at,size);constants[hex(at)]=dict(bytes=chunk.hex(),sha256=hashlib.sha256(chunk).hexdigest());words=struct.unpack('<'+'I'*(size//4),chunk)
  init+='const std::array<std::uint32_t,'+str(len(words))+'> c'+str(at)+'{'+','.join(hex(x)+'u'for x in words)+'};std::memcpy(p+'+str(at)+',c'+str(at)+'.data(),'+str(size)+');\n'
 preset_words=struct.unpack_from('<48I',raw,0x7174f0-0x570000)
 init+='const std::array<std::uint32_t,48> presets{'+','.join(hex(x)+'u'for x in preset_words)+'};std::memcpy(p+0x7174f0,presets.data(),192);\n'
 (out/'owned_constants.hpp').write_text(init+'}\n')
 inventory_path=ROOT/'build-native-sjuni/gameplay-script-content-llvm-v8/inventory.json';members=json.loads(inventory_path.read_text());sections=[];assets=[]
 for item in members:
  if item['format']!='R':continue
  with Path(item['archive']).open('rb')as f:f.seek(item['archive_offset']);data=f.read(item['bytes'])
  assert hashlib.sha256(data).hexdigest()==item['sha256'];start,length=struct.unpack_from('<II',data,8);assert length and start+length<=len(data);section=data[start:start+length];sections.append(section)
  assets.append(dict(member=item['member'],name=item['name'],bytes=item['bytes'],sha256=item['sha256'],section_bytes=length,section_sha256=hashlib.sha256(section).hexdigest()))
 assert len(sections)==166
 (out/'owned_room_sections.bin').write_bytes(struct.pack('<I',len(sections))+b''.join(struct.pack('<I',len(s))+s for s in sections))
 env=dict(os.environ);env['PATH']=str(cc.parent)+os.pathsep+env.get('PATH','');binary=out/'checks.exe'
 command=[str(cc),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source')]+[str(out/'source'/p)for p in ['game/native/gameplay_scenario/scene_models.cpp','game/native/gameplay_scenario/content.cpp','game/native/transform_math/transform_math.cpp']]+[str(out/'tests.cpp'),'-o',str(binary)]
 record=dict(status='failed',compiler=str(cc),compiler_sha256=sha(cc),source_sha256=before,original_owned_bodies=proof,constant_content=constants,owned_preset_bytes=raw[0x7174f0-0x570000:0x7175b0-0x570000].hex(),owned_preset_sha256=hashlib.sha256(raw[0x7174f0-0x570000:0x7175b0-0x570000]).hexdigest(),owned_assets=assets,source_math_qualification=dict(path=mathq.relative_to(ROOT).as_posix(),sha256=sha(mathq)),game_launched=False,live_process_access=False,installed_in_game=False,physical_ps2_exceptional_parity=False,command=command)
 try:
  result=subprocess.run(command,env=env,capture_output=True,text=True,timeout=180);(out/'compile.txt').write_text(result.stdout+result.stderr);assert result.returncode==0,'compile failed; see '+str(out/'compile.txt')
  result=subprocess.run([str(binary)],cwd=out,env=env,capture_output=True,text=True,timeout=180);(out/'run.txt').write_text(result.stdout+result.stderr);assert result.returncode==0,'comparison failed; see '+str(out/'run.txt')
  observed=json.loads(result.stdout);assert observed['owned_rooms']==166 and observed['flag_cases']==2048 and observed['matrix_cases']==1024
  assert all(sha(ROOT/n)==digest for n,digest in before.items()),'source drift';record.update(status='passed',result=observed,binary_sha256=sha(binary),limitations=['Native model visibility/style/current-pose state only; external pose bindings and rendering remain separate consumers.','Byte-indexed source visibility writes128..255 explicitly mutate the overlapping style-word bit; there are128visibilitybytes, not256 independent flags.','Native pose/style operations refuse beyond128 owned slots rather than exporting writes into unrelated source state.','Stock default transform profile admits the eight hash-verified presets; source wider indexing has no local bound.','Original complete bodies execute only in the offline oracle using the qualified finite SIMD/scalar surroundings; physical PS2 exceptional values/flags are not claimed.','Actual room payloads/imported remaps are verified, but conservative script-prefix paths do not prove live reachability or game installation.'])
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(dict(status=record['status'],result=record.get('result'),receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--compiler',required=True);p.add_argument('--output',required=True,type=Path);main(p.parse_args())
