"""Exercise original font-code and 2-bit glyph expansion against the owned font.

This prepares the presenter work; it does not claim original GS output or a
complete UI renderer. The reference executes the source bodies, including the
nonzero-mode pair mapper selected by File 1's startup font descriptor.
"""
import argparse, hashlib, json, os, re, subprocess, sys, time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / 'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source, elf_reader

CC = Path('C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe')
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--cohort-snapshot', type=Path)
    args = parser.parse_args()
    out = args.output.resolve()
    assert not out.exists() and out.is_relative_to((ROOT / 'build-native-sjuni').resolve())
    out.mkdir(parents=True)
    snapshot=args.cohort_snapshot.resolve() if args.cohort_snapshot else None
    source_root=snapshot/'source' if snapshot else ROOT
    elf = ROOT / 'game_data/SLUS_207.65'
    assert sha(elf) == '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    read = elf_reader(elf.read_bytes())
    descriptor = read(0x2346c8, 52)
    assert descriptor[:20] == bytes.fromhex('0100000014000000010000000000000000010000')
    assert descriptor[24:36] == bytes.fromhex('02000000801e000064000000')
    addresses = (0x1b5ca0, 0x1b6580, 0x1b6670, 0x1b64f0, 0x1b6460, 0x1b6380, 0x1b65b0)
    sources, audits = [], []
    for address in addresses:
        source = next((ROOT / 'recomp/config/output').glob(f'sub_{address:08X}_*'))
        body = source.read_text()
        begin, end = (int(v, 16) for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)', body).groups())
        audits.append(compare_source('original font body', source.relative_to(ROOT).as_posix(), begin, end, read))
        sources.append(source)
    reference = (ROOT / 'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp').read_text()
    reference = reference.replace('struct R5900Context {', 'struct R5900Context { std::uint64_t hi{}, lo{};')
    (out / 'reference.hpp').write_text(reference + '\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define SRA32(v,n) ((v) >> (n))\n')
    body = '\n'.join(source.read_text() for source in sources)
    names = {source.stem for source in sources}
    calls = set(re.findall(r'\b(sub_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram', body))
    declarations = ''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for name in sorted(names))
    declarations += ''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n' for name in sorted(calls-names))
    (out / 'functions.h').write_text('#pragma once\n' + declarations)
    (out / 'original.cpp').write_text(body)
    for name in ('ps2_runtime.h', 'ps2_runtime_macros.h'):
        (out / name).write_text('#pragma once\n#include "reference.hpp"\n')
    (out / 'ps2_recompiled_functions.h').write_text('#pragma once\n#include "functions.h"\n')
    for name in ('ps2_recompiled_stubs.h', 'ps2_stubs.h', 'ps2_syscalls.h'):
        (out / name).write_text('#pragma once\n')
    inventory = ROOT / 'build-native-sjuni/audio-asset-inventory/file1-v1/members.json'
    assert sha(inventory) == '276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2'
    entry = next(row for row in json.loads(inventory.read_text()) if row['member'] == 'NETBIO00.DAT/0/554')
    assert entry['names'] == ['romdata_usa.afs', 's20le04.bin'] and entry['bytes'] == 780800
    with (ROOT / 'iso/Resident Evil - Outbreak (v2.00).iso').open('rb') as source:
        source.seek(entry['iso_offset']); data = source.read(entry['bytes'])
    assert hashlib.sha256(data).hexdigest() == entry['sha256'] == '9e73fbd679db0f8867fe5b3b0697e20741f8daf1e780d0d81880bf7ede5a4e97'
    asset = out / 's20le04.bin'; asset.write_bytes(data)
    fixture = ROOT / 'tools/native_reconstruction/presentation/font_glyph_original.cpp'
    native=source_root/'game/native/gameplay_presentation/font_face.cpp'
    inputs = [fixture, inventory, native, native.with_suffix('.hpp'), source_root/'game/native/gameplay_scenario/text_cache.hpp', ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp',
              ROOT/'tools/native_reconstruction/audit_retail_effect_descriptors.py', *sources]
    before = {str(path.relative_to(ROOT)): sha(path) for path in inputs}
    executable = out / 'font_checks.exe'
    env = dict(os.environ, PATH=str(CC.parent) + os.pathsep + os.environ.get('PATH', ''))
    archive=None
    if snapshot:
        snapshot_receipt=snapshot/'receipt.json';prior=json.loads(snapshot_receipt.read_text());assert prior['status']=='passed'
        cohort_receipt=ROOT/prior['cohort'];assert sha(cohort_receipt)==prior['cohort_sha256'];cohort=json.loads(cohort_receipt.read_text())
        assert cohort['status']=='passed' and not cohort['source_drift'] and not cohort['archive_drift'] and sha(CC)==cohort['compiler_sha256']
        def verify_snapshot():
            for name,expected in prior['source_sha256'].items():
                if sha(source_root/name)!=expected:raise RuntimeError('snapshot source mismatch: '+name)
            for name,expected in cohort['sources_sha256'].items():
                if prior['source_sha256'].get(name)!=expected:raise RuntimeError('cohort source mismatch: '+name)
        verify_snapshot();relative='gameplay_application/libreo_native_gameplay_presentation.a';archive=snapshot/'native-build'/relative
        assert sha(archive)==prior['archives_sha256'][relative]==cohort['archives_sha256'][relative]
    flags = [str(CC), '-std=c++20', '-O2', '-msse4.1', '-ffp-contract=off', '-Wall', '-Wextra', '-Wpedantic', '-Werror',
             '-Wno-unused-label', '-Wno-unused-parameter', '-Wno-unused-variable', '-I'+str(source_root), '-I'+str(ROOT), '-I'+str(out),
             '-I'+str(ROOT/'third_party/PS2Recomp/ps2xRuntime/include')]
    commands = [('compile', flags + [str(out/'original.cpp'), str(fixture), str(archive or native), '-o', str(executable)]),
                ('run', [str(executable), str(asset)])]
    receipt = {'status': 'failed', 'compiler_sha256': sha(CC), 'elf_sha256': sha(elf), 'source_sha256': before,
               'asset_sha256': sha(asset), 'descriptor_hex': descriptor.hex(), 'original_word_audits': audits,
               'driver_sha256': sha(Path(__file__)), 'checks': [], 'game_run': False}
    try:
        for name, command in commands:
            start = time.monotonic(); result = subprocess.run(command, capture_output=True, env=env, timeout=120)
            (out / (name+'.out')).write_bytes(result.stdout); (out / (name+'.err')).write_bytes(result.stderr)
            receipt['checks'].append({'name': name, 'seconds': time.monotonic()-start, 'exit': result.returncode})
            if result.returncode: raise RuntimeError(name+': '+result.stderr.decode(errors='replace')[-4000:])
        assert before == {str(path.relative_to(ROOT)): sha(path) for path in inputs}
        if snapshot:
            verify_snapshot();assert sha(archive)==prior['archives_sha256'][relative]
            receipt.update(snapshot_receipt=str(snapshot_receipt),snapshot_receipt_sha256=sha(snapshot_receipt),archive_sha256=sha(archive))
        receipt.update(status='passed', observed=json.loads((out/'run.out').read_text()))
    finally:
        (out/'receipt.json').write_text(json.dumps(receipt, indent=2)+'\n')
    print(json.dumps(receipt['observed']))

if __name__ == '__main__':
    main()
