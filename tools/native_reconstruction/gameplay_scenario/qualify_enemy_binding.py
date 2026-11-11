"""Seal canonical linked enemy record binding and body-priority queries."""
import json
from pathlib import Path

from qualify_v18 import QUALIFICATIONS, ROOT, sha
from qualify_v19 import read_cohort


def main():
    records, references = read_cohort('gameplay-enemy-binding-{compiler}-v1')
    first, second = records
    assert first['source_sha256'] == second['source_sha256']
    assert first['result'] == second['result']
    result = first['result']
    assert result['enemy_binding_calls'] == 4096 and result['enemy_binding_refusals'] == 14
    assert result['body_priority_calls'] == 7696 and result['body_priority_refusals'] == 2545
    archives = []
    parents = {}
    for compiler in ('llvm', 'gcc'):
        path = ROOT / 'build-native-sjuni' / f'gameplay-enemy-binding-archive-{compiler}-v1/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed'
        assert receipt['result']['members'] == 186 and receipt['result']['checks'] == 14206
        assert receipt['result']['enemy_banks'] == 10
        assert all(sha(ROOT / name) == digest for name, digest in receipt['source_sha256'].items())
        assert not receipt['game_launched'] and not receipt['installed_in_game']
        archives.append(dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), result=receipt['result']))
        for kind in ('parent', 'tests'):
            log = ROOT / 'build-native-sjuni' / f'enemy-binding-{kind}-{compiler}-v1.log'
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
    document = ROOT / 'docs/native-gameplay/ENEMY_BINDING.md'
    previous = QUALIFICATIONS / 'native_enemy_initialization_qualification_v1.json'
    qualification = dict(
        schema='reo.native.enemy.binding.qualification.v1', status='qualified_partial',
        installed_in_game=False, stage4_complete=False,
        source_sha256=first['source_sha256'], original_sources_sha256=first['original_sources_sha256'],
        documentation_and_tools_sha256={p.relative_to(ROOT).as_posix(): sha(p)
                                        for p in (document, Path(__file__))},
        previous_qualification=dict(path=previous.relative_to(ROOT).as_posix(), sha256=sha(previous)),
        receipts=references, result=result, direct_archive_regression=archives, parent_logs_sha256=parents,
        opcode_qualification=dict(path=ledger.relative_to(ROOT).as_posix(), sha256=sha(ledger)),
        limitations=[
            'The binder admits actual category2 actors in the shared fifty-node linked pool.',
            'Definition, policy and timer indices require reviewed initialized extents.',
            'Original actor self references become direct canonical component ownership.',
            'Linked-family fields are typed independently of primary-family inventory and pending-hit roles.',
            'Model/resource construction, enemy behavior and room orchestration remain open.',
            'Actual game installation and full native Step 4 acceptance remain open.',
        ])
    output = QUALIFICATIONS / 'native_enemy_binding_qualification_v1.json'
    with output.open('x', encoding='utf-8') as target:
        target.write(json.dumps(qualification, indent=2) + '\n')
    print(json.dumps(dict(path=str(output), sha256=sha(output), checks=result['checks'])))


if __name__ == '__main__':
    main()
