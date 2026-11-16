"""Compare the complete original 1D3100 second bank to owned static poses.

Uses the prior original-body fixture and exact immutable native snapshot, with
an independently recorded input/archive identity and no shared build changes.
"""
import argparse,hashlib,json,os,subprocess,time
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
CC=Path('C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe')
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);args=p.parse_args();out=args.output.resolve()
    assert not out.exists() and out.is_relative_to((ROOT/'build-native-sjuni').resolve());out.mkdir(parents=True)
    original=ROOT/'build-native-sjuni/resource-static-llvm-v1';snapshot=ROOT/'build-native-sjuni/room-membership-frontend-cohort-snapshot-v1'
    source=original/'tests.cpp';fixture=ROOT/'tools/native_reconstruction/presentation/resource_bind_bank_original.inc';assets=original/'owned_static_nbd.bin'
    previous=json.loads((original/'receipt.json').read_text());assert previous['status']=='passed' and previous['source_unchanged']
    snap=json.loads((snapshot/'receipt.json').read_text());assert snap['status']=='passed'
    archives=sorted((snapshot/'native-build').rglob('*.a'));assert len(archives)==68
    inputs=[source,fixture,assets,original/'original_visuals.cpp',original/'original_dispatch.hpp',original/'functions.h',original/'reference.hpp',original/'owned_constants.hpp',original/'receipt.json',snapshot/'receipt.json',*archives]
    before={str(f.relative_to(ROOT)):sha(f) for f in inputs}
    text=source.read_text();prefix=text[:text.index('std::vector<std::vector<std::byte>> load(')]
    (out/'fixture.cpp').write_text(prefix+'\n#include "'+fixture.as_posix()+'"\n')
    exe=out/'checks.exe';env=dict(os.environ,PATH=str(CC.parent)+os.pathsep+os.environ.get('PATH',''))
    command=[str(CC),'-std=c++20','-O2','-msse4.1','-ffp-contract=off','-pthread','-Wno-unused-label','-Wno-unused-parameter',
             '-I'+str(snapshot/'source'),'-I'+str(original),str(out/'fixture.cpp'),'-Wl,--start-group',*(str(a) for a in archives),'-Wl,--end-group',
             '-luser32','-lgdi32','-ldxgi','-luuid','-lxinput','-o',str(exe)]
    receipt=dict(status='failed',compiler_sha256=sha(CC),input_sha256=before,driver_sha256=sha(Path(__file__)),commands=[],game_run=False,
                 limits=['Complete 1D3100 original-body fixture with its declared heap/registry ports; first four owned DEF NBDs.',
                         'Compares source second-bank matrices to current native first-bank matrices through affine identity tolerance.',
                         'Does not prove general singular, nonorthogonal or physical PS2 exceptional arithmetic.'])
    try:
        for name,cmd in [('compile',command),('run',[str(exe),str(assets)])]:
            start=time.monotonic();r=subprocess.run(cmd,capture_output=True,env=env,timeout=120)
            (out/(name+'.out')).write_bytes(r.stdout);(out/(name+'.err')).write_bytes(r.stderr)
            receipt['commands'].append(dict(name=name,seconds=time.monotonic()-start,exit=r.returncode))
            if r.returncode:raise RuntimeError(name+': '+r.stderr.decode(errors='replace')[-5000:])
        assert before=={str(f.relative_to(ROOT)):sha(f) for f in inputs}
        receipt.update(status='passed',observed=json.loads((out/'run.out').read_text()))
    finally:(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(receipt['observed']))
if __name__=='__main__':main()
