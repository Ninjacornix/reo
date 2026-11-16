"""Bounded complete1D1030 comparison through the actual fresh application."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys
import time

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(Path(__file__).resolve().parent / 'gameplay_scenario'))
from verify_scenario_specific_events import body
from audit_retail_effect_descriptors import compare_source, elf_reader


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--compiler', type=Path, required=True)
    parser.add_argument('--immutable-snapshot', type=Path)
    parser.add_argument('--build-receipt', type=Path)
    parser.add_argument('--startup-supplement', type=Path)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--prepare-only', action='store_true')
    args = parser.parse_args()
    compiler = args.compiler.resolve()
    assert sha(compiler) == 'f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3'
    output = args.output.resolve()
    assert not output.exists() and output.is_relative_to(ROOT / 'build-native-sjuni')
    output.mkdir()
    snapshot = args.immutable_snapshot.resolve() if args.immutable_snapshot else None
    source_root = snapshot / 'source' if snapshot else ROOT
    captured = json.loads((snapshot / 'receipt.json').read_text()) if snapshot else None
    if captured:
        assert captured['status'] == 'passed' and sha(snapshot / 'cohort.json') == captured['cohort_sha256']
    assert args.prepare_only or captured
    elf = ROOT / 'game_data/SLUS_207.65'
    assert sha(elf) == '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    read = elf_reader(elf.read_bytes())
    overlay = ROOT / 'build-function-index/owned-overlays/o2.bin'
    assert sha(overlay) == '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    overlay_bytes = overlay.read_bytes()
    entries = {}; proof = []; originals = []
    for address in (0x1d1030,0x1d0b70,0x1d3a70,0x1d3ca0,0x1d3dc0,0x5b4ce0,0x6b4ae0):
        group = 'o2' if address >= 0x570000 else 'sub'
        folder = ROOT / ('recomp/config/output_ovl/o2' if group == 'o2' else 'recomp/config/output')
        original = next(folder.glob(group + '_' + format(address,'08X') + '_*.cpp')); originals.append(original)
        name = group + '_' + format(address,'08X') + '_0x' + format(address,'x')
        entries[address] = (name,body(original,name))
        begin,end=(int(value,16)for value in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',original.read_text()).groups())
        reader = (lambda at,n:overlay_bytes[at-0x570000:at-0x570000+n]) if group=='o2' else read
        proof.append(compare_source('complete scenario model/actor-resource producer executed through source-qualified ports',original.relative_to(ROOT).as_posix(),begin,end,reader))
    original_body = '\n'.join(text for _,text in entries.values())
    for address in (0x129c08,0x1297a0,0x129610,0x129240,0x1ac730,0x1ab310):
        path=next((ROOT/'recomp/config/output').glob('sub_'+format(address,'08X')+'_*.cpp'));originals.append(path)
        begin,end=(int(value,16)for value in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',path.read_text()).groups())
        proof.append(compare_source('static source qualification of declared SDK/catalogue/bank-install boundary, not executed',path.relative_to(ROOT).as_posix(),begin,end,read))
    ports = {int(value, 16) for value in re.findall(r'lookupFunction\((0x[0-9a-fA-F]+)', original_body)}
    ports |= {int(value, 16) for value in re.findall(r'\b(?:sub|o2)_([0-9A-F]+)_0x[0-9a-f]+\(rdram', original_body)}
    ports -= entries.keys()
    header = ROOT / 'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    (output / 'effect_assets_reference.hpp').write_bytes(header.read_bytes())
    declarations = ''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name,_ in entries.values())
    declarations += ''.join('inline void sub_' + format(address, '08X') + '_0x' + format(address, 'x') + '(std::uint8_t* m,R5900Context* c,PS2Runtime* r){c->pc=' + hex(address) + ';original_transform_port(m,c,r);}\n' for address in sorted(ports))
    (output / 'effect_assets_declarations.hpp').write_text('#pragma once\n' + declarations)
    (output / 'original.cpp').write_text('#include "effect_assets_reference.hpp"\n#include "effect_assets_declarations.hpp"\n' + original_body)
    constants = [(0x256300, read(0x256300, 0x60)),(0x256248,read(0x256248,32)),(0x256648,read(0x256648,0x80)),(0x740c90,overlay_bytes[0x740c90-0x570000:0x740c90-0x570000+64])]
    (output / 'effect_assets_constants.hpp').write_text('inline void effect_assets_constants(std::uint8_t* p){' + ''.join('{const unsigned char b[]{' + ','.join(map(str, data)) + '};std::memcpy(p+' + hex(address) + ',b,sizeof b);}' for address, data in constants) + '}\n')
    helper = ROOT / 'tools/native_reconstruction/scenario_effect_assets_reference.inc'
    text = (source_root / 'game/native/gameplay_application/session_startup_tests.cpp').read_text()
    text = text.replace('namespace {\nunsigned checks', '#include "../gameplay_world/resource_programs.hpp"\n#include "../gameplay_bank_loading/aliases.hpp"\n#include "../gameplay_scenario/actor_voice_archive_assets.hpp"\n#include "session_audio.hpp"\n#include "effect_assets_constants.hpp"\n#include "scenario_effect_assets_reference.inc"\nnamespace {\nunsigned checks', 1)
    anchor = 'const auto scenario_effects=frontend_app.startup().scenario_effect_bank();'
    assert text.count(anchor) == 1
    text = text.replace(anchor, 'compare_original_scenario_effect_assets(frontend_app);\n        '+anchor, 1)
    preparation_anchor='const auto reached=frontend_app.start(nullptr);'
    assert text.count(preparation_anchor)==1
    text=text.replace(preparation_anchor,'prepare_actor_resource_case(frontend_app);\n        '+preparation_anchor,1)
    main_anchor = 'int main(int argc,char** argv)try{'
    assert text.count(main_anchor) == 1
    entry = 'if(argc==6&&std::strcmp(argv[5],"--scenario-effects-original")==0){effect_archive_path=argv[1];effect_voice_path=argv[4];fresh_application(argv[1],argv[2],argv[3],argv[4]);std::cout<<"{\\"checks\\":"<<effect_asset_checks<<",\\"original_calls\\":"<<effect_asset_original_calls<<",\\"selectors\\":"<<effect_asset_selectors<<",\\"actor_resource_cases\\":"<<actor_resource_cases<<",\\"fresh_application_cases\\":1,\\"frame_run\\":false}\\n";return 0;}'
    text = text.replace(main_anchor, main_anchor + entry, 1)
    (output / 'fixture.cpp').write_text(text)
    inputs = [Path(__file__).resolve(), helper, *originals, header]
    receipt = {'status': 'failed', 'schema': 'reo.native.scenario_effect_assets.v1', 'archives_only': True,
               'compiler_sha256': sha(compiler), 'original_owned_bodies': proof,
               'ports': sorted(map(hex, ports)), 'commands': [], 'frame_run': False,
               'scope': 'Complete1D1030/1D0B70/1D3A70/1D3CA0/1D3DC0 with reached5B4CE0/6B4AE0, declared I/O, selector observation and previously qualified model/SND import boundaries; actual application/resource/weapon consumers execute.',
               'limits': ['Only the admitted mode1 scenario41 producer path executes; no mode0 filesystem qualification.',
                          'Existing Geometry/Tracks/MaterialTracks source qualification is reused; this comparison does not re-run their unchanged full matrices.',
                          'The application uses explicitly controlled EVB roots and real RN/model/static/WMD/audio/buffer owners; no untouched-script startup or game frame is claimed.'],
               'inputs_sha256': {str(path.relative_to(ROOT)): sha(path) for path in inputs}}
    environment = dict(os.environ, PATH=str(compiler.parent) + os.pathsep + os.environ.get('PATH', ''))

    def run(label, command):
        start = time.monotonic()
        result = subprocess.run(command, env=environment, cwd=ROOT, capture_output=True, timeout=240)
        (output / (label + '.stdout.txt')).write_bytes(result.stdout)
        (output / (label + '.stderr.txt')).write_bytes(result.stderr)
        receipt['commands'].append({'label': label, 'command': command, 'returncode': result.returncode, 'seconds': time.monotonic() - start})
        assert result.returncode == 0, label + ': ' + result.stderr.decode(errors='replace')[-4000:]
        return result.stdout

    try:
        flags = [str(compiler), '-std=c++20', '-O2', '-msse4.1', '-fno-fast-math', '-ffp-contract=off', '-I' + str(source_root), '-I' + str(source_root / 'game/native/gameplay_application'), '-I' + str(output), '-I' + str(helper.parent)]
        run('original', flags + ['-w', '-c', str(output / 'original.cpp'), '-o', str(output / 'original.o')])
        run('fixture', flags + ['-Wall', '-Wextra', '-Wpedantic', '-Werror', '-c', str(output / 'fixture.cpp'), '-o', str(output / 'fixture.o')])
        if args.prepare_only:
            receipt['status'] = 'prepared'
            return
        library_paths = {name: snapshot / 'native-build' / name for name in captured['archives_sha256']}
        libraries = {name: sha(path) for name, path in library_paths.items()}
        assert libraries == captured['archives_sha256']
        cohort = json.loads((snapshot / 'cohort.json').read_text())
        assert cohort['status'] == 'passed'
        if args.startup_supplement:
            supplement = args.startup_supplement.resolve()
            extra = json.loads((supplement / 'receipt.json').read_text())
            assert extra['status'] == 'passed' and extra['cohort_sha256'] == captured['cohort_sha256']
            assert extra['snapshot_receipt_sha256'] == sha(snapshot / 'receipt.json')
            for name, digest in extra['extra_archives_sha256'].items():
                path = supplement / 'native-build' / name
                assert sha(path) == cohort['archives_sha256'][name] == digest
                library_paths[name] = path
                libraries[name] = digest
            assert set(extra['required_libraries']) <= set(libraries)
            receipt['startup_supplement_receipt_sha256'] = sha(supplement / 'receipt.json')
        receipt['native_library_sha256'] = libraries
        receipt['immutable_snapshot'] = str(snapshot.relative_to(ROOT))
        receipt['source_sha256'] = {name: sha(source_root / name) for name in captured['source_sha256']}
        assert receipt['source_sha256'] == captured['source_sha256']
        run('link', [str(compiler), str(output / 'original.o'), str(output / 'fixture.o'), '-Wl,--start-group', *[str(path) for path in library_paths.values()], '-Wl,--end-group', '-lgdi32', '-ldwmapi', '-ldxgi', '-lxinput', '-ldinput8', '-ldxguid', '-lole32', '-loleaut32', '-luuid', '-lshell32', '-lwinspool', '-lcomdlg32', '-ladvapi32', '-lpthread', '-o', str(output / 'checks.exe')])
        owned = next(command for command in cohort['commands'] if command['label'] == 'session-startup-owned')
        command = [str(output / 'checks.exe'), *owned['command'][1:5], '--scenario-effects-original']
        assert len(command) == 6
        raw = run('test', command)
        rows = [json.loads(line) for line in raw.decode(errors='replace').splitlines() if line.startswith('{"checks":')]
        assert len(rows) == 1
        receipt['observed'] = rows[0]
        assert receipt['observed']['original_calls'] > 0 and receipt['observed']['selectors'] == 17
        assert all(sha(library_paths[name]) == digest for name, digest in libraries.items())
        receipt['status'] = 'passed'
    finally:
        receipt['generated_sha256'] = {path.name: sha(path) for path in output.iterdir() if path.is_file() and path.name != 'receipt.json'}
        (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
    print(json.dumps({'status': receipt['status'], 'observed': receipt.get('observed')}))


if __name__ == '__main__':
    main()
