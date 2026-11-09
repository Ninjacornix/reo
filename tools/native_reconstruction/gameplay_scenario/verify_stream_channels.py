"""Three native engine stream channels against complete owned main bodies."""
import argparse,hashlib,json,os,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
IDS=['001BA170','001ADA20','001ADF00','001ADF50','001ADFD0','001AE0C0','001AE190','001AE2E0','001AE3F0','001AE4B0']
PORTS={0x131e38,0x131ef8,0x1327b8,0x132e50,0x133490,0x1b82a0,0x12bef8}
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def run(cmd,out,label):
 p=subprocess.run(cmd,capture_output=True,text=True,timeout=180);(out/(label+'.stdout.txt')).write_text(p.stdout);(out/(label+'.stderr.txt')).write_text(p.stderr)
 if p.returncode:raise RuntimeError(label+' failed: '+p.stderr[-6000:])
 return dict(command=cmd,exit_code=p.returncode,stdout_sha256=sha(out/(label+'.stdout.txt')),stderr_sha256=sha(out/(label+'.stderr.txt')))
def main(a):
 cc=Path(a.compiler).resolve();out=a.output.resolve();assert cc.exists() and not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir(parents=True)
 elf_path=Path(os.environ['LOCALAPPDATA'])/'OutbreakRecomp/launcher/imports/file1/25e64b631bbaa0cac9a4822cb66174ff14c3531851d1e502c0a06704379bf446/data/SLUS_207.65'
 elf=elf_path.read_bytes();elf_sha=hashlib.sha256(elf).hexdigest();assert elf_sha=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
 phoff=struct.unpack_from('<I',elf,28)[0];phsize,phcount=struct.unpack_from('<HH',elf,42);loads=[struct.unpack_from('<8I',elf,phoff+i*phsize) for i in range(phcount)];loads=[p for p in loads if p[0]==1]
 def read(at,n):
  p=next(p for p in loads if p[2]<=at and at+n<=p[2]+p[4]);return elf[p[1]+at-p[2]:p[1]+at-p[2]+n]
 curve=read(0x234060,512);assert hashlib.sha256(curve).hexdigest()=='36fb2dc8488a843da5b2ff8d7538afee1af1edbdb005746582e79cdd80032387'
 text=[];original={};comments=0;functions={}
 for ident in IDS:
  p=next((ROOT/'recomp/config/output').glob('sub_'+ident+'_*'));s=p.read_text();original[p.relative_to(ROOT).as_posix()]=sha(p);shutil.copyfile(p,out/p.name)
  for pc,w in re.findall(r'// (0x[0-9a-f]+): (0x[0-9a-f]+)\s',s):assert struct.unpack('<I',read(int(pc,16),4))[0]==int(w,16);comments+=1
  text.append('\n'.join(l for l in s.splitlines() if not l.startswith('#include')));functions[int(ident,16)]='sub_'+ident+'_0x'+format(int(ident,16),'x')
 s='\n'.join(text);names=set(re.findall(r'\b((?:sub|o2)_[A-Za-z0-9_]+)\(',s));names|={f'sub_{a:08X}_0x{a:x}' for a in PORTS}
 (out/'original_declarations.inc').write_text('\n'.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);' for n in sorted(names))+'\ninline constexpr std::array<std::int32_t,128> original_curve{'+','.join(str(x) for x in struct.unpack('<128i',curve))+'};\n')
 available=functions|{a:f'sub_{a:08X}_0x{a:x}' for a in PORTS}
 (out/'original_lookup.inc').write_text('\n'.join(f'case 0x{a:x}:return {n};' for a,n in available.items())+'\n')
 missing=names-set(available.values());stubs='\n'.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*){throw std::runtime_error("Unexecuted original dependency '+n+'");}' for n in sorted(missing))
 fixture=(ROOT/'tools/native_reconstruction/gameplay_save/original_fixture.hpp').read_text().replace('0x400000','0x800000').replace('#include <cstdint>','#include <cstdint>\n#include <array>\n#include <bit>\n#include "word_conversion.hpp"')
 fixture=fixture.replace('std::uint64_t lo{},hi{};','std::uint64_t lo{},hi{};float f[32]{};std::uint32_t fcr31{};').replace('Function lookupFunction(std::uint32_t)const{throw std::runtime_error("Unexpected original dynamic dispatch");}','Function lookupFunction(std::uint32_t)const;')
 fixture+='\n#define WRITE32(a,v) fixture_write<std::uint32_t>(rdram,a,v)\n#define FPU_CVT_S_W(a) (float(std::int32_t(a)))\n#define FPU_CVT_W_S(a) Ps2FpuConvertWord(float(a))\n#define FPU_ADD_S(a,b) (float(a)+float(b))\n#define FPU_SUB_S(a,b) (float(a)-float(b))\n#define FPU_MUL_S(a,b) (float(a)*float(b))\n#define FPU_DIV_S(a,b) (float(a)/float(b))\n#define FPU_C_OLE_S(a,b) (float(a)<=float(b))\n#define FPU_C_OLT_S(a,b) (float(a)<float(b))\n#define FPU_C_EQ_S(a,b) (float(a)==float(b))\n#define SUB32(a,b) (std::uint32_t(std::uint32_t(a)-std::uint32_t(b)))\n#define SRA32(a,b) (std::int32_t(std::int32_t(a)>>(std::uint32_t(b)&31)))\n'
 fixture+='\n#define FPU_MOV_S(a) (float(a))\n'
 conversion=ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h';shutil.copyfile(conversion,out/'word_conversion.hpp')
 (out/'original_fixture.hpp').write_text(fixture);(out/'original.cpp').write_text('#include "original_fixture.hpp"\n#include "original_declarations.inc"\n'+s+'\n'+stubs)
 paths=[HERE/'stream_channel_tests.cpp',Path(__file__),conversion,ROOT/'game/native/gameplay_scenario/stream_channels.hpp',ROOT/'game/native/gameplay_scenario/stream_channels.cpp',ROOT/'game/native/gameplay_scenario/stream_gain_curve.inc'];before={p.relative_to(ROOT).as_posix():sha(p) for p in paths}
 for p in paths:shutil.copyfile(p,out/p.name)
 os.environ['PATH']=str(cc.parent)+os.pathsep+os.environ.get('PATH','');base=[str(cc),'-std=c++20','-O2','-fno-fast-math','-ffp-contract=off','-I'+str(ROOT),'-I'+str(out)]
 checks=[run(base+['-w','-c',str(out/'original.cpp'),'-o',str(out/'original.o')],out,'compile-original')]
 checks.append(run(base+['-Wall','-Wextra','-Wpedantic','-Werror',str(out/'stream_channel_tests.cpp'),str(ROOT/'game/native/gameplay_scenario/stream_channels.cpp'),str(out/'original.o'),'-o',str(out/'checks.exe')],out,'compile-tests'))
 checks.append(run([str(out/'checks.exe')],out,'test'));assert all(sha(ROOT/p)==d for p,d in before.items())
 result=dict(status='passed',compiler=str(cc),compiler_sha256=sha(cc),source_sha256=before,owned_main_elf_sha256=elf_sha,owned_gain_curve_sha256=hashlib.sha256(curve).hexdigest(),original_sources_sha256=original,checked_owned_instruction_comments=comments,checks=checks,result=json.loads((out/'test.stdout.txt').read_text()),game_launched=False,installed_in_game=False,limitations=['Canonical engine channel state/ramp/request algorithms only; real nativeInstances/source-catalog adapter is qualified separately.','Original low-level SDK functions are declared primitive test ports; no MIPS runs in production.','Service advances call-based ramps only when explicitly invoked with a real game tick; audio background pumps must not advance these ramps.','Initialization/allocation, full query selectors/prepared-wait/name/voice routes and live game callers remain independent gates.'])
 (out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(dict(status='passed',result=result['result'],instruction_comments=comments)))
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--compiler',required=True);p.add_argument('--output',required=True,type=Path);main(p.parse_args())
