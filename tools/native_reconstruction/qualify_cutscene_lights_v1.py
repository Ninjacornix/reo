"""Seal the qualified cinematic-light owner and reached archive corrections."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    sources = [
        'game/native/gameplay_scenario/' + name + extension
        for name in ['cutscene_light_curves', 'cutscene_lights', 'lighting',
                     'cutscene_playback', 'cutscene_descriptor_loader', 'scenario_archive']
        for extension in ['.hpp', '.cpp']
    ] + [
        'docs/native-gameplay/CUTSCENE_LIGHTS.md',
        'docs/native-gameplay/CUTSCENE_VIEW_CONTROLS.md',
    ] + ['tools/native_reconstruction/' + name for name in [
        'cutscene_light_curves_tests.cpp', 'cutscene_lights_tests.cpp',
        'cutscene_lights_assets_tests.cpp', 'cutscene_light_controller_tests.inc',
        'cutscene_playback_tests.cpp', 'cutscene_descriptor_loader_tests.cpp',
        'verify_cutscene_light_curves.py', 'verify_cutscene_lights.py',
        'verify_cutscene_playback.py', 'verify_cutscene_descriptor_loader.py',
        'verify_descriptor_workspace.py', 'qualify_cutscene_lights_v1.py',
    ]]
    current = {name: digest(ROOT / name) for name in sources}
    receipts = {}
    loaded = []
    cohorts = [
        ('policy', 'cutscene-light-curves-{}-v3'),
        ('owner', 'cutscene-lights-{}-v7'),
        ('controller', 'cutscene-playback-{}-v23'),
        ('sector_workspace', 'descriptor-workspace-{}-v4'),
        ('corrective_loader', 'cutscene-descriptor-loader-{}-v9'),
        ('current_assets', 'scenario-events-lights-assets-{}-v3'),
        ('current_parents', 'scenario-events-parents-{}-v1'),
    ]
    for role, pattern in cohorts:
        for compiler in ['llvm', 'gcc']:
            path = ROOT / 'build-native-sjuni' / pattern.format(compiler) / 'receipt.json'
            value = json.loads(path.read_text())
            assert value['status'] == 'passed', path
            assert value.get('source_unchanged', True), path
            assert not value.get('source_drift') and not value.get('owned_source_drift'), path
            for proof in value.get('original_owned_bodies', []):
                assert proof['conflicts'] == 0 and proof['matched_comments'] > 0, path
            loaded.append(value)
            receipts[role + '_' + compiler] = {
                'path': path.relative_to(ROOT).as_posix(), 'sha256': digest(path),
                'compiler_sha256': value['compiler_sha256'],
                'observed': value.get('observed', value.get('result')),
                'parent_tests': value.get('parent_tests'),
                'source_unchanged': value.get('source_unchanged'),
                'source_drift': value.get('source_drift', value.get('owned_source_drift')),
            }
    tested = {}
    for name, expected in current.items():
        if name.startswith('docs/') or name.endswith('qualify_cutscene_lights_v1.py'):
            continue
        matches = [key for key, value in zip(receipts, loaded)
                   if value.get('source_sha256', {}).get(name) == expected]
        assert matches, ('owned source lacks a matching qualified snapshot', name)
        tested[name] = matches
    result = dict(
        schema=1, status='passed',
        scope='Complete cinematic light constructor/reset/tracks/interpolation over canonical Lighting and retained RoomResources, sole-controller adoption, and reached default-catalogue/physical-sector descriptor-loader correction.',
        game_run=False, device_opened=False, installed_in_game=False, stage4_complete=False,
        source_sha256=current, matching_qualified_snapshots=tested, receipts=receipts,
        current_integration_cmake_sha256=digest(ROOT / 'game/native/gameplay_scenario/CMakeLists.txt'),
        cmake_scope='Working integration hash includes independently owned pending registrations. This checkpoint stages only the light units and light-assets test stanza; each receipt preserves its complete actual CMake closure.',
        corrections={
            'superseded_commit': '5e262487081cbebaad9357db869f27620e22c9ae',
            'superseded_seal': 'tools/native_reconstruction/native_cutscene_view_controls_qualification_v1.json',
            'mode0': 'The older controlled-read fixture wrongly treated flags1 default lookup as a successful scenario read. All1342 owned default compiled keys now execute through original normalization; no DM name matches. Native mode0 preserves prior workspace and snapshot on the genuine missing read.',
            'storage': 'The older fixture returned logical member bytes. Original1A9F20/129C08/130E40 return whole sectors. Native reads actual archive padding and places its marker after that storage extent; no manufactured padding. Workspace v4 and loader v9 supersede the physical-boundary claim. Pure logical descriptor import remains separate valid component evidence.',
        },
        limits=[
            'Policy617000 is a numeric material seam; owner/controller617000 is the independently qualified actual native Grid seam. Complete616F60 and child value helpers execute. No original grid body is claimed by these cohorts.',
            'Owner proof uses exact copied SessionRooms v6 archives and matching headers, complete current Lighting.cpp, and new light units. Controller v23 compiles its current native source. Current-assets v3 and parent28 v1 establish the current D1/ScenarioArchive/trail registration ABI and link closure.',
            'Corrective loader executes11 complete original source bodies and all1342 encoded default keys. SDK task allocation/actual-sector transfer/completion/close and bounded standard string/format primitives remain explicit fixtures; independent AFS range proof supplies sector metadata.',
            'Finite FP32 nearest-rounding profile; exceptional physical PS2 numeric equivalence, SDK disk scheduling, complete scene/movie lifecycle, remaining frame workers, renderer/session/game installation and fullStep4 are not established.',
        ],
    )
    destination = ROOT / 'tools/native_reconstruction/native_cutscene_lights_qualification_v1.json'
    destination.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'receipts': len(receipts),
                      'sources': len(sources), 'seal_sha256': digest(destination)}))


if __name__ == '__main__':
    main()
