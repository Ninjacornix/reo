"""Archive-only132/570080 timed text,5A4F90 choice catalog/draw and1D4020 oracle."""
import argparse,hashlib,json,os,re,struct,subprocess,sys,time
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parent))
from verify_native_session import dependency_sources
from audit_retail_effect_descriptors import compare_source,elf_reader
from verify_scenario_specific_events import body

def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()

def message_corpus(inventory):
    path=Path(inventory[0]['archive']);rows=[]
    with path.open('rb')as f:
        def read(at,n):f.seek(at);data=f.read(n);assert len(data)==n;return data
        def table(base):
            h=read(base,8);assert h[:4]==b'AFS\0';n=struct.unpack_from('<I',h,4)[0]
            assert 0<n<=100000
            raw=read(base+8,n*8+8);no,ns=struct.unpack_from('<II',raw,n*8);names=read(base+no,ns)
            return [(struct.unpack_from('<II',raw,i*8),names[i*48:i*48+32].split(b'\0')[0].decode('ascii'))for i in range(n)]
        roots=table(0)
        for sid in(1,2,28,35,41):
            (base,size),_=next(x for x in roots if x[1].lower()==f'r{sid:03}.afs');sub=table(base)
            (ho,hn),_=next(x for x in roots if x[1].lower()==f'r{sid:03}_h.bin');h=read(ho,hn);first,count=struct.unpack_from('<II',h)
            assert len(h)==8+16*count
            for variant in(0,1):
                key=f'R{sid:03}'+('U'if variant else'')+'_BIN'
                hits=[i for i in range(count)if h[8+16*i:24+16*i].split(b'\0')[0].decode('ascii')==key];assert len(hits)<=1
                data=b'';offset=None;logical=0
                if hits:
                    (at,logical),_=sub[first+hits[0]];extent=(logical+2047)&~2047
                    assert at+extent<=size;offset=base+at;data=read(offset,extent)
                rows.append(dict(scenario=sid,variant=variant,key=key,archive=str(path),offset=offset,logical_bytes=logical,
                                 bytes=len(data),sha256=hashlib.sha256(data).hexdigest(),data=data))
    assert all(row['bytes']if row['variant']else not row['bytes']for row in rows)
    return rows

