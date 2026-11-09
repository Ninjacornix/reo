"""Bind native height-pass integration checks to its owned ordering source."""
import hashlib
import json
from pathlib import Path
import re
from audit_retail_effect_descriptors import compare_source

ROOT = Path(__file__).resolve().parents[2]


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    cohorts = {}
    common = None
    for compiler in ['llvm', 'gcc']:
        path = ROOT / f'build-native-sjuni/gameplay-collision-phase-{compiler}-v1/receipt.json'
        receipt = json.loads(path.read_text())
        assert receipt['status'] == 'passed' and receipt['result']['checks'] == 25
        if common is None:
            common = receipt['source_sha256']
        assert common == receipt['source_sha256']
        for name, expected in common.items():
            assert digest(ROOT / name) == expected, name
            assert digest(path.parent / 'source' / name) == expected, name
        cohorts[compiler] = dict(path=path.relative_to(ROOT).as_posix(), sha256=digest(path),
                                 result=receipt['result'])
    image = ROOT / 'build-function-index/owned-overlays/o2.bin'
    assert digest(image) == '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    raw = image.read_bytes()
    source = 'recomp/config/output_ovl/o2/o2_005DA680_0x5da680.cpp'
    start, end = [int(value, 16) for value in re.search(
        r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)', (ROOT / source).read_text()).groups()]
    audit = compare_source('native collision-height pass ordering', source, start, end,
                           lambda address, count: raw[address - 0x570000:address - 0x570000 + count])
    dependencies = {}
    for name in ['native_gameplay_world_collision_qualification_v1.json',
                 'native_gameplay_secondary_ground_qualification_v1.json']:
        path = Path('tools/native_reconstruction') / name
        dependencies[path.as_posix()] = digest(ROOT / path)
    output = ROOT / 'tools/native_reconstruction/native_gameplay_collision_phase_qualification_v1.json'
    assert not output.exists()
    record = dict(schema=1, status='passed', stage4_complete=False, installed_in_game=False,
                  game_run=False, original_ordering_body_executed=False,
                  scope='static owned ordering plus real canonical primary/auxiliary/secondary integration and partial failures',
                  cohorts=cohorts, source_sha256=common, original_static_word_audit=audit,
                  dependencies=dependencies,
                  remaining=['Native auxiliary and secondary spawning/pose/wall owners',
                             'Game worker installation and acceptance'])
    output.write_text(json.dumps(record, indent=2) + '\n', encoding='utf8')
    print(digest(output))


if __name__ == '__main__':
    main()
