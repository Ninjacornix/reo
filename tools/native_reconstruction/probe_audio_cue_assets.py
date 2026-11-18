#!/usr/bin/env python3
"""Audit real retained File1 ADX extents against native queued-clip admission."""
import argparse,collections,hashlib,json,os,subprocess
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
BASE=ROOT/'build-native-sjuni'
INVENTORY=BASE/'audio-asset-inventory/file1-v1'
IMPORT_SHA='ae3668c7e98defe0eb16ce107490078451e9c2f57cb2fb87c162f37520f2600b'
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    for name in ('data','compiler','manifest','native-receipt','output'):parser.add_argument('--'+name,type=Path,required=True)
    args=parser.parse_args();out=args.output.resolve();data=args.data.resolve();imported=data.parent/'import.json'
    if out.exists() or not out.is_relative_to(BASE/'queued-audio-checks'):raise ValueError('Fresh private output required')
    if sha(imported)!=IMPORT_SHA:raise ValueError('Pinned owned File1 import required')
    manifest=json.loads(args.manifest.read_bytes());native=json.loads(args.native_receipt.read_bytes())
    if native['status']!='native media pipeline standalone build and tests passed' or native['manifest_sha256']!=sha(args.manifest) or native['compiler_sha256']!=sha(args.compiler):raise ValueError('Matching complete native archive cohort required')
    inventory=json.loads((INVENTORY/'receipt.json').read_bytes())
    for name in ('members.json','archives.json'):
        if sha(INVENTORY/name)!=inventory['output_sha256'][name]:raise ValueError('Owned inventory drift')
    roots={r['member']:r for r in json.loads((INVENTORY/'archives.json').read_bytes()) if '/' not in r['member']}
    imports={r['Name'].upper():r for r in json.loads(imported.read_bytes())['Files']}
    members=[r for r in json.loads((INVENTORY/'members.json').read_bytes()) if r['recognition']=='adx_structural_header']
    plan=[]
    for index,row in enumerate(members):
        root=roots[row['container']];file=imports[row['container'].upper()];relative=row['iso_offset']-root['iso_offset'];sectors=(row['bytes']+2047)//2048
        if file['Sha256']!=root['sha256'] or file['Length']!=root['bytes'] or relative<0 or relative%2048 or not sectors or relative+sectors*2048>file['Length']:raise ValueError('Owned cue extent identity/range mismatch')
        plan.append(f"{index}\t{row['container']}\t{relative//2048}\t{sectors}\n")
    inputs={name:digest for name,digest in manifest['files'].items() if name.startswith('game/native/')}
    for path in ('recomp/overrides/native_adxt/source_profile.cpp','recomp/overrides/native_adxt/source_profile.h',
                 'tools/native_reconstruction/probe_audio_cue_assets.cpp',Path(__file__).relative_to(ROOT).as_posix()):inputs[path]=sha(ROOT/path)
    def verify():
        for name,digest in {**inputs,**native['libraries']}.items():
            if sha(ROOT/name)!=digest:raise ValueError('Source/archive drift: '+name)
    verify();before={name:(s.st_size,s.st_mtime_ns,s.st_ino) for name in imports for s in [(data/name).stat()]}
    out.mkdir(parents=True);(out/'plan.tsv').write_text(''.join(plan),encoding='utf8')
    (out/'planned-members.json').write_text(json.dumps(members,indent=2)+'\n',encoding='utf8')
    env=dict(os.environ);env['PATH']=str(args.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    record=dict(schema=1,status='failed',compiler_sha256=sha(args.compiler),source_sha256=inputs,
        manifest_sha256=sha(args.manifest),native_receipt_sha256=sha(args.native_receipt),inventory_receipt_sha256=sha(INVENTORY/'receipt.json'),
        import_manifest_sha256=IMPORT_SHA,planned=len(members),game_run=False,audio_device_opened=False,owned_payloads_copied=False,checks=[])
    try:
        binary=out/'probe.exe';command=[args.compiler,'-std=c++20','-O2','-pthread','-Wall','-Wextra','-Wpedantic','-Werror',
            '-DNOMINMAX','-DWIN32_LEAN_AND_MEAN','-I'+str(ROOT),ROOT/'tools/native_reconstruction/probe_audio_cue_assets.cpp',
            ROOT/'recomp/overrides/native_adxt/source_profile.cpp','-Wl,--start-group',*[ROOT/name for name in native['libraries']],'-Wl,--end-group',
            '-lbcrypt','-lole32','-lruntimeobject','-o',binary]
        result=subprocess.run(list(map(str,command)),capture_output=True,text=True,env=env,timeout=180)
        (out/'compile.txt').write_text(result.stdout+result.stderr,encoding='utf8');record['checks'].append(dict(name='compile',exit=result.returncode,command=list(map(str,command))))
        if result.returncode:raise ValueError('Probe compile failed; see retained log')
        command=[binary,data,out/'plan.tsv']
        with (out/'results.jsonl').open('x',encoding='utf8') as output,(out/'probe-stderr.txt').open('x',encoding='utf8') as error:
            result=subprocess.run(list(map(str,command)),stdout=output,stderr=error,env=env,timeout=1200)
        record['checks'].append(dict(name='owned-catalogue',exit=result.returncode,command=list(map(str,command))))
        if result.returncode:raise ValueError('Owned cue audit failed; see retained log')
        results=[json.loads(line) for line in (out/'results.jsonl').read_text().splitlines()]
        if len(results)!=len(members) or [r['index'] for r in results]!=list(range(len(members))):raise ValueError('Incomplete or reordered cue results')
        for result,row in zip(results,members):
            if result['status']=='ready' and (result['channels'],result['frequency'],result['samples'])!=(row['adx']['channels'],row['adx']['frequency'],row['adx']['total_samples']):raise ValueError('Native/independent header metadata mismatch')
        record.update(status='owned File1 native queued-clip admission audit completed',binary_sha256=sha(binary),
            status_counts=dict(collections.Counter(r['status'] for r in results)),
            refused_clip_status_counts=dict(collections.Counter(str(r.get('clip_status')) for r in results if r['status']!='ready')),
            ready_inline_loop_assets=sum(result['status']=='ready' and row['adx']['loop'].get('enabled',0)>0 for result,row in zip(results,members)),
            refused_members=[dict(member=row['member'],names=row['names'],result=result,independent_header=row['adx']) for result,row in zip(results,members) if result['status']!='ready'],
            selected_cues=[dict(member=row['member'],names=row['names'],result=result) for result,row in zip(results,members) if any('e3-bio_mix' in name.lower() or 's010100a.adx' in name.lower() or name.lower()=='bgm00.adx' for name in row['names'])],
            limitations=['Structural ADX inventory only; opaque/unconfirmed candidates are not admitted by this audit.',
                'Header admission is not PCM output, playlist controls, actual engine caller coverage or audible sync.',
                'Rejected assets remain explicit; do not remove checks or fall back to the original queue to label the route native.'])
        verify()
    finally:
        record['source_stats_unchanged']=all((s.st_size,s.st_mtime_ns,s.st_ino)==before[name] for name in imports for s in [(data/name).stat()])
        record['import_manifest_unchanged']=sha(imported)==IMPORT_SHA
        if not record['source_stats_unchanged'] or not record['import_manifest_unchanged']:record['status']='failed source drift'
        record['output_sha256']={p.name:sha(p) for p in out.iterdir() if p.is_file()}
        (out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf8')
    print(json.dumps({key:record[key] for key in ('status','planned','status_counts','selected_cues')}))

if __name__=='__main__':main()
