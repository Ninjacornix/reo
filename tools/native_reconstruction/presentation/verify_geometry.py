"""Owned AMO, AHI bind and clipping checks against the current shared production archives."""
import hashlib,json,math,os,pathlib,struct,subprocess
ROOT=pathlib.Path(__file__).resolve().parents[3]
BUILD=ROOT/'build-native-sjuni/gameplay-native-llvm-v1'
RECEIPT=ROOT/'build-native-sjuni/stage4-orchestration/presentation-controls-integration-llvm-v2/receipt.json'
OUT=ROOT/'build-native-sjuni/stage4-orchestration/presentation-geometry-shared-llvm-v1'
ASSETS=ROOT/'build-native-sjuni/stage4-orchestration/presentation-mesh-explore'
CC=pathlib.Path('C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe')
EXPECTED={'r0417300.nbd':'6d49570f8148054ef35d81ba6e64680740c8ff3288cdbd81bf92425ce3c546c3','r0010100.nbd':'383df48e9c9e99d3bd3819dffa1f9599d235fd7ca8f1a6501a6f641cd920441e','P00_00.nbd':'964daa4c3ce1cf724e62b0e9cda79a88a4761c4899d159d0090ae5ba539b4baf'}
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def source_hashes():
 paths=[p for p in sorted((ROOT/'game/native').rglob('*')) if p.is_file() and (p.suffix in ('.cpp','.hpp','.h','.inc') or p.name=='CMakeLists.txt')]
 paths += [ROOT/'runtime/input/input.h',ROOT/'runtime/input/input.cpp']
 return {p.relative_to(ROOT).as_posix():sha(p) for p in paths}
def multiply(a,b):return [[sum(a[r][k]*b[k][c] for k in range(4)) for c in range(4)] for r in range(4)]
def reference_bind(data):
 base=struct.unpack_from('<I',data,0x24)[0];n=struct.unpack_from('<I',data,base+4)[0];at=base+12;poses=[]
 for _ in range(n):
  typ,count,size=struct.unpack_from('<III',data,at)
  if not typ&255:at+=size;continue
  p=at+12;index,parent=struct.unpack_from('<ii',data,p);assert index==len(poses) and parent<index and count==1
  sx,sy,sz=struct.unpack_from('<fff',data,p+16);x,y,z,w=struct.unpack_from('<ffff',data,p+32)
  if typ==0x40000003:sx,sy,sz=1/sx,1/sy,1/sz;x,y,z=-x,-y,-z
  q=math.sqrt(x*x+y*y+z*z+w*w);x,y,z,w=x/q,y/q,z/q,w/q
  m=[[sx*(1-2*(y*y+z*z)),sy*2*(x*y-z*w),sz*2*(x*z+y*w),0],
     [sx*2*(x*y+z*w),sy*(1-2*(x*x+z*z)),sz*2*(y*z-x*w),0],
     [sx*2*(x*z-y*w),sy*2*(y*z+x*w),sz*(1-2*(x*x+y*y)),0],[0,0,0,1]]
  m[0][3],m[1][3],m[2][3]=struct.unpack_from('<fff',data,p+48)
  if parent>=0:m=multiply(poses[parent],m)
  poses.append(m);at+=size
 return poses
def main():
 assert not OUT.exists();receipt=json.loads(RECEIPT.read_text());assert receipt['status']=='passed' and not receipt['source_drift'] and not receipt['archive_drift'] and sha(CC)==receipt['compiler_sha256']
 before=source_hashes();assert all(before.get(k)==v for k,v in receipt['sources_sha256'].items());archives={k:sha(BUILD/k) for k in receipt['archives_sha256']};assert archives==receipt['archives_sha256']
 for name,value in EXPECTED.items():assert sha(ASSETS/name)==value
 OUT.mkdir(parents=True);env=dict(os.environ,PATH=str(CC.parent)+os.pathsep+os.environ.get('PATH',''));fixtures=['inspect_model_mesh.cpp','actor_bind_tests.cpp','raster_tests.cpp']
 binaries=[]
 for fixture in fixtures:
  exe=OUT/(fixture+'.exe');cmd=[str(CC),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(ROOT),str(ROOT/'tools/native_reconstruction/presentation'/fixture),str(BUILD/'gameplay_application/libreo_native_gameplay_presentation.a'),str(BUILD/'transform_math/libreo_native_transform_math.a'),'-o',str(exe)]
  subprocess.run(cmd,check=True,env=env,capture_output=True);binaries.append(exe)
 mesh=subprocess.run([str(binaries[0]),*[str(ASSETS/n) for n in EXPECTED]],check=True,capture_output=True,text=True,env=env)
 bind=subprocess.run([str(binaries[1]),str(ASSETS/'P00_00.nbd'),str(OUT/'inverse.bin')],check=True,capture_output=True,text=True,env=env);assert bind.stdout.strip()=='36'
 raster=subprocess.run([str(binaries[2])],check=True,capture_output=True,text=True,env=env);assert raster.stdout.strip()=='13 raster checks passed'
 poses=reference_bind((ASSETS/'P00_00.nbd').read_bytes());raw=(OUT/'inverse.bin').read_bytes();assert len(raw)==len(poses)*64
 maximum=0
 for i,pose in enumerate(poses):
  values=struct.unpack_from('<16f',raw,i*64);inverse=[[values[4*c+r] for c in range(4)] for r in range(4)];identity=multiply(pose,inverse)
  maximum=max(maximum,max(abs(identity[r][c]-(r==c)) for r in range(4) for c in range(4)))
 assert maximum<0.001
 assert before==source_hashes() and archives=={k:sha(BUILD/k) for k in archives}
 result={'status':'passed','game_run':False,'mesh_output':mesh.stdout,'bind_matrices':len(poses),'max_identity_error':maximum,'raster_output':raster.stdout,'compiler_sha256':sha(CC),'build_receipt_sha256':sha(RECEIPT),'sources_sha256':before,'extra_unlinked_sources':{k:v for k,v in before.items() if k not in receipt['sources_sha256']},'archives_sha256':archives,'owned_assets_sha256':EXPECTED,'fixture_sha256':{f:sha(ROOT/'tools/native_reconstruction/presentation'/f) for f in fixtures},'driver_sha256':sha(pathlib.Path(__file__))}
 (OUT/'receipt.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({'status':'passed','bind_matrices':len(poses),'max_identity_error':maximum,'raster_checks':13,'game_run':False}))
if __name__=='__main__':main()
