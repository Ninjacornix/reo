"""Compile both game audio bridges and test actual Windows launcher IPC.

Use --compiler with the portable LLVM MinGW C++ compiler, or put clang++ on PATH.
No game executable, audio device, or owned game data is required.
"""
import argparse
import os
from pathlib import Path
import shutil
import subprocess

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--compiler', default=shutil.which('clang++'))
args = parser.parse_args()
if not args.compiler:
    parser.error('Provide --compiler or put clang++ on PATH')
root = Path(__file__).resolve().parents[2]
output = root / 'build-ninja/audio_bridge_check'
output.mkdir(parents=True, exist_ok=True)
environment = os.environ.copy()
environment['PATH'] = str(Path(args.compiler).resolve().parent) + os.pathsep + environment['PATH']
for game in ('file1', 'file2'):
    executable = output / (game + '.exe')
    command = [args.compiler, '-std=c++20', '-O2', '-Wall', '-Wextra', '-DREO_GAME_' + game.upper(),
               str(Path(__file__).with_suffix('.cpp')),
               str(Path(__file__).with_name('bridge_api_consumer.cpp')), '-o', str(executable)]
    result = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    (output / (game + '-build.log')).write_text(result.stdout)
    if result.returncode:
        raise SystemExit(result.stdout)
    result = subprocess.run([str(executable)], env=environment, stdout=subprocess.PIPE,
                            stderr=subprocess.STDOUT, text=True)
    (output / (game + '-test.log')).write_text(result.stdout)
    print(game, result.stdout.strip())
    if result.returncode:
        raise SystemExit(result.returncode)
