#!/usr/bin/env python3
"""Detect lost control state and destructive admission in canonical ADXT sources."""
import argparse,hashlib,json,os,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--compiler',type=Path,required=True);p.add_argument('--native-receipt',type=Path,required=True);p.add_argument('--manifest',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/adxt-game-control'):raise ValueError('Fresh owned output required')
    native=json.loads(a.native_receipt.read_bytes());manifest=json.loads(a.manifest.read_bytes())
    if native['status']!='native media pipeline standalone build and tests passed' or native['manifest_sha256']!=sha(a.manifest) or native['compiler_sha256']!=sha(a.compiler):raise ValueError('Matching complete native build required')
    def verify():
        for n,d in manifest['files'].items():
            if sha(ROOT/n)!=d:raise ValueError('Source drift '+n)
        for n,d in native['libraries'].items():
            if sha(ROOT/n)!=d:raise ValueError('Archive drift '+n)
    verify();out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    own_hash=sha(Path(__file__));record=dict(status='failed',manifest_sha256=sha(a.manifest),native_receipt_sha256=sha(a.native_receipt),compiler_sha256=sha(a.compiler),verifier_sha256=own_hash,checks=[],detected_faults=[],game_run=False,device_opened=False)
    def run(label,sources,negative=False):
        exe=out/(label+'.exe');cmd=[a.compiler,'-std=c++20','-O2','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off','-frounding-math','-I'+str(ROOT/'game/native/adxt_instances'),'-I'+str(ROOT/'game/native/adxt_control_session'),*sources,'-Wl,--start-group',*[ROOT/n for n in native['libraries']],'-Wl,--end-group','-o',exe]
        v=subprocess.run(list(map(str,cmd)),capture_output=True,text=True,env=env,timeout=90);(out/(label+'-compile.txt')).write_text(v.stdout+v.stderr,encoding='utf-8',newline='\n')
        if v.returncode:raise ValueError('Compile failed '+label)
        v=subprocess.run([str(exe)],capture_output=True,text=True,env=env,timeout=60);(out/(label+'.txt')).write_text(v.stdout+v.stderr,encoding='utf-8',newline='\n');record['checks'].append(dict(label=label,exit=v.returncode,negative=negative))
        if (v.returncode==0)==negative:raise ValueError('Unexpected result '+label)
        print(label+': '+('fault detected' if negative else 'passed'),flush=True)
    instances=ROOT/'game/native/adxt_instances/instances.cpp';session=ROOT/'game/native/adxt_control_session/control_session.cpp'
    tests=ROOT/'game/native/adxt_instances/game_control_tests.cpp'
    try:
        run('native',[tests]);body=instances.read_text()
        for label,anchor,replacement in (
            ('lose-replacement-base','if(r.time_base)requested.player.time_base=*r.time_base;',''),
            ('retire-before-loop-admission','if((source.player.sequence || source.player.lsc_input) && r.loop_enabled.value_or(source.player.decoder.loop_enabled))return Status::unsupported_profile;',''),
        ):
            if body.count(anchor)!=1:raise ValueError('Instance mutation anchor '+label)
            changed=out/(label+'.cpp');changed.write_text(body.replace(anchor,replacement),encoding='utf-8',newline='\n');run(label,[changed,tests],True);record['detected_faults'].append(label)
        body=session.read_text();anchor='if(s.busy || s.clock->in_call || s.clock->service_busy)return Status::busy;'
        if body.count(anchor)!=1:raise ValueError('Clock guard anchor')
        changed=out/'import-during-service.cpp';changed.write_text(body.replace(anchor,''),encoding='utf-8',newline='\n')
        run('import-during-service',[changed,ROOT/'game/native/adxt_control_session/control_session_tests.cpp'],True);record['detected_faults'].append('import-during-service')
        verify()
        if sha(Path(__file__))!=own_hash:raise ValueError('Verifier source drift')
        record['status']='stable native game controls and admission faults qualified'
    finally:
        record['outputs_sha256']={p.name:sha(p)for p in out.iterdir()if p.suffix in ('.txt','.cpp')};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps({'status':record['status'],'receipt_sha256':sha(out/'receipt.json')}))
if __name__=='__main__':main()
