"""Qualify the original scanners' ordinal-translation equivalence.

This checks the source property used by script_program's finite-state proof;
the separate shared-build script_program_tests exercise native admission and VM
behavior. It does not claim to run the complete original script dispatcher.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main(args):
    compiler, out = args.compiler.resolve(), args.output.resolve()
    assert sha(compiler) == 'f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3'
    assert not out.exists() and out.is_relative_to(ROOT / 'build-native-sjuni')
    out.mkdir()
    overlay = ROOT / 'build-function-index/owned-overlays/o2.bin'
    assert sha(overlay) == '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    raw = overlay.read_bytes()
    sources, chunks, declarations = [Path(__file__).resolve()], [], []
    words = 0
    for address in (0x68c990, 0x68c9e0, 0x68cbe0):
        path = next((ROOT / 'recomp/config/output_ovl/o2').glob(f'o2_{address:08X}_*'))
        source = path.read_text()
        for pc, opcode in re.findall(r'// (0x[0-9a-f]+): (0x[0-9a-f]+)\s', source):
            assert struct.unpack_from('<I', raw, int(pc, 16) - 0x570000)[0] == int(opcode, 16)
            words += 1
        name = f'o2_{address:08X}_0x{address:x}'
        declarations.append(f'void {name}(std::uint8_t*,R5900Context*,PS2Runtime*);')
        chunks.append('\n'.join(line for line in source.splitlines() if not line.startswith('#include')))
        sources.append(path)
    table = raw[0x717600 - 0x570000:0x717600 - 0x570000 + 132]
    assert len(table) == 132 and struct.unpack_from('<I', table, 128)[0] == 0xffffffff
    fixture = ROOT / 'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    (out / 'original_fixture.hpp').write_bytes(fixture.read_bytes())
    declarations.append('inline void original_constants(std::uint8_t* m){const std::array<std::uint8_t,132> data{' +
                        ','.join(map(str, table)) + '};std::memcpy(m+0x717600,data.data(),data.size());}')
    (out / 'original_declarations.inc').write_text('\n'.join(declarations) + '\n')
    (out / 'original.cpp').write_text('#include "original_fixture.hpp"\n#include "original_declarations.inc"\n' + '\n'.join(chunks))
    sources.extend([fixture, HERE / 'script_closure_tests.cpp',
                    ROOT / 'game/native/gameplay_scenario/script_program.cpp',
                    ROOT / 'game/native/gameplay_scenario/script_program_tests.cpp',
                    ROOT / 'game/native/gameplay_scenario/script_program.hpp',
                    ROOT / 'game/native/gameplay_scenario/interpreter.cpp'])
    before = {p.relative_to(ROOT).as_posix(): sha(p) for p in sources}
    env = dict(os.environ, PATH=str(compiler.parent) + os.pathsep + os.environ.get('PATH', ''))
    commands = []

    def run(command, label):
        result = subprocess.run(command, capture_output=True, text=True, env=env, timeout=120)
        for stream in ('stdout', 'stderr'):
            (out / f'{label}.{stream}.txt').write_text(getattr(result, stream))
        commands.append(dict(command=command, returncode=result.returncode,
                             stdout_sha256=sha(out / f'{label}.stdout.txt'),
                             stderr_sha256=sha(out / f'{label}.stderr.txt')))
        if result.returncode:
            raise RuntimeError(label + ': ' + result.stderr[-4000:])
        return result.stdout

    base = [str(compiler), '-std=c++20', '-O2', '-msse4.1', '-fno-fast-math', '-ffp-contract=off', '-I' + str(out)]
    run(base + ['-w', '-c', str(out / 'original.cpp'), '-o', str(out / 'original.o')], 'original')
    run(base + ['-Wall', '-Wextra', '-Wpedantic', '-Werror', '-c', str(HERE / 'script_closure_tests.cpp'),
                '-o', str(out / 'tests.o')], 'tests')
    run([str(compiler), str(out / 'original.o'), str(out / 'tests.o'), '-o', str(out / 'checks.exe')], 'link')
    observed = json.loads(run([str(out / 'checks.exe')], 'run'))
    drift = [name for name, digest in before.items() if sha(ROOT / name) != digest]
    assert not drift
    receipt = dict(schema='reo.native.script_closure_ordinal.v1', status='passed',
                   compiler_sha256=sha(compiler), source_sha256=before, source_drift=drift,
                   original_overlay_sha256=sha(overlay), checked_original_words=words,
                   executable_sha256=sha(out / 'checks.exe'), commands=commands, observed=observed,
                   scope='Original scanner translation equivalence; native admission has separate regression evidence',
                   game_run=False, stage4_complete=False)
    (out / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
    print(json.dumps(dict(status='passed', observed=observed)))


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--compiler', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    main(parser.parse_args())
