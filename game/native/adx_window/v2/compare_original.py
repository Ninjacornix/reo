#!/usr/bin/env python3
"""Whole draft comparison from plain original snapshots; no expected native input."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[3]
ORIGINAL = ROOT / 'build-native-sjuni/adx-window-v2-oracle'
INPUT, PCM, PCM_PHYSICAL = 0x400010, 0x410010, 16576


def sha(path): return hashlib.sha256(path.read_bytes()).hexdigest()
def encode(v): return (json.dumps(v, sort_keys=True, separators=(',', ':')) + '\n').encode()
def load(p): return json.loads(p.read_bytes())


def project(state):
    i, p, o, m, f, k = (bytes.fromhex(state[n]) for n in ('inner_hex', 'predictor_hex', 'outer_hex', 'main_hex', 'source_hex', 'key_global_hex'))
    u = lambda data, at, size=4: int.from_bytes(data[at:at + size], 'little')
    s = lambda data, at, size=4: int.from_bytes(data[at:at + size], 'little', signed=True)
    coordinate = lambda pointer, role, base: [role, pointer - base] if pointer else [0, 0]
    span = lambda pointer, n, role, base: coordinate(pointer, role, base) + [n]
    channels = o[2]
    return dict(outer=dict(phase=o[1], endflag=o[3], input=span(u(o, 0x14), s(o, 0x18), 1, INPUT),
        pcm=[span(u(o, 0x1c + 8 * c), s(o, 0x20 + 8 * c), 2 + c, PCM + c * PCM_PHYSICAL) for c in range(channels)],
        counters=[s(o, x) for x in (0x2c, 0x30, 0x34, 0x38, 0x3c, 0x40, 0x44)], header_bytes=u(o, 0x98)),
        inner=dict(phase=u(i, 4), input=coordinate(u(i, 0x48), 1, INPUT),
            values=[s(i, x) for x in (0x4c, 0x68, 0x6c, 0x70, 0x88, 0x8c, 0x90, 0x94)],
            request_settings=[s(i, x) for x in (0xb4, 0xb8, 0xc0, 0xc4)]),
        predictor=dict(phase=u(p, 0xc), completed=u(p, 0x10), mode=u(p, 0x14),
            input=coordinate(u(p, 0x18), 1, INPUT), requested=u(p, 0x1c),
            left=coordinate(u(p, 0x20), 2, PCM), right=coordinate(u(p, 0x24), 3, PCM + PCM_PHYSICAL),
            history=list(struct.unpack_from('<4h', p, 0x28)), coefficients=list(struct.unpack_from('<2h', p, 0x30)),
            key=list(struct.unpack_from('<3H', p, 0x34))),
        header=dict(phase=u(i, 2, 2), base=[s(i, 0xc, 1), s(i, 0xd, 1), s(i, 0xf, 1), s(i, 0xe, 1), u(i, 0x14), u(i, 0x18), s(i, 0x10)],
            filter=s(i, 0x1c, 2), tag=s(i, 0x98, 2), configured_key=list(struct.unpack_from('<3H', i, 0x9c)),
            loop=[s(i, 0x20), u(i, 0x24, 2), u(i, 0x26, 2), *[u(i, a) for a in (0x28, 0x2c, 0x30, 0x34)]],
            ainf=dict(value=u(i, 0xc8), payload=i[0xcc:0xdc].hex(), halves=[u(i, a, 2) for a in (0xdc, 0xde, 0xe0)]),
            borrowed_pcm=[s(i, 0x40), s(i, 0x44), int(u(i, 0x3c) == PCM)],
            active_pcm=[s(i, 0x60), s(i, 0x64), int(u(i, 0x5c) == PCM)],
            output_channels=s(i, 0x38), active=[s(i, a) for a in (0x50, 0x54, 0x58)]),
        main=[m[1], s(m, 0x50), s(m, 0x8c), s(m, 0x90), s(m, 0x4c), s(m, 0xa4), m[0x98], s(m, 0x48)],
        saved_history=[s(i, at, 2) for at in (0xa8, 0xac, 0xaa, 0xae)], saved_key=list(struct.unpack_from('<3H', i, 0xa2)),
        source=[s(f, 1, 1), s(f, 0x1c), s(f, 0x54), s(f, 0x30), s(f, 3, 1), u(f, 0x40, 1), u(f, 2, 1),
                u(f, 0x43, 1), u(f, 0x44, 1), u(f, 0x42, 1), int(u(f, 8) != 0 and u(f, 0x45, 1) == 1),
                u(f, 0x20) - INPUT if u(f, 0x20) else 0, s(f, 0x24)],
        source_loop=[s(o, 0x3c), s(f, 0x2c), m[0x6c], s(i, 0x2c), s(i, 0x34), s(i, 0x28), s(i, 0x30)],
        rings=[[q[n] for n in (8, 9, 3, 4, 5, 6, 10, 11, 12, 13)] for q in state['rings']], odd=state['odd_u32'],
        keys=[u(k, 0), *[u(k, at, 2) for at in (0x10, 0x12, 0x14)]])


def difference(a, b, path='root'):
    if type(a) != type(b): return path + ': type ' + type(a).__name__ + '/' + type(b).__name__
    if isinstance(a, dict):
        if a.keys() != b.keys(): return path + ': keys'
        for k in a:
            found = difference(a[k], b[k], path + '.' + k)
            if found: return found
    elif isinstance(a, list):
        if len(a) != len(b): return path + ': length ' + str(len(a)) + '/' + str(len(b))
        for n, (x, y) in enumerate(zip(a, b)):
            found = difference(x, y, path + '[' + str(n) + ']')
            if found: return found
    elif a != b: return path + ': ' + str(a)[:90] + '/' + str(b)[:90]
    return None


def compare_records(actual, wanted):
    """Relate live owned credit to the original's separately saved descriptor.

    At130A50 Get(0) writes a stack descriptor. The original copies it into the
    file record only at130AD8/130ADC, AFTER the Ring leave observation. Source2
    exposes its actual acquired Chunk at that observation. Do not fake a cached
    file record or change either raw transcript. Check the measured free-credit
    delta/offset directly, and explicitly exclude only those two cached fields
    at this one transfer boundary. All stable descriptors still compare fully.
    """
    if len(actual) != len(wanted): return difference(actual, wanted), []
    exclusions = []
    for n, (a, b) in enumerate(zip(actual, wanted, strict=True)):
        before_a, before_b = (actual[n - 1], wanted[n - 1]) if n else ({}, {})
        get_free_leave = (a.get('kind') == b.get('kind') == 'L' and a.get('ring') == b.get('ring') == 0 and
            before_a.get('kind') == before_b.get('kind') == 'E' and before_a.get('ring') == before_b.get('ring') == 0 and
            before_a.get('action') == before_b.get('action') == a['action'] == b['action'])
        if get_free_leave:
            delta_a = before_a['state']['rings'][0][3] - a['state']['rings'][0][3]
            delta_b = before_b['state']['rings'][0][3] - b['state']['rings'][0][3]
            get_free_leave = delta_a > 0 and delta_b > 0
        if get_free_leave:
            owned = a['state']['source'][11:13]; cache = b['state']['source'][11:13]
            if delta_a != delta_b or owned != [before_a['state']['rings'][0][4], delta_a]:
                return f'root[{n}]: acquired source ownership disagrees with measured free-credit transfer', exclusions
            if cache != before_b['state']['source'][11:13]:
                return f'root[{n}]: original saved descriptor was not the measured pre-Get cache', exclusions
            exclusions.append(dict(record=n, action=a['action'], fields=['file_record_cached_producer_offset', 'file_record_cached_producer_bytes'],
                native_live_owned_descriptor=owned, original_pre_copy_cache=cache, measured_acquired_bytes=delta_a,
                evidence='actual130A50 stack Get; actual130AD8/130ADC later file-record copies'))
            # New comparison views only. The saved native/original rows remain
            # verbatim and no count, flag, sample or PCM value is normalized.
            av = json.loads(json.dumps(a)); bv = json.loads(json.dumps(b))
            av['state']['source'] = av['state']['source'][:11]
            bv['state']['source'] = bv['state']['source'][:11]
            mismatch = difference(av, bv, f'root[{n}]')
        else:
            mismatch = difference(a, b, f'root[{n}]')
        if mismatch: return mismatch, exclusions
    return None, exclusions


def commands(c):
    if 'expected' in json.dumps(c): raise ValueError('Expected output entered native inputs')
    initial = c.get('initial_pcm_bytes', [0] * c['channels'])
    if len(set(initial)) != 1: raise ValueError('Asymmetric constructor outside profile')
    lines = [' '.join(map(str, [c['channels'], c['downmix'], c['loop_enabled'], c['seamless'], c['position'], c['seed_bytes'], initial[0], c['file_hex']]))]
    for n, a in enumerate(c['actions']):
        kind = a['kind']; values = []
        if kind == 'source':
            if a['entry'] != 0x130b78: raise ValueError('Complete lifecycle entry required')
            values = [a['statuses'][0], -999 if a['accept'] == 'requested' else a['accept'], int(a['statuses'][1] == 3), int(a['inline_write'])]
        elif kind == 'consume_pcm': values = [a['bytes']]
        elif kind == 'write_job': values = [a['id']]
        elif kind == 'call' and a['entry'] == 'source_stop': kind = 'source_stop'
        elif kind not in ('header', 'ready', 'decode'): raise ValueError('Unimplemented transport action ' + kind)
        lines.append(' '.join(map(str, [n, kind, *values])))
    return '\n'.join(lines) + '\n'


def expected_rows(c, original, observed):
    backings = [bytearray.fromhex(h) for h in original['initial_backings_hex']]
    hashes = lambda: [hashlib.sha256(b[16:-16]).hexdigest() for b in backings[1:]]
    rows = [dict(action=-1, kind='end', state=project(original['initial']), pcm_backings=[b[16:-16].hex() for b in backings[1:]], pcm_backing_sha256=hashes())]
    for n, operation in enumerate(original['operations']):
        if c['actions'][n]['kind'] != 'consume_pcm':
            for event in observed['events']:
                if event['action'] != n: continue
                row = {k: v for k, v in event.items() if k != 'state'}; row['state'] = project(event['state']); rows.append(row)
        results = operation['results'] if isinstance(operation['results'], list) else [operation['results']]
        for result in results:
            if result['failure']: raise ValueError('Partial original entered admitted whole comparison')
            for backing, effect in zip(backings, result['backing_effects'], strict=True):
                if hashlib.sha256(backing).hexdigest() != effect['before_sha256']: raise ValueError('Backing preimage changed')
                for change in effect['changes']:
                    at = change['offset']; before = bytes.fromhex(change['before_hex']); after = bytes.fromhex(change['after_hex'])
                    if backing[at:at + len(before)] != before or len(before) != len(after): raise ValueError('Invalid original delta')
                    backing[at:at + len(after)] = after
                if hashlib.sha256(backing).hexdigest() != effect['after_sha256']: raise ValueError('Backing postimage changed')
        rows.append(dict(action=n, kind='end', state=project(results[-1]['after']), pcm_backings=[b[16:-16].hex() for b in backings[1:]], pcm_backing_sha256=hashes()))
    return rows


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--cxx', required=True); p.add_argument('--implementation', type=Path, required=True)
    p.add_argument('--observations', type=Path, required=True); p.add_argument('--output', type=Path, required=True)
    p.add_argument('--case', action='append'); a = p.parse_args(); cc = shutil.which(a.cxx); out = a.output.resolve()
    if not cc or out.exists() or not out.is_relative_to(ROOT / 'build-native-sjuni/window2'):
        raise ValueError('Exact compiler and fresh scoped output required')
    impl = load(a.implementation / 'manifest.json')
    for n, digest in impl['files'].items():
        if sha(ROOT / n) != digest: raise ValueError('Draft implementation drift: ' + n)
    receipt = load(a.observations / 'receipt.json')
    if not receipt['original_transcripts_unchanged']: raise ValueError('Original instrumentation changed execution')
    cases = load(ORIGINAL / 'frozen-v3/inputs.json')['cases']; descriptors = {r['name']: r for r in receipt['cases']}
    if a.case and set(a.case) - descriptors.keys(): raise ValueError('Unknown selected observations')
    out.mkdir(parents=True); env = dict(os.environ); env['PATH'] = str(Path(cc).parent) + os.pathsep + env.get('PATH', '')
    sources = ['game/native/sjrb/sjrb.cpp', 'game/native/adxt_shared_source/shared_source.cpp', 'game/native/adxt_refill/adxt_refill.cpp',
        'game/native/resource_io/async_read_owner.cpp', 'game/native/tasks/serial_worker.cpp', 'game/native/resources/resource_session.cpp',
        'game/native/resources/virtual_file_view.cpp', 'game/native/resources/bounded_view.cpp', 'game/native/adx_header/adx_header.cpp',
        'game/native/adx_workspace/adx_workspace.cpp', 'game/native/adx_pcm_store/v2/pcm_store.cpp',
        'game/native/adx_window/v2/stream_window.cpp', 'game/native/adx_window/v2/fixture_runner.cpp']
    binary = out / 'fixture.exe'; flags = [cc, '-std=c++20', '-O1', '-pthread', '-Wall', '-Wextra', '-Wpedantic', '-Werror',
        '-Wno-misleading-indentation', '-fno-fast-math', '-ffp-contract=off', '-frounding-math', '-I' + str(ROOT)]
    report = dict(schema=1, status='running', compiler=cc, compiler_sha256=sha(Path(cc)),
        implementation_manifest_sha256=sha(a.implementation / 'manifest.json'), original_observation_receipt_sha256=sha(a.observations / 'receipt.json'),
        runner_sha256=sha(HERE / 'fixture_runner.cpp'), comparator_sha256=sha(Path(__file__)),
        hash_helper_sha256=sha(ROOT / 'recomp/overrides/native_geometry/reo_vu_native_sha256.h'), cases=[], game_run=False)
    try:
        command = flags + sources + ['-o', str(binary)]; built = subprocess.run(command, cwd=ROOT, env=env, capture_output=True, text=True, timeout=90)
        (out / 'build.txt').write_text(built.stdout + built.stderr, encoding='utf-8', newline='\n')
        if built.returncode: raise RuntimeError(built.stderr)
        report.update(compile_command=command, executable_sha256=sha(binary))
        for c in cases:
            name = c['name']
            if name not in descriptors or a.case and name not in a.case: continue
            descriptor = descriptors[name]; captured_path = a.observations / (name + '.json')
            if sha(captured_path) != descriptor['sha256']: raise ValueError('Capture drift')
            captured = load(captured_path); original_path = ORIGINAL / 'gcc-v2' / (name + '.json')
            if sha(original_path) != captured['original_transcript_sha256']: raise ValueError('Different original execution')
            original = load(original_path)
            # These are declared gaps, never counted as parity/refusal successes.
            exclusion = None
            if not c.get('file_present', True): exclusion = 'outside file-backed constructor profile'
            elif name.startswith('pcm-asymmetric-'): exclusion = 'asymmetric channel constructor not represented'
            elif any(a['kind'] == 'call' and a['entry'] != 'source_stop' for a in c['actions']): exclusion = 'outside direct helper-call transport profile'
            elif name == 'seamless-short-end-record': exclusion = 'malformed marker loses original descriptor; owned fault policy pending comparison'
            elif any(r.get('failure') for op in original['operations'] for r in (op['results'] if isinstance(op['results'], list) else [op['results']])):
                exclusion = 'explicit original partial/unqualified branch'
            if exclusion:
                report['cases'].append(dict(name=name, classification='excluded_not_parity', reason=exclusion)); continue
            wire = out / (name + '.input.txt'); wire.write_text(commands(c), encoding='utf-8', newline='\n')
            wanted = expected_rows(c, original, captured); (out / (name + '.expected.json')).write_bytes(encode(wanted))
            ran = subprocess.run([str(binary), str(wire)], cwd=ROOT, env=env, capture_output=True, text=True, timeout=60)
            (out / (name + '.native.jsonl')).write_text(ran.stdout, encoding='utf-8', newline='\n'); (out / (name + '.stderr.txt')).write_text(ran.stderr, encoding='utf-8', newline='\n')
            if ran.returncode: raise RuntimeError('Native transport failure ' + name + ': ' + ran.stderr)
            actual = [json.loads(line) for line in ran.stdout.splitlines()]
            for row in actual:
                status = row.pop('status', 0)
                if status not in (0, 1, 2): raise ValueError(name + ': undeclared native refusal ' + str(status))
            mismatch, exclusions = compare_records(actual, wanted)
            (out / (name + '.representation-differences.json')).write_bytes(encode(exclusions))
            if mismatch: raise ValueError(name + ': ' + mismatch)
            report['cases'].append(dict(name=name, classification='matched selected whole snapshots/events', records=len(actual), wire_sha256=sha(wire),
                live_reservation_vs_legacy_cache_observations=len(exclusions)))
            print(name, len(actual), flush=True)
        report['status'] = 'passed selected comparison; wider scope still pending'
    except Exception as error:
        report.update(status='failed', failure=str(error)); raise
    finally:
        report['input_drift'] = [n for n, digest in impl['files'].items() if sha(ROOT / n) != digest]
        if report['input_drift']: report.update(status='failed', failure='Draft source drift')
        (out / 'receipt.json').write_bytes(encode(report))
    print(json.dumps(dict(status=report['status'], cases=len(report['cases']), receipt_sha256=sha(out / 'receipt.json'))))


if __name__ == '__main__': main()
