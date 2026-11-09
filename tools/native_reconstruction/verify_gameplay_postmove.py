"""Compare native postmovement policy to unchanged source6636D0 with qualified ports."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();allowed=(ROOT/'build-native-sjuni').resolve()
 if out.exists() or out==allowed or not out.is_relative_to(allowed):raise ValueError('Fresh private output required')
 image=ROOT/'build-function-index/owned-overlays/o2.bin';data=image.read_bytes()
 if sha(image)!='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226':raise ValueError('Owned image changed')
 source=ROOT/'recomp/config/output_ovl/o2/o2_006636D0_0x6636d0.cpp';text=source.read_text();end=int(re.search(r'// Address: 0x[0-9a-fA-F]+ - 0x([0-9a-fA-F]+)',text)[1],16);audit=compare_source('native-postmove-original',str(source.relative_to(ROOT)),0x6636d0,end,lambda at,n:data[at-0x570000:at-0x570000+n])
 base=ROOT/'tools/native_reconstruction/gameplay_collision_oracle/reference.hpp';ports=ROOT/'tools/native_reconstruction/gameplay_collision_oracle/postmove_ports.hpp';header=base.read_text().split('void o0_00370760')[0];header+='\n#define WRITE16(at,v) ref_write(rdram,at,std::uint16_t(v))\n#include "tools/native_reconstruction/gameplay_collision_oracle/postmove_ports.hpp"\nvoid o2_006636D0_0x6636d0(std::uint8_t*,R5900Context*,PS2Runtime*);\ninline PS2Runtime::Fn PS2Runtime::lookupFunction(std::uint32_t at)const{switch(at){case 0x5da420:return o2_005DA420_0x5da420;case 0x616f60:return o2_00616F60_0x616f60;case 0x574680:return o2_00574680_0x574680;case 0x57c0b0:return o2_0057C0B0_0x57c0b0;default:throw std::runtime_error("Undeclared postmove call");}}\n'
 names=['collision.cpp','collision.hpp','response.cpp','response.hpp','sweep.cpp','sweep.hpp','actors.cpp','actors.hpp','ownership.cpp','ownership.hpp','trace.cpp','trace.hpp','room_objects.cpp','room_objects.hpp','footprint.cpp','footprint.hpp','regions.cpp','regions.hpp','postmove.cpp','postmove.hpp','postmove_tests.cpp'];paths=[ROOT/'game/native/gameplay_collision'/n for n in names]+[ROOT/'game/native/gameplay_actors/entity.hpp',ROOT/'game/native/gameplay_actors/entity.cpp',base,ports,ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h',Path(__file__),source]
 inputs={p.relative_to(ROOT).as_posix():sha(p) for p in paths};out.mkdir();(out/'postmove_reference.hpp').write_text(header);original=out/'original.cpp';original.write_text('#include "postmove_reference.hpp"\n'+text[text.index('// Function:'):])
 inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json'
 if sha(inventory)!='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2':raise ValueError('Owned inventory changed')
 selected=['w0010100.bin','g0010100.bin','obj001.dat','r001.sto','r0010100.rdt'];assets={}
 with (ROOT/'iso/Resident Evil - Outbreak (v2.00).iso').open('rb') as stream:
  for entry in json.loads(inventory.read_bytes()):
   matching=[n for n in selected if n in entry['names']]
   if not matching:continue
   stream.seek(entry['iso_offset']);body=stream.read(entry['bytes'])
   if hashlib.sha256(body).hexdigest()!=entry['sha256']:raise ValueError('Owned postmove asset changed')
   for name in matching:
    (out/name).write_bytes(body);assets[name]=entry
 if set(assets)!=set(selected):raise ValueError('Missing owned postmove fixture')
 room=(out/'r0010100.rdt').read_bytes()
 for index in [14,16]:
  at=int.from_bytes(room[8*index:8*index+4],'little');size=int.from_bytes(room[8*index+4:8*index+8],'little')
  if at>len(room) or size>len(room)-at:raise ValueError('Owned room section outside RDT')
  (out/f'section{index}.bin').write_bytes(room[at:at+size])
 compiler=COMPILERS[a.compiler];env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','');exe=out/'postmove.exe';record=dict(schema=1,status='failed',source_sha256=inputs,compiler_sha256=sha(compiler),original_word_audits=[audit],owned_assets=assets,game_launched=False,checks=[])
 command=[str(compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-parameter','-ffp-contract=off','-I'+str(ROOT),'-I'+str(out),*[str(ROOT/'game/native/gameplay_collision'/n) for n in names if n.endswith('.cpp')],str(ROOT/'game/native/gameplay_actors/entity.cpp'),str(original),'-o',str(exe)]
 try:
  for label,cmd in [('compile',command),('test',[str(exe),*[str(out/n) for n in selected[:4]],str(out/'section14.bin'),str(out/'section16.bin')])]:
   result=subprocess.run(cmd,capture_output=True,env=env,timeout=120);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);record['checks'].append(dict(label=label,command=cmd,exit=result.returncode))
   if result.returncode:raise RuntimeError(label+': '+result.stderr.decode(errors='replace')[-3000:])
   if label=='test':record['results']=json.loads(result.stdout)
  for name,digest in inputs.items():
   if sha(ROOT/name)!=digest:raise ValueError('Source changed: '+name)
  record['status']='native postmovement caller comparisons passed'
 finally:
  record['output_sha256']={p.name:sha(p) for p in out.iterdir() if p.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(record['results']))
if __name__=='__main__':main()
