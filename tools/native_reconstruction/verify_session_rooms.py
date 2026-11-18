"""Qualify production room resources and complete original collision-mask producers.

Builds actual CMake owners, snapshots their whole dependency closure, and links
the same native archives into a separate original-body comparison executable.
No game, device, register machine or original RAM model enters production.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess
import struct
from audit_retail_effect_descriptors import compare_source
from verify_native_session import dependency_sources
from verify_gameplay_collision import COMPILERS

ROOT = Path(__file__).resolve().parents[2]
CMAKE = Path('C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe')
PROFILES = [(0x619a50, 0x619a68), (0x6161e0, 0x616304),
            (0x5dcb60, 0x5dcb88), (0x5dcb90, 0x5dcbb4)]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def afs(source, base):
    source.seek(base)
    magic, count = struct.unpack('<4sI', source.read(8))
    assert magic == b'AFS\0' and count < 100000
    entries = [struct.unpack('<II', source.read(8)) for _ in range(count)]
    names, names_size = struct.unpack('<II', source.read(8))
    assert names_size >= count * 48
    source.seek(base + names)
    labels = [source.read(48).split(b'\0', 1)[0].decode('ascii').lower() for _ in range(count)]
    return [dict(name=name, archive_offset=base + offset, bytes=size) for name, (offset, size) in zip(labels, entries)]


def main(args):
    out = args.output.resolve()
    assert not out.exists() and out.is_relative_to(ROOT / 'build-native-sjuni')
    out.mkdir()
    compiler = COMPILERS[args.compiler]
    build = ROOT / 'build-native-sjuni' / ('gameplay-native-' + args.compiler + '-v1')
    env = dict(os.environ, PATH=str(compiler.parent) + os.pathsep + os.environ.get('PATH', ''))
    commands = []
    receipt = dict(schema='reo.native.session_rooms.v1', status='failed',
                   game_launched=False, device_opened=False, installed_in_game=False, stage4_complete=False)

    def run(command, label):
        result = subprocess.run([str(value) for value in command], env=env,
                                capture_output=True, text=True, timeout=900)
        stdout, stderr = out / (label + '.stdout.txt'), out / (label + '.stderr.txt')
        stdout.write_text(result.stdout)
        stderr.write_text(result.stderr)
        commands.append(dict(command=[str(value) for value in command], returncode=result.returncode,
                             stdout_sha256=sha(stdout), stderr_sha256=sha(stderr)))
        if result.returncode:
            raise RuntimeError(label + ': ' + result.stdout[-3000:] + result.stderr[-3000:])
        return result.stdout

    try:
        run([CMAKE, '-S', ROOT / 'game/native', '-B', build], 'configure')
        sources, libraries = dependency_sources(build, 'gameplay_application/session_rooms_tests.exe')
        application_sources,application_libraries=dependency_sources(build,'gameplay_application/native_session_tests.exe')
        sources=sorted(set(sources+application_sources))
        libraries=sorted(set(libraries+application_libraries))
        sources.extend([Path(__file__).resolve(), ROOT / 'tools/native_reconstruction/verify_native_session.py',
                        ROOT / 'tools/native_reconstruction/gameplay_collision_oracle/reference.hpp',
                        ROOT / 'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h'])
        image_path = ROOT / 'build-function-index/owned-overlays/o2.bin'
        assert sha(image_path) == '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
        image = image_path.read_bytes()
        audits, bodies = [], []
        for start, end in PROFILES:
            source = ROOT / f'recomp/config/output_ovl/o2/o2_{start:08X}_0x{start:x}.cpp'
            sources.append(source)
            audits.append(compare_source('session-room-original', source.relative_to(ROOT).as_posix(),
                                         start, end, lambda at, n: image[at - 0x570000:at - 0x570000 + n]))
            value = source.read_text()
            bodies.append(value[value.index('// Function:'):])
        before = {path.relative_to(ROOT).as_posix(): sha(path) for path in sorted(set(sources))}
        receipt.update(source_sha256=before, original_word_audits=audits, owned_overlay_sha256=sha(image_path),
                       compiler=str(compiler), compiler_sha256=sha(compiler))
        for name in before:
            target = out / 'source' / name
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes((ROOT / name).read_bytes())
        inventory_path = ROOT / 'build-native-sjuni/gameplay-script-content-llvm-v14/inventory.json'
        inventory = json.loads(inventory_path.read_bytes())
        index = json.loads((inventory_path.parent / 'receipt.json').read_bytes())
        assert index['status'] == 'passed' and index['output_sha256']['inventory.json'] == sha(inventory_path)
        room = next(row for row in inventory if row['name'] == 'r0417300.rdt')
        archive = Path(room['archive'])
        members = [room]
        with archive.open('rb') as source:
            root = afs(source, 0)
            scenario = next(row for row in root if row['name'] == 'r041.afs')
            header = next(row for row in root if row['name'] == 'r041_h.bin')
            physical = afs(source, scenario['archive_offset'])
            source.seek(header['archive_offset'])
            index_bytes = source.read(header['bytes'])
            first, count = struct.unpack_from('<II', index_bytes)
            assert len(index_bytes) == 8 + count * 16 and first + count <= len(physical)
            keys = [index_bytes[8 + i * 16:24 + i * 16].split(b'\0', 1)[0].decode('ascii') for i in range(count)]
            header['sha256'] = hashlib.sha256(index_bytes).hexdigest()
            for name in ['w0417300.bin', 'g0417300.bin', 'obj041.dat', 'r041.sto', 'r0417300.nbd']:
                ordinal = first + keys.index(name.upper().replace('.', '_'))
                row = dict(physical[ordinal], name=name, resource_ordinal=ordinal)
                source.seek(row['archive_offset'])
                row['sha256'] = hashlib.sha256(source.read(row['bytes'])).hexdigest()
                members.append(row)
        receipt['resource_index'] = header
        identity = dict(size=archive.stat().st_size, mtime_ns=archive.stat().st_mtime_ns)
        for member in members:
            with archive.open('rb') as source:
                source.seek(member['archive_offset'])
                value = source.read(member['bytes'])
            assert hashlib.sha256(value).hexdigest() == member['sha256']
        receipt.update(owned_members=[{key: row[key] for key in ('name', 'sha256', 'archive_offset', 'bytes')} for row in members],
                       archive_identity=identity, inventory_sha256=sha(inventory_path))
        run([CMAKE, '--build', build, '--target', 'session_rooms_tests', 'native_session_tests', '--parallel', '2'], 'build')
        exe = build / 'gameplay_application/session_rooms_tests.exe'
        receipt['fixture_result'] = json.loads(run([exe], 'fixture-tests'))
        receipt['result'] = json.loads(run([exe, archive], 'owned-tests'))
        receipt['application_result'] = json.loads(run([build / 'gameplay_application/native_session_tests.exe', archive], 'application-tests'))
        assert receipt['result']['rooms'] == 4 and receipt['result']['queries'] > 0 and receipt['result']['hits'] > 0
        receipt['native_library_sha256'] = {name: sha(build / name) for name in libraries}
        # Original bodies are admitted only in this independent test executable.
        # The native application archive itself has no original-code linkage.
        original = out / 'original.cpp'
        original.write_text('#include "tools/native_reconstruction/gameplay_collision_oracle/reference.hpp"\n' + '\n'.join(bodies))
        oracle = out / 'session-rooms-original.exe'
        command = [compiler, '-std=c++20', '-O2', '-Wall', '-Wextra', '-Wpedantic', '-Werror',
                   '-Wno-unused-parameter', '-fno-fast-math', '-ffp-contract=off', '-DSESSION_ROOMS_ORIGINAL',
                   '-I' + str(out / 'source'), '-I' + str(ROOT),
                   out / 'source/game/native/gameplay_application/session_rooms_tests.cpp', original,
                   '-Wl,--start-group', *[build / name for name in libraries], '-Wl,--end-group', '-o', oracle]
        run(command, 'original-compile')
        receipt['original_result'] = json.loads(run([oracle, archive], 'original-tests'))
        assert receipt['original_result']['original_calls'] == 10250
        assert dict(size=archive.stat().st_size, mtime_ns=archive.stat().st_mtime_ns) == identity
        receipt['current_shared_source_drift'] = {name: sha(ROOT / name) for name, digest in before.items() if sha(ROOT / name) != digest}
        assert not receipt['current_shared_source_drift'], receipt['current_shared_source_drift']
        receipt['executable_sha256'] = sha(exe)
        receipt['oracle_executable_sha256'] = sha(oracle)
        receipt['limitations'] = [
            'Only rooms without current-room movable-object placements are admitted until actual object model/proxy construction is composed.',
            'Production installation, complete frame services, broader scripts and semantic saves remain required.',
            'Geometry query integration reuses already-qualified native solvers; full original bodies here prove wall-grid initialization and mask set/clear producers.']
        receipt['status'] = 'passed'
    finally:
        receipt['commands'] = commands
        receipt['output_sha256'] = {path.name: sha(path) for path in out.iterdir() if path.is_file()}
        (out / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
    print(json.dumps(dict(compiler=args.compiler, result=receipt['result'], original_result=receipt['original_result'])))


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--compiler', choices=COMPILERS, required=True)
    parser.add_argument('--output', type=Path, required=True)
    main(parser.parse_args())
