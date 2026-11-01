"""Check RNA destruction against real RPC and PCM code using an existing Mac Ninja build.

Sources are staged privately; the supplied SDK, runtime archive and game build
remain unchanged. The baseline run intentionally fails the regression assertion.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shlex
import shutil
import subprocess

ROOT = Path(__file__).resolve().parents[2]
REL = Path('ps2xRuntime/src/lib/Kernel/Syscalls')
PATCH = ROOT / 'third_party/patches/ps2recomp/0113-cri-release-destroyed-rna-voices.patch'


def run(args):
    out = args.out.resolve()
    out.relative_to(ROOT)  # Stage only beneath this checkout; never mutate an external SDK.
    out.mkdir(parents=True, exist_ok=False)
    stage = out / 'sdk'
    files = [REL / name for name in ('RPC.cpp', 'RPC.h', 'Helpers/CriAudio.cpp',
             'Helpers/CriAudio.h', 'Helpers/ReoSoundBanks.h')]
    files += [Path('ps2xRuntime/src/lib') / name for name in
              ('cri_pcm_retire.h', 'vblank_music_diag.h')]
    for relative in files:
        target = stage / relative
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(args.sdk / relative, target)
    apply = ['git', 'apply', '--directory=' + stage.relative_to(ROOT).as_posix()]
    already = subprocess.run(apply + ['--reverse', '--check', str(PATCH)], cwd=ROOT,
                             capture_output=True).returncode == 0
    if args.baseline and already:
        subprocess.run(apply + ['--reverse', str(PATCH)], cwd=ROOT, check=True)
    elif not already:
        subprocess.run(apply + ['--check', str(PATCH)], cwd=ROOT, check=True)
        if not args.baseline:
            subprocess.run(apply + [str(PATCH)], cwd=ROOT, check=True)
    commands = json.loads((args.runtime_build / 'compile_commands.json').read_text())
    command = next(c for c in commands if c['file'].endswith('/Kernel/Syscalls/RPC.cpp'))
    template = command.get('arguments') or shlex.split(command['command'])
    objects = []
    for source in (Path(__file__).with_name('main.cpp'), stage / REL / 'RPC.cpp',
                   stage / REL / 'Helpers/CriAudio.cpp'):
        obj = out / (source.stem + '.o')
        compiler = list(template)
        compiler[compiler.index('-o') + 1] = str(obj)
        compiler[-1] = str(source)
        compiler[1:1] = ['-I' + str(stage / REL), '-I' + str(args.sdk / REL)]
        with (out / (source.stem + '.compile.log')).open('w') as log:
            subprocess.run(compiler, cwd=command['directory'], stdout=log,
                           stderr=subprocess.STDOUT, check=True)
        objects.append(str(obj))
    ninja = subprocess.check_output(['ninja', '-C', str(args.game_build), '-t',
                                      'commands', 'recomp/reo_recomp'], text=True)
    link = shlex.split(ninja.splitlines()[-1].split(' && ')[1])
    if any(a.startswith('@') for a in link):
        raise ValueError('Response-file link commands are not supported by this Mac runner')
    at = link.index('-o')
    executable = out / 'audio-transition-check'
    # Replace game objects, including main(), with the fixture and changed SDK
    # objects. Keep the existing runtime archive and its exact platform libraries.
    link = [a for a in link[:at] if not a.endswith('.o')] + ['-o', str(executable)] + objects + link[at + 2:]
    with (out / 'link.log').open('w') as log:
        subprocess.run(link, cwd=args.game_build, stdout=log, stderr=subprocess.STDOUT, check=True)
    environment = {key: value for key, value in os.environ.items()
                   if not key.startswith(('REO_', 'OPENSNAP_'))}
    with (out / 'runtime.log').open('w') as log:
        result = subprocess.run([str(executable)], cwd=out, env=environment,
                                stdout=log, stderr=subprocess.STDOUT)
    receipt = {'baseline': args.baseline, 'returncode': result.returncode,
               'sdk': str(args.sdk), 'patchSha256': hashlib.sha256(PATCH.read_bytes()).hexdigest(),
               'sourceSha256': {str(p): hashlib.sha256((stage / p).read_bytes()).hexdigest()
                                for p in files},
               'scope': 'Real RPC destroy and production PCM output; synthetic producer data; no game/device verification'}
    (out / 'result.json').write_text(json.dumps(receipt, indent=2) + '\n')
    print((out / 'runtime.log').read_text().splitlines()[-1])
    return result.returncode


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--sdk', type=lambda p: Path(p).resolve(), required=True,
                        help='SDK with the existing canonical release patches applied')
    parser.add_argument('--runtime-build', type=lambda p: Path(p).resolve(), required=True)
    parser.add_argument('--game-build', type=lambda p: Path(p).resolve(), required=True)
    parser.add_argument('--out', type=Path, required=True, help='Fresh directory beneath this checkout')
    parser.add_argument('--baseline', action='store_true')
    raise SystemExit(run(parser.parse_args()))
