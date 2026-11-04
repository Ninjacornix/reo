"""Test both production subtitle hooks and their real Windows IPC.

No owned game data is needed for the default bridge checks.
"""
import argparse
import os
from pathlib import Path
import shutil
import subprocess

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--compiler', default=shutil.which('clang++'))
parser.add_argument('--owned-queue', action='store_true', help='Also execute locally generated guest queue functions')
args = parser.parse_args()
if not args.compiler:
    parser.error('Provide --compiler or put clang++ on PATH')
root = Path(__file__).resolve().parents[2]
output = root / 'build-ninja/subtitle-toggle/native'
output.mkdir(parents=True, exist_ok=True)
environment = os.environ.copy()
environment['PATH'] = str(Path(args.compiler).resolve().parent) + os.pathsep + environment['PATH']
for game in ('file1', 'file2'):
    executable = output / (game + '.exe')
    command = [args.compiler, '-std=c++20', '-O2', '-Wall', '-Wextra',
               '-DREO_GAME_' + game.upper(), str(Path(__file__).with_name('check.cpp')),
               '-o', str(executable)]
    if args.owned_queue:
        from owned_queue import stage
        stage(root, output / game, game)
        command += ['-DREO_GENERATED_QUEUE', '-I', str(output / game)]
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
