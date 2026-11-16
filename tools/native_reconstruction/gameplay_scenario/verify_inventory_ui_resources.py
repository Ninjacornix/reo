"""Current-archive zero63 complete reached inventory resource producer oracle."""
import argparse,hashlib,json,os,re,struct,subprocess,sys,time,shutil
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parent))
from verify_native_session import dependency_sources
from audit_retail_effect_descriptors import compare_source,elf_reader
from verify_scenario_specific_events import body

def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()

def main(a):
    cc=a.compiler.resolve();build=a.native_build.resolve();out=a.output.resolve()
    snapshot=a.immutable_snapshot.resolve()if a.immutable_snapshot else None
    manifest=json.loads((snapshot/'receipt.json').read_text())if snapshot else None
    if snapshot:
        assert manifest['status']=='passed'and sha(snapshot/'cohort.json')==manifest['cohort_sha256']
        build=snapshot/'native-build';a.build_receipt=snapshot/'cohort.json'
    assert sha(cc)=='f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3'
    assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
    elf=ROOT/'game_data/SLUS_207.65';overlay=ROOT/'build-function-index/owned-overlays/o2.bin'
    assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    main_read=elf_reader(elf.read_bytes());raw=overlay.read_bytes();o0path=ROOT/'build-function-index/owned-overlays/o0.bin';o0=o0path.read_bytes();assert sha(o0path)=='bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2';readers={'sub':main_read,'o2':lambda at,n:raw[at-0x570000:at-0x570000+n],'o0':lambda at,n:o0[at-0x370000:at-0x370000+n]}
    entries={};proof=[];sources=[Path(__file__).resolve(),HERE/'verify_scenario_specific_events.py',HERE.parent/'audit_retail_effect_descriptors.py']
    groups=[('o2',(0x604310,0x6ddd70,0x6d82b0,0x6d83c0,0x6d8630,0x6d8120,0x6d8850,0x6db640,0x6db6d0,0x6dbd10,0x6dc8b0)),
            ('o0',(0x377b30,0x377be0)),('sub',(0x107c68,0x1b6fd0,0x1aec80,0x192190,0x1921a0,0x18f340,0x18f470))]
    for group,addresses in groups:
        directory=ROOT/('recomp/config/output'if group=='sub'else'recomp/config/output_ovl/'+group)
        for at in addresses:
            path=next(directory.glob(f'{group}_{at:08X}_*.cpp'));name=f'{group}_{at:08X}_0x{at:x}';value=body(path,name)
            start,end=(int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',path.read_text()).groups())
            proof.append(compare_source('complete zero63 reached resource body',path.relative_to(ROOT).as_posix(),start,end,readers[group]))
            entries[at]=(name,value);sources.append(path)
    inventory_path=ROOT/'build-native-sjuni/gameplay-script-content-llvm-v21/inventory.json';inventory=json.loads(inventory_path.read_text());sources.append(inventory_path)
    asset_path=Path(inventory[0]['archive'])
    sys.path.insert(0,str(ROOT/'tools/assets'));from afs_inspect import read_toc
    sources.append(ROOT/'tools/assets/afs_inspect.py');asset_pins=[];catalogue_pins=[]
    with asset_path.open('rb')as f:
        roots,_,names=read_toc(f,0)
        def root(name):return roots[next(i for i,(n,_)in enumerate(names)if n.lower()==name.lower())]
        base,extent=root('romdata_usa.afs');rows,_,labels=read_toc(f,base);assert len(rows)==1342
        for ordinal,name,key in [(510,'itmsge.dat','SCENE_ITEM_MSG_ITMSGE_DAT'),(511,'spitem.dat','SCENE_ITEM_MSG_SPITEM_DAT'),(514,'cp_back.img','SCENE_ITEM_MSG_CP_BACK_IMG'),(515,'file.img','SCENE_ITEM_MSG_FILE_IMG'),(516,'itemicon.img','SCENE_ITEM_MSG_ITEMICON_IMG')]:
            pointer=struct.unpack('<I',main_read(0x2322c0+4*ordinal,4))[0];encoded=main_read(pointer,128).split(b'\0')[0];decoded=bytes(c^255 for c in encoded).decode('ascii');assert decoded==key,(ordinal,decoded)
            catalogue_pins.append(dict(ordinal=ordinal,pointer=hex(pointer),key=decoded,encoded_sha256=hashlib.sha256(encoded).hexdigest()))
            at,n=rows[ordinal];assert labels[ordinal][0].lower()==name;storage=(n+2047)&~2047;assert at+storage<=extent
            f.seek(base+at);data=f.read(storage);asset_pins.append(dict(key=key,offset=base+at,logical_bytes=n,physical_bytes=storage,sha256=hashlib.sha256(data).hexdigest()))
        for sid in(1,2,28,35,41):
            base,extent=root(f'r{sid:03}.afs');rows,_,_=read_toc(f,base);ho,hn=root(f'r{sid:03}_h.bin');f.seek(ho);h=f.read(hn);first,count=struct.unpack_from('<II',h);assert len(h)==8+16*count
            for stem in('ITMSG','FILE'):
                key=f'{stem}{sid:03}E_DAT';hits=[i for i in range(count)if h[8+16*i:24+16*i].split(b'\0')[0].decode('ascii')==key];assert len(hits)==1
                at,n=rows[first+hits[0]];storage=(n+2047)&~2047;assert at+storage<=extent
                f.seek(base+at);data=f.read(storage);asset_pins.append(dict(scenario=sid,key=key,offset=base+at,logical_bytes=n,physical_bytes=storage,sha256=hashlib.sha256(data).hexdigest()))

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
                if header&0xffffff==0x63 and struct.unpack_from('<I',data,obj['offset']+at+4)[0]==0:
                    authored.append(dict(member=member['name'],member_sha256=member['sha256'],block=obj['table_index'],offset=at,header=header,request_mode=0))
                at+=extent
    assert len(authored)==1 and authored[0]['member']=='r002.evb'and authored[0]['offset']==1928
    (out/'authored_command.hpp').write_text('inline constexpr unsigned authored_header='+str(authored[0]['header'])+'u;\n')
    actual={name for name,_ in entries.values()};joined='\n'.join(text for _,text in entries.values())
    called=set(re.findall(r'\b((?:sub|o[0-9]+)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(',joined));ports=called-actual
    runtime_calls={int(at,16)for at in re.findall(r'lookupFunction\((0x[0-9A-Fa-f]+)',joined)}
    port_addresses={int(n.split('_')[-1],16)for n in ports}|(runtime_calls-set(entries))
    assert port_addresses=={0x10a830,0x19c8e0,0x1aa3e0,0x1cc8f0,0x6d8e30},sorted(map(hex,port_addresses))
    decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual))
    decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){c->pc='+name.split('_')[-1]+';original_transform_port(m,c,r);}\n'for name in sorted(ports))
    (out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text('#include "reference.hpp"\n#include "functions.h"\n'+joined)
    (out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+name+'(memory,context,runtime);return;\n'for at,(name,_)in entries.items()))
    reference=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';conversion=ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h';sources.extend([reference,conversion])
    header=reference.read_text().replace('Register r[32];','std::uint64_t lo{},hi{};Register r[32];')
    header+='\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define SRA32(v,n) (std::int32_t(v)>>(n))\n#define PS2_PCPYLD(a,b) _mm_unpacklo_epi64((b),(a))\n#define PS2_PAND(a,b) _mm_and_si128((a),(b))\n#define PS2_PNOR(a,b) _mm_xor_si128(_mm_or_si128((a),(b)),_mm_set1_epi32(-1))\n#define PS2_PSUBB(a,b) _mm_sub_epi8((a),(b))\n#define PS2_PSUBW(a,b) _mm_sub_epi32((a),(b))\n#include "ps2_fpu_convert.h"\n#define FPU_CVT_W_S(v) Ps2FpuConvertWord(v)\n'
    (out/'reference.hpp').write_text(header);(out/'ps2_fpu_convert.h').write_bytes(conversion.read_bytes())
    constants=[('o2',0x733c80,0x1b0),('o2',0x7427a0,0x210),('o2',0x742e50,4),('sub',0x22fe20,32),('sub',0x241c88,12)]
    (out/'owned_constants.hpp').write_text('inline void owned_constants(std::uint8_t* p){'+''.join('{const std::uint8_t data[]{'+','.join(map(str,readers[group](at,n)))+'};std::memcpy(p+'+str(at)+',data,sizeof data);}'for group,at,n in constants)+'}\n')
    fixture=HERE/'inventory_ui_resources_tests.cpp';sources.append(fixture)
    input_paths={p.relative_to(ROOT).as_posix():p for p in sources}
    if snapshot:
        for name,digest in manifest['source_sha256'].items():
            path=snapshot/'source'/name;assert sha(path)==digest;input_paths[name]=path
        libraries=sorted(manifest['archives_sha256'])
    else:
        native,libraries=dependency_sources(build);input_paths.update({p.relative_to(ROOT).as_posix():p for p in native})
    before={name:sha(path)for name,path in input_paths.items()};archives={n:sha(build/n)for n in libraries}
    if snapshot:assert archives==manifest['archives_sha256']
    cohort_sha=None
    if not a.prepare_only:
        assert a.build_receipt;cohort=json.loads(a.build_receipt.read_text());assert cohort['status']=='passed'and cohort['compiler_sha256']==sha(cc)
        if not snapshot:
            current={name:sha(ROOT/name)for name in cohort['sources_sha256']}
            assert current==cohort['sources_sha256']
        assert all(cohort['archives_sha256'].get(n)==d for n,d in archives.items());cohort_sha=sha(a.build_receipt)
    receipt=dict(schema='reo.native.inventory_ui_resources.v1',status='failed',compiler_sha256=sha(cc),source_sha256=before,native_library_sha256=archives,
        qualification_scope='immutable_cohort_source_header_and_archive_snapshot'if snapshot else'current_shared_archives',immutable_snapshot=str(snapshot.relative_to(ROOT))if snapshot else None,immutable_snapshot_receipt_sha256=sha(snapshot/'receipt.json')if snapshot else None,
        original_inputs={elf.relative_to(ROOT).as_posix():sha(elf),overlay.relative_to(ROOT).as_posix():sha(overlay),o0path.relative_to(ROOT).as_posix():sha(o0path)},original_owned_bodies=proof,
        constant_pins=[dict(group=g,address=hex(at),bytes=n,sha256=hashlib.sha256(readers[g](at,n)).hexdigest())for g,at,n in constants],authored_records=authored,default_catalogue=catalogue_pins,owned_asset_pins=asset_pins,original_ports=sorted(map(hex,port_addresses)),commands=[],archives_only=True,game_launched=False,stage4_complete=False,limitations=[
        'Complete reached zero63 resource producer; active inventory presentation and a presented game frame are not claimed.',
        'Native retained texture identities/content replace legacy GS allocator addresses; original packet encoders execute in the test only.'])
    env=dict(os.environ,PATH=str(cc.parent)+os.pathsep+os.environ.get('PATH',''))
    def run(label,cmd):
        start=time.monotonic();result=subprocess.run(cmd,env=env,capture_output=True,timeout=240)
        for stream in('stdout','stderr'):(out/(label+'.'+stream+'.txt')).write_bytes(getattr(result,stream))
        receipt['commands'].append(dict(label=label,command=cmd,returncode=result.returncode,seconds=time.monotonic()-start));assert result.returncode==0,label+': '+result.stderr.decode(errors='replace')[-4500:]
        return result.stdout
    try:
        flags=[str(cc),'-std=c++20','-O2','-msse4.1','-fno-fast-math','-ffp-contract=off']+(['-I'+str(snapshot/'source')]if snapshot else[])+['-I'+str(ROOT),'-I'+str(out)]
        reused=[]
        if a.objects_from:
            old=a.objects_from.resolve();old_receipt=json.loads((old/'receipt.json').read_text());assert old_receipt['compiler_sha256']==sha(cc)
            for name in ('reference.hpp','ps2_fpu_convert.h','functions.h','original.cpp','original_dispatch.hpp','owned_constants.hpp','authored_command.hpp'):
                assert sha(out/name)==old_receipt['generated_sha256'][name]==sha(old/name),name
            headers={name:d for name,d in before.items()if Path(name).suffix in('.hpp','.h','.inc')}
            fixture_name=fixture.relative_to(ROOT).as_posix()
            fixture_reusable=old_receipt['source_sha256'].get(fixture_name)==sha(fixture)and all(old_receipt['source_sha256'].get(n)==d for n,d in headers.items())
            for label in ('original','fixture'):
                if label=='fixture'and not fixture_reusable:
                    run('fixture',flags+['-Wall','-Wextra','-Wpedantic','-Werror','-c',str(fixture),'-o',str(out/'fixture.o')]);continue
                obj=label+'.o';assert sha(old/obj)==old_receipt['generated_sha256'][obj]
                cmd=old_receipt.get('compilation_flags')or next(row['command']for row in old_receipt['commands']if row['label']==label)
                assert cmd[:6]==flags[:6],(label,cmd[:6],flags[:6])
                shutil.copyfile(old/obj,out/obj);reused.append(dict(object=obj,sha256=sha(out/obj),previous_receipt_sha256=sha(old/'receipt.json')))
        else:
            run('original',flags+['-w','-c',str(out/'original.cpp'),'-o',str(out/'original.o')]);run('fixture',flags+['-Wall','-Wextra','-Wpedantic','-Werror','-c',str(fixture),'-o',str(out/'fixture.o')])
        receipt['reused_objects']=reused;receipt['compilation_flags']=flags[:6]
        if a.prepare_only:receipt['status']='prepared';return
        run('link',[str(cc),str(out/'original.o'),str(out/'fixture.o'),'-Wl,--start-group',*[str(build/n)for n in libraries],'-Wl,--end-group','-lpthread','-o',str(out/'checks.exe')])
        receipt['observed']=json.loads(run('test',[str(out/'checks.exe'),str(asset_path)]))
        receipt['source_drift']=[n for n,d in before.items()if sha(input_paths[n])!=d];receipt['archive_drift']=[n for n,d in archives.items()if sha(build/n)!=d]
        receipt['live_source_drift']=[n for n,d in before.items()if not(ROOT/n).is_file()or sha(ROOT/n)!=d]
        assert not receipt['source_drift']and not receipt['archive_drift'];receipt.update(status='passed',build_receipt_sha256=cohort_sha,executable_sha256=sha(out/'checks.exe'))
    finally:
        receipt['generated_sha256']={p.name:sha(p)for p in out.iterdir()if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(dict(status=receipt['status'],observed=receipt['observed'])))
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--native-build',type=Path,required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--build-receipt',type=Path);p.add_argument('--prepare-only',action='store_true');p.add_argument('--objects-from',type=Path);p.add_argument('--immutable-snapshot',type=Path);main(p.parse_args())
