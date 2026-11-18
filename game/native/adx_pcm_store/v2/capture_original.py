#!/usr/bin/env python3
"""Read-only original PCM capture before encoded credit return; no native run."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import sys

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[3]
sys.path.insert(0, str(ROOT / 'tools/native_reconstruction'))
import adx_window_v2_oracle as oracle

OLD = oracle.old
ORIGINAL = ROOT / 'build-native-sjuni/adx-window-v2-oracle'
SCOPE = ROOT / 'build-native-sjuni/adx-pcm-store/v2'
sha = oracle.sha
encode = OLD.compact_serialized


class Capture(OLD.Machine):
    def __init__(self, *args):
        super().__init__(*args)
        self.captures = []

    def instruction(self, pc, word):
        if (pc == 0x13fbf8 and self.action.get('kind') == 'decode' and
                self.regs[4] & 0xffffffff == self.rings[0] and self.regs[5] & 0xffffffff == 0):
            active = self.mem.active
            self.mem.active = False
            try:
                self.captures.append(dict(pc=pc, source_put_pool=0,
                    rings=[[r[3], r[4], r[5], r[6], *r[10:14]] for r in self.small()['rings'][1:]],
                    backings=[self.raw(a, n).hex() for a, n in self.buffers[1:]]))
            finally:
                self.mem.active = active
        return super().instruction(pc, word)


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--output', type=Path, required=True)
    p.add_argument('--freeze', action='store_true')
    p.add_argument('--frozen', type=Path)
    p.add_argument('--compiler', choices=oracle.FP_PARENTS)
    a = p.parse_args(); out = a.output.resolve()
    if out.exists() or not out.is_relative_to(SCOPE):
        raise ValueError('Fresh scoped output required')
    freeze = json.loads((HERE / 'frozen_identity.json').read_bytes())
    for n, digest in freeze['files'].items():
        if sha((ROOT / n).read_bytes()) != digest:
            raise ValueError('Phased core drift')
    original_plan = json.loads((ORIGINAL / 'frozen-v3/input-manifest.json').read_bytes())
    bodies, authority = oracle.authority()
    if authority != original_plan['authority'] or sha((ORIGINAL / 'frozen-v3/inputs.json').read_bytes()) != original_plan['inputs_sha256']:
        raise ValueError('Original authority/input drift')
    if a.freeze:
        cases = [c for c in json.loads((ORIGINAL / 'frozen-v3/inputs.json').read_bytes())['cases'] if c['name'].startswith('pcm-tail-')]
        if len(cases) != 90:
            raise ValueError('Expected90 original partial-tail clients')
        out.mkdir(parents=True); (out / 'inputs.json').write_bytes(encode(cases))
        (out / 'manifest.json').write_bytes(encode(dict(schema=1, cases=90,
            source_sha256=sha(Path(__file__).read_bytes()), core_freeze_sha256=sha((HERE / 'frozen_identity.json').read_bytes()),
            inputs_sha256=sha((out / 'inputs.json').read_bytes()), original_manifest_sha256=sha((ORIGINAL / 'frozen-v3/input-manifest.json').read_bytes()),
            original_engines=original_plan['engines'], authority=authority)))
        print('New phase-capture inputs frozen; no original/native execution'); return
    if not a.frozen or not a.compiler:
        raise ValueError('Frozen inputs and exact qualified FP worker required')
    manifest = json.loads((a.frozen / 'manifest.json').read_bytes())
    if (manifest['source_sha256'] != sha(Path(__file__).read_bytes()) or manifest['authority'] != authority or
            manifest['core_freeze_sha256'] != sha((HERE / 'frozen_identity.json').read_bytes()) or
            manifest['inputs_sha256'] != sha((a.frozen / 'inputs.json').read_bytes())):
        raise ValueError('Frozen capture drift')
    for n, digest in manifest['original_engines'].items():
        if sha((ROOT / 'tools/native_reconstruction' / n).read_bytes()) != digest:
            raise ValueError('Original engine drift')
    folder = oracle.FP_PARENTS[a.compiler]
    if sha((folder / 'original-fixture.json').read_bytes()) != oracle.FP_PARENT_SHA[a.compiler]:
        raise ValueError('Unqualified FP parent')
    fp = json.loads((folder / 'original-fixture.json').read_bytes()); cc = Path(fp['compatibility']['compiler']); binary = folder / 'fp_worker.exe'
    if sha(cc.read_bytes()) != fp['compatibility']['compiler_sha256'] or sha(binary.read_bytes()) != fp['compatibility']['worker_binary_sha256']:
        raise ValueError('Exact compiler/worker identity drift')
    full = json.loads((ORIGINAL / ('gcc-v2' if a.compiler == 'gcc' else 'llvm-v2') / 'manifest.json').read_bytes())
    # The parent full replay already qualified current macros/conversion/emission.
    if full['fp_worker_sha256'] != sha(binary.read_bytes()):
        raise ValueError('Capture uses different full-replay FP worker')
    os.environ['PATH'] = str(cc.parent) + os.pathsep + os.environ.get('PATH', '')
    out.mkdir(parents=True); rows = []; steps = 0
    with OLD.math.FpuWorker(binary) as worker:
        for case in json.loads((a.frozen / 'inputs.json').read_bytes()):
            m = Capture(case, worker, bodies); m.prepare()
            expected_path = ORIGINAL / ('gcc-v2' if a.compiler == 'gcc' else 'llvm-v2') / (case['name'] + '.json')
            descriptor = next(r for r in full['cases'] if r['name'] == case['name'])
            if sha(expected_path.read_bytes()) != descriptor['sha256']:
                raise ValueError('Full replay transcript drift')
            expected = json.loads(expected_path.read_bytes())
            for action, operation in zip(case['actions'], expected['operations'], strict=True):
                m.action = action; m.status_index = 0
                entry, argument = (0x133fe0, OLD.MAIN) if action['kind'] == 'ready' else (0x12d638, OLD.window.OUTER)
                result = m.run(entry, [argument], full=False, limit=2500000)
                if result != operation['results']:
                    raise ValueError('Read-only capture changed original transcript: ' + case['name'])
            if len(m.captures) > 1:
                raise ValueError('Unexpected multiple input-credit transactions')
            rows.append(dict(name=case['name'], stage=m.captures[0] if m.captures else None,
                original_instructions=m.total_steps, original_transcript_sha256=descriptor['sha256']))
            steps += m.total_steps
    (out / 'phases.json').write_bytes(encode(rows))
    receipt = dict(schema=1, compiler=a.compiler, compiler_binary_sha256=sha(cc.read_bytes()),
        fp_worker_sha256=sha(binary.read_bytes()), input_manifest_sha256=sha((a.frozen / 'manifest.json').read_bytes()),
        phases_sha256=sha((out / 'phases.json').read_bytes()), cases=len(rows),
        stage_captures=sum(r['stage'] is not None for r in rows), original_instructions=steps,
        original_transcripts_unchanged=True, game_run=False, native_executed=False)
    (out / 'receipt.json').write_bytes(encode(receipt)); print(json.dumps(receipt))


if __name__ == '__main__':
    main()
