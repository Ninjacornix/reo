"""Original secondary-ground bodies, real floor relocation and native reference views."""
import argparse, hashlib, json, os, re, subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source, elf_reader
from verify_gameplay_collision import COMPILERS
from verify_gameplay_collision_response import PROFILES as RESPONSE
ROOT = Path(__file__).resolve().parents[2]
EXTRA = [('o2', '00637740', 0x637740), ('o2', '00637860', 0x637860),
         ('o2', '006379D0', 0x6379d0), ('o2', '00634DF0', 0x634df0),
         ('o2', '00616ED0', 0x616ed0), ('o2', '00616F20', 0x616f20),
         ('o2', '00616FA0', 0x616fa0), ('o2', '00616720', 0x616720),
         ('o2', '006172F0', 0x6172f0), ('o0', '00371480', 0x371480),
         ('main', '00191EF0', 0x191ef0)]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def source_path(overlay, number, start):
    return ROOT / (f'recomp/config/output/sub_{number}_0x{start:x}.cpp' if overlay == 'main'
                   else f'recomp/config/output_ovl/{overlay}/{overlay}_{number}_0x{start:x}.cpp')


def main():
    p = argparse.ArgumentParser()
    p.add_argument('--compiler', choices=COMPILERS, required=True)
    p.add_argument('--output', type=Path, required=True)
    a = p.parse_args()
    out = a.output.resolve()
    allowed = (ROOT / 'build-native-sjuni').resolve()
    if out.exists() or out == allowed or not out.is_relative_to(allowed):
        raise ValueError('Fresh private output required')
    profiles = list(RESPONSE)
    for o, n, start in EXTRA:
        text = source_path(o, n, start).read_text()
        end = int(re.search(r'// Address: 0x[0-9a-fA-F]+ - 0x([0-9a-fA-F]+)', text)[1], 16)
        profiles.append((o, n, start, end))
    sources, bodies, audits = [], [], []
    for o, n, start, end in profiles:
        image = ROOT / ('game_data/SLUS_207.65' if o == 'main'
                        else f'build-function-index/owned-overlays/{o}.bin')
        expected = {'main': '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46',
                    'o0': 'bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2',
                    'o2': '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'}[o]
        if sha(image) != expected:
            raise ValueError('Owned source image changed')
        data = image.read_bytes()
        base = 0x370000 if o == 'o0' else 0x570000
        read = elf_reader(data) if o == 'main' else lambda at, size: data[at-base:at-base+size]
        source = source_path(o, n, start)
        sources.append(source)
        audits.append(compare_source('secondary-ground-original', str(source.relative_to(ROOT)), start, end, read))
        text = source.read_text()
        bodies.append(text[text.index('// Function:'):])
    base_header = ROOT / 'tools/native_reconstruction/gameplay_collision_oracle/response_reference.hpp'
    ports = ROOT / 'tools/native_reconstruction/gameplay_collision_oracle/secondary_ground_ports.hpp'
    header = base_header.read_text().replace('#include "reference.hpp"', '#include "tools/native_reconstruction/gameplay_collision_oracle/reference.hpp"')
    for name in ['o2_00616720_0x616720', 'o2_006172F0_0x6172f0']:
        header = re.sub(r'RESPONSE_PORT\(' + name + r',[^\n]+\)', '', header)
    for name in ['o0_00371480_0x371480', 'sub_0018FDF0_0x18fdf0']:
        header = re.sub(r'inline void ' + name + r'[^\n]+\n', '', header)
    names = [('sub' if o == 'main' else o, n, start) for o, n, start in EXTRA]
    declarations = '\n'.join(f'void {o}_{n}_0x{start:x}(std::uint8_t*,R5900Context*,PS2Runtime*);' for o, n, start in names)
    marker = 'inline PS2Runtime::Fn PS2Runtime::lookupFunction(std::uint32_t at)const{'
    header = header.replace(marker, declarations + '\n' + ports.read_text() + '\n' + marker)
    cases = '\n'.join(f'    case 0x{start:x}:return {o}_{n}_0x{start:x};' for o, n, start in names if start not in [0x616720, 0x6172f0, 0x371480])
    cases += '\n case 0x5da420:return o2_005DA420_0x5da420;case 0x370320:return o0_00370320_0x370320;case 0x192180:return sub_00192180_0x192180;case 0x1919d0:return sub_001919D0_0x1919d0;\n'
    header = header.replace('    default:throw', cases + '    default:throw')
    native = ['game/native/gameplay_collision/' + n for n in
              ['secondary_ground.hpp', 'secondary_ground.cpp', 'secondary_ground_tests.cpp',
               'postmove_view.hpp', 'postmove.hpp', 'footprint.hpp', 'regions.hpp',
               'room_objects.hpp', 'ownership.hpp', 'actors.hpp', 'response.hpp',
               'response.cpp', 'collision.hpp', 'collision.cpp']]
    native += ['game/native/transform_math/transform_math.hpp', 'game/native/transform_math/transform_math.cpp',
               'game/native/gameplay_actors/entity.hpp', 'game/native/gameplay_actors/entity.cpp']
    paths = [ROOT / n for n in native] + [base_header, ports, Path(__file__), *sources,
              ROOT / 'tools/native_reconstruction/gameplay_collision_oracle/reference.hpp',
              ROOT / 'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h']
    before = {p.relative_to(ROOT).as_posix(): sha(p) for p in paths}
    out.mkdir()
    (out / 'secondary_reference.hpp').write_text(header)
    original = out / 'original.cpp'
    original.write_text('#include "secondary_reference.hpp"\n#pragma GCC diagnostic ignored "-Wunused-variable"\n' + '\n'.join(bodies))
    # Pin the full owned floor asset set, rather than relying on private file names.
    inventory = ROOT / 'build-native-sjuni/audio-asset-inventory/file1-v1/members.json'
    if sha(inventory) != '276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2':
        raise ValueError('Pinned owned inventory changed')
    selected = [e for e in json.loads(inventory.read_bytes())
                if any(re.fullmatch(r'g[0-9]{7}\.bin', name) for name in e['names'])]
    assets = []
    with (ROOT / 'iso/Resident Evil - Outbreak (v2.00).iso').open('rb') as stream:
        for e in selected:
            name = next(name for name in e['names'] if re.fullmatch(r'g[0-9]{7}\.bin', name))
            stream.seek(e['iso_offset'])
            body = stream.read(e['bytes'])
            if hashlib.sha256(body).hexdigest() != e['sha256']:
                raise ValueError('Owned floor asset changed')
            path = out / (str(len(assets)) + '-' + name)
            path.write_bytes(body)
            assets.append((path, e))
    asset_list = out / 'asset-list.txt'
    asset_list.write_text('\n'.join(str(path) for path, _ in assets) + '\n')
    compiler = COMPILERS[a.compiler]
    env = dict(os.environ)
    env['PATH'] = str(compiler.parent) + os.pathsep + env.get('PATH', '')
    exe = out / 'secondary.exe'
    record = dict(schema=1, status='failed', compiler_sha256=sha(compiler), source_sha256=before,
                  original_word_audits=audits, game_launched=False, checks=[], owned_assets=[e for _, e in assets])
    data = (ROOT / 'build-function-index/owned-overlays/o2.bin').read_bytes()
    record['owned_constants'] = {hex(at): dict(bytes=data[at-0x570000:at-0x570000+size].hex(),
                               sha256=hashlib.sha256(data[at-0x570000:at-0x570000+size]).hexdigest())
                               for at, size in [(0x740168, 4), (0x710638, 4)]}
    command = [str(compiler), '-std=c++20', '-O2', '-Wall', '-Wextra', '-Wpedantic', '-Werror',
               '-Wno-unused-parameter', '-fno-fast-math', '-ffp-contract=off', '-I'+str(ROOT), '-I'+str(out),
               *[str(ROOT / n) for n in ['game/native/gameplay_collision/secondary_ground.cpp',
                 'game/native/gameplay_collision/secondary_ground_tests.cpp',
                 'game/native/gameplay_collision/response.cpp', 'game/native/gameplay_collision/collision.cpp',
                 'game/native/transform_math/transform_math.cpp', 'game/native/gameplay_actors/entity.cpp']],
               str(original), '-o', str(exe)]
    try:
        for label, cmd in [('compile', command), ('test', [str(exe), str(asset_list)])]:
            result = subprocess.run(cmd, capture_output=True, env=env, timeout=180)
            (out / (label + '.stdout.txt')).write_bytes(result.stdout)
            (out / (label + '.stderr.txt')).write_bytes(result.stderr)
            record['checks'].append(dict(label=label, command=cmd, exit=result.returncode))
            if result.returncode:
                raise RuntimeError(label + ': ' + result.stderr.decode(errors='replace')[-3000:])
            if label == 'test':
                record['results'] = json.loads(result.stdout)
        for name, digest in before.items():
            if sha(ROOT / name) != digest:
                raise ValueError('Source drift: ' + name)
        record['status'] = 'native ordered secondary actor ground passes original bodies and owned floor assets'
    finally:
        record['output_sha256'] = {p.name: sha(p) for p in out.iterdir() if p.is_file()}
        (out / 'receipt.json').write_text(json.dumps(record, indent=2) + '\n')
    print(json.dumps(record['results']))


if __name__ == '__main__':
    main()
