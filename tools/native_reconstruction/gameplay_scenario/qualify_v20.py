"""Verify the scene startup cohorts and publish their opcode coverage."""
import json
from pathlib import Path

from qualify_v18 import QUALIFICATIONS, ROOT, sha
from qualify_v19 import read_cohort


def main():
    records, receipts = read_cohort('gameplay-scenario-scene-boot-{compiler}-v1')
    first, second = records
    assert first['source_sha256'] == second['source_sha256']
    assert first['result'] == second['result']
    assert first['room_counter_policy'] == second['room_counter_policy']
    for receipt in records:
        assert not receipt['game_launched'] and not receipt['pinned_shared_sources']
    result = first['result']
    for key, count in dict(cutscene_command_calls=2048, scene_auxiliary_cells=1043,
                           auxiliary_timer_checks=4096, roster_dispatches=512,
                           scene_boot_dispatches=512).items():
        assert result[key] == count

    previous = QUALIFICATIONS / 'gameplay_scenario_qualification_v19.json'
    ledger = json.loads(previous.read_bytes())
    opcodes = [0x62, 0xea, 0x120, 0x121, 0x122]
    for profile, coverage in result['coverage'].items():
        mask = coverage['native_algorithm']
        prior = [item[profile]['native_algorithm'] for item in ledger['bindings']]
        assert {i for i, bit in enumerate(mask) if bit != prior[i]} == set(opcodes)
        for opcode in opcodes:
            assert mask[opcode]
            ledger['bindings'][opcode][profile]['native_algorithm'] = True
        ledger['coverage'][profile]['native_algorithm'] = coverage['count']
        ledger['coverage'][profile]['unsupported'] = coverage['total'] - coverage['count']

    docs = ROOT / 'docs/native-gameplay/SCENARIO_SCENE_BOOT.md'
    ledger.pop('inventory_compaction')
    ledger.pop('intervening_qualifications')
    ledger.update(
        schema='reo.native.gameplay.scenario.qualification.v20',
        status='qualified_partial_native_scenario_scene_boot',
        new_opcodes=opcodes,
        previous_qualification={'path': previous.relative_to(ROOT).as_posix(), 'sha256': sha(previous)},
        source_sha256=first['source_sha256'],
        documentation_and_tools_sha256={
            path.relative_to(ROOT).as_posix(): sha(path) for path in (docs, Path(__file__))
        },
        receipts=receipts,
        result=result,
        owned_scenario_inputs=first['room_counter_policy'],
        limitations=[
            'The native cutscene request producer requires a typed provider for forced terminal effects.',
            'Auxiliary rows and timers are qualified independently of actual SPK asset playback.',
            'Live game loading and end-to-end Stage 4 verification remain open.',
        ],
    )
    output = QUALIFICATIONS / 'gameplay_scenario_qualification_v20.json'
    with output.open('x', encoding='utf-8') as target:
        target.write(json.dumps(ledger, indent=2) + '\n')
    print(json.dumps({'path': str(output), 'sha256': sha(output), 'coverage': ledger['coverage']}))


if __name__ == '__main__':
    main()
