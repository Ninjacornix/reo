#!/usr/bin/env python3
"""Storage-only projection: original decoded PCM is an INPUT, not a codec test."""
import argparse
import hashlib
import json
from pathlib import Path
import struct

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
COHORT = ROOT / 'build-native-sjuni/adx-window-v2-oracle'
NORMAL_MANIFEST = 'f3a8c7527d7a36420e269b989232487bd9e649a8f34ce43d58da20d4a8aef78b'
FROZEN_MANIFEST = 'c28d49395aa089b63843e11d925ec5be86204022100efb4bdd79bd3e4ddb6c5e'


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def encode(value):
    return (json.dumps(value, sort_keys=True, separators=(',', ':')) + '\n').encode()


def project():
    freeze = json.loads((HERE / 'frozen_identity.json').read_bytes())
    for name, digest in freeze['files'].items():
        if sha(ROOT / name) != digest:
            raise ValueError('Frozen core drift: ' + name)
    if sha(COHORT / 'frozen-v3/input-manifest.json') != FROZEN_MANIFEST or sha(COHORT / 'gcc-v2/manifest.json') != NORMAL_MANIFEST:
        raise ValueError('Original authority changed')
    frozen = json.loads((COHORT / 'frozen-v3/input-manifest.json').read_bytes())
    if sha(COHORT / 'frozen-v3/inputs.json') != frozen['inputs_sha256']:
        raise ValueError('Original input changed')
    clients = json.loads((COHORT / 'frozen-v3/inputs.json').read_bytes())['cases']
    manifest = json.loads((COHORT / 'gcc-v2/manifest.json').read_bytes())
    rows = []
    for case in clients:
        if not case['name'].startswith('pcm-tail-'):
            continue
        path = COHORT / 'gcc-v2' / (case['name'] + '.json')
        descriptor = next(r for r in manifest['cases'] if r['name'] == case['name'])
        if sha(path) != descriptor['sha256']:
            raise ValueError('Original transcript changed')
        row = json.loads(path.read_bytes())
        before = [bytearray.fromhex(h) for h in row['initial_backings_hex']]
        for op in row['operations']:
            result = op['results']
            if isinstance(result, list) or result['failure']:
                raise ValueError('Unexpected partial PCM client')
            for backing, effect in zip(before, result['backing_effects'], strict=True):
                if hashlib.sha256(backing).hexdigest() != effect['before_sha256']:
                    raise ValueError('Backing preimage drift')
                for change in effect['changes']:
                    at = change['offset']; old = bytes.fromhex(change['before_hex']); new = bytes.fromhex(change['after_hex'])
                    if backing[at:at + len(old)] != old or len(old) != len(new):
                        raise ValueError('Invalid original delta')
                    backing[at:at + len(new)] = new
                if hashlib.sha256(backing).hexdigest() != effect['after_sha256']:
                    raise ValueError('Backing postimage drift')
        result = row['operations'][-1]['results']
        codec = [e for e in result['events'] if e.get('kind') == 'original_entry' and e['pc'] in (0x1276d8, 0x127c80, 0x1278b8)]
        callbacks = [e for e in result['events'] if e['kind'] == 'pcm_callback']
        completion = [e for e in result['events'] if e.get('name') == 'default_complete']
        channels = case['channels']
        if len(codec) > 1 or len(completion) != len(codec):
            raise ValueError('Not a single plain unmarked codec transaction')
        pcm = []; produced = published = 0
        if codec:
            # These authored clients contain plain blocks, no marker. This
            # projection supplies the ORIGINAL PCM as input to the storage
            # component. It does not claim an independent scalar comparison.
            requested = codec[0]['arguments_u64'][1]
            if requested % channels:
                raise ValueError('Incomplete stereo request')
            raw_bytes = requested // channels * 64
            produced = completion[0]['arguments_u64'][2]
            published = callbacks[0]['arguments_u64'][3] // 2
            offset = result['before']['rings'][1][5]
            if offset < 192 or offset + produced * 2 > 16384:
                raise ValueError('Projection would need pre-mirror PCM capture')
            if len(callbacks) != channels or any(e['arguments_u64'][3] != published * 2 for e in callbacks):
                raise ValueError('Unexpected publication geometry')
            pcm = [bytes(b[16 + offset:16 + offset + raw_bytes]).hex() for b in before[1:]]
        elif callbacks or result['before']['rings'][1][4] >= 64:
            raise ValueError('Not the admitted backpressure projection')
        initial = result['before']['rings'][1:]
        if any(r[6] != 0 or r[5] != case['initial_pcm_bytes'][0] or r[3] != r[5] for r in initial):
            raise ValueError('Initial queue geometry differs from constructor')
        expected_rings = [[r[3], r[4], r[5], r[6], *r[10:14]] for r in result['after']['rings'][1:]]
        rows.append(dict(name=case['name'], channels=channels, queued_bytes=case['initial_pcm_bytes'][0],
            operation='publish' if codec else 'backpressure', left_hex=pcm[0] if pcm else '',
            right_hex=pcm[1] if channels == 2 and pcm else '', produced=produced, published=published,
            expected=dict(rings=expected_rings, callbacks=[e['pcm_hex'] for e in callbacks],
                backings=[bytes(b[16:-16]).hex() for b in before[1:]]),
            original_case_sha256=descriptor['sha256']))
    if len(rows) != 90:
        raise ValueError('Expected exactly90 new symmetric tail clients')
    return rows


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--output', type=Path, required=True)
    a = p.parse_args(); out = a.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT / 'build-native-sjuni/adx-pcm-store'):
        raise ValueError('Fresh scoped output required')
    rows = project(); out.mkdir(parents=True)
    (out / 'cases.json').write_bytes(encode(rows))
    receipt = dict(schema=1, cases=len(rows), original_manifest_sha256=NORMAL_MANIFEST,
        original_inputs_manifest_sha256=FROZEN_MANIFEST, cases_sha256=sha(out / 'cases.json'),
        core_freeze_sha256=sha(HERE / 'frozen_identity.json'), projector_sha256=sha(Path(__file__)),
        limitations=['Decoded original PCM is supplied INPUT to the storage owner, not independent codec parity.',
                    'Symmetric partial-tail clients only. No complete Window2, source/header/loop, RNA/DTR or game claim.',
                    'Backpressure clients perform no storage operation, preserving the caller-selected original branch.'])
    (out / 'manifest.json').write_bytes(encode(receipt))
    print(json.dumps(dict(cases=90, manifest_sha256=sha(out / 'manifest.json'))))


if __name__ == '__main__':
    main()
