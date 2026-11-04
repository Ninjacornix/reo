"""Replay bank cancellation with production mixers and a headless device boundary.

Requires an existing C++20 compiler and an owned File #1 data directory.
The supplied SDK is read-only. Baseline deliberately fails the cancellation check.
"""
import argparse,hashlib,json,os,shutil,subprocess
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
REL=Path('ps2xRuntime/src/lib/Kernel/Syscalls/Helpers')
PATCH=ROOT/'third_party/patches/ps2recomp/0114-audio-retire-cancelled-bank-sequences.patch'

def run(args):
    out=args.out.resolve();out.relative_to(ROOT);out.mkdir(parents=True,exist_ok=False)
    stage=out/'sdk'
    for name in ['CriAudio.cpp','CriAudio.h','ReoSoundBanks.cpp','ReoSoundBanks.h']:
        dest=stage/REL/name;dest.parent.mkdir(parents=True,exist_ok=True)
        shutil.copyfile(args.sdk/REL/name,dest)
    # Existing diagnostic no-op and device stubs exclude scheduler/device setup;
    # all PCM generation, packet handling, sequence scheduling and envelopes are real.
    shutil.copyfile(ROOT/'tools/audio_mixer_check/vblank_music_diag.h',stage/'ps2xRuntime/src/lib/vblank_music_diag.h')
    apply=['git','apply','--directory='+stage.relative_to(ROOT).as_posix()]
    already=subprocess.run(apply+['--reverse','--check',str(PATCH)],cwd=ROOT,capture_output=True).returncode==0
    if args.baseline and already:subprocess.run(apply+['--reverse',str(PATCH)],cwd=ROOT,check=True)
    elif not already:
        subprocess.run(apply+['--check',str(PATCH)],cwd=ROOT,check=True)
        if not args.baseline:subprocess.run(apply+[str(PATCH)],cwd=ROOT,check=True)
    binary=out/('bank-cancel.exe' if os.name=='nt' else 'bank-cancel')
    command=[str(args.compiler),'-O2','-std=c++20','-DNOMINMAX','-I'+str(stage/REL),'-I'+str(ROOT/'tools/audio_mixer_check'),
        str(Path(__file__).with_name('bank_cancel.cpp')),str(stage/REL/'CriAudio.cpp'),str(stage/REL/'ReoSoundBanks.cpp'),'-o',str(binary)]
    (out/'command.json').write_text(json.dumps(command,indent=2))
    with (out/'compile.log').open('w') as log:subprocess.run(command,stdout=log,stderr=subprocess.STDOUT,check=True)
    result=subprocess.run([str(binary),str(args.data)],capture_output=True,text=True)
    (out/'runtime.log').write_text(result.stdout+result.stderr)
    (out/'result.json').write_text(json.dumps({'baseline':args.baseline,'returncode':result.returncode,
        'sdk':str(args.sdk),'patchSha256':hashlib.sha256(PATCH.read_bytes()).hexdigest(),
        'scope':'Production bank packet scheduler and PCM mixer; authored repeating TQ with owned menu sample; no game transition claim'},indent=2))
    print(result.stdout+result.stderr)
    return result.returncode

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    for option in ['sdk','data','compiler','out']:p.add_argument('--'+option,type=lambda x:Path(x).resolve(),required=True)
    p.add_argument('--baseline',action='store_true')
    raise SystemExit(run(p.parse_args()))
