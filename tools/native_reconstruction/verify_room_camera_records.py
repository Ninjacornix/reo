"""Complete room camera loader, geometry and link comparisons on owned content.

Production comes only from the current shared build. Original fixtures are
private test inputs; no addressed memory or original gameplay enters native code.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import time
from audit_retail_effect_descriptors import compare_source, elf_reader
from verify_native_session import dependency_sources

ROOT = Path(__file__).resolve().parents[2]
FIXTURE = ROOT / 'tools/native_reconstruction/room_camera_records_tests.cpp'
REFERENCE = ROOT / 'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'


def sha(path):
    with Path(path).open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def main(args):
    out, build, compiler = args.output.resolve(), args.native_build.resolve(), args.compiler.resolve()
    assert not out.exists() and out.is_relative_to(ROOT / 'build-native-sjuni')
    assert sha(compiler) == 'f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3'
    pins = {
        ROOT / 'game_data/SLUS_207.65': '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46',
        ROOT / 'build-function-index/owned-overlays/o0.bin': 'bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2',
        ROOT / 'build-function-index/owned-overlays/o2.bin': '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226',
    }
    assert all(sha(path) == digest for path, digest in pins.items())
    blobs = [path.read_bytes() for path in pins]
    readers = {'sub': elf_reader(blobs[0]),
               'o0': lambda at, n: blobs[1][at-0x370000:at-0x370000+n],
               'o2': lambda at, n: blobs[2][at-0x570000:at-0x570000+n]}
    entries, proof, sources = {}, [], [Path(__file__).resolve(), FIXTURE, REFERENCE,
                                      ROOT / 'tools/native_reconstruction/audit_retail_effect_descriptors.py',
                                      ROOT / 'tools/native_reconstruction/verify_native_session.py']
    for group, addresses in [('o2', (0x5be3e0, 0x5c0330, 0x5be930, 0x5c07c0)),
                             ('o0', (0x370420, 0x371160)), ('sub', (0x191d10, 0x191d80))]:
        directory = ROOT / ('recomp/config/output' if group == 'sub' else 'recomp/config/output_ovl/' + group)
        for address in addresses:
            path = next(directory.glob(f'{group}_{address:08X}_*.cpp'))
            source = path.read_text()
            end = int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)', source)[1], 16)
            proof.append(compare_source('complete camera import/math/link body', path.relative_to(ROOT).as_posix(), address, end, readers[group]))
            entries[address] = path
            sources.append(path)
    caller = ROOT / 'recomp/config/output/sub_001D3830_0x1d3830.cpp'
    caller_end = int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)', caller.read_text())[1], 16)
    proof.append(compare_source('static actual room-section dispatcher, not executed', caller.relative_to(ROOT).as_posix(), 0x1d3830, caller_end, readers['sub']))
    sources.append(caller)
    callback = struct.unpack('<4I', readers['sub'](0x236820, 16))
    assert callback == (0x5be3e0, 0, 0, 0)
    tables = [(0x70a6b0, readers['o2'](0x70a6b0, 32)), (0x73e7b0, readers['o2'](0x73e7b0, 40))]
    assert tables[0][1] == bytes([0,7,1,6,0,5,3,6,1,6,0,7,3,6,0,5,0,5,3,6,1,6,0,7,3,6,0,5,0,7,1,6])
    assert struct.unpack('<10I', tables[1][1]) == (0x5be7dc,) + (0x5be4f0,) * 9
    inventory = ROOT / 'build-native-sjuni/gameplay-script-content-llvm-v21/inventory.json'
    sources.append(inventory)
    sections, corpus = [], []
    for member in json.loads(inventory.read_text()):
        if member['format'] != 'R':
            continue
        with Path(member['archive']).open('rb') as stream:
            stream.seek(member['archive_offset'])
            raw = stream.read(member['bytes'])
        assert hashlib.sha256(raw).hexdigest() == member['sha256']
        offset, size = struct.unpack_from('<2I', raw)
        assert size >= 8 and offset + size <= len(raw)
        section = raw[offset:offset+size]
        sections.append(section)
        corpus.append(dict(name=member['name'], member_sha256=member['sha256'], archive=member['archive'],
                           archive_offset=member['archive_offset'], offset=offset, bytes=size,
                           sha256=hashlib.sha256(section).hexdigest(), count=struct.unpack_from('<H', section, 4)[0]))
    assert len(sections) == 166
    out.mkdir(parents=True)
    (out / 'sections.bin').write_bytes(struct.pack('<I', len(sections)) + b''.join(struct.pack('<I', len(s)) + s for s in sections))
    body = '\n'.join(path.read_text() for path in entries.values())
    actual = {path.stem for path in entries.values()}
    called = set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram', body))
    declarations = ''.join('void ' + name + '(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for name in sorted(actual))
    declarations += ''.join('inline void ' + name + '(std::uint8_t* m,R5900Context* c,PS2Runtime* r){c->pc=' + name.split('_')[-1] + ';original_transform_port(m,c,r);}\n' for name in sorted(called-actual))
    (out / 'functions.h').write_text('#pragma once\n' + declarations)
    (out / 'original.cpp').write_text(body)
    (out / 'reference.hpp').write_text(REFERENCE.read_text() + '\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define SRA32(v,n) (std::int32_t(v)>>(n))\n')
    (out / 'original_dispatch.hpp').write_text(''.join('case ' + hex(address) + ':' + path.stem + '(memory,context,runtime);return;\n' for address, path in entries.items()))
    for name in ('ps2_runtime.h', 'ps2_runtime_macros.h'):
        (out / name).write_text('#pragma once\n#include "reference.hpp"\n')
    for name in ('ps2_recompiled_functions.h', 'o0_functions.h', 'o2_functions.h'):
        (out / name).write_text('#pragma once\n#include "functions.h"\n')
    for name in ('ps2_recompiled_stubs.h', 'ps2_stubs.h', 'ps2_syscalls.h'):
        (out / name).write_text('#pragma once\n')
    (out / 'owned_constants.hpp').write_text('inline void owned_constants(std::uint8_t* p){\n' + ''.join(
        '{const std::uint8_t data[]{' + ','.join(map(str, data)) + '};std::memcpy(p+' + str(at) + ',data,sizeof data);}\n'
        for at, data in tables) + '}\n')
    native_sources, libraries = dependency_sources(build)
    sources.extend(native_sources)
    before = {p.relative_to(ROOT).as_posix(): sha(p) for p in sources}
    archives = {name: sha(build / name) for name in libraries}
    if not args.prepare_only:
        assert args.build_receipt
        cohort = json.loads(args.build_receipt.read_text())
        assert cohort['status'] == 'passed' and cohort['compiler_sha256'] == sha(compiler)
        current = {p.relative_to(ROOT).as_posix(): sha(p) for p in (ROOT / 'game/native').rglob('*')
                   if p.is_file() and p.suffix in ('.cpp', '.hpp', '.h', '.inc', '.txt')}
        assert current == cohort['sources_sha256'], 'Shared build native source identity mismatch'
        assert all(cohort['archives_sha256'].get(name) == digest for name, digest in archives.items())
    receipt = dict(schema='reo.native.room_camera_records.v1', status='failed', commands=[],
                   compiler_sha256=sha(compiler), source_sha256=before, native_library_sha256=archives,
                   original_inputs={p.relative_to(ROOT).as_posix(): h for p, h in pins.items()},
                   original_owned_bodies=proof, authored_sections=corpus,
                   callback_row=dict(address='0x236820', words=callback, invocation='0x1d39ec'),
                   game_run=False, stage4_complete=False,
                   scope='Complete 5BE3E0, 5C0330, 5BE930 and 5C07C0/5C0800; actual room camera import and canonical SequenceControl. Ordinary camera selection, pose, tasks and presentation are separate remaining consumers.',
                   arithmetic_profile='Finite FP32 nearest-rounding scalar/SIMD; physical PS2 exceptional arithmetic is not claimed. Bounded explicit memcpy/memset are the only ported original primitives.')
    env = dict(os.environ, PATH=str(compiler.parent)+os.pathsep+os.environ.get('PATH', ''))
    def run(label, command):
        start = time.monotonic()
        result = subprocess.run(command, env=env, capture_output=True, timeout=180)
        for stream in ('stdout', 'stderr'):
            (out / (label+'.'+stream+'.txt')).write_bytes(getattr(result, stream))
        receipt['commands'].append(dict(label=label, command=command, returncode=result.returncode, seconds=time.monotonic()-start))
        assert result.returncode == 0, label + ': ' + result.stderr.decode(errors='replace')[-4500:]
        return result.stdout
    try:
        flags = [str(compiler), '-std=c++20', '-O2', '-msse4.1', '-fno-fast-math', '-ffp-contract=off', '-I'+str(out), '-I'+str(ROOT)]
        run('original', flags + ['-w', '-c', str(out / 'original.cpp'), '-o', str(out / 'original.o')])
        run('fixture', flags + ['-Wall', '-Wextra', '-Wpedantic', '-Werror', '-c', str(FIXTURE), '-o', str(out / 'fixture.o')])
        if args.prepare_only:
            receipt['status'] = 'prepared'
            return
        run('link', [str(compiler), str(out / 'original.o'), str(out / 'fixture.o'), '-Wl,--start-group',
                     *[str(build / name) for name in libraries], '-Wl,--end-group', '-lpthread', '-o', str(out / 'checks.exe')])
        receipt['observed'] = json.loads(run('test', [str(out / 'checks.exe'), str(out / 'sections.bin')]))
        receipt['source_drift'] = [name for name, digest in before.items() if sha(ROOT / name) != digest]
        receipt['archive_drift'] = [name for name, digest in archives.items() if sha(build / name) != digest]
        assert not receipt['source_drift'] and not receipt['archive_drift']
        receipt.update(status='passed', executable_sha256=sha(out / 'checks.exe'), build_receipt_sha256=sha(args.build_receipt))
    finally:
        receipt['generated_sha256'] = {p.name: sha(p) for p in out.iterdir() if p.is_file() and p.name != 'receipt.json'}
        (out / 'receipt.json').write_text(json.dumps(receipt, indent=2)+'\n')
    print(json.dumps({k: receipt[k] for k in ('status', 'observed', 'source_drift', 'archive_drift')}))


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--compiler', type=Path, required=True)
    parser.add_argument('--native-build', type=Path, required=True)
    parser.add_argument('--build-receipt', type=Path)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--prepare-only', action='store_true')
    main(parser.parse_args())
