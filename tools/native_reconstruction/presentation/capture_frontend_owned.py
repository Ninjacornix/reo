"""Seal the four-asset frontend branch omitted from the coordinated receipt.

This runs the already-linked cohort executable; it does not rebuild or claim
installed gameplay. The snapshot and the shared archives are checked before
and after execution, and all four real input hashes match the cohort receipt.
"""
import argparse,hashlib,json,os,subprocess,time
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
CC=Path('C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe')
BUILD=ROOT/'build-native-sjuni/gameplay-native-llvm-v1'
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--snapshot',type=Path,required=True);p.add_argument('--output',type=Path,required=True);args=p.parse_args()
    snapshot=args.snapshot.resolve();out=args.output.resolve();assert not out.exists() and out.is_relative_to((ROOT/'build-native-sjuni').resolve());out.mkdir(parents=True)
    snapshot_receipt=snapshot/'receipt.json';snap=json.loads(snapshot_receipt.read_text());assert snap['status']=='passed'
    cohort_receipt=ROOT/snap['cohort'];assert sha(cohort_receipt)==snap['cohort_sha256'];cohort=json.loads(cohort_receipt.read_text())
    assert cohort['status']=='passed' and not cohort['source_drift'] and not cohort['archive_drift'] and sha(CC)==cohort['compiler_sha256']
    def verify():
        for name,expected in snap['source_sha256'].items():
            if sha(snapshot/'source'/name)!=expected:raise RuntimeError('snapshot source mismatch: '+name)
        for name,expected in cohort['sources_sha256'].items():
            if snap['source_sha256'].get(name)!=expected:raise RuntimeError('cohort source mismatch: '+name)
        for name,expected in snap['archives_sha256'].items():
            if sha(snapshot/'native-build'/name)!=expected or sha(BUILD/name)!=expected or cohort['archives_sha256'].get(name)!=expected:
                raise RuntimeError('cohort archive mismatch: '+name)
    verify()
    baseline=next(c['command'] for c in cohort['commands'] if c['label']=='session-startup-owned')
    assert len(baseline)==4
    voice=next(name for name in cohort['input_sha256'] if name.upper().endswith('NETBIO01.DAT'))
    command=baseline+[voice];executable=Path(command[0]);executable_hash=sha(executable)
    inputs=[Path(value) for value in command[1:]]
    for asset in inputs:assert sha(asset)==cohort['input_sha256'][str(asset.resolve())]
    env=dict(os.environ,PATH=str(CC.parent)+os.pathsep+os.environ.get('PATH',''))
    started=time.monotonic();result=subprocess.run(command,cwd=ROOT,capture_output=True,env=env,timeout=120)
    (out/'stdout.txt').write_bytes(result.stdout);(out/'stderr.txt').write_bytes(result.stderr)
    verify();assert sha(executable)==executable_hash
    assert all(sha(asset)==cohort['input_sha256'][str(asset.resolve())] for asset in inputs)
    observed=json.loads(result.stdout.decode().strip().splitlines()[-1]);assert result.returncode==0 and observed['checks']>=4400
    receipt={'status':'passed','cohort_receipt':str(cohort_receipt),'cohort_receipt_sha256':sha(cohort_receipt),
             'snapshot_receipt':str(snapshot_receipt),'snapshot_receipt_sha256':sha(snapshot_receipt),
             'executable_sha256':executable_hash,'compiler_sha256':sha(CC),'archive_sha256':snap['archives_sha256'],
             'input_sha256':{str(asset.resolve()):sha(asset) for asset in inputs},'command':command,'seconds':time.monotonic()-started,
             'stdout_sha256':sha(out/'stdout.txt'),'stderr_sha256':sha(out/'stderr.txt'),'observed':observed,
             'scope':'Four-asset owned frontend branch in the cohort-built executable; no installed gameplay or hardware parity claim.',
             'game_run':False}
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(observed))
if __name__=='__main__':main()
