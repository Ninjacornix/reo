#!/usr/bin/env python3
"""Native control admission/source fence and detected unsafe shutdown mutations."""
import argparse,hashlib,json,os,subprocess
from pathlib import Path
HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--native-receipt',type=Path,required=True)
    p.add_argument('--manifest',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/adxt-control-owner'):raise ValueError('Fresh owned output required')
    manifest=json.loads(a.manifest.read_bytes());native=json.loads(a.native_receipt.read_bytes())
    if native['status']!='native media pipeline standalone build and tests passed' or native['compiler_sha256']!=sha(a.compiler) or native['manifest_sha256']!=sha(a.manifest):raise ValueError('Matching native cohort/compiler required')
    def verify():
        for name,digest in manifest['files'].items():
            if sha(ROOT/name)!=digest:raise ValueError('Source drift '+name)
        for name,digest in native['libraries'].items():
            if sha(ROOT/name)!=digest:raise ValueError('Archive drift '+name)
    verify();out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    record=dict(status='failed',manifest_sha256=sha(a.manifest),native_receipt_sha256=sha(a.native_receipt),compiler_sha256=sha(a.compiler),game_run=False,device_opened=False,negative_controls=[])
    def run(label,source,negative=False):
        binary=out/(label+'.exe');command=[a.compiler,'-std=c++20','-O1','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off','-pthread','-I'+str(HERE),source,HERE/'owner_tests.cpp','-Wl,--start-group',*[ROOT/n for n in native['libraries']],'-Wl,--end-group','-o',binary]
        value=subprocess.run(list(map(str,command)),capture_output=True,text=True,env=env,timeout=90)
        (out/(label+'-compile.txt')).write_text(value.stdout+value.stderr,encoding='utf-8',newline='\n')
        if value.returncode:raise ValueError('Fixture compile failed '+label)
        value=subprocess.run([str(binary)],capture_output=True,text=True,env=env,timeout=45)
        (out/(label+'.txt')).write_text(value.stdout+value.stderr,encoding='utf-8',newline='\n')
        if (value.returncode==0)==negative:raise ValueError('Unexpected fixture result '+label)
        return sha(binary)
    try:
        record['binary_sha256']=run('native',HERE/'owner.cpp');body=(HERE/'owner.cpp').read_text()
        admission='    if(s.stopping.load(std::memory_order_acquire)){++s.refused;return Admission::closed;}\n'
        if body.count(admission)!=2:raise ValueError('Admission anchors changed')
        front,tail=body.rsplit(admission,1)
        mutations=[('omit-post-lock-admission',front+tail),
            ('bypass-controller-fence',body.replace('request_stop();std::lock_guard lock(s.control);','request_stop();')),
            ('complete-pending-source',body.replace('if(status!=instances::Status::pending)return Join::fault;','if(status==instances::Status::pending){s.final=s.players.snapshot();s.joined.store(true,std::memory_order_release);return Join::completed;}\n        if(status!=instances::Status::pending)return Join::fault;'))]
        for label,changed in mutations:
            if changed==body:raise ValueError('Mutation anchor changed '+label)
            source=out/(label+'.cpp');source.write_text(changed,encoding='utf-8',newline='\n');run(label,source,True);record['negative_controls'].append(dict(name=label,detected=True))
        verify();record.update(status='native controller admission and actual source retirement qualified',workflows=3)
    finally:
        record['outputs_sha256']={p.name:sha(p)for p in out.iterdir()if p.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=record['status'],receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
