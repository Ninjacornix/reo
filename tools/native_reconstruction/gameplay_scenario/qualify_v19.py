"""Verify the actor inventory cohorts and publish the scenario opcode ledger."""
import json
from pathlib import Path

from qualify_v18 import QUALIFICATIONS, ROOT, sha


def read_cohort(name):
    paths = [ROOT / 'build-native-sjuni' / name.format(compiler=compiler) / 'receipt.json'
             for compiler in ('llvm', 'gcc')]
    records = [json.loads(path.read_bytes()) for path in paths]
    for receipt in records:
        assert receipt['status'] == 'passed'
        assert not receipt['installed_in_game']
        assert all(sha(ROOT / name) == digest for name, digest in receipt['source_sha256'].items())
    references = [dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path),
                       compiler_sha256=receipt['compiler_sha256'])
                  for path, receipt in zip(paths, records)]
    return records, references


def main():
    records, receipts = read_cohort('gameplay-scenario-actor-inventory-{compiler}-v3')
    first, second = records
    assert first['source_sha256'] == second['source_sha256']
    assert first['result'] == second['result']
    for receipt in records:
        assert not receipt['game_launched'] and not receipt['pinned_shared_sources']
    result = first['result']
    assert result['actor_inventory_dispatches'] == 2048
    assert result['actor_placement_dispatches'] == 512

    inventory_records, inventory_receipts = read_cohort('resource-inventory-compaction-{compiler}-v1')
    observed = inventory_records[0]['observed']
    assert observed == inventory_records[1]['observed']

    previous = QUALIFICATIONS / 'gameplay_scenario_qualification_v18.json'
    ledger = json.loads(previous.read_bytes())
    grants = [0x38, 0x39, 0x173]
    placements = [0x65, 0x68, 0x69, 0x6a]
    for profile, coverage in result['coverage'].items():
        mask = coverage['native_algorithm']
        prior = [item[profile]['native_algorithm'] for item in ledger['bindings']]
        assert {i for i, bit in enumerate(mask) if bit != prior[i]} == set(grants + placements)
        for opcode in grants + placements:
            assert mask[opcode]
            ledger['bindings'][opcode][profile]['native_algorithm'] = True
        ledger['coverage'][profile]['native_algorithm'] = coverage['count']
        ledger['coverage'][profile]['unsupported'] = coverage['total'] - coverage['count']

    docs = ROOT / 'docs/native-gameplay'
    ledger.pop('room_counter_policy')
    ledger.update(
        schema='reo.native.gameplay.scenario.qualification.v19',
        status='qualified_partial_native_scenario_actor_inventory',
        new_opcodes=grants,
        previous_qualification={'path': previous.relative_to(ROOT).as_posix(), 'sha256': sha(previous)},
        intervening_qualifications={'actor_placements': placements},
        source_sha256=first['source_sha256'],
        documentation_and_tools_sha256={
            path.relative_to(ROOT).as_posix(): sha(path)
            for path in (docs / 'SCENARIO_ACTOR_INVENTORY.md', docs / 'SCENARIO_ACTOR_PLACEMENTS.md', Path(__file__))
        },
        receipts=receipts,
        result=result,
        inventory_compaction={'receipts': inventory_receipts, 'observed': observed},
        limitations=[
            'Original dispatchers run controlled script, actor, and resource pool contexts.',
            'Malformed storage groups are bounded by the native storage owner.',
            'Live game loading and end-to-end Stage 4 verification remain open.',
        ],
    )
    output = QUALIFICATIONS / 'gameplay_scenario_qualification_v19.json'
    with output.open('x', encoding='utf-8') as target:
        target.write(json.dumps(ledger, indent=2) + '\n')
    print(json.dumps({'path': str(output), 'sha256': sha(output), 'coverage': ledger['coverage']}))


if __name__ == '__main__':
    main()
