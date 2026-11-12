"""Native owned scene-voice preparation through real canonical instances, loader and finite queue; no game/device access."""
import argparse,hashlib,json,os,struct,subprocess,shutil
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
CMAKE=Path('C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe')
NINJA=Path('C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/Ninja/ninja.exe')
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def run(cmd,out,label):
 p=subprocess.run(cmd,capture_output=True,text=True,timeout=300);(out/(label+'.stdout.txt')).write_text(p.stdout);(out/(label+'.stderr.txt')).write_text(p.stderr)
 if p.returncode:raise RuntimeError(label+' failed: '+p.stdout[-4500:]+p.stderr[-4500:])
 return dict(command=cmd,exit_code=p.returncode,stdout_sha256=sha(out/(label+'.stdout.txt')),stderr_sha256=sha(out/(label+'.stderr.txt')))
def main(a):
 cc=Path(a.compiler).resolve();out=a.output.resolve();assert cc.exists() and not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir(parents=True);(out/'receipt.json').write_text(json.dumps(dict(status='failed',game_launched=False,hardware_output=False))+'\n')
 data=Path(os.environ['LOCALAPPDATA'])/'OutbreakRecomp/launcher/imports/file1/25e64b631bbaa0cac9a4822cb66174ff14c3531851d1e502c0a06704379bf446/data'
 elf=(data/'SLUS_207.65').read_bytes();assert hashlib.sha256(elf).hexdigest()=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';phoff=struct.unpack_from('<I',elf,28)[0];phsize,phcount=struct.unpack_from('<HH',elf,42);loads=[struct.unpack_from('<8I',elf,phoff+i*phsize) for i in range(phcount)]
 segment=next(p for p in loads if p[0]==1 and p[2]<=0x220498 and 0x220498+4000<=p[2]+p[4]);table=elf[segment[1]+0x220498-segment[2]:segment[1]+0x220498-segment[2]+4000];assert hashlib.sha256(table).hexdigest()=='ba7a4e40b40741d52daddb3e80bf6c55d0ddcf93df46580ba6de9ad8c5e9c138';(out/'attenuation.bin').write_bytes(table)
 base=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1';receipt=json.loads((base/'receipt.json').read_text());assert receipt['status']=='passed'
 for name,digest in receipt['output_sha256'].items():assert sha(base/name)==digest
 members=json.loads((base/'members.json').read_text());member=next(x for x in members if x['member']=='NETBIO01.DAT/1/69');container=next(x for x in json.loads((base/'containers.json').read_text()) if x['path']==member['container']);path=data/member['container'];offset=member['iso_offset']-container['offset'];before_asset=(path.stat().st_size,path.stat().st_mtime_ns)
 with path.open('rb') as f:f.seek(offset);payload=f.read(member['bytes'])
 assert hashlib.sha256(payload).hexdigest()==member['sha256']=='f6fc3d252472720860b71ebfa8c63536de2ff73726ab0b63fb4bd607a9d62231';(out/'owned_bgm69.adx').write_bytes(payload)
 scene_assets=[];scene_before=[]
 for index in [32,33]:
  chosen=next(x for x in members if x['member']==f'NETBIO01.DAT/0/{index}');container_scene=next(x for x in json.loads((base/'containers.json').read_text())if x['path']==chosen['container']);source_path=data/chosen['container'];scene_before.append((source_path,source_path.stat().st_size,source_path.stat().st_mtime_ns))
  with source_path.open('rb')as scene_file:scene_file.seek(chosen['iso_offset']-container_scene['offset']);body=scene_file.read(chosen['bytes'])
  assert hashlib.sha256(body).hexdigest()==chosen['sha256'];(out/f'owned_scene{index}.adx').write_bytes(body);scene_assets.append(chosen)

 paths=[HERE/'scene_voice_preparation_oracle/CMakeLists.txt',HERE/'scene_voice_preparation_oracle/scene_voice_preparation_tests.inc',HERE/'stream_instances_oracle/tests.cpp',Path(__file__)]+[ROOT/'game/native/gameplay_scenario'/n for n in ['stream_channels.hpp','stream_channels.cpp','stream_gain_curve.inc','stream_instances.hpp','stream_instances.cpp','stream_voice_queue.cpp','scene_voice_assets.hpp','scene_voice_assets.cpp','scene_voice_profile.inc','scene_voice_preparation.hpp','scene_voice_preparation.cpp']]
 before={p.relative_to(ROOT).as_posix():sha(p) for p in paths}
 for p in paths:
  target=out/'sources'/p.relative_to(ROOT);target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(p,target)
 os.environ['PATH']=str(cc.parent)+os.pathsep+os.environ.get('PATH','')
 checks=[run([str(CMAKE),'-S',str(HERE/'scene_voice_preparation_oracle'),'-B',str(out/'build'),'-G','Ninja','-DCMAKE_BUILD_TYPE=Release','-DCMAKE_EXPORT_COMPILE_COMMANDS=ON','-DCMAKE_CXX_COMPILER='+str(cc),'-DCMAKE_MAKE_PROGRAM='+str(NINJA)],out,'configure')]
 commands=json.loads((out/'build/compile_commands.json').read_text());sources=sorted({Path(c['file']).resolve() for c in commands if Path(c['file']).resolve().is_relative_to(ROOT/'game/native')})
 modules={ROOT/'game/native'/p.relative_to(ROOT/'game/native').parts[0] for p in sources};headers={p for module in modules for p in module.rglob('*') if p.is_file() and p.suffix in ['.h','.hpp','.inc']}
 native={p.relative_to(ROOT).as_posix():sha(p) for p in sources};native_headers={p.relative_to(ROOT).as_posix():sha(p) for p in sorted(headers)}
 checks.append(run([str(CMAKE),'--build',str(out/'build'),'--target','scene_voice_preparation_checks','-j','2'],out,'build'))
 checks.append(run([str(out/'build/scene_voice_preparation_checks.exe'),str(out/'owned_bgm69.adx'),str(out/'attenuation.bin'),str(out/'owned_scene32.adx'),str(out/'owned_scene33.adx')],out,'test'))
 assert all(sha(ROOT/p)==d for p,d in before.items()) and all(sha(ROOT/p)==d for p,d in native.items()) and all(sha(ROOT/p)==d for p,d in native_headers.items());assert (path.stat().st_size,path.stat().st_mtime_ns)==before_asset;assert all((p.stat().st_size,p.stat().st_mtime_ns)==(size,modified)for p,size,modified in scene_before)
 q=dict(status='passed',compiler=str(cc),compiler_sha256=sha(cc),cmake_sha256=sha(CMAKE),ninja_sha256=sha(NINJA),source_sha256=before,native_cpp_source_sha256=native,native_header_source_sha256=native_headers,owned_asset=member,owned_scene_assets=scene_assets,owned_member_container_offset=offset,owned_member_copied_sha256=sha(out/'owned_bgm69.adx'),owned_attenuation_table_sha256=sha(out/'attenuation.bin'),index_receipt_sha256=sha(base/'receipt.json'),checks=checks,result=json.loads((out/'test.stdout.txt').read_text()),game_launched=False,hardware_output=False,installed_in_game=False,limitations=['Owned BGM69 and actual scene32/33 ADX payloads share a declared bounded native AFS fixture; this proves their contents and canonical preparation, not a stock archive-route installation.','Native instances/decoder/PCM/submix run offscreen without a physical audio device; no subjective audio claim or game-speed measurement.','Three-instance mixer order is explicit test input; actual production summation-order authority remains a caller gate.','2-second source-service test holds the real game tick fixed and does not advance the engine ramp.'])
 (out/'receipt.json').write_text(json.dumps(q,indent=2)+'\n');print(json.dumps(dict(status='passed',result=q['result'])))
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--compiler',required=True);p.add_argument('--output',required=True,type=Path);main(p.parse_args())
