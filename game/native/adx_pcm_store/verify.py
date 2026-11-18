#!/usr/bin/env python3
"""PCM credit checks and private post-effect/ID fault controls; no game/device."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]


def sha(p):
    return hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--cxx', required=True)
    p.add_argument('--output', type=Path, required=True)
    a = p.parse_args()
    cc = shutil.which(a.cxx)
    out = a.output.resolve()
    if not cc or out.exists() or not out.is_relative_to(ROOT / 'build-native-sjuni/adx-pcm-store'):
        raise ValueError('Exact compiler and fresh scoped output required')
    freeze = json.loads((HERE / 'frozen_identity.json').read_bytes())
    for n, digest in freeze['files'].items():
        if sha(ROOT / n) != digest:
            raise ValueError('Frozen source drift: ' + n)
    out.mkdir(parents=True)
    env = dict(os.environ)
    env['PATH'] = str(Path(cc).parent) + os.pathsep + env.get('PATH', '')
    tracked = [ROOT / n for n in freeze['files']] + [HERE / 'pcm_store_tests.cpp', HERE / 'verify.py', HERE / 'frozen_identity.json']
    inputs = {str(n.relative_to(ROOT)): sha(n) for n in tracked}
    receipt = dict(schema=1, status='running', compiler=cc, compiler_sha256=sha(Path(cc)),
                   inputs=inputs, checks=[], game_run=False, device_opened=False,
                   whole_window2_parity=False)

    def run(name, command, expected=0):
        command = [str(v) for v in command]
        r = subprocess.run(command, cwd=ROOT, env=env, capture_output=True, text=True, timeout=90)
        (out / (name + '.txt')).write_text(r.stdout + r.stderr, encoding='utf-8', newline='\n')
        receipt['checks'].append(dict(name=name, command=command, exit_code=r.returncode,
                                      expected=expected, stdout=r.stdout))
        if r.returncode != expected:
            raise RuntimeError(name + ':\n' + r.stdout + r.stderr)

    try:
        flags = [cc, '-std=c++20', '-O1', '-Wall', '-Wextra', '-Wpedantic', '-Werror', '-I' + str(HERE)]
        deps = [ROOT / 'game/native/sjrb/sjrb.cpp', HERE / 'pcm_store_tests.cpp']
        exe = out / 'units.exe'
        run('compile', flags + [HERE / 'pcm_store.cpp'] + deps + ['-o', exe])
        run('units', [exe])
        receipt['executable_sha256'] = sha(exe)
        source = (HERE / 'pcm_store.cpp').read_text(encoding='utf-8')
        anchor = 'producer_[c] = suffix;'
        if source.count(anchor) != 1:
            raise ValueError('Post-prefix fault anchor changed')
        injected = source.replace(anchor, anchor + '\n        if (c == 0) return fail(); // private post-effect fault')
        negative = injected.replace('if (c == 0) return fail(); // private post-effect fault',
                                    'if (c == 0) (void)Status::ring_failure; // negative: ignore injected failure')
        constructor_anchor = 'domain_->channels = config.channels;'
        if source.count(constructor_anchor) != 1:
            raise ValueError('ID fault anchor changed')
        exhausted = source.replace(constructor_anchor, constructor_anchor +
            '\n    last_write_ = last_read_ = std::numeric_limits<std::uint64_t>::max();')
        for name, text, argument, expected in [('posteffect', injected, 'posteffect', 0),
                                               ('negative_ignore_error', negative, 'posteffect', 1),
                                               ('ids', exhausted, 'ids', 0)]:
            path = out / (name + '.cpp')
            path.write_text(text, encoding='utf-8', newline='\n')
            binary = out / (name + '.exe')
            run(name + '_compile', flags + [path] + deps + ['-o', binary])
            run(name, [binary, argument], expected)
            receipt.setdefault('private_variant_sha256', {})[name] = sha(path)
        receipt['status'] = 'passed'
    except Exception as e:
        receipt.update(status='failed', failure=str(e))
        raise
    finally:
        receipt['inputs_postcheck'] = [n for n, digest in inputs.items() if sha(ROOT / n) != digest]
        if receipt['inputs_postcheck']:
            receipt.update(status='failed', failure='Source drift')
        (out / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8', newline='\n')
    print(json.dumps(dict(status=receipt['status'], receipt=str(out / 'receipt.json'), sha256=sha(out / 'receipt.json'))))


if __name__ == '__main__':
    main()
