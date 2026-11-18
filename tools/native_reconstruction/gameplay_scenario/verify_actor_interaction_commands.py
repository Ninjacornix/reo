"""Small original-body qualification for 172/6C/106 with canonical VM owners."""
import argparse,hashlib,json,os,re,struct,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parent))
from verify_native_session import dependency_sources
from verify_scenario_specific_events import body
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def main(a):
    cc=a.compiler.resolve();build=a.native_build.resolve();out=a.output.resolve()
    assert sha(cc)=='f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3'
    assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
    raw=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes()
    assert hashlib.sha256(raw).hexdigest()=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    originals=[];chunks=[];words=0
    for ident in ['0068F420','00692480','00694AD0','006268D0','005F2210']:
        source=next((ROOT/'recomp/config/output_ovl/o2').glob('o2_'+ident+'_*'));originals.append(source)
        text=body(source,'o2_'+ident+'_0x'+format(int(ident,16),'x'));chunks.append(text)
        for pc,opcode in re.findall(r'// (0x[0-9a-f]+): (0x[0-9a-f]+)\s',text):
            assert int.from_bytes(raw[int(pc,16)-0x570000:int(pc,16)-0x570000+4],'little')==int(opcode,16);words+=1
    joined='\n'.join(chunks);defined=set(re.findall(r'void (o2_[A-Za-z0-9_]+)\(',joined))
    names=set(re.findall(r'\b(o2_[A-Za-z0-9_]+)\(',joined));assert names==defined
    fixture=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    text=fixture.read_text().replace('float vu0_q{};','float vu0_q{};std::uint64_t lo{},hi{};')
    text+='\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define SRA32(a,b) (std::int32_t(std::int32_t(a)>>(std::uint32_t(b)&31)))\n'
    (out/'original_fixture.hpp').write_text(text)
    (out/'original_declarations.inc').write_text('\n'.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);'for name in sorted(defined)))
    (out/'original_lookup.inc').write_text('\n'.join('case '+name.split('_')[-1]+':'+name+'(m,c,r);return;'for name in sorted(defined)))
    (out/'original.cpp').write_text('#include "original_fixture.hpp"\n#include "original_declarations.inc"\n'+joined)
    inventory=ROOT/'build-native-sjuni/gameplay-script-content-llvm-v21/inventory.json';members=json.loads(inventory.read_text());authored=[]
    for member in members:
        if member['format']!='E':continue
        with Path(member['archive']).open('rb')as stream:stream.seek(member['archive_offset']);data=stream.read(member['bytes'])
        assert hashlib.sha256(data).hexdigest()==member['sha256']
        for block in member['declared_objects']:
            if block['role']!=0:continue
            at=0
            while at<block['upper_bound_bytes']:
                header=struct.unpack_from('<I',data,block['offset']+at)[0];extent=4<<(header>>24);opcode=header&0xffffff
                if opcode in(0x6c,0x106,0x172):
                    payload=struct.unpack_from('<'+'I'*(extent//4-1),data,block['offset']+at+4)
                    authored.append(dict(member=member['name'],member_sha256=member['sha256'],block=block['table_index'],offset=at,opcode=opcode,payload=payload))
                at+=extent
    assert len(authored)==12
    (out/'authored_commands.inc').write_text('\n'.join('Command{'+str(row['opcode'])+'u,{'+','.join(str(v)+'u'for v in row['payload'])+'}},'for row in authored))
    env=dict(os.environ,PATH=str(cc.parent)+os.pathsep+os.environ.get('PATH',''));commands=[]
    def run(command,label):
        result=subprocess.run(command,capture_output=True,text=True,env=env,timeout=240)
        (out/(label+'.stdout.txt')).write_text(result.stdout);(out/(label+'.stderr.txt')).write_text(result.stderr)
        commands.append(dict(command=command,returncode=result.returncode,stdout_sha256=sha(out/(label+'.stdout.txt')),stderr_sha256=sha(out/(label+'.stderr.txt'))))
        if result.returncode:raise RuntimeError(label+': '+result.stderr[-5000:])
    if not a.prepare_only:
        sources,libraries=dependency_sources(build);sources.extend([Path(__file__).resolve(),HERE/'verify_scenario_specific_events.py',*originals,fixture,HERE/'actor_interaction_commands_tests.cpp',inventory])
        before={p.relative_to(ROOT).as_posix():sha(p)for p in sources};library_hashes={name:sha(build/name)for name in libraries}
    base=[str(cc),'-std=c++20','-O2','-msse4.1','-fno-fast-math','-ffp-contract=off','-I'+str(ROOT),'-I'+str(out)]
    run(base+['-w','-c',str(out/'original.cpp'),'-o',str(out/'original.o')],'compile-original')
    run(base+['-Wall','-Wextra','-Wpedantic','-Werror','-c',str(HERE/'actor_interaction_commands_tests.cpp'),'-o',str(out/'tests.o')],'compile-tests')
    if a.prepare_only:print('Original and focused fixture compilation passed; archives not linked.');return
    run([str(cc),str(out/'original.o'),str(out/'tests.o'),'-Wl,--start-group']+[str(build/name)for name in libraries]+['-Wl,--end-group','-lpthread','-o',str(out/'checks.exe')],'link')
    run([str(out/'checks.exe')],'test')
    assert all(sha(ROOT/name)==digest for name,digest in before.items());assert all(sha(build/name)==digest for name,digest in library_hashes.items())
    receipt=dict(schema='reo.native.actor_interaction_commands.v1',status='passed',compiler=str(cc),compiler_sha256=sha(cc),source_sha256=before,native_library_sha256=library_hashes,executable_sha256=sha(out/'checks.exe'),generated_original_sha256=sha(out/'original.cpp'),generated_fixture_sha256=sha(out/'original_fixture.hpp'),archives_only=True,commands=commands,result=json.loads((out/'test.stdout.txt').read_text()),checked_owned_instruction_comments=words,authored_records=authored,game_launched=False,stage4_complete=False)
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(dict(status='passed',result=receipt['result'])))
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--native-build',type=Path,required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--prepare-only',action='store_true');main(p.parse_args())
