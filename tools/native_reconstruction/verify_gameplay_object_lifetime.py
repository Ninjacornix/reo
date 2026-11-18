"""Audit pool/derived geometry/wall caller against owned unchanged originals."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
ENTRIES=[0x6adba0,0x6add40,0x6adf60,0x6ae0e0,0x6ae5e0,0x6aeda0,0x6aee20,0x619930,0x619a50,0x57c0b0,0x6afd70,0x6acf80,0x6ad010,0x6ad0f0,0x6ad310,0x6ad360,0x6ad860,0x6ae4b0,0x6ae9f0,0x6afbd0,0x6b07b0,0x6b0890,0x6b0ac0,0x5c1120,0x5c11b0,0x5c12a0,0x5c5d30,0x5c6100,0x5c62f0,0x5c63b0,0x5c6480,0x5c6550,0x5c66c0,0x5da420,0x6ad9b0,0x6adab0,0x6ad260,0x6ae2b0,0x6ae310,0x6ae390,0x6aebe0,0x6b1010,0x6b0510,0x590be0,0x590c70,0x590d80]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();allowed=(ROOT/'build-native-sjuni').resolve()
 if out.exists() or out==allowed or not out.is_relative_to(allowed):raise ValueError('Fresh private output required')
 image=ROOT/'build-function-index/owned-overlays/o2.bin';data=image.read_bytes()
 if sha(image)!='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226':raise ValueError('Owned image changed')
 sources=[];bodies=[];audits=[]
 profiles=[('o2',start) for start in ENTRIES]+[('o0',0x370320),('main',0x191f80)]
 for overlay,start in profiles:
  owned=ROOT/('game_data/SLUS_207.65' if overlay=='main' else f'build-function-index/owned-overlays/{overlay}.bin');blob=owned.read_bytes();expected='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46' if overlay=='main' else 'bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2' if overlay=='o0' else '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
  if sha(owned)!=expected:raise ValueError('Owned source changed')
  prefix='sub' if overlay=='main' else overlay;source=ROOT/(f'recomp/config/output/sub_{start:08X}_0x{start:x}.cpp' if overlay=='main' else f'recomp/config/output_ovl/{overlay}/{prefix}_{start:08X}_0x{start:x}.cpp');text=source.read_text();end=int(re.search(r'// Address: 0x[0-9a-fA-F]+ - 0x([0-9a-fA-F]+)',text)[1],16);read=elf_reader(blob) if overlay=='main' else lambda at,n:blob[at-(0x370000 if overlay=='o0' else 0x570000):at-(0x370000 if overlay=='o0' else 0x570000)+n];sources.append(source);audits.append(compare_source('room-geometry-original',str(source.relative_to(ROOT)),start,end,read));bodies.append(text[text.index('// Function:'):])
 actual_binding_sources=[ROOT/f'recomp/config/output_ovl/o2/o2_{at:08X}_0x{at:x}.cpp' for at in [0x581830,0x5d8280,0x5d8300]]
 for source in actual_binding_sources:
  text=source.read_text();start,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',text).groups()];audits.append(compare_source('actual model binding primitive',source.relative_to(ROOT).as_posix(),start,end,lambda at,n:data[at-0x570000:at-0x570000+n]));sources.append(source)
 base=ROOT/'tools/native_reconstruction/gameplay_collision_oracle/reference.hpp';ports=ROOT/'tools/native_reconstruction/gameplay_collision_oracle/ownership_ports.hpp';header=base.read_text().split('void o0_00370760')[0]
 header+='\n#define FPU_C_EQ_S(a,b) ((a)==(b))\n#define SRL32(a,b) (std::uint32_t(a)>>(b))\n#define SRA32(a,b) (std::bit_cast<std::int32_t>(std::uint32_t(a))>>(b))\n#define WRITE16(at,v) ref_write(rdram,at,std::uint16_t(v))\n#include "tools/native_reconstruction/gameplay_collision_oracle/ownership_ports.hpp"\n'
 header+='\n'.join(f'void {"sub" if o=="main" else o}_{s:08X}_0x{s:x}(std::uint8_t*,R5900Context*,PS2Runtime*);' for o,s in profiles)
 header+='\ninline void footprint_length(std::uint8_t* m,R5900Context* c,PS2Runtime*){const auto v=ref_read<std::array<float,3>>(m,GPR_U32(c,4));c->f[0]=std::sqrt((v[0]*v[0]+v[1]*v[1])+v[2]*v[2]);c->pc=GPR_U32(c,31);}'
 header+='\ninline void footprint_normalize(std::uint8_t* m,R5900Context* c,PS2Runtime*){auto v=ref_read<std::array<float,3>>(m,GPR_U32(c,4));const auto n=std::sqrt((v[0]*v[0]+v[1]*v[1])+v[2]*v[2]);for(auto& x:v)x=n==0?0:x*(1/n);ref_write(m,GPR_U32(c,4),v);c->pc=GPR_U32(c,31);}'
 header+='\ninline void footprint_sub(std::uint8_t* m,R5900Context* c,PS2Runtime*){const auto a=ref_read<std::array<float,3>>(m,GPR_U32(c,5)),b=ref_read<std::array<float,3>>(m,GPR_U32(c,6));ref_write(m,GPR_U32(c,4),std::array<float,3>{a[0]-b[0],a[1]-b[1],a[2]-b[2]});c->pc=GPR_U32(c,31);}'
 header+='\ninline void o2_00616F20_0x616f20(std::uint8_t* m,R5900Context* c,PS2Runtime*){c->f[0]=ref_read<float>(m,160);c->pc=GPR_U32(c,31);}'
 header+='\n#include "tools/native_reconstruction/gameplay_collision_oracle/room_geometry_ports.hpp"\n'
 header+='\n#include "tools/native_reconstruction/gameplay_collision_oracle/object_lifetime_ports.hpp"\n'
 header+='\ninline PS2Runtime::Fn PS2Runtime::lookupFunction(std::uint32_t at)const{switch(at){\n'
 header+='\n'.join(f'case 0x{s:x}:return {"sub" if o=="main" else o}_{s:08X}_0x{s:x};' for o,s in profiles)
 for at,name in [(0x107c68,'memset'),(0x107ab0,'memcpy'),(0x1900e0,'matrix_copy'),(0x191430,'inverse'),(0x370570,'vector'),(0x370500,'vector'),(0x1919d0,'transform'),(0x1920a0,'abs')]:header+=f'\ncase 0x{at:x}:return port_{name};'
 header+='\ncase 0x18fdf0:return lifetime_identity;case 0x581830:return lifetime_model;case 0x5d8280:return lifetime_bind;case 0x5d8300:return lifetime_unbind;case 0x616f60:return lifetime_floor;case 0x3705e0:return geometry_scale;case 0x1902d0:return geometry_yaw;case 0x191a40:return geometry_transform;case 0x579980:return o2_00579980_0x579980;case 0x191cc0:return footprint_length;case 0x191d80:return footprint_normalize;case 0x370420:return footprint_sub;\ncase 0x616f20:return o2_00616F20_0x616f20;\ncase 0x6177c0:return o2_006177C0_0x6177c0;default:throw std::runtime_error("Undeclared owner support call "+std::to_string(at));}}\n'
 names=['collision.cpp','collision.hpp','response.cpp','response.hpp','sweep.cpp','sweep.hpp','actors.cpp','actors.hpp','ownership.cpp','ownership.hpp','room_objects.cpp','room_objects.hpp','footprint.cpp','footprint.hpp','trace.cpp','trace.hpp','room_geometry.cpp','room_geometry.hpp','object_interactions.cpp','object_interactions.hpp','object_lifetime.cpp','object_lifetime.hpp','object_lifetime_tests.cpp']
 paths=[ROOT/'game/native/gameplay_collision'/n for n in names]+[ROOT/'game/native/gameplay_actors/entity.hpp',ROOT/'game/native/gameplay_actors/entity.cpp',ROOT/'game/native/transform_math/transform_math.hpp',ROOT/'game/native/transform_math/transform_math.cpp',base,ports,ROOT/'tools/native_reconstruction/gameplay_collision_oracle/room_geometry_ports.hpp',ROOT/'tools/native_reconstruction/gameplay_collision_oracle/object_lifetime_ports.hpp',ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h',Path(__file__),*sources]
 model_native=[ROOT/p for p in ['game/native/gameplay_scenario/scene_models.hpp','game/native/gameplay_scenario/scene_models.cpp','game/native/gameplay_scenario/model_transform_presets.inc','game/native/gameplay_scenario/scene_model_bindings.hpp','game/native/gameplay_scenario/scene_model_bindings.cpp','game/native/gameplay_scenario/content.hpp','game/native/gameplay_scenario/content.cpp']]
 paths += model_native
 inputs={p.relative_to(ROOT).as_posix():sha(p) for p in paths};out.mkdir();(out/'ownership_reference.hpp').write_text(header);original=out/'original.cpp';original.write_text('#include "ownership_reference.hpp"\n'+'\n'.join(bodies))
 actual_bindings=out/'actual_model_bindings.cpp';actual_bindings.write_text('#include "ownership_reference.hpp"\nnamespace model_binding_original {\n'+'\n'.join(source.read_text()[source.read_text().index('// Function:'):]for source in actual_binding_sources)+'\n}\n')
 assets=[];rows=[];inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json'
 if sha(inventory)!='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2':raise ValueError('Owned inventory changed')
 entries=json.loads(inventory.read_bytes());blobs={}
 with (ROOT/'iso/Resident Evil - Outbreak (v2.00).iso').open('rb') as stream:
  for e in entries:
   asset_names=[n for n in e['names'] if re.fullmatch(r'(obj[0-9]{3}\.dat|r[0-9]{3}\.sto|r(001|002|041)[0-9]{4}\.rdt|[wg](001|002|041)[0-9]{4}\.bin)',n)]
   if not asset_names:continue
   stream.seek(e['iso_offset']);b=stream.read(e['bytes'])
   if hashlib.sha256(b).hexdigest()!=e['sha256']:raise ValueError('Owned object asset changed')
   n=asset_names[0];blobs[n]=b;assets.append(dict(name=n,**e))
 for scenario in [1,2,41]:
  for n in [f'obj{scenario:03}.dat',f'r{scenario:03}.sto']:(out/n).write_bytes(blobs[n])
 for n,b in blobs.items():
  if not n.endswith('.rdt'):continue
  offset=int.from_bytes(b[0x70:0x74],'little');size=int.from_bytes(b[0x74:0x78],'little')
  if not size:continue
  if size<0x934 or offset>len(b) or size>len(b)-offset:raise ValueError('Owned sectionE extent invalid')
  destination=out/(n+'.section-e');destination.write_bytes(b[offset:offset+size]);scenario=int(n[1:4]);room=int(n[4:6]);wall='w'+n[1:8]+'.bin';(out/wall).write_bytes(blobs[wall]);floor='g'+n[1:8]+'.bin';(out/floor).write_bytes(blobs[floor]);rows.append('\t'.join([str(out/f'obj{scenario:03}.dat'),str(out/f'r{scenario:03}.sto'),str(room),str(destination),str(out/wall),str(out/floor)]))
 manifest=out/'rooms.tsv';manifest.write_text('\n'.join(rows)+'\n');profile=data[0x723740-0x570000:0x723740-0x570000+200]
 if hashlib.sha256(profile).hexdigest()!='c49896573cdc5137476866c5b6ac54566e95893b9a0e97b786ee31eabc403659':raise ValueError('Owned profile table changed')
 (out/'profiles.bin').write_bytes(profile);(out/'geometry_tables.bin').write_bytes(data[0x719900-0x570000:0x719a60-0x570000])
 compiler=COMPILERS[a.compiler];env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','');exe=out/'ownership.exe';record=dict(schema=1,status='failed',source_sha256=inputs,compiler_sha256=sha(compiler),original_word_audits=audits,owned_assets=assets,game_launched=False,checks=[])
 command=[str(compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(ROOT),'-I'+str(out),*[str(ROOT/'game/native/gameplay_collision'/n) for n in names if n.endswith('.cpp')],*[str(p)for p in model_native if p.suffix=='.cpp'],str(ROOT/'game/native/gameplay_actors/entity.cpp'),str(ROOT/'game/native/transform_math/transform_math.cpp'),str(original),str(actual_bindings),'-o',str(exe)]
 try:
  for label,cmd in [('compile',command),('test',[str(exe),str(manifest),str(out/'profiles.bin'),str(out/'geometry_tables.bin')])]:
   result=subprocess.run(cmd,capture_output=True,env=env,timeout=120);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);record['checks'].append(dict(label=label,command=cmd,exit=result.returncode))
   if result.returncode:raise RuntimeError(label+': '+result.stderr.decode(errors='replace')[-3000:])
   if label=='test':record['results']=json.loads(result.stdout)
  for name,digest in inputs.items():
   if sha(ROOT/name)!=digest:raise ValueError('Source changed: '+name)
  record['status']='native canonical room-object lifetime comparisons passed'
 finally:
  record['output_sha256']={p.name:sha(p) for p in out.iterdir() if p.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(record['results']))
if __name__=='__main__':main()
