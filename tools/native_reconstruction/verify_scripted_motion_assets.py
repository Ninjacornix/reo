"""Check actual File1 motion archive reads, native consumers and original loader routing."""
import argparse, hashlib, json, os, re, struct, subprocess, sys
from pathlib import Path
from audit_retail_effect_descriptors import compare_source, elf_reader
from verify_gameplay_collision import COMPILERS

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools/assets'))
from afs_inspect import read_toc
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--compiler', choices=COMPILERS, required=True)
    parser.add_argument('--build', type=Path, required=True)
    parser.add_argument('--cmake', type=Path, required=True)
    parser.add_argument('--data-root', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    out = args.output.resolve()
    assert not out.exists() and out.is_relative_to(ROOT / 'build-native-sjuni')
    compiler = COMPILERS[args.compiler]
    build = args.build.resolve()
    configured = re.search(r'^CMAKE_CXX_COMPILER:[^=]+=([^\n]+)', (build / 'CMakeCache.txt').read_text(), re.M)[1]
    assert Path(configured.strip()).resolve() == compiler.resolve()
    profile_path = ROOT / 'build-native-sjuni/scripted-motion-member-profile-v1/receipt.json'
    profile = json.loads(profile_path.read_bytes())
    assert profile['status'] == 'passed' and profile['output_sha256'] == sha(ROOT / 'game/native/gameplay_world/scripted_motion_members.inc')
    elf = ROOT / 'game_data/SLUS_207.65'
    assert sha(elf) == '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    read = elf_reader(elf.read_bytes())
    original = ROOT / 'recomp/config/output/sub_001D1CC0_0x1d1cc0.cpp'
    proof = compare_source('complete original three-file scripted motion loader', original.relative_to(ROOT).as_posix(), 0x1d1cc0, 0x1d1dfc, read)
    sources = [p for p in (ROOT / 'game/native').rglob('*') if p.is_file() and
               (p.suffix in ('.cpp', '.hpp', '.inc', '.h') or p.name == 'CMakeLists.txt')]
    sources += [Path(__file__), original, ROOT / 'runtime/assets/virtual_afs.h',
                ROOT / 'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp',
                ROOT / 'tools/native_reconstruction/scripted_motion_loader_reference_tests.inc',
                ROOT / 'tools/native_reconstruction/generate_scripted_motion_profile.py']
    before = {p.relative_to(ROOT).as_posix(): sha(p) for p in sources}
    out.mkdir()
    for name in before:
        target = out / 'source' / name
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes((ROOT / name).read_bytes())
    archive = args.data_root / 'NETBIO00.DAT'
    stamp = archive.stat().st_size, archive.stat().st_mtime_ns
    inventory_path = ROOT / 'build-native-sjuni/audio-asset-inventory/file1-v1/members.json'
    assert sha(inventory_path) == '276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2'
    inventory = {r['member']: r for r in json.loads(inventory_path.read_bytes())}
    rows, manifest = [], []
    with archive.open('rb') as stream:
        outer = read_toc(stream, 0)
        common = [i for i, r in enumerate(outer[2]) if r[0].lower() == 'romdata_usa.afs']
        assert len(common) == 1
        index = common[0]
        base = outer[0][index][0]
        directory = read_toc(stream, base)
        assert len(directory[0]) == 1342
        for row in profile['rows']:
            member = row['member']
            relative, length = directory[0][member]
            stream.seek(base + relative)
            raw = stream.read(length)
            item = inventory[f'NETBIO00.DAT/{index}/{member}']
            assert len(raw) == length == item['bytes'] and hashlib.sha256(raw).hexdigest() == item['sha256']
            rows.append(dict(row, archive_offset=base + relative, bytes=length, sha256=item['sha256']))
            manifest.append(' '.join(str(v) for v in [row['scenario'], row['clip'], row['kind'], member, base + relative, length]))
    (out / 'owned-members.txt').write_text('\n'.join(manifest) + '\n')
    reference = (ROOT / 'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp').read_text()
    reference += '\nvoid sub_001D1CC0_0x1d1cc0(std::uint8_t*,R5900Context*,PS2Runtime*);\n'
    for address in [0x10a830, 0x1cc8f0, 0x1d1960]:
        reference += f'inline void sub_{address:08X}_0x{address:x}(std::uint8_t* m,R5900Context* c,PS2Runtime* r){{original_transform_port(m,c,r);}}\n'
    reference += 'inline void owned_loader_formats(std::uint8_t* memory){\n'
    for address in [0x256430, 0x256460, 0x256490]:
        raw = read(address, 64).split(b'\0')[0] + b'\0'
        reference += '{const std::uint8_t b[]{' + ','.join(map(str, raw)) + '};std::memcpy(memory+' + str(address) + ',b,sizeof b);}\n'
    reference += '}\n'
    (out / 'reference.hpp').write_text(reference)
    body = original.read_text()
    (out / 'original.cpp').write_text('#include "reference.hpp"\n' + body[body.index('// Function:'):])
    (out / 'scripted_motion_loader_reference_tests.inc').write_bytes((ROOT / 'tools/native_reconstruction/scripted_motion_loader_reference_tests.inc').read_bytes())
    record = dict(schema=1, status='failed', source_sha256=before, compiler_sha256=sha(compiler),
                  profile=dict(path=str(profile_path), sha256=sha(profile_path)), owned_members=rows,
                  original_owned_body=proof, original_observation_ports=['10A830 verified-format sprintf',
                      '1CC8F0 controlled file-read results; no original I/O', '1D1960 construction argument observation; no parser substitution claim'],
                  game_launched=False, installed_in_game=False, stage4_complete=False, commands=[])
    env = dict(os.environ)
    env['PATH'] = str(compiler.parent) + os.pathsep + str(args.cmake.parent) + os.pathsep + env.get('PATH', '')
    binary = build / 'gameplay_world/scripted_motion_assets_tests.exe'
    commands = [('configure', [str(args.cmake), '-S', str(ROOT / 'game/native'), '-B', str(build), '-DREO_SCRIPTED_MOTION_REFERENCE_DIR=' + str(out)]),
                ('build', [str(args.cmake), '--build', str(build), '--parallel', '2', '--target', 'scripted_motion_assets_tests']),
                ('test', [str(binary), str(archive), str(out / 'owned-members.txt')])]
    try:
        for label, command in commands:
            result = subprocess.run(command, env=env, capture_output=True, timeout=180)
            (out / (label + '.stdout.txt')).write_bytes(result.stdout)
            (out / (label + '.stderr.txt')).write_bytes(result.stderr)
            record['commands'].append(dict(command=command, exit_code=result.returncode))
            assert result.returncode == 0, label + ' ' + result.stdout.decode(errors='replace')[-2500:] + result.stderr.decode(errors='replace')[-2500:]
            if label == 'test':
                record['observed'] = json.loads(result.stdout)
        assert all(sha(ROOT / name) == digest for name, digest in before.items())
        assert (archive.stat().st_size, archive.stat().st_mtime_ns) == stamp
        record.update(status='passed', source_unchanged=True, binary_sha256=sha(binary))
    finally:
        record['output_sha256'] = {p.name: sha(p) for p in out.iterdir() if p.is_file()}
        (out / 'receipt.json').write_text(json.dumps(record, indent=2) + '\n')
    print(json.dumps(dict(status=record['status'], observed=record['observed'])))


if __name__ == '__main__':
    main()
