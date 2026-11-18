#!/usr/bin/env python3
"""Apply the public dependency series to a fresh private pinned checkout only.

Does not modify the active dependency checkout, build libraries or run a game.
Preserves partial audit trees on failure. Receipts identify patches and resulting
source files; patch applicability alone does not establish compiled-library ABI.
"""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[2]
PIN = 'c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f'


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--checkout', required=True, type=Path)
    args = parser.parse_args()
    checkout = args.checkout.resolve()
    allowed = ROOT / 'build-native-sjuni'
    if not checkout.is_relative_to(allowed) or checkout == allowed:
        raise ValueError('Audit only a fresh separate checkout below build-native-sjuni')

    def git(*arguments):
        return subprocess.run(['git', '-C', str(checkout), *arguments], text=True, capture_output=True)

    top, revision, dirty = git('rev-parse', '--show-toplevel'), git('rev-parse', 'HEAD'), git('status', '--porcelain=v1')
    if (top.returncode or revision.returncode or dirty.returncode or Path(top.stdout.strip()).resolve() != checkout or
        revision.stdout.strip() != PIN or dirty.stdout.strip()):
        raise ValueError('A clean independent checkout at the recorded pin is required')
    patches = sorted((ROOT / 'third_party/patches/ps2recomp').glob('*.patch'))
    if not patches:
        raise ValueError('Public dependency patch directory is empty or unavailable')
    receipt = dict(schema=1, status='running', base_revision=PIN, checkout=str(checkout),
                   active_checkout_modified=False, game_launched=False, libraries_built=False, patches=[])
    output = checkout.parent / (checkout.name + '-receipt.json')
    try:
        for patch in patches:
            entry = dict(path=patch.relative_to(ROOT).as_posix(), sha256=sha(patch))
            receipt['patches'].append(entry)
            check = git('apply', '--check', str(patch))
            entry['check_exit_code'] = check.returncode
            entry['check_stderr'] = check.stderr
            if check.returncode:
                raise RuntimeError('Patch check failed: ' + patch.name)
            applied = git('apply', str(patch))
            entry['apply_exit_code'] = applied.returncode
            entry['apply_stderr'] = applied.stderr
            if applied.returncode:
                raise RuntimeError('Patch application failed: ' + patch.name)
        receipt['source_sha256'] = {p.relative_to(checkout).as_posix(): sha(p)
                                    for p in sorted(checkout.rglob('*')) if p.is_file() and
                                    p.relative_to(checkout).parts[0] != '.git'}
        receipt['source_scope'] = 'checkout source files; excludes .git administration'
        receipt['status'] = 'passed'
    except Exception as error:
        receipt['status'] = 'failed'
        receipt['failure'] = str(error)
        raise
    finally:
        receipt['applied_count'] = sum(p.get('apply_exit_code') == 0 for p in receipt['patches'])
        output.write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8')
        print(json.dumps({k: receipt[k] for k in ('status', 'base_revision', 'applied_count')}))
        print('Receipt: ' + str(output))


if __name__ == '__main__':
    main()
