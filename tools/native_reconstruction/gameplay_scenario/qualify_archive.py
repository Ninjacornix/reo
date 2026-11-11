"""Seal the direct host scenario archive and owner binding comparison."""
import json
from pathlib import Path

from qualify_v18 import ROOT, QUALIFICATIONS, sha


def main():
    paths = [ROOT / 'build-native-sjuni' / f'gameplay-scenario-archive-{compiler}-v2' / 'receipt.json'
             for compiler in ('llvm', 'gcc')]
    records = [json.loads(path.read_bytes()) for path in paths]
    first, second = records
    assert first['source_sha256'] == second['source_sha256']
    assert first['result'] == second['result'] and first['members'] == second['members']
    assert first['result']['checks'] == 1924
    assert first['result']['members'] == 171 and first['result']['room_bindings'] == 51
    for receipt in records:
        assert receipt['status'] == 'passed'
        assert not receipt['game_launched'] and not receipt['installed_in_game'] and not receipt['stage4_complete']
    names = ['game/native/gameplay_scenario/scenario_archive.hpp',
             'game/native/gameplay_scenario/scenario_archive.cpp',
             'game/native/gameplay_scenario/scenario_archive_tests.cpp',
             'game/native/gameplay_scenario/CMakeLists.txt',
             'game/native/gameplay_update/script_setup.cpp',
             'game/native/gameplay_update/update.hpp',
             'runtime/assets/virtual_afs.h',
             'tools/native_reconstruction/gameplay_scenario/verify_archive.py']
    assert all(sha(ROOT / name) == first['source_sha256'][name] for name in names)
    document = ROOT / 'docs/native-gameplay/SCENARIO_ARCHIVE.md'
    result = dict(schema='reo.native.scenario.archive.qualification.v1', status='qualified_partial',
                  source_sha256={name: first['source_sha256'][name] for name in names},
                  documentation_and_tools_sha256={p.relative_to(ROOT).as_posix(): sha(p)
                                                   for p in (document, Path(__file__))},
                  receipts=[dict(path=p.relative_to(ROOT).as_posix(), sha256=sha(p),
                                 compiler_sha256=r['compiler_sha256'], result=r['result'])
                            for p, r in zip(paths, records)],
                  members=first['members'], stage4_complete=False, installed_in_game=False)
    output = QUALIFICATIONS / 'native_scenario_archive_qualification_v1.json'
    with output.open('x', encoding='utf-8') as target:
        target.write(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'path': str(output), 'sha256': sha(output), 'result': first['result']}))


if __name__ == '__main__':
    main()
