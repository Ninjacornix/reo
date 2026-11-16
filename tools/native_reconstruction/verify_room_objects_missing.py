"""Original 6AD5C0/6AD720/6AD610 missing-asset differential (owned inputs)."""
import argparse,hashlib,json,os,re,shlex,subprocess,time
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
ROOT=Path(__file__).resolve().parents[2]
COMPILER=Path('C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe')
ENTRIES=[0x6ad5c0,0x6acf80,0x6ad720,0x6ad610,0x6ad0f0,0x6ad010]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def native_sources():
    return {p.relative_to(ROOT).as_posix():sha(p) for p in (ROOT/'game/native').rglob('*') if p.is_file() and p.suffix in ('.cpp','.hpp','.h','.inc','.txt')}
def main():
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);p.add_argument('--native-build',type=Path,required=True);p.add_argument('--build-receipt',type=Path,required=True);a=p.parse_args()
    out=a.output.resolve();build=a.native_build.resolve();allowed=(ROOT/'build-native-sjuni').resolve()
    if out.exists() or out==allowed or not out.is_relative_to(allowed):raise ValueError('Fresh private output required')
    receipt=json.loads(a.build_receipt.read_text());before=native_sources()
    archives={p.relative_to(build).as_posix():sha(p) for p in build.rglob('*.a')}
    if receipt['status']!='passed' or before!=receipt['sources_sha256'] or archives!=receipt['archives_sha256'] or sha(COMPILER)!=receipt['compiler_sha256']:
        raise ValueError('Passing shared compiler/source/archive identity required')
    image=ROOT/'build-function-index/owned-overlays/o2.bin';image_bytes=image.read_bytes()
    if sha(image)!='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226':raise ValueError('Owned image changed')
    inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json'
    if sha(inventory)!='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2':raise ValueError('Owned inventory changed')
    selected={}
    with (ROOT/'iso/Resident Evil - Outbreak (v2.00).iso').open('rb') as iso:
        for entry in json.loads(inventory.read_bytes()):
            matches=set(entry['names'])&{'obj041.dat','r041.sto'}
            if not matches:continue
            iso.seek(entry['iso_offset']);payload=iso.read(entry['bytes'])
            if hashlib.sha256(payload).hexdigest()!=entry['sha256']:raise ValueError('Owned asset changed')
            for name in matches:selected[name]=payload
    if len(selected)!=2:raise ValueError('Owned type/placement assets missing')
    out.mkdir()
    for name,data in selected.items():(out/name).write_bytes(data)
    (out/'profiles.bin').write_bytes(image_bytes[0x723740-0x570000:0x723740-0x570000+200])
    audits=[];bodies=[]
    for at in ENTRIES:
        source=ROOT/f'recomp/config/output_ovl/o2/o2_{at:08X}_0x{at:x}.cpp';text=source.read_text();end=int(re.search(r'// Address: 0x[0-9a-fA-F]+ - 0x([0-9a-fA-F]+)',text)[1],16)
        audits.append(compare_source('room-startup-missing',str(source.relative_to(ROOT)),at,end,lambda off,n:image_bytes[off-0x570000:off-0x570000+n]));bodies.append(text[text.index('// Function:'):])
    base=(ROOT/'tools/native_reconstruction/gameplay_collision_oracle/reference.hpp').read_text().split('void o0_00370760')[0].replace('#pragma once','',1)
    declarations='\n'.join(f'void o2_{at:08X}_0x{at:x}(std::uint8_t*,R5900Context*,PS2Runtime*);' for at in ENTRIES)
    prefix=r'''
#include "game/native/gameplay_collision/room_objects.hpp"
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iterator>
#include <vector>
#define WRITE16(at,v) ref_write(rdram,at,std::uint16_t(v))
std::vector<std::byte> files[2];unsigned current_file{};bool present[2]{};
void port_memset(std::uint8_t* m,R5900Context* c,PS2Runtime*){std::memset(m+GPR_U32(c,4),int(GPR_U32(c,5)&255),GPR_U32(c,6));c->g[2].lo=GPR_U32(c,4);c->pc=GPR_U32(c,31);}
void port_memcpy(std::uint8_t* m,R5900Context* c,PS2Runtime*){std::memcpy(m+GPR_U32(c,4),m+GPR_U32(c,5),GPR_U32(c,6));c->g[2].lo=GPR_U32(c,4);c->pc=GPR_U32(c,31);}
void port_format(std::uint8_t*,R5900Context* c,PS2Runtime*){const auto fmt=GPR_U32(c,5);current_file=fmt==0x740c48?0:1;if(fmt!=0x740c48&&fmt!=0x740c08)throw std::runtime_error("unexpected original path");c->pc=GPR_U32(c,31);}
void port_load(std::uint8_t* m,R5900Context* c,PS2Runtime*){if(present[current_file])std::memcpy(m+GPR_U32(c,5),files[current_file].data(),files[current_file].size());c->g[2].lo=present[current_file]?files[current_file].size():0;c->pc=GPR_U32(c,31);}
'''
    lookup='\nPS2Runtime::Fn PS2Runtime::lookupFunction(std::uint32_t a)const{switch(a){'
    for at in ENTRIES:lookup+=f'case 0x{at:x}:return o2_{at:08X}_0x{at:x};'
    for at,name in [(0x107c68,'memset'),(0x107ab0,'memcpy'),(0x10a830,'format'),(0x1aa3e0,'load')]:lookup+=f'case 0x{at:x}:return port_{name};'
    lookup+='default:throw std::runtime_error("unhandled original call");}}\n'
    maincode=r'''
using reo::native::gameplay_collision::room_objects::Owner;
std::vector<std::byte> load(const char* path){std::ifstream f(path,std::ios::binary);std::vector<char> raw{std::istreambuf_iterator<char>(f),{}};if(raw.empty())throw std::runtime_error("missing owned fixture");auto data=std::as_bytes(std::span(raw));return {data.begin(),data.end()};}
void check(bool ok){if(!ok)throw std::runtime_error("original/native missing room-object mismatch");}
int main(int argc,char**argv){try{check(argc==4);files[0]=load(argv[1]);files[1]=load(argv[2]);auto profile=load(argv[3]);check(profile.size()==200);unsigned cases=0,checks=0;
for(unsigned types=0;types<2;++types)for(unsigned placements=0;placements<3;++placements){
    std::vector<std::uint8_t> m(0x800000,0);std::memcpy(m.data()+0x723740,profile.data(),profile.size());
    present[0]=types!=0;present[1]=placements!=0;auto original_placement=files[1];if(placements==2)files[1][0]=std::byte{0};
    m[0x3243d7]=1;ref_write(m.data(),0x3243da,std::uint16_t(41));ref_write(m.data(),0x32440c,std::uint32_t(0x20000));
    m[0x74b2ba]=12;m[0x74b2b9]=13;m[0x74b2bc]=14;R5900Context c{};c.g[29].lo=0x7f0000;c.g[31].lo=0x1234;PS2Runtime runtime;o2_006AD5C0_0x6ad5c0(m.data(),&c,&runtime);
    Owner native=types?Owner::import_types(files[0]):Owner{};native.apply_source_startup_bytes();
    if(placements)native.import_placements(files[1]);else native.finish_without_placements();
    check(native.initialized()&&c.pc==0x1234&&m[0x74b2ba]==0&&m[0x74b2b9]==4&&m[0x74b2bc]==0);++checks;
    for(unsigned i=0;i<32;++i){auto* t=native.type(i);const auto at=0x74b1c0+8*i;const bool ok=t&&std::uint8_t(t->profile)==m[at]&&std::uint8_t(t->capacity)==m[at+1]&&t->callback==m[at+3]&&t->parameter4==m[at+4]&&t->flags==ref_read<std::uint16_t>(m.data(),at+6)&&t->model_slot==ref_read<std::uint16_t>(m.data(),0x74b180+2*i);if(!ok)std::fprintf(stderr,"types=%u placements=%u type=%u native=%u/%u/%u/%u/%u/%u original=%u/%u/%u/%u/%u/%u\n",types,placements,i,unsigned(std::uint8_t(t->profile)),unsigned(std::uint8_t(t->capacity)),unsigned(t->callback),unsigned(t->parameter4),unsigned(t->flags),unsigned(t->model_slot),unsigned(m[at]),unsigned(m[at+1]),unsigned(m[at+3]),unsigned(m[at+4]),unsigned(ref_read<std::uint16_t>(m.data(),at+6)),unsigned(ref_read<std::uint16_t>(m.data(),0x74b180+2*i)));check(ok);++checks;}
    const auto ids=native.objects();if(ids.size()!=m[0x7473f0])std::fprintf(stderr,"types=%u placements=%u count=%zu original=%u\n",types,placements,ids.size(),unsigned(m[0x7473f0]));check(ids.size()==m[0x7473f0]);++checks;
    for(unsigned i=0;i<ids.size();++i){const auto* o=native.get(ids[i]);const auto at=0x3c4580+60*(i+1);const bool ok=o&&o->room==m[at+1]&&o->external_id==m[at+2]&&o->type==ref_read<std::uint16_t>(m.data(),at+4)&&o->control_flags==ref_read<std::uint32_t>(m.data(),at+0x24)&&o->width==std::int8_t(m[at+0x1f])&&o->height==std::int8_t(m[at+0x20])&&o->depth==std::int8_t(m[at+0x21]);if(!ok)std::fprintf(stderr,"types=%u placements=%u object=%u native=%u/%u/%u/%u/%d/%d/%d original=%u/%u/%u/%u/%d/%d/%d\n",types,placements,i,unsigned(o->room),unsigned(o->external_id),unsigned(o->type),unsigned(o->control_flags),int(o->width),int(o->height),int(o->depth),unsigned(m[at+1]),unsigned(m[at+2]),unsigned(ref_read<std::uint16_t>(m.data(),at+4)),unsigned(ref_read<std::uint32_t>(m.data(),at+0x24)),int(std::int8_t(m[at+0x1f])),int(std::int8_t(m[at+0x20])),int(std::int8_t(m[at+0x21])));check(ok);++checks;}
    files[1]=std::move(original_placement);++cases;
}
std::printf("{\"cases\":%u,\"checks\":%u,\"game_launched\":false}\n",cases,checks);return 0;
}catch(const std::exception&e){std::fprintf(stderr,"%s\n",e.what());return 1;}}
'''
    fixture=out/'original_native.cpp';fixture.write_text(base+prefix+declarations+lookup+'\n'.join(bodies)+maincode)
    ninja=(build/'build.ninja').read_text();at=ninja.index('build gameplay_application/native_session_tests.exe:');libs=shlex.split(re.search(r'^  LINK_LIBRARIES = (.*)$',ninja[at:],re.M).group(1))
    exe=out/'original_native.exe';env=dict(os.environ);env['PATH']=str(COMPILER.parent)+os.pathsep+env.get('PATH','')
    cmd=[str(COMPILER),'-std=c++20','-O2','-fno-fast-math','-ffp-contract=off','-I'+str(ROOT),str(fixture),*libs,'-o',str(exe)]
    record={'status':'failed','compiler_sha256':sha(COMPILER),'build_receipt':str(a.build_receipt.resolve()),'build_receipt_sha256':sha(a.build_receipt),'native_sources_sha256':before,'archives_sha256':archives,'original_word_audits':audits,'fixture_sha256':sha(fixture),'assets_sha256':{name:hashlib.sha256(data).hexdigest() for name,data in selected.items()},'checks':[],
            'game_run':False,'installed_in_game':False,'stage4_complete':False,
            'scope':'Six source-ordered room-object importer cases on actual owned obj041/r041 inputs, including missing types/placements and invalid placement schema. Complete original gameplay importer bodies run; bounded IO/format and memory primitives are ports. Shared production archives only; no complete startup or gameplay claim.'}
    try:
        for name,command in [('compile',cmd),('test',[str(exe),str(out/'obj041.dat'),str(out/'r041.sto'),str(out/'profiles.bin')])]:
            start=time.monotonic();result=subprocess.run(command,cwd=build,env=env,capture_output=True,timeout=120);(out/(name+'.stdout.txt')).write_bytes(result.stdout);(out/(name+'.stderr.txt')).write_bytes(result.stderr);record['checks'].append({'name':name,'command':command,'exit':result.returncode,'seconds':time.monotonic()-start})
            if result.returncode:raise RuntimeError(name+': '+result.stderr.decode(errors='replace')[-3000:])
            if name=='test':record['result']=json.loads(result.stdout)
        record['status']='passed'
    finally:
        after=native_sources();record['source_drift']=[name for name in sorted(before.keys()|after.keys()) if before.get(name)!=after.get(name)]
        after_archives={p.relative_to(build).as_posix():sha(p) for p in build.rglob('*.a')}
        record['archive_drift']=[name for name in sorted(archives.keys()|after_archives.keys()) if archives.get(name)!=after_archives.get(name)]
        if record['source_drift'] or record['archive_drift']:record['status']='failed'
        (out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    if record['status']!='passed':raise ValueError('Source/archive drift during comparison')
    print(json.dumps(record['result']))
if __name__=='__main__':main()
