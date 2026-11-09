#!/usr/bin/env python3
"""Use the sealed game's raylib, with bounded owned-window probes; no game/audio."""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('compiler', 'raylib', 'include', 'output'):
        parser.add_argument('--' + name, type=Path, required=True)
    args = parser.parse_args()
    if args.output.exists():
        raise ValueError('Fresh evidence directory required')
    args.output.mkdir(parents=True)
    source = Path(__file__).with_name('minimized_window_close.cpp')
    binary = args.output.resolve() / 'probe.exe'
    command = [str(args.compiler.resolve()), '-std=c++20', '-O2', '-Wall', '-Wextra', '-Werror',
               '-I' + str(args.include.resolve()), str(source), str(args.raylib.resolve()),
               '-o', str(binary), '-lwinmm', '-lgdi32', '-lopengl32', '-luser32', '-static']
    build = subprocess.run(command, capture_output=True)
    (args.output / 'compile.stdout.txt').write_bytes(build.stdout)
    (args.output / 'compile.stderr.txt').write_bytes(build.stderr)
    build.check_returncode()
    results = {}
    for case in ('baseline', 'fixed'):
        try:
            run = subprocess.run([str(binary), case], capture_output=True, timeout=4)
            item = dict(exit_code=run.returncode, timed_out=False,
                        stdout=run.stdout.decode(errors='replace'), stderr=run.stderr.decode(errors='replace'))
        except subprocess.TimeoutExpired as error:
            # subprocess.run terminates and joins only this synthetic child.
            item = dict(exit_code=None, timed_out=True, stdout=(error.stdout or b'').decode(errors='replace'),
                        stderr=(error.stderr or b'').decode(errors='replace'))
        results[case] = item
    fixed = results['fixed']
    passed = results['baseline']['timed_out'] and fixed['exit_code'] == 0
    if passed:
        sample = json.loads(fixed['stdout'])
        passed = sample['always_run'] and sample['minimized_observed'] and sample['close_observed']
    record = dict(status='passed' if passed else 'failed', source_sha256=sha(source),
                  runner_sha256=sha(Path(__file__)), compiler_sha256=sha(args.compiler),
                  raylib_sha256=sha(args.raylib), header_sha256=sha(args.include / 'raylib.h'),
                  binary_sha256=sha(binary), compile_command=command, cases=results,
                  game_launched=False, audio_device_opened=False, focus_requested=False,
                  limitations=['Synthetic regression; actual patched game retirement is a separate test.',
                               'Foreground identity may change if the user changes applications.'])
    (args.output / 'receipt.json').write_text(json.dumps(record, indent=2) + '\n', encoding='utf8')
    print(json.dumps(dict(status=record['status'], cases=results)))
    raise SystemExit(0 if passed else 1)


if __name__ == '__main__':
    main()
