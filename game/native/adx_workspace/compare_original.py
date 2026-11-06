#!/usr/bin/env python3
"""Inputs-only transport into frozen allocation-free native codec; no decoder."""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import subprocess

BASE=Path(__file__).resolve().parent
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def verify_freeze():
    frozen=json.loads((BASE/'frozen_identity.json').read_bytes())
    for name,digest in frozen['files'].items():
        if sha(BASE/name)!=digest:raise RuntimeError('Frozen native source changed: '+name)


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--fixture',type=Path,required=True);parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--compiler',required=True);args=parser.parse_args()
    verify_freeze();manifest=json.loads((args.fixture/'manifest.json').read_bytes())
    for name,field in [('inputs.json','inputs_sha256'),('expected.json','expected_sha256')]:
        if sha(args.fixture/name)!=manifest[field]:raise RuntimeError('Original fixture changed')
    if sha(BASE/'frozen_identity.json')!=manifest['core_freeze_sha256']:raise RuntimeError('Fixture linked to a different core freeze')
    inputs=json.loads((args.fixture/'inputs.json').read_bytes())['cases']
    expected=json.loads((args.fixture/'expected.json').read_bytes())
    if len(inputs)!=len(expected):raise RuntimeError('Fixture count differs')
    out=args.output.resolve()
    if out.exists():raise RuntimeError('Preserve earlier evidence; use new directory')
    out.mkdir(parents=True);compiler=shutil.which(args.compiler) or args.compiler
    binary=out/'probe.exe';command=[compiler,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror',
        str(BASE/'adx_workspace.cpp'),str(BASE/'fixture_runner.cpp'),'-o',str(binary)]
    build=subprocess.run(command,capture_output=True,text=True);(out/'compiler.stdout.txt').write_text(build.stdout);(out/'compiler.stderr.txt').write_text(build.stderr)
    if build.returncode:raise RuntimeError(build.stderr)
    lines=[str(len(inputs))]
    for index,c in enumerate(inputs):
        encoded=bytes.fromhex(c['encoded_hex']);route={'mono':0,'normal':1,'downmix':2}[c['route']]
        # No expected output/state is passed to the compiled probe.
        tokens=[f'case_{index}',route,c['requested'],len(encoded),c['output_samples'],*c['history'],c['key'],
                *c['coefficients'],c['multiplier'],c['addend'],*encoded]
        lines.append(' '.join(map(str,tokens)))
    transport='\n'.join(lines)+'\n';(out/'input.txt').write_text(transport)
    run=subprocess.run([str(binary)],input=transport,capture_output=True,text=True)
    (out/'native-results.jsonl').write_text(run.stdout);(out/'runtime.stderr.txt').write_text(run.stderr)
    if run.returncode:raise RuntimeError('Native probe failed: '+str(run.returncode)+' '+run.stderr)
    observed=[json.loads(line) for line in run.stdout.splitlines()]
    if len(observed)!=len(expected):raise RuntimeError('Native result count differs')
    comparisons=[];mismatches=[]
    fields=('kernel_return','stop','history','key','left_history_committed','right_history_committed',
            'complete_channel_blocks','samples_per_plane','encoded_bytes_consumed','encoded_bytes_inspected','left_pcm','right_pcm')
    for index,(c,e,row) in enumerate(zip(inputs,expected,observed)):
        e=e['expected'];checks=dict(name=row['name']==f'case_{index}',status=row['status']==e['status'],
            allocation_free=row['allocation_attempts']==0,guards=row['guards'],encoded_unchanged=row['encoded_unchanged'])
        if e['status']=='admitted':checks.update({key:row.get(key)==e[key] for key in fields})
        else:checks['no_output_effects']=all(v==-23131 for key in ('left_pcm','right_pcm') for v in row[key])
        comparisons.append(dict(name=c['name'],checks=checks,passed=all(checks.values())))
        if not all(checks.values()):mismatches.append(dict(name=c['name'],fields=[k for k,v in checks.items() if not v],observed=row,expected=e))
    verify_freeze()
    receipt=dict(schema=1,manifest_sha256=sha(args.fixture/'manifest.json'),frozen_identity_sha256=sha(BASE/'frozen_identity.json'),
        input_sha256=manifest['inputs_sha256'],expected_sha256=manifest['expected_sha256'],
        compiler=dict(path=compiler,sha256=sha(Path(compiler)),command=command),probe_sha256=sha(binary),
        runner_sha256=sha(BASE/'fixture_runner.cpp'),comparator_sha256=sha(Path(__file__)),
        transport_sha256=sha(out/'input.txt'),native_result_sha256=sha(out/'native-results.jsonl'),
        comparisons=comparisons,mismatches=mismatches,summary=dict(**manifest['summary'],passed=len(comparisons)-len(mismatches),failed=len(mismatches)))
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2,sort_keys=True)+'\n')
    print(json.dumps(receipt['summary'],indent=2))
    if mismatches:raise RuntimeError('Native/original mismatches; see retained receipt')


if __name__=='__main__':main()
