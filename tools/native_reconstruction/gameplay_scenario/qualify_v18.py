"""Verify both room-counter VM cohorts and publish the current opcode ledger."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
QUALIFICATIONS = ROOT / 'tools/native_reconstruction'


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    paths = [
        ROOT / 'build-native-sjuni' / f'gameplay-scenario-room-counters-{compiler}-v2' / 'receipt.json'
        for compiler in ('llvm', 'gcc')
    ]
    records = [json.loads(path.read_bytes()) for path in paths]
    first, second = records
    assert first['source_sha256'] == second['source_sha256']
    assert first['result'] == second['result']
    assert first['room_counter_policy'] == second['room_counter_policy']
    for receipt in records:
        assert receipt['status'] == 'passed'
        assert not receipt['game_launched'] and not receipt['installed_in_game']
        assert not receipt['pinned_shared_sources']
        assert all(sha(ROOT / name) == digest for name, digest in receipt['source_sha256'].items())
    result = first['result']
    assert result['room_counter_handler_calls'] == 73728
    assert result['room_counter_resets'] == 24
    assert result['room_counter_dispatches'] == 192

    previous = QUALIFICATIONS / 'gameplay_scenario_qualification_v17.json'
    ledger = json.loads(previous.read_bytes())
    refresh = {
        'ordinary': {0x5a, 0xa8, 0xf2},
        'offline_actor': {0xa8, 0xf2},
    }
    for profile, observed in result['coverage'].items():
        prior = [item[profile]['native_algorithm'] for item in ledger['bindings']]
        assert {i for i, value in enumerate(observed['native_algorithm']) if value != prior[i]} == refresh[profile]
        for opcode in refresh[profile]:
            assert observed['native_algorithm'][opcode]
            ledger['bindings'][opcode][profile]['native_algorithm'] = True
        ledger['coverage'][profile]['native_algorithm'] = observed['count']
        ledger['coverage'][profile]['unsupported'] = observed['total'] - observed['count']
    entry = ledger['bindings'][0xf2]
    assert entry['ordinary']['original_target'] == entry['offline_actor']['original_target'] == '00691D20'
    entry['selected_native_provider_composition_qualified'] = True
    ledger.pop('canonical_periodic_owner')
    docs = ROOT / 'docs/native-gameplay/SCENARIO_ROOM_COUNTERS.md'
    ledger.update(
        schema='reo.native.gameplay.scenario.qualification.v18',
        status='qualified_partial_native_scenario_room_counters',
        new_opcodes=[0xf2],
        previous_qualification={'path': previous.relative_to(ROOT).as_posix(), 'sha256': sha(previous)},
        intervening_qualifications={
            name: sha(QUALIFICATIONS / name) for name in (
                'native_scenario_surface_effects_qualification_v1.json',
                'native_navigation_bank_qualification_v1.json',
            )
        },
        source_sha256=first['source_sha256'],
        room_counter_policy=first['room_counter_policy'],
        documentation_and_tools_sha256={
            p.relative_to(ROOT).as_posix(): sha(p) for p in (docs, Path(__file__))
        },
        receipts=[
            dict(path=p.relative_to(ROOT).as_posix(), sha256=sha(p), compiler=r['compiler'],
                 compiler_sha256=r['compiler_sha256'], result=r['result'],
                 checked_owned_instruction_comments=r['checked_owned_instruction_comments'])
            for p, r in zip(paths, records)
        ],
        limitations=[
            'Four owned policy rows, 128 room rows and 24 counters per room are admitted.',
            'The full original dispatchers use controlled script/channel contexts and owned policy tables.',
            'The runtime scenario loader must still configure the native Session and install the stock program.',
            'No game, stock room execution or complete Stage 4 migration is claimed.',
        ],
    )
    output = QUALIFICATIONS / 'gameplay_scenario_qualification_v18.json'
    with output.open('x', encoding='utf-8') as target:
        target.write(json.dumps(ledger, indent=2) + '\n')
    print(json.dumps({'path': str(output), 'sha256': sha(output), 'coverage': ledger['coverage']}))


if __name__ == '__main__':
    main()
