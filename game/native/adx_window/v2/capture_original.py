#!/usr/bin/env python3
"""New full-state guard observations during unchanged original whole replay."""
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
SCOPE = ROOT / 'build-native-sjuni/window2'
sha = oracle.sha
encode = OLD.compact_serialized
BASE_MACHINE = OLD.Machine


class Capture(BASE_MACHINE):
    latest = None

    def __init__(self, *args):
        super().__init__(*args)
        self.observations = []; self.ring_stack = []; self.next_ring = None
        Capture.latest = self

    def observe(self, kind, **fields):
        if not self.action:
            return
        action = next(i for i, a in enumerate(self.inputs['actions']) if a is self.action)
        active = self.mem.active; self.mem.active = False
        try:
            row = dict(action=action, kind=kind, state=self.small(),
                pcm_backing_sha256=[sha(self.raw(a, n)) for a, n in self.buffers[1:]], **fields)
            if kind == 'P':
                row.update(bytes=self.regs[7] & 0xffffffff,
                           payload=self.raw(self.regs[6] & 0xffffffff, self.regs[7] & 0xffffffff).hex())
            self.observations.append(row)
        finally:
            self.mem.active = active

    def instruction(self, pc, word):
        if pc in (0x13fa88, 0x13fbf8, 0x13fd58):
            pointer = self.regs[4] & 0xffffffff
            self.next_ring = self.rings.index(pointer) if pointer in self.rings else None
        if pc == 0x133ab8:
            self.observe('T')
        return super().instruction(pc, word)

    def hook(self, pc):
        if pc == 0x13f258:
            if self.action:
                if self.next_ring is None:
                    raise ValueError('Guard without actual owned Ring entry')
                self.ring_stack.append(self.next_ring); self.observe('E', ring=self.next_ring)
        elif pc == 0x13f270:
            if self.action:
                if not self.ring_stack:
                    raise ValueError('Unbalanced Ring guard')
                self.observe('L', ring=self.ring_stack.pop())
        elif pc == OLD.window.PCM_CALLBACK:
            self.observe('P', ring=(self.regs[5] & 0xffffffff) + 1)
        elif pc in (0x13f080, 0x13ef80, 0x13ef78, 0x13f038, 0x13f058, 0x13ebd8):
            notice = {0x13f080: 3, 0x13ef80: 4, 0x13ef78: 5, 0x13f038: 6, 0x13ebd8: 9}.get(pc)
            register = 5
            if pc == 0x13f058:
                notice = 7 + (self.regs[5] & 0xffffffff); register = 6
            value = self.regs[register] & 0xffffffff
            if value >= 0x80000000: value -= 0x100000000
            self.observe('N', notice=notice, value=value)
        elif pc in (0x128128, 0x1280d0):
            address = self.regs[4] & 0xffffffff
            notice = {0x239b68: 0, 0x23ad50: 1, 0x23b6c0: 2}.get(address)
            if notice is not None:
                self.observe('N', notice=notice, value=0)
        return super().hook(pc)


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--output', type=Path, required=True); p.add_argument('--freeze', action='store_true')
    p.add_argument('--frozen', type=Path); p.add_argument('--implementation', type=Path)
    p.add_argument('--compiler', choices=oracle.FP_PARENTS); p.add_argument('--case', action='append')
    a = p.parse_args(); out = a.output.resolve()
    if out.exists() or not out.is_relative_to(SCOPE):
        raise ValueError('Fresh scoped output required')
    bodies, authority = oracle.authority()
    source_plan = json.loads((ORIGINAL / 'frozen-v3/input-manifest.json').read_bytes())
    if authority != source_plan['authority'] or sha((ORIGINAL / 'frozen-v3/inputs.json').read_bytes()) != source_plan['inputs_sha256']:
        raise ValueError('Original authority/input drift')
    if a.freeze:
        if not a.implementation:
            raise ValueError('Explicit earlier implementation snapshot required')
        impl = json.loads((a.implementation / 'manifest.json').read_bytes())
        for n, digest in impl['files'].items():
            if sha((ROOT / n).read_bytes()) != digest:
                raise ValueError('Draft snapshot drift')
        out.mkdir(parents=True); (out / 'inputs.json').write_bytes((ORIGINAL / 'frozen-v3/inputs.json').read_bytes())
        plan = dict(schema=1, source_sha256=sha(Path(__file__).read_bytes()), inputs_sha256=source_plan['inputs_sha256'],
            original_manifest_sha256=sha((ORIGINAL / 'frozen-v3/input-manifest.json').read_bytes()),
            implementation_manifest_sha256=sha((a.implementation / 'manifest.json').read_bytes()),
            authority=authority, engines=source_plan['engines'])
        (out / 'manifest.json').write_bytes(encode(plan)); print('Whole capture inputs frozen; no original/native execution'); return
    if not a.frozen or not a.compiler:
        raise ValueError('Frozen capture and exact compiler required')
    plan = json.loads((a.frozen / 'manifest.json').read_bytes())
    if (plan['authority'] != authority or plan['source_sha256'] != sha(Path(__file__).read_bytes()) or
            sha((a.frozen / 'inputs.json').read_bytes()) != plan['inputs_sha256']):
        raise ValueError('Capture definition/input drift')
    for n, digest in plan['engines'].items():
        if sha((ROOT / 'tools/native_reconstruction' / n).read_bytes()) != digest:
            raise ValueError('Original engine drift')
    folder = oracle.FP_PARENTS[a.compiler]; parent = json.loads((folder / 'original-fixture.json').read_bytes())
    if sha((folder / 'original-fixture.json').read_bytes()) != oracle.FP_PARENT_SHA[a.compiler]:
        raise ValueError('Unqualified FP parent')
    compiler = Path(parent['compatibility']['compiler']); worker = folder / 'fp_worker.exe'
    if sha(compiler.read_bytes()) != parent['compatibility']['compiler_sha256'] or sha(worker.read_bytes()) != parent['compatibility']['worker_binary_sha256']:
        raise ValueError('Exact FP/compiler identity changed')
    original_dir = ORIGINAL / ('gcc-v2' if a.compiler == 'gcc' else 'llvm-v2')
    full = json.loads((original_dir / 'manifest.json').read_bytes())
    if full['fp_worker_sha256'] != sha(worker.read_bytes()): raise ValueError('Different full-replay worker')
    os.environ['PATH'] = str(compiler.parent) + os.pathsep + os.environ.get('PATH', '')
    cases = json.loads((a.frozen / 'inputs.json').read_bytes())['cases']
    if a.case and set(a.case) - {c['name'] for c in cases}: raise ValueError('Unknown selected case')
    out.mkdir(parents=True); rows = []
    with OLD.math.FpuWorker(worker) as fp:
        for case in cases:
            if a.case and case['name'] not in a.case: continue
            original_path = original_dir / (case['name'] + '.json')
            expected = next(r for r in full['cases'] if r['name'] == case['name'])
            if sha(original_path.read_bytes()) != expected['sha256']: raise ValueError('Original transcript drift')
            # Only replace construction with a read-only instrumented subclass.
            # The frozen execution driver, instructions, hooks and results stay
            # unchanged, verified against EVERY complete original transcript.
            OLD.Machine = Capture
            try: result = oracle.execute(case, fp, bodies)
            finally: OLD.Machine = BASE_MACHINE
            if encode(result) != original_path.read_bytes():
                raise ValueError('Instrumentation changed original whole transcript: ' + case['name'])
            observed = Capture.latest.observations
            path = out / (case['name'] + '.json'); path.write_bytes(encode(dict(name=case['name'], events=observed,
                original_transcript_sha256=expected['sha256'], original_instructions=result['original_instructions'])))
            rows.append(dict(name=case['name'], sha256=sha(path.read_bytes()), events=len(observed), original_instructions=result['original_instructions']))
            print(case['name'], len(observed), flush=True)
    receipt = dict(schema=1, compiler=a.compiler, compiler_sha256=sha(compiler.read_bytes()), fp_worker_sha256=sha(worker.read_bytes()),
        input_manifest_sha256=sha((a.frozen / 'manifest.json').read_bytes()), selected_cases=a.case, cases=rows,
        original_transcripts_unchanged=True, original_instructions=sum(r['original_instructions'] for r in rows),
        game_run=False, native_executed=False)
    (out / 'receipt.json').write_bytes(encode(receipt)); print(json.dumps(dict(cases=len(rows), original_instructions=receipt['original_instructions'])))


if __name__ == '__main__': main()
