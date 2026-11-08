#!/usr/bin/env python3
"""Declared-port ordinary game ABI checks with real native imported sources."""
import argparse,hashlib,json,os,re,struct,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2];HERE=ROOT/'recomp/overrides/native_adxt'
sys.path.insert(0,str(ROOT/'tools/function_index'));from index import Elf
PORTS=ROOT/'build-native-sjuni/audio-media-factory/prepared-llvm-v1'
PORTS_SHA='948c0bf63919cb7a8ba9e6f193ee4a6a49265b86c9410b54208538c380606e8c'
META=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1'
SCENARIOS=('ordinary','phase','image','entry','mount','worker','registry','factory','partial','callback','producer','changed_child','order','foreign','guest_depth','query_alias')
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def write(path,body):path.write_text(body,encoding='utf-8',newline='\n')
def main():
    p=argparse.ArgumentParser(description=__doc__)
    for name in ('compiler','manifest','native-receipt','data','output'):p.add_argument('--'+name,type=Path,required=True)
    a=p.parse_args();out=a.output.resolve();native=json.loads(a.native_receipt.read_bytes());manifest=json.loads(a.manifest.read_bytes())
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/adxt-binding'):raise ValueError('Fresh owned output required')
    if native['status']!='native media pipeline standalone build and tests passed' or native['compiler_sha256']!=sha(a.compiler) or native['manifest_sha256']!=sha(a.manifest):raise ValueError('Matching complete native archive cohort required')
    if sha(PORTS/'receipt.json')!=PORTS_SHA:raise ValueError('Qualified factory surroundings required')
    elf=Elf(ROOT/'game_data/SLUS_207.65')
    if elf.sha256!='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46':raise ValueError('Owned File1 ELF required')
    entries=re.findall(r'X\((0x[0-9a-f]+),(\w+),(\w+)\)',(HERE/'ordinary_entries.inc').read_text())
    registered=(ROOT/'recomp/config/output/register_functions.cpp').read_text();original={}
    for at,name,_ in entries:
        if f'runtime.registerFunction({at}, {name});' not in registered:raise ValueError('Original registry mismatch '+at)
        source=ROOT/'recomp/config/output'/(name+'.cpp');original[source.relative_to(ROOT).as_posix()]=sha(source)
        for pc,word in re.findall(r'//\s*0x([0-9a-fA-F]+):\s*0x([0-9a-fA-F]+)',source.read_text()):
            if int.from_bytes(elf.read(int(pc,16),4),'little')!=int(word,16):raise ValueError('Original word mismatch '+pc)
    inventory=json.loads((META/'receipt.json').read_bytes())
    for n in ('members.json','archives.json'):
        if sha(META/n)!=inventory['output_sha256'][n]:raise ValueError('Independent inventory drift')
    baseline=ROOT/'build-native-sjuni/adx-asset-streams/full-gcc-v1/results.jsonl'
    if sha(baseline)!='43b3876e4855a7b5cce35b448b1e1fa7b1fa707c8ed6be599508b2a6b80a12b9':raise ValueError('Qualified finite baseline required')
    finite={row['member']:row for row in map(json.loads,baseline.read_text().splitlines()) if row['decode_requested']}
    members={row['member']:row for row in json.loads((META/'members.json').read_bytes())}
    root=next(row for row in json.loads((META/'archives.json').read_bytes()) if row['member']=='NETBIO01.DAT')
    plan=[]
    for member in ('NETBIO01.DAT/0/39','NETBIO01.DAT/0/409/0'):
        row=members[member];meta=row['adx'];expected=finite[member];relative=row['iso_offset']-root['iso_offset']
        if relative%2048 or meta['loop'].get('enabled'):raise ValueError('Qualified finite aligned source required')
        plan.append(' '.join(map(str,(relative//2048,(row['bytes']+2047)//2048,meta['channels'],meta['frequency'],meta['total_samples'],*expected['byte_digest']))))
    fixture=HERE/'handle_profile_tests.cpp';proof=json.loads((HERE/'handle_qualification.json').read_bytes())
    if sha(fixture)!=proof['authored_sha256']['handle_profile_tests.cpp']:raise ValueError('Qualified independent handle fixture required')
    inputs={n:d for n,d in manifest['files'].items() if n.startswith('game/native/') or n.startswith('recomp/overrides/native_banks/')}
    paths=[HERE/'ordinary_runtime.cpp',HERE/'ordinary_runtime.h',HERE/'ordinary_entries.inc',HERE/'game_handles.cpp',HERE/'game_handles.h',HERE/'source_profile.cpp',HERE/'source_profile.h',fixture,HERE/'handle_profile.h',Path(__file__),*sorted((HERE/'ordinary_tests').iterdir())]
    inputs.update({p.relative_to(ROOT).as_posix():sha(p) for p in paths if p.is_file()})
    def verify():
        for n,d in {**inputs,**native['libraries'],**original}.items():
            if sha(ROOT/n)!=d:raise ValueError('Source/archive drift '+n)
    verify();data=a.data.resolve();imported=data.parent/'import.json'
    if sha(imported)!='ae3668c7e98defe0eb16ce107490078451e9c2f57cb2fb87c162f37520f2600b':raise ValueError('Actual File1 import required')
    before={row['Name']:(data/row['Name']).stat() for row in json.loads(imported.read_bytes())['Files']}
    out.mkdir(parents=True);write(out/'plan.txt','\n'.join(plan)+'\n')
    segments=((0x12a658,0x308),(0x1315e0,0x373c),(0x12c680,0x30),(0x220498,4000))
    image=struct.pack('<I',len(segments))+b''.join(struct.pack('<II',at,size)+elf.read(at,size) for at,size in segments);(out/'qualified-image.bin').write_bytes(image)
    body=fixture.read_text();anchor='template<class F>void refuse'
    if body.count(anchor)!=1:raise ValueError('Independent fixture extraction anchor')
    write(out/'handle_fixture.hpp','#pragma once\n'+body[:body.index(anchor)])
    (out/'ordinary_runtime_body.cpp').write_bytes((HERE/'ordinary_runtime.cpp').read_bytes())
    env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    record=dict(schema=1,status='failed',sources=inputs,original_source_sha256=original,compiler_sha256=sha(a.compiler),native_receipt_sha256=sha(a.native_receipt),native_manifest_sha256=sha(a.manifest),elf_sha256=elf.sha256,factory_ports_receipt_sha256=PORTS_SHA,inventory_receipt_sha256=sha(META/'receipt.json'),finite_baseline_sha256=sha(baseline),actual_game_bodies_executed=False,actual_runtime_acquisition=False,actual_native_workers=True,actual_immutable_import=True,actual_backend_selection=False,game_run=False,device_opened=False,checks=[])
    def run(label,command,negative=False):
        result=subprocess.run(list(map(str,command)),env=env,capture_output=True,text=True,timeout=100);write(out/(label+'.txt'),result.stdout+result.stderr);record['checks'].append(dict(label=label,exit=result.returncode,negative=negative))
        if (result.returncode==0)==negative:raise ValueError(label+' unexpected result; see retained log')
        print(label+': '+('fault detected' if negative else 'passed'),flush=True)
    try:
        exe=out/'ordinary.exe';flags=[a.compiler,'-std=c++20','-O2','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-misleading-indentation','-fno-fast-math','-ffp-contract=off','-DNOMINMAX','-DWIN32_LEAN_AND_MEAN','-DREO_GAME_FILE1','-DREO_BUILD_NATIVE_RESOURCE_READS=1','-I'+str(HERE/'ordinary_tests'),'-I'+str(out),'-I'+str(HERE),'-I'+str(PORTS/'snapshot'),'-I'+str(ROOT)]
        run('compile',flags+[HERE/'game_handles.cpp',HERE/'source_profile.cpp',HERE/'ordinary_tests/tests.cpp','-Wl,--start-group',*[ROOT/n for n in native['libraries']],'-Wl,--end-group','-lbcrypt','-lole32','-lruntimeobject','-o',exe])
        for case in SCENARIOS:run(case,[exe,out/'qualified-image.bin',data,out/'plan.txt',case])
        body=(HERE/'ordinary_runtime.cpp').read_text();test=(HERE/'ordinary_tests/tests.cpp').read_text();mutations={}
        faults={
            'drop-child-retirement':('if(action==Action::destroy_child){destroy(at);return false;}','if(action==Action::destroy_child){return false;}','ordinary'),
            'fallback-unsupported-producer':('if(action==Action::unsupported)fail("unsupported-producer",address);','if(action==Action::unsupported)return false;','producer'),
            'ignore-child-replacement':('fail("replaced-child-identity",address);','(void)0;','changed_child')}
        faults['omit-native-discard']=(
            'result=p.discard_rebase(key,tick());',
            '(void)p;(void)key;result.status=adxt_control_session::Status::completed;', 'ordinary')
        for name,(anchor,replacement,case) in faults.items():
            if body.count(anchor)!=1:raise ValueError('Unique adapter mutation anchor '+name)
            folder=out/name;folder.mkdir();changed=folder/'ordinary_runtime_body.cpp';write(changed,body.replace(anchor,replacement));fixture=out/(name+'-tests.cpp');write(fixture,test.replace('#include "ordinary_runtime_body.cpp"','#include "'+name+'/ordinary_runtime_body.cpp"'))
            binary=out/(name+'.exe');run(name+'-compile',flags+[HERE/'game_handles.cpp',HERE/'source_profile.cpp',fixture,'-Wl,--start-group',*[ROOT/n for n in native['libraries']],'-Wl,--end-group','-lbcrypt','-lole32','-lruntimeobject','-o',binary]);run(name,[binary,out/'qualified-image.bin',data,out/'plan.txt',case],True);mutations[name]=sha(changed)
        verify();record.update(status='ordinary game ABI declared-port checks passed',scenarios=len(SCENARIOS),binary_sha256=sha(exe),detected_faults=list(faults),fault_source_sha256=mutations)
    except Exception as error:record['failure']=str(error);raise
    finally:
        record['source_stats_unchanged']=all((s.st_size,s.st_mtime_ns,s.st_ino)==((t:=(data/n).stat()).st_size,t.st_mtime_ns,t.st_ino) for n,s in before.items());record['import_manifest_unchanged']=sha(imported)=='ae3668c7e98defe0eb16ce107490078451e9c2f57cb2fb87c162f37520f2600b'
        if not record['source_stats_unchanged'] or not record['import_manifest_unchanged']:record['status']='failed source drift'
        record['output_sha256']={p.name:sha(p) for p in out.iterdir() if p.suffix in ('.txt','.hpp','.bin','.exe')};write(out/'receipt.json',json.dumps(record,indent=2)+'\n')
    print(json.dumps(dict(status=record['status'],receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
