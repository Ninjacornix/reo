"""Compare native route batching with the owned complete 680B40 body and declared providers."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();allowed=(ROOT/'build-native-sjuni').resolve()
 if out.exists()or out==allowed or not out.is_relative_to(allowed):raise ValueError('Fresh private output required')
 source=ROOT/'recomp/config/output_ovl/o2/o2_00680B40_0x680b40.cpp';image=ROOT/'build-function-index/owned-overlays/o2.bin'
 if sha(image)!='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226':raise ValueError('Owned overlay changed')
 data=image.read_bytes();audit=compare_source('native-contact-routes',str(source.relative_to(ROOT)),0x680b40,0x680de8,lambda at,size:data[at-0x570000:at-0x570000+size]);base=ROOT/'tools/native_reconstruction/gameplay_collision_oracle/reference.hpp';ports=ROOT/'tools/native_reconstruction/gameplay_collision_oracle/contact_routes_ports.hpp'
 control_source=ROOT/'recomp/config/output_ovl/o2/o2_005819C0_0x5819c0.cpp';control_audit=compare_source('native-contact-related-control',str(control_source.relative_to(ROOT)),0x5819c0,0x581a50,lambda at,size:data[at-0x570000:at-0x570000+size])
 paths=[ROOT/'game/native/gameplay_collision'/name for name in ['contact_routes.hpp','contact_routes.cpp','contact_route_controls_tests.cpp']]+[ROOT/'game/native/gameplay_scenario'/n for n in ['scene_control_routes.hpp','scene_control_routes.cpp','scene_controls.hpp','scene_controls.cpp','action_choices.hpp']]+[ROOT/'game/native/gameplay_session/session.hpp',ROOT/'game/native/gameplay_session/session.cpp',control_source,base,ports,source,Path(__file__),ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h'];inputs={p.relative_to(ROOT).as_posix():sha(p)for p in paths}
 header=base.read_text().split('void o0_00370760_0x370760')[0]+'\n#define WRITE16(at,v) ref_write(rdram,at,std::uint16_t(v))\nvoid o2_00680B40_0x680b40(std::uint8_t*,R5900Context*,PS2Runtime*);\n'+ports.read_text()
 a_port=header.index('inline void o2_005819C0_0x5819c0');b_port=header.index('inline void sub_001B0310_0x1b0310',a_port);header=header[:a_port]+'void o2_005819C0_0x5819c0(std::uint8_t*,R5900Context*,PS2Runtime*);\n'+header[b_port:]
 out.mkdir();(out/'routes_reference.hpp').write_text(header);text=source.read_text();original=out/'original.cpp';original.write_text('#include "routes_reference.hpp"\n#pragma GCC diagnostic ignored "-Wunused-variable"\n'+text[text.index('// Function:'):]+'\n'+control_source.read_text()[control_source.read_text().index('// Function:'):]);compiler=COMPILERS[a.compiler];env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','');exe=out/'routes.exe'
 command=[str(compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-parameter','-ffp-contract=off','-I'+str(ROOT),'-I'+str(out),str(ROOT/'game/native/gameplay_collision/contact_routes.cpp'),str(ROOT/'game/native/gameplay_collision/contact_route_controls_tests.cpp'),str(ROOT/'game/native/gameplay_scenario/scene_control_routes.cpp'),str(ROOT/'game/native/gameplay_scenario/scene_controls.cpp'),str(ROOT/'game/native/gameplay_session/session.cpp'),str(original),'-o',str(exe)];record=dict(schema=1,status='failed',source_sha256=inputs,compiler_sha256=sha(compiler),original_word_audits=[audit,control_audit],game_launched=False,checks=[])
 try:
  for label,cmd in [('compile',command),('test',[str(exe)])]:
   result=subprocess.run(cmd,capture_output=True,env=env,timeout=120);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);record['checks'].append(dict(label=label,command=cmd,exit=result.returncode))
   if result.returncode:raise RuntimeError(label+': '+result.stderr.decode(errors='replace')[-2500:])
   if label=='test':record['results']=json.loads(result.stdout)
  for name,digest in inputs.items():
   if sha(ROOT/name)!=digest:raise ValueError('Source changed: '+name)
  record['status']='native contact route consumer matches full original body with actual native SceneControls lookup and controlled durability/send providers'
 finally:
  record['output_sha256']={p.name:sha(p)for p in out.iterdir()if p.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(record['results']))
if __name__=='__main__':main()
