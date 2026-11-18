#!/usr/bin/env python3
"""Detect lost construction and thread ownership in the canonical reset guard."""
import argparse,hashlib,json,os,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2];HERE=ROOT/'game/native/adxt_control_owner'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser(description=__doc__)
    for name in ('compiler','manifest','native-receipt','output'):p.add_argument('--'+name,type=Path,required=True)
    a=p.parse_args();out=a.output.resolve();native=json.loads(a.native_receipt.read_bytes());manifest=json.loads(a.manifest.read_bytes())
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/adxt-quiescent-reset'):raise ValueError('Fresh owned output required')
    if native['status']!='native media pipeline standalone build and tests passed' or native['compiler_sha256']!=sha(a.compiler) or native['manifest_sha256']!=sha(a.manifest):raise ValueError('Matching complete native cohort required')
    inputs={n:d for n,d in manifest['files'].items() if n.startswith('game/native/')}
    inputs[Path(__file__).relative_to(ROOT).as_posix()]=sha(Path(__file__))
    def verify():
        for n,d in {**inputs,**native['libraries']}.items():
            if sha(ROOT/n)!=d:raise ValueError('Source/archive drift '+n)
    verify();out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    record=dict(status='failed',sources=inputs,compiler_sha256=sha(a.compiler),manifest_sha256=sha(a.manifest),native_receipt_sha256=sha(a.native_receipt),game_run=False,device_opened=False,checks=[])
    def run(label,command,negative=False):
        result=subprocess.run(list(map(str,command)),env=env,text=True,capture_output=True,timeout=90);(out/(label+'.txt')).write_text(result.stdout+result.stderr,encoding='utf-8',newline='\n');record['checks'].append(dict(label=label,exit=result.returncode,negative=negative))
        if (result.returncode==0)==negative:raise ValueError(label+' unexpected result; see retained log')
        print(label+': '+('fault detected' if negative else 'passed'),flush=True)
    flags=[a.compiler,'-std=c++20','-O2','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off','-I'+str(HERE)]
    libraries=['-Wl,--start-group',*[ROOT/n for n in native['libraries']],'-Wl,--end-group']
    try:
        body=(HERE/'owner.cpp').read_text();faults={
            'ignore-constructed-instance':('state.instances || ',''),
            'ignore-proof-thread':('inside_control && empty_proof==this && render && render==render_','render && render==render_')}
        mutations={}
        for name,(anchor,replacement) in faults.items():
            if body.count(anchor)!=1:raise ValueError('Unique mutation anchor required '+name)
            path=out/(name+'.cpp');path.write_text(body.replace(anchor,replacement),encoding='utf-8',newline='\n');binary=out/(name+'.exe')
            run(name+'-compile',flags+[path,HERE/'owner_tests.cpp',*libraries,'-o',binary]);run(name,[binary],True);mutations[name]=sha(path)
        verify();record.update(status='canonical quiescent reset ownership faults detected',detected_faults=list(faults),fault_sources_sha256=mutations)
    finally:
        record['outputs_sha256']={p.name:sha(p) for p in out.iterdir() if p.suffix=='.txt'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=record['status'],receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
