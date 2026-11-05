#!/usr/bin/env python3
"""Compare typed native ADX phase/window control against unchanged owned-word oracle.

Native code never enters the oracle. The existing generator/integer engine run
only admitted owned instructions over synthetic memory. The native executable
consumes their state images through a bounded test-only binary transport.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import struct
import subprocess

from adx_phase_oracle import generate

ROOT = Path(__file__).resolve().parents[2]
OPERATIONS = {name: index for index, name in enumerate((
    'phase', 'mono', 'stereo', 'request', 'cancel', 'acknowledge', 'completed', 'mono_window', 'stereo_window'))}


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def encode(data):
    output = bytearray(b'ADXCTL1\0' + struct.pack('<II', 1, len(data['cases'])))

    def word(value):
        output.extend(struct.pack('<I', value & 0xffffffff))

    def snapshot(value):
        for key, count in (('context_words_u32', 15), ('decoder_words_u32', 32), ('payload_probe_u32', 192)):
            if len(value[key]) != count:
                raise ValueError('Unexpected oracle snapshot shape')
            for item in value[key]:
                word(item)

    for case in data['cases']:
        name = case['name'].encode('utf-8')
        word(len(name)); output.extend(name)
        snapshot(case['initial_state'])
        word(len(case['operations']))
        for operation in case['operations']:
            reference = operation['expected']
            word(OPERATIONS[operation['operation']])
            word(len(reference['arguments_i32']))
            for argument in reference['arguments_i32']:
                word(argument)
            word(int(reference['return_is_defined']))
            word(reference['return_u32'] if reference['return_is_defined'] else 0)
            snapshot(reference['state'])
    return output


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cxx', help='C++20 compiler; optional for prebuilt mode')
    parser.add_argument('--executable', type=Path, help='Existing adx_control_tests executable')
    parser.add_argument('--output', type=Path)
    args = parser.parse_args()
    compiler = shutil.which(args.cxx or 'g++') if (args.cxx or not args.executable) else None
    if compiler is None and (args.cxx or not args.executable):
        parser.error('Pass an installed C++20 compiler')
    supplied = args.executable.resolve() if args.executable else None
    if supplied and (not supplied.is_file() or supplied.name.lower() not in ('adx_control_tests.exe', 'adx_control_tests')):
        parser.error('--executable must name an existing adx_control_tests executable')
    output = (args.output or ROOT / 'build-native-sjuni/adx-control-checks').resolve()
    if output.name != 'adx-control-checks' or not any(output.is_relative_to((ROOT / directory).resolve())
            for directory in ('build-native-sjuni', 'build-function-index')):
        parser.error('--output must be named adx-control-checks below an ignored repository build root')
    output.mkdir(parents=True, exist_ok=True)
    sources = [*(ROOT / 'game/native/adx_control').glob('*'), Path(__file__),
               ROOT / 'tools/native_reconstruction/adx_phase_oracle.py', ROOT / 'tools/native_reconstruction/sjuni_oracle.py']
    hashes = {p.relative_to(ROOT).as_posix(): sha(p) for p in sources if p.is_file()}
    data = generate()  # Unchanged original-word generator; no native algorithm imported.
    if (data['counts']['cases'], data['counts']['operations']) != (16, 96):
        raise ValueError('Expected the complete16-case/96-call scalar corpus')
    fixture = output / 'adx-phase-original-words.json'
    fixture.write_text(json.dumps(data, indent=2) + '\n', encoding='utf-8')
    wire = output / 'adx-control-fixtures.bin'
    wire.write_bytes(encode(data))
    receipt = dict(schema=1, status='running', game_launched=False, runtime_library_linked=False,
                   scope='Nine synchronous ADX scalar phase/window helpers only',
                   build_mode='prebuilt' if supplied else 'source', source_sha256=hashes,
                   compiler=compiler, compiler_sha256=sha(Path(compiler)) if compiler else None,
                   compiler_version=subprocess.check_output([compiler, '--version'], text=True).splitlines()[0] if compiler else None,
                   oracle_identity=data['identity'], oracle_counts=data['counts'],
                   original_fixture_sha256=sha(fixture), binary_fixture_sha256=sha(wire), checks=[])
    environment = dict(os.environ)
    if compiler:
        environment['PATH'] = str(Path(compiler).parent) + os.pathsep + environment.get('PATH', '')

    def run(command, name):
        result = subprocess.run(command, cwd=ROOT, env=environment, text=True, capture_output=True, timeout=30)
        receipt['checks'].append(dict(name=name, command=[str(item) for item in command], exit_code=result.returncode,
                                      stdout=result.stdout, stderr=result.stderr))
        if result.returncode:
            raise RuntimeError(name + ' failed:\n' + result.stdout + result.stderr)
        return result

    try:
        executable = supplied or output / ('adx_control_tests.exe' if os.name == 'nt' else 'adx_control_tests')
        if not supplied:
            command = [compiler, '-std=c++20', '-Wall', '-Wextra', '-Wpedantic', '-Werror', '-O1',
                       'game/native/adx_control/predictor_control.cpp', 'game/native/adx_control/predictor_control_tests.cpp']
            if os.name == 'nt':
                command += ['-static-libgcc', '-static-libstdc++']
            run(command + ['-o', str(executable)], 'native_control_build')
        receipt['executable'] = str(executable)
        receipt['executable_sha256'] = sha(executable)
        unit = run([str(executable), '--unit'], 'typed_native_unit_contracts')
        compared = run([str(executable), '--fixtures', str(wire)], 'original_word_full_state_comparison')
        if hashes != {p.relative_to(ROOT).as_posix(): sha(p) for p in sources if p.is_file()}:
            raise RuntimeError('Source/oracle changed during comparison')
        metrics = {key: int(value) for key, value in re.findall(r'(cases|calls|state_images|snapshot_words|defined_returns|ignored_void_returns)=(\d+)', compared.stdout)}
        if metrics != dict(cases=16, calls=96, state_images=96, snapshot_words=22944, defined_returns=72, ignored_void_returns=24):
            raise RuntimeError('Incomplete native/original comparison metrics')
        receipt['comparison'] = metrics
        receipt['status'] = 'passed'
        print(unit.stdout.strip(), flush=True)
        print(compared.stdout.strip(), flush=True)
    except Exception as error:
        receipt['status'] = 'failed'; receipt['failure'] = str(error)
        raise
    finally:
        receipt['limitations'] = [
            'Opaque span tokens and word offsets do not validate capacity, retain payload storage or authorize dereference.',
            'Original layout conversion exists only in the isolated fixture test; unrelated owner words/decoder/payload stay in its preserved shadow.',
            'Full post-call images and defined32-bit results compared; void raw registers and original memset hook ABI are not native return contracts.',
            'No kernel/PCM decode, scheduler, worker/IOP, stream refill/publication, stop/join, audio/video device or game execution.',
            'Original phase oracle and integer engine remain unchanged; no native control algorithm enters the oracle.',
        ]
        if supplied:
            receipt['limitations'].append('Prebuilt mode records current source snapshot; retain separate build provenance for the supplied binary.')
        (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8')
    print('Receipt: ' + str(output / 'receipt.json'))


if __name__ == '__main__':
    main()
