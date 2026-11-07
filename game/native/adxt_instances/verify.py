#!/usr/bin/env python3
"""Exercise actual stable-instance/source/session ownership and detected faults."""
import argparse,hashlib,json,os,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent;BASE=ROOT/'build-native-sjuni/adxt-instances'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--native-receipt',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(BASE):raise ValueError('Fresh owned scope required')
    native=json.loads(a.native_receipt.read_bytes())
    if native['status']!='native media pipeline standalone build and tests passed' or native['compiler_sha256']!=sha(a.compiler) or native['manifest_sha256']!=sha(HERE/'manifest.json'):raise ValueError('Matching native build required')
    manifest=json.loads((HERE/'manifest.json').read_bytes())
    def verify():
        for name,digest in manifest['files'].items():
            if sha(ROOT/name)!=digest:raise ValueError('Source drift '+name)
    verify();libraries=[]
    for name,digest in native['libraries'].items():
        path=ROOT/name
        if sha(path)!=digest:raise ValueError('Native library drift')
        libraries.append(path)
    out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    record=dict(status='failed',manifest_sha256=sha(HERE/'manifest.json'),native_build_sha256=sha(a.native_receipt),compiler_sha256=sha(a.compiler),negative_controls=[],sources={p.relative_to(ROOT).as_posix():sha(p) for p in [HERE/'instances.cpp',HERE/'instances.hpp',HERE/'instances_tests.cpp',Path(__file__)]},game_run=False,device_opened=False)
    def run(label,source,negative=False):
        binary=out/(label+'.exe');cmd=[str(a.compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off','-frounding-math','-I'+str(HERE),str(source),str(HERE/'instances_tests.cpp'),'-Wl,--start-group',*[str(p) for p in libraries],'-Wl,--end-group','-o',str(binary)]
        value=subprocess.run(cmd,capture_output=True,text=True,env=env);(out/(label+'-compile.txt')).write_text(value.stdout+value.stderr,encoding='utf-8')
        if value.returncode:raise ValueError('Instance fixture compile failed '+label)
        value=subprocess.run([str(binary)],capture_output=True,text=True,env=env,timeout=45);(out/(label+'.txt')).write_text(value.stdout+value.stderr,encoding='utf-8',newline='\n')
        if (value.returncode==0)==negative:raise ValueError('Unexpected instance fixture result '+label)
        return sha(binary)
    try:
        record['binary_sha256']=run('native',HERE/'instances.cpp');body=(HERE/'instances.cpp').read_text()
        mutations=[('retain-superseded-request','r.pending=std::move(source);','if(!r.pending)r.pending=std::move(source);'),
                   ('forget-idle-pause','r.pause=value;','r.pause=0;'),
                   ('accept-stale-generation','r.generation==key.generation_','true'),
                   ('stop-shared-session','r.pending.reset();r.retiring=true;return retire(key.slot_);','r.pending.reset();(void)s.session.request_stop();r.retiring=true;return retire(key.slot_);')]
        for label,old,new in mutations:
            if body.count(old)!=1:raise ValueError('Mutation anchor missing '+label)
            path=out/(label+'.cpp');path.write_text(body.replace(old,new),encoding='utf-8',newline='\n');run(label,path,True);record['negative_controls'].append(dict(name=label,detected=True))
        verify();record.update(status='stable native ADXT instance ownership qualified',workflows=3,real_source_workers=True,output_provider='explicit callback/fence model')
    finally:
        record['outputs_sha256']={p.name:sha(p) for p in out.iterdir() if p.suffix in ['.json','.txt','.cpp'] and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps({k:record[k] for k in ['status','workflows']}))
if __name__=='__main__':main()
