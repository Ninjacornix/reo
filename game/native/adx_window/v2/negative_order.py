#!/usr/bin/env python3
"""Whole-owner negative: return encoded credit before stores; finals still match."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import compare_original as comparison

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[3]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cxx', required=True)
    parser.add_argument('--implementation', type=Path, required=True)
    parser.add_argument('--matched', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    cc = shutil.which(args.cxx)
    out = args.output.resolve()
    if not cc or out.exists() or not out.is_relative_to(ROOT / 'build-native-sjuni/window2'):
        raise ValueError('Exact compiler and fresh scoped output required')
    manifest_path = args.implementation / 'manifest.json'
    manifest = json.loads(manifest_path.read_bytes())
    for name, digest in manifest['files'].items():
        if sha(ROOT / name) != digest:
            raise ValueError('Implementation drift: ' + name)
    prior = json.loads((args.matched / 'receipt.json').read_bytes())
    if prior['input_drift'] or not prior['status'].startswith('passed'):
        raise ValueError('Prior actual matched comparison required')
    out.mkdir(parents=True)
    text = (HERE / 'stream_window.cpp').read_text(encoding='utf-8')
    credit = ('    phase_ = Phase::encoded_credit;\n'
              '    if (!finish_input({source::FinishKind::consume_single_prefix, engine_.consumed_bytes})) return fail(Status::source_failure);\n')
    if text.count(credit) != 1 or text.count('    phase_ = Phase::staged_pcm;') != 1:
        raise ValueError('Whole-order mutation anchor changed')
    text = text.replace(credit, '').replace('    phase_ = Phase::staged_pcm;', credit + '    phase_ = Phase::staged_pcm;')
    private = out / 'early_credit.cpp'
    private.write_text(text, encoding='utf-8', newline='\n')
    command = prior['compile_command'][:]
    command[0] = cc
    command[command.index('game/native/adx_window/v2/stream_window.cpp')] = str(private)
    command[-1] = str(out / 'fixture.exe')
    command.insert(1, '-I' + str(HERE))
    env = dict(os.environ)
    env['PATH'] = str(Path(cc).parent) + os.pathsep + env.get('PATH', '')
    report = dict(schema=1, status='running', implementation_manifest_sha256=sha(manifest_path),
                  matched_receipt_sha256=sha(args.matched / 'receipt.json'), compiler_sha256=sha(Path(cc)),
                  verifier_sha256=sha(Path(__file__)), comparator_sha256=sha(HERE / 'compare_original.py'),
                  variant_sha256=sha(private), game_run=False, device_opened=False, cases=[])
    try:
        process = subprocess.run(command, cwd=ROOT, env=env, text=True, capture_output=True, timeout=90)
        (out / 'compile.txt').write_text(process.stdout + process.stderr, encoding='utf-8', newline='\n')
        if process.returncode:
            raise RuntimeError(process.stderr)
        report.update(compile_command=command, executable_sha256=sha(out / 'fixture.exe'))
        for name in ['long-mono-44100', 'pcm-tail-stereo-total-33-free-96', 'file-loop-first-and-repeat']:
            descriptor = next(c for c in prior['cases'] if c['name'] == name)
            if not descriptor['classification'].startswith('matched'):
                raise ValueError('Negative case lacks actual positive comparison')
            wire = args.matched / (name + '.input.txt')
            if sha(wire) != descriptor['wire_sha256']:
                raise ValueError('Authored wire input drift')
            wanted = json.loads((args.matched / (name + '.expected.json')).read_bytes())
            process = subprocess.run([str(out / 'fixture.exe'), str(wire)], cwd=ROOT, env=env,
                                     text=True, capture_output=True, timeout=60)
            (out / (name + '.native.jsonl')).write_text(process.stdout, encoding='utf-8', newline='\n')
            if process.returncode:
                raise RuntimeError(process.stderr)
            actual = [json.loads(row) for row in process.stdout.splitlines()]
            for row in actual:
                if row.pop('status', 0) not in (0, 1, 2):
                    raise ValueError('Mutation refused instead of completing')
            final_actual = [r for r in actual if r['kind'] == 'end']
            final_expected = [r for r in wanted if r['kind'] == 'end']
            if final_actual != final_expected:
                raise ValueError('Negative changed stable operation results: ' + name)
            mismatch, _ = comparison.compare_records(actual, wanted)
            if not mismatch:
                raise ValueError('Whole-owner comparison failed to detect early credit: ' + name)
            report['cases'].append(dict(name=name, stable_results_match=True,
                                        stable_results=len(final_actual), detected_mismatch=mismatch))
        report['status'] = 'passed: all stable results match; all three whole-order mutants detected'
    except Exception as error:
        report.update(status='failed', failure=str(error))
        raise
    finally:
        report['input_drift'] = [n for n, digest in manifest['files'].items() if sha(ROOT / n) != digest]
        if report['input_drift']:
            report.update(status='failed', failure='Source drift')
        (out / 'receipt.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8', newline='\n')
    print(json.dumps(dict(status=report['status'], receipt_sha256=sha(out / 'receipt.json'))))


if __name__ == '__main__':
    main()
