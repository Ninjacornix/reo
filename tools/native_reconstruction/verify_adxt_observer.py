#!/usr/bin/env python3
"""Qualify transparent original-call observation with declared runtime ports."""
import argparse,hashlib,json,os,re,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2];HERE=ROOT/'recomp/overrides/native_adxt'
sys.path.insert(0,str(ROOT/'tools/function_index'));from index import Elf
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists()or not out.is_relative_to(ROOT/'build-native-sjuni/adxt-binding'):raise ValueError('Fresh owned output required')
    elf_path=ROOT/'game_data/SLUS_207.65';elf=Elf(elf_path)
    if elf.sha256!='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46':raise ValueError('Owned File1 ELF required')
    entry_text=(HERE/'observer_entries.inc').read_text();entries=re.findall(r'X\((0x[0-9a-f]+),(\w+),(true|false)\)',entry_text)
    registered=(ROOT/'recomp/config/output/register_functions.cpp').read_text();original={}
    for at,name,_ in entries:
        if f'runtime.registerFunction({at}, {name});'not in registered:raise ValueError('Registration mismatch '+at)
        source=ROOT/'recomp/config/output'/(name+'.cpp');original[source.relative_to(ROOT).as_posix()]=sha(source)
        for pc,word in re.findall(r'//\s*0x([0-9a-fA-F]+):\s*0x([0-9a-fA-F]+)',source.read_text()):
            if int.from_bytes(elf.read(int(pc,16),4),'little')!=int(word,16):raise ValueError('Original word mismatch '+pc)
    files=[HERE/'runtime_observer.cpp',HERE/'runtime_observer.h',HERE/'handle_profile.h',HERE/'observer_entries.inc',*sorted((HERE/'observer_tests').glob('*')),Path(__file__)]
    sources={p.relative_to(ROOT).as_posix():sha(p)for p in files if p.is_file()};out.mkdir(parents=True)
    env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    record=dict(schema=1,status='failed',compiler_sha256=sha(a.compiler),elf_sha256=elf.sha256,authored_sha256=sources,original_source_sha256=original,registered_entries=len(entries),checks=[],detected_faults=[],actual_guest_bodies_executed=False,actual_runtime=False,game_run=False,device_opened=False)
    flags=[a.compiler,'-std=c++20','-O2','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off','-DNOMINMAX','-DWIN32_LEAN_AND_MEAN','-I'+str(HERE/'observer_tests'),'-I'+str(ROOT),'-I'+str(HERE)]
    def run(label,cmd,negative=False):
        v=subprocess.run(list(map(str,cmd)),env=env,capture_output=True,text=True,timeout=150);(out/(label+'.txt')).write_text(v.stdout+v.stderr,encoding='utf-8',newline='\n');record['checks'].append(dict(label=label,exit=v.returncode,negative=negative))
        if (v.returncode==0)==negative:raise ValueError('Unexpected result '+label)
        print(label+': '+('fault detected'if negative else'passed'),flush=True)
    def rows(path):
        values=[json.loads(line)for line in path.read_text().splitlines()]
        if values[-1]!={'capture_closed':True,'export_complete':True}:raise ValueError('No complete export fence')
        return values
    try:
        binary=out/'observer.exe';run('compile',flags+[HERE/'runtime_observer.cpp',HERE/'observer_tests/tests.cpp','-o',binary])
        for case in ('admission','transparent','blocked','overflow'):
            folder=out/case;folder.mkdir();run(case,[binary,elf_path,folder,case])
        data=rows(out/'transparent/transparent.jsonl');events=[r for r in data if 'stage'in r];counts={r['entry']:r['calls']for r in data if 'calls'in r}
        if len(counts)!=len(entries)or counts[0x1328b8]!=1 or counts[0x131ef8]!=2:raise ValueError('Call/depth/nested observations differ')
        constructors=[r for r in events if r['entry']==0x1315e0 and r['stage']==1]
        if len(constructors)!=1 or constructors[0]['handle']!=0x20f3c8 or constructors[0]['args'][0]!=1 or constructors[0]['handle_status']!=0:raise ValueError('Constructor return/profile observation differs')
        if not any(r['entry']==0x133490 and r['stage']==1 and r['pc']==0x1334ec for r in events):raise ValueError('Yield PC not observed')
        overflow=rows(out/'overflow/overflow.jsonl')
        if overflow[0]['events']!=65536 or overflow[0]['dropped']!=14464:raise ValueError('Bounded drop accounting differs')
        blocked=rows(out/'blocked/blocked.jsonl')
        record.update(events=len(events),original_call_ram_context_comparisons=len(entries),blocked_export_complete=bool(blocked),overflow_dropped=overflow[0]['dropped'])
        body=(HERE/'runtime_observer.cpp').read_text();anchor='    Original(ram,context,runtime);'
        if body.count(anchor)!=1:raise ValueError('Delegation fault anchor')
        changed=out/'drop_original.cpp';changed.write_text(body.replace(anchor,'    context->pc=GPR_U32(context,31);'),encoding='utf-8',newline='\n')
        fault=out/'drop_original.exe';run('fault-compile',flags+[changed,HERE/'observer_tests/tests.cpp','-o',fault]);folder=out/'fault';folder.mkdir();run('drop-original-call',[fault,elf_path,folder,'transparent'],True);record['detected_faults'].append('drop-original-call')
        for n,d in {**sources,**original}.items():
            if sha(ROOT/n)!=d:raise ValueError('Source drift '+n)
        record.update(status='bounded original-call ADXT observer qualified with declared ports',binary_sha256=sha(binary))
    finally:
        record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()and p.suffix in ('.txt','.jsonl','.exe')};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps({'status':record['status'],'receipt_sha256':sha(out/'receipt.json')}))
if __name__=='__main__':main()
