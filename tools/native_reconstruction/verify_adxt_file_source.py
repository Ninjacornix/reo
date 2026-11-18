#!/usr/bin/env python3
"""Check actual immutable import subranges without a runtime or game launch."""
import argparse,hashlib,json,os,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2];HERE=ROOT/'recomp/overrides/native_adxt'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--compiler',type=Path,required=True);p.add_argument('--data',type=Path,required=True);p.add_argument('--native-receipt',type=Path,required=True);p.add_argument('--manifest',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists()or not out.is_relative_to(ROOT/'build-native-sjuni/adxt-binding'):raise ValueError('Fresh owned output required')
    native=json.loads(a.native_receipt.read_bytes());manifest=json.loads(a.manifest.read_bytes())
    if native['status']!='native media pipeline standalone build and tests passed'or native['manifest_sha256']!=sha(a.manifest)or native['compiler_sha256']!=sha(a.compiler):raise ValueError('Matching archive/compiler cohort required')
    # Only the archive bodies and their interfaces are consumed here. The
    # separately rebuilt runtime observer/factory is outside these archives.
    inputs={n:d for n,d in manifest['files'].items()if n.startswith('game/native/')or n.startswith('recomp/overrides/native_banks/')}
    inputs.update({p.relative_to(ROOT).as_posix():sha(p)for p in (HERE/'source_profile.h',HERE/'source_profile.cpp',HERE/'source_profile_tests.cpp',Path(__file__))})
    def verify():
        for n,d in {**inputs,**native['libraries']}.items():
            if sha(ROOT/n)!=d:raise ValueError('Source/archive drift '+n)
    verify();data=a.data.resolve();imported=data.parent/'import.json'
    if sha(imported)!='ae3668c7e98defe0eb16ce107490078451e9c2f57cb2fb87c162f37520f2600b':raise ValueError('Qualified actual File1 import required')
    files=json.loads(imported.read_bytes())['Files'];before={x['Name']:(data/x['Name']).stat()for x in files};out.mkdir(parents=True)
    env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    record=dict(status='failed',compiler_sha256=sha(a.compiler),native_receipt_sha256=sha(a.native_receipt),archive_manifest_sha256=sha(a.manifest),sources=inputs,checks=[],actual_import=True,game_run=False,actual_runtime=False,device_opened=False)
    def run(label,command,negative=False):
        r=subprocess.run(list(map(str,command)),env=env,capture_output=True,text=True,timeout=150);(out/(label+'.txt')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n');record['checks'].append(dict(label=label,exit=r.returncode,negative=negative))
        if (r.returncode==0)==negative:raise ValueError(label+' unexpected result; see retained log')
        print(label+': '+('fault detected'if negative else'passed'),flush=True)
    try:
        exe=out/'source.exe';flags=[a.compiler,'-std=c++20','-O2','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off','-I'+str(ROOT),'-I'+str(HERE)]
        run('compile',flags+[HERE/'source_profile.cpp',HERE/'source_profile_tests.cpp','-Wl,--start-group',*[ROOT/n for n in native['libraries']],'-Wl,--end-group','-lbcrypt','-lole32','-lruntimeobject','-o',exe]);run('actual-import',[exe,data]);verify()
        body=(HERE/'source_profile.cpp').read_text();anchor='std::uint64_t(range.start_sector)*2048'
        if body.count(anchor)!=1:raise ValueError('Subrange mutation anchor')
        changed=out/'ignore-start-sector.cpp';changed.write_text(body.replace(anchor,'0'),encoding='utf-8',newline='\n');fault=out/'ignore-start-sector.exe'
        run('fault-compile',flags+[changed,HERE/'source_profile_tests.cpp','-Wl,--start-group',*[ROOT/n for n in native['libraries']],'-Wl,--end-group','-lbcrypt','-lole32','-lruntimeobject','-o',fault]);run('ignore-start-sector',[fault,data],True);verify()
        record.update(status='actual immutable file source subranges and retained lifetime qualified',binary_sha256=sha(exe),detected_faults=['ignore-start-sector'],fault_source_sha256=sha(changed))
    finally:
        after={x['Name']:(data/x['Name']).stat()for x in files};record['source_stats_unchanged']=all((s.st_size,s.st_mtime_ns,s.st_ino)==(after[n].st_size,after[n].st_mtime_ns,after[n].st_ino)for n,s in before.items());record['import_manifest_unchanged']=sha(imported)=='ae3668c7e98defe0eb16ce107490078451e9c2f57cb2fb87c162f37520f2600b'
        if not record['source_stats_unchanged']or not record['import_manifest_unchanged']:record['status']='failed source drift'
        record['outputs_sha256']={p.name:sha(p)for p in out.iterdir()if p.suffix=='.txt'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps({'status':record['status'],'receipt_sha256':sha(out/'receipt.json')}))
if __name__=='__main__':main()
