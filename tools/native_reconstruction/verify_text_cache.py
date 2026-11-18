"""Compare the real32-entry text cache with complete owned main bodies."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes());entries={};proof=[]
 for at in [0x1b4a60,0x1b4590,0x1b4650,0x1b46e0,0x1b48e0,0x1b49b0,0x1b4940,0x1b4450,0x107c68,0x10afc0,0x10ae78]:
  path=next((ROOT/'recomp/config/output').glob(f'sub_{at:08X}_*'));begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',path.read_text()).groups()];entries[at]=path.relative_to(ROOT).as_posix();proof.append(compare_source('complete native text cache or reached string/memory body',entries[at],begin,end,read))
 files=['game/native/gameplay_scenario/text_cache.cpp','game/native/gameplay_scenario/text_cache.hpp','tools/native_reconstruction/text_cache_tests.cpp','tools/native_reconstruction/verify_text_cache.py','tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp',*entries.values()];before={name:sha(ROOT/name)for name in files};result=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(a.compiler),owned_elf_sha256=sha(elf),original_owned_bodies=proof,game_run=False,audio_device_opened=False,stage4_complete=False,limits=['Complete cache clear/admission/duplicate/insert/dialogue-alpha/erase/expire/cull bodies execute, including original107C68/10AE78/10AFC0 string and memory helpers.','Native state owns32 typed cache entries and value snapshots. The source clear also zeros an unused16-byte control header; no unsupported header semantics or callback installer1B4A20 is claimed.','One controlled copy-entry interruption compares the exact prefix before an overlong128-byte string would overrun its source text field. Native refuses that unsupported profile.','Actual1B4500 font/glyph rendering consumer, its graphics-resource gates and timed-message suppression ownership are separate integration. No renderer, game or audio device runs.'])
 try:
  for name in files:
   target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
  header=(ROOT/files[4]).read_text().replace('Register r[32];','std::uint64_t lo{},hi{};Register r[32];')+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define SRA32(v,n) (std::int32_t(v)>>(n))\n#define PS2_PCPYLD(a,b) _mm_unpacklo_epi64((b),(a))\n#define PS2_PAND(a,b) _mm_and_si128((a),(b))\n#define PS2_PNOR(a,b) _mm_xor_si128(_mm_or_si128((a),(b)),_mm_set1_epi32(-1))\n#define PS2_PSUBB(a,b) _mm_sub_epi8((a),(b))\n#define PS2_PSUBW(a,b) _mm_sub_epi32((a),(b))\n';(out/'reference.hpp').write_text(header)
  body='\n'.join((ROOT/name).read_text()for name in entries.values());actual={Path(name).stem for name in entries.values()};calls=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual));decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(calls-actual));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text(body);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+Path(name).stem+'(memory,context,runtime);return;\n'for at,name in entries.items()))
  for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
  (out/'ps2_recompiled_functions.h').write_text('#pragma once\n#include "functions.h"\n')
  for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'checks.exe';command=[str(a.compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),str(out/'source'/files[0]),str(out/'source'/files[2]),str(out/'original.cpp'),'-o',str(binary)];result['command']=command
  for label,cmd in [('compile',command),('run',[str(binary)])]:
   done=subprocess.run(cmd,env=env,capture_output=True,timeout=180);(out/(label+'.txt')).write_bytes(done.stdout+done.stderr);assert done.returncode==0,label+' failed: '+(done.stdout+done.stderr).decode(errors='replace')[-1500:]
   if label=='run':result['observed']=json.loads(done.stdout)
  result['snapshot_unchanged']=all(sha(out/'source'/name)==digest for name,digest in before.items());assert result['snapshot_unchanged'];result['live_source_drift']=[name for name,digest in before.items()if not(ROOT/name).is_file()or sha(ROOT/name)!=digest];result['status']='passed'
 finally:
  result['output_sha256']={path.relative_to(out).as_posix():sha(path)for path in out.iterdir()if path.is_file()and path.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n')
 print(json.dumps(dict(status=result['status'],observed=result['observed'],live_source_drift=result['live_source_drift'])))
if __name__=='__main__':main()
