"""Compare owned native efdata imports to complete original curve/track bodies."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
from audit_retail_effect_descriptors import compare_source

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--compiler', type=Path, required=True)
    parser.add_argument('--corpus', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    out = args.output.resolve()
    assert not out.exists() and out.is_relative_to(ROOT / 'build-native-sjuni')
    corpus = args.corpus.resolve()
    corpus_receipt = corpus / 'receipt.json'
    cr = json.loads(corpus_receipt.read_bytes())
    assert len(cr['assets']) == 25 and sha(corpus / 'owned_effect_tracks.bin') == cr['package_sha256']
    overlay_path = ROOT / 'build-function-index/owned-overlays/o2.bin'
    assert sha(overlay_path) == '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    overlay = overlay_path.read_bytes()
    originals = ['recomp/config/output_ovl/o2/o2_' + name for name in ['00590B10_0x590b10.cpp', '005903E0_0x5903e0.cpp']]
    proof = []
    for name in originals:
        begin, end = [int(v, 16) for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)', (ROOT / name).read_text()).groups()]
        proof.append(compare_source('complete original effect scalar curve / piece transform body', name, begin, end,
                                    lambda at, size: overlay[at - 0x570000:at - 0x570000 + size]))
    native = ['game/native/gameplay_effects/tracks.hpp', 'game/native/gameplay_effects/tracks.cpp',
              'game/native/transform_math/transform_math.hpp', 'game/native/transform_math/transform_math.cpp']
    helper = 'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    fixture = 'tools/native_reconstruction/effect_tracks_tests.cpp'
    files = native + originals + [helper, fixture, Path(__file__).relative_to(ROOT).as_posix()]
    frozen = {name: (ROOT / name).read_bytes() for name in files}
    out.mkdir(parents=True)
    record = dict(schema=1, status='failed', source_sha256={n: hashlib.sha256(b).hexdigest() for n, b in frozen.items()},
                  compiler_sha256=sha(args.compiler), corpus=dict(path=str(corpus_receipt), sha256=sha(corpus_receipt)),
                  original_owned_bodies=proof, game_run=False, installed_in_game=False, stage4_complete=False,
                  physical_ps2_exceptional_parity=False, full_effect_pipeline=False)
    try:
        for name, body in frozen.items():
            target = out / 'source' / name
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes(body)
        (out / 'tests.cpp').write_bytes(frozen[fixture])
        reference = frozen[helper].decode() + '\n#define FPU_CVT_W_S(a) static_cast<std::int32_t>(a)\n'
        (out / 'reference.hpp').write_text(reference)
        (out / 'original_tracks.cpp').write_text('\n'.join(frozen[n].decode() for n in originals))
        (out / 'functions.h').write_text('#pragma once\n' + ''.join('void ' + Path(n).stem + '(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for n in originals))
        for name in ['ps2_runtime.h', 'ps2_runtime_macros.h']:
            (out / name).write_text('#pragma once\n#include "reference.hpp"\n')
        (out / 'o2_functions.h').write_text('#pragma once\n#include "functions.h"\n')
        for name in ['ps2_recompiled_stubs.h', 'ps2_stubs.h', 'ps2_syscalls.h']:
            (out / name).write_text('#pragma once\n')
        raw = overlay[0x73e110 - 0x570000:0x73e110 - 0x570000 + 36]
        record['owned_switch_table'] = dict(address='0x73e110', bytes=raw.hex())
        (out / 'owned_constants.hpp').write_text('inline void owned_constants(std::uint8_t* memory){const std::uint8_t bytes[]{' + ','.join(str(v) for v in raw) + '};std::memcpy(memory+0x73e110,bytes,sizeof bytes);}\n')
        (out / 'owned_effect_tracks.bin').write_bytes((corpus / 'owned_effect_tracks.bin').read_bytes())
        env = dict(os.environ)
        env['PATH'] = str(args.compiler.resolve().parent) + os.pathsep + env.get('PATH', '')
        binary = out / 'checks.exe'
        command = [str(args.compiler), '-std=c++20', '-O2', '-msse4.1', '-Wall', '-Wextra', '-Wpedantic', '-Werror',
                   '-Wno-unused-label', '-Wno-unused-parameter', '-fno-fast-math', '-ffp-contract=off',
                   '-I' + str(out), '-I' + str(out / 'source'), str(out / 'source' / native[1]),
                   str(out / 'source' / native[3]), str(out / 'tests.cpp'), '-o', str(binary)]
        record['command'] = command
        for label, cmd in [('compile', command), ('run', [str(binary), str(out / 'owned_effect_tracks.bin')])]:
            result = subprocess.run(cmd, env=env, capture_output=True, timeout=180)
            (out / (label + '.stdout.txt')).write_bytes(result.stdout)
            (out / (label + '.stderr.txt')).write_bytes(result.stderr)
            assert result.returncode == 0, label + ' failed; see retained output'
            if label == 'run':
                record['observed'] = json.loads(result.stdout)
        record['source_unchanged'] = all((ROOT / n).read_bytes() == b for n, b in frozen.items())
        assert record['source_unchanged']
        record.update(status='passed', binary_sha256=sha(binary))
    finally:
        record['output_sha256'] = {p.relative_to(out).as_posix(): sha(p) for p in out.rglob('*') if p.is_file() and p.name != 'receipt.json'}
        (out / 'receipt.json').write_text(json.dumps(record, indent=2) + '\n')
    print(json.dumps(record['observed']))


if __name__ == '__main__':
    main()
