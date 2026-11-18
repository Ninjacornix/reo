#!/usr/bin/env python3
"""Independent native range comparisons and real retained-tail/lifetime checks."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
BASE=ROOT/'build-native-sjuni/afs-source-range'
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()


def wire(case):
    if case.get('kind')=='open':return f"open {case['start']} {case['count']} {case['total']}\n"
    return f"archive {case['archive_bytes']} {len(case['lengths'])}\n"+'\n'.join(f'{a} {n}'for a,n in zip(case['offsets'],case['lengths'],strict=True))+'\n'


def expected(case,original,actual):
    projection=original['projection']
    if any(o['failure']for o in original['operations']):raise ValueError('Partial original entered positive comparison')
    if actual['status']!=0:return 'native refusal '+str(actual['status'])
    if case.get('kind')=='open':
        if any(actual[k]!=projection[k]for k in ('start_sector','byte_length')):return 'open range differs'
        return None
    if actual['count']!=projection['member_count']:return 'member count differs'
    if actual['entries'][0][0]!=projection['first_sector']:return 'first data sector differs'
    descriptor=bytes.fromhex(original['operations'][-1]['after']['descriptor_hex'])
    width=4 if case['mode']==1 else 2
    cursor=projection['first_sector']
    for i,entry in enumerate(actual['entries']):
        at=0x118+width*(i+1)
        sectors=int.from_bytes(descriptor[at:at+width],'little')
        if entry[:2]!=[cursor,sectors]:return 'parsed descriptor entry differs '+str(i)
        if entry[2]!=case['lengths'][i]:return 'logical source metadata differs '+str(i)
        cursor+=sectors
    for row in projection['ranges']:
        if row['result_u32']!=0:continue
        entry=actual['entries'][row['index']]
        if row['start']!=entry[0]+case['base_sector']or row['count']!=entry[1]:return 'resolved member differs '+str(row['index'])
    return None


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--cxx',required=True);parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args();cc=shutil.which(args.cxx);out=args.output.resolve()
    if not cc or out.exists()or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh scoped output required')
    manifest=json.loads((HERE/'manifest.json').read_bytes())
    for n,d in manifest['files'].items():
        if sha(ROOT/n)!=d:raise ValueError('Frozen source drift '+n)
    frozen=BASE/'frozen-v3';proof=json.loads((BASE/'original-v3/receipt.json').read_bytes())
    if proof['source_postcheck']or any(c['partials']for c in proof['cases']):raise ValueError('Original observation is incomplete')
    if sha(frozen/'manifest.json')!=proof['manifest_sha256']:raise ValueError('Different original frozen inputs')
    identity=json.loads((frozen/'manifest.json').read_bytes())
    if sha(frozen/'inputs.json')!=identity['inputs_sha256']:raise ValueError('Authored input drift')
    cases=json.loads((frozen/'inputs.json').read_bytes());descriptors={c['name']:c for c in proof['cases']}
    originals={}
    for case in cases:
        p=BASE/'original-v3'/(case['name']+'.json')
        if sha(p)!=descriptors[case['name']]['sha256']:raise ValueError('Original output drift')
        originals[case['name']]=json.loads(p.read_bytes())
    out.mkdir(parents=True);shutil.copyfile(__file__,out/'verify.source.py')
    env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    receipt=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),
                 implementation_manifest_sha256=sha(HERE/'manifest.json'),verifier_sha256=sha(Path(__file__)),
                 fixture_sha256=sha(HERE/'fixture_runner.cpp'),original_receipt_sha256=sha(BASE/'original-v3/receipt.json'),
                 game_run=False,device_opened=False,checks=[],cases=[],negatives=[])
    flags=[cc,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(HERE)]
    backing=ROOT/'game/native/resources/bounded_view.cpp'
    def run(name,command,wanted=0):
        p=subprocess.run([str(x)for x in command],cwd=ROOT,env=env,text=True,capture_output=True,timeout=60)
        (out/(name+'.txt')).write_text(p.stdout+p.stderr,encoding='utf-8',newline='\n')
        receipt['checks'].append(dict(name=name,command=[str(x)for x in command],exit_code=p.returncode,expected=wanted,stdout=p.stdout))
        if p.returncode!=wanted:raise RuntimeError(name+': '+p.stdout+p.stderr)
        return p.stdout
    def build(name,core,client):
        binary=out/(name+'.exe');run(name+'_compile',flags+[backing,core,client,'-o',binary]);return binary
    def execute(binary,case):
        p=out/(case['name']+'.input.txt')
        if not p.exists():p.write_text(wire(case),encoding='utf-8',newline='\n')
        result=subprocess.run([str(binary),str(p)],cwd=ROOT,env=env,text=True,capture_output=True,timeout=10)
        (out/(binary.stem+'-'+case['name']+'.json')).write_text(result.stdout,encoding='utf-8',newline='\n')
        if result.returncode:raise RuntimeError('Fixture execution failed '+result.stderr)
        return json.loads(result.stdout)
    try:
        units=build('units',HERE/'afs_source_range.cpp',HERE/'afs_source_range_tests.cpp');run('units',[units])
        binary=build('fixture',HERE/'afs_source_range.cpp',HERE/'fixture_runner.cpp');receipt['executable_sha256']=sha(binary)
        for case in cases:
            actual=execute(binary,case);mismatch=expected(case,originals[case['name']],actual)
            if mismatch:raise ValueError(case['name']+': '+mismatch)
            receipt['cases'].append(dict(name=case['name'],classification='matched source range arithmetic or parsed/resolved sector table',members=actual.get('count',0)))
        text=(HERE/'afs_source_range.cpp').read_text(encoding='utf-8')
        anchor='(std::uint64_t(length) + 2047) / 2048'
        if text.count(anchor)!=1:raise ValueError('Sector mutation anchor changed')
        mutant=out/'negative_floor.cpp';mutant.write_text(text.replace(anchor,'std::uint64_t(length) / 2048'),encoding='utf-8',newline='\n')
        bad=build('negative_floor',mutant,HERE/'fixture_runner.cpp');differences=[]
        for case in cases:
            if expected(case,originals[case['name']],execute(bad,case)):differences.append(case['name'])
        if not differences:raise ValueError('Comparison missed floor-sector negative')
        receipt['negatives'].append(dict(name='floor_sector_lengths',differences=differences,variant_sha256=sha(mutant)))
        # Separate real-byte test catches an adapter which substitutes the
        # logical member extent after computing correct sector metadata.
        anchor='std::uint64_t(selected->sectors) * 2048);'
        if text.count(anchor)!=1:raise ValueError('View mutation anchor changed')
        mutant=out/'negative_logical_view.cpp';mutant.write_text(text.replace(anchor,'std::uint64_t(selected->logical_bytes));'),encoding='utf-8',newline='\n')
        bad=build('negative_logical_view',mutant,HERE/'afs_source_range_tests.cpp');run('negative_logical_view',[bad],1)
        receipt['negatives'].append(dict(name='logical_extent_replaces_actual_sector_view',variant_sha256=sha(mutant),detected=True))
        receipt['status']='passed bounded AFS index/source range qualification'
    except Exception as e:
        receipt.update(status='failed',failure=str(e));raise
    finally:
        receipt['input_drift']=[n for n,d in manifest['files'].items()if sha(ROOT/n)!=d]
        if receipt['input_drift']:receipt.update(status='failed',failure='Source drift')
        (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=receipt['status'],cases=len(receipt['cases']),receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
