"""Complete authored D0 callbacks against original bodies and real native owners."""
import argparse,hashlib,json,os,re,struct,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parent))
from verify_native_session import dependency_sources
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def body(source,name):
    text=source.read_text();start=text.index('void '+name+'(');begin=text.index('{',start);depth=1;at=begin+1
    while depth:
        depth+=(text[at]=='{')-(text[at]=='}');at+=1
    return text[start:at]
def main(a):
    cc=a.compiler.resolve();build=a.native_build.resolve();out=a.output.resolve()
    assert sha(cc)=='f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3'
    assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
    raw=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes()
    assert hashlib.sha256(raw).hexdigest()=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    zero=(ROOT/'build-function-index/owned-overlays/o0.bin').read_bytes()
    assert hashlib.sha256(zero).hexdigest()=='bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2'
    elfpath=Path(os.environ['LOCALAPPDATA'])/'OutbreakRecomp/launcher/imports/file1/25e64b631bbaa0cac9a4822cb66174ff14c3531851d1e502c0a06704379bf446/data/SLUS_207.65'
    elf=elfpath.read_bytes();assert hashlib.sha256(elf).hexdigest()=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    phoff=struct.unpack_from('<I',elf,28)[0];stride,count=struct.unpack_from('<HH',elf,42)
    loads=[struct.unpack_from('<8I',elf,phoff+i*stride)for i in range(count)];loads=[p for p in loads if p[0]==1]
    def mainbytes(at,size):
        p=next(p for p in loads if p[2]<=at and at+size<=p[2]+p[4]);return elf[p[1]+at-p[2]:p[1]+at-p[2]+size]
    ids=['00690EF0','005B92B0','005B93B0','005A0BA0','005B69A0','006FABF0','005A30F0','005B8880','005B8C90','006FD060','005703E0','00570370','005703A0','005704B0','00570550','005705F0','00666080','0067DBD0','005DD6F0']
    mains=['001AEC80','0018FDF0','001B02D0','001B0300','001B0310','00191A40','00370500']
    chunks=[];originals=[];words=0
    for ident in ids+mains:
        overlay=ident in ids;static=ident=='00370500';prefix='o0_'if static else'o2_'if overlay else'sub_'
        source=next((ROOT/('recomp/config/output_ovl/o0'if static else'recomp/config/output_ovl/o2'if overlay else'recomp/config/output')).glob(prefix+ident+'_*'))
        name=prefix+ident+'_0x'+format(int(ident,16),'x');text=body(source,name);originals.append(source)
        for pc,opcode in re.findall(r'// (0x[0-9a-f]+): (0x[0-9a-f]+)\s',text):
            at=int(pc,16);actual=zero[at-0x370000:at-0x370000+4]if static else raw[at-0x570000:at-0x570000+4]if overlay else mainbytes(at,4)
            assert struct.unpack('<I',actual)[0]==int(opcode,16);words+=1
        chunks.append(text)
    joined='\n'.join(chunks);names=sorted(set(re.findall(r'\b((?:o0|o2|sub)_[A-Za-z0-9_]+)\(',joined)))
    defined=set(re.findall(r'void ((?:o0|o2|sub)_[A-Za-z0-9_]+)\(',joined))
    declarations=['void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);'for name in names]
    ports=set(names)-defined
    joined+='\n'+'\n'.join('void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){c->pc='+name.split('_')[-1]+';original_transform_port(m,c,r);}'for name in sorted(ports))
    fixture=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    text=fixture.read_text().replace('float vu0_q{};','float vu0_q{};std::uint64_t lo{},hi{};')
    text+='\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define SRA32(a,b) (std::int32_t(std::int32_t(a)>>(std::uint32_t(b)&31)))\n'
    (out/'original_fixture.hpp').write_text(text)
    init='inline void original_constants(std::uint8_t* m){\n'
    for at,size in [(0x70a0d0,256),(0x709620,192),(0x709f50,192),(0x73c940,192),(0x7097d0,152),(0x70a0a0,12),(0x70a0c8,5),(0x70b5e0,136),(0x70b668,12)]:
        data=raw[at-0x570000:at-0x570000+size];assert len(data)==size
        init+='const std::array<std::uint8_t,'+str(size)+'> b'+str(at)+'{'+','.join(map(str,data))+'};std::memcpy(m+'+str(at)+',b'+str(at)+'.data(),'+str(size)+');\n'
    initializer=next((ROOT/'recomp/config/output').glob('sub_00195E50_*'));originals.append(initializer)
    stores={}
    for pc,opcode in re.findall(r'// (0x[0-9a-f]+): (0x[0-9a-f]+)\s',initializer.read_text()):
        at=int(pc,16);op=int(opcode,16);assert struct.unpack('<I',mainbytes(at,4))[0]==op
        if 0x195f5c<=at<=0x195fec and op>>26==43:
            assert(op>>21)&31==1;reg=(op>>16)&31;offset=(op&0xffff)-0x4e00
            assert reg in(0,3)and 0<=offset<64;stores[offset]=0x3f800000 if reg==3 else 0
    assert set(stores)==set(range(0,64,4))
    identity=struct.pack('<16I',*(stores[offset]for offset in range(0,64,4)))
    assert struct.unpack('<16f',identity)==(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1)
    init+='const std::array<std::uint8_t,64> identity{'+','.join(map(str,identity))+'};std::memcpy(m+0x294e00,identity.data(),64);}\n'
    (out/'original_declarations.inc').write_text('\n'.join(declarations)+'\n'+init)
    (out/'original_lookup.inc').write_text('\n'.join('case '+name.split('_')[-1]+':'+('original_notices.emplace_back(GPR_U32(c,4),GPR_U32(c,5),GPR_U32(c,6));'if int(name.split('_')[-1],16)==0x67dbd0 else'')+name+'(m,c,r);return;'for name in sorted(defined)))
    (out/'original.cpp').write_text('#include "original_fixture.hpp"\n#include "original_declarations.inc"\n'+joined)
    corpus=ROOT/'build-native-sjuni/effect-geometry-owned-v1';qualification=json.loads((corpus/'receipt.json').read_text());package=corpus/'owned_effect_geometry.bin'
    assert sha(package)==qualification['package_sha256']
    sources,libraries=dependency_sources(build);sources.extend([Path(__file__).resolve(),*originals,fixture,HERE/'scenario_specific_events_tests.cpp'])
    before={p.relative_to(ROOT).as_posix():sha(p)for p in sources};library_hashes={name:sha(build/name)for name in libraries}
    env=dict(os.environ,PATH=str(cc.parent)+os.pathsep+os.environ.get('PATH',''));commands=[]
    def run(command,label):
        result=subprocess.run(command,capture_output=True,text=True,env=env,timeout=240)
        (out/(label+'.stdout.txt')).write_text(result.stdout);(out/(label+'.stderr.txt')).write_text(result.stderr)
        commands.append(dict(command=command,returncode=result.returncode,stdout_sha256=sha(out/(label+'.stdout.txt')),stderr_sha256=sha(out/(label+'.stderr.txt'))))
        if result.returncode:raise RuntimeError(label+': '+result.stderr[-5000:])
    base=[str(cc),'-std=c++20','-O2','-msse4.1','-fno-fast-math','-ffp-contract=off','-I'+str(ROOT),'-I'+str(out)]
    run(base+['-w','-c',str(out/'original.cpp'),'-o',str(out/'original.o')],'compile-original')
    run(base+['-Wall','-Wextra','-Wpedantic','-Werror','-c',str(HERE/'scenario_specific_events_tests.cpp'),'-o',str(out/'tests.o')],'compile-tests')
    # Build the three actual changed native units privately. This permits fast
    # source corrections while retaining the ABI-consistent dependency graph.
    native_objects=[]
    for folder,name in ([]if a.archives_only else[('gameplay_scenario','interpreter'),('gameplay_scenario','scenario_events'),('gameplay_collision','impact_populations')]):
        path=ROOT/'game/native'/folder/(name+'.cpp');obj=out/(name+'.o')
        run(base+['-Wall','-Wextra','-Wpedantic','-Werror','-c',str(path),'-o',str(obj)],'compile-'+name);native_objects.append(str(obj))
    run([str(cc),str(out/'original.o'),str(out/'tests.o'),*native_objects,'-Wl,--start-group']+[str(build/name)for name in libraries]+['-Wl,--end-group','-lpthread','-o',str(out/'checks.exe')],'link')
    run([str(out/'checks.exe'),str(package)],'test')
    assert all(sha(ROOT/name)==digest for name,digest in before.items());assert all(sha(build/name)==digest for name,digest in library_hashes.items())
    receipt=dict(schema='reo.native.scenario_specific_events.v1',status='passed',compiler=str(cc),compiler_sha256=sha(cc),source_sha256=before,native_library_sha256=library_hashes,native_override_object_sha256={Path(name).name:sha(Path(name))for name in native_objects},executable_sha256=sha(out/'checks.exe'),generated_original_sha256=sha(out/'original.cpp'),generated_fixture_sha256=sha(out/'original_fixture.hpp'),archives_only=a.archives_only,commands=commands,result=json.loads((out/'test.stdout.txt').read_text()),checked_owned_instruction_comments=words,owned_effect_package_sha256=sha(package),initialized_identity_profile=dict(static_authority='195E50',bootstrap_executed=False),game_launched=False,stage4_complete=False)
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(dict(status='passed',result=receipt['result'])))
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--native-build',type=Path,required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--archives-only',action='store_true');main(p.parse_args())
