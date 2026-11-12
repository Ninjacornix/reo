"""Compare actual native Program admission before/after the eligibility-bank cut.

Compiles frozen native source, uses no original CPU/register/RAM fixture, and
does not launch a game. The baseline is the source-audited pre-cut commit.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess

ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
BASELINE='bc5d18b2'

def sha(data):return hashlib.sha256(data).hexdigest()

def main(args):
    out=args.output.resolve()
    assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
    out.mkdir(parents=True)
    compiler=Path(args.compiler).resolve()
    native_build=args.native_build.resolve()
    env=dict(os.environ,PATH=str(compiler.parent)+os.pathsep+os.environ.get('PATH',''))
    units=[ROOT/'game/native/gameplay_scenario'/name for name in ('interpreter.cpp','script_program.cpp','content.cpp','actor_requests.cpp')]
    probe=HERE/'scene_record_eligibility_admission.cpp'
    pending=units+[probe];sources={}
    while pending:
        path=pending.pop();name=path.relative_to(ROOT).as_posix()
        if name in sources:continue
        frozen=args.source_snapshot/name if args.source_snapshot and path.is_relative_to(ROOT/'game/native') else path
        data=frozen.read_bytes();sources[name]=data
        for included in re.findall(r'#include "([^"]+)"',data.decode()):
            resolved=next((p.resolve() for p in (path.parent/included,ROOT/included) if p.is_file()),None)
            if resolved and resolved.is_relative_to(ROOT/'game/native'):pending.append(resolved)
    for name,data in sources.items():
        path=out/'source'/name;path.parent.mkdir(parents=True,exist_ok=True);path.write_bytes(data)
    baseline_commit=args.baseline_commit or BASELINE
    before=subprocess.check_output(['git','show',baseline_commit+':game/native/gameplay_scenario/interpreter.cpp'],cwd=ROOT)
    baseline=out/'before_interpreter.cpp';baseline.write_bytes(before)
    # A baseline implementation must retain its own Program declaration. API
    # and private-layout additions cannot be patched into historical source or
    # mixed with a probe compiled against a different Program object layout.
    before_header=subprocess.check_output(['git','show',baseline_commit+':game/native/gameplay_scenario/interpreter.hpp'],cwd=ROOT)
    before_source=out/'before_source';shutil.copytree(out/'source',before_source)
    (before_source/'game/native/gameplay_scenario/interpreter.hpp').write_bytes(before_header)
    rows=json.loads((ROOT/'build-native-sjuni/gameplay-script-content-llvm-v21/inventory.json').read_text())
    manifest=[];identities=[]
    for row in rows:
        with Path(row['archive']).open('rb') as source:
            source.seek(row['archive_offset']);raw=source.read(row['bytes'])
        assert sha(raw)==row['sha256']
        manifest.append('\t'.join((row['format'],row['archive'],str(row['archive_offset']),str(row['bytes']))))
        identities.append({key:row[key] for key in ('name','format','sha256')})
    assert len(rows)==171
    (out/'cases.tsv').write_text('\n'.join(manifest)+'\n')
    commands=[]
    # Keep the full production interpreter translation unit. Its uncalled
    # effect graph still needs real native definitions at link time. Retain
    # immutable copies of the actual CMake target's native archives rather
    # than inventing successful provider stubs or rewriting the interpreter.
    ninja=(native_build/'build.ninja').read_text()
    target=re.search(r'^build gameplay_scenario/gameplay_script_program_tests\.exe:.*?\n  FLAGS =.*?\n  LINK_LIBRARIES = ([^\n]+)',ninja,re.M)
    assert target
    libraries=[];library_sha={}
    for entry in target[1].split():
        if entry.endswith('.a'):
            source=native_build/entry;path=out/'libraries'/entry;path.parent.mkdir(parents=True,exist_ok=True)
            data=source.read_bytes();path.write_bytes(data);libraries.append(path);library_sha[entry]=sha(data)
        else:libraries.append(entry)
    def run(command,label):
        result=subprocess.run([str(x) for x in command],env=env,capture_output=True,text=True,timeout=180)
        (out/(label+'.stdout.txt')).write_text(result.stdout);(out/(label+'.stderr.txt')).write_text(result.stderr)
        commands.append(dict(command=[str(x) for x in command],returncode=result.returncode,stdout_sha256=sha(result.stdout.encode()),stderr_sha256=sha(result.stderr.encode())))
        if result.returncode:raise RuntimeError(label+': '+result.stderr[-6000:])
        return result.stdout
    flags=[compiler,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-ffunction-sections','-fdata-sections']
    results={}
    for label,source in [('before',baseline),('after',out/'source/game/native/gameplay_scenario/interpreter.cpp')]:
        tree=before_source if label=='before' else out/'source'
        base=flags+['-I'+str(tree),'-I'+str(tree/'game/native/gameplay_scenario')]
        common=[]
        for path in units[1:]+[probe]:
            obj=out/(label+'-'+path.stem+'.o');run(base+['-c',tree/path.relative_to(ROOT),'-o',obj],'compile-'+label+'-'+path.stem);common.append(obj)
        obj=out/(label+'.o');exe=out/(label+'.exe')
        run(base+['-c',source,'-o',obj],'compile-'+label)
        run([compiler,'-Wl,--gc-sections',obj,*common,*libraries,'-o',exe],'link-'+label)
        results[label]=json.loads(run([exe,out/'cases.tsv'],'run-'+label))
    evbs=[]
    for index,row in enumerate(rows):
        if row['format']=='E':
            original=results['before']['banks'][index];native=results['after']['banks'][index]
            if baseline_commit==BASELINE:
                assert original[0]['status']==2 and original[0]['opcode']==(0x156 if row['name']=='r041.evb' else 0x164)
            assert all(value['opcode']!=int(args.cut,16) for value in native)
            evbs.append(dict(name=row['name'],before=original,after=native))
    assert len(evbs)==5
    expected=[list(map(int,value.split(','))) for value in (args.expected_before_coverage,args.expected_after_coverage)]
    assert [[sum(mask) for mask in results[label]['coverage']] for label in ('before','after')]==expected
    accepted={label:[sum(row[p]['status']==0 for row in result['banks']) for p in (0,1)] for label,result in results.items()}
    drift={name:sha((ROOT/name).read_bytes()) for name,data in sources.items() if (ROOT/name).read_bytes()!=data}
    receipt=dict(schema='reo.native.scene_record_eligibility.admission.v1',status='passed',compiler=str(compiler),compiler_sha256=sha(compiler.read_bytes()),source_sha256={name:sha(data) for name,data in sources.items()},
        baseline_commit=baseline_commit,cut_opcode=args.cut,baseline_interpreter_sha256=sha(before),baseline_header_sha256=sha(before_header),baseline_probe_uses_matching_header=True,commands=commands,members=identities,evbs=evbs,admitted=accepted,
        native_library_sha256=library_sha,current_shared_source_drift=drift,source_frozen=True,game_launched=False,installed_in_game=False,stage4_complete=False)
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(dict(status='passed',admitted=accepted,evbs=evbs,current_shared_source_drift=drift)))

if __name__=='__main__':
    parser=argparse.ArgumentParser();parser.add_argument('--compiler',required=True);parser.add_argument('--output',type=Path,required=True);parser.add_argument('--native-build',type=Path,required=True);parser.add_argument('--source-snapshot',type=Path)
    parser.add_argument('--baseline-commit');parser.add_argument('--cut',default='164');parser.add_argument('--expected-before-coverage',default='355,327');parser.add_argument('--expected-after-coverage',default='356,328');main(parser.parse_args())
