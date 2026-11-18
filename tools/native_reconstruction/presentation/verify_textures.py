"""Compare native indexed TIM2 pixels with the launcher algorithm on owned room and character assets."""
import hashlib,json,os,pathlib,struct,subprocess,sys
ROOT=pathlib.Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'tools/ps2_debug'))
from dump_nbd_tex import ob_decompress
OUT=ROOT/'build-native-sjuni/stage4-orchestration/presentation-textures-shared-llvm-v2'
BUILD=ROOT/'build-native-sjuni/gameplay-native-llvm-v1'
BUILD_RECEIPT=ROOT/'build-native-sjuni/stage4-orchestration/presentation-controls-integration-llvm-v2/receipt.json'
CC=pathlib.Path('C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe')
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()
def source_hashes():
 paths=[p for p in sorted((ROOT/'game/native').rglob('*')) if p.is_file() and (p.suffix in ('.cpp','.hpp','.h','.inc') or p.name=='CMakeLists.txt')]
 paths += [ROOT/'runtime/input/input.h',ROOT/'runtime/input/input.cpp']
 return {p.relative_to(ROOT).as_posix():sha(p) for p in paths}
def reference(data):
 b=ob_decompress(data);assert b[:4]==b'TIM2';p=16 if b[5]==0 else 128
 total,clut,image=struct.unpack_from('<III',b,p);header,colors=struct.unpack_from('<HH',b,p+12);ct,typ=b[p+18:p+20];w,h=struct.unpack_from('<HH',b,p+20)
 assert typ in (4,5) and (ct&63)==3 and colors==(16 if typ==4 else 256) and p+total<=len(b) and header+image+clut<=total
 pixels=bytearray(w*h*4);im=p+header;pal=im+image
 for i in range(w*h):
  k=((b[im+i//2]>>((i&1)*4))&15) if typ==4 else b[im+i]
  if typ==5 and not ct&128:k=(k&~24)|((k&8)<<1)|((k&16)>>1)
  pixels[i*4:i*4+3]=b[pal+k*4:pal+k*4+3];pixels[i*4+3]=min(255,b[pal+k*4+3]*2)
 return w,h,bytes(pixels)
def main():
 receipt=json.loads(BUILD_RECEIPT.read_text());assert receipt['status']=='passed' and not receipt['source_drift'] and not receipt['archive_drift'] and sha(CC)==receipt['compiler_sha256']
 before=source_hashes();assert all(before.get(name)==value for name,value in receipt['sources_sha256'].items());extra_sources={name:value for name,value in before.items() if name not in receipt['sources_sha256']};archives={name:sha(BUILD/name) for name in receipt['archives_sha256']};assert archives==receipt['archives_sha256']
 assert not OUT.exists();OUT.mkdir(parents=True);exe=OUT/'texture_checks.exe';env=dict(os.environ,PATH=str(CC.parent)+os.pathsep+os.environ.get('PATH',''))
 subprocess.run([str(CC),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(ROOT),str(ROOT/'tools/native_reconstruction/presentation/texture_tests.cpp'),str(BUILD/'gameplay_application/libreo_native_gameplay_presentation.a'),'-o',str(exe)],check=True,env=env)
 inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json';assert sha(inventory)=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2';rows=json.loads(inventory.read_bytes());lookup={r['member']:r for r in rows};mesh=(ROOT/'build-native-sjuni/stage4-orchestration/presentation-mesh-explore/r0417300.nbd').read_bytes();assert hashlib.sha256(mesh).hexdigest()=='6d49570f8148054ef35d81ba6e64680740c8ff3288cdbd81bf92425ce3c546c3'
 count=struct.unpack_from('<I',mesh,128)[0];ordinals=struct.unpack_from('<'+'I'*count,mesh,132);items=[]
 with (ROOT/'iso/Resident Evil - Outbreak (v2.00).iso').open('rb') as f:
  for ordinal in ordinals:
   row=lookup[f'NETBIO00.DAT/9/{ordinal}'];f.seek(row['iso_offset']);data=f.read(row['bytes']);assert hashlib.sha256(data).hexdigest()==row['sha256'];items.append((str(ordinal),data))
 actor=(ROOT/'build-native-sjuni/stage4-orchestration/presentation-mesh-explore/P00_00.nbd').read_bytes();assert hashlib.sha256(actor).hexdigest()=='964daa4c3ce1cf724e62b0e9cda79a88a4761c4899d159d0090ae5ba539b4baf';offset=struct.unpack_from('<I',actor,4)[0]
 for i in range(struct.unpack_from('<I',actor,12)[0]):
  n=struct.unpack_from('<I',actor,offset)[0];offset+=4;items.append((f'actor{i}',actor[offset:offset+n]));offset+=n
 total=0
 for name,data in items:
  src=OUT/(name+'.sld');dst=OUT/(name+'.rgba');src.write_bytes(data);w,h,expected=reference(data)
  run=subprocess.run([str(exe),str(src),str(dst)],capture_output=True,text=True,env=env,check=True);assert run.stdout.strip()==f'{w} {h}' and dst.read_bytes()==expected;total+=w*h
 assert before==source_hashes() and archives=={name:sha(BUILD/name) for name in archives}
 result={'textures':len(items),'pixels':total,'status':'passed','game_run':False,'compiler_sha256':sha(CC),'build_receipt_sha256':sha(BUILD_RECEIPT),'sources_sha256':before,'extra_unlinked_sources':extra_sources,'archives_sha256':archives,'owned_asset_sha256':{'room':hashlib.sha256(mesh).hexdigest(),'actor':hashlib.sha256(actor).hexdigest(),'inventory':sha(inventory)},'compressed_texture_sha256':{name:hashlib.sha256(data).hexdigest() for name,data in items},'fixture_sha256':sha(ROOT/'tools/native_reconstruction/presentation/texture_tests.cpp'),'reference_sha256':sha(ROOT/'tools/ps2_debug/dump_nbd_tex.py'),'driver_sha256':sha(pathlib.Path(__file__))}
 (OUT/'receipt.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({'textures':len(items),'pixels':total,'status':'passed','game_run':False}))
if __name__=='__main__':main()
