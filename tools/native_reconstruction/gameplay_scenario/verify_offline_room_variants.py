"""Complete701840/815E70(2), explicit cold authority and retained SGL owners."""
import argparse,hashlib,json,os,re,struct,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parent))
from verify_native_session import dependency_sources
from verify_scenario_specific_events import body
ASSETS={'r001.sgl':'73df31bfd576bc6095fe44b6c51f1eb1e6c955c73b25d2ff9d5e4312cb475faf','r002.sgl':'0347121969ec0a76d4baf6d0e5256e874bf5f93eaa95fe6f147187dd4877a64a','r028.sgl':'e79050973d67a082954357452782bd571e1fd71c87802b8ec4799f8766afbe36','r035.sgl':'64776cadc528f509bde1d864bb1c1684072a8fbdeed3e49940eabbf02e94a468','r041.sgl':'55e3a5e8d1ef8a8a04599736315322323a5facbc995298742c32fedfbb01e17d'}
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def main(a):
    cc=a.compiler.resolve();build=a.native_build.resolve();out=a.output.resolve()
    assert sha(cc)=='f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3'
    assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
    elfpath=Path(os.environ['LOCALAPPDATA'])/'OutbreakRecomp/launcher/imports/file1/25e64b631bbaa0cac9a4822cb66174ff14c3531851d1e502c0a06704379bf446/data/SLUS_207.65'
    elf=elfpath.read_bytes();assert hashlib.sha256(elf).hexdigest()=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    phoff=struct.unpack_from('<I',elf,28)[0];stride,count=struct.unpack_from('<HH',elf,42)
    segments=[struct.unpack_from('<8I',elf,phoff+i*stride)for i in range(count)]
    cold_ranges=[(0x843780,12),(0x4b9d20,128),(0x83e540,0x5210)]
    for start,size in cold_ranges:
        assert any(p[0]==1 and p[2]+p[4]<=start and start+size<=p[2]+p[5]for p in segments)
    chunks=[];originals=[];words=0
    for group,ids,digest,base in [('o2',[0x701840],'45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226',0x570000),('o9',[0x815e30,0x815e70,0x816000,0x816020,0x816040,0x816060,0x816080,0x8160c0,0x816100,0x816120,0x8161e0,0x816220,0x816250,0x816280,0x8162c0,0x816310,0x816360,0x8163b0,0x8194d0,0x8194f0],'604126d6edca1b1333948d79d1d2c8d2f2e22f4a233efbdfb769c106dafe7343',0x810000)]:
        raw=(ROOT/('build-function-index/owned-overlays/'+group+'.bin')).read_bytes();assert hashlib.sha256(raw).hexdigest()==digest
        for address in ids:
            source=next((ROOT/('recomp/config/output_ovl/'+group)).glob(group+'_'+format(address,'08X')+'_*'));originals.append(source)
            text=body(source,group+'_'+format(address,'08X')+'_0x'+format(address,'x'));chunks.append(text)
            for pc,opcode in re.findall(r'// (0x[0-9a-f]+): (0x[0-9a-f]+)\s',text):
                assert struct.unpack_from('<I',raw,int(pc,16)-base)[0]==int(opcode,16);words+=1
    joined='\n'.join(chunks);defined=set(re.findall(r'void ((?:o2|o9)_[A-Za-z0-9_]+)\(',joined));names=set(re.findall(r'\b((?:o2|o9)_[A-Za-z0-9_]+)\(',joined))
    declarations=['void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);'for name in sorted(names)]
    joined+='\n'+'\n'.join('void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){c->pc='+name.split('_')[-1]+';original_transform_port(m,c,r);}'for name in sorted(names-defined))
    fixture=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    (out/'original_fixture.hpp').write_text(fixture.read_text().replace('float vu0_q{};','float vu0_q{};std::uint64_t lo{},hi{};')+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define SRA32(a,b) (std::int32_t(std::int32_t(a)>>(std::uint32_t(b)&31)))\n')
    (out/'original_declarations.inc').write_text('\n'.join(declarations))
    (out/'original_lookup.inc').write_text('\n'.join('case '+name.split('_')[-1]+':'+name+'(m,c,r);return;'for name in sorted(defined)))
    (out/'original.cpp').write_text('#include "original_fixture.hpp"\n#include "original_declarations.inc"\n'+joined)
    inventory=ROOT/'build-native-sjuni/gameplay-script-content-llvm-v21/inventory.json';authored=[]
    for member in json.loads(inventory.read_text()):
        if member['format']!='E':continue
        with Path(member['archive']).open('rb')as stream:stream.seek(member['archive_offset']);data=stream.read(member['bytes'])
        assert hashlib.sha256(data).hexdigest()==member['sha256']
        for block in member['declared_objects']:
            if block['role']!=0:continue
            at=0
            while at<block['upper_bound_bytes']:
                header=struct.unpack_from('<I',data,block['offset']+at)[0];extent=4<<(header>>24)
                if header&0xffffff==0x5a:
                    payload=struct.unpack_from('<2I',data,block['offset']+at+4)
                    authored.append(dict(member=member['name'],member_sha256=member['sha256'],block=block['table_index'],offset=at,payload=payload))
                at+=extent
    assert len(authored)==14
    (out/'authored_commands.inc').write_text('\n'.join('std::array<std::uint32_t,2>{'+','.join(str(v)+'u'for v in row['payload'])+'},'for row in authored))
    assets=[ROOT/'build-native-sjuni/gameplay-navigation-bank-llvm-v2'/name for name in ASSETS]
    assert all(sha(path)==ASSETS[path.name]for path in assets)
    env=dict(os.environ,PATH=str(cc.parent)+os.pathsep+os.environ.get('PATH',''));commands=[]
    def run(command,label):
        result=subprocess.run(command,capture_output=True,text=True,env=env,timeout=240)
        (out/(label+'.stdout.txt')).write_text(result.stdout);(out/(label+'.stderr.txt')).write_text(result.stderr)
        commands.append(dict(command=command,returncode=result.returncode,stdout_sha256=sha(out/(label+'.stdout.txt')),stderr_sha256=sha(out/(label+'.stderr.txt'))))
        if result.returncode:raise RuntimeError(label+': '+result.stderr[-5000:])
    if not a.prepare_only:
        sources,libraries=dependency_sources(build);sources.extend([Path(__file__).resolve(),HERE/'verify_scenario_specific_events.py',*originals,fixture,HERE/'offline_room_variants_tests.cpp',inventory,*assets])
        before={p.relative_to(ROOT).as_posix():sha(p)for p in sources};library_hashes={name:sha(build/name)for name in libraries}
    base=[str(cc),'-std=c++20','-O2','-msse4.1','-fno-fast-math','-ffp-contract=off','-I'+str(ROOT),'-I'+str(out)]
    run(base+['-w','-c',str(out/'original.cpp'),'-o',str(out/'original.o')],'compile-original')
    run(base+['-Wall','-Wextra','-Wpedantic','-Werror','-c',str(HERE/'offline_room_variants_tests.cpp'),'-o',str(out/'tests.o')],'compile-tests')
    if a.prepare_only:print('Original and focused fixture compilation passed; archives not linked.');return
    run([str(cc),str(out/'original.o'),str(out/'tests.o'),'-Wl,--start-group']+[str(build/name)for name in libraries]+['-Wl,--end-group','-lpthread','-o',str(out/'checks.exe')],'link')
    run([str(out/'checks.exe'),*map(str,assets)],'test')
    assert all(sha(ROOT/name)==digest for name,digest in before.items());assert all(sha(build/name)==digest for name,digest in library_hashes.items())
    receipt=dict(schema='reo.native.offline_room_variants.v1',status='passed',compiler=str(cc),compiler_sha256=sha(cc),source_sha256=before,native_library_sha256=library_hashes,executable_sha256=sha(out/'checks.exe'),generated_original_sha256=sha(out/'original.cpp'),generated_fixture_sha256=sha(out/'original_fixture.hpp'),archives_only=True,commands=commands,result=json.loads((out/'test.stdout.txt').read_text()),checked_owned_instruction_comments=words,authored_records=authored,elf_sha256=hashlib.sha256(elf).hexdigest(),cold_elf_bss_ranges=cold_ranges,game_launched=False,stage4_complete=False)
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(dict(status='passed',result=receipt['result'])))
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--native-build',type=Path,required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--prepare-only',action='store_true');main(p.parse_args())
