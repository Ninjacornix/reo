"""Seal the native launch roster and normal Update entry-point comparison."""
import json
from pathlib import Path

from qualify_v18 import QUALIFICATIONS, ROOT, sha
from qualify_v19 import read_cohort


def main():
    records, references = read_cohort('gameplay-scenario-launch-roster-{compiler}-v1')
    first, second = records
    assert first['source_sha256'] == second['source_sha256']
    assert first['result'] == second['result']
    result = first['result']
    assert result['launch_roster_cases'] == 4096
    assert result['launch_roster_refusals'] == 6
    parents = []
    for compiler, receipt in zip(('llvm', 'gcc'), records):
        assert not receipt['game_launched'] and not receipt['pinned_shared_sources']
        build = ROOT / 'build-native-sjuni'
        for kind in ('parent', 'tests'):
            log = build / f'launch-roster-{kind}-{compiler}-v1.log'
            raw = log.read_bytes()
            text = raw.decode('utf-16') if raw.startswith(b'\xff\xfe') else raw.decode('utf-8')
            if kind == 'tests':
                assert '100% tests passed, 0 tests failed out of 7' in text
            parents.append(dict(path=log.relative_to(ROOT).as_posix(), sha256=sha(log)))
    document = ROOT / 'docs/native-gameplay/LAUNCH_ROSTER.md'
    qualification = dict(
        schema='reo.native.launch.roster.qualification.v1', status='qualified_partial',
        source_sha256=first['source_sha256'],
        original_sources_sha256=first['original_sources_sha256'],
        documentation_and_tools_sha256={p.relative_to(ROOT).as_posix(): sha(p)
                                       for p in (document, Path(__file__))},
        receipts=references, parent_logs=parents, result=result,
        limitations=['Initialization requires existing canonical actor leases.',
                     'Actor/model creation and actual launch caller installation remain open.',
                     'Coherent native gameplay acceptance remains open.'],
        installed_in_game=False, stage4_complete=False)
    output = QUALIFICATIONS / 'native_launch_roster_qualification_v1.json'
    with output.open('x', encoding='utf-8') as target:
        target.write(json.dumps(qualification, indent=2) + '\n')
    print(json.dumps({'path': str(output), 'sha256': sha(output), 'checks': result['checks']}))


if __name__ == '__main__':
    main()
