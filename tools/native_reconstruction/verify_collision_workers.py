"""Seal and run native World/motion/pose/collision-worker composition checks."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess

ROOT = Path(__file__).resolve().parents[2]
UNITS = {
    'gameplay_world': ['world', 'behavior', 'surfaces', 'collision', 'collision_phase',
                       'motion', 'motion_transforms', 'surface_orientation', 'surface_orientation_math', 'bodies'],
    'gameplay_actors': ['entity', 'input', 'health', 'status', 'hit'],
    'gameplay_session': ['session'],
    'gameplay_collision': ['collision', 'response', 'actors', 'actor_views', 'sweep', 'ownership',
                           'trace', 'room_objects', 'footprint', 'regions', 'postmove',
                           'postmove_view', 'secondary_ground'],
    'gameplay_update': ['update', 'collision_workers', 'collision_workers_tests'],
    'gameplay_tasks': ['tasks', 'events'],
    'gameplay_scenario': ['interpreter', 'flags', 'offline', 'scene_resources', 'scene_controls',
                          'content', 'sequence_control', 'lighting', 'stream_channels', 'scene_models'],
    'transform_math': ['transform_math'],
}


def sha(body):
    return hashlib.sha256(body).hexdigest()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--compiler', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--scenario-ref', required=True)
    args = parser.parse_args()
    output = args.output.resolve()
    assert output.is_relative_to(ROOT / 'build-native-sjuni') and not output.exists()
    revision = subprocess.check_output(['git', 'rev-parse', args.scenario_ref + '^{commit}'], cwd=ROOT, text=True).strip()
    def read(name):
        if name.startswith('game/native/gameplay_scenario/'):
            return subprocess.check_output(['git', 'show', revision + ':' + name], cwd=ROOT)
        return (ROOT / name).read_bytes()
    units = [f'game/native/{group}/{name}.cpp' for group, names in UNITS.items() for name in names]
    paths = list(units)
    frozen = {}
    for name in paths:
        body = read(name)
        frozen[name] = body
        for include in re.findall(r'^\s*#include "([^"]+)"', body.decode(), re.M):
            local = ((ROOT / name).parent / include).resolve()
            dependency = local if local.is_file() else (ROOT / include).resolve()
            assert dependency.is_relative_to(ROOT / 'game/native') and dependency.is_file(), (name, include)
            relative = dependency.relative_to(ROOT).as_posix()
            if relative not in paths:
                paths.append(relative)
    tool = Path(__file__).relative_to(ROOT).as_posix()
    frozen[tool] = read(tool)
    output.mkdir(parents=True)
    record = dict(schema=1, status='failed', stage4_complete=False, game_run=False,
                  installed_in_game=False, original_bodies_executed=False,
                  scope='real native World, local motion, pose, body and height worker composition; declared behavior/secondary-wall fixtures',
                  scenario_source_commit=revision,
                  source_sha256={name: sha(body) for name, body in frozen.items()},
                  compiler_sha256=sha(args.compiler.read_bytes()))
    try:
        for name, body in frozen.items():
            destination = output / 'source' / name
            destination.parent.mkdir(parents=True, exist_ok=True)
            destination.write_bytes(body)
        executable = output / 'collision-workers.exe'
        command = [str(args.compiler), '-std=c++20', '-O2', '-Wall', '-Wextra', '-Wpedantic', '-Werror',
                   '-fno-fast-math', '-ffp-contract=off', '-I' + str(output / 'source')]
        command += [str(output / 'source' / name) for name in units]
        command += ['-o', str(executable)]
        record['command'] = command
        env = dict(os.environ)
        env['PATH'] = str(args.compiler.resolve().parent) + os.pathsep + env.get('PATH', '')
        for label, cmd in [('compile', command), ('test', [str(executable)])]:
            result = subprocess.run(cmd, capture_output=True, env=env, timeout=240)
            (output / (label + '.stdout.txt')).write_bytes(result.stdout)
            (output / (label + '.stderr.txt')).write_bytes(result.stderr)
            assert result.returncode == 0, f'{label} failed; see retained output'
            if label == 'test':
                record['result'] = json.loads(result.stdout)
                assert record['result']['checks'] > 100
        assert all(read(name) == body for name, body in frozen.items())
        record.update(status='passed', executable_sha256=sha(executable.read_bytes()))
    finally:
        (output / 'receipt.json').write_text(json.dumps(record, indent=2) + '\n', encoding='utf8')
    print(json.dumps(record['result']))


if __name__ == '__main__':
    main()
