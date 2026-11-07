#!/usr/bin/env python3
"""Replay an inventoried owned SFD catalogue with an exact qualified GPU binary."""
import argparse,hashlib,json,os,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    p=argparse.ArgumentParser()
    for name in ['qualified','routes','data','output']:p.add_argument('--'+name,type=Path,required=True)
    a=p.parse_args();out=a.output.resolve();data=a.data.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/movie-matrix'):raise ValueError('Fresh owned scope required')
    qualified=json.loads(a.qualified.read_bytes());binary=a.qualified.with_name('gpu_check.exe')
    if qualified['status']!='real offscreen native movie geometry qualified' or sha(binary)!=qualified['binary_sha256']:raise ValueError('Qualified exact binary required')
    def source_check():
        for name,digest in qualified['sources'].items():
            if sha(ROOT/name)!=digest:raise ValueError('GPU source drift '+name)
    source_check();inventory=json.loads(a.routes.read_bytes());route_receipt=json.loads(a.routes.with_name('receipt.json').read_bytes())
    if sha(a.routes)!=route_receipt['members_sha256']:raise ValueError('Route inventory drift')
    compiler=Path(qualified['compiler'])
    if sha(compiler)!=qualified['compiler_sha256']:raise ValueError('Compiler drift')
    env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','')
    out.mkdir(parents=True);results=[]
    record=dict(status='running',qualified_receipt_sha256=sha(a.qualified),binary_sha256=sha(binary),route_inventory_sha256=sha(a.routes),runner_sha256=sha(Path(__file__)),results=results,game_run=False,audio_device_opened=False)
    try:
        for index,asset in enumerate(inventory):
            if not asset['complete'] or asset['audio_ids']:raise ValueError('Unadmitted catalogue route')
            folder=out/f'{index:03d}';folder.mkdir();source=(data/asset['container']).resolve()
            if not source.is_relative_to(data):raise ValueError('Container outside explicit import')
            with source.open('rb') as f:f.seek(asset['source_offset']);payload=f.read(asset['bytes'])
            if hashlib.sha256(payload).hexdigest()!=asset['sha256']:raise ValueError('Owned payload drift')
            path=folder/'owned.sfd';path.write_bytes(payload)
            run=subprocess.run([str(binary.resolve()),str(path),str(ROOT/'tools/parallel_gs_backend/movie_runtime/assets/movie_ipu_csc_nv12.spv')],capture_output=True,text=True,env=env,timeout=240)
            log=folder/'gpu-run.txt';log.write_text(run.stdout+run.stderr,encoding='utf-8',newline='\n')
            result=dict(index=index,asset=asset,exit=run.returncode,log_sha256=sha(log))
            if not run.returncode:
                result['result']=json.loads(next(s for s in reversed(run.stdout.splitlines()) if s.startswith('{')))
                if result['result']['status']!='real GPU movie matrix checks passed':raise ValueError('Missing GPU completion proof')
            results.append(result)
            print(json.dumps(dict(index=index,asset='/'.join(asset['names']),exit=run.returncode,decoded=result.get('result',{}).get('decoded'))),flush=True)
            (out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
        source_check()
        record.update(status='complete catalogue executed',passed=sum(x['exit']==0 for x in results),failed=sum(x['exit']!=0 for x in results))
    finally:
        (out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
    if record['failed']:raise ValueError('Catalogue has retained failures')

if __name__=='__main__':main()
