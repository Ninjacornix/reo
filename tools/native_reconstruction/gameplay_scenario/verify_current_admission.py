"""Current all171-bank admission against actual rebuilt LLVM native archives."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parent))
from verify_native_session import dependency_sources

def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()

def main(args):
    compiler=args.compiler.resolve();build=args.native_build.resolve();out=args.output.resolve()
    snapshot=args.immutable_snapshot.resolve() if args.immutable_snapshot else None
    manifest=json.loads((snapshot/'receipt.json').read_text()) if snapshot else None
    if snapshot:
        assert manifest['status']=='passed' and sha(snapshot/'cohort.json')==manifest['cohort_sha256']
        build=snapshot/'native-build'
    assert compiler.name=='x86_64-w64-mingw32-clang++.exe'
    assert sha(compiler)=='f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3'
    assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
    probe=HERE/'scene_record_eligibility_admission.cpp'
    if snapshot:
        inputs={name:snapshot/'source'/name for name in manifest['source_sha256']}
        assert all(sha(path)==manifest['source_sha256'][name] for name,path in inputs.items())
        libraries=sorted(manifest['archives_sha256'])
    else:
        sources,libraries=dependency_sources(build)
        inputs={p.relative_to(ROOT).as_posix():p for p in sources}
    inputs.update({p.relative_to(ROOT).as_posix():p for p in (Path(__file__).resolve(),probe)})
    before={name:sha(path) for name,path in inputs.items()}
    library_hashes={name:sha(build/name) for name in libraries}
    if snapshot:assert library_hashes==manifest['archives_sha256']
    members=json.loads((ROOT/'build-native-sjuni/gameplay-script-content-llvm-v21/inventory.json').read_text())
    cases=[]
    for row in members:
        with Path(row['archive']).open('rb') as stream:stream.seek(row['archive_offset']);data=stream.read(row['bytes'])
        assert hashlib.sha256(data).hexdigest()==row['sha256']
        cases.append('\t'.join(map(str,(row['format'],row['archive'],row['archive_offset'],row['bytes']))))
    assert len(cases)==171
    # These directories are the actual8163B0/700330 SGL table producers,
    # separate from the existing171 EVB/RDT bank metric.
    from verify_offline_room_variants import ASSETS
    sgl=[]
    for name,digest in ASSETS.items():
        path=ROOT/'build-native-sjuni/gameplay-navigation-bank-llvm-v2'/name
        data=path.read_bytes();assert hashlib.sha256(data).hexdigest()==digest
        key=path.relative_to(ROOT).as_posix();inputs[key]=path;before[key]=digest
        table=struct.unpack_from('<I',data,8)[0];count=struct.unpack_from('<I',data,table)[0]
        descriptors=[struct.unpack_from('<hhII',data,table+4+12*i)for i in range(count)]
        starts=sorted(set(row[2]for row in descriptors))
        for i,start in enumerate(starts):
            end=starts[i+1]if i+1<len(starts)else len(data)
            directory=start+struct.unpack_from('<I',data,start+4)[0]
            assert directory+64<=end
            sgl.append(dict(asset=name,asset_sha256=digest,graph_offset=start,directory_offset=directory,bytes=end-directory,
                            descriptors=[dict(room=r,variant=v,policy=policy)for r,v,offset,policy in descriptors if offset==start]))
            cases.append('\t'.join(map(str,('S',path,directory,end-directory))))
    assert len(sgl)==166
    (out/'cases.tsv').write_text('\n'.join(cases)+'\n')
    env=dict(os.environ,PATH=str(compiler.parent)+os.pathsep+os.environ.get('PATH',''))
    commands=[]
    def run(command,label):
        result=subprocess.run(command,capture_output=True,text=True,env=env,timeout=240)
        (out/(label+'.stdout.txt')).write_text(result.stdout);(out/(label+'.stderr.txt')).write_text(result.stderr)
        commands.append(dict(command=command,returncode=result.returncode,stdout_sha256=hashlib.sha256(result.stdout.encode()).hexdigest(),stderr_sha256=hashlib.sha256(result.stderr.encode()).hexdigest()))
        if result.returncode:raise RuntimeError(label+': '+result.stderr[-4000:])
        return result.stdout
    base=[str(compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off']+(['-I'+str(snapshot/'source')] if snapshot else [])+['-I'+str(ROOT)]
    run(base+['-c',str(probe),'-o',str(out/'probe.o')],'compile')
    run([str(compiler),str(out/'probe.o'),'-Wl,--start-group']+[str(build/name) for name in libraries]+['-Wl,--end-group','-lpthread','-o',str(out/'checks.exe')],'link')
    result=json.loads(run([str(out/'checks.exe'),str(out/'cases.tsv')],'run-after'))
    drift={name:sha(inputs[name]) for name,digest in before.items() if sha(inputs[name])!=digest}
    assert not drift
    assert all(sha(build/name)==digest for name,digest in library_hashes.items())
    admitted=[sum(row[p]['status']==0 for row in result['banks'][:len(members)]) for p in (0,1)]
    evbs=[dict(name=member['name'],after=result['banks'][i]) for i,member in enumerate(members) if member['format']=='E']
    sgl_results=[dict(**entry,after=result['banks'][len(members)+i])for i,entry in enumerate(sgl)]
    sgl_admitted=[sum(row['after'][profile]['status']==0 for row in sgl_results)for profile in range(2)]
    startup_admitted=[sum(row['after'][profile]['startup']['status']==0 for row in evbs) for profile in range(2)]
    receipt=dict(schema='reo.native.current_script_admission.v1',status='passed',compiler=str(compiler),compiler_sha256=sha(compiler),source_sha256=before,native_library_sha256=library_hashes,commands=commands,
        current_shared_source_drift=drift,qualification_scope='immutable_cohort_source_header_and_archive_snapshot' if snapshot else 'current_shared_archives',immutable_snapshot=str(snapshot.relative_to(ROOT)) if snapshot else None,immutable_snapshot_receipt_sha256=sha(snapshot/'receipt.json') if snapshot else None,
        live_source_drift=[name for name,digest in before.items() if not(ROOT/name).is_file()or sha(ROOT/name)!=digest],executable_sha256=sha(out/'checks.exe'),members=[{key:row[key] for key in ('name','format','sha256')} for row in members],admitted=admitted,coverage=[sum(row) for row in result['coverage']],evbs=evbs,evb_startup_admitted=startup_admitted,sgl_graphs=sgl_results,sgl_admitted=sgl_admitted,game_launched=False,stage4_complete=False)
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(dict(status='passed',admitted=admitted,coverage=receipt['coverage'],evbs=evbs,evb_startup_admitted=startup_admitted,sgl_admitted=sgl_admitted)))

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--native-build',type=Path,required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--immutable-snapshot',type=Path);main(p.parse_args())
