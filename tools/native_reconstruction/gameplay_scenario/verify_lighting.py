"""Native LIG importer/pool against complete owned original bodies, offline."""
import argparse,hashlib,json,os,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
IDS=['006B1DC0','006B1EC0','006B1FE0','006B2020','006B2170','006B2FA0','006B3020','006B3090']
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def invoke(cmd,out,label):
 p=subprocess.run(cmd,capture_output=True,text=True,timeout=180)
 (out/(label+'.stdout.txt')).write_text(p.stdout);(out/(label+'.stderr.txt')).write_text(p.stderr)
 if p.returncode:raise RuntimeError(label+' failed: '+p.stderr[-6000:])
 return dict(command=cmd,exit_code=p.returncode,stdout_sha256=sha(out/(label+'.stdout.txt')),stderr_sha256=sha(out/(label+'.stderr.txt')))
def main(a):
 cc=Path(a.compiler).resolve();out=a.output.resolve();assert cc.exists() and not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir(parents=True)
 raw=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes();assert hashlib.sha256(raw).hexdigest()=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
 texts=[];sources={};words=0
 for ident in IDS:
  p=next((ROOT/'recomp/config/output_ovl/o2').glob('o2_'+ident+'_*'));text=p.read_text();sources[p.relative_to(ROOT).as_posix()]=sha(p);shutil.copyfile(p,out/p.name)
  for pc,opcode in re.findall(r'// (0x[0-9a-f]+): (0x[0-9a-f]+)\s',text):assert struct.unpack_from('<I',raw,int(pc,16)-0x570000)[0]==int(opcode,16);words+=1
  texts.append('\n'.join(l for l in text.splitlines() if not l.startswith('#include')))
 text='\n'.join(texts);names=sorted(set(re.findall(r'\b((?:o2|sub)_[A-Za-z0-9_]+)\(',text)))
 (out/'original_declarations.inc').write_text('\n'.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);' for n in names)+'\n')
 fixture=(ROOT/'tools/native_reconstruction/gameplay_save/original_fixture.hpp').read_text().replace('0x400000','0x800000').replace('#include <cstdint>','#include <cstdint>\n#include <array>\n#include <bit>')
 fixture=fixture.replace('std::uint64_t lo{},hi{};','std::uint64_t lo{},hi{};float f[32]{};std::uint32_t fcr31{};').replace('Function lookupFunction(std::uint32_t)const{throw std::runtime_error("Unexpected original dynamic dispatch");}','Function lookupFunction(std::uint32_t)const;')
 fixture+='\n#define WRITE32(a,v) fixture_write<std::uint32_t>(rdram,a,v)\n#define FPU_C_OLE_S(a,b) ((a)<=(b))\n#define SUB32(a,b) (std::uint32_t(std::uint32_t(a)-std::uint32_t(b)))\n'
 (out/'original_fixture.hpp').write_text(fixture);(out/'original.cpp').write_text('#include "original_fixture.hpp"\n#include "original_declarations.inc"\n'+text)
 paths=[HERE/'lighting_tests.cpp',Path(__file__),ROOT/'game/native/gameplay_scenario/lighting.hpp',ROOT/'game/native/gameplay_scenario/lighting.cpp']
 before={p.relative_to(ROOT).as_posix():sha(p) for p in paths}
 for p in paths:shutil.copyfile(p,out/p.name)
 index=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1';members=json.loads((index/'members.json').read_text());containers={r['path']:r for r in json.loads((index/'containers.json').read_text())}
 index_receipt=json.loads((index/'receipt.json').read_text());assert index_receipt['status']=='passed'
 for n,d in index_receipt['output_sha256'].items():assert sha(index/n)==d
 imported=json.loads((a.data_root.parent/'import.json').read_text());assert imported['ElfSha256']=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
 identities=[];lines=[]
 for m in members:
  if not m['names'] or not m['names'][-1].lower().endswith('.rdt'):continue
  c=containers[m['container']];p=a.data_root/m['container'];at=m['iso_offset']-c['offset']
  with p.open('rb') as f:f.seek(at);b=f.read(m['bytes'])
  assert hashlib.sha256(b).hexdigest()==m['sha256'];offset,size=struct.unpack_from('<II',b,11*8);assert not size or offset+size<=len(b)
  if not size:continue
  lig=b[offset:offset+size];version,count=struct.unpack_from('<Ii',lig);assert version==4 and count<=4
  bank_counts=[struct.unpack_from('<I',lig,struct.unpack_from('<I',lig,8+4*i)[0]+4)[0]&65535 for i in range(max(count,0))];assert all(n<=32 for n in bank_counts)
  identities.append(dict(name=m['names'][-1],rdt_sha256=m['sha256'],container=m['container'],member_offset=at,section_offset=offset,section_size=size,section_sha256=hashlib.sha256(lig).hexdigest(),banks=count,entry_counts=bank_counts))
  lines.append(str(p)+'\t'+str(at+offset)+'\t'+str(size))
 (out/'cases.tsv').write_text('\n'.join(lines)+'\n');(out/'owned_lig_identity.json').write_text(json.dumps(identities,indent=2)+'\n')
 os.environ['PATH']=str(cc.parent)+os.pathsep+os.environ.get('PATH','');base=[str(cc),'-std=c++20','-O2','-I'+str(ROOT),'-I'+str(out)]
 checks=[invoke(base+['-w','-c',str(out/'original.cpp'),'-o',str(out/'original.o')],out,'compile-original')]
 for label,path in [('core',ROOT/'game/native/gameplay_scenario/lighting.cpp'),('tests',out/'lighting_tests.cpp')]:checks.append(invoke(base+['-Wall','-Wextra','-Wpedantic','-Werror','-c',str(path),'-o',str(out/(label+'.o'))],out,'compile-'+label))
 checks.append(invoke([str(cc)]+[str(out/(n+'.o')) for n in ['original','core','tests']]+['-o',str(out/'checks.exe')],out,'link'))
 checks.append(invoke([str(out/'checks.exe'),str(out/'cases.tsv')],out,'test'));assert all(sha(ROOT/n)==d for n,d in before.items())
 receipt=dict(status='passed',compiler=str(cc),compiler_sha256=sha(cc),source_sha256=before,original_sources_sha256=sources,checked_owned_instruction_comments=words,checks=checks,result=json.loads((out/'test.stdout.txt').read_text()),owned_lig_count=len(identities),owned_lig_identity_sha256=sha(out/'owned_lig_identity.json'),game_launched=False,installed_in_game=False,limitations=['Native light state/import and primary-pool management only; no GS output or modern renderer consumer is implemented.','Original helpers execute only in bounded offline oracle; standard memcpy/memset are explicit dependency implementations.','Native profiles reject more than four banks or32 descriptors and refuse malformed extents; original unchecked aliasing outside these owners is not supported.'])
 (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(dict(status='passed',result=receipt['result'],owned_lig_count=len(identities),instruction_comments=words)))
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--compiler',required=True);p.add_argument('--output',required=True,type=Path);p.add_argument('--data-root',required=True,type=Path);main(p.parse_args())
