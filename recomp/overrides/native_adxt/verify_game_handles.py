#!/usr/bin/env python3
"""Guest-handle bookkeeping against the canonical native source owner.

Uses declared constructor layouts and actual native workers; no guest hooks,
runtime capability acquisition, audio device or game launch.
"""
import argparse,hashlib,json,os,subprocess
from pathlib import Path
HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--compiler',type=Path,required=True);p.add_argument('--native-receipt',type=Path,required=True);p.add_argument('--manifest',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists()or not out.is_relative_to(ROOT/'build-native-sjuni/adxt-binding'):raise ValueError('Fresh owned output required')
    native=json.loads(a.native_receipt.read_bytes());manifest=json.loads(a.manifest.read_bytes())
    if native['status']!='native media pipeline standalone build and tests passed' or native['manifest_sha256']!=sha(a.manifest) or native['compiler_sha256']!=sha(a.compiler):raise ValueError('Matching complete native source build required')
    authored={p.relative_to(ROOT).as_posix():sha(p)for p in HERE.iterdir()if p.suffix in ('.h','.cpp','.py')}
    def verify():
        for n,d in {**manifest['files'],**authored,**native['libraries']}.items():
            if sha(ROOT/n)!=d:raise ValueError('Input drift '+n)
    verify();out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    record=dict(schema=1,status='failed',manifest_sha256=sha(a.manifest),native_receipt_sha256=sha(a.native_receipt),compiler_sha256=sha(a.compiler),authored=authored,checks=[],detected_faults=[],game_run=False,actual_guest_hooks_installed=False,actual_runtime_acquisition=False,device_opened=False)
    def run(label,source,negative=False):
        exe=out/(label+'.exe');cmd=[a.compiler,'-std=c++20','-O2','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off','-frounding-math','-I'+str(HERE),'-I'+str(ROOT),source,HERE/'game_handles_tests.cpp','-Wl,--start-group',*[ROOT/n for n in native['libraries']],'-Wl,--end-group','-o',exe]
        v=subprocess.run(list(map(str,cmd)),env=env,capture_output=True,text=True,timeout=90);(out/(label+'-compile.txt')).write_text(v.stdout+v.stderr,encoding='utf-8',newline='\n')
        if v.returncode:raise ValueError('Compile failed '+label)
        v=subprocess.run([exe],env=env,capture_output=True,text=True,timeout=45);(out/(label+'.txt')).write_text(v.stdout+v.stderr,encoding='utf-8',newline='\n');record['checks'].append(dict(label=label,exit=v.returncode,negative=negative))
        if (v.returncode==0)==negative:raise ValueError('Unexpected result '+label)
        print(label+': '+('fault detected'if negative else'passed'),flush=True)
    try:
        run('native',HERE/'game_handles.cpp');body=(HERE/'game_handles.cpp').read_text()
        for label,old,new in (
            ('file-slot-is-stream-slot','h.decoder_slot,h.slot,h.rna_slot','h.decoder_slot,h.file_slot,h.rna_slot'),
            ('release-pending-children','if(status==S::completed)release(key.slot_);','if(status==S::completed || status==S::pending)release(key.slot_);'),
            ('ignore-secondary-transfer','a.transfer[i]==b.transfer[j]','(i==0 && j==0 && a.transfer[i]==b.transfer[j])'),
        ):
            if body.count(old)!=1:raise ValueError('Mutation anchor '+label)
            changed=out/(label+'.cpp');changed.write_text(body.replace(old,new),encoding='utf-8',newline='\n');run(label,changed,True);record['detected_faults'].append(label)
        verify();record.update(status='native game handle ownership and source retirement qualified',workflows=3)
    finally:
        record['outputs_sha256']={p.name:sha(p)for p in out.iterdir()if p.suffix in('.txt','.cpp')};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps({'status':record['status'],'receipt_sha256':sha(out/'receipt.json')}))
if __name__=='__main__':main()
