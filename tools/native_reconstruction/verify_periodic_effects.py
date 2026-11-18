"""Compare native periodic task/timing policy to complete owned original bodies."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
from audit_retail_effect_descriptors import compare_source, elf_reader

ROOT = Path(__file__).resolve().parents[2]


def sha(body):
    return hashlib.sha256(body).hexdigest()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--compiler', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--scenario-ref')
    args = parser.parse_args()
    output = args.output.resolve()
    assert output.is_relative_to(ROOT / 'build-native-sjuni') and not output.exists()
    revision = subprocess.check_output(['git','rev-parse',args.scenario_ref+'^{commit}'],cwd=ROOT,text=True).strip() if args.scenario_ref else None
    def read_source(name):
        if revision and name.startswith('game/native/gameplay_scenario/') and not Path(name).name.startswith('periodic_effects.'):
            return subprocess.check_output(['git','show',revision+':'+name],cwd=ROOT)
        return (ROOT/name).read_bytes()
    overlay = (ROOT / 'build-function-index/owned-overlays/o2.bin').read_bytes()
    assert sha(overlay) == '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    elf = (ROOT / 'game_data/SLUS_207.65').read_bytes()
    assert sha(elf) == '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    original = [next((ROOT / 'recomp/config/output_ovl/o2').glob('o2_' + name + '_*')).relative_to(ROOT).as_posix()
                for name in ['005D9630', '00573890', '005D9680', '005DDC70', '005709B0', '00570A10']]
    original.append('recomp/config/output/sub_001AEC80_0x1aec80.cpp')
    audits = []
    for name in original:
        start, end = [int(value, 16) for value in re.search(r'// Address: (0x[\da-f]+) - (0x[\da-f]+)', (ROOT / name).read_text()).groups()]
        reader = elf_reader(elf) if start < 0x570000 else lambda address, size: overlay[address - 0x570000:address - 0x570000 + size]
        audits.append(compare_source('complete periodic effect task policy', name, start, end, reader))
    units = ['game/native/gameplay_scenario/' + name + '.cpp' for name in ['periodic_effects', 'scene_controls', 'flags']]
    units += ['game/native/gameplay_session/session.cpp', 'game/native/gameplay_tasks/tasks.cpp']
    paths = list(units)
    frozen = {}
    for name in paths:
        body = read_source(name);frozen[name] = body
        for include in re.findall(r'^\s*#include "([^"]+)"', body.decode(), re.M):
            local = ((ROOT / name).parent / include).resolve()
            dependency = local if local.is_file() else (ROOT / include).resolve()
            assert dependency.is_relative_to(ROOT / 'game/native') and dependency.is_file(), (name, include)
            relative = dependency.relative_to(ROOT).as_posix()
            if relative not in paths:paths.append(relative)
    fixture = 'tools/native_reconstruction/gameplay_scenario/periodic_effects_tests.cpp'
    runtime = 'tools/native_reconstruction/gameplay_actor_oracle/status_runtime.hpp'
    for name in original + [fixture, runtime, Path(__file__).relative_to(ROOT).as_posix()]:
        frozen[name] = read_source(name)
    output.mkdir(parents=True)
    record = dict(schema=1, status='failed', stage4_complete=False, game_run=False, installed_in_game=False,
                  original_bodies=audits, source_sha256={name: sha(body) for name, body in frozen.items()},
                  compiler_sha256=sha(args.compiler.read_bytes()),
                  declared_ports=['573630 native qualified scheduler allocation profile', '573740 native qualified scheduler removal profile',
                                  '6525D0 required actual native visual/resource owner; fixture emission is not full effect creation'],
                  full_visual_pipeline=False, scenario_source_commit=revision)
    try:
        for name, body in frozen.items():
            target = output / 'source' / name;target.parent.mkdir(parents=True, exist_ok=True);target.write_bytes(body)
        (output / 'tests.cpp').write_bytes(frozen[fixture])
        surroundings = frozen[runtime].decode().replace(
            '#define SET_GPR_U32(c,n,v) ((c)->r[n][0]=static_cast<std::uint32_t>(v))',
            '#define SET_GPR_U32(c,n,v) SET_GPR_S32(c,n,v)')
        surroundings += '\n#define SRA32(a,b) (static_cast<std::int32_t>(a) >> (static_cast<unsigned>(b)&31))\n#define SRL32(a,b) (static_cast<std::uint32_t>(a) >> (static_cast<unsigned>(b)&31))\n'
        (output / 'runtime.hpp').write_text(surroundings, encoding='utf8')
        for name in ['ps2_runtime.h', 'ps2_runtime_macros.h']:
            (output / name).write_text('#pragma once\n#include "runtime.hpp"\n')
        for name in ['ps2_recompiled_stubs.h', 'ps2_syscalls.h', 'ps2_stubs.h']:
            (output / name).write_text('#pragma once\n')
        body = '\n'.join(frozen[name].decode() for name in original)
        (output / 'original_periodic.cpp').write_text(body, encoding='utf8')
        actual = {Path(name).stem for name in original}
        calls = set(re.findall(r'\b((?:o2|sub)_[0-9A-Fa-f]+_0x[\da-f]+)\(rdram', body))
        declarations = ''.join('void ' + name + '(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for name in sorted(actual))
        declarations += ''.join('inline void ' + name + '(std::uint8_t* r,R5900Context* c,PS2Runtime* t){original_port(r,c,t);}\n' for name in sorted(calls - actual))
        (output / 'functions.h').write_text('#pragma once\nvoid original_port(std::uint8_t*,R5900Context*,PS2Runtime*);\n' + declarations)
        for name in ['o2_functions.h', 'ps2_recompiled_functions.h']:(output / name).write_text('#pragma once\n#include "functions.h"\n')
        executable = output / 'periodic.exe'
        command = [str(args.compiler), '-std=c++20', '-O2', '-Wall', '-Wextra', '-Wpedantic', '-Werror', '-Wno-unused-label',
                   '-fno-fast-math', '-ffp-contract=off', '-I' + str(output), '-I' + str(output / 'source')]
        command += [str(output / 'source' / name) for name in units] + [str(output / 'tests.cpp'), '-o', str(executable)]
        record['command'] = command
        env = dict(os.environ);env['PATH'] = str(args.compiler.resolve().parent) + os.pathsep + env.get('PATH', '')
        for label, cmd in [('compile', command), ('test', [str(executable)])]:
            result = subprocess.run(cmd, env=env, capture_output=True, timeout=180)
            (output / (label + '.stdout.txt')).write_bytes(result.stdout);(output / (label + '.stderr.txt')).write_bytes(result.stderr)
            assert result.returncode == 0, f'{label} failed; see retained output'
            if label == 'test':record['result'] = json.loads(result.stdout)
        assert all(read_source(name) == body for name, body in frozen.items())
        record.update(status='passed', executable_sha256=sha(executable.read_bytes()))
    finally:(output / 'receipt.json').write_text(json.dumps(record, indent=2) + '\n', encoding='utf8')
    print(json.dumps(record['result']))


if __name__ == '__main__':
    main()
