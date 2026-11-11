"""Seal native room actor asset requests and direct archive regression."""
import json
from pathlib import Path

from qualify_v18 import QUALIFICATIONS, ROOT, sha
from qualify_v19 import read_cohort


def main():
    records, receipts = read_cohort('gameplay-scenario-room-assets-{compiler}-v1')
    first, second = records
    assert first['source_sha256'] == second['source_sha256']
    assert first['result'] == second['result']
    result = first['result']
    assert result['room_actor_asset_dispatches'] == 2048
    assert result['room_actor_asset_queries'] == 16384
    for receipt in records:
        assert not receipt['game_launched'] and not receipt['pinned_shared_sources']
    archives, archive_receipts = read_cohort('gameplay-scenario-archive-{compiler}-v3')
    assert archives[0]['source_sha256'] == archives[1]['source_sha256']
    assert archives[0]['result'] == archives[1]['result']
    assert archives[0]['result']['members'] == 171
    assert archives[0]['result']['room_bindings'] == 51
    previous = QUALIFICATIONS / 'gameplay_scenario_qualification_v20.json'
    ledger = json.loads(previous.read_bytes())
    opcodes = [0x85, 0x86, 0x87]
    for profile, coverage in result['coverage'].items():
        prior = [item[profile]['native_algorithm'] for item in ledger['bindings']]
        assert {i for i, bit in enumerate(coverage['native_algorithm']) if bit != prior[i]} == set(opcodes)
        for opcode in opcodes:
            assert coverage['native_algorithm'][opcode]
            ledger['bindings'][opcode][profile]['native_algorithm'] = True
        ledger['coverage'][profile]['native_algorithm'] = coverage['count']
        ledger['coverage'][profile]['unsupported'] = coverage['total'] - coverage['count']
    docs = ROOT / 'docs/native-gameplay'
    ledger.pop('owned_scenario_inputs')
    ledger.update(
        schema='reo.native.gameplay.scenario.qualification.v21',
        status='qualified_partial_native_scenario_room_actor_assets',
        new_opcodes=opcodes,
        previous_qualification={'path': previous.relative_to(ROOT).as_posix(), 'sha256': sha(previous)},
        source_sha256=first['source_sha256'],
        documentation_and_tools_sha256={p.relative_to(ROOT).as_posix(): sha(p) for p in (
            docs / 'SCENARIO_ROOM_ACTOR_ASSETS.md', docs / 'SCENARIO_ARCHIVE.md', Path(__file__))},
        receipts=receipts,
        result=result,
        direct_archive_regression={'receipts': archive_receipts, 'result': archives[0]['result']},
        limitations=[
            'Script and descriptor comparisons use controlled original dispatcher contexts.',
            'The native owner admits 128 room rows with four pairs each.',
            'The actual descriptor and model loading callers still need to adopt the canonical requests.',
            'Live game loading and end-to-end Stage 4 verification remain open.',
        ],
    )
    output = QUALIFICATIONS / 'gameplay_scenario_qualification_v21.json'
    with output.open('x', encoding='utf-8') as target:
        target.write(json.dumps(ledger, indent=2) + '\n')
    print(json.dumps({'path': str(output), 'sha256': sha(output), 'coverage': ledger['coverage']}))


if __name__ == '__main__':
    main()
