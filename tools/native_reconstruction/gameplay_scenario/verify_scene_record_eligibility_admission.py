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
    before=subprocess.check_output(['git','show',BASELINE+':game/native/gameplay_scenario/interpreter.cpp'],cwd=ROOT)
    baseline=out/'before_interpreter.cpp';baseline.write_bytes(before)
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
    base=[compiler,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-ffunction-sections','-fdata-sections','-I'+str(out/'source'),'-I'+str(out/'source/game/native/gameplay_scenario')]
    common=[]
    for path in units[1:]+[probe]:
        obj=out/(path.stem+'.o');run(base+['-c',out/'source'/path.relative_to(ROOT),'-o',obj],'compile-'+path.stem);common.append(obj)
    results={}
    for label,source in [('before',baseline),('after',out/'source/game/native/gameplay_scenario/interpreter.cpp')]:
        obj=out/(label+'.o');exe=out/(label+'.exe')
        run(base+['-c',source,'-o',obj],'compile-'+label)
        run([compiler,'-Wl,--gc-sections',obj,*common,*libraries,'-o',exe],'link-'+label)
        results[label]=json.loads(run([exe,out/'cases.tsv'],'run-'+label))
    evbs=[]
    for index,row in enumerate(rows):
        if row['format']=='E':
            original=results['before']['banks'][index];native=results['after']['banks'][index]
            assert original[0]['status']==2 and original[0]['opcode']==(0x156 if row['name']=='r041.evb' else 0x164)
            assert all(value['opcode']!=0x164 for value in native)
            evbs.append(dict(name=row['name'],before=original,after=native))
    assert len(evbs)==5
    assert [[sum(mask) for mask in results[label]['coverage']] for label in ('before','after')]==[[355,327],[356,328]]
    accepted={label:[sum(row[p]['status']==0 for row in result['banks']) for p in (0,1)] for label,result in results.items()}
    drift={name:sha((ROOT/name).read_bytes()) for name,data in sources.items() if (ROOT/name).read_bytes()!=data}
    receipt=dict(schema='reo.native.scene_record_eligibility.admission.v1',status='passed',compiler=str(compiler),compiler_sha256=sha(compiler.read_bytes()),source_sha256={name:sha(data) for name,data in sources.items()},
        baseline_commit=BASELINE,baseline_interpreter_sha256=sha(before),commands=commands,members=identities,evbs=evbs,admitted=accepted,
        native_library_sha256=library_sha,current_shared_source_drift=drift,source_frozen=True,game_launched=False,installed_in_game=False,stage4_complete=False)
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(dict(status='passed',admitted=accepted,evbs=evbs,current_shared_source_drift=drift)))

if __name__=='__main__':
    parser=argparse.ArgumentParser();parser.add_argument('--compiler',required=True);parser.add_argument('--output',type=Path,required=True);parser.add_argument('--native-build',type=Path,required=True);parser.add_argument('--source-snapshot',type=Path);main(parser.parse_args())
