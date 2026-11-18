"""Seal enemy priority initialization and owned linked model metadata."""
import json
from pathlib import Path

from qualify_v18 import QUALIFICATIONS, ROOT, sha
from qualify_v19 import read_cohort


def main():
    records, references = read_cohort('gameplay-enemy-initialization-{compiler}-v3')
    first, second = records
    assert first['source_sha256'] == second['source_sha256']
    assert first['result'] == second['result']
    result = first['result']
    assert result['enemy_priority_calls'] == 64792
    assert result['enemy_priority_refusals'] == 747
    assert result['linked_definition_cases'] == 16384
    linked = []
    parents = {}
    for compiler in ('llvm', 'gcc'):
        path = ROOT / 'build-native-sjuni' / f'animation-enemy-definitions-{compiler}-v2/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        assert all(sha(ROOT / name) == digest for name, digest in receipt['source_sha256'].items())
        assert receipt['observed']['checks'] == 195138
        assert receipt['observed']['original_calls'] == 1526661
        assert not receipt['game_run']
        linked.append(dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path),
                           observed=receipt['observed']))
        for kind in ('parent', 'tests'):
            log = ROOT / 'build-native-sjuni' / f'enemy-initialization-{kind}-{compiler}-v1.log'
            raw = log.read_bytes()
            text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            if kind == 'tests':
                assert '100% tests passed, 0 tests failed out of 7' in text
            else:
                assert 'FAILED:' not in text and 'error:' not in text
            parents[log.relative_to(ROOT).as_posix()] = sha(log)
    ledger = QUALIFICATIONS / 'gameplay_scenario_qualification_v25.json'
    bindings = json.loads(ledger.read_bytes())['bindings']
    for profile, coverage in result['coverage'].items():
        assert coverage['native_algorithm'] == [entry[profile]['native_algorithm'] for entry in bindings]
    document = ROOT / 'docs/native-gameplay/ENEMY_INITIALIZATION.md'
    qualification = dict(
        schema='reo.native.enemy.initialization.qualification.v1', status='qualified_partial',
        installed_in_game=False, stage4_complete=False,
        source_sha256=first['source_sha256'],
        original_sources_sha256=first['original_sources_sha256'],
        documentation_and_tools_sha256={p.relative_to(ROOT).as_posix(): sha(p)
                                        for p in (document, Path(__file__))},
        receipts=references, result=result, linked_model_regression=linked,
        parent_logs_sha256=parents,
        opcode_qualification=dict(path=ledger.relative_to(ROOT).as_posix(), sha256=sha(ledger)),
        limitations=[
            'Model definition reads require the initialized physical span of one of 62 owned directory entries.',
            'The original zero declared-count aliases still read their shared initialized definitions.',
            'Enemy priority indices outside the eight rows refuse before writes when the selected mode indexes them.',
            'Full enemy actor binding, construction, behavior and room orchestration remain open.',
            'Coherent installed native gameplay and end-to-end Step 4 acceptance remain open.',
        ])
    output = QUALIFICATIONS / 'native_enemy_initialization_qualification_v1.json'
    with output.open('x', encoding='utf-8') as target:
        target.write(json.dumps(qualification, indent=2) + '\n')
    print(json.dumps(dict(path=str(output), sha256=sha(output), checks=result['checks'])))


if __name__ == '__main__':
    main()