def main(a):
    cc=a.compiler.resolve();build=a.native_build.resolve();out=a.output.resolve();snapshot=None;manifest=None
    if a.immutable_snapshot:
        snapshot=a.immutable_snapshot.resolve();manifest=json.loads((snapshot/'receipt.json').read_text());assert manifest['status']=='passed'
        assert sha(snapshot/'cohort.json')==manifest['cohort_sha256'];build=snapshot/'native-build';a.build_receipt=snapshot/'cohort.json'
    assert sha(cc)=='f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3'
    assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
    elf=ROOT/'game_data/SLUS_207.65';overlay=ROOT/'build-function-index/owned-overlays/o2.bin'
    assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    main_read=elf_reader(elf.read_bytes());raw=overlay.read_bytes();readers={'sub':main_read,'o2':lambda at,n:raw[at-0x570000:at-0x570000+n]}
    entries={};proof=[];sources=[Path(__file__).resolve(),HERE/'verify_scenario_specific_events.py',HERE.parent/'audit_retail_effect_descriptors.py']
    groups=[('o2',(0x692be0,0x570080,0x570120,0x570140,0x6b6880,0x6b9f30,0x6b9fa0,0x6ba070,0x6ba190,
                    0x5a4f90,0x5a5060,0x5a5090,0x5a52c0,0x6ba230,0x6b7480,0x6b74d0,0x5735a0,0x573630,0x573740,0x573840,0x573890,0x6dee20)),
            ('sub',(0x1c1ce0,0x1b4820,0x1b4590,0x1b4650,0x1b46e0,0x1b49b0,0x1b4a60,0x1a9750,0x1d4020,0x107c68,0x10ae78,0x10afc0,0x10b158))]
    for group,addresses in groups:
        directory=ROOT/('recomp/config/output'if group=='sub'else'recomp/config/output_ovl/'+group)
        for at in addresses:
            path=next(directory.glob(f'{group}_{at:08X}_*.cpp'));name=f'{group}_{at:08X}_0x{at:x}';text=body(path,name)
            start,end=(int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',path.read_text()).groups())
            proof.append(compare_source('complete timed scene text/message-bank/cache/task body',path.relative_to(ROOT).as_posix(),start,end,readers[group]))
            entries[at]=(name,text);sources.append(path)
    for group,at in [('sub',0x1bac20),('sub',0x1baec0),('o2',0x5eadd0),('o2',0x5eaeb0),('o2',0x5fe3c0),('o2',0x5ecf90),('o2',0x5eb520)]:
        directory=ROOT/('recomp/config/output'if group=='sub'else'recomp/config/output_ovl/'+group)
        path=next(directory.glob(f'{group}_{at:08X}_*.cpp'));start,end=(int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',path.read_text()).groups())
        proof.append(compare_source('static native lifecycle/selection/loader caller, not executed',path.relative_to(ROOT).as_posix(),start,end,readers[group]));sources.append(path)
    elfbytes=elf.read_bytes();phoff=struct.unpack_from('<I',elfbytes,28)[0];stride,count=struct.unpack_from('<HH',elfbytes,42)
    segments=[struct.unpack_from('<8I',elfbytes,phoff+i*stride)for i in range(count)]
    cold=next(p for p in segments if p[0]==1 and p[2]+p[4]<=0x3151c0 and 0x316350<=p[2]+p[5])
    inventory_path=ROOT/'build-native-sjuni/gameplay-script-content-llvm-v21/inventory.json';inventory=json.loads(inventory_path.read_text());sources.append(inventory_path)
    corpus=message_corpus(inventory)
    (out/'message_corpus.bin').write_bytes(struct.pack('<I',len(corpus))+b''.join(struct.pack('<III',r['scenario'],r['variant'],r['bytes'])+r['data']for r in corpus))
    authored=[]
    for member in inventory:
        if member['format']!='E':continue
        with Path(member['archive']).open('rb')as f:f.seek(member['archive_offset']);data=f.read(member['bytes'])
        assert hashlib.sha256(data).hexdigest()==member['sha256']
        for obj in member['declared_objects']:
            if obj['role']!=0:continue
            at=0
            while at<obj['upper_bound_bytes']:
                header=struct.unpack_from('<I',data,obj['offset']+at)[0];extent=4<<(header>>24)
                if header&0xffffff==0x132:authored.append(dict(member=member['name'],member_sha256=member['sha256'],block=obj['table_index'],offset=at,header=header,payload=struct.unpack_from('<I',data,obj['offset']+at+4)[0]))
                at+=extent
    assert len(authored)==1 and authored[0]['payload']==181
    (out/'authored_command.hpp').write_text('inline constexpr unsigned authored_header='+str(authored[0]['header'])+'u,authored_payload='+str(authored[0]['payload'])+'u;\n')
    actual={name for name,_ in entries.values()};joined='\n'.join(text for _,text in entries.values())
    called=set(re.findall(r'\b((?:sub|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(',joined));ports=called-actual
    runtime_calls={int(at,16)for at in re.findall(r'lookupFunction\((0x[0-9A-Fa-f]+)',joined)}
    port_addresses={int(n.split('_')[-1],16)for n in ports}|(runtime_calls-set(entries))
    assert port_addresses=={0x10a830,0x1aa3e0,0x1cc8f0},sorted(map(hex,port_addresses))
    decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual))
    decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){c->pc='+name.split('_')[-1]+';original_transform_port(m,c,r);}\n'for name in sorted(ports))
    (out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text('#include "reference.hpp"\n#include "functions.h"\n'+joined)
    (out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+name+'(memory,context,runtime);return;\n'for at,(name,_)in entries.items()))
    reference=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';conversion=ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h';sources.extend([reference,conversion])
    header=reference.read_text().replace('Register r[32];','std::uint64_t lo{},hi{};Register r[32];')
    header+='\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define SRA32(v,n) (std::int32_t(v)>>(n))\n#define PS2_PCPYLD(a,b) _mm_unpacklo_epi64((b),(a))\n#define PS2_PAND(a,b) _mm_and_si128((a),(b))\n#define PS2_PNOR(a,b) _mm_xor_si128(_mm_or_si128((a),(b)),_mm_set1_epi32(-1))\n#define PS2_PSUBB(a,b) _mm_sub_epi8((a),(b))\n#define PS2_PSUBW(a,b) _mm_sub_epi32((a),(b))\n#include "ps2_fpu_convert.h"\n#define FPU_CVT_W_S(v) Ps2FpuConvertWord(v)\n'
    (out/'reference.hpp').write_text(header);(out/'ps2_fpu_convert.h').write_bytes(conversion.read_bytes())
    system_table=main_read(0x2352f0,64*4);system_pointers=struct.unpack('<64I',system_table)
    assert all(system_pointers[:-1])and system_pointers[-1]==0
    system_messages=[main_read(pointer,1024).split(b'\0')[0]+b'\0'for pointer in system_pointers[:-1]]
    constant_ranges=[(0x256738,main_read(0x256738,0x60)),(0x2352f0,system_table),(0x709880,readers['o2'](0x709880,20))]+list(zip(system_pointers[:-1],system_messages))
    (out/'owned_constants.hpp').write_text('inline void owned_constants(std::uint8_t* p){'+''.join('{const std::uint8_t data[]{'+','.join(map(str,data))+'};std::memcpy(p+'+hex(at)+',data,sizeof data);}'for at,data in constant_ranges)+'}\n')
    fixture=HERE/'timed_scene_text_tests.cpp';sources.append(fixture)
    input_paths={p.relative_to(ROOT).as_posix():p for p in sources}
    if snapshot:
        for n,d in manifest['source_sha256'].items():
            path=snapshot/'source'/n;assert sha(path)==d;input_paths[n]=path
        libraries=sorted(manifest['archives_sha256'])
    else:
        native,libraries=dependency_sources(build);input_paths.update({p.relative_to(ROOT).as_posix():p for p in native})
    before={n:sha(path)for n,path in input_paths.items()};archives={n:sha(build/n)for n in libraries}
    if snapshot:assert archives==manifest['archives_sha256']
    cohort_sha=None
    if not a.prepare_only:
        assert a.build_receipt;cohort=json.loads(a.build_receipt.read_text());assert cohort['status']=='passed'and cohort['compiler_sha256']==sha(cc)
        current={p.relative_to(ROOT).as_posix():sha(p)for p in(ROOT/'game/native').rglob('*')if p.is_file()and p.suffix in('.cpp','.hpp','.h','.inc','.txt')}
        if not snapshot:assert current==cohort['sources_sha256']
        assert all(cohort['archives_sha256'].get(n)==d for n,d in archives.items());cohort_sha=sha(a.build_receipt)
    receipt=dict(schema='reo.native.timed_scene_text.v1',status='failed',compiler_sha256=sha(cc),source_sha256=before,native_library_sha256=archives,
        original_inputs={elf.relative_to(ROOT).as_posix():sha(elf),overlay.relative_to(ROOT).as_posix():sha(overlay)},original_owned_bodies=proof,
        cold_text_cache=dict(begin=hex(0x3151c0),end=hex(0x316350),elf_pt_load=cold),authored_records=authored,
        system_messages=[dict(id=i,address=hex(system_pointers[i]),bytes=len(data),sha256=hashlib.sha256(data).hexdigest())for i,data in enumerate(system_messages)],system_table_sha256=hashlib.sha256(system_table).hexdigest(),message_corpus=[{k:v for k,v in row.items()if k!='data'}for row in corpus],original_ports=sorted(map(hex,port_addresses)),immutable_snapshot=str(snapshot.relative_to(ROOT))if snapshot else None,qualification_scope='immutable_cohort_source_header_and_archive_snapshot'if snapshot else'current_archives',commands=[],archives_only=True,game_launched=False,stage4_complete=False,limitations=[
        'Kind0 fixed132 and kind2 system570080 share the actual task/cache owner; kind1 DM requests remain unsupported.',
        'Native archive loading mode1 preserves complete1D4020 read/store semantics; mode0 direct filesystem/defaultcatalog capability refuses before work.',
        'Text cache state is the UI consumer under comparison; glyph/font rendering1B4500 and a presented game frame are not claimed.',
        'Native lifecycle enter/leave replaces guest MAIN task-group bookkeeping; static original producer pins qualify the observable display gates.'])
    env=dict(os.environ,PATH=str(cc.parent)+os.pathsep+os.environ.get('PATH',''))
    def run(label,cmd):
        start=time.monotonic();result=subprocess.run(cmd,env=env,capture_output=True,timeout=240)
        for stream in('stdout','stderr'):(out/(label+'.'+stream+'.txt')).write_bytes(getattr(result,stream))
        receipt['commands'].append(dict(label=label,command=cmd,returncode=result.returncode,seconds=time.monotonic()-start));assert result.returncode==0,label+': '+result.stderr.decode(errors='replace')[-4500:]
        return result.stdout
    try:
        flags=[str(cc),'-std=c++20','-O2','-msse4.1','-fno-fast-math','-ffp-contract=off',*(['-I'+str(snapshot/'source')]if snapshot else[]),'-I'+str(ROOT),'-I'+str(out)]
        run('original',flags+['-w','-c',str(out/'original.cpp'),'-o',str(out/'original.o')]);run('fixture',flags+['-Wall','-Wextra','-Wpedantic','-Werror','-c',str(fixture),'-o',str(out/'fixture.o')])
        if a.prepare_only:receipt['status']='prepared';return
        private=[]
        if a.override_task:
            assert snapshot
            unit=ROOT/'game/native/gameplay_scenario/timed_scene_text.cpp';copied=out/'private_timed_scene_text.cpp';copied.write_bytes(unit.read_bytes());obj=out/'private_timed_scene_text.o'
            run('private-task',flags+['-I'+str(snapshot/'source/game/native/gameplay_scenario'),'-Wall','-Wextra','-Wpedantic','-Werror','-c',str(copied),'-o',str(obj)]);private=[str(obj)]
            receipt.update(archives_only=False,qualification_scope='diagnostic_current_task_override_with_immutable_cohort_dependencies',private_native_override=dict(source=str(unit.relative_to(ROOT)),source_sha256=sha(unit),object_sha256=sha(obj)))
        run('link',[str(cc),*private,str(out/'original.o'),str(out/'fixture.o'),'-Wl,--start-group',*[str(build/n)for n in libraries],'-Wl,--end-group','-lpthread','-o',str(out/'checks.exe')])
        receipt['observed']=json.loads(run('test',[str(out/'checks.exe'),str(out/'message_corpus.bin')]))
        receipt['source_drift']=[n for n,d in before.items()if sha(input_paths[n])!=d];receipt['archive_drift']=[n for n,d in archives.items()if sha(build/n)!=d]
        assert not receipt['source_drift']and not receipt['archive_drift'];receipt.update(status='passed',build_receipt_sha256=cohort_sha,executable_sha256=sha(out/'checks.exe'))
    finally:
        receipt['generated_sha256']={p.name:sha(p)for p in out.iterdir()if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(dict(status=receipt['status'],observed=receipt['observed'])))
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--native-build',type=Path,required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--build-receipt',type=Path);p.add_argument('--prepare-only',action='store_true');p.add_argument('--immutable-snapshot',type=Path);p.add_argument('--override-task',action='store_true');main(p.parse_args())
