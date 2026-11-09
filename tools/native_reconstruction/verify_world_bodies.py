"""Snapshot and check canonical World body consumer/lifetime contracts.

Original geometry/solver parity belongs to the retained actor-view cohort.
This check exercises the actual motion caller and ownership adapter.
"""
import argparse
import hashlib
import json
import os
import re
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[2]
GROUPS = {
    'gameplay_world': ['world.hpp', 'world.cpp', 'motion.hpp', 'motion.cpp',
                       'bodies.hpp', 'bodies.cpp', 'bodies_tests.cpp'],
    'gameplay_actors': ['entity.hpp', 'entity.cpp', 'health.hpp', 'status.hpp',
                        'hit.hpp', 'input.hpp', 'input.cpp'],
    'gameplay_session': ['session.hpp', 'session.cpp'],
    'gameplay_collision': ['collision.hpp', 'collision.cpp', 'response.hpp',
                           'response.cpp', 'actors.hpp', 'actors.cpp',
                           'actor_views.hpp', 'actor_views.cpp', 'postmove_view.hpp',
                           'postmove.hpp', 'contact_component.hpp', 'hit_regions.hpp',
                           'spatial.hpp'],
}


def digest(body):
    return hashlib.sha256(body).hexdigest()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--compiler', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--consumer', choices=['bodies', 'heights'], default='bodies')
    args = parser.parse_args()
    output = args.output.resolve()
    assert output.is_relative_to(ROOT / 'build-native-sjuni') and not output.exists()
    groups = {group: list(names) for group, names in GROUPS.items()}
    if args.consumer == 'heights':
        groups['gameplay_world'] = ['world.hpp', 'world.cpp', 'collision.hpp', 'collision.cpp',
                                    'collision_phase.hpp', 'collision_phase.cpp', 'collision_phase_tests.cpp']
        groups['gameplay_collision'] += [name + '.cpp' for name in
            ['sweep', 'ownership', 'trace', 'room_objects', 'footprint', 'regions', 'postmove',
             'postmove_view', 'secondary_ground']]
        groups['transform_math'] = ['transform_math.hpp', 'transform_math.cpp']
    paths = [f'game/native/{group}/{name}' for group, names in groups.items() for name in names]
    # Retain the complete local include closure, including borrowed view types.
    for name in paths:
        for include in re.findall(r'^\s*#include "([^"]+)"', (ROOT / name).read_text(), re.M):
            dependency = ((ROOT / name).parent / include).resolve()
            assert dependency.is_relative_to(ROOT / 'game/native') and dependency.is_file()
            relative = dependency.relative_to(ROOT).as_posix()
            if relative not in paths:
                paths.append(relative)
    paths.append(Path(__file__).relative_to(ROOT).as_posix())
    frozen = {name: (ROOT / name).read_bytes() for name in paths}
    output.mkdir(parents=True)
    record = dict(schema=1, status='failed', stage4_complete=False, game_run=False,
                  installed_in_game=False, original_bodies_executed=False,
                  scope=('real motion registration, canonical body state and native lifetime contracts'
                         if args.consumer == 'bodies' else
                         'ordered native primary, auxiliary and secondary collision-height consumer'),
                  source_sha256={name: digest(body) for name, body in frozen.items()},
                  compiler_sha256=digest(args.compiler.read_bytes()))
    try:
        for name, body in frozen.items():
            target = output / 'source' / name
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes(body)
        executable = output / 'world-bodies.exe'
        command = [str(args.compiler), '-std=c++20', '-O2', '-Wall', '-Wextra', '-Wpedantic',
                   '-Werror', '-fno-fast-math', '-ffp-contract=off']
        command += [str(output / 'source' / name) for name in paths if name.endswith('.cpp')]
        command += ['-o', str(executable)]
        record['command'] = command
        env = dict(os.environ)
        env['PATH'] = str(args.compiler.resolve().parent) + os.pathsep + env.get('PATH', '')
        for label, cmd in [('compile', command), ('test', [str(executable)])]:
            result = subprocess.run(cmd, capture_output=True, env=env, timeout=120)
            (output / (label + '.stdout.txt')).write_bytes(result.stdout)
            (output / (label + '.stderr.txt')).write_bytes(result.stderr)
            assert result.returncode == 0, f'{label} failed; see retained output'
            if label == 'test':
                record['result'] = json.loads(result.stdout)
        assert all((ROOT / name).read_bytes() == body for name, body in frozen.items())
        record.update(status='passed', executable_sha256=digest(executable.read_bytes()))
    finally:
        (output / 'receipt.json').write_text(json.dumps(record, indent=2) + '\n', encoding='utf8')
    print(json.dumps(record['result']))


if __name__ == '__main__':
    main()
