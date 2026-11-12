"""Seal actual contact constructors, channels, canonical pose owner and parents."""
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
from verify_gameplay_collision import COMPILERS

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    domain = ['game/native/gameplay_effects/' + name for name in (
        'contact_styles.hpp', 'contact_styles.cpp', 'actor_contact_channels.hpp',
        'actor_contact_channels.cpp', 'periodic_visuals.hpp', 'periodic_visuals.cpp', 'CMakeLists.txt')]
    domain += ['game/native/gameplay_world/' + name for name in (
        'world.hpp', 'actor_initial_state.hpp', 'primary_actor_records_tests.cpp',
        'contact_weapon_effects.hpp', 'contact_weapon_effects.cpp', 'weapon_fire.cpp', 'resource_actor_contact_pose.hpp')]
    domain += ['tools/native_reconstruction/' + name for name in (
        'effect_work_sources.py', 'verify_periodic_visuals.py', 'periodic_visuals_tests.cpp',
        'contact_styles_tests.inc', 'actor_contact_owner_tests.inc', 'verify_actor_contact_channels.py',
        'actor_contact_channels_tests.cpp', 'qualify_contact_effects_v1.py')]
    domain += ['docs/native-gameplay/CONTACT_EFFECTS.md']
    sources = {name: sha(ROOT / name) for name in domain}
    cohorts, observations, parents, builds = {}, {}, {}, {}
    cmake = Path('C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe')
    for compiler in ('llvm', 'gcc'):
        cohorts[compiler] = {}
        for family, stem, version in (
            ('owner', 'actor-contact-owner', 6), ('policy', 'actor-contact-policy', 2),
            ('bootstrap', 'contact-style-primary-clear', 1), ('periodic', 'contact-periodic-parent', 1)):
            path = ROOT / 'build-native-sjuni' / f'{stem}-{compiler}-v{version}/receipt.json'
            record = json.loads(path.read_bytes())
            assert record['status'] == 'passed' and record['source_unchanged']
            if family in observations:
                assert observations[family] == record['observed'], family
            observations[family] = record['observed']
            changes = {}
            for name, digest in record['source_sha256'].items():
                assert sha(path.parent / 'source' / name) == digest, name
                current = sha(ROOT / name)
                if current != digest:
                    changes[name] = {'qualified': digest, 'current': current}
                if family == 'owner' and name in sources:
                    assert current == digest, name
            if family == 'bootstrap':
                for name in ('game/native/gameplay_world/actor_initial_state.hpp', 'game/native/gameplay_world/primary_actor_records_tests.cpp'):
                    assert record['source_sha256'][name] == sources[name], name
            if family == 'policy':
                for name in ('game/native/gameplay_effects/actor_contact_channels.hpp', 'game/native/gameplay_effects/actor_contact_channels.cpp'):
                    assert record['source_sha256'][name] == sources[name], name
            cohorts[compiler][family] = {
                'path': path.relative_to(ROOT).as_posix(), 'sha256': sha(path), 'observed': record['observed'],
                'compiler_sha256': record['compiler_sha256'], 'subsequent_dependency_changes': changes}
        assert observations['owner']['channel_owner_cases'] == 384 and observations['owner']['channel_owner_frames'] == 8648
        assert observations['owner']['contact_selectors'] == 65536 and observations['policy']['cases'] == 5242880
        baseline = ROOT / 'build-native-sjuni' / f'session-rooms-parents-{compiler}-v1/receipt.json'
        prior = json.loads(baseline.read_bytes())
        assert prior['status'] == 'passed' and not prior['source_drift'] and prior['parent_tests'] == 22
        out = ROOT / 'build-native-sjuni' / f'contact-effects-parents-{compiler}-v1'
        assert not out.exists()
        out.mkdir()
        frozen = {name: (ROOT / name).read_bytes() for name in sorted(set(prior['source_sha256']) | set(domain))}
        for name, contents in frozen.items():
            path = out / 'source' / name
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_bytes(contents)
        env = dict(os.environ)
        env['PATH'] = str(COMPILERS[compiler].parent) + os.pathsep + env.get('PATH', '')
        build = ROOT / 'build-native-sjuni' / f'gameplay-native-{compiler}-v1'
        command = [str(cmake), '--build', str(build), '--target', 'reo_native_contact_weapon_effects', '--parallel', '2']
        result = subprocess.run(command, cwd=ROOT, capture_output=True, env=env, timeout=300)
        (out / 'contact-build.log').write_bytes(result.stdout + result.stderr)
        assert result.returncode == 0, result.stdout.decode(errors='replace') + result.stderr.decode(errors='replace')
        libraries = [build / 'gameplay_effects' / f'libreo_native_{name}.a' for name in ('gameplay_effects', 'periodic_visuals', 'contact_weapon_effects')]
        libraries += [build / 'gameplay_world/libreo_native_weapon_actions.a']
        builds[compiler] = {'command': command, 'returncode': 0, 'libraries': {p.relative_to(ROOT).as_posix(): sha(p) for p in libraries}}
        for label, cmd in zip(('build', 'tests'), prior['commands']):
            result = subprocess.run(cmd, cwd=ROOT, capture_output=True, env=env, timeout=600)
            (out / (label + '.log')).write_bytes(result.stdout + result.stderr)
            assert result.returncode == 0, label + ' failed; see ' + str(out)
            if label == 'tests':
                assert b'100% tests passed, 0 tests failed out of 22' in result.stdout
        drift = {name: sha(ROOT / name) for name, contents in frozen.items() if (ROOT / name).read_bytes() != contents}
        assert not drift, drift
        parent = dict(schema=1, status='passed', parent_tests=22, game_run=False, installed_in_game=False,
                      stage4_complete=False, source_sha256={name: hashlib.sha256(contents).hexdigest() for name, contents in frozen.items()},
                      source_drift=drift, commands=prior['commands'], baseline={'path': baseline.relative_to(ROOT).as_posix(), 'sha256': sha(baseline)},
                      output_sha256={p.relative_to(out).as_posix(): sha(p) for p in out.glob('*.log')})
        receipt = out / 'receipt.json'
        receipt.write_text(json.dumps(parent, indent=2) + '\n')
        parents[compiler] = {'path': receipt.relative_to(ROOT).as_posix(), 'sha256': sha(receipt), 'parent_tests': 22}
    assert sources == {name: sha(ROOT / name) for name in domain}
    output = ROOT / 'tools/native_reconstruction/native_contact_effects_qualification_v1.json'
    assert not output.exists()
    record = dict(schema=1, status='passed', game_run=False, installed_in_game=False, stage4_complete=False,
                  source_sha256=sources, cohorts=cohorts, current_parent_tests=parents, cmake_builds=builds,
                  limits=['Policy-only pose/clone/sample/release ports are superseded by complete original owner comparisons in the composed cohort.',
                          'Owned banks retain actual missing-resource outcomes; canonical weapon-model matrices are explicit fixture inputs.',
                          'Native generation refusal replaces unsafe original pointer reuse.',
                          'Pose-work family5823E0, complete host adoption, renderer integration and installed game acceptance remain open.'])
    output.write_text(json.dumps(record, indent=2) + '\n')
    print(sha(output))


if __name__ == '__main__':
    main()
