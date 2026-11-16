"""Current-archive complete offline actor policy, retirement and condition oracle."""
import argparse,hashlib,json,os,re,struct,subprocess,sys,time,shutil
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parent))
from verify_native_session import dependency_sources
from audit_retail_effect_descriptors import compare_source,elf_reader
from verify_scenario_specific_events import body

def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()

def main(a):
    cc=a.compiler.resolve();build=a.native_build.resolve();out=a.output.resolve();snapshot=None;snapshot_manifest=None
    if a.immutable_snapshot:
        snapshot=a.immutable_snapshot.resolve();snapshot_manifest=json.loads((snapshot/'receipt.json').read_text());assert snapshot_manifest['status']=='passed';build=snapshot/'native-build'
        assert sha(snapshot/'cohort.json')==snapshot_manifest['cohort_sha256']
        a.build_receipt=snapshot/'cohort.json'
    assert sha(cc)=='f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3'
    assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
    elf=ROOT/'game_data/SLUS_207.65';overlay=ROOT/'build-function-index/owned-overlays/o2.bin'
    assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    main_read=elf_reader(elf.read_bytes());raw=overlay.read_bytes();o0path=ROOT/'build-function-index/owned-overlays/o0.bin';o0=o0path.read_bytes();assert sha(o0path)=='bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2'
    o9path=ROOT/'build-function-index/owned-overlays/o9.bin';o9=o9path.read_bytes();assert sha(o9path)=='604126d6edca1b1333948d79d1d2c8d2f2e22f4a233efbdfb769c106dafe7343'
    readers={'sub':main_read,'o2':lambda at,n:raw[at-0x570000:at-0x570000+n],'o0':lambda at,n:o0[at-0x370000:at-0x370000+n],'o9':lambda at,n:o9[at-0x810000:at-0x810000+n]}
    entries={};proof=[];sources=[Path(__file__).resolve(),HERE/'verify_scenario_specific_events.py',HERE.parent/'audit_retail_effect_descriptors.py']
    seeds={0x702ad0,0x702bc0,0x702ce0,0x702d70,0x702f90,0x813380,0x81a6e0,0x81a6f0,0x817170,0x817100,0x191d10,0x68c9e0,0x68c990,0x5f6800,0x5b5f10,0x5b4320,0x5b43f0}
    allowed_main={0x107c68}
    def allowed(at):return at in seeds or at in allowed_main
    pending=list(seeds)
    while pending:
        at=pending.pop()
        if at in entries:continue
        group='sub'if at<0x300000 else'o0'if at<0x570000 else'o2'if at<0x810000 else'o9'
        directory=ROOT/('recomp/config/output'if group=='sub'else'recomp/config/output_ovl/'+group)
        path=next(directory.glob(f'{group}_{at:08X}_*.cpp'));name=f'{group}_{at:08X}_0x{at:x}';value=body(path,name)
        start,end=(int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',path.read_text()).groups())
        proof.append(compare_source('complete offline actor policy, resource and condition dependency body',path.relative_to(ROOT).as_posix(),start,end,readers[group]))
        entries[at]=(name,value);sources.append(path)
        called={int(v,16)for v in re.findall(r'lookupFunction\((0x[0-9A-Fa-f]+)',value)}
        called|={int(v,16)for v in re.findall(r'\b(?:sub|o[0-9]+)_[0-9A-Fa-f]+_0x([0-9a-f]+)\(',value)}
        pending.extend(x for x in called if allowed(x)and x not in entries)
    inventory_path=ROOT/'build-native-sjuni/gameplay-script-content-llvm-v21/inventory.json';inventory=json.loads(inventory_path.read_text());sources.append(inventory_path)
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
                if header&0xffffff in(0x1a6,0x1a7,0x1a9,0x1aa,0x1ac):authored.append(dict(member=member['name'],member_sha256=member['sha256'],block=obj['table_index'],offset=at,header=header,payload=(header&0xffffff,*(struct.unpack_from('<I',data,obj['offset']+at+4+4*i)[0]if extent>=8+4*i else 0 for i in range(3)))))
                at+=extent
    assert len(authored)==20
    (out/'authored_command.hpp').write_text('inline constexpr std::array<std::array<unsigned,4>,20> authored_commands{{'+','.join('{'+','.join(str(v)+'u'for v in r['payload'])+'}'for r in authored)+'}};\n')
    actual={name for name,_ in entries.values()};joined='\n'.join(text for _,text in entries.values())
    called=set(re.findall(r'\b((?:sub|o[0-9]+)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(',joined));ports=called-actual
    runtime_calls={int(at,16)for at in re.findall(r'lookupFunction\((0x[0-9A-Fa-f]+)',joined)}
    port_addresses={int(n.split('_')[-1],16)for n in ports}|(runtime_calls-set(entries))
    assert port_addresses=={0x5b1a90},sorted(map(hex,port_addresses))
    decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual))
    decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){c->pc='+name.split('_')[-1]+';original_transform_port(m,c,r);}\n'for name in sorted(ports))
    (out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text('#include "reference.hpp"\n#include "functions.h"\n'+joined)
    (out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+name+'(memory,context,runtime);return;\n'for at,(name,_)in entries.items()))
    reference=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';conversion=ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h';sources.extend([reference,conversion])
    header=reference.read_text().replace('Register r[32];','std::uint64_t lo{},hi{};Register r[32];')
    header+='\n#define FPU_C_EQ_S(a,b) ((a)==(b))\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define SRA32(v,n) (std::int32_t(v)>>(n))\n#define PS2_PCPYLD(a,b) _mm_unpacklo_epi64((b),(a))\n#define PS2_PAND(a,b) _mm_and_si128((a),(b))\n#define PS2_PNOR(a,b) _mm_xor_si128(_mm_or_si128((a),(b)),_mm_set1_epi32(-1))\n#define PS2_PSUBB(a,b) _mm_sub_epi8((a),(b))\n#define PS2_PSUBW(a,b) _mm_sub_epi32((a),(b))\n#include "ps2_fpu_convert.h"\n#define FPU_CVT_W_S(v) Ps2FpuConvertWord(v)\n'
    (out/'reference.hpp').write_text(header);(out/'ps2_fpu_convert.h').write_bytes(conversion.read_bytes())
    constants=[];elfbytes=elf.read_bytes();phoff=struct.unpack_from('<I',elfbytes,28)[0];stride,count=struct.unpack_from('<HH',elfbytes,42)
    for i in range(count):
        kind,offset,address,_,size,_,_,_=struct.unpack_from('<8I',elfbytes,phoff+i*stride)
        if kind==1 and size:constants.append((address,elfbytes[offset:offset+size]))
    constants.append((0x717600,readers['o2'](0x717600,132))) #32 opener words + originalFFFFFFFF terminator
    (out/'constants.bin').write_bytes(b''.join(struct.pack('<II',at,len(value))+value for at,value in constants))
    fixture=HERE/'offline_actor_controls_tests.cpp';sources.append(fixture)
    input_paths={p.relative_to(ROOT).as_posix():p for p in sources}
    if snapshot:
        for n,d in snapshot_manifest['source_sha256'].items():
            path=snapshot/'source'/n;assert sha(path)==d;input_paths[n]=path
        libraries=sorted(snapshot_manifest['archives_sha256'])
    else:
        native,libraries=dependency_sources(build);input_paths.update({p.relative_to(ROOT).as_posix():p for p in native})
    before={n:sha(path)for n,path in input_paths.items()};archives={n:sha(build/n)for n in libraries}
    if snapshot:assert archives==snapshot_manifest['archives_sha256']

    cohort_sha=None;nonimpact_drift={};impact={};cohort_failures=[];archived_headers={};critical={n:d for n,d in before.items()if not n.startswith('game/native/')or(Path(n).suffix in('.cpp','.hpp','.h','.inc')and not re.search(r'(?:^|_)tests?(?:[._]|$)',Path(n).name))}
    if not a.prepare_only:
        assert a.build_receipt;cohort=json.loads(a.build_receipt.read_text());assert cohort['compiler_sha256']==sha(cc)
        cohort_failures=[row['label']for row in cohort.get('commands',[])if row['returncode']]
        if cohort['status']!='passed':
            assert set(cohort_failures)==set(a.allow_failed_test)and cohort_failures
            assert cohort['build']['returncode']==0 and not cohort['source_drift']and not cohort['archive_drift']
            assert all(row['returncode']==0 for row in cohort['commands']if row['label']in('focused-ctest','native-session-owned'))
        if a.archived_cohort:
            assert a.objects_from
            old_receipt=json.loads((a.objects_from/'receipt.json').read_text())
            archived_headers={n:d for n,d in old_receipt['source_sha256'].items()if Path(n).suffix in('.hpp','.h','.inc')and not re.search(r'(?:^|_)tests?(?:[._]|$)',Path(n).name)}
            assert all(cohort['sources_sha256'].get(n)==d for n,d in archived_headers.items()if n.startswith('game/native/')or n in cohort['sources_sha256'])

        current={p.relative_to(ROOT).as_posix():sha(p)for p in(ROOT/'game/native').rglob('*')if p.is_file()and p.suffix in('.cpp','.hpp','.h','.inc','.txt')}
        for name in cohort['sources_sha256']:
            if name not in current and (ROOT/name).exists():current[name]=sha(ROOT/name)
        drift={n:dict(cohort=cohort['sources_sha256'].get(n),current=current.get(n))for n in set(current)|set(cohort['sources_sha256'])if current.get(n)!=cohort['sources_sha256'].get(n)}
        impact={n:v for n,v in drift.items()if n in critical}
        if not a.archived_cohort and not snapshot:assert not impact,impact
        nonimpact_drift={n:v for n,v in drift.items()if n not in impact}
        assert all(cohort['archives_sha256'].get(n)==d for n,d in archives.items());cohort_sha=sha(a.build_receipt)
    receipt=dict(schema='reo.native.offline_actor_controls.v1',status='failed',compiler_sha256=sha(cc),source_sha256=before,source_sha256_scope='current tree observation; archived_fixture_header_sha256 records actual precompiled fixture headers when archive mode is selected',native_library_sha256=archives,
        original_inputs={elf.relative_to(ROOT).as_posix():sha(elf),overlay.relative_to(ROOT).as_posix():sha(overlay),o0path.relative_to(ROOT).as_posix():sha(o0path),o9path.relative_to(ROOT).as_posix():sha(o9path)},original_owned_bodies=proof,
        constant_pins=[dict(address=hex(at),bytes=len(value),sha256=hashlib.sha256(value).hexdigest())for at,value in constants],authored_records=authored,
        original_ports=sorted(map(hex,port_addresses)),qualification_scope='immutable_cohort_source_header_and_archive_snapshot'if snapshot else'archived_cohort_with_exact_precompiled_fixture_headers'if a.archived_cohort else'archive_cohort_with_verified_linked_production_and_fixture_dependencies',immutable_snapshot=str(snapshot.relative_to(ROOT))if snapshot else None,immutable_snapshot_receipt_sha256=sha(snapshot/'receipt.json')if snapshot else None,cohort_status=cohort['status']if not a.prepare_only else None,cohort_failed_tests=cohort_failures,archived_fixture_header_sha256=archived_headers,current_dependency_drift=impact,nonimpact_current_tree_drift=nonimpact_drift,commands=[],archives_only=True,game_launched=False,stage4_complete=False,limitations=[
        'Complete1A6/1A7/1A9/1AA/1AC handlers and actual interpreter scanner/resource consumers; other offline families remain explicit unsupported.',
        'Native10A0 retains the low halfword used by its sole812540 consumer; unused high-half guest bookkeeping has no separate native field.',
        'Selected-resource release5B1A90 is an explicit unreached boundary: this bounded resource comparison fixes selected_resource=0; existing resource owners and application tests retain real release readiness.'])
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
            for name in ('reference.hpp','ps2_fpu_convert.h','functions.h','original.cpp','original_dispatch.hpp','authored_command.hpp'):
                assert sha(out/name)==old_receipt['generated_sha256'][name]==sha(old/name),name
            headers={name:d for name,d in before.items()if Path(name).suffix in('.hpp','.h','.inc')and name in critical}
            fixture_name=fixture.relative_to(ROOT).as_posix()
            fixture_reusable=old_receipt['source_sha256'].get(fixture_name)==sha(fixture)and(a.archived_cohort or all(old_receipt['source_sha256'].get(n)==d for n,d in headers.items()))
            if a.archived_cohort:assert fixture_reusable
            for label in ('original','fixture'):
                if label=='fixture'and not fixture_reusable:
                    run('fixture',flags+['-Wall','-Wextra','-Wpedantic','-Werror','-c',str(fixture),'-o',str(out/'fixture.o')]);continue
                obj=label+'.o';assert sha(old/obj)==old_receipt['generated_sha256'][obj]
                if 'compilation_flags' in old_receipt:assert old_receipt['compilation_flags'][:6]==flags[:6]
                else:
                    cmd=next(row['command']for row in old_receipt['commands']if row['label']==label)
                    assert cmd[:6]==flags[:6],(label,cmd[:7],flags[:7])
                shutil.copyfile(old/obj,out/obj);reused.append(dict(object=obj,sha256=sha(out/obj),previous_receipt_sha256=sha(old/'receipt.json')))
        else:
            run('original',flags+['-w','-c',str(out/'original.cpp'),'-o',str(out/'original.o')]);run('fixture',flags+['-Wall','-Wextra','-Wpedantic','-Werror','-c',str(fixture),'-o',str(out/'fixture.o')])
        receipt['reused_objects']=reused;receipt['compilation_flags']=flags[:7]
        if a.prepare_only:receipt['status']='prepared';return
        run('link',[str(cc),str(out/'original.o'),str(out/'fixture.o'),'-Wl,--start-group',*[str(build/n)for n in libraries],'-Wl,--end-group','-lpthread','-o',str(out/'checks.exe')])
        receipt['observed']=json.loads(run('test',[str(out/'checks.exe'),str(out/'constants.bin')]))
        receipt['source_drift']=[n for n,d in critical.items()if(not a.archived_cohort or not n.startswith('game/native/'))and sha(input_paths[n])!=d];receipt['nonimpact_run_drift']=[n for n,d in before.items()if n not in critical and sha(input_paths[n])!=d];receipt['archive_drift']=[n for n,d in archives.items()if sha(build/n)!=d]
        assert not receipt['source_drift']and not receipt['archive_drift'];receipt.update(status='passed',build_receipt_sha256=cohort_sha,executable_sha256=sha(out/'checks.exe'))
    finally:
        receipt['generated_sha256']={p.name:sha(p)for p in out.iterdir()if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(dict(status=receipt['status'],observed=receipt['observed'])))
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--native-build',type=Path,required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--build-receipt',type=Path);p.add_argument('--prepare-only',action='store_true');p.add_argument('--objects-from',type=Path);p.add_argument('--archived-cohort',action='store_true');p.add_argument('--allow-failed-test',action='append',default=[]);p.add_argument('--immutable-snapshot',type=Path);main(p.parse_args())
