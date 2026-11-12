"""Seal complete resource-flight policy, canonical owner and firing adapter."""
import hashlib
import json
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    domain = ['game/native/gameplay_effects/' + name for name in (
        'resource_flight.hpp', 'resource_flight.cpp', 'resource_flight_profile.inc',
        'resource_flight_queries.hpp', 'resource_flight_queries.cpp',
        'periodic_visuals.hpp', 'periodic_visuals.cpp', 'CMakeLists.txt')]
    domain += ['game/native/gameplay_world/' + name for name in (
        'animation_audio.hpp', 'animation_audio.cpp', 'resource_flight_audio.hpp',
        'resource_flight_audio.cpp', 'flight_weapon_effects.hpp', 'flight_weapon_effects.cpp')]
    domain += ['tools/native_reconstruction/' + name for name in (
        'effect_work_sources.py', 'verify_periodic_visuals.py', 'periodic_visuals_tests.cpp',
        'generate_resource_flight_profile.py', 'verify_resource_flight.py',
        'resource_flight_tests.cpp', 'resource_flight_owner_tests.inc', 'qualify_resource_flight_v1.py')]
    domain += ['docs/native-gameplay/RESOURCE_FLIGHT.md']
    sources = {name: sha(ROOT / name) for name in domain}
    cohorts = {}
    parents = {}
    observations = {}
    for compiler in ('llvm', 'gcc'):
        cohorts[compiler] = {}
        for family, version in (('policy', 4), ('owner', 4), ('periodic-parent', 1)):
            path = ROOT / 'build-native-sjuni' / f'resource-flight-{family}-{compiler}-v{version}/receipt.json'
            record = json.loads(path.read_bytes())
            assert record['status'] == 'passed' and record['source_unchanged']
            if family in observations:
                assert observations[family] == record['observed'], family
            observations[family] = record['observed']
            changes = {}
            for name, digest in record['source_sha256'].items():
                assert sha(path.parent / 'source' / name) == digest, name
                if name in sources:
                    assert sources[name] == digest, name
                current = sha(ROOT / name)
                if current != digest:
                    changes[name] = {'qualified': digest, 'current': current}
            cohorts[compiler][family] = {
                'path': path.relative_to(ROOT).as_posix(), 'sha256': sha(path),
                'observed': record['observed'], 'compiler_sha256': record['compiler_sha256'],
                'subsequent_dependency_changes': changes}
            if family == 'owner':
                for key in ('flight_geometry_parent', 'flight_cue_asset', 'declared_ports'):
                    cohorts[compiler][family][key] = record[key]
                for name in ('owned_flight_cue.bin', 'owned_flight_walls.bin', 'owned_flight_floors.bin'):
                    assert sha(path.parent / name) == record['output_sha256'][name], name
        path = ROOT / 'build-native-sjuni' / f'script-resource-activation-parents-{compiler}-v2/receipt.json'
        record = json.loads(path.read_bytes())
        assert record['status'] == 'passed' and not record['source_drift'] and record['parent_tests'] == 19
        parents[compiler] = {'path': path.relative_to(ROOT).as_posix(), 'sha256': sha(path),
                             'parent_tests': record['parent_tests']}
    assert observations['policy']['constructors'] == 32768
    assert observations['policy']['cases'] == 1310720
    assert observations['owner']['flight_owner_frames'] == 12408
    assert observations['owner']['flight_signal_samples'] == 2172728
    builds = {}
    cmake = 'C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe'
    for compiler in ('llvm', 'gcc'):
        build = ROOT / 'build-native-sjuni' / f'gameplay-native-{compiler}-v1'
        command = [cmake, '--build', str(build), '--target', 'reo_native_weapon_flight_effects', '--parallel', '2']
        result = subprocess.run(command, cwd=ROOT, capture_output=True, timeout=300)
        assert result.returncode == 0, result.stdout.decode(errors='replace') + result.stderr.decode(errors='replace')
        names = ('gameplay_effects', 'periodic_visuals', 'resource_flight_audio', 'weapon_flight_effects')
        libraries = [build / 'gameplay_effects' / f'libreo_native_{name}.a' for name in names]
        builds[compiler] = {'command': command, 'returncode': result.returncode,
                            'output': result.stdout.decode(errors='replace'),
                            'libraries': {p.relative_to(ROOT).as_posix(): sha(p) for p in libraries}}
    assert sources == {name: sha(ROOT / name) for name in domain}
    output = ROOT / 'tools/native_reconstruction/native_resource_flight_qualification_v1.json'
    assert not output.exists()
    record = dict(schema=1, status='passed', game_run=False, installed_in_game=False,
                  stage4_complete=False, source_sha256=sources, cohorts=cohorts,
                  current_parent_tests=parents, cmake_builds=builds,
                  limits=['Original geometry allocation/render lookup/retirement are declared oracle ports.',
                          'Room trace ports use independently qualified native traces on retained owned grids.',
                          'Cue bank assignment is an explicit fixture; no installed game bank setup claim.',
                          'Other weapon families, renderer installation and full gameplay acceptance remain open.'])
    output.write_text(json.dumps(record, indent=2) + '\n')
    print(sha(output))


if __name__ == '__main__':
    main()
