"""Archive-only complete5D6A60/5D6ED0 paired-node animation comparison."""
import argparse,hashlib,json,os,re,struct,subprocess,sys,time
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parent));sys.path.insert(0,str(HERE.parent/'gameplay_scenario'))
from verify_native_session import dependency_sources
from audit_retail_effect_descriptors import compare_source,elf_reader
from verify_scenario_specific_events import body
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
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
    raw=overlay.read_bytes();read=lambda at,n:raw[at-0x570000:at-0x570000+n]
    entries={};proof=[];sources=[Path(__file__).resolve(),HERE/'behavior_attachments_tests.cpp',HERE.parent/'audit_retail_effect_descriptors.py',HERE.parent/'gameplay_scenario/verify_scenario_specific_events.py']
    for at in (0x5d6a60,0x5d6ed0,0x66b500,0x66a730,0x66a750,0x5eec50,0x67bc90):
        path=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*.cpp'))
        begin,end=(int(x,16)for x in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',path.read_text()).groups())
        proof.append(compare_source('complete paired-node body'if at in(0x5d6a60,0x5d6ed0)else'static actual behavior/initializer/shared cinematic C50 producer',path.relative_to(ROOT).as_posix(),begin,end,read));sources.append(path)
        if at in(0x5d6a60,0x5d6ed0):entries[at]=(path.stem,body(path,path.stem))
    joined='\n'.join(text for _,text in entries.values());actual={name for name,_ in entries.values()}
    called=set(re.findall(r'\b((?:sub|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(',joined));assert not called-actual
    assert not re.findall(r'lookupFunction\(',joined)
    (out/'functions.h').write_text('#pragma once\n'+''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual)))
    (out/'original.cpp').write_text('#include "reference.hpp"\n#include "functions.h"\n'+joined)
    (out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+name+'(memory,context,runtime);return;\n'for at,(name,_)in entries.items()))
    ref=HERE.parent/'gameplay_world_oracle/transform_reference.hpp';conversion=ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h';sources.extend([ref,conversion])
    (out/'reference.hpp').write_text(ref.read_text()+'\n#include "ps2_fpu_convert.h"\n#define FPU_CVT_W_S(v) Ps2FpuConvertWord(v)\n#define FPU_C_EQ_S(a,b) ((a)==(b))\n')
    (out/'ps2_fpu_convert.h').write_bytes(conversion.read_bytes())
    constants=[(at,read(at,40))for at in(0x70b010,0x70b040)]
    (out/'owned_constants.hpp').write_text('inline void owned_constants(std::uint8_t* p){'+''.join('{const std::uint8_t b[]{'+','.join(map(str,data))+'};std::memcpy(p+'+hex(at)+',b,sizeof b);}'for at,data in constants)+'}\n')
    inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json';assert sha(inventory)=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2';sources.append(inventory);members={r['member']:r for r in json.loads(inventory.read_bytes())};assets=[];skeletons=[]
    with(ROOT/'iso/Resident Evil - Outbreak (v2.00).iso').open('rb')as stream:
        for index in(507,490):
            row=members[f'NETBIO00.DAT/0/{index}'];stream.seek(row['iso_offset']);data=stream.read(row['bytes']);assert hashlib.sha256(data).hexdigest()==row['sha256'];at,size=struct.unpack_from('<II',data,0x24);assert at and size and size<=len(data)-at;skeletons.append(data[at:at+size]);assets.append(row)
    (out/'owned_skeletons.bin').write_bytes(struct.pack('<I',2)+b''.join(struct.pack('<I',len(b))+b for b in skeletons))
    input_paths={p.relative_to(ROOT).as_posix():p for p in sources}
    if snapshot:
        for n,d in manifest['source_sha256'].items():
            path=snapshot/'source'/n;assert sha(path)==d;input_paths[n]=path
        libraries=sorted(manifest['archives_sha256'])
    else:
        native,libraries=dependency_sources(build);input_paths.update({p.relative_to(ROOT).as_posix():p for p in native})
    before={n:sha(path)for n,path in input_paths.items()};archives={n:sha(build/n)for n in libraries}
    if snapshot:assert archives==manifest['archives_sha256'];cohort_sha=None
    if not a.prepare_only:
        assert a.build_receipt;cohort=json.loads(a.build_receipt.read_text());assert cohort['status']=='passed'and cohort['compiler_sha256']==sha(cc)
        current={p.relative_to(ROOT).as_posix():sha(p)for p in(ROOT/'game/native').rglob('*')if p.is_file()and p.suffix in('.cpp','.hpp','.h','.inc','.txt')}
        if not snapshot:assert current==cohort['sources_sha256']
        assert all(cohort['archives_sha256'].get(n)==d for n,d in archives.items());cohort_sha=sha(a.build_receipt)
    receipt=dict(schema='reo.native.behavior_attachments.v1',status='failed',compiler_sha256=sha(cc),source_sha256=before,native_library_sha256=archives,original_owned_bodies=proof,original_inputs={elf.relative_to(ROOT).as_posix():sha(elf),overlay.relative_to(ROOT).as_posix():sha(overlay)},owned_assets=assets,owned_constants=[dict(address=hex(at),bytes=len(data),sha256=hashlib.sha256(data).hexdigest())for at,data in constants],original_ports=[],immutable_snapshot=str(snapshot.relative_to(ROOT))if snapshot else None,qualification_scope='immutable_cohort_source_header_and_archive_snapshot'if snapshot else'current_archives',commands=[],archives_only=True,game_run=False,stage4_complete=False,limitations=['Finite FP32 step values with the source integer conversion in range; actual behavior caller step1 is covered.','Invalid initial table phase outside0..2 refuses; actual full-clear and reachable update cycle keep the phase in0..2.','Local matrices, part visibility and retained immutable snapshots are compared; a rendered game frame is not claimed.'])
    env=dict(os.environ,PATH=str(cc.parent)+os.pathsep+os.environ.get('PATH',''))
    def run(label,cmd):
        start=time.monotonic();result=subprocess.run(cmd,env=env,capture_output=True,timeout=240)
        for stream in('stdout','stderr'):(out/(label+'.'+stream+'.txt')).write_bytes(getattr(result,stream))
        receipt['commands'].append(dict(label=label,command=cmd,returncode=result.returncode,seconds=time.monotonic()-start));assert result.returncode==0,label+': '+result.stderr.decode(errors='replace')[-4500:]
        return result.stdout
    try:
        flags=[str(cc),'-std=c++20','-O2','-msse4.1','-fno-fast-math','-ffp-contract=off',*(['-I'+str(snapshot/'source')]if snapshot else[]),'-I'+str(ROOT),'-I'+str(out)]
        run('original',flags+['-w','-c',str(out/'original.cpp'),'-o',str(out/'original.o')]);run('fixture',flags+['-Wall','-Wextra','-Wpedantic','-Werror','-c',str(HERE/'behavior_attachments_tests.cpp'),'-o',str(out/'fixture.o')])
        if a.prepare_only:receipt['status']='prepared';return
        run('link',[str(cc),str(out/'original.o'),str(out/'fixture.o'),'-Wl,--start-group',*[str(build/n)for n in libraries],'-Wl,--end-group','-lpthread','-o',str(out/'checks.exe')])
        receipt['observed']=json.loads(run('test',[str(out/'checks.exe'),str(out/'owned_skeletons.bin')]))
        receipt['source_drift']=[n for n,d in before.items()if sha(input_paths[n])!=d];receipt['archive_drift']=[n for n,d in archives.items()if sha(build/n)!=d];assert not receipt['source_drift']and not receipt['archive_drift'];receipt.update(status='passed',build_receipt_sha256=cohort_sha,executable_sha256=sha(out/'checks.exe'))
    finally:
        receipt['generated_sha256']={p.name:sha(p)for p in out.iterdir()if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(dict(status=receipt['status'],observed=receipt['observed'])))
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--native-build',type=Path,required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--build-receipt',type=Path);p.add_argument('--prepare-only',action='store_true');p.add_argument('--immutable-snapshot',type=Path);main(p.parse_args())
