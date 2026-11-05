#!/usr/bin/env python3
"""Read-only real File1 import probe. No game/runtime/original instructions run.

Requires an explicit installed data directory. Outputs stay below this checkout's
ignored build-native-sjuni directory. Only bounded payload comparisons are made;
normal factory verification streams all imported file hashes through pinned handles.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import uuid

ROOT = Path(__file__).resolve().parents[2]


def sha(path):
    result = hashlib.sha256()
    with path.open('rb') as source:
        while block := source.read(1024 * 1024):
            result.update(block)
    return result.hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--data-root', required=True, type=Path)
    parser.add_argument('--expected-files', type=int, default=85)
    parser.add_argument('--cxx', default='g++')
    parser.add_argument('--output', type=Path)
    args = parser.parse_args()
    if not args.data_root.is_absolute() or not args.data_root.is_dir():
        parser.error('--data-root must explicitly name an existing absolute imported data directory')
    if not 1 <= args.expected_files <= 65536:
        parser.error('--expected-files must be 1..65536')
    compiler = shutil.which(args.cxx)
    if compiler is None:
        parser.error('Pass an installed Windows C++20 GCC/Clang compiler')
    output = (args.output or ROOT / 'build-native-sjuni/real-import-probe').resolve()
    if not output.is_relative_to((ROOT / 'build-native-sjuni').resolve()):
        parser.error('--output must stay below repository build-native-sjuni')
    output.mkdir(parents=True, exist_ok=True)
    missing_iso = output / ('not-an-iso-' + uuid.uuid4().hex + '.iso')
    if missing_iso.exists():
        raise ValueError('Private ISO sentinel unexpectedly exists')
    manifest = args.data_root.parent / 'import.json'
    manifest_before = sha(manifest)
    cpp = [
        'game/native/resources_windows/mounted_reader.cpp',
        'game/native/resources_windows/mounted_resources.cpp',
        'game/native/resources_windows/import_manifest.cpp',
        'game/native/resources_windows/pinned_file.cpp',
        'game/native/resources/resource_session.cpp',
        'game/native/resources/virtual_file_view.cpp',
        'runtime/cdvd/cdvd.cpp',
        'tools/native_reconstruction/probe_mounted_import.cpp',
    ]
    sources = [*map(lambda p: ROOT / p, cpp), *(ROOT / 'game/native/resources_windows').glob('*.hpp'),
               ROOT / 'game/native/resources/resource_session.hpp', ROOT / 'game/native/resources/virtual_file_view.hpp',
               ROOT / 'game/native/resources/byte_view.hpp', ROOT / 'runtime/assets/virtual_afs.h',
               ROOT / 'runtime/assets/overlay.h', ROOT / 'runtime/cdvd/cdvd.h',
               ROOT / 'runtime/core/host_file.h', ROOT / 'recomp/overrides/native_geometry/reo_vu_native_sha256.h',
               Path(__file__)]
    source_hashes = {p.relative_to(ROOT).as_posix(): sha(p) for p in sources}
    receipt = dict(schema=1, status='running', game_launched=False, runtime_library_linked=False,
                   user_assets_written=False, original_iso_opened=False, overlay_requested=False,
                   data_root=str(args.data_root), expected_files=args.expected_files,
                   compiler=compiler, compiler_sha256=sha(Path(compiler)),
                   compiler_version=subprocess.check_output([compiler, '--version'], text=True).splitlines()[0],
                   import_manifest_sha256_before=manifest_before, source_sha256=source_hashes, checks=[])
    environment = {k: v for k, v in os.environ.items() if not k.upper().startswith('REO_')}
    environment['PATH'] = str(Path(compiler).parent) + os.pathsep + environment.get('PATH', '')

    def run(command, name, timeout):
        result = subprocess.run(command, cwd=ROOT, env=environment, text=True, capture_output=True, timeout=timeout)
        receipt['checks'].append(dict(name=name, command=[str(x) for x in command], exit_code=result.returncode,
                                      stdout=result.stdout[:16384], stderr=result.stderr[:16384]))
        if result.returncode:
            raise RuntimeError(name + ' failed:\n' + result.stdout[:16384] + result.stderr[:16384])
        return result

    try:
        executable = output / 'probe_mounted_import.exe'
        run([compiler, '-std=c++20', '-Wall', '-Wextra', '-Wpedantic', '-Werror', '-O1', '-pthread',
             '-I.', *cpp, '-lruntimeobject', '-lole32', '-lbcrypt', '-static-libgcc', '-static-libstdc++',
             '-o', str(executable)], 'host_probe_build', 60)
        if source_hashes != {p.relative_to(ROOT).as_posix(): sha(p) for p in sources}:
            raise RuntimeError('Source changed during compilation; no real import probe executed')
        receipt['executable'] = str(executable)
        receipt['executable_sha256'] = sha(executable)
        result = run([str(executable), str(args.data_root), str(missing_iso), str(args.expected_files)],
                     'read_only_real_import', 300)
        metrics = {}
        text_keys = {'detail', 'route_sha256', 'manifest_sha256'}
        for line in result.stdout.splitlines():
            if line.startswith('PROBE '):
                key, value = line[6:].split('=', 1)
                if key in metrics:
                    raise RuntimeError('Duplicate probe metric')
                metrics[key] = value if key in text_keys else int(value)
        receipt['metrics'] = metrics
        if not metrics.get('passed') or metrics.get('manifest_sha256') != manifest_before:
            raise RuntimeError('Probe result/retained raw manifest identity mismatch')
        receipt['import_manifest_sha256_after'] = sha(manifest)
        if receipt['import_manifest_sha256_after'] != manifest_before:
            raise RuntimeError('Import manifest changed during read-only probe')
        if source_hashes != {p.relative_to(ROOT).as_posix(): sha(p) for p in sources}:
            raise RuntimeError('Source changed during probe; source/build identity is not stable')
        receipt['status'] = 'passed'
        print(json.dumps(metrics, indent=2), flush=True)
    except Exception as error:
        receipt['status'] = 'failed'
        receipt['failure'] = str(error)
        raise
    finally:
        receipt['limitations'] = [
            'Read-only actual installed import; whole-file hashes streamed by normal factory without snapshots.',
            'Only bounded sector/prefix samples compared; no payload bytes are saved or printed.',
            'Construction time includes hash/admission work and cache effects; it is not a game performance measurement.',
            'The explicit PAK facade differs from original ISO sector layout; missing private ISO sentinel is never created.',
            'No game, original instructions, runtime library, RPC/guest publication, async I/O or overlay payload executed.',
            'Existing writable-mapping, local-manifest authenticity and namespace-race limits remain.',
        ]
        (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8')
    print('Receipt: ' + str(output / 'receipt.json'))


if __name__ == '__main__':
    main()
