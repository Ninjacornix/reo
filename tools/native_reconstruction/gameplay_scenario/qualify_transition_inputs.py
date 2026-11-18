"""Seal the typed cutscene collection and actor placement consumers."""
import json
from pathlib import Path

from qualify_v18 import QUALIFICATIONS, ROOT, sha
from qualify_v19 import read_cohort


def main():
    records, receipts = read_cohort('gameplay-scenario-transition-inputs-{compiler}-v1')
    first, second = records
    assert first['source_sha256'] == second['source_sha256']
    assert first['result'] == second['result']
    result = first['result']
    assert result['cutscene_batches'] == 4096
    assert result['placement_packets'] == 4096
    assert result['room_placement_finishes'] == 2048
    for receipt in records:
        assert not receipt['game_launched'] and not receipt['pinned_shared_sources']
    previous = QUALIFICATIONS / 'gameplay_scenario_qualification_v21.json'
    ledger = json.loads(previous.read_bytes())
    for profile, coverage in result['coverage'].items():
        assert coverage['native_algorithm'] == [item[profile]['native_algorithm'] for item in ledger['bindings']]
    document = ROOT / 'docs/native-gameplay/SCENARIO_TRANSITION_INPUTS.md'
    qualification = dict(
        schema='reo.native.scenario.transition.inputs.qualification.v1', status='qualified_partial',
        source_sha256=first['source_sha256'],
        documentation_and_tools_sha256={p.relative_to(ROOT).as_posix(): sha(p) for p in (document, Path(__file__))},
        opcode_qualification={'path': previous.relative_to(ROOT).as_posix(), 'sha256': sha(previous)},
        receipts=receipts, result=result,
        declared_ports=['371AD0/371B70 scene mode effects', '6DE480/6DE590 media/UI effects',
                        '5D7D60/651850/5EB520 preparation and resource loading'],
        limitations=[
            'The cutscene queue is nonempty, normalized and serialized on the simulation owner.',
            'Packet admission bounds the primary request slots and imported position records.',
            'The original room completion comparison controls the three preparation/load children.',
            'Transport, actual media/UI consumers and native gameplay acceptance remain open.',
        ],
        installed_in_game=False, stage4_complete=False)
    output = QUALIFICATIONS / 'native_scenario_transition_inputs_qualification_v1.json'
    with output.open('x', encoding='utf-8') as target:
        target.write(json.dumps(qualification, indent=2) + '\n')
    print(json.dumps({'path': str(output), 'sha256': sha(output), 'result': {
        key: result[key] for key in ('checks', 'cutscene_batches', 'placement_packets', 'room_placement_finishes')}}))


if __name__ == '__main__':
    main()
