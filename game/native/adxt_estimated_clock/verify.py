#!/usr/bin/env python3
"""Compare independent prepared clock against frozen original observations."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
BASE = ROOT / 'build-native-sjuni/adxt-estimated-clock'


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def wire(case):
    fields = ['mode', 'ratio', 'counter', 'rebase_mode', 'service_guard', 'drift_bits', 'estimate_base', 'tick_base', 'paused',
              'state', 'decoded', 'total', 'frequency', 'base', 'offset', 'depth_mode', 'depth_code', 'output_present',
              'output_bytes', 'rna_free_bytes']
    rows = [' '.join(str(int(case[k]) & 0xffffffff) for k in fields)]
    tick = case['tick']
    for op in case['operations']:
        tick = op.get('tick', tick)
        rows.append(f"{op['op']} {tick} {op.get('value', 0) & 0xffffffff}")
    return '\n'.join(rows) + '\n'


def expected(case):
    mapping = {'external_critical_enter': 0, 'external_critical_leave': 1, 'external_diagnostic': 2}
    rows = []
    for op in case['operations']:
        if op['result']['failure']:
            raise ValueError('Partial original is not a positive comparison')
        # These events are precisely the external observations qualified here;
        # no raw stack/register or per-write guest ABI claim is made.
        events = []
        for event in op['result']['events']:
            if event['kind'] not in mapping: continue
            # Reconstruct the actual original state at this observation from
            # its before image and ordered writes preceding the hook index.
            memory = [(0x600000, bytearray.fromhex(op['result']['before']['main_hex'])),
                      (0x630000, bytearray.fromhex(op['result']['before']['rna_hex'])),
                      (0x21b750, bytearray.fromhex(op['result']['before']['globals_hex']))]
            for write in op['result']['writes'][:event['write_index']]:
                for origin, data in memory:
                    at = write['address'] - origin; payload = bytes.fromhex(write['value_hex'])
                    if at >= 0 and at + len(payload) <= len(data): data[at:at + len(payload)] = payload
            main, rna, shared = [data for _, data in memory]
            word = lambda data, at: int.from_bytes(data[at:at + 4], 'little')
            events.append(dict(kind=mapping[event['kind']], estimate_base_u32=word(main, 0x9c),
                               tick_base_u32=word(main, 0xa0), paused_byte=main[0x72], rna_play_byte=rna[0x24],
                               mode_u32=word(shared, 0), counter_u32=word(shared, 12), drift_bits_u32=word(shared, 60)))
        value = op['result']['raw_v0_lower64_observation_only'] & 0xffffffff if op['op'] == 'centiseconds' else 0
        rows.append(dict(status=0, projection=op['projection'], value=value, events=events))
    return rows


def exclusion(case):
    if case['name'] == 'discard-unowned-service': return 'unowned worker service', 5
    if case['name'].startswith('zero-denominators-'): return 'native finite FP profile excludes zero divisor', 4
    return None


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cxx', required=True)
    parser.add_argument('--original', choices=['gcc-v1', 'llvm-v1'], required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    cc = shutil.which(args.cxx)
    out = args.output.resolve()
    if not cc or out.exists() or not out.is_relative_to(BASE):
        raise ValueError('Exact compiler and fresh scoped output required')
    manifest_path = HERE / 'manifest.json'
    manifest = json.loads(manifest_path.read_bytes())
    for name, digest in manifest['files'].items():
        if sha(ROOT / name) != digest: raise ValueError('Frozen implementation drift: ' + name)
    original = BASE / args.original
    receipt = json.loads((original / 'receipt.json').read_bytes())
    if receipt['source_postcheck'] or receipt['status'] != 'completed_literal_observations':
        raise ValueError('Original proof did not complete unchanged')
    for name, digest in receipt['outputs'].items():
        if sha(original / name) != digest: raise ValueError('Original output drift')
    data = BASE / 'frozen-v1/inputs.json'
    if sha(data) != receipt['inputs_sha256']: raise ValueError('Authored original input drift')
    cases = json.loads(data.read_bytes())['cases']
    wanted = {c['name']: c for c in json.loads((original / 'expected.json').read_bytes())}
    out.mkdir(parents=True)
    env = dict(os.environ)
    env['PATH'] = str(Path(cc).parent) + os.pathsep + env.get('PATH', '')
    report = dict(schema=1, status='running', compiler=cc, compiler_sha256=sha(Path(cc)),
                  implementation_manifest_sha256=sha(manifest_path), verifier_sha256=sha(Path(__file__)),
                  fixture_sha256=sha(HERE / 'fixture_runner.cpp'), original_receipt_sha256=sha(original / 'receipt.json'),
                  game_run=False, device_opened=False, checks=[], cases=[], negatives=[])
    shutil.copyfile(__file__, out / 'verify.source.py')
    flags = [cc, '-std=c++20', '-O2', '-Wall', '-Wextra', '-Wpedantic', '-Werror', '-fno-fast-math',
             '-ffp-contract=off', '-frounding-math', '-I' + str(HERE)]
    integer = ROOT / 'game/native/adxt_integer_clock/integer_clock.cpp'

    def run(name, command):
        process = subprocess.run([str(x) for x in command], cwd=ROOT, env=env, text=True, capture_output=True, timeout=60)
        (out / (name + '.txt')).write_text(process.stdout + process.stderr, encoding='utf-8', newline='\n')
        report['checks'].append(dict(name=name, command=[str(x) for x in command], exit_code=process.returncode, stdout=process.stdout))
        if process.returncode: raise RuntimeError(name + ': ' + process.stderr + process.stdout)
        return process.stdout

    def build(name, core, test):
        binary = out / (name + '.exe')
        run(name + '_compile', flags + [integer, core, test, '-o', binary])
        return binary

    def execute(binary, name, text):
        path = out / (name + '.input.txt')
        if not path.exists(): path.write_text(text, encoding='utf-8', newline='\n')
        process = subprocess.run([str(binary), str(path)], cwd=ROOT, env=env, text=True, capture_output=True, timeout=10)
        (out / (binary.stem + '-' + name + '.jsonl')).write_text(process.stdout, encoding='utf-8', newline='\n')
        if process.returncode: raise RuntimeError('Fixture failed: ' + process.stderr)
        return [json.loads(row) for row in process.stdout.splitlines()]

    try:
        units = build('units', HERE / 'estimated_clock.cpp', HERE / 'estimated_clock_tests.cpp')
        run('units', [units])
        binary = build('fixture', HERE / 'estimated_clock.cpp', HERE / 'fixture_runner.cpp')
        report['executable_sha256'] = sha(binary)
        for case in cases:
            name = case['name']; rows = execute(binary, name, wire(case)); excluded = exclusion(case)
            if excluded:
                if len(rows) != 1 or rows[0]['status'] != excluded[1] or rows[0]['events']:
                    raise ValueError('Expected explicit early native refusal: ' + name)
                initial = dict(output_u32=0x5a5a5a5a, denominator_u32=0x5a5a5a5a,
                               estimate_base_u32=case['estimate_base'], tick_base_u32=case['tick_base'],
                               paused_byte=case['paused'], rna_play_byte=0, mode_u32=case['mode'],
                               counter_u32=case['counter'], drift_bits_u32=case['drift_bits'])
                if rows[0]['projection'] != initial: raise ValueError('Refusal changed state: ' + name)
                report['cases'].append(dict(name=name, classification='native refusal; excluded from parity', reason=excluded[0]))
                continue
            expected_rows = expected(wanted[name])
            (out / (name + '.expected.json')).write_text(json.dumps(expected_rows, indent=2) + '\n', encoding='utf-8', newline='\n')
            if rows != expected_rows:
                mismatch = next((i, a, b) for i, (a, b) in enumerate(zip(rows, expected_rows)) if a != b) if len(rows) == len(expected_rows) else (len(rows), len(expected_rows))
                raise ValueError(name + ': ' + repr(mismatch))
            report['cases'].append(dict(name=name, classification='matched prepared clock state/output/control events', operations=len(rows)))
        text = (HERE / 'estimated_clock.cpp').read_text(encoding='utf-8')
        mutations = {
            'negative_threshold': ('60.0f < drift', '60.001f < drift'),
            'negative_refresh': ('state_.tick_base = tick;\n        }\n    } else', 'state_.tick_base = tick; value = state_.estimate_base;\n        }\n    } else')}
        for name, (anchor, replacement) in mutations.items():
            if text.count(anchor) != 1: raise ValueError('Mutation anchor changed')
            path = out / (name + '.cpp'); path.write_text(text.replace(anchor, replacement), encoding='utf-8', newline='\n')
            mutant = build(name, path, HERE / 'fixture_runner.cpp'); differences = []
            for case in cases:
                if exclusion(case): continue
                if execute(mutant, name + '-' + case['name'], wire(case)) != expected(wanted[case['name']]): differences.append(case['name'])
            if not differences: raise ValueError('Comparison missed clock negative: ' + name)
            report['negatives'].append(dict(name=name, differences=differences, variant_sha256=sha(path), executable_sha256=sha(mutant)))
        report['status'] = 'passed bounded prepared clock qualification'
    except Exception as error:
        report.update(status='failed', failure=str(error))
        raise
    finally:
        report['input_drift'] = [n for n, digest in manifest['files'].items() if sha(ROOT / n) != digest]
        if report['input_drift']: report.update(status='failed', failure='Source drift')
        (out / 'receipt.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8', newline='\n')
    print(json.dumps(dict(status=report['status'], receipt_sha256=sha(out / 'receipt.json'))))


if __name__ == '__main__': main()
