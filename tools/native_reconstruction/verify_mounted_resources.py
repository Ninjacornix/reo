#!/usr/bin/env python3
"""Build/test Windows mounted resources against private synthetic trees.

Copies the owned ELF only as a data/hash identity fixture. All archive payloads,
manifests, plans, namespace changes and writes are newly generated under ignored
build-native-sjuni output. No original instructions, game or runtime execute.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess
import uuid

ROOT = Path(__file__).resolve().parents[2]
ELF_HASH = '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def afs(payload):
    # Synthetic writer only; production Overlay/table/build remains the reader.
    result = bytearray(4144)
    struct.pack_into('<4sI', result, 0, b'AFS\0', 1)
    struct.pack_into('<IIII', result, 8, 2048, len(payload), 4096, 48)
    result[2048:2048 + len(payload)] = payload
    result[4096:4103] = b'one.bin'
    struct.pack_into('<I', result, 4140, len(payload))
    return bytes(result)


def plan(entries, elf_hash=ELF_HASH):
    result = bytearray(b'REOPAK1\0' + struct.pack('<I', 1) + bytes.fromhex(elf_hash) + struct.pack('<I', len(entries)))
    for target, path, original in entries:
        for value in (target, str(path)):
            encoded = value.encode('utf-8')
            result.extend(struct.pack('<I', len(encoded)) + encoded)
        payload = path.read_bytes()
        result.extend(struct.pack('<Q', len(payload)))
        result.extend(hashlib.sha256(original).digest() + hashlib.sha256(payload).digest())
    return result


def prepare(folder, scenario, owned):
    data = folder / 'data'
    data.mkdir(parents=True)
    shutil.copyfile(owned, data / 'SLUS_207.65')
    fixtures = {
        'z-last.bin': b'last bytes',
        'BOOT/0FLIST.DIR': b'five!',
        'empty.bin': b'',
        'alpha.bin': bytes((i * 17 + i // 7) % 256 for i in range(4097)),
        'NETBIO00.DAT': afs(b'original zero'),
        'NETBIO01.DAT': afs(b'original one'),
        'NETBIO02.DAT': afs(b'original two'),
    }
    for name, payload in fixtures.items():
        path = data / name
        path.parent.mkdir(exist_ok=True)
        path.write_bytes(payload)
    # Intentionally unsorted, mixed-case rows; optional Source is untrusted
    # provenance and never serves as the admitted file location.
    rows = [{'Name': name, 'Length': (data / name).stat().st_size, 'Sha256': sha(data / name)}
            for name in [*fixtures, 'SLUS_207.65']]
    manifest = dict(Version=2 if scenario == 'pak-v2' else 1, Game='file1',
                    Source='verified-looking caller text / NOT AN AUTHORITY',
                    SourceLength=123, SourceWriteTicks=638000000000000000,
                    ElfSha256=ELF_HASH, Files=rows)
    if scenario == 'pak-case':
        for row in rows:
            row['Name'] = row['Name'].swapcase()
    if scenario == 'pak-hardlink':
        os.link(data / 'alpha.bin', folder / 'outside-alpha.bin')
    if scenario == 'manifest-elf':
        manifest['ElfSha256'] = '00' * 32
    if scenario == 'manifest-duplicate-case':
        manifest['Files'].append(dict(Name='ALPHA.BIN', Length=4097, Sha256=sha(data / 'alpha.bin')))
    if scenario == 'manifest-traversal':
        rows[0]['Name'] = '../z-last.bin'
    if scenario == 'hash':
        rows[0]['Sha256'] = '00' * 32
    if scenario == 'length':
        rows[0]['Length'] += 1
    if scenario == 'missing':
        (data / 'z-last.bin').unlink()
    if scenario == 'unlisted':
        (data / 'extra.bin').write_bytes(b'unlisted')
    if scenario == 'renamed':
        rows[0]['Name'] = 'renamed.bin'
    if scenario == 'unicode-name':
        (data / 'non-ascii-\u6728.bin').write_bytes(b'unicode')
        rows.append(dict(Name='non-ascii-\u6728.bin', Length=7, Sha256=sha(data / 'non-ascii-\u6728.bin')))
    text = json.dumps(manifest, indent=2, ensure_ascii=False)
    if scenario == 'manifest-malformed':
        text = text[:-1]
    # V2 also checks retained raw BOM bytes vs parsed logical content.
    (folder / 'import.json').write_bytes((b'\xef\xbb\xbf' if scenario == 'pak-v2' else b'') + text.encode('utf-8'))
    cache = folder / 'cache'
    cache.mkdir()
    payloads = [bytes((i * 31) % 256 for i in range(8193)), b'changed one', b'original two']
    if scenario == 'overlay-empty':
        payloads[0] = b''
    originals = [b'original zero', b'original one', b'original two']
    entries = []
    for i, payload in enumerate(payloads):
        replacement = cache / f'replacement-\u00e9-\u6728-{i}.bin'
        replacement.write_bytes(payload)
        entries.append((f'NETBIO0{i}.DAT/0', replacement, originals[i]))
    binary = plan(entries)
    if scenario == 'overlay-base-hash':
        # Offset of first original hash, derived from the existing wire fields.
        offset = 48 + 4 + len(entries[0][0].encode()) + 4 + len(str(entries[0][1]).encode()) + 8
        binary[offset] ^= 1
    if scenario == 'overlay-new-hash':
        binary[-1] ^= 1
    if scenario == 'overlay-oversize':
        offset = 48 + 4 + len(entries[0][0].encode()) + 4 + len(str(entries[0][1]).encode())
        struct.pack_into('<Q', binary, offset, 256 * 1024 * 1024 + 1)
    if scenario == 'overlay-trailing':
        binary.extend(b'bad')
    (folder / 'asset-overlay.bin').write_bytes(binary)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cxx', help='Compiler for a source build, or optional prebuilt toolchain provenance')
    parser.add_argument('--executable', type=Path, help='Existing mounted_resources_tests.exe; skip compilation')
    parser.add_argument('--output', type=Path, help='Private ignored output directory named mounted-resources-checks')
    args = parser.parse_args()
    compiler = shutil.which(args.cxx or 'g++') if (args.cxx or not args.executable) else None
    if compiler is None and (args.cxx or not args.executable):
        parser.error('Pass an installed Windows C++20 GCC/Clang compiler')
    supplied = args.executable.resolve() if args.executable else None
    if supplied and (not supplied.is_file() or supplied.name.lower() != 'mounted_resources_tests.exe'):
        parser.error('--executable must be an existing mounted_resources_tests.exe')
    owned = ROOT / 'game_data/SLUS_207.65'
    if sha(owned) != ELF_HASH:
        raise ValueError('Owned ELF identity fixture mismatch')
    output = (args.output or ROOT / 'build-native-sjuni/mounted-resources-checks').resolve()
    allowed = (ROOT / 'build-native-sjuni', ROOT / 'build-function-index')
    if output.name != 'mounted-resources-checks' or not any(output.is_relative_to(p.resolve()) for p in allowed):
        parser.error('--output must be named mounted-resources-checks beneath a repository ignored build directory')
    output.mkdir(parents=True, exist_ok=True)
    token = uuid.uuid4().hex
    fixture = output / ('synthetic-' + token)
    fixture.mkdir()
    (fixture / '.mounted-resources-fixture').write_text(token, encoding='ascii')
    scenarios = ('pak-v1', 'pak-v2', 'pak-case', 'pak-hardlink', 'overlay', 'overlay-empty', 'retention', 'hash', 'length', 'missing', 'unlisted',
                 'renamed', 'unicode-name', 'manifest-elf', 'manifest-duplicate-case', 'manifest-traversal',
                 'manifest-malformed', 'overlay-base-hash', 'overlay-new-hash', 'overlay-trailing', 'overlay-oversize',
                 'junction', 'replacement-junction')
    for scenario in scenarios:
        prepare(fixture / scenario, scenario, owned)
    cpp = [
        'game/native/resources_windows/mounted_resources.cpp',
        'game/native/resources_windows/import_manifest.cpp',
        'game/native/resources_windows/pinned_file.cpp',
        'game/native/resources/resource_session.cpp',
        'game/native/resources/virtual_file_view.cpp',
        'runtime/cdvd/cdvd.cpp',
        'game/native/resources_windows/mounted_resources_tests.cpp',
    ]
    sources = [*map(lambda p: ROOT / p, cpp), *(ROOT / 'game/native/resources_windows').glob('*.hpp'),
               ROOT / 'runtime/assets/overlay.h', ROOT / 'runtime/assets/virtual_afs.h',
               ROOT / 'runtime/cdvd/cdvd.h', ROOT / 'game/native/resources/resource_session.hpp',
               ROOT / 'game/native/resources/virtual_file_view.hpp', ROOT / 'game/native/resources/byte_view.hpp',
               ROOT / 'recomp/overrides/native_geometry/reo_vu_native_sha256.h',
               ROOT / 'game/native/resources_windows/README_MOUNT.md', Path(__file__)]
    receipt = dict(schema=1, status='running', game_launched=False, runtime_library_linked=False,
                   build_mode='prebuilt' if supplied else 'source',
                   owned_elf_role='Read/copy/hash identity fixture only', owned_elf_sha256=ELF_HASH,
                   compiler=compiler, compiler_sha256=sha(Path(compiler)) if compiler else None,
                   compiler_version=subprocess.check_output([compiler, '--version'], text=True).splitlines()[0] if compiler else None,
                   source_sha256={p.relative_to(ROOT).as_posix(): sha(p) for p in sources}, checks=[])
    environment = dict(os.environ)
    if compiler:
        environment['PATH'] = str(Path(compiler).parent) + os.pathsep + environment.get('PATH', '')

    def run(command, name):
        result = subprocess.run(command, cwd=ROOT, env=environment, capture_output=True, text=True, timeout=60)
        receipt['checks'].append(dict(name=name, exit_code=result.returncode, command=[str(x) for x in command],
                                      stdout=result.stdout, stderr=result.stderr))
        if result.returncode:
            raise RuntimeError(name + ' failed:\n' + result.stdout + result.stderr)
        print(name + ': passed', flush=True)

    try:
        executable = supplied or output / 'mounted_resources_tests.exe'
        if not supplied:
            run([compiler, '-std=c++20', '-Wall', '-Wextra', '-Wpedantic', '-Werror', '-O1', '-pthread',
                 '-I.', *cpp, '-lruntimeobject', '-lole32', '-lbcrypt', '-static-libgcc', '-static-libstdc++',
                 '-o', str(executable)], 'host_mount_build')
        receipt['executable'] = str(executable)
        receipt['executable_sha256'] = sha(executable)
        for scenario in scenarios:
            run([str(executable), str(fixture / scenario), token, scenario], scenario)
        receipt['status'] = 'passed'
    except Exception as error:
        receipt['status'] = 'failed'
        receipt['failure'] = str(error)
        raise
    finally:
        receipt['limitations'] = [
            'Local File1 extracted-data/PAK routes only; no original ISO layout or raw-volume admission.',
            'Non-ASCII imported facade names, reparse points and UNC/device paths fail explicitly.',
            'The local manifest is unsigned; matching its hashes does not authenticate an entire retail disc.',
            'PinnedFile read-sharing does not revoke previously existing writable mappings.',
            'Namespace checks are not a filesystem transaction against hostile concurrent namespace changes.',
            'Synthetic archives/providers plus copied owned ELF identity data; no original instruction/game execution.',
        ]
        if supplied:
            receipt['limitations'].append('Prebuilt mode records current source hashes but does not prove this binary was built from them; retain CMake/build provenance separately.')
        (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8')
    print('Receipt: ' + str(output / 'receipt.json'))


if __name__ == '__main__':
    main()
