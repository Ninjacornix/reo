"""Compile real private game units with a separately prepared cold-path header.

Uses recorded commands from the full reference build, preserves O2/FP flags,
and writes only to the candidate's private experiment directory.
"""
import json
import os
from pathlib import Path
import subprocess
import sys
import time

from benchmark_compilation import load


def main():
    repo = Path(__file__).resolve().parents[2]
    candidate = Path(sys.argv[1]).resolve()
    label = sys.argv[2]
    if Path(label).name != label:
        raise ValueError('Use a simple experiment name')
    names = sys.argv[3:] or ['main5']
    out = candidate.parent / label
    out.mkdir(exist_ok=False)
    full = repo / 'build-ninja/compile-full-20261020'
    events = [json.loads(line) for line in (full / 'old/commands.jsonl').read_text().splitlines()]
    units = {Path(row['command'][-1]).stem: row['command'] for row in events
             if row['stage'] == 'compile' and row['event'] == 'begin'}
    if not set(names).issubset(units):
        raise ValueError('Requested units have no recorded baseline command')
    reference = next(row['command'] for row in events if row['stage'] == 'pch' and row['event'] == 'begin')
    # The original header search paths stay present, with only this one shadow
    # header first. Runtime source and the active private kit are never edited.
    header = out / 'candidate.hpp'
    header.write_bytes(Path(reference[reference.index('c++-header')+1]).read_bytes())
    pch = out / 'candidate.pch'
    command = reference[:]
    command[command.index('c++-header')+1] = str(header)
    command[command.index('-o')+1] = str(pch)
    extra = (['-ivfsoverlay', str(candidate / 'overlay.json')] if (candidate / 'overlay.json').is_file()
             else ['-I'+str(candidate)])
    command[1:1] = extra
    kit = repo / 'build-ninja/import-optimized-20261020/kit'
    paths = json.loads((repo / 'build-ninja/import-profile-20261020/paths.json').read_text())
    os.environ['REO_LLVM_MINGW'] = paths['compiler']
    worker = load('coldpath_reference_worker', kit / 'tools/local_build/compile_game.py')
    env, _ = worker.portable_environment(kit, json.loads((kit / 'compile-plan.json').read_text()))
    rows = []

    def run(name, command):
        started = time.perf_counter()
        with (out / (name+'.log')).open('wb') as log:
            process = subprocess.run(command, env=env, stdout=log, stderr=subprocess.STDOUT)
        row = {'name': name, 'seconds': time.perf_counter()-started, 'exit': process.returncode, 'command': command}
        rows.append(row)
        (out / 'results.json').write_text(json.dumps({'gameExecuted': False, 'acceptedForRelease': False,
            'concurrentFullBuild': json.loads((full/'results.json').read_text())['status']=='running', 'rows': rows}, indent=2))
        print(name, f"{row['seconds']:.3f}s", 'exit', process.returncode, flush=True)
        if process.returncode:
            raise RuntimeError(f'Candidate compile failed; see {out / (name+".log")}')

    run('pch', command)
    for name in names:
        command = units[name][:]
        command[command.index('-o')+1] = str(out / (name+'.obj'))
        command[command.index('-include-pch')+1] = str(pch)
        command[1:1] = extra
        run(name, command)


if __name__ == '__main__':
    main()
