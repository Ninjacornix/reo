"""Seal the native forced transition, local publication and VM adapter."""
import json
from pathlib import Path

from qualify_v18 import QUALIFICATIONS, ROOT, sha
from qualify_v19 import read_cohort


def main():
    records, receipts = read_cohort('gameplay-scenario-forced-terminal-{compiler}-v1')
    first, second = records
    assert first['source_sha256'] == second['source_sha256'] and first['result'] == second['result']
    result = first['result']
    assert result['forced_terminal_adapter_dispatches'] == 512
    for receipt in records:
        assert not receipt['game_launched'] and not receipt['pinned_shared_sources']
    forced, forced_receipts = read_cohort('actor-forced-terminal-{compiler}-v3')
    assert forced[0]['source_sha256'] == forced[1]['source_sha256']
    observed = forced[0]['observed']
    assert observed == forced[1]['observed'] and observed['checks'] == 909920516
    assert observed['forced_terminal_cases'] == 10240 and observed['local_player_message_cases'] == 5120
    assert observed['forced_terminal_messages'] == 1400 and observed['forced_terminal_refusals'] == 15
    for receipt in forced:
        assert receipt['source_unchanged'] and not receipt['focused_forced_terminal_run']
        assert not receipt['game_run'] and not receipt['installed_in_game']

    publication = []
    parents = {}
    binaries = {}
    for compiler in ('llvm', 'gcc'):
        path = ROOT / 'build-native-sjuni' / f'local-player-publication-regression-{compiler}-v1/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        assert receipt['observed']['checks'] == 73525738
        name = 'game/native/gameplay_update/scenario_publication.hpp'
        assert receipt['source_sha256'][name] == sha(ROOT / name)
        publication.append(dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=receipt['observed']))
        for kind in ('parent', 'tests'):
            log = ROOT / 'build-native-sjuni' / f'actor-forced-terminal-{kind}-{compiler}-v1.log'
            raw = log.read_bytes()
            text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            if kind == 'tests':
                assert '100% tests passed, 0 tests failed out of 7' in text
            else:
                assert 'FAILED:' not in text and 'error:' not in text
            parents[log.relative_to(ROOT).as_posix()] = sha(log)
        base = ROOT / 'build-native-sjuni' / f'gameplay-native-{compiler}-v1'
        for name in ('gameplay_world/gameplay_world_tests.exe', 'gameplay_world/owned_resource_recipes_tests.exe',
                     'gameplay_scenario/gameplay_script_program_tests.exe', 'gameplay_scenario/gameplay_archive_tests.exe',
                     'gameplay_update/gameplay_collision_workers_tests.exe',
                     'gameplay_update/gameplay_cooperative_events_tests.exe', 'gameplay_update/gameplay_ai_owner_tests.exe'):
            binary = base / name
            binaries[binary.relative_to(ROOT).as_posix()] = sha(binary)

    previous = QUALIFICATIONS / 'gameplay_scenario_qualification_v21.json'
    ledger = json.loads(previous.read_bytes())
    for profile, coverage in result['coverage'].items():
        prior = [item[profile]['native_algorithm'] for item in ledger['bindings']]
        assert {i for i, bit in enumerate(coverage['native_algorithm']) if bit != prior[i]} == {0x61}
        ledger['bindings'][0x61][profile]['native_algorithm'] = True
        ledger['coverage'][profile]['native_algorithm'] = coverage['count']
        ledger['coverage'][profile]['unsupported'] = coverage['total'] - coverage['count']
    for opcode in (0x61, 0x62):
        ledger['bindings'][opcode]['selected_native_provider_composition_qualified'] = True
    transition = QUALIFICATIONS / 'native_scenario_transition_inputs_qualification_v1.json'
    document = ROOT / 'docs/native-gameplay/ACTOR_FORCED_TERMINAL.md'
    ledger.pop('direct_archive_regression')
    ledger.update(
        schema='reo.native.gameplay.scenario.qualification.v22',
        status='qualified_partial_native_scenario_forced_actor_transition', new_opcodes=[0x61],
        previous_qualification={'path': previous.relative_to(ROOT).as_posix(), 'sha256': sha(previous)},
        intervening_qualifications={transition.relative_to(ROOT).as_posix(): sha(transition)},
        source_sha256=first['source_sha256'],
        documentation_and_tools_sha256={p.relative_to(ROOT).as_posix(): sha(p) for p in (document, Path(__file__))},
        receipts=receipts, result=result,
        forced_transition={'receipts': forced_receipts, 'source_sha256': forced[0]['source_sha256'], 'observed': observed},
        general_publication_regression=publication, parent_logs_sha256=parents, parent_binaries_sha256=binaries,
        limitations=[
            'The VM adapter comparison declares the terminal child as a port. Complete6671D0 is independently compared.',
            'UI6E1430 and final message transport are explicit controlled consumers in the original comparisons.',
            'Known local-player message selectors are0,1,7. Unknown original stack payloads remain unadmitted.',
            'Live scene orchestration and native gameplay acceptance remain open.',
        ])
    output = QUALIFICATIONS / 'gameplay_scenario_qualification_v22.json'
    with output.open('x', encoding='utf-8') as target:
        target.write(json.dumps(ledger, indent=2) + '\n')
    print(json.dumps({'path': str(output), 'sha256': sha(output), 'coverage': ledger['coverage']}))


if __name__ == '__main__':
    main()
