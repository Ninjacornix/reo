"""Bounded original selector 0x15 probe; no native renderer equivalence claim."""
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
    output = parser.parse_args().output.resolve()
    assert not output.exists() and output.is_relative_to((ROOT / 'build-native-sjuni').resolve())
    output.mkdir()
    elf = ROOT / 'game_data/SLUS_207.65'
    assert sha(elf) == '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    read = elf_reader(elf.read_bytes())
    paths, audits = [], []
    for address in (0x1af780, 0x196010):
        path = next((ROOT / 'recomp/config/output').glob(f'sub_{address:08X}_*'))
        begin, end = (int(v, 16) for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)', path.read_text()).groups())
        audits.append(compare_source('complete graphics selector', path.relative_to(ROOT).as_posix(), begin, end, read))
        paths.append(path)
    extra = '\n#include "ps2_fpu_convert.h"\n#define FPU_CVT_W_S(v) Ps2FpuConvertWord(v)\n#define PS2_PCPYLD(a,b) _mm_unpacklo_epi64((b),(a))\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n'
    reference = (ROOT / 'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp').read_text()
    (output / 'reference.hpp').write_text(reference.replace('Register r[32];', 'std::uint64_t lo{},hi{};Register r[32];') + extra)
    body = '\n'.join(path.read_text() for path in paths)
    names = {path.stem for path in paths}
    calls = set(re.findall(r'\b(sub_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram', body))
    declarations = ''.join('void ' + name + '(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for name in sorted(names))
    declarations += ''.join('inline void ' + name + '(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n' for name in sorted(calls - names))
    (output / 'functions.h').write_text('#pragma once\n' + declarations)
    (output / 'original.cpp').write_text(body)
    for name in ('ps2_runtime.h', 'ps2_runtime_macros.h'):
        (output / name).write_text('#pragma once\n#include "reference.hpp"\n')
    (output / 'ps2_recompiled_functions.h').write_text('#pragma once\n#include "functions.h"\n')
    for name in ('ps2_recompiled_stubs.h', 'ps2_stubs.h', 'ps2_syscalls.h'):
        (output / name).write_text('#pragma once\n')
    fixture = ROOT / 'tools/native_reconstruction/presentation/frontend_format_original_probe.cpp'
    native_header = ROOT / 'game/native/gameplay_presentation/graphics_state.hpp'
    native_source = native_header.with_suffix('.cpp')
    executable = output / 'checks.exe'
    env = dict(os.environ, PATH=str(CC.parent) + os.pathsep + os.environ.get('PATH', ''))
    flags = [str(CC), '-std=c++20', '-O2', '-msse4.1', '-Wall', '-Wextra', '-Wpedantic', '-Werror',
             '-Wno-unused-label', '-Wno-unused-parameter', '-Wno-unused-variable', '-I' + str(output),
             '-I' + str(ROOT / 'third_party/PS2Recomp/ps2xRuntime/include')]
    commands = [('compile', flags + [str(output / 'original.cpp'), str(fixture), str(native_source), '-o', str(executable)]), ('run', [str(executable)])]
    receipt = {'status': 'failed', 'compiler_sha256': sha(CC), 'elf_sha256': sha(elf),
               'fixture_sha256': sha(fixture), 'driver_sha256': sha(Path(__file__)),
               'native_header_sha256': sha(native_header),
               'native_source_sha256': sha(native_source),
               'original_word_audits': audits, 'checks': [], 'game_run': False}
    try:
        for name, command in commands:
            start = time.monotonic()
            result = subprocess.run(command, capture_output=True, env=env, timeout=120)
            (output / (name + '.out')).write_bytes(result.stdout)
            (output / (name + '.err')).write_bytes(result.stderr)
            receipt['checks'].append({'name': name, 'seconds': time.monotonic() - start, 'exit': result.returncode})
            if result.returncode:
                raise RuntimeError(name + ': ' + result.stderr.decode(errors='replace')[-3000:])
        receipt['observed'] = json.loads((output / 'run.out').read_text())
        assert sha(native_header) == receipt['native_header_sha256']
        assert sha(native_source) == receipt['native_source_sha256']
        receipt['status'] = 'passed'
    finally:
        (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
    print(json.dumps(receipt['observed']))

if __name__ == '__main__':
    main()
